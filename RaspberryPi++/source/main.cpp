// Client side C/C++ program to demonstrate Socket programming
// Geeks for Geeks and additions by Mathieu

#define FILE_PATH "/home/pi/Documents/PI_client/client.json"

#include <stdio.h>
#include "JsonFile.h"
#include "TCP_Client.h"
#define PORT 3000

using namespace std;

int main()
{
	TCP_Client a("192.168.178.5", PORT);
	a.connectToServer();

	return 0;
}
