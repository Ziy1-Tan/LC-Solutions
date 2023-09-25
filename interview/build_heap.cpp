#include <iostream>
#include <vector>
using namespace std;

void ShiftUp(vector<int> &heap, int i) {
  int p = (i - 1) / 2;
  while (i > 0 && heap[i] > heap[p]) {
    swap(heap[i], heap[p]);
    i = p;
    p = (i - 1) / 2;
  }
}

void ShiftDown(vector<int> &heap, int i) {
  int l = i * 2 + 1;
  int n = heap.size();
  while (l < heap.size()) {
    int maxChild = (l + 1 < n && heap[l] > heap[l + 1]) ? l : l + 1;
    if (heap[i] >= heap[maxChild]) {
      break;
    }

    swap(heap[i], heap[maxChild]);
    i = maxChild;
    l = i * 2 + 1;
  }
}

void BuildHeap(vector<int> &heap) {
  for (int i = (heap.size() - 2) / 2; i >= 0; i--) {
    ShiftDown(heap, i);
  }
}

int main(int argc, char const *argv[]) {
  vector<int> nums{1, 5, 3, 4, 6};
  BuildHeap(nums);
  for (auto &&i : nums) {
    cout << i << " ";
  }
  cout << '\n';

    return 0;
}
