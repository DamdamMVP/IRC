#include "Server.hpp"
#include "Channel.hpp"
#include "Client.hpp"
#include "Tokenisation.hpp"

bool Server::validateTopic(const TokenisedCommand &cmd, int fd) {
    (void)cmd;
	(void)fd;
    return true;
}

void Server::doTopic(const TokenisedCommand &cmd, int fd) {
    (void)cmd;
	(void)fd;
}