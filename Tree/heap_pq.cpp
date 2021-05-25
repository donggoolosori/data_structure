// heap자료구조로 우선순위 큐 구현
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Heap {
 private:
  vector<T> heap;

 public:
  bool empty() { return heap.size() == 0 ? true : false; }
  void push(T data) {
    heap.push_back(data);
    int idx = heap.size() - 1;
    while (idx > 0 && heap[(idx - 1) / 2] < heap[idx]) {
      swap(heap[idx], heap[(idx - 1) / 2]);
      idx = (idx - 1) / 2;
    }
  }
  void pop() {
    heap[0] = heap.back();
    heap.pop_back();
    int curr = 0;

    while (true) {
      int left = curr * 2 + 1, right = curr * 2 + 2;
      if (left >= heap.size()) break;

      int next = curr;
      if (heap[next] < heap[left]) next = left;
      if (right < heap.size() && heap[next] < heap[right]) next = right;
      if (next == curr) break;

      swap(heap[next], heap[curr]);
      curr = next;
    }
  }
  T top() {
    if (empty()) {
      cout << "Error: 힙이 비어있습니다.";
      exit(-1);
    }
    return heap[0];
  }
};

int main() {
  Heap<int> heap;
  heap.push(5);
  heap.push(2);
  heap.push(9);
  heap.push(1);

  while (!heap.empty()) {
    cout << heap.top() << ' ';
    heap.pop();
  }

  return 0;
}