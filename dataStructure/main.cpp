#include <iostream>
#include "iList.h"
#include "iBTree.h"

void print_list(istd::iList *pList) {
	while (!pList->empty()) {
		std::cout << pList->pop_front() << "\n";
	}
}

int main() {


	return 0;
}