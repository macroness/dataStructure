#include "iBTree.h"
#include <iostream>

using namespace std;
using namespace istd;
//namespace istd {
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

iBTree::Node* iBTree::searchNodeParent(Node* pNode, const int& val) {
	// root ó��
	if (pNode == m_pRoot && pNode->data == val) {
		return NULL;
	}
	// ū ��� ������
	if (pNode->data < val) {
		if (pNode->r == NULL || pNode->r->data == val) return pNode;

		return searchNodeParent(pNode->r, val);
	}

	// ���� ��� ����
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

const char iBTree::getChildNum(const Node* pNode) {
	if (pNode->l != NULL && pNode->r != NULL) return 2;
	if (pNode->l != NULL || pNode->r != NULL) return 1;
	return 0;
}

void iBTree::setChild(Node* pParent, Node* pNode, const int val) {
	// NULL�ΰ��� pNode�� root�� ���
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
	// �ڽ��� ���� ���
	if (childNum == 0) {
		setChild(pParent, NULL, val);
		delete pNode;

		return;
	}

	// �ڽ��� �ϳ��� ���
	if (childNum == 1) {
		Node* pChild = (pNode->l == NULL) ? pNode->r : pNode->l;
		setChild(pParent, pChild, val);
		delete pNode;

		return;
	}

	// �ڽ��� ���� ���
	Node* pChild = getLeftLarge(pNode);
	pNode->data = pChild->data;
	deleteNode(pChild);
}

void iBTree::preOrderPrint(Node *pNode) {
	cout << pNode->data << " ";
	preOrderPrint(pNode->l);
	preOrderPrint(pNode->r);
}

void iBTree::inOrderPrint(Node *pNode) {
	inOrderPrint(pNode->l);
	cout << pNode->data << " ";
	inOrderPrint(pNode->r);
}

void iBTree::postOrderPrint(Node *pNode) {
	postOrderPrint(pNode->l);
	postOrderPrint(pNode->r);
	cout << pNode->data << " ";
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

	if(pDelNode){
		deleteNode(pDelNode);
		return true;
	}

	return false;
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

//} // namespace istd
