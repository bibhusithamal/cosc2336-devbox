/** @file Queue.hpp
 * @brief Abstract base class definition of Queue abstract data type.
 *   This header defines the abstraction/interface for concrete
 *   Queue implementations.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Queues
 * @date   June 1, 2021
 *
 * Defination of Queue abstraction.  Concrete implementations of
 * this Queue interface must inherit from this abstract base class
 * and implement all defined virtual functions.
 */
#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_
#include <iostream>
using namespace std;

/** @class Queue
 * @brief The Queue data type abstraction
 *
 * The defined ADT interface for a Queue data type.  This abstraction
 * provides the ability to perform the most common tasks we want to
 * perform with queues, such as enqueue and dequeue items from the
 * queue and retrieve the item now at the front of the queue.
 */
template<class T>
class Queue
{
public:
  // accessor and information methods
  int getSize() const;
  bool isEmpty() const;
  virtual T front() const = 0;
  virtual string str() const = 0;
  virtual bool operator==(const Queue<T>& rhs) const = 0;
  virtual T& operator[](int index) const = 0;

  // adding, accessing and removing values from the queue
  virtual void clear() = 0;
  // virtual void enqueue(const T& newItem) = 0;
  virtual void dequeue() = 0;

  // friend functions and friend operators
  template<typename U>
  friend ostream& operator<<(ostream& out, const Queue<U>& rhs);

protected: // private to this class and its children
  /// @brief the current size of the queue of values, this is
  ///   protected so derived classes can access it
  int size;
};

#endif // _QUEUE_HPP_