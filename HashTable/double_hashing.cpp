// 학번으로 학생이름 찾기
// 이중해쉬 해쉬테이블
#include <iostream>
#include <string>

using namespace std;

enum Status { EMPTY, INUSE, DELETED };

class Slot {
 private:
  int id;
  string name;
  Status status;

 public:
  Slot() {}
  Slot(int id, string name, Status status)
      : id(id), name(name), status(status) {}
  void setStatus(Status status) { this->status = status; }
  Status getStatus() { return status; }
  int getId() { return id; }
  string getName() { return name; }
};

class HashTable {
 private:
  int size;
  Slot* hashTable;
  int hashFunction1(int id) { return id % size; }
  int hashFunction2(int id) { return 1 + id % 7; }

 public:
  HashTable(int size) : size(size) { hashTable = new Slot[size]; }
  void put(int id, string name) {
    int key = hashFunction1(id);
    int jump = hashFunction2(id);
    // 데이터를 넣을 수 있는 인덱스를 탐색
    while (hashTable[key].getStatus() != EMPTY) {
      key = (key + jump) % size;
    }
    hashTable[key] = Slot(id, name, INUSE);
  }
  string get(int id) {
    int key = hashFunction1(id);
    int jump = hashFunction2(id);
    while (hashTable[key].getStatus() != EMPTY) {
      if (hashTable[key].getId() == id) {
        return hashTable[key].getName();
      }
      key = (key + jump) % size;
    }
    return "Not Exists";
  }
  void showAllData() {
    for (int i = 0; i < size; i++) {
      int key = hashFunction1(hashTable[i].getId());
      int jump = hashFunction2(hashTable[i].getId());
      string name = hashTable[i].getName();
      Status status = hashTable[i].getStatus();
      cout << "Key: " << key << ", Jump: " << jump << ", Name: " << name
           << ", Status: " << status << '\n';
    }
  }
  ~HashTable() { delete[] hashTable; }
};

int main() {
  HashTable hashTable(10);
  hashTable.put(10, "김동준");
  hashTable.put(20, "김은현");
  hashTable.put(30, "신재현");
  hashTable.put(7, "김현진");

  cout << hashTable.get(10) << '\n';
  cout << hashTable.get(20) << '\n';
  cout << hashTable.get(30) << '\n';
  cout << hashTable.get(7) << '\n';

  hashTable.showAllData();
  return 0;
}