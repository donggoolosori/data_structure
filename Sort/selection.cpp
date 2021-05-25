#include <iostream>
#include <vector>

using namespace std;

// 오름차순 선택 정렬
void selection_sort(vector<int> &arr) {
  int size = arr.size();
  for (int i = 0; i < size; i++) {
    int minIdx = i, minValue = arr[i];
    for (int j = i + 1; j < size; j++) {
      if (arr[j] < minValue) {
        minValue = arr[j];
        minIdx = j;
      }
    }
    swap(arr[i], arr[minIdx]);
  }
}
// 모든 원소 출력
void print(vector<int> &arr) {
  for (const int &n : arr) cout << n << ' ';
}

int main() {
  vector<int> arr = {9, 7, 3, 5, 1, 10, 2, 6, 8, 4};
  selection_sort(arr);
  print(arr);

  return 0;
}