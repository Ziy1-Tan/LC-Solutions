#include <iostream>
#include <vector>
using namespace std;

// 添加的时候
void ShiftUp(vector<int> &heap, int i) {
  int p = (i - 1) / 2;
  while (i > 0 && heap[i] > heap[p]) {
    swap(heap[i], heap[p]);
    i = p;
    p = (i - 1) / 2;
  }
}

// 删除或者建堆的时候
void ShiftDown(vector<int> &heap, int i, int end) {
  int child = i * 2 + 1;
  while (child <= end) {
    if (child + 1 <= end && heap[child] < heap[child + 1]) {
      child++;
    }
    // 最大堆，父节点已经比子节点大了
    if (heap[i] >= heap[child]) {
      break;
    }

    swap(heap[i], heap[child]);
    i = child;
    child = i * 2 + 1;
  }
}

void BuildHeap(vector<int> &heap) {
  int n = heap.size();
  for (int i = n / 2 - 1; i >= 0; i--) {
    ShiftDown(heap, i, n - 1);
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
