#pragma once

#include <netinet/in.h>
#include <string>
#include <map>

class Client
{
  private:
	int fd;                          // Descripteur de fichier du client
	bool authenticated;              // Indique si le client est authentifié
	bool hasPassword;                // Le client a-t-il envoyé PASS ?
	bool hasNick;                    // Le client a-t-il envoyé NICK ?
	bool hasUser;                    // Le client a-t-il envoyé USER ?
	std::string _nickname;            // Pseudo
	std::string _username;            // Nom d'utilisateur
	std::string _realname;            // Nom complet
	std::string _hostname;            // Adresse IP/Hostname

  public:
	// Constructeur
	Client(int fd);
	// Destructeur
	~Client();

	// Getters
	int getFd() const;
	bool isAuthenticated() const;
	std::string getNickname() const;
	std::string getUsername() const;
	std::string getRealname() const;
	std::string getHostname() const;
	bool getHasPassword() const;

	// Setters
	void setPassword(bool status);
	void setNickname(const std::string &nick);
	void setUsername(const std::string &user, const std::string &real);
	void setHostname(const std::string &host);
	void authenticate();
};
