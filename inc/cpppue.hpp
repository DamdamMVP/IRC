#pragma once
# include <iostream>
# include <map>
# include <set>
# include <map>
# include <vector>

struct Client {
    int fd;                     // File descriptor pour l'utilisateur
    std::string nickname;       // Pseudo de l'utilisateur
    std::string username;       // Nom d'utilisateur
    std::string hostname;       // Hôte de l'utilisateur
    bool isOperator;            // Statut d'opérateur
    bool isAuthenticated;       // Statut d'authentification
    Client();
    Client(std::string nickname);
    ~Client();
};

struct Channel {
    std::string name;                    // Nom du channel
    std::string topic;                   // Sujet du channel
    std::set<int> users;                 // Liste des utilisateurs par FD
    std::set<int> operators;             // Liste des opérateurs par FD
    int userLimit;                       // Limite d'utilisateurs
    std::string password;                // Mot de passe du channel
    bool inviteOnly;                     // Mode sur invitation
    bool topicRestricted;                // Restriction de modification du topic
    Channel();
    Channel(std::string name);
    ~Channel();
    int getNbrUsersOn();
    void notifyChannel(std::string message); //TODO
};

class ClientManager
{
    private:
        std::map<int, Client> _clients;
    public:
        ClientManager();
        ~ClientManager();
        //functions
        void sendToAllUsers(Channel *channel, std::string message); //TODO
        void sendPrvMsg(Client *client, std::string message); //TODO
        //getter
        Client *getClient(int fd);
        int getFd(std::string username);
        std::string getNickname(int fd);
        std::string getClientname(int fd);
        std::string getHostname(int fd);
        const std::map<int, Client> &getClients() const;
        void updateNickname(int fd, std::string nickname);
        //setter
        void setAuthenticated(int fd, bool isAuthenticated);
        void setOperator(int fd, bool isOperator);
        void setNickname(int fd, std::string nickname);
        void setClientname(int fd, std::string username);
        void setHostname(int fd, std::string hostname);
        //check
        bool isOperator(int fd);
        bool userExists(int fd);
        bool nicknameExists(std::string nickname);
        bool isAuthenticated(int fd);
};


class ChannelManager
{
  private:
    std::map<std::string, Channel> _channels;
  public:
    ChannelManager();
    ~ChannelManager();
    //functions
    void addChannel(std::string channelName, Channel channel);
    void removeChannel(std::string channelName);
    Channel *getChannel(std::string channelName);
    void addUser(std::string channelName, Client user);
    void removeUser(std::string channelName, Client user);
    //getter
    std::set<int> getUsers(std::string channelName);
    std::set<int> getOperators(std::string channelName);
    int getUserLimit(std::string channelName);
    std::string getPassword(std::string channelName);
    const std::map<std::string, Channel> &getChannels() const;
    //setter
    void setTopic(std::string channelName, std::string topic);
    void setUserLimit(std::string channelName, int userLimit);
    void setPassword(std::string channelName, std::string password);
    void setInviteOnly(std::string channelName, bool inviteOnly);
    void setTopicRestricted(std::string channelName, bool topicRestricted);
    //check
    bool channelExists(std::string channelName);
    bool userExists(std::string channelName, int fd);
    bool isOperator(std::string channelName, int fd);
    bool isInviteOnly(std::string channelName);
    bool isTopicRestricted(std::string channelName);
    bool isPasswordProtected(std::string channelName);
    bool isFull(std::string channelName);
    bool isUserInChannel(std::string channelName, int fd);
};

class CommandHandler {
  private:
    ClientManager& _clientManager;
    ChannelManager& _channelManager;

  public:
    CommandHandler(ClientManager& clientMgr, ChannelManager& chanMgr)
	: _clientManager(clientMgr), _channelManager(chanMgr) {}

    // Commandes d'authentification
    void handleNick(int clientFd, const std::vector<std::string>& args, ClientManager& userManager,
		    ChannelManager& channelManager);
    void handleUser(int clientFd, const std::vector<std::string>& args, ClientManager& userManager,
		    ChannelManager& channelManager);
    void handlePass(int clientFd, const std::vector<std::string>& args, ClientManager& userManager,
		    ChannelManager& channelManager);

    // Commandes de gestion de channels
    void handleJoin(int clientFd, const std::vector<std::string>& args, ClientManager& userManager,
		    ChannelManager& channelManager);
    void handlePart(int clientFd, const std::vector<std::string>& args, ClientManager& userManager,
		    ChannelManager& channelManager);
    void handleTopic(int clientFd, const std::vector<std::string>& args, ClientManager& userManager,
		     ChannelManager& channelManager);
    void handleMode(int clientFd, const std::vector<std::string>& args, ClientManager& userManager,
		    ChannelManager& channelManager);

    // Commandes de messagerie
    void handlePrivmsg(int clientFd, const std::vector<std::string>& args, ClientManager& userManager,
		       ChannelManager& channelManager);
    void handleNotice(int clientFd, const std::vector<std::string>& args, ClientManager& userManager,
		      ChannelManager& channelManager);

    // Commandes de gestion
    void handleKick(int clientFd, const std::vector<std::string>& args, ClientManager& userManager,
		    ChannelManager& channelManager);
    void handleInvite(int clientFd, const std::vector<std::string>& args, ClientManager& userManager,
		      ChannelManager& channelManager);
    void handleQuit(int clientFd, const std::vector<std::string>& args, ClientManager& userManager,
            ChannelManager& channelManager);
    void handleMsg(int clientFd, const std::vector<std::string>& args, ClientManager& userManager,
            ChannelManager& channelManager);
};
