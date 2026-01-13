
#include <bits/stdc++.h>
using namespace std;

void part1() {
  ifstream ifs{"./Day02/input.txt"};
  string range;
  long long sumInvalids = 0;
  while (getline(ifs, range, ',')) {
    istringstream iss(range);
    string lower_s, upper_s;
    getline(iss, lower_s, '-');
    getline(iss, upper_s);
    long long lower = stoll(lower_s);
    long long upper = stoll(upper_s);
    for (long long i = lower; i <= upper; i++) {
      int digits = floor(log10(i)) + 1;
      if (digits % 2 == 1)
        continue;
      int left = i / pow(10, digits / 2);
      int right = i % static_cast<int>(pow(10, digits / 2));
      if (left == right)
        sumInvalids += i;
    }
  }
  cout << sumInvalids << endl;
}

bool isInvalid_2(long long n) {
  string n_str = to_string(n);
  int digits = n_str.length();
  int maxSequence = digits / 2;
  string_view n_str_view(n_str);
  for (int i = 1; i <= maxSequence; i++) {
    if (digits % i != 0)
      continue;
    string_view seq = n_str_view.substr(0, i);
    int j = i;
    while (n_str_view.substr(j, i) == seq) {
      if (j + i == digits)
        return true;
      j += i;
    }
  }
  return false;
}

void part2() {
  ifstream ifs{"./Day02/input.txt"};
  string range;
  long long sumInvalids = 0;
  while (getline(ifs, range, ',')) {
    istringstream iss(range);
    string lower_s, upper_s;
    getline(iss, lower_s, '-');
    getline(iss, upper_s);
    unsigned long long lower = stoull(lower_s);
    unsigned long long upper = stoull(upper_s);
    for (unsigned long long i = lower; i <= upper; i++) {
      if (isInvalid_2(i))
        sumInvalids += i;
    }
  }
  cout << sumInvalids << endl;
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