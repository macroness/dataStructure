#include "iBTree.h"
#include <iostream>

using namespace std;

namespace istd {
iBTree::iBTree() : m_pRoot(NULL) {}

iBTree::iBTree(const int& val) {
	insert(val);
}

iBTree::~iBTree(){
	while (m_pRoot != NULL) {
		deleteNode(m_pRoot);
	}
}

iBTree::Node* iBTree::createNewNode(const int& val) {
	Node *pNew = new Node();
	pNew->data = val;
	return pNew;
}

bool iBTree::insertNode(Node *pNode, const int& val) {

	// empty tree
	if (pNode == NULL) {
		m_pRoot = createNewNode(val);
		m_pRoot->parent = NULL;
		return true;
	}

	// 큰 경우 오른쪽
	if (pNode->data < val) {
		if (pNode->r == NULL) {
			pNode->r = createNewNode(val);
			pNode->r->parent = pNode;
			return true;
		}

		return insertNode(pNode->r, val);
	}

	// 작은 경우 왼쪽
	if (pNode->data > val) {
		if (pNode->l == NULL) {
			pNode->l = createNewNode(val);
			pNode->l->parent = pNode;
			return true;
		}
		
		return insertNode(pNode->l, val);
	}

	// 같은 값이 있는 경우 실패
	return false;
}

iBTree::Node* iBTree::searchNode(Node* pNode, const int& val) {

	if (pNode == NULL || pNode->data == val) {
		return pNode;
	}

	if (pNode->data < val) {
		return searchNode(pNode->r, val);
	}

	return searchNode(pNode->l, val);
}

iBTree::Node* iBTree::getLeftLarge(Node* pNode) {
	Node* pRet = pNode->l;

	while (pRet->r != NULL) {
		pRet = pRet->r;
	}

	return pRet;
}

const char iBTree::getChildNum(const Node* pNode) {
	if (pNode->l != NULL && pNode->r != NULL) return 2;
	if (pNode->l != NULL || pNode->r != NULL) return 1;
	return 0;
}

void iBTree::setChild(Node* pParent, Node* pNode, const int val) {
	// NULL인경우는 pNode가 root인 경우
	if (pParent == NULL) {
		m_pRoot = pNode;
		if(m_pRoot)
			m_pRoot->parent = NULL;
		return;
	}

	if (pParent->r->data == val) {
		pParent->r = pNode;
		if(pNode)
			pNode->parent = pParent;
		return;
	}

	pParent->l = pNode;
	if (pNode)
		pNode->parent = pParent;
}

bool iBTree::deleteNode(Node* pNode) {
	if (pNode == NULL) return false;

	Node* pParent = pNode->parent;
	const int val = pNode->data;

	const int8_t childNum = getChildNum(pNode);
	// 자식이 없는 경우
	if (childNum == 0) {
		setChild(pParent, NULL, val);
		delete pNode;

		return true;
	}

	// 자식이 하나인 경우
	if (childNum == 1) {
		Node* pChild = (pNode->l == NULL) ? pNode->r : pNode->l;
		setChild(pParent, pChild, val);
		delete pNode;

		return true;
	}

	// 자식이 둘인 경우
	Node* pChild = getLeftLarge(pNode);
	pNode->data = pChild->data;
	deleteNode(pChild);

	return true;
}

void iBTree::preOrderPrint(Node *pNode) {
	if (pNode == NULL) return;
	cout << pNode->data << " ";
	preOrderPrint(pNode->l);
	preOrderPrint(pNode->r);
}

void iBTree::inOrderPrint(Node *pNode) {
	if (pNode == NULL) return;
	inOrderPrint(pNode->l);
	cout << pNode->data << " ";
	inOrderPrint(pNode->r);
}

void iBTree::postOrderPrint(Node *pNode) {
	if (pNode == NULL) return;
	postOrderPrint(pNode->l);
	postOrderPrint(pNode->r);
	cout << pNode->data << " ";
}

bool iBTree::exist(const int& val) {
	const Node *pNode = searchNode(m_pRoot, val);

	return pNode != NULL;
}

bool iBTree::insert(const int& val) {
	return insertNode(m_pRoot, val);
}

bool iBTree::del(const int& val) {
	return deleteNode(searchNode(m_pRoot, val));
}

void iBTree::preOrder() {
	preOrderPrint(m_pRoot);
}

void iBTree::inOrder() {
	inOrderPrint(m_pRoot);
}

void iBTree::postOrder() {
	postOrderPrint(m_pRoot);
}

} // namespace istd
