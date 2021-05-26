#include <iostream>
#include <vector>
using namespace std;

vector<int> arr = {38, 27, 43, 9, 3, 82, 10};

void quick_sort(int start, int end) {
  if (start >= end) return;
  int pivot = start;  // 맨 처음 수를 pivot으로 설정
  int low = start + 1, high = end;

  while (low <= high) {
    while (arr[low] <= arr[pivot] && low <= end) low++;
    while (arr[high] >= arr[pivot] && high > start) high--;

    if (low > high)  // 엇갈린 상태면 pivot과 high 교체
      swap(arr[pivot], arr[high]);
    else  // 엇갈리지 않았으면 low high 교체
      swap(arr[low], arr[high]);
  }
  // 재귀 호출
  quick_sort(start, high - 1);
  quick_sort(high + 1, end);
}

// 모든 원소 출력
void print() {
  for (const int &n : arr) cout << n << ' ';
}

int main() {
  // 퀵정렬 수행
  quick_sort(0, 6);
  // 결과 출력 : 3 9 10 27 38 43 82
  print();

  return 0;
}