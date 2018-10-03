#ifndef HEAP_H
#define HEAP_H

#include <vector>
using namespace std;

/*Vectors are same as dynamic arrays with the ability to resize itself automatically
when an element is inserted or deleted, with their storage being handled
automatically by the container. Vector elements are placed in contiguous storage
so that they can be accessed and traversed using iterators. In vectors,
data is inserted at the end. Inserting at the end takes differential time,
as sometimes there may be a need of extending the array.Removing the last
element takes only constant time, because no resizing happens. Inserting and
erasing at the beginning or in the middle is linear in time.*/


class Heap {
private:   
    vector<int> v; //size of v is zero; v[10] is an ERROR!
    int sze;

    int parent(int i) { return i / 2;}
    int left(int i)   { return i * 2;}
    int right(int i)  { return i * 2 + 1;}

    void heapify(int i) {
        int smallest = i;  //initialise root as smallest
       
        // If left child is smaller than root
        if (left(i) <= sze && v[left(i)] < v[smallest]) {
            smallest = left(i);
        }
        
        //  If right child is smaller than root
        if (right(i) <= sze && v[right(i)] < v[smallest]) {
            smallest = right(i);
        }
        
        //if root is not smallest
        if (smallest != i) {
            swap(v[smallest], v[i]);
            // Recursively heapify the affected sub-tree
            heapify(smallest);
        }
    }

public:
    Heap() {
        sze = 0;
        v.push_back(-1);    //arbitary element:sentinel
    }

    void push(int ele) {
        //insert an element in the heap
        v.push_back(ele);
        ++sze;

        int curIdx = sze;

        while (curIdx > 1 && v[curIdx] < v[parent(curIdx)]) {
            // Move current root to end
            swap(v[curIdx], v[parent(curIdx)]);
            curIdx = parent(curIdx);
        }
    }

    void pop() {
        if (sze <= 0) return;

        swap(v[1], v[sze]);

        v.pop_back();
        --sze;
        heapify(1);
    }

    int top() {
        if (sze < 1) return 1000000000;
        return v[1];
    }

    int size() {
        return sze;
    }
};

#endif
