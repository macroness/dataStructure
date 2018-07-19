#include "iBTree.h"
#include <iostream>

using namespace std;
using namespace istd;
//namespace istd {
iBTree::iBTree() : m_pRoot(NULL) {}

iBTree::iBTree(const int& val) {
	insert(val);
}

iBTree::Node* iBTree::createNewNode(const int& val) {
	Node *pNew = new Node();
	pNew->data = val;
	return pNew;
}

bool iBTree::insertNode(Node *pNode, const int& val) {
	// 같은 값이 있는 경우 실패
	if (pNode->data == val) return false;

	// 큰 경우 오른쪽
	if (pNode->data < val) {
		if (pNode->r == NULL) {
			pNode->r = createNewNode(val);
			return true;
		}
		else {
			return insertNode(pNode->r, val);
		}
	}

	// 작은 경우 왼쪽
	if (pNode->data > val) {
		if (pNode->l == NULL) {
			pNode->l = createNewNode(val);
			return true;
		}
		else {
			return insertNode(pNode->l, val);
		}
	}

}

bool iBTree::insert(const int& val) {

	if (m_pRoot == NULL) {
		m_pRoot = createNewNode(val);
		return true;
	}

	return insertNode(m_pRoot, val);
}

//} // namespace istd