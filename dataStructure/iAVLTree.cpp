#include <iostream>
#include <algorithm>

#include "iAVLTree.h"

namespace istd {

int iAVLTree::height(const Node* root) {

	if (root == NULL) {
		return 0;
	}

	const int left = height(root->l);
	const int right = height(root->r);
	const int maxHeight = std::max(left, right);
	
	return maxHeight + 1;
}


















} // namespace istd