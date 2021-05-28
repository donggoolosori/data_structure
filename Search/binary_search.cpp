#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &arr, int target) {
  int low = 0, high = arr.size() - 1;

  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == target) {
      return mid;
    }
    if (arr[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return -1;
}

int main() {
  vector<int> arr = {1, 3, 4, 7, 8, 11, 14, 21, 32, 42};
  // 14의 위치 탐색
  int idx = binarySearch(arr, 14);
  // 출력
  cout << idx << '\n';
  return 0;
}