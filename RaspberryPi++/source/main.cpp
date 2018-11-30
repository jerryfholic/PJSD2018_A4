
//============================================================================
// Name        : main.cpp
// Author      : Matthijs
// Version     : 0.1
// Description : Raspberri Pi main program
//============================================================================
#define FILE_PATH "/var/www/html/PHP_CPP_COMM.json" //Path to the JSON file used, change if necessary

//GPIO Pin 18
#define LED_GPIO "18"
#define LED_GPIO_PATH "/sys/class/gpio/gpio18/"
#define GPIO_SYSFS "/sys/class/gpio/"

#include <iostream>
#include <fstream>
#include <thread>

#include "JsonFile.h"

using namespace std;

void LED_Setup();
void writeFile(const char* filepath, const char* value);
void writeValToLED(int val);

int main() {

	LED_Setup();

	JsonFile json(FILE_PATH);

	for(int i = 0; i < 600; i++) {
		this_thread::sleep_for(chrono::microseconds(1000000));	//Wait for 1 second
		json.edit("Potmeter", i);								//Edit value for key "Potmeter"
		writeValToLED(json.getIntValue("ToggleLed"));			//Write value for key "ToggleLed" to the LED
		json.print();											//Print the contents of the JSON file
	}
	return 0;
}

void writeFile(const char* filepath, const char* value) {
	ofstream file;			//Outputstream for writng to file
	file.open(filepath);	//Open the file
	file << value;			//Write value to file
	file.close();			//Close the file
}

void LED_Setup() {
	writeFile(GPIO_SYSFS "export", LED_GPIO);
	writeFile(LED_GPIO_PATH "direction", "out");
}

void writeValToLED(int val) {
	if(0 < val && val <= 1) {
		writeFile(LED_GPIO_PATH "value", to_string(val).c_str() );
	} else {
		cout << "Invalid LED value" << endl;
	}
}
