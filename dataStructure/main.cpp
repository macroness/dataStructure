#include <iostream>
//#include "iList.h"
#include "iBTree.h"
#include "iPQueue.h"
#include "iAVLTree.h"
#include "iHuffmanCoding.h"

using namespace istd;
using namespace std;
/*
void print_list(iList *pList) {
	while (!pList->empty()) {
		std::cout << pList->pop_front() << "\n";
	}
}
*/

void initBtree(iBTree* pTree){
	pTree->insert(5);
	pTree->insert(3);
	pTree->insert(4);
	pTree->insert(1);
	pTree->insert(6);
	pTree->insert(8);
	pTree->insert(2);
	pTree->insert(7);
	pTree->insert(9);
}

void testBTree() {
	iBTree tree;
	initBtree(&tree);
	tree.inOrder();
	cout << "\n";
	cout << tree.exist(3) << "\n";
	cout << tree.insert(3) << "\n";

	cout << tree.del(5) << "\n";
	tree.inOrder();
	cout << "\n";
	tree.preOrder();
	cout << "\n";
	tree.postOrder();
}

void testPQueue() {
	iPQueue q;

	for (int i = 9; i > 0; --i) {
		q.push(i);
	}

	while (!q.empty()) {
		cout << q.top() << " ";
		q.pop();
	}
	cout << "\n";

	// 아무일도 일어나지 않음
	q.pop();

	// 중복 숫자 확인
	for (int i = 9; i > 0; --i) {
		q.push(i);
		q.push(i);
	}

	while (!q.empty()) {
		cout << q.top() << " ";
		q.pop();
	}
	cout << "\n";
}

void testAVLTree() {
	// TODO
}

void testHuffman() {
	iHuffmanCoding h;
	const string inputStr = "asklfjlgajnbrel;jqt;;lasfjmasdf;aslvnzxnvm,asdjf;q1231414";
	const string encodingStr = h.doEncoding(inputStr);
	cout << encodingStr.c_str() << "\n";

	const string decodingStr = h.doDecoding(encodingStr).c_str();
	cout << "decoding string : " << decodingStr.c_str() << "\n";
	cout << "original string : " << inputStr.c_str() << "\n";

	cout << inputStr.compare(decodingStr) << "\n";
}

int main() {
	testHuffman();
	return 0;
}
