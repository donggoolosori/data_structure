#include <iostream>
#include <vector>

using namespace std;

vector<int> arr = {9, 7, 3, 5, 1, 10, 2, 6, 8, 4};
vector<int> temp(10);

void merge(int left, int right) {
  int mid = (left + right) / 2;
  int lIdx = left, rIdx = mid + 1, k = left;

  while (k <= right) {
    if (lIdx > mid) {
      temp[k++] = arr[rIdx++];
      continue;
    }
    if (rIdx > right) {
      temp[k++] = arr[lIdx++];
      continue;
    }
    if (arr[lIdx] <= arr[rIdx])
      temp[k++] = arr[lIdx++];
    else
      temp[k++] = arr[rIdx++];
  }
  for (int i = left; i <= right; i++) arr[i] = temp[i];
}

// 오름차순 병합 정렬
void merge_sort(int left, int right) {
  if (left >= right) return;
  int mid = (left + right) / 2;
  merge_sort(left, mid);
  merge_sort(mid + 1, right);
  merge(left, right);
}
// 모든 원소 출력
void print() {
  for (const int &n : temp) cout << n << ' ';
}

int main() {
  // arr 벡터에 병합정렬 수행
  merge_sort(0, arr.size() - 1);
  // 정렬결과 출력
  print();

  return 0;
}