
//============================================================================
// Name        : main.cpp
// Author      : Matthijs
// Version     : 0.1
// Description : Raspberri Pi main program
//============================================================================
#define FILE_PATH "/var/www/html/PHP_CPP_COMM.json"
#include "JsonFile.h"

#include <iostream>
using namespace std;

int main() {

	JsonFile json(FILE_PATH);
	json.fill("{\"json\":\"JAAAAAAAAAAAAAAAAAAAAAAAAAAAAASOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOONNNNNNN!!!!!!!!!\"}");
	json.edit("Potmeter", 555);
	json.print();
	cout << "JAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAASOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOON!" << endl;
	return 0;
}
