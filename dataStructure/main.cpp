#include <iostream>
//#include "iList.h"
#include "iBTree.h"

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

int main() {
	

	return 0;
}
