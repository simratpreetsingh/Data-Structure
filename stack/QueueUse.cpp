#include <iostream>
#include "Queue.h"
using namespace std;

void reverse(Queue<int> &q) {
	if (q.size() <= 1) {
		return;
	}
	int a = q.dequeue();
	reverse(q);
	q.enqueue(a);
}

int main() {
	Queue<int> a;
	a.enqueue(10);
	a.enqueue(20);
	a.enqueue(30);
	a.enqueue(40);
	a.enqueue(50);
	reverse(a);
	while (!a.isEmpty()) {
		cout << a.dequeue() << endl;
	}
}

