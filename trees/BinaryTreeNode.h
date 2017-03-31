
template <typename T>
using namespace std;


class BinaryTreeNode {
	public:
	T data;
	BinaryTreeNode<T>* left;
	BinaryTreeNode<T>* right;

	BinaryTreeNode(T data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}

	~BinaryTreeNode() {
		if (left) {
			delete left;
		}

		if (right) {
			delete right;
		}
	}
};
