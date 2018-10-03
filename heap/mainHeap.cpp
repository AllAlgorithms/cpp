
#include "heap.h"
#include <iostream>
using namespace std;
int main() {
    Heap h;

    h.push(2);
    h.push(4);
    h.push(3);
    cout << h.top() << endl;
    h.push(1);
    cout << h.top() << endl;
    h.pop();
    cout << h.top() << endl;
    h.pop();
    cout << h.top() << endl;
}
