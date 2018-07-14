//#include <stdio.h>
#ifndef _iList_H_
#define _iList_H_


namespace istd {

// 원형 더블 연결 리스트
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
	void push_front(int val);

	/*
	 * 맨 뒤 삽입
	 */
	void push_back(int val);

	/*
	 * 맨 앞 data reference 반환 (빈 list일 경우 정의되지 않은 동작이 일어남)
	 */
	int& front();

	/*
	* 맨 뒤 data reference 반환 (빈 list일 경우 정의되지 않은 동작이 일어남)
	*/
	int& back();

	/*
	 * 맨 앞 가져오기
	 */
	int pop_front();

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