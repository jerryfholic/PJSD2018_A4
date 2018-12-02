// Client side C/C++ program to demonstrate Socket programming
// Geeks for Geeks and additions by Mathieu

#define FILE_PATH "/home/pi/Documents/PI_client/client.json"

#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "JsonFile.h"
#include <iostream>
#define PORT 3000

using namespace std;

int main(int argc, char const *argv[])
{
    int value = 0;
    JsonFile json(FILE_PATH);
    value = json.getIntValue("LedValue");
    //json.print();
    //json.edit("LedValue", 7);
    //json.print();
    //int value = 8;
    struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char const *buttons = "BUTTONS";
    char const *leds = "LEDS";
    char buffer[512] = {0};
    char buffer2[512] = {0};


    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
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

    send(sock , leds , strlen(leds) , 0 );
    valread = read( sock , buffer, 512);
    printf("%s\n",buffer );
    buffer[512] = {0};

    //write()
    send(sock , &value , 1 , 0);
    printf("Leds data sent\n");

    send(sock , buttons , strlen(buttons), 0 );
    printf("Button request\n");
    valread = read( sock , buffer2, 512);
    printf("Button value = %s\n", buffer2);
    buffer2[1024] = {0};
    return 0;
}
