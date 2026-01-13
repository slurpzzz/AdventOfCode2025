
#include <bits/stdc++.h>
using namespace std;

void part1() {
  // process nums
  ifstream ifs{"./Day06/input.txt"};
  if (!ifs) {
    cerr << "Could not open file" << endl;
    return;
  }
  string line;
  getline(ifs, line, '\n');
  uint32_t numProblems = 0;
  istringstream line1_iss{line};
  uint32_t n;
  while (line1_iss >> n) {
    numProblems++;
  }
  ifs.clear();
  ifs.seekg(0, ios::beg);
  line1_iss.clear();

  vector<vector<uint32_t>> problems(numProblems);
  vector<char> operators(numProblems);
  while (getline(ifs, line)) {
    uint32_t i = 0;
    istringstream line_iss{line};
    if (line.find('+') == string::npos && line.find('*') == string::npos) {
      while (line_iss >> n) {
        if (i >= problems.size())
          i = 0;
        problems[i].push_back(n);
        i++;
      }
    } else {
      while (line_iss >> operators[i]) {
        i++;
        if (i >= problems.size())
          break;
      }
    }
  }
  ifs.clear();

  uint64_t total = 0;
  for (uint32_t i = 0; i < problems.size(); i++) {
    uint64_t result = problems[i][0];
    for (uint32_t j = 1; j < problems[i].size(); j++) {
      if (operators[i] == '*')
        result *= problems[i][j];
      else if (operators[i] == '+')
        result += problems[i][j];
    }
    total += result;
  }
  cout << total << '\n';
}

void part2() {
  ifstream ifs{"./Day06/input.txt"};
  if (!ifs) {
    cerr << "Could not open file" << endl;
    return;
  }
  string line;
  getline(ifs, line, '\n');
  ifs.clear();
  ifs.seekg(0, ios::beg);
  vector<string> problems(line.length());
  while (getline(ifs, line, '\n')) {
    if (line.find('+') != string::npos || line.find('*') != string::npos)
      break;
    istringstream iss{line};
    for (uint32_t i = 0; i < problems.size(); i++) {
      char c;
      iss.get(c);
      problems[i] += c;
    }
  }

  char op;
  istringstream iss{line};
  iss >> op;
  uint64_t total = 0;
  uint64_t result = stoull(problems[0]);
  for (uint32_t i = 1; i < problems.size(); i++) {
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

int main() {
  auto start = chrono::high_resolution_clock::now();
  part1();
  auto part1end = chrono::high_resolution_clock::now();
  part2();
  auto part2end = chrono::high_resolution_clock::now();

  cout << "Part 1: "
       << chrono::duration_cast<chrono::milliseconds>(part1end - start) << '\n';
  cout << "Part 2: "
       << chrono::duration_cast<chrono::milliseconds>(part2end - part1end)
       << '\n';
}
