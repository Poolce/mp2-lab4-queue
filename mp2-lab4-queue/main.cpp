#include <iostream>
#include "TQueue.h"
using namespace std;

int main() {
	TQueue<int> qu(3);
	cout << qu << "\n";

	for (int i = 1; i <= 3; i++) {
		qu.push(i);
		cout << qu << "\n";
	}

	qu.pop();
	cout << qu << "\n";

	qu.push(4);
	cout << qu << "\n";

	qu.pop();
	cout << qu << "\n";

	qu.push(5);
	cout << qu << "\n";

	for (int i = 1; i <= 3; i++) {
		qu.pop();
		cout << qu << "\n";
	}

	for (int i = 1; i <= 3; i++) {
		qu.push(i * 100);
		cout << qu << "\n";
	}

	cout << "\nTrying to add 400:\n";
	try {
		qu.push(400);
	}
	catch (...) {
		cout << "Exception\n";
	}

	cout << "\nLet's copy to \"other\" variable and continue:\n\n";
	TQueue<int> other(qu);
	cout << other << '\n';

	for (int i = 1; i <= 3; i++) {
		other.pop();
		cout << other << "\n";
	}

	cout << "\nTrying to pop again:\n";
	try {
		other.pop();
	}
	catch (...) {
		cout << "Exception\n";
	}

	cout << "\nTrying to create queue with max_size < 2:\n";
	try {
		TQueue<char> qu2(-2);
	}
	catch (...) {
		cout << "Exception\n";
	}

	return 0;
}