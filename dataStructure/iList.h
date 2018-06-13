//#include <stdio.h>
#ifndef _iList_H_
#define _iList_H_


namespace istd {

template <typename valueType> // ����Ÿ���� �����ϱ����� ���ø�����
class Node { // list�� �����ϴ� �� Node.
    valueType data; // ������ ��
    Node *prev; // �� ���
    Node *next; // ���� ���
};

template <typename valueType>
class iList {

    iList(int size = 0) { // ������ ũ�⸦ �� �� �ֵ���
        // TODO: size�� ���缭 List �ʱ�ȭ
    }
    ~iList() {
    };

public:
    iList operator=(iList list) {
        // TODO: = ���۷����� ����
    }

    void push_back(valueType val) {
        Node<valueType> *pNew = new Node<valueType>();
        pNew->data = val;
        
        pNew->next = m_pFirst;
        pNew->prev = m_pFirst->prev;
        m_pFirst->prev->next = pNew;
        m_pFirst->prev = pNew;
    }

    // TODO : push_front()
    // TODO : pop_front()

    valueType pop_back() {
        valueType val = m_pFirst->prev->data;
        del(m_pFirst->prev);
        return val;
    }

    void del(Node<valueType> *pNode) {

        if (empty()) {
            return;
        }

        if (m_numOfSize == 1) {
            delete pNode;
            m_pFirst = NULL;
            m_numOfSize--;
            return;
        }

        // TODO: ���̿� �ִ� ��� �����


    }

    bool empty() {
        return m_numOfSize == 0;
    }
private:
    Node *m_pFirst;
    int m_numOfSize;

};

} // namespace istd

#endif