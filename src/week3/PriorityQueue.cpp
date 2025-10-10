#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int leftChild(int i) {
        return 2 * i + 1;
    }

    int rightChild(int i) {
        return 2 * i + 2;
    }

public:
    void swap(int i, int j) {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    void swim(int i) {
        while (i > 0 && heap[i] > heap[parent(i)]) {
            swap(i, parent(i));
            i = parent(i);
        }
    }

    void sink(int i) {
        int maxIndex = i;

        while (true) {
            int l = leftChild(i);
            int r = rightChild(i);

            if (l < size() && heap[l] > heap[maxIndex]) {
                maxIndex = l;
            }

            if (r < size() && heap[r] > heap[maxIndex]) {
                maxIndex = r;
            }

            if (i == maxIndex) {
                break;
            }

            swap(i, maxIndex);
            i = maxIndex;
        }
    }

    void insert(int key) {
        heap.push_back(key);
        swim(heap.size() - 1);
    }

    int delMax() {
        if (isEmpty()) {
            return -1; 
        }
        int maxElement = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        
        if (!isEmpty()) {
            sink(0);
        }
        return maxElement;
    }

    bool isEmpty() const {
        return heap.empty();
    }

    int max() const {
        if (isEmpty()) {
            return -1;
        }
        return heap[0];
    }

    int size() const {
        return heap.size();
    }

    void printHeap() const {
        for (int i = 0; i < size(); ++i) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};