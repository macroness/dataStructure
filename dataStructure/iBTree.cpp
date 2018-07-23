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

	// ū ��� ������
	if (pNode->data < val) {
		if (pNode->r == NULL) {
			pNode->r = createNewNode(val);
			return true;
		}

		return insertNode(pNode->r, val);
	}

	// ���� ��� ����
	if (pNode->data > val) {
		if (pNode->l == NULL) {
			pNode->l = createNewNode(val);
			return true;
		}
		
		return insertNode(pNode->l, val);
	}

	// ���� ���� �ִ� ��� ����
	return false;
}

iBTree::Node* iBTree::searchNode(Node* pNode, const int& val) {

	// ū ��� ������
	if (pNode->data < val) {
		if (pNode->r == NULL) return NULL;

		return searchNode(pNode->r, val);
	}

	// ���� ��� ����
	if (pNode->data > val) {
		if (pNode->l == NULL) return NULL;

		return searchNode(pNode->l, val);
	}

	// ���� ���� ��� ��� ��ȯ
	return pNode;
}

bool iBTree::insert(const int& val) {

	if (m_pRoot == NULL) {
		m_pRoot = createNewNode(val);
		return true;
	}

	return insertNode(m_pRoot, val);
}

//} // namespace istd