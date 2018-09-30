#include <queue>
#include <iostream>

#include "iHuffmanCoding.h"

using namespace std;

namespace istd {

iHuffmanCoding::iHuffmanCoding() {}

iHuffmanCoding::~iHuffmanCoding() {
	// TODO : node delete 해야됨
}

iHuffmanCoding::Node* iHuffmanCoding::createNewNode(const int f, const char ch) {
	Node* newNode = new Node();
	newNode->freq = f;
	newNode->c = ch;

	return newNode;
}

void iHuffmanCoding::bitcodeMapping(map<char, string>& map, iHuffmanCoding::Node* pNode, string bitcode) {
	if (pNode->c != NULL) {
		map[pNode->c] = bitcode;
		return;
	}
	bitcodeMapping(map, pNode->l, bitcode + "0");
	bitcodeMapping(map, pNode->r, bitcode + "1");
}

const string iHuffmanCoding::bitEncoding(const map<char, std::string>& map, const string& str) {
	string ret;
	for (string::const_iterator it = str.begin(); it != str.end(); ++it) {
		ret += map.find(*it)->second;
	}

	return ret;
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
			m_pRoot = parent;
			break;
		}

		pQ.push(parent);
	}

	// 각 글자별로 비트코드 매핑
	map<char, string> bitcodeMap;
	bitcodeMapping(bitcodeMap, m_pRoot, "");

	return bitEncoding(bitcodeMap, str);
}

string iHuffmanCoding::doDecoding(const string str) {
	string ret;
	Node* curNode = m_pRoot;
	for (string::const_iterator it = str.begin(); it != str.end(); ++it) {
		if (*it == '0') {
			curNode = curNode->l;
		}
		else {
			curNode = curNode->r;
		}

		if (curNode->c != NULL) {
			ret += curNode->c;
			curNode = m_pRoot;
		}
	}

	return ret;
}


} // namespace istd