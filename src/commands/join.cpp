#include "Channel.hpp"
#include "Client.hpp"
#include "Tokenisation.hpp"

bool validateJoin(ClientManager& clients, ChannelManager& channels,
                  const TokenisedCommand &cmd, int idClient) {
  if (cmd.getArguments().empty()) {
    std::cerr << "error_461 : ERR_NEEDMOREPARAMS" << std::endl;
    return false;
  }

  std::string channelName = cmd.getArguments()[0];

  if (channelName.empty() || channelName[0] != '#' ||
      channelName.length() > 50) {
    std::cerr << "error_476 : ERR_BADCHANMASK" << std::endl;
    return false;
  }

  // Si le channel n'existe pas encore, les vérifications suivantes ne sont pas nécessaires
  if (channels.channelExists(channelName)) {
    if (channels.isBanned(channelName, idClient)) {
      std::cerr << "error_474 : ERR_BANNEDFROMCHAN" << std::endl;
      return false;
    }

    if (channels.isFull(channelName)) {
      std::cerr << "error_471 : ERR_CHANNELISFULL" << std::endl;
      return false;
    }

    if (channels.isPasswordProtected(channelName)) {
      if (cmd.getArguments().size() < 2 || 
          channels.getPassword(channelName) != cmd.getArguments()[1]) {
        std::cerr << "error_475 : ERR_BADCHANNELKEY" << std::endl;
        return false;
      }
    }
  }

  (void)clients;
  return true;
}

void doJoin(ClientManager& clients, ChannelManager& channels,
            const TokenisedCommand &cmd, int fdClient) {

  std::string channelName = cmd.getArguments()[0];
  if (channels.getChannel(channelName) == NULL) {
    channels.addChannel(channelName, new Channel(channelName));
	channels.addOperator(channelName, clients.getClient(fdClient));
  }
  channels.addUser(channelName, clients.getClient(fdClient));

  std::set<int> users = channels.getUsers(channelName);
  std::set<int>::iterator it = users.begin();
  while (it != users.end()) {
    std::cout << "user : " << *it << " is in " << channelName << std::endl;
    it++;
  }

  channels.notifyChannel(":caca JOIN " + channelName + "\n", channelName);

  //   if (!channel->getTopic().empty()) {
  //     clients.sendMessage("rpl_332"); // RPL_TOPIC
  //   }

  //   clients.sendMessage("rpl_353"); // RPL_NAMREPLY
  //   clients.sendMessage("rpl_366"); // RPL_ENDOFNAMES
}
