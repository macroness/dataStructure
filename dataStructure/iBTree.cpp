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

iBTree::Node* iBTree::getLeftLarge(Node* pNode) {
	Node* pRet = pNode->l;

	while (pRet->r == NULL) {
		pRet = pRet->r;
	}

	return pRet;
}

const int8_t iBTree::getChildNum(const Node* pNode) {
	if (pNode->l != NULL && pNode->r != NULL) return 2;
	if (pNode->l != NULL || pNode->r != NULL) return 1;
	return 0;
}

void iBTree::setChild(Node* pParent, Node* pNode, const int val) {
	// NULL인경우는 pNode가 root인 경우
	if (pParent == NULL) {
		m_pRoot = pNode;
		return;
	}

	if (pParent->r->data == val) {
		pParent->r = pNode;
	}

	pParent->l = pNode;
}

void iBTree::deleteNode(Node* pNode) {
	Node* pParent = searchNodeParent(m_pRoot, pNode->data);
	const int val = pNode->data;

	const int8_t childNum = getChildNum(pNode);
	// 자식이 없는 경우
	if (childNum == 0) {
		setChild(pParent, NULL, val);
		delete pNode;

		return;
	}

	// 자식이 하나인 경우
	if (childNum == 1) {
		Node* pChild = (pNode->l == NULL) ? pNode->r : pNode->l;
		setChild(pParent, pChild, val);
		delete pNode;

		return;
	}

	// 자식이 둘인 경우
	Node* pChild = getLeftLarge(pNode);

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