/*
1. 분할정복 방식의 정렬
2. 재귀적으로 배열을 분할해준다
3. 각각의 파티션들을 합치며 정렬하는 방식
4. n*log(n)의 시간복잡도
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> temp(7);
vector<int> arr = {38, 27, 43, 9, 3, 82, 10};

void merge(int left, int right) {
  int mid = (left + right) / 2;
  // lIdx: 왼쪽 부분배열의 인덱스, rIdx: 오른쪽 부분배열의 인덱스, k: 현재까지
  // 병합 한 인덱스
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

// 더 이상 분할 되지 않을 때까지 분할한 후
// merge 함수를 호출하여 병합한다.
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
  // 병합정렬 수행
  merge_sort(0, 6);
  // 결과 출력 : 3 9 10 27 38 43 82
  print();

  return 0;
}