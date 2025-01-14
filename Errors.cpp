#include "Errors.hpp"

// void error_443(Client* client, Channel* channel);
void Errors::error_443(Client* client, Channel* channel)
{
	// if (client == nullptr || !client->isConnected())
	// 	return;

	std::string errorMsg = ":$(SERVER_NAME) 443 " + client->getNickname() + channel->getChannel() + " :is already on channel";
	send(client->fd, errorMsg.c_str(), errorMsg.size(), 0);
	std::cout << "443 ERR_USERONCHANNEL" << std::endl;
	return;
}

// void error_441(Client* client, Channel* channel);
void Errors::error_441(Client* client, Channel* channel)
{
	// if (client == nullptr || !client->isConnected())
	// 	return;

	std::string errorMsg = ":$(SERVER_NAME) 441 " + client->getNickname() + channel->getChannel() + " :They aren't on that channel";
	send(client->fd, errorMsg.c_str(), errorMsg.size(), 0);
	std::cout << "441 ERR_USERNOTINCHANNEL" << std::endl;
	return;
}

// void error_476(Client* client, Channel* channel);
void Errors::error_476(Client* client, Channel* channel)
{
	// if (client == nullptr || !client->isConnected())
	// 	return;

	std::string errorMsg = ":$(SERVER_NAME) 476 " + client->getNickname() + channel->getChannel() + " :Bad Channel Mask";
	send(client->fd, errorMsg.c_str(), errorMsg.size(), 0);
	std::cout << "476 ERR_BADCHANMASK" << std::endl;
	return;
}

// void error_403(Client* client, Channel* channel);
void Errors::error_403(Client* client, Channel* channel)
{
	// if (client == nullptr || !client->isConnected())
	// 	return;

	std::string errorMsg = ":$(SERVER_NAME) 403 " + client->getNickname() + channel->getChannel() + " :No such channel";
	send(client->fd, errorMsg.c_str(), errorMsg.size(), 0);
	std::cout << "403 ERR_NOSUCHCHANNEL" << std::endl;
	return;
}

// void error_442(Client* client, Channel* channel);
void Errors::error_442(Client* client, Channel* channel)
{
	// if (client == nullptr || !client->isConnected())
	// 	return;

	std::string errorMsg = ":$(SERVER_NAME) 442 " + client->getNickname() + channel->getChannel() + " :You're not on that channel";
	send(client->fd, errorMsg.c_str(), errorMsg.size(), 0);
	std::cout << "442 ERR_NOTONCHANNEL" << std::endl;
	return;
}

// void error_461(Client* client, std::string command);
void Errors::error_461(Client* client, std::string command)
{
	// if (client == nullptr || !client->isConnected())
	// 	return;

	std::string errorMsg = ":$(SERVER_NAME) 461 " + client->getNickname() + command + " :Not enough parameters";
	send(client->fd, errorMsg.c_str(), errorMsg.size(), 0);
	std::cout << "461 ERR_NEEDMOREPARAMS" << std::endl;
	return;
}

// void error_482(Client* client, Channel* channel);
void Errors::error_482(Client* client, Channel* channel)
{
	// if (client == nullptr || !client->isConnected())
	// 	return;

	std::string errorMsg = ":$(SERVER_NAME) 482 " + client->getNickname() + channel->getChannel() + " :You're not channel operator";
	send(client->fd, errorMsg.c_str(), errorMsg.size(), 0);
	std::cout << "482 ERR_CHANOPRIVSNEEDED" << std::endl;
	return;
}

// void error_501(Client* client);
void Errors::error_501(Client* client)
{
	// if (client == nullptr || !client->isConnected())
	// 	return;

	std::string errorMsg = ":$(SERVER_NAME) 501 " + client->getNickname() + " :Unknown MODE flag";
	send(client->fd, errorMsg.c_str(), errorMsg.size(), 0);
	std::cout << "501 ERR_UMODEUNKNOWNFLAG" << std::endl;
	return;
}

// void error_431(Client* client);
void Errors::error_431(Client* client)
{
	// if (client == nullptr || !client->isConnected())
	// 	return;

	std::string errorMsg = ":$(SERVER_NAME) 431 " + client->getNickname() + " :No nickname given";
	send(client->fd, errorMsg.c_str(), errorMsg.size(), 0);
	std::cout << "431 ERR_NONICKNAMEGIVEN" << std::endl;
	return;
}

// void error_432(Client* client, std::string target_nick);
void Errors::error_432(Client* client, std::string target_nick)
{
	// if (client == nullptr || !client->isConnected())
	// 	return;

	std::string errorMsg = ":$(SERVER_NAME) 432 " + client->getNickname() + target_nick + ":Erroneus nickname";
	send(client->fd, errorMsg.c_str(), errorMsg.size(), 0);
	std::cout << "432 ERR_ERRONEUSNICKNAME" << std::endl;
	return;
}

// void error_433(Client* client, std::string target_nick);
void Errors::error_433(Client* client, std::string target_nick)
{
	// if (client == nullptr || !client->isConnected())
	// 	return;

	std::string errorMsg = ":$(SERVER_NAME) 433 " + client->getNickname() + target_nick + ":Nickname is already in use";
	send(client->fd, errorMsg.c_str(), errorMsg.size(), 0);
	std::cout << "433 ERR_NICKNAMEINUSE" << std::endl;
	return;
}

// void error_436(Client* client, std::string target_nick);
void Errors::error_436(Client* client, std::string target_nick)
{
	// if (client == nullptr || !client->isConnected())
	// 	return;

	std::string errorMsg = ":$(SERVER_NAME) 436 " + client->getNickname() + target_nick + ":Nickname collision KILL from <user>@<host>";
	send(client->fd, errorMsg.c_str(), errorMsg.size(), 0);
	std::cout << "436 ERR_NICKCOLLISION" << std::endl;
	return;
}

// void error_401(Client* client, std::string target_nick);
void Errors::error_401(Client* client, std::string target_nick)
{
	// if (client == nullptr || !client->isConnected())
	// 	return;

	std::string errorMsg = ":$(SERVER_NAME) 401 " + client->getNickname() + target_nick + " :No such nick/channel";
	send(client->fd, errorMsg.c_str(), errorMsg.size(), 0);
	std::cout << "401 ERR_NOSUCHNICK" << std::endl;
	return;
}

// void error_402(Client* client, std::string target_server);
void Errors::error_402(Client* client, std::string target_server)
{
	// if (client == nullptr || !client->isConnected())
	// 	return;

	std::string errorMsg = ":$(SERVER_NAME) 402 " + client->getNickname() + target_server + " :No such server";
	send(client->fd, errorMsg.c_str(), errorMsg.size(), 0);
	std::cout << "402 ERR_NOSUCHSERVER" << std::endl;
	return;
}

// void error_404(Client* client, Channel* channel);
void Errors::error_404(Client* client, Channel* channel)
{
	// if (client == nullptr || !client->isConnected())
	// 	return;

	std::string errorMsg = ":$(SERVER_NAME) 404 " + client->getNickname() + channel->getChannel() + " :Cannot send to channel";
	send(client->fd, errorMsg.c_str(), errorMsg.size(), 0);
	std::cout << "404 ERR_CANNOTSENDTOCHAN" << std::endl;
	return;
}

// void error_411(Client* client);
void Errors::error_411(Client* client)
{
	// if (client == nullptr || !client->isConnected())
	// 	return;

	std::string errorMsg = ":$(SERVER_NAME) 411 " + client->getNickname() + " :No recipient given (<command>)";
	send(client->fd, errorMsg.c_str(), errorMsg.size(), 0);
	std::cout << "411 ERR_NORECIPIENT" << std::endl;
	return;
}

// void error_412(Client* client);
void Errors::error_412(Client* client)
{
	// if (client == nullptr || !client->isConnected())
	// 	return;

	std::string errorMsg = ":$(SERVER_NAME) 412 " + client->getNickname() + " :No text to send";
	send(client->fd, errorMsg.c_str(), errorMsg.size(), 0);
	std::cout << "412 ERR_NOTEXTTOSEND" << std::endl;
	return;
}

// void error_462(Client* client);
void Errors::error_462(Client* client)
{
	// if (client == nullptr || !client->isConnected())
	// 	return;

	std::string errorMsg = ":$(SERVER_NAME) 462 " + client->getNickname() + " :You may not reregister";
	send(client->fd, errorMsg.c_str(), errorMsg.size(), 0);
	std::cout << "462 ERR_ALREADYREGISTERED" << std::endl;
	return;
}

// void error_405(Client* client, Channel* channel);
void Errors::error_405(Client* client, Channel* channel)
{
	// if (client == nullptr || !client->isConnected())
	// 	return;

	std::string errorMsg = ":$(SERVER_NAME) 405 " + client->getNickname() + channel->getChannel() + " :You have joined too many channels";
	send(client->fd, errorMsg.c_str(), errorMsg.size(), 0);
	std::cout << "405 ERR_TOOMANYCHANNELS" << std::endl;
	return;
}

// void error_406(Client* client, std::string target_nick);
void Errors::error_406(Client* client, std::string target_nick)
{
	// if (client == nullptr || !client->isConnected())
	// 	return;

	std::string errorMsg = ":$(SERVER_NAME) 406 " + client->getNickname() + target_nick + " :There was no such nickname";
	send(client->fd, errorMsg.c_str(), errorMsg.size(), 0);
	std::cout << "406 ERR_WASNOSUCHNICK" << std::endl;
	return;
}

// void error_409(Client* client);
void Errors::error_409(Client* client)
{
	// if (client == nullptr || !client->isConnected())
	// 	return;

	std::string errorMsg = ":$(SERVER_NAME) 409 " + client->getNickname() + " :No origin specified";
	send(client->fd, errorMsg.c_str(), errorMsg.size(), 0);
	std::cout << "409 ERR_NOORIGIN" << std::endl;
	return;
}

// void error_417(Client* client);
void Errors::error_417(Client* client)
{
	// if (client == nullptr || !client->isConnected())
	// 	return;

	std::string errorMsg = ":$(SERVER_NAME) 417 " + client->getNickname() + " :Input line was too long";
	send(client->fd, errorMsg.c_str(), errorMsg.size(), 0);
	std::cout << "417 ERR_INPUTTOOLONG" << std::endl;
	return;
}

// void error_421(Client* client);
void Errors::error_421(Client* client)
{
	// if (client == nullptr || !client->isConnected())
	// 	return;

	std::string errorMsg = ":$(SERVER_NAME) 421 " + client->getNickname() + " <command> :Unknown command";
	send(client->fd, errorMsg.c_str(), errorMsg.size(), 0);
	std::cout << "421 ERR_UNKNOWNCOMMAND" << std::endl;
	return;
}

// void error_451(Client* client);
void Errors::error_451(Client* client)
{
	// if (client == nullptr || !client->isConnected())
	// 	return;

	std::string errorMsg = ":$(SERVER_NAME) 451 " + client->getNickname() + " :You have not registered";
	send(client->fd, errorMsg.c_str(), errorMsg.size(), 0);
	std::cout << "451 ERR_NOTREGISTERED" << std::endl;
	return;
}

// void error_464(Client* client);
void Errors::error_464(Client* client)
{
	// if (client == nullptr || !client->isConnected())
	// 	return;

	std::string errorMsg = ":$(SERVER_NAME) 464 " + client->getNickname() + " :Password incorrect";
	send(client->fd, errorMsg.c_str(), errorMsg.size(), 0);
	std::cout << "464 ERR_PASSWDMISMATCH" << std::endl;
	return;
}

// void error_465(Client* client);
void Errors::error_465(Client* client)
{
	// if (client == nullptr || !client->isConnected())
	// 	return;

	std::string errorMsg = ":$(SERVER_NAME) 465 " + client->getNickname() + " :You are banned from this server.";
	send(client->fd, errorMsg.c_str(), errorMsg.size(), 0);
	std::cout << "465 ERR_YOUREBANNEDCREEP" << std::endl;
	return;
}

// void error_471(Client* client, Channel* channel);
void Errors::error_471(Client* client, Channel* channel)
{
	// if (client == nullptr || !client->isConnected())
	// 	return;

	std::string errorMsg = ":$(SERVER_NAME) 471 " + client->getNickname() + channel->getChannel() + " :Cannot join channel (+l)";
	send(client->fd, errorMsg.c_str(), errorMsg.size(), 0);
	std::cout << "471 ERR_CHANNELISFULL" << std::endl;
	return;
}

// void error_472(Client* client, std::string mode_char);
void Errors::error_472(Client* client, std::string mode_char)
{
	// if (client == nullptr || !client->isConnected())
	// 	return;

	std::string errorMsg = ":$(SERVER_NAME) 472 " + client->getNickname() +  mode_char + " :is unknown mode char to me";
	send(client->fd, errorMsg.c_str(), errorMsg.size(), 0);
	std::cout << "472 ERR_UNKNOWNMODE" << std::endl;
	return;
}

// void error_473(Client* client, Channel* channel);
void Errors::error_473(Client* client, Channel* channel)
{
	// if (client == nullptr || !client->isConnected())
	// 	return;

	std::string errorMsg = ":$(SERVER_NAME) 473 " + client->getNickname() + channel->getChannel() + " :Cannot join channel (+i)";
	send(client->fd, errorMsg.c_str(), errorMsg.size(), 0);
	std::cout << "473 ERR_INVITEONLYCHAN" << std::endl;
	return;
}

// void error_474(Client* client, Channel* channel);
void Errors::error_474(Client* client, Channel* channel)
{
	// if (client == nullptr || !client->isConnected())
	// 	return;

	std::string errorMsg = ":$(SERVER_NAME) 474 " + client->getNickname() + channel->getChannel() + " :Cannot join channel (+b)";
	send(client->fd, errorMsg.c_str(), errorMsg.size(), 0);
	std::cout << "474 ERR_BANNEDFROMCHAN" << std::endl;
	return;
}

// void error_475(Client* client, Channel* channel);
void Errors::error_475(Client* client, Channel* channel)
{
	// if (client == nullptr || !client->isConnected())
	// 	return;

	std::string errorMsg = ":$(SERVER_NAME) 475 " + client->getNickname() + channel->getChannel() + " :Cannot join channel (+k)";
	send(client->fd, errorMsg.c_str(), errorMsg.size(), 0);
	std::cout << "475 ERR_BADCHANNELKEY" << std::endl;
	return;
}

// void error_483(Client* client);
void Errors::error_483(Client* client)
{
	// if (client == nullptr || !client->isConnected())
	// 	return;

	std::string errorMsg = ":$(SERVER_NAME) 483 " + client->getNickname() + " :You cant kill a server!";
	send(client->fd, errorMsg.c_str(), errorMsg.size(), 0);
	std::cout << "483 ERR_CANTKILLSERVER" << std::endl;
	return;
}

// void error_491(Client* client);
void Errors::error_491(Client* client)
{
	// if (client == nullptr || !client->isConnected())
	// 	return;

	std::string errorMsg = ":$(SERVER_NAME) 491 " + client->getNickname() + " :No O-lines for your host";
	send(client->fd, errorMsg.c_str(), errorMsg.size(), 0);
	std::cout << "491 ERR_NOOPERHOST" << std::endl;
	return;
}

