#ifndef _IAVLTREE_H_
#define _IAVLTREE_H_

#include "iBTree.h"

namespace istd {

class iAVLTree : public iBTree {
private:

	/*
	 * �ش� ��带 ��Ʈ���ϴ� Ʈ���� ���̸� ��ȯ
	 */
	int height(const Node* node);

	/*
	 * balance factor(���� �μ� : ��������)�� ��ȯ
	 */
	int getBF(const Node& node);

	/*
	* RR rotation
	*/
	Node* rr(Node *node);

	/*
	 * LL rotation
	 */
	Node* ll(Node *node);

	/*
	 * LR rotation
	 */
	Node* lr(Node *node);

	/*
	 * RL rotation
	 */
	Node* rl(Node *node);

	/*
	* tree�� �뷱���� ������
	*/

	/*
	 * Ʈ���� �뷱���� ������
	 */
	void balanceTree(Node *node);


public:

	iAVLTree();
	iAVLTree(const int& val);

	~iAVLTree();

	/*
	 * val ���� (���� ���� ���� ��� false ��ȯ)
	 */
	bool insert(const int& val);


};















} // namespace istd

#endif