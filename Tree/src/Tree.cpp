#include "Node.h"
#include "Tree.h"

namespace NodeTask {

	Tree::Tree() : root(nullptr), size_(0){}

	Tree::~Tree() {
		std::queue<Node*> q;
		q.push(root);

		while (!q.empty()) {
			Node* node = q.front();
			q.pop();

			if (node->left_) {
				q.push(node->left_);
			}
			if (node->right_) {
				q.push(node->right_);
			}

			delete node;
		}
	}

	void Tree::add_node(int value) {
		Node* newnode = new Node(value);
		size_++;

		if (!root) {
			root = newnode;
		}
		else {
			Node* current = root;
			Node* parent;

			while (true) {
				parent = current;

				if (value < current->value_) {
					current = current->left_;

					if (!current) {
						parent->left_ = newnode;
						return;
					}
				}
				else {
					current = current->right_;

					if (!current) {
						parent->right_ = newnode;
						return;
					}
				}
			}
		}
	}

	

	const int Tree::get_size() {
		return size_;
	}
	void print_tree(Node *tree_root) {
		if (tree_root) {
			print_tree(tree_root->left_);
			std::cout << tree_root->value_ << " ";
			print_tree(tree_root->right_);
		}
	}
}