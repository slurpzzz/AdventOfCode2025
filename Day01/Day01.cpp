
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>

void part1()
{
	std::ifstream ifs{ "input.txt" };
	std::string input;
	int pw = 0;
	int dialPos = 50;
	while (ifs >> input) {
		char dir = input[0];
		int amount = std::stoi(input.substr(1, input.size() - 1));
		if (dir == 'L') {
			dialPos -= amount;
			while (dialPos < 0) dialPos += 100;
		} else {
			dialPos += amount;
			while (dialPos > 99) dialPos -= 100;
		}
		if (dialPos == 0) pw++;
	}
	std::cout << pw << std::endl;
}

void part2()
{
	std::ifstream ifs{ "input.txt" };
	std::string input;
	int pw = 0;
	int dialPos = 50;
	while (ifs >> input) {
		char dir = input[0];
		int amount = std::stoi(input.substr(1, input.size() - 1));
		if (dir == 'L') {
			for (int i = 0; i < amount; i++) {
				dialPos--;
				if (dialPos < 0) dialPos += 100;
				else if (dialPos == 0) pw++;
			}
		} else {
			for (int i = 0; i < amount; i++) {
				dialPos++;
				if (dialPos > 99) dialPos -= 100;
				if (dialPos == 0) pw++;
			}
		}
	}
	std::cout << pw << std::endl;
}

int main()
{
	part1();
	part2();
}
