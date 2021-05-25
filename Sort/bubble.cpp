#include <iostream>
#include <vector>

using namespace std;

// 오름차순 버블 정렬
void bubble_sort(vector<int> &arr) {
  int size = arr.size();
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
    }
  }
}
// 모든 원소 출력
void print(vector<int> &arr) {
  for (const int &n : arr) cout << n << ' ';
}

int main() {
  vector<int> arr = {9, 7, 3, 5, 1, 10, 2, 6, 8, 4};
  bubble_sort(arr);
  print(arr);

  return 0;
}