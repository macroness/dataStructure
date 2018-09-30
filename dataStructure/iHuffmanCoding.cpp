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

	// �󵵼� üũ
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
	// �켱���� ť�� ���� ����ֱ�
	for (map<char, int>::iterator it = freqMap.begin(); it != freqMap.end(); ++it) {
		pQ.push(createNewNode(it->second, it->first));
	}

	// ������Ʈ�� �����
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