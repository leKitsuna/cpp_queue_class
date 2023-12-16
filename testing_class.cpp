#include "queue_class.h"

int main() {

    Queue <int> test1;

    test1.Add(1);
    test1.Add(2);
    test1.Add(5);
    test1.Add(8);

    cout << "Queue size: " << test1.Size() << endl;
    cout << "Front element: " << test1.Front() << endl;
    cout << "Back element: " << test1.Back() << endl;
    
    test1.Pop();
    cout << "Now front element: " << test1.Front() << endl;
    cout << "Now Queue size: " << test1.Size() << endl;

    test1.~Queue();
    cout << test1.Empty() << endl;
    return 0;
    
}