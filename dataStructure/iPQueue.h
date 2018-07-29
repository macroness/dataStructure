#ifndef _IPQUEUE_H_
#define _IPQUEUE_H_

#include <vector>

namespace istd {

class iPQueue {
private:
	/*
	 * ���� child index ��ȯ
	 */
	int getMinChildIndex(const int child1, const int child2);

public:
	iPQueue();

	~iPQueue();

	/*
	 * ���� ����.
	 */
	void push(const int val);

	/*
	 * ���� ���� �� ��ȯ
	 */
	int top();

	/*
	 * ���� ���� �� ����
	 */
	void pop();

	/*
	 * ����ִ��� Ȯ��
	 */
	bool empty();

	/*
	 * heap size ��ȯ
	 */
	int size();

private:
	std::vector<int> m_heap;
};

} // namespace istd
#endif