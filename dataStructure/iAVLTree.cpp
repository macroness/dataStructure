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
















} // namespace istd