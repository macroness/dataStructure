#ifndef _IAVLTREE_H_
#define _IAVLTREE_H_

#include "iBTree.h"

namespace istd {

class iAVLTree : public iBTree {
private:

	/*
	 * 해당 노드를 루트로하는 트리의 높이를 반환
	 */
	int height(const Node* node);

	/*
	 * balance factor(균형 인수 : 높이차이)를 반환
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
	* tree의 밸런스를 맞춰줌
	*/

	/*
	 * 트리의 밸런스를 맞춰줌
	 */
	void balanceTree(Node *node);


public:

	iAVLTree();
	iAVLTree(const int& val);

	~iAVLTree();

	/*
	 * val 삽입 (같은 값이 있을 경우 false 반환)
	 */
	bool insert(const int& val);


};















} // namespace istd

#endif