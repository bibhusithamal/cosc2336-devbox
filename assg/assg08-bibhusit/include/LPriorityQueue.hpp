/** @file LPriorityQueue.hpp
 * @brief Concrete linked list based implementation of Priority Queue ADT.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Queues
 * @date   June 1, 2021
 *
 * Implement the Queue abstraction but maintain the queue as a
 * priority queue.  This is a linked list based implementation.  We
 * inherit from the LQueue class and override the
 * enqueue() method to insert new values into the queue
 * based on their priority.  For this class we assume that
 * operator<() is defined for the type T being managed, and that
 * it returns true when the lhs T value is higher priority than the
 * rhs T value.
 */
#ifndef _LPRIORITYQUEUE_HPP_
#define _LPRIORITYQUEUE_HPP_
#include "LQueue.hpp"
#include "Node.hpp"
using namespace std;

/** @class LPriorityQueue
 * @brief The LPriorityQueue concrete linked list based implemention of the
 *   Queue interface that dequeues items in order of priority.
 *
 * Concrete implementation of Queue abstraction using a linked list based
 * implementation.  We inherit from the linked list based LQueue implementation.
 * we only override the enqueue() method so that we insert new values into
 * the queue in priority order.
 */
template<class T>
class LPriorityQueue : public LQueue<T>
{
public:
  // adding, accessing and removing values from the queue
};

#endif // define _LPRIORITYQUEUE_HPP_