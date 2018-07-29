#include "iPQueue.h"

namespace istd {

iPQueue::iPQueue() {
}

iPQueue::~iPQueue() {

}

static void _swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

int iPQueue::getMinChildIndex(const int child1, const int child2) {
	if (child2 >= size()) return child1;

	return m_heap[child2] < m_heap[child1] ? child2 : child1;
}

void iPQueue::push(const int val) {
	m_heap.push_back(val);

	int i = size() - 1;

	if (i == 0) return;

	int parent = (i - 1) / 2;
	while ((i != 0) && (m_heap[parent] >= m_heap[i])) {
		_swap(&m_heap[i], &m_heap[parent]);
		i = parent;
		parent = (i - 1) / 2;
	}
}

int iPQueue::top() {
	return m_heap[0];
}


void iPQueue::pop() {
	if (empty()) return;

	m_heap[0] = m_heap.back();
	m_heap.pop_back();

	int i = 0;

	if (1 >= size()) return;
	int minChild = getMinChildIndex(1, 2);

	while (m_heap[i] > m_heap[minChild]) {
		_swap(&m_heap[i], &m_heap[minChild]);
		i = minChild;
		const int child1 = (i * 2) + 1;
		const int child2 = child1 + 1;

		if (child1 >= size()) return;
		minChild = getMinChildIndex(child1, child2);
	}
}

bool iPQueue::empty() {
	return m_heap.empty();
}

int iPQueue::size() {
	return m_heap.size();
}


} // namespace istd

