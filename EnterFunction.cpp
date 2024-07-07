#include <iostream>
#include "EnterFunction.h"
void pressEnter(const std::string& text) {

	std::cout << "Press [ENTER] " << text << '\n';
	std::cin.ignore();
};
void pressEnter() {
	pressEnter("to Continue");
};