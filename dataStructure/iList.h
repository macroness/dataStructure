//#include <stdio.h>
#ifndef _iList_H_
#define _iList_H_


namespace istd {

// ���� ���� ���� ����Ʈ
class iList {
private:
	class Node { // list�� �����ϴ� �� Node.
	public:
		int data; // ������ ��
		Node *prev; // �� ���
		Node *next; // ���� ���
	};

	/*
	 * ��� ����
	 */
	void del(Node *pNode);
public:

	/*
	 * @param size      : �ʱ�ȭ ũ��
	 * @param initValue : �ʱ�ȭ ��
	 */
	iList(int size = 0, int initValue = 0);

	~iList();

	/*
	 * �� �� ����
	 */
	void push_front(int val);

	/*
	 * �� �� ����
	 */
	void push_back(int val);

	/*
	 * �� �� data reference ��ȯ (�� list�� ��� ���ǵ��� ���� ������ �Ͼ)
	 */
	int& front();

	/*
	* �� �� data reference ��ȯ (�� list�� ��� ���ǵ��� ���� ������ �Ͼ)
	*/
	int& back();

	/*
	 * �� �� ��������
	 */
	int pop_front();

	/*
	 * �� �� ��������
	 */
	int pop_back();

	/*
	 * �ش� val �� ��� ����
	 */
	int remove(int val);

	/*
	 * ����ִ��� Ȯ��
	 */
	bool empty();
private:
	Node * m_pFirst;
	int m_numOfSize;

};

} // namespace istd

#endif