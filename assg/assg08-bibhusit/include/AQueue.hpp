/** @file AQueue.hpp
 * @brief Concrete array based implementation of Queue ADT.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Queues
 * @date   June 1, 2021
 *
 * Implement the Queue abstraction using a fixed sized array.  This
 * array based implementation will dynamically allocate a new block of
 * memory once the current allocation becomes full.  The new block is
 * double in size of the old.  Thus push at the end of the queue
 * can be O(1) in most cases, but will take O(n) copies as well as a
 * memory allocation if it needs to grow.  In order to make
 * queue operations efficient for both enqueue on the back and dequeue
 * on the front of the queue, we have to now treat the array ov
 * values as a circular buffer.
 */
#ifndef _AQUEUE_HPP_
#define _AQUEUE_HPP_
#include "Queue.hpp"
#include <string>
using namespace std;

/** @class AQueue
 * @brief The AQueue concrete array based implemention of the
 *   Queue interface.
 *
 * Concrete implementation of Queue abstraction using an array based
 * implementation.  We maintain an array (a block of memory) to hold
 * the values currently in the queue.  To make both enqueue and dequeue
 * operations efficient, we treat the array as a circular buffer of items,
 * so both putting items on the end of the queue and taking items from the
 * front can be constant time O(1) operations.
 */
template<class T>
class AQueue : public Queue<T>
{
public:
  // constructors and destructors
  AQueue();                            // default constructor
  AQueue(int size, T values[]);        // array based constructor
  AQueue(const AQueue<T>& otherQueue); // copy constructor
  ~AQueue();                           // destructor

  // accessors and information methods
  int getAllocationSize() const;
  string str() const;
  bool operator==(const Queue<T>& rhs) const;
  T& operator[](int index) const;

  // adding, accessing and removing values from the queue
  void clear();
  T front() const;
  //void dequeue();

protected:
  /// @brief private constant, initial allocation size for empty queues
  ///   to grow to
  const int INITIAL_ALLOCATION_SIZE = 10;

  /// @brief the current amount of allocated memory being
  ///   managed by/for this queue of values
  int allocationSize;

  /// @brief the current index of the front item of the queue in
  ///   our array of values
  int frontIndex;

  /// @brief the current index of the back item of the queue in
  ///   our array of values
  int backIndex;

  /// @brief For the array based implementation, the values is a fixed
  ///   array of type T values.  The values contained in the queue
  ///   will be manged from the array, and a new array allocated and
  ///   values copied if we fill up the current allocation.  The array
  ///   is treated as a circular buffer so that enqueueing and dequeuing
  //    will be efficient operations for the array based queue.
  T* values;

  // private member methods for managing the Queue internally
  void growQueueIfNeeded();
};

#endif // define _AQUEUE_HPP_
