/** @file APriorityQueue.hpp
 * @brief Concrete array based implementation of Priority Queue ADT.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Queues
 * @date   June 1, 2021
 *
 * Implement the Queue abstraction but maintain the queue as a
 * priority queue.  This is an array based implementation.  We
 * inherit from the AQueue class and override the
 * enqueue() method to insert new values into the queue
 * based on their priority.  For this class we assume that
 * operator>() is defined for the type T being managed, and that
 * it returns true when the lhs T value is higher priority than the
 * rhs T value.
 */
#ifndef _APRIORITYQUEUE_HPP_
#define _APRIORITYQUEUE_HPP_
#include "AQueue.hpp"
using namespace std;

/** @class APriorityQueue
 * @brief The APriorityQueue concrete array based implemention of the
 *   Queue interface that dequeues items in order of priority.
 *
 * Concrete implementation of Queue abstraction using an array based
 * implementation.  We inherit from the array based AQueue implementation.
 * we only override the enqueue() method so that we insert new values into
 * the queue in priority order.
 */
template<class T>
class APriorityQueue : public AQueue<T>
{
public:
  // constructors and destructors
  APriorityQueue();                             // default constructor
  APriorityQueue(int initSize, T initValues[]); // array based constructor

  // adding, accessing and removing values from the queue

private:
  int modulo(int index, int bufferSize);
};

#endif // define _APRIORITYQUEUE_HPP_
