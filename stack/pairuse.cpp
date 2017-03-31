#include <iostream>
#include "pair.h"
#include "Node.h"
using namespace std;

int main() {
	pair1<int> p;
	cout << p.a << endl;
	cout << p.b << endl;

	pair1<int*> p1;
	cout << p1.a << endl;
	cout << p1.b << endl;

	Node<int>* a = new Node<int>(19);

}

