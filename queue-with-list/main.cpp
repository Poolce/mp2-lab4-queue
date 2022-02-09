#include <iostream>
#include "TLQueue.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "russian");
    setlocale(LC_NUMERIC, "eng");
    
    TLQueue<int> qu;
    cout << "qu: " << qu << "\nEmpty = " << qu.empty() << "\n\n";

    for (int i = 1; i <= 3; i++) {
        cout << i << " pushed:\n";
        qu.push(i);
        cout << qu << "\nEmpty = " << qu.empty() << "\n\n";
    }
    cout << "\n";

    cout << "Assign qu to qu2 and clear qu:\n";
    TLQueue<int> qu2 = qu;
    qu.clear();
    cout << "qu: " << qu << "\nEmpty = " << qu.empty() << "\n\n";
    cout << "qu2: " << qu2 << "\nEmpty = " << qu2.empty() << "\n\n";


    cout << "We can't pop from qu again:\n";
    try {
        qu.pop();
    }
    catch (...) {
        cout << "Exception\n\n";
    }

    cout << "Then we continue with qu2.\n\n";

    for (int i = 1; i <= 3; i++) {
        cout << qu2.pop() << " popped:\n";
        cout << qu2 << "\nEmpty = " << qu2.empty() << "\n\n";
    }
    cout << "\n";


    for (int i = 4; i <= 6; i++) {
        cout << i << " pushed:\n";
        qu2.push(i);
        cout << qu2 << "\nEmpty = " << qu2.empty() << "\n\n";
    }

    cout << "Other tests:\n\n";
    TLQueue<int> qu3(qu2);

    cout << "qu2: " << qu2 << "\nEmpty = " << qu2.empty() << "\n\n";
    cout << "qu3(qu2): " << qu3 << "\nEmpty = " << qu3.empty() << "\n\n";

    cout << "(qu3 == qu2) = " << (qu3 == qu2) << "\n\n";

    cout << qu2.pop() << " popped from qu2:\n";
    cout << "qu2: " << qu2 << "\nEmpty = " << qu2.empty() << "\n\n";

    cout << "(qu3 == qu2) = " << (qu3 == qu2) << "\n";
    
    return 0;
}