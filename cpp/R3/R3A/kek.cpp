#include <iostream>
#include <vector>

int main() {
  std::vector<std::vector<int> > keeeek;
  int n = 3;
  for (int i = 0; i < n; i++) {
    std::vector<int> temp;
    int t;
    for (int j = 0; j < n; j++) {
      std::cin >> t;
      temp.push_back(t);
    }
    keeeek.push_back(temp);
  }
  return 0;
}
