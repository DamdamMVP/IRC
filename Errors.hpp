#ifndef ERRORS_HPP
#define ERRORS_HPP

#include "Client.hpp"
#include "Channel.hpp"

#include <string>
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>

void	error_443(Client* client, Channel* channel);
void	error_441(Client* client, Channel* channel);
void	error_476(Client* client, Channel* channel);
void	error_403(Client* client, Channel* channel);
void	error_442(Client* client, Channel* channel);
void	error_461(Client* client, std::string command);
void	error_482(Client* client, Channel* channel);
void	error_501(Client* client);
void	error_431(Client* client);
void	error_432(Client* client, std::string target_nick);
void	error_433(Client* client, std::string target_nick);
void	error_436(Client* client, std::string target_nick);
void	error_401(Client* client, std::string target_nick);
void	error_402(Client* client, std::string target_server);
void	error_404(Client* client, Channel* channel);
void	error_411(Client* client);
void	error_412(Client* client);
void	error_462(Client* client);
void	error_405(Client* client, Channel* channel);
void	error_406(Client* client, std::string target_nick);
void	error_409(Client* client);
void	error_417(Client* client);
void	error_421(Client* client);
void	error_451(Client* client);
void	error_464(Client* client);
void	error_465(Client* client);
void	error_471(Client* client, Channel* channel);
void	error_472(Client* client, std::string mode_char);
void	error_473(Client* client, Channel* channel);
void	error_474(Client* client, Channel* channel);
void	error_475(Client* client, Channel* channel);
void	error_483(Client* client);
void	error_491(Client* client);


#endif