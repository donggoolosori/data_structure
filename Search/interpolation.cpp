// 보간 탐색
// 재귀
#include <iostream>
#include <vector>

using namespace std;

int interpolation(vector<int> &arr, int low, int high, const int target) {
  if (arr[low] > target || arr[high] < target) return -1;
  int mid =
      (double)(target - arr[low]) / (arr[high] - arr[low]) * (high - low) + low;
  if (arr[mid] == target) {
    return mid;
  }
  if (arr[mid] < target) {
    return interpolation(arr, mid + 1, high, target);
  } else {
    return interpolation(arr, low, mid - 1, target);
  }
}

int main() {
  vector<int> arr = {1, 6, 11, 16, 21, 26, 31, 36, 41, 46, 51, 56, 61};
  // 46의 위치 보간 탐색
  int idx = interpolation(arr, 0, arr.size() - 1, 46);
  // 출력 > 9
  cout << idx << '\n';
  return 0;
}