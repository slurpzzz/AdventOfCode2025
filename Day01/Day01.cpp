
#include <bits/stdc++.h>
using namespace std;

void part1() {
  ifstream ifs{"./Day01/input.txt"};
  string input;
  int pw = 0;
  int dialPos = 50;
  while (ifs >> input) {
    char dir = input[0];
    int amount = stoi(input.substr(1, input.size() - 1));
    if (dir == 'L') {
      dialPos -= amount;
      while (dialPos < 0)
        dialPos += 100;
    } else {
      dialPos += amount;
      while (dialPos > 99)
        dialPos -= 100;
    }
    if (dialPos == 0)
      pw++;
  }
  cout << pw << endl;
}

void part2() {
  ifstream ifs{"./Day01/input.txt"};
  string input;
  int pw = 0;
  int dialPos = 50;
  while (ifs >> input) {
    char dir = input[0];
    int amount = stoi(input.substr(1, input.size() - 1));
    if (dir == 'L') {
      for (int i = 0; i < amount; i++) {
        dialPos--;
        if (dialPos < 0)
          dialPos += 100;
        else if (dialPos == 0)
          pw++;
      }
    } else {
      for (int i = 0; i < amount; i++) {
        dialPos++;
        if (dialPos > 99)
          dialPos -= 100;
        if (dialPos == 0)
          pw++;
      }
    }
  }
  cout << pw << endl;
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
