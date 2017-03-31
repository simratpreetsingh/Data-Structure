#include <iostream>
#include "Node.h"
using namespace std;

template <typename T>
class StackLL {
	Node<T>* head;
	int length;

	public:

		StackLL() {
			head = NULL;
			length = 0;
		}

		bool isEmpty() {
			return length == 0;
		}

		int size() {
			return length;
		}

		void push(T element) {
			Node<T>* newNode = new Node<T>(element);
			newNode->next = head;
			head = newNode;
			length++;
		}

		T pop() {
			if (head == NULL) {
				cout << "Empty Stack " << endl;
				return 0;
			}
			Node<T>* temp = head;
			T output = temp->data;
			head = head->next;
			temp->next = NULL;
			delete temp;
			length--;
			return output;
		}

		T top() {
			if (head == NULL) {
				cout << "Empty Stack " << endl;
				return 0;
			}
			return head->data;
		}
		
		~StackLL() {
			if (head != NULL)
				delete head;
		}



};
