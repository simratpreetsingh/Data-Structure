#include <iostream>
#include "StackUsingLL.h"
using namespace std;

int main() {
	StackLL<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	while (!s.isEmpty()) {
		cout << s.pop() << endl;
	}
	s.push(40);
	s.push(50);
	s.push(60);
	while (!s.isEmpty()) {
		cout << s.pop() << endl;
	}
}
