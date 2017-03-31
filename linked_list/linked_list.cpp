#include <iostream>
#include "Node.h"
using namespace std;

Node* takeLLInputBetter() {
	cout << "Enter first element" << endl;
	int nextElement;
	cin >> nextElement;
	Node * head = NULL;
	Node * tail = NULL;
	while (nextElement != -1) {
		Node* nextNode = new Node(nextElement);
		if (head == NULL) {
			head = nextNode;
			tail = nextNode;
		} else {
			tail->next = nextNode;
			tail = nextNode;
		}
		cout << "Enter next element" << endl;
		cin >> nextElement;
	}
	return head;
}

Node* takeLLInput() {
	cout << "Enter first element" << endl;
	int nextElement;
	cin >> nextElement;
	Node * head = NULL;
	while (nextElement != -1) {
		Node* nextNode = new Node(nextElement);
		if (head == NULL) {
			head = nextNode;
		} else {
			Node* temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = nextNode;
		}
		cout << "Enter next element" << endl;
		cin >> nextElement;
	}
	return head;
}

void print(Node* head) {
	Node* temp = head;
	while (head != NULL) {
		cout << head->data << "-->";
		head = head->next;
	}
	cout << endl;

	/*
		 head = temp;
		 while (head != NULL) {
		 cout << head->data << "-->";
		 head = head->next;
		 }
		 cout << endl;
	 */
}

Node* findMid(Node* head) {
	if (head == NULL) {
		return NULL;
	}
	Node* slow = head;
	Node* fast = head->next;
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

Node* reverseI(Node* head) {
	Node* current = head;
	Node* prev = NULL;
	while (current != NULL) {
		Node* currentNext = current->next;
		current->next = prev;
		prev = current;
		current = currentNext;
	}
	return prev;
}

Node* reverse3(Node* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}
	Node* smallHead = reverse3(head->next);
	head->next->next = head;
	head->next = NULL;
	return smallHead;
}

DoubleNode* reverse2(Node* head) {
	if (head == NULL || head->next == NULL) {
		DoubleNode* output = new DoubleNode(head, head);
		return output;
	}

	DoubleNode* smallerOutput = reverse2(head->next);
	smallerOutput->second->next = head;
	head->next = NULL;
	smallerOutput->second = head;
	return smallerOutput;
}

Node* reverse1(Node* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}
	
	Node* smallHead = reverse1(head->next);
	Node* smallTail = smallHead;
	while (smallTail->next != NULL) {
		smallTail = smallTail->next;
	}
	smallTail->next = head;
	head->next = NULL;
	return smallHead;
}

int findElement(Node* head, int element) {
	int position = 0;
	while (head != NULL && head->data != element) {
		position++;
		head = head->next;
	}
	if (head == NULL) {
		return -1;
	} else {
		return position;
	}
}

Node* insertR(Node* head, int position, int element) {
	if (position == 0) {
		Node* node = new Node(element);
		node->next = head;
		return node;
	}
	head->next = insertR(head->next, position - 1, element);
	return head;
}

int lengthR(Node* head) {
	if (head == NULL) {
		return 0;
	}
	return 1 + lengthR(head->next);
}

int length(Node* head) {
	int count = 0;
	while (head != NULL) {
		count++;
		head = head->next;
	}
	return count;
}

Node* insert (Node* head, int position, int element) {
	Node* node = new Node(element);
	if (position == 0) {
		node->next = head;
		return node;
	}

	int currentPosition = 1;
	Node* prev = head;
	while (currentPosition < position) {
		currentPosition++;
		prev = prev->next;
	}

	node->next = prev->next;
	prev->next = node;
	return head;
}

Node* bubbleSort(Node* head) {
	int n = length(head);
	for (int i = 0; i < n; i++) {
		Node* current = head;
		Node* prev = NULL;
		while (current->next != NULL) {
			if (current->data > current->next->data) {
				Node* currentNext = current->next;
				current->next = current->next->next;
				currentNext->next = current;
				if (prev != NULL) {
					prev->next = currentNext;
					prev = currentNext;
				} else {
					prev = currentNext;
					head = prev;
				}
			} else {
				prev = current;
				current = current->next;
			}
		}
	}
	return head;
}


int main() {
	Node* head = takeLLInput();
	print(head);
	head = bubbleSort(head);
	print(head);

	delete head;

	/*
	while (head != NULL) {
		Node* temp = head->next;
		delete head;
		head = temp;
	}
*/
}
