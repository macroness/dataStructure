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

	// 큰 경우 오른쪽
	if (pNode->data < val) {
		if (pNode->r == NULL) {
			pNode->r = createNewNode(val);
			return true;
		}

		return insertNode(pNode->r, val);
	}

	// 작은 경우 왼쪽
	if (pNode->data > val) {
		if (pNode->l == NULL) {
			pNode->l = createNewNode(val);
			return true;
		}
		
		return insertNode(pNode->l, val);
	}

	// 같은 값이 있는 경우 실패
	return false;
}

iBTree::Node* iBTree::searchNodeParent(Node* pNode, const int& val) {
	// root 처리
	if (pNode == m_pRoot && pNode->data == val) {
		return NULL;
	}
	// 큰 경우 오른쪽
	if (pNode->data < val) {
		if (pNode->r == NULL || pNode->r->data == val) return pNode;

		return searchNodeParent(pNode->r, val);
	}

	// 작은 경우 왼쪽
	if (pNode->l == NULL || pNode->l->data == val) return pNode;

	return searchNodeParent(pNode->l, val);
}

bool iBTree::exist(const int& val) {
	const Node *pNode = searchNodeParent(m_pRoot, val);

	return pNode == NULL || pNode->l->data == val || pNode->r->data == val;
}

bool iBTree::insert(const int& val) {
	// empty tree
	if (m_pRoot == NULL) {
		m_pRoot = createNewNode(val);
		return true;
	}

	Node *pNode = searchNodeParent(m_pRoot, val);

	if (pNode == NULL) {
		return false;
	}

	if (pNode->data > val) {
		if (pNode->r == NULL) {
			pNode->r = createNewNode(val);
			return true;
		}
	}
	else {
		if (pNode->l == NULL) {
			pNode->l = createNewNode(val);
			return true;
		}
	}

	return false;
}

bool iBTree::del(const int& val) {
	Node *pDelNode = searchNodeParent(m_pRoot, val);

	

}

//} // namespace istd