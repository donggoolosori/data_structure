#include <iostream>
#include <vector>

using namespace std;

// 오름차순 선택 정렬
void insertion_sort(vector<int> &arr) {
  int size = arr.size();
  for (int i = 1; i < size; i++) {
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
      swap(arr[j - 1], arr[j]);
      j--;
    }
  }
}
// 모든 원소 출력
void print(vector<int> &arr) {
  for (const int &n : arr) cout << n << ' ';
}

int main() {
  vector<int> arr = {9, 7, 3, 5, 1, 10, 2, 6, 8, 4};
  insertion_sort(arr);
  print(arr);

  return 0;
}