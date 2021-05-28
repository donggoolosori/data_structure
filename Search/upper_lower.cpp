#include <iostream>
#include <vector>

using namespace std;

int lowerCase(vector<int> &arr, int target) {
  int low = 0, high = arr.size() - 1;

  while (low < high) {
    int mid = (low + high) / 2;
    if (arr[mid] >= target) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }

  return low;
}

int upperCase(vector<int> &arr, int target) {
  int low = 0, high = arr.size() - 1;

  while (low < high) {
    int mid = (low + high) / 2;
    if (arr[mid] <= target) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }

  return low;
}

int main() {
  vector<int> arr = {1, 3, 4, 4, 4, 7, 8, 11, 11, 12, 14, 21, 32, 42};
  // 4의 lower case 위치
  int lower = lowerCase(arr, 4);
  // 11의 upper case 위치
  int upper = upperCase(arr, 11);
  // 출력 > lower: 2, upper: 9
  cout << "lower: " << lower << '\n';
  cout << "upper: " << upper << '\n';

  return 0;
}