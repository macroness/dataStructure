#ifndef _iBTree_H_
#define _iBTree_H_

namespace istd {

// Binary Tree 
class iBTree {
private:
	class Node {
	public:
		int data; // data value
		Node *l; // left leaf
		Node *r; // right leaf
	};

	/*
	 * 새 노드 생성해서 반환
	 */
	Node* createNewNode(const int& val);

	/*
	 * 새 노드 삽입 (같은 값이 있을 경우 false 반환)
	 */
	bool insertNode(Node* pNode, const int& val);
public:

	iBTree();

	iBTree(const int& val);

	~iBTree();

	/*
	 * val이 존재하는지 검색
	 */
	bool exist(const int& val);

	/*
	 * val 삽입 (같은 값이 있을 경우 false 반환)
	 */
	bool insert(const int& val);

	/*
	 * val 삭제 (값이 없을 경우 false 반환)
	 */
	bool del(const int& val);

private:
	Node *m_pRoot; // root node

};
} // namespace istd
#endif