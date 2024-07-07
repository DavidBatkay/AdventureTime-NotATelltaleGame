#include "Repeat.h"
#include <iostream>
std::string repeat(const std::string& text, int times) {
	std::string result;
	for (int i = 0; i < times; ++i) {
		result += text;
	}
	return result;
}