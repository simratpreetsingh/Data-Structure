#include <iostream>
using namespace std;

template <typename T>
class Stack {
	T* data;
	int nextIndex;
	int capacity;
	public:
		Stack() {
			capacity = 10;
			data = new T[capacity];
			nextIndex = 0;
		}

		int size() {
			return nextIndex;
		}

		bool isEmpty() {
			if (nextIndex == 0) {
				return true;
			} else {
				return false;
			}
		}

		T top() {
			if (nextIndex == 0) {
				return 0;
			}
			return data[nextIndex - 1];
		}

		T pop() {
			if (nextIndex == 0) {
				return 0;
			}
			nextIndex--;
			return data[nextIndex];
		}

		void push(T element) {
			if (nextIndex == capacity) {
				T* temp = data;
				capacity = capacity * 2;
				data = new T[capacity];
				for (int i = 0; i < nextIndex; i++) {
					data[i] = temp[i];
				}
				delete [] temp;
			}
			data[nextIndex] = element;
			nextIndex++;
		}

		~Stack() {
			delete [] data;
		}

};
