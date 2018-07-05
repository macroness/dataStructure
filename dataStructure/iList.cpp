#include "iList.h"
#include <iostream>

namespace istd {

iList::iList(int size, int initValue) {
	// TODO: size에 맞춰서 initValue 값으로 List 초기화
}

iList::~iList() {
};

void iList::del(Node *pNode) {

	if (empty()) {
		return;
	}

	if (m_numOfSize == 1) {
		delete pNode;
		m_pFirst = NULL;
		m_numOfSize--;
		return;
	}

	pNode->prev->next = pNode->next;
	pNode->next->prev = pNode->prev;
	delete pNode;
	m_numOfSize--;
}

void iList::push_back(int val) {
	Node *pNew = new Node();
	pNew->data = val;

	if (empty()) {
		m_pFirst = pNew;
		m_pFirst->next = pNew;
		m_pFirst->prev = pNew;
		m_numOfSize++;
		return;
	}

	pNew->next = m_pFirst;
	pNew->prev = m_pFirst->prev;
	m_pFirst->prev->next = pNew;
	m_pFirst->prev = pNew;
	m_numOfSize++;
}

// TODO : push_front()
// TODO : pop_front()

int iList::pop_back() {
	int val = m_pFirst->prev->data;
	del(m_pFirst->prev);
	return val;
}


int iList::remove(int val) {
	Node* pNode = m_pFirst;
	int removeNum = 0;
	const int listSize = m_numOfSize;
	for (int i = 0; i < listSize; ++i) {
		Node *tempNode = pNode->next;
		if (pNode->data == val) {
			del(pNode);
			removeNum++;
		}
		pNode = tempNode;
	}

	return removeNum;
}

bool iList::empty() {
	return m_numOfSize == 0;
}

} // namespace istd


void print_list(istd::iList *pList) {
	while (!pList->empty()) {
		std::cout << pList->pop_back() << "\n";
	}
}

void init_list(istd::iList *pList, const int n) {
	for (int i = 0; i < n; ++i) {
		pList->push_back(i);
	}
	for (int i = 0; i < n; ++i) {
		pList->push_back(i);
	}
}

int main() {
	
	istd::iList l;

	init_list(&l, 5);

	l.remove(3);

	print_list(&l);

	init_list(&l, 10);

	print_list(&l);

	

	return 0;
}