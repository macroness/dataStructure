#ifndef _IBTREE_H_
#define _IBTREE_H_

namespace istd {

// Binary Tree 
class iBTree {
protected:
	class Node {
	public:
		int data; // data value
		Node *l; // left leaf
		Node *r; // right leaf
		Node *parent; // parent node
	};

	/*
	 * 새 노드 삽입 (같은 값이 있을 경우 false 반환)
	 */
	bool insertNode(Node* pNode, const int& val);

	/*
	 * 트리를 예쁘게 프린트합니다.
	 */
	bool printTree(Node* pNode, const int& level);

private:
	/*
	 * 새 노드 생성해서 반환
	 */
	Node* createNewNode(const int& val);

	/*
	 * val 값을 가진 노드 반환
	 */
	Node* searchNode(Node* pNode, const int& val);

	/*
	 * 왼쪽 노드 중 가장 큰 Node를 반환
	 */
	Node* getLeftLarge(Node* pNode);

	/*
	 * 자식노드 수 반환
	 */
	const char getChildNum(const Node* pNode);

	/*
	 * pParent의 자식중 val이 같은 쪽 자식 pNode로 변경
	 */
	void setChild(Node* pParent, Node* pNode, const int val);

	/*
	 * 해당 노드 삭제 (삭제할 노드없으면 false)
	 */
	bool deleteNode(Node* pNode);

	/*
	 * 전위순회 출력
	 */
	void preOrderPrint(const Node *pNode);

	/*
	 * 중위순회 출력
	 */
	void inOrderPrint(const Node *pNode);

	/*
	 * 후위순회 출력
	 */
	void postOrderPrint(const Node *pNode);



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

	/*
	 * 전위순회 출력
	 */
	void preOrder();

	/*
	 * 중위순회 출력
	 */
	void inOrder();

	/*
	 * 후위순회 출력
	 */
	void postOrder();

	/*
	* 트리를 예쁘게 프린트합니다.
	*/
	bool print();

protected:
	Node *m_pRoot; // root node

};
} // namespace istd
#endif
