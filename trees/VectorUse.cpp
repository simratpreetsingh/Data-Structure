#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	//v = 10;
	cout << v.capacity() << endl;
	v.push_back(20);
	cout << v.capacity() << endl;
	v.push_back(20);
	cout << v.capacity() << endl;
	v.push_back(20);
	cout << v.capacity() << endl;
	v.push_back(20);
	cout << v.capacity() << endl;
	v.push_back(20);
	cout << v.capacity() << endl;
	v[0] = 10;
	cout << v[0] << endl;
	cout << v.at(0) << endl;
}

