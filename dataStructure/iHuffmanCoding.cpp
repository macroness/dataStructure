#include <queue>
#include <map>
#include <iostream>

#include "iHuffmanCoding.h"

using namespace std;

namespace istd {

iHuffmanCoding::iHuffmanCoding() {}

iHuffmanCoding::~iHuffmanCoding() {}

iHuffmanCoding::Node* iHuffmanCoding::createNewNode(const int f, const char ch) {
	Node* newNode = new Node();
	newNode->freq = f;
	newNode->c = ch;

	return newNode;
}

string iHuffmanCoding::doEncoding(const string str) {

	map<char, int> freqMap;

	// 빈도수 체크
	for (string::const_iterator it = str.begin(); it != str.end(); ++it) {
		map<char, int>::iterator mapItr = freqMap.find(*it);
		if (mapItr != freqMap.end()) {
			mapItr->second++;
		}
		else {
			freqMap[*it] = 1;
		}
	}

	priority_queue<Node*, vector<Node*>, Node::compareNode> pQ;
	// 우선순위 큐에 전부 집어넣기
	for (map<char, int>::iterator it = freqMap.begin(); it != freqMap.end(); ++it) {
		pQ.push(createNewNode(it->second, it->first));
	}

	// 허프만트리 만들기
	while (true) {
		Node* node1 = pQ.top();
		pQ.pop();
		Node* node2 = pQ.top();
		pQ.pop();

		Node* parent = createNewNode(node1->freq + node2->freq);
		parent->l = node1;
		parent->r = node2;

		if (pQ.empty()) {
			m_root = parent;
			break;
		}

		pQ.push(parent);
	}





	return "";
}


} // namespace istd