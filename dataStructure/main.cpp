#include <iostream>
#include "iList.h"
#include "iBTree.h"

using namespace istd;

void print_list(iList *pList) {
	while (!pList->empty()) {
		std::cout << pList->pop_front() << "\n";
	}
}

int main() {


	return 0;
}