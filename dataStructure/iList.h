//#include <stdio.h>
#ifndef _iList_H_
#define _iList_H_


namespace istd {

template <typename valueType> // 여러타입을 지원하기위해 템플릿으로
class Node { // list를 구성하는 각 Node.
    valueType data; // 데이터 값
    Node *prev; // 앞 노드
    Node *next; // 다음 노드
};

template <typename valueType>
class iList {

    iList(int size = 0) { // 생성시 크기를 줄 수 있도록
        // TODO: size에 맞춰서 List 초기화
    }
    ~iList() {
    };

public:
    iList operator=(iList list) {
        // TODO: = 오퍼레이터 정의
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

        // TODO: 사이에 있는 노드 지우기


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