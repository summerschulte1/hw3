#include "heap.h"
#include <iostream>
#include <string>
#include <cassert>

// Custom comparator for a max-heap of integers
struct IntMaxComparator {
    bool operator()(const int& lhs, const int& rhs) const {
        return lhs > rhs; // Max-heap
    }
};

// Function to test the heap with integers
void testIntHeap() {
    // Test min-heap
    Heap<int> minHeap;
    minHeap.push(50);
    minHeap.push(20);
    minHeap.push(60);
    minHeap.push(10);
    minHeap.push(40);

    std::cout << "Testing min-heap...\n";
    assert(minHeap.top() == 10);
    minHeap.pop();
    assert(minHeap.top() == 20);
    minHeap.pop();
    std::cout << "Min-heap tests passed.\n";

    // Test max-heap
    Heap<int, IntMaxComparator> maxHeap(2, IntMaxComparator());
    maxHeap.push(50);
    maxHeap.push(20);
    maxHeap.push(60);
    maxHeap.push(10);
    maxHeap.push(40);

    std::cout << "Testing max-heap...\n";
    assert(maxHeap.top() == 60);
    maxHeap.pop();
    assert(maxHeap.top() == 50);
    maxHeap.pop();
    std::cout << "Max-heap tests passed.\n";
}

int main() {
    try {
        testIntHeap();
    } catch (const std::exception& e) {
        std::cerr << "Test failed with exception: " << e.what() << std::endl;
        return 1;
    }
    std::cout << "All heap tests successfully passed!" << std::endl;
    return 0;
}
