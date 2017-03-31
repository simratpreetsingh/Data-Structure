class Node {
	public:
		int data;
		Node* next;

		Node(int data) {
			this->data = data;
			next = NULL;
		}

		~Node {
			if (next != NULL) {
				delete next;
			}
		}
};
