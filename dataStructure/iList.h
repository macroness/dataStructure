//#include <stdio.h>
#ifndef _iList_H_
#define _iList_H_


namespace istd {

class iList {
private:
	class Node { // list를 구성하는 각 Node.
	public:
		int data; // 데이터 값
		Node *prev; // 앞 노드
		Node *next; // 다음 노드
	};

	/*
	 * 노드 삭제
	 */
	void del(Node *pNode);
public:

	/*
	 * @param size      : 초기화 크기
	 * @param initValue : 초기화 값
	 */
	iList(int size = 0, int initValue = 0);


	~iList();

	/*
	 * 맨 뒤 삽입
	 */
	void push_back(int val);

	// TODO : push_front()
	// TODO : pop_front()

	/*
	 * 맨 뒤 가져오기
	 */
	int pop_back();

	/*
	 * 해당 val 값 모두 삭제
	 */
	int remove(int val);

	/*
	 * 비어있는지 확인
	 */
	bool empty();
private:
	Node * m_pFirst;
	int m_numOfSize;

};

} // namespace istd

#endif