#pragma once

#ifndef CPP_TREE_H
#define CPP_TREE_H

#include "Node.h"
#include <queue>
#include <iostream>

namespace NodeTask {
	class Tree {
	private:
		size_t size_;
	public:
		Node* root;
		Tree();

		~Tree();

		void add_node(int value);

		const int get_size();
	};
	void print_tree(Node *tree_root);
}

#endif //CPP_TREE_H