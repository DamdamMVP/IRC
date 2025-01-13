#include "Client.hpp"
#include <unistd.h>

// Constructeur
Client::Client(int fd) : fd(fd), authenticated(false), hasPassword(false),
	hasNick(false), hasUser(false)
{
}

// Destructeur
Client::~Client()
{
	close(fd); // Ferme la connexion proprement
}

// Getters
int Client::getFd() const
{
	return (fd);
}
bool Client::isAuthenticated() const
{
	return (authenticated);
}
std::string Client::getNickname() const
{
	return (_nickname);
}
std::string Client::getUsername() const
{
	return (_username);
}
std::string Client::getRealname() const
{
	return (_realname);
}
std::string Client::getHostname() const
{
	return (_hostname);
}

bool Client::getHasPassword() const
{
	return hasPassword;
}

// Setters
void Client::setPassword(bool status)
{
	hasPassword = status;
}
void Client::setNickname(const std::string &nick)
{
	_nickname = nick;
	hasNick = true;
}
void Client::setUsername(const std::string &user, const std::string &real)
{
	_username = user;
	_realname = real;
	hasUser = true;
}
void Client::setHostname(const std::string &host)
{
	_hostname = host;
}

// Authentification
void Client::authenticate()
{
	if (hasPassword && hasNick && hasUser)
		authenticated = true;
}
