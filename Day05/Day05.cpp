
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

void part1()
{
	ifstream ifs{ "input.txt" };
	vector<pair<uint64_t, uint64_t>> freshRanges;
	string range;
	while (getline(ifs, range) && range != "") {
		istringstream range_iss{ range };
		string lower, upper;
		getline(range_iss, lower, '-');
		getline(range_iss, upper);
		freshRanges.push_back({ static_cast<uint64_t>(stoull(lower)), static_cast<uint64_t>(stoull(upper)) });
	}
	uint16_t freshIDs = 0;
	uint64_t ID;
	while (ifs >> ID) {
		for (uint16_t i = 0; i < freshRanges.size(); i++) {
			if (ID >= freshRanges[i].first && ID <= freshRanges[i].second) {
				freshIDs++;
				break;
			}
		}
	}
	ifs.close();
	cout << freshIDs << '\n';
}

void part2()
{
	ifstream ifs{ "input.txt" };
	vector<pair<uint64_t, uint64_t>> freshRanges;
	string range;
	while (getline(ifs, range) && range != "") {
		istringstream range_iss{ range };
		string lower, upper;
		getline(range_iss, lower, '-');
		getline(range_iss, upper);
		freshRanges.push_back({ static_cast<uint64_t>(stoull(lower)), static_cast<uint64_t>(stoull(upper)) });
	}

	for (uint16_t i = 1; i < freshRanges.size(); i++) {
		uint64_t first = freshRanges[i].first;
		uint64_t second = freshRanges[i].second;

		for (uint16_t j = 0; j < i; j++) {
			uint64_t cleanFirst = freshRanges[j].first;
			uint64_t cleanSecond = freshRanges[j].second;
			if (first < cleanFirst && second > cleanSecond) { //hangs off on both sides
				freshRanges.erase(freshRanges.begin() + i);
				freshRanges.push_back({ first, cleanFirst - 1 });
				freshRanges.push_back({ cleanSecond + 1, second });
				i--;
				break;
			} else if (first >= cleanFirst && second <= cleanSecond) { //fully overlaps within
				freshRanges.erase(freshRanges.begin() + i);
				i--;
				break;
			} else if (first <= cleanSecond && second > cleanSecond) { //overlaps on right side
				freshRanges[i].first = cleanSecond + 1;
			} else if (second >= cleanFirst && first < cleanFirst) { //overlaps on left side
				freshRanges[i].second = cleanFirst - 1;
			}
		}
	}
	uint64_t total = 0;
	for (const auto& range : freshRanges) {
		//cout << range.first << '\t' << range.second << '\n';
		total += (range.second - range.first) + 1;
	}
	cout << total;

	ifs.close();
}

int main()
{
	part1();
	part2();
}
