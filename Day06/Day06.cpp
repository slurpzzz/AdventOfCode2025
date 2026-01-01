
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

void part1()
{
	// process nums
	ifstream ifs{ "input.txt" };
	string line;
	getline(ifs, line, '\n');
	int numProblems = 0;
	istringstream line1_iss{ line };
	int n;
	while (line1_iss >> n) {
		numProblems++;
	}
	ifs.clear();
	ifs.seekg(0, ios::beg);
	line1_iss.clear();

	vector<vector<int>> problems(numProblems);
	vector<char> operators(numProblems);
	while (getline(ifs, line)) {
		int i = 0;
		istringstream line_iss{ line };
		if (line.find('+') == string::npos && line.find('*') == string::npos) {
			while (line_iss >> n) {
				if (i >= problems.size()) i = 0;
				problems[i].push_back(n);
				i++;
			}
		} else {
			while (line_iss >> operators[i]) {
				i++;
				if (i >= problems.size()) break;
			}
		}
	}
	ifs.clear();

	uint64_t total = 0;
	for (int i = 0; i < problems.size(); i++) {
		uint64_t result = problems[i][0];
		for (int j = 1; j < problems[i].size(); j++) {
			if (operators[i] == '*') result *= problems[i][j];
			else if (operators[i] == '+') result += problems[i][j];
		}
		total += result;
	}
	cout << total << '\n';
}

void part2()
{
	ifstream ifs{ "input.txt" };
	string line;
	getline(ifs, line, '\n');
	ifs.clear();
	ifs.seekg(0, ios::beg);
	vector<string> problems(line.length());
	while (getline(ifs, line, '\n')) {
		if (line.find('+') != string::npos || line.find('*') != string::npos)
			break;
		istringstream iss{ line };
		for (int i = 0; i < problems.size(); i++) {
			char c;
			iss.get(c);
			problems[i] += c;
		}
	}

	char op;
	istringstream iss{ line };
	iss >> op;
	uint64_t total = 0;
	uint64_t result = stoull(problems[0]);
	for (int i = 1; i < problems.size(); i++) {
		erase(problems[i], ' ');
		if (problems[i] == "") {
			iss >> op;
			total += result;
			result = stoull(problems[++i]);
		} else {
			if (op == '+') {
				result += stoull(problems[i]);
			} else {
				result *= stoull(problems[i]);
			}
		}
	}
	total += result;
	cout << total << '\n';
}

int main()
{
	part1();
	part2();
}

// 10695785254836
// 10695785245101