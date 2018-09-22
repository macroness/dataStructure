#include <iostream>
#include <algorithm>

#include "iAVLTree.h"

namespace istd {

int iAVLTree::height(const Node* node) {

	if (node == NULL) {
		return 0;
	}

	return std::max(height(node->l), height(node->r)) + 1;
}

int iAVLTree::getBF(const Node& node){
	return height(node.l) - height(node.r);
}

iAVLTree::Node* iAVLTree::rr(Node *node) {
	Node* tempNode = node->r;
	node->r = tempNode->l;
	tempNode->l = node;

	return tempNode;
}


iAVLTree::Node* iAVLTree::ll(Node *node) {
	Node* tempNode = node->l;
	node->l = tempNode->r;
	tempNode->r = node;

	return tempNode;
}

iAVLTree::Node* iAVLTree::lr(Node *node) {
	Node* tempNode = node->l;
	node->l = rr(tempNode);

	return ll(node);
}


iAVLTree::Node* iAVLTree::rl(Node *node) {
	Node* tempNode = node->r;
	node->r = ll(tempNode);

	return rr(node);
}

void iAVLTree::balanceTree(Node *node) {
	const int bf = getBF(*node);

	if (bf > 1) {
		if (getBF(*node->l) > 0) {
			node = ll(node);
		}
		node = lr(node);
	}
	else if (bf < -1) {
		if (getBF(*node->l) > 0) {
			node = rl(node);
		}
		node = rr(node);
	}
	return;
}











} // namespace istd