#ifndef _IHUFFMAN_CODING_H_
#define _IHUFFMAN_CODING_H_

#include <map>

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

	const std::string bitEncoding(const std::map<char, std::string>& map, const std::string& str);
public:
	iHuffmanCoding();

	~iHuffmanCoding();

	// TODO : doEncoding() 은 솔직히 너무 막짜서 리팩토링이 필요함...함수를 좀 나눠야함.
	std::string doEncoding(const std::string str);

	std::string doDecoding(const std::string str);

private:
	Node* m_pRoot;

};




} // namespace istd

#endif