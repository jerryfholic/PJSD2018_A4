/*
 * TCP_Client.h
 *
 *  Created on: Dec 3, 2018
 *      Author: programmer
 */

#ifndef TCP_CLIENT_H_
#define TCP_CLIENT_H_

#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <unistd.h>


using namespace std;

class TCP_Client
{
public:
	TCP_Client(const char *address, int port);
	void TCP_socket();
	void createSocket();
	bool connectToServer(string, int);
	bool sendString(char const *str);

	void receive();

private:
	int sock;
	int port;
	struct sockaddr_in serv_addr;
	const char *ip_address;
	char buffer[1024];
	int valread;

};

#endif /* TCP_CLIENT_H_ */
