#ifndef _IHUFFMAN_CODING_H_
#define _IHUFFMAN_CODING_H_

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
public:
	iHuffmanCoding();

	~iHuffmanCoding();

	std::string doEncoding(const std::string str);

	std::string doDecoding(const std::string str);

private:
	Node* m_root;

};




} // namespace istd

#endif