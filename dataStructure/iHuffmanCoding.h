#ifndef _IHUFFMAN_CODING_H_
#define _IHUFFMAN_CODING_H_

#include <map>
#include <queue>

namespace istd {

class iHuffmanCoding {

	struct Node {
		Node() : freq(0), c(NULL), l(NULL), r(NULL) {}

		struct compareNode {
			bool operator()(Node* t, Node* u) {
				return t->freq > u->freq;
			};
		};

		int freq;
		char c;
		Node *l;
		Node *r;
	};

	Node* createNewNode(const int f, const char ch = NULL);

	void bitcodeMapping(std::map<char, std::string>& map, Node* pNode, std::string bitcode);

	// 허프만코드로 문자열 치환
	const std::string bitEncoding(const std::map<char, std::string>& map, const std::string& str);

	void deleteNode(Node* pNode);
	
	void createHuffmanTree(priority_queue<Node*, vector<Node*>, Node::compareNode> &pQ);
public:
	iHuffmanCoding();

	~iHuffmanCoding();

	// TODO : doEncoding() 은 솔직히 너무 막짜서 리팩토링이 필요함...함수를 좀 나눠야함.
	// 주어진 문자열을 허프만 알고리즘으로 압축.
	std::string doEncoding(const std::string str);

	// 압축한 코드를 다시 원래 상태로 압축을 품.
	std::string doDecoding(const std::string str);

	// 객체 초기화
	void clear();
private:
	Node* m_pRoot;

};




} // namespace istd

#endif