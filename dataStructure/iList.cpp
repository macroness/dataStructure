#include "iList.h"
#include <iostream>

using namespace std;

namespace istd {

iList::iList(int size, int initValue) {
	for (int i = 0; i < size; ++i) {
		push_back(i);
		push_back(i);
	}
}

iList::~iList() {
	while(m_pFirst) {
		del(m_pFirst);
	}
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
	if (pNode == m_pFirst) {
		m_pFirst = m_pFirst->next;
	}
	delete pNode;
	m_numOfSize--;
}

void iList::push_front(int val) {
	// 맨 뒤 삽입 후 m_pFirst를 한 칸 앞으로 당긴다.(원형 더블 링크드 리스트이기 때문)
	push_back(val);
	m_pFirst = m_pFirst->prev;
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

int& iList::front() {
	return m_pFirst->data;
}

int& iList::back() {
	return m_pFirst->prev->data;
}

int iList::pop_front() {
	int val = m_pFirst->data;
	del(m_pFirst);
	return val;
}

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
		std::cout << pList->pop_front() << "\n";
	}
}

int main() {
	
	istd::iList l(3,0);

	l.remove(1);
	if (l.empty()) {
		cout << "empty\n";
	}
	print_list(&l);

	return 0;
}