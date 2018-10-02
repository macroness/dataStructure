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

	// �������ڵ�� ���ڿ� ġȯ
	const std::string bitEncoding(const std::map<char, std::string>& map, const std::string& str);

	void deleteNode(Node* pNode);
	
	void createHuffmanTree(priority_queue<Node*, vector<Node*>, Node::compareNode> &pQ);
public:
	iHuffmanCoding();

	~iHuffmanCoding();

	// TODO : doEncoding() �� ������ �ʹ� ��¥�� �����丵�� �ʿ���...�Լ��� �� ��������.
	// �־��� ���ڿ��� ������ �˰������� ����.
	std::string doEncoding(const std::string str);

	// ������ �ڵ带 �ٽ� ���� ���·� ������ ǰ.
	std::string doDecoding(const std::string str);

	// ��ü �ʱ�ȭ
	void clear();
private:
	Node* m_pRoot;

};




} // namespace istd

#endif