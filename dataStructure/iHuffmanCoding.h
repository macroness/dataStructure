#ifndef _IHUFFMAN_CODING_H_
#define _IHUFFMAN_CODING_H_

namespace istd {

class iHuffmanCoding {

	class Node {
	public:
		Node() : preq(0), c(NULL), l(NULL), r(NULL) {}

	private:
		int preq;
		char c;
		Node *l;
		Node *r;
	};

public:
	iHuffmanCoding();

	~iHuffmanCoding();

	std::string doEncoding(const std::string str);

	std::string doDecoding(const std::string str);

private:


};




} // namespace istd

#endif