#ifndef _iBTree_H_
#define _iBTree_H_

namespace istd {

// Binary Tree 
class iBTree {
private:
	class Node {
	public:
		int data; // data value
		Node *l // left leaf
		Node *r // right leaf
	};

	/*
	 * val 값을 가진 Node를 반환한다 (없는경우 NULL)
	 */
	Node* search_node(const int val);
public:
	iBTree();

	~iBTree();

	/*
	 * val이 존재하는지 검색
	 */
	bool exist(const int val);

	/*
	 * val 삽입 (같은 값이 있을경우 false 반환)
	 */
	bool insert(const int val);

	/*
	 * val 삭제 (값이 없을 경우 false 반환)
	 */
	bool del(const int val);

private:
	Node *m_pRoot; // root node

};

