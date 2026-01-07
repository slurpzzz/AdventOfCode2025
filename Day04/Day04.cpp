
#include <iostream>
#include <sstream>
#include <fstream>
#include <chrono>
#include <cmath>
#include <vector>
using namespace std;

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v)
{
	for (const auto& i : v) {
		os << i;
	}
	os << '\n';
	return os;
}

ifstream& operator>>(ifstream& ifs, vector<string>& v)
{
	string s;
	while (ifs >> s) {
		v.push_back(move(s));
	}
	return ifs;
}

bool canAccess(int row, int col, const vector<string>& grid)
{
	int rolls = 0;
	for (int i = row - 1; i <= row + 1; i++) {
		for (int j = col - 1; j <= col + 1; j++) {
			if (i >= 0 && j >= 0 && i < grid.size() && j < grid[i].size() && !(i == row && j == col)) {
				rolls += grid[i][j] == '@' ? 1 : 0;
			}
		}
	}
	return rolls < 4;
}

void part1()
{
	ifstream ifs{ "input.txt" };
	vector<string> grid;
	ifs >> grid;

	int accessibleRolls = 0;
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (grid[i][j] == '.') continue;
			if (canAccess(i, j, grid)) accessibleRolls++;
		}
	}
	cout << accessibleRolls << '\n';
}

void part2()
{
	ifstream ifs{ "input.txt" };
	vector<string> grid;
	ifs >> grid;
	int removedRolls = 0;
	int prev = -1;
	while (removedRolls != prev) {
		prev = removedRolls;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				if (grid[i][j] == '.' || grid[i][j] == 'x') continue;
				if (canAccess(i, j, grid)) {
					removedRolls++;
					grid[i][j] = 'x';
				}
			}
		}
	}
	cout << removedRolls << '\n';
	//cout << grid;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();
	part1();
	auto part1end = chrono::high_resolution_clock::now();
	part2();
	auto part2end = chrono::high_resolution_clock::now();

	cout << "Part 1: " << chrono::duration_cast<chrono::milliseconds>(part1end - start) << '\n';
	cout << "Part 2: " << chrono::duration_cast<chrono::milliseconds>(part2end - part1end) << '\n';
}
