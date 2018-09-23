#include <iostream>
#include <algorithm>

#include "iAVLTree.h"

namespace istd {

iAVLTree::iAVLTree() : iBTree(NULL) {}

iAVLTree::iAVLTree(const int& val) : iBTree(val) {}

iAVLTree::~iAVLTree() {
}

int iAVLTree::height(const Node* pNode) {

	if (pNode == NULL) {
		return 0;
	}

	return std::max(height(pNode->l), height(pNode->r)) + 1;
}

int iAVLTree::getBF(const Node& node){
	return height(node.l) - height(node.r);
}

iAVLTree::Node* iAVLTree::rr(Node *pNode) {
	Node* tempNode = pNode->r;
	pNode->r = tempNode->l;
	tempNode->l = pNode;

	return tempNode;
}


iAVLTree::Node* iAVLTree::ll(Node *pNode) {
	Node* tempNode = pNode->l;
	pNode->l = tempNode->r;
	tempNode->r = pNode;

	return tempNode;
}

iAVLTree::Node* iAVLTree::lr(Node *pNode) {
	Node* tempNode = pNode->l;
	pNode->l = rr(tempNode);

	return ll(pNode);
}


iAVLTree::Node* iAVLTree::rl(Node *pNode) {
	Node* tempNode = pNode->r;
	pNode->r = ll(tempNode);

	return rr(pNode);
}

void iAVLTree::balanceTree(Node *pNode) {
	const int bf = getBF(*pNode);

	if (bf > 1) {
		if (getBF(*pNode->l) > 0) {
			pNode = ll(pNode);
		}
		pNode = lr(pNode);
	}
	else if (bf < -1) {
		if (getBF(*pNode->l) > 0) {
			pNode = rl(pNode);
		}
		pNode = rr(pNode);
	}
	return;
}

bool iAVLTree::insert(const int& val){
	if (insertNode(m_pRoot, val)) {
		balanceTree(m_pRoot);
		return true;
	}

	return false;
}

} // namespace istd