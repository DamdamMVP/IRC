#include "cpppue.hpp"

bool stricmp(const std::string &str, const std::string &str2)
{
    if (str.size() != str2.size())
        return false;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (std::tolower(str[i]) != std::tolower(str2[i]))
            return false;
    }
    return true;
}

void ClientManager::updateNickname(int fd, std::string nickname)
{
    if (_clients.find(fd) != _clients.end())
        setNickname(fd, nickname);
}
//------------------getters------------------

Client *ClientManager::getClient(int fd)
{
    return &_clients[fd];
}

int ClientManager::getFd(std::string username)
{
    std::map<int, Client>::iterator it = _clients.begin();
    while (it != _clients.end())
    {
        if (it->second.username == username)
            return it->first;
        it++;
    }
    return -1;
}

std::string ClientManager::getNickname(int fd)
{
    return _clients[fd].nickname;
}

std::string ClientManager::getClientname(int fd)
{
    return _clients[fd].username;
}

std::string ClientManager::getHostname(int fd)
{
    return _clients[fd].hostname;
}

const std::map<int, Client> &ClientManager::getClients() const
{
    return _clients;
}
// ------------------checkers------------------
bool ClientManager::isOperator(int fd)
{
    return _clients[fd].isOperator;
}

bool ClientManager::nicknameExists(std::string nickname)
{
    std::map<int, Client>::iterator it = _clients.begin();
    while (it != _clients.end())
    {
        if (stricmp(it->second.nickname, nickname))
            return true;
        it++;
    }
    return false;
}

bool ClientManager::userExists(int fd)
{
    return (_clients.find(fd) != _clients.end());
}

bool ClientManager::isAuthenticated(int fd)
{
    return _clients[fd].isAuthenticated;
}
// ------------------setters------------------
void ClientManager::setAuthenticated(int fd, bool isAuthenticated)
{
    _clients[fd].isAuthenticated = isAuthenticated;
}

void ClientManager::setOperator(int fd, bool isOperator)
{
    _clients[fd].isOperator = isOperator;
}

void ClientManager::setNickname(int fd, std::string nickname)
{
    _clients[fd].nickname = nickname;
}

void ClientManager::setClientname(int fd, std::string username)
{
    _clients[fd].username = username;
}

void ClientManager::setHostname(int fd, std::string hostname)
{
    _clients[fd].hostname = hostname;
}

ClientManager::ClientManager()
{
}

ClientManager::~ClientManager()
{
}

Client::Client() : nickname(""), username(""), hostname(""), isOperator(false), isAuthenticated(false)
{
}

Client::Client(std::string nickname) : nickname(nickname), username(""), hostname(""), isOperator(false), isAuthenticated(false)
{
}

Client::~Client()
{
}
