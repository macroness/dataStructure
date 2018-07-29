#ifndef _IPQUEUE_H_
#define _IPQUEUE_H_

#include <vector>

namespace istd {

class iPQueue {
private:
	/*
	 * 작은 child index 반환
	 */
	int getMinChildIndex(const int child1, const int child2);

public:
	iPQueue();

	~iPQueue();

	/*
	 * 힙에 삽입.
	 */
	void push(const int val);

	/*
	 * 가장 작은 값 반환
	 */
	int top();

	/*
	 * 가장 작은 값 삭제
	 */
	void pop();

	/*
	 * 비어있는지 확인
	 */
	bool empty();

	/*
	 * heap size 반환
	 */
	int size();

private:
	std::vector<int> m_heap;
};

} // namespace istd
#endif