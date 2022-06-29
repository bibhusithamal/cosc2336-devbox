/** @file LQueue.hpp
 * @brief Concrete link listed based implementation of Queue ADT.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Queues
 * @date   June 1, 2021
 *
 * Implement the Queue abstraction using a linked list of dynamically
 * allocated node items.  The linked list based implementation creates
 * new nodes dynamically when items are pushed onto the queue, and
 * deletes these nodes when the value is dequeued back off the front.
 * The Node structure defined in the Node.hpp header file is used by
 * this queue and is private to this queue member functions.  We use
 * the back of the linked list to enqueue items onto the queue, and
 * the front of the list to dequeue items from.  This is the
 * natural interpretation of the queue, and since we are only removing
 * from the front, both enqueue and dequeue are constant time O(1)
 * operations.
 */
#ifndef _LQUEUE_HPP_
#define _LQUEUE_HPP_
#include "Node.hpp"
#include "Queue.hpp"
#include <string>
using namespace std;

/** @class LQueue
 * @brief The LQueue concrete linked list implemention of the
 *   Queue interface.
 *
 * Concrete implementation of Queue abstraction using a dynamic
 * link listed of nodes.  We enqueue items onto the back of the
 * linked list, and dequeue them from the front of the linked list.
 */
template<class T>
class LQueue : public Queue<T>
{
public:
  // constructors and destructors
  LQueue();                            // default constructor
  LQueue(int size, T values[]);        // array based constructor
  LQueue(const LQueue<T>& otherQueue); // copy constructor
  ~LQueue();                           // destructor

  // accessors and information methods
  T front() const;
  string str() const;
  bool operator==(const Queue<T>& rhs) const;
  T& operator[](int index) const;

  // adding, accessing and removing values from the queue
  void clear();
  void enqueue(const T& value);
  void dequeue();

protected: // private to all except this class and its children
  /// @brief pointer to the front node of the linked list of
  ///   nodes that we manage for the LQueue.
  Node<T>* frontNode;

  /// @brief pointer to the back node of the linked list of
  ///   nodes that we manage for the LQueue.
  Node<T>* backNode;
};

#endif // define _LQUEUE_HPP_
