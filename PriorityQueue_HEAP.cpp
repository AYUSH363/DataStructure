#include <iostream>
#include <vector>

using namespace std;

class MaxHeapPriorityQueue {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

public:
    void add(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int getMax() {
        return heap.empty() ? -1 : heap[0];
    }
};

int main() {
    MaxHeapPriorityQueue pq;

    // Adding elements to the priority queue
    pq.add(30);
    pq.add(10);
    pq.add(20);

    // Displaying the maximum element
    cout << "Maximum element in the priority queue: " << pq.getMax() << endl;

    return 0;
}

