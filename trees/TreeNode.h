#include <vector>
using namespace std;

template <typename T>
class TreeNode {
	vector<TreeNode<T>*>* children;
	public:
		T data;
		
		TreeNode(T data) {
			this->data = data;
			children = new vector<TreeNode<T>*>();
		}

		int numChildren() {
			return children->size();
		}

		void addChild(TreeNode<T>* child) {
			children->push_back(child);
		}

		TreeNode<T>* getChild(int index) {
			return children->at(index);
		}

		void setChild(int index, TreeNode<T>* child) {
			(*children)[index] = child;
		}


		~TreeNode() {
			for (int i = 0; i < children->size(); i++) {
				delete children->at(i);
			}
			delete children;
		}
};
