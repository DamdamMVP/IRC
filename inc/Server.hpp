/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <gbruscan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:09:29 by gbruscan          #+#    #+#             */
/*   Updated: 2025/01/13 23:19:33 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include "Client.hpp"
# include <map>
# include <poll.h>
# include <string>

class	Client;

class Server
{
  private:
	int server_fd;
	int epoll_fd; // Descripteur pour epoll
	int port;
	std::string password;
	std::map<int, Client *> _clients; // Gestion des clients connectés

  public:
	Server(int port, const std::string &password);
	~Server();
	void run();
	void setupSocket();
	void acceptNewClient();
	void handleClientMessage(int fd);
};

#endif
