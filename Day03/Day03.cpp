
#include <bits/stdc++.h>
using namespace std;

void part1() {
  ifstream ifs{"./Day03/input.txt"};
  string bank;
  int totalJoltage = 0;
  while (ifs >> bank) {
    int max = 0;
    int max_index = 0;
    int second_max = 0;
    int second_max_index = 0;
    for (int i = 0; i < bank.length() - 1; i++) {
      int battery = bank[i] - '0';
      if (battery > max) {
        max = battery;
        max_index = i;
        second_max = 0;
      } else if (battery > second_max) {
        second_max = battery;
        second_max_index = i;
      }
    }
    int battery = bank[bank.length() - 1] - '0';
    if (battery > second_max) {
      second_max = battery;
      second_max_index = bank.length() - 1;
    }
    totalJoltage += max * 10 + second_max;
  }
  cout << totalJoltage << endl;
}

void part2() {
  ifstream ifs{"./Day03/input.txt"};
  string bank;
  long long int totalJoltage = 0;
  while (ifs >> bank) {
    int rightmostCellIndex = -1;
    int remainingCells = 11;
    while (remainingCells >= 0) {
      string subBank =
          bank.substr(rightmostCellIndex + 1, bank.length() - remainingCells -
                                                  (rightmostCellIndex + 1));
      int cell = -1;
      int tmp = rightmostCellIndex;
      for (int i = 0; i < subBank.length(); i++) {
        int battery = subBank[i] - '0';
        if (battery > cell) {
          cell = battery;
          rightmostCellIndex = tmp + i + 1;
        }
      }
      // cout << cell;
      totalJoltage += cell * pow(10, remainingCells);
      remainingCells--;
    }
    // cout << '\n';
  }
  cout << totalJoltage << endl;
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
