#include "LinkedQueue.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
    // create a queue of integers
    LinkedQueue<int> queueA;
    const int MAX_SIZE = 10;

    // attempt to display the front and back
    try {
        cout << queueA.front() << " ";
    } catch (string& e) {
        cout << e << " ";
    }
    try {
        cout << queueA.back() << " ";
    } catch (string& e) {
        cout << e << " ";
    }

    // insert just one element to queue A
    queueA.enqueue(-5);

    // display its length, front, and back
    cout << "A length: " << queueA.getLength() << " ";
    cout << "A front: "  << queueA.front()     << " ";
    cout << "A back: "   << queueA.back()      << " ";

    // now remove the single element from queue A
    queueA.dequeue();

    // display its length, front, and back
    cout << "A length: " << queueA.getLength() << " ";
    try {
        cout << queueA.front() << " ";
    } catch (string& e) {
        cout << e << " ";
    }
    try {
        cout << queueA.back() << " ";
    } catch (string& e) {
        cout << e << " ";
    }

    // populate queue A by enqueueing  values
    for (int i = 0; i < MAX_SIZE; i++) {
        queueA.enqueue(i);
    }

    // display its length, front, and back
    cout << "A length: " << queueA.getLength() << " ";
    cout << "A front: "  << queueA.front()     << " ";
    cout << "A back: "   << queueA.back()      << " ";

    // make a copy of queue A
    LinkedQueue<int> queueB = queueA;

    // loop to dequeue and print
    cout << "A contains: ";
    for (int i = 0; i < MAX_SIZE; i++) {
        cout << queueA.front() << ' ';
        queueA.dequeue();
    }
    cout << " ";

    // queue A should now be empty
    if (queueA.isEmpty()) {
        cout << "A is now empty ";
    }
    else {
        cout << "A is not empty [ERROR] ";
    }

    // display queue B length, front, and back
    cout << "B length: " << queueB.getLength() << " ";
    cout << "B front: "  << queueB.front()     << " ";
    cout << "B back: "   << queueB.back()      << " ";

    // make a copy of queue B
    LinkedQueue<int> queueC;
    queueC = queueB;

    // clear out queue B
    queueB.clear();

    // queue B should now be empty
    if (queueB.isEmpty()) {
        cout << "B is now empty ";
    }
    else {
        cout << "B is not empty [ERROR] ";
    }

    // display queue C length, front, and back
    cout << "C length: " << queueC.getLength() << " ";
    cout << "C front: "  << queueC.front()     << " ";
    cout << "C back: "   << queueC.back()      << " ";

    // terminate
    return 0;
}
