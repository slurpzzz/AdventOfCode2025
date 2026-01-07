
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <chrono>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;
using std::cout;

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v)
{
	for (const auto& i : v) {
		os << i << '\n';
	}
	os << '\n';
	return os;
}

void part1()
{
	ifstream ifs{ "input.txt" };
	string line;
	vector<string> diagram{};
	while (getline(ifs, line, '\n')) {
		diagram.push_back(line);
	}
	//cout << diagram;
	int beamStart = diagram[0].find('S');
	diagram[1][beamStart] = '|';
	int splits = 0;
	for (int i = 1; i < diagram.size() - 1; i++) {
		for (int j = 1; j < diagram[i].size() - 1; j++) {
			if (diagram[i][j] == '|') {
				if (diagram[i + 1][j] == '.') {
					diagram[i + 1][j] = '|';
				} else if (diagram[i + 1][j] == '^') {
					splits++;
					diagram[i + 1][j - 1] = '|';
					diagram[i + 1][j + 1] = '|';
				}
			}
		}
	}
	//cout << diagram;
	cout << splits << '\n';
}

uint64_t searchTimelines(vector<string>& diagram, pair<int, int> cell, map<pair<int, int>, uint64_t>& cache)
{
	if (cache.find(cell) != cache.end()) {
		return cache[cell];
	}
	int i = cell.first;
	while (i < diagram.size() && diagram[i][cell.second] != '^') {
		i++;
	}
	if (i >= diagram.size()) return 1;
	if (cell.second == 0) {
		cache[cell] = searchTimelines(diagram, { i, cell.second + 1 }, cache);
		return cache[cell];
	}
	if (cell.second == diagram[i].size() - 1) {
		cache[cell] = searchTimelines(diagram, { i, cell.second - 1 }, cache);
		return cache[cell];
	}
	cache[cell] = searchTimelines(diagram, { i, cell.second - 1 }, cache) + searchTimelines(diagram, { i, cell.second + 1 }, cache);
	return cache[cell];
}

void part2()
{
	ifstream ifs{ "input.txt" };
	string line;
	vector<string> diagram{};
	while (getline(ifs, line, '\n')) {
		diagram.push_back(line);
	}
	int beamStart = diagram[0].find('S');
	diagram[1][beamStart] = '|';
	map<pair<int, int>, uint64_t> cache;
	cout << searchTimelines(diagram, { 1, beamStart }, cache) << '\n';
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
