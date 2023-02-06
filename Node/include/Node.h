#pragma once

#ifndef CPP_NODE_H
#define CPP_NODE_H


namespace NodeTask {

class Node {
public:
	int value_;
	Node *left_, *right_;
	Node(int& value);
};
}

#endif //CPP_NODE_H