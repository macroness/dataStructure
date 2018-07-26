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

	/*
	 * val 이 tree에 없는 경우 : insert할 위치의 부모노드 반환
	 * val 이 tree에 있는 경우 : 해당 val값을 data로 가진 노드의 부모노드 반환 (root에 data가 val일 경우 NULL 반환)
	 * val 이 root에 있는 경우 : NULL 반환
	 */
	Node* searchNodeParent(Node* pNode, const int& val);

	/*
	 * 왼쪽 노드 중 가장 큰 Node를 반환
	 */
	Node* getLeftLarge(Node* pNode);

	/*
	 * 해당 노드 삭제
	 */
	void deleteNode(Node* pNode);
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