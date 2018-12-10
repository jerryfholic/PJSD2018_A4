/*
 * TCP_Client.cpp
 *
 *  Created on: Dec 3, 2018
 *      Author: programmer
 */

#include "TCP_Client.h"

TCP_Client::TCP_Client(const char* address, int poort)
{
	ip_address = address;
	port = poort;
	TCP_socket();
	createSocket();
}

void TCP_Client::TCP_socket()
{
	sock = -1;
}

void TCP_Client::createSocket()
{
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock == -1)
	{
		//TODO Socket creating error
	}
	cout  << "Socket created\n";
}

bool TCP_Client::connectToServer(string address, int)
{
	//create socket if it isnt created yet!
	if(sock == -1)
	{
		createSocket();
	}
	else{}

	memset(&serv_addr, 0, sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);



	//IP address conversion to binary
	if(inet_pton(AF_INET, "192.168.4.3", &serv_addr.sin_addr)<=0)
	    {
	        printf("\nInvalid address/ Address not supported \n");
	        return -1;
	    }

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	    {
	        printf("\nConnection Failed \n");
	        return -1;
	    }
	return 0;
}


bool TCP_Client::sendString(char const *str)
{
	send(sock, str, strlen(str), 0);
	return 0;
}

void TCP_Client::receive()
{
	valread = read(sock, buffer, 1024);
	printf("%s\n",buffer);
	buffer[1024] = {0};
}
