// 연결리스트 구현
#include <iostream>

using namespace std;

template <typename T>
class Node {
 private:
  T data;
  Node<T> *next;

 public:
  Node(T data) : data(data), next(NULL){};
  T getData() { return data; }
  Node<T> *getNext() { return next; }
  void setNext(Node<T> *next) { this->next = next; }
};

template <typename T>
class List {
 private:
  int list_size;
  Node<T> *head, *tail;

 public:
  // list에 저장된 데이터 수 반환
  int size() { return list_size; }
  bool empty() { return list_size == 0 ? true : false; }
  // 삽입
  void insert(T data) {
    list_size++;
    Node<T> *newNode = new Node<T>(data);
    if (head == NULL) {
      head = newNode;
    } else {
      tail->setNext(newNode);
    }
    tail = newNode;
  }
  // 특정 인덱스에 삽입
  void insert(T data, int index) {
    if (index > list_size) {
      cout << "삽입가능 범위가 아닙니다\n";
      return;
    }
    list_size++;
    Node<T> *newNode = new Node<T>(data);
    Node<T> *prev = NULL;
    Node<T> *curr = head;
    int cnt = 0;
    while (true) {
      if (cnt == index) {
        if (cnt == 0) {
          newNode->setNext(head);
          head = newNode;
        } else if (cnt == list_size - 1) {
          insert(data);
          list_size--;  // insert 함수에서 중복으로 size 증가
        } else {
          prev->setNext(newNode);
          newNode->setNext(curr);
        }
        return;
      }
      prev = curr;
      curr = curr->getNext();
      cnt++;
    }
  }
  // 가장 앞의 데이터 반환
  T front() {
    if (head == NULL) {
      return -1;
    } else {
      return head->getData();
    }
  }
  // 가장 뒤 데이터 반환
  T back() {
    if (tail == NULL) {
      return -1;
    } else {
      return tail->getData();
    }
  }
  // 특정 인덱스 삭제
  void erase(int index) {
    if (index >= list_size) {
      cout << "인덱스 범위가 올바르지 않습니다.\n";
      return;
    }
    int cnt = 0;
    Node<T> *prev = NULL;
    Node<T> *curr = head;
    if (index == 0) {
      head = head->getNext();
      delete curr;
      return;
    }
    while (curr != NULL) {
      if (cnt == index) {
        prev->setNext(curr->getNext());
        delete curr;
        if (cnt == list_size - 1) {
          tail = prev;
        }
        list_size--;
        return;
      }
      cnt++;
      prev = curr;
      curr = curr->getNext();
    }
  }
  // 데이터 모두 출력
  void showAll() {
    Node<T> *curr = head;
    while (curr != NULL) {
      cout << curr->getData() << " -> ";
      curr = curr->getNext();
    }
  }
  ~List() {
    if (empty()) return;
    Node<T> *next = head->getNext();
    Node<T> *curr = head;

    while (curr != NULL) {
      delete curr;
      curr = next;
      if (next != NULL) next = next->getNext();
    }
  }
};

int main() {
  List<int> list;
  // 뒤에서부터 insert
  list.insert(3);
  list.insert(7);
  list.insert(2);
  list.insert(4);
  list.insert(5);
  list.insert(9);
  list.insert(10);
  list.insert(7);
  list.insert(6);
  list.insert(1);

  // index 8의 원소 삭제
  list.erase(8);
  // 11을 index 2 위치에 삽입
  list.insert(11, 2);

  cout << "front: " << list.front() << '\n';
  cout << "back: " << list.back() << '\n';
  cout << "size: " << list.size() << '\n';
  list.showAll();

  return 0;
}