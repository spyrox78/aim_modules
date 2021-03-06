/**
 * @file HorizonModuleExt.cpp
 * @brief HorizonModule extension
 *
 * This file is created at "Distributed Organisms B.V.". It is open-source software and part of "Robotic Suite". 
 * This software is published under the GNU General Lesser Public license (LGPLv3).
 *
 * Copyright © 2013 Anne C. van Rossum <anne@dobots.nl>
 *
 * @author                   Anne C. van Rossum
 * @date                     Oct 28, 2013
 * @organisation             Distributed Organisms B.V.
 * @project                  Robotic Suite
 */

#include <HorizonModuleExt.h>
#include <iostream>

using namespace rur;

//! Replace with your own code
HorizonModuleExt::HorizonModuleExt(): controller(NULL) {
}

//! Replace with your own code
HorizonModuleExt::~HorizonModuleExt() {
	if (controller != NULL) {
		controller->disconnect();		
		delete controller;
	}
}

//! Set controller to the same IP address
void HorizonModuleExt::SetController(std::string address) {
	if (controller != NULL) {
		controller->disconnect();
		delete controller;	
	}
	controller = new horizonremote::RemoteController(address.c_str());
	controller->connect();
	std::cout << "State: " << (int)controller->state() << std::endl;
	controller->toggle_key(0xe007);
	//controller->toggle_key(0xe301);
}

void HorizonModuleExt::Tick() {
	std::string* ip_address = readAddress(false);
	if (ip_address) {
		std::cout << "Set ip address to " << *ip_address << std::endl;
		SetController(*ip_address);
	}

	if (controller == NULL) return;

	int* channel = readChannel(false);
	if (channel) {
		std::vector<int> digits;
		getDigits(*channel, digits);
		for (int i = 0; i < digits.size(); ++i) {
			unsigned short key = 0xe300+digits[i];
			std::cout << "Send key 0x" << std::hex << key << std::endl;
			controller->toggle_key(key);
		}
	}

	std::string *cmd = readCommand(false);
	if (cmd) {
		std::string scmd = *cmd;
		std::cout << "Send command " << scmd << std::endl;
		std::cout << " Pause command is e.g.: " << STR_PAUSE << std::endl;
		unsigned short key = getKey(scmd);
		std::cout << "Send key 0x" << std::hex << key << std::endl;
		controller->toggle_key(key);
	}
}

bool HorizonModuleExt::Stop() {
	return false;
}

