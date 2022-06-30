/** @file AQueue.cpp
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
 * memory allocation if it needs to grow. In order to make
 * queue operations efficient for both enqueue on the back and dequeue
 * on the front of the queue, we have to now treat the array ov
 * values as a circular buffer.
 */
#include "AQueue.hpp"
#include "Job.hpp"
#include "QueueException.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/**
 * @brief Default constructor
 *
 * Construct an empty queue.  The empty queue will have no allocated memory
 * nor any values.
 */
template<class T>
AQueue<T>::AQueue()
{
  // Empty queue has no values nor any allocated memory
  // associated with it
  this->size = 0;
  this->allocationSize = 0;
  this->frontIndex = 0;
  this->backIndex = -1; // for empty queue, back index is an invalid index
  values = nullptr;
}

/**
 * @brief Standard constructor
 *
 * Construct a queue of  values from a (statically) defined and
 * provided array of values.  We simply allocate a block of memory
 * dynamically large enough to hold the values, then copy the values
 * from the input parameter into our own private array of values.
 *
 * @param size The size of the input values were are given as well as the
 *   size of the new queue we are to construct.
 * @param values The (static) array of values to use to construct
 *   this Queue values with.
 */
template<class T>
AQueue<T>::AQueue(int size, T values[])
{
  // dynamically allocate a block of memory on the heap large enough to copy
  // the given input values into
  this->size = size;
  this->allocationSize = size;
  this->values = new T[allocationSize];

  // copy the values from the input paramter into our new shiny block of memory
  for (int index = 0; index < size; index++)
  {
    this->values[index] = values[index];
  }

  // set up the front and back index.  Back index should point to the
  // last value of the array
  this->frontIndex = 0;
  this->backIndex = this->size - 1;
}

/**
 * @brief Copy constructor
 *
 * Provide a copy constructor for the Queue class.  A copy constructor
 * will be invoked whenver you assign one instance of a Queue to another.
 * For example
 *   Queue newQueue = existingQueue;
 * Where of course existingQueue was a previously created Queue.  This copy
 * constructor, as the name suggests, should make a copy of the values from
 * the given input queue into a new Queue instance.
 *
 * @param queue The other Queue we are to make a copy of in this
 *   constructor.
 */
template<class T>
AQueue<T>::AQueue(const AQueue<T>& queue)
{
  // copy the size of the existing queue and allocate memory to hold
  // values we will copy
  this->size = queue.getSize();
  allocationSize = 2 * this->size;
  values = new T[allocationSize];

  // copy the values from the input Queue into this queue
  for (int index = 0; index < this->size; index++)
  {
    values[index] = queue[index];
  }

  // set up front and back index.  Back index should point to the
  // last value of the array
  this->frontIndex = 0;
  this->backIndex = this->size - 1;
}

/**
 * @brief Class destructor
 *
 * Destructor for the Queue class.  A concrete Queue implementation must
 * provide a clear() method to clear all items and safely deallocate any
 * memory that the concrete instance is using.  Invoke the clear
 * of the concrete subclass to perform the destruction.
 */
template<class T>
AQueue<T>::~AQueue()
{
  // call clear to do actual work to deallocate any allocation
  // before we destruct
  this->clear();
}

/**
 * @brief Allocation size accessor
 *
 * Accessor method to get the current amount of memory allocated
 * by and being managed by this queue.
 *
 * @returns int Returns the current allocation size of the
 *   Queue of values.
 */
template<class T>
int AQueue<T>::getAllocationSize() const
{
  return allocationSize;
}

/**
 * @brief Access front of queue
 *
 * Accessor method to get a copy of the item currently
 * at the front of this queue.
 *
 * @returns T Returns a copy of the front item of the
 *   queue.
 *
 * @throws QueueEmptyException If an attempt is made to
 *   access front item of an empty queue, this exception
 *   is generated and thrown instead.
 */
template<class T>
T AQueue<T>::front() const
{
  // make sure queue is not empty before we try and access
  // the front item
  if (this->isEmpty())
  {
    ostringstream out;
    out << "Error: <AQueue>::top() attempt to get item"
        << " from empty queue, size:  " << this->size;

    throw QueueEmptyException(out.str());
  }

  // otherwise safe to return the top item
  return values[this->frontIndex];
}
/**
 * @brief Dequeue queue front item
 *
 * Dequeue the item from the front of the queue.  This operation is
 * O(1) constant time because we dequeue from the front of our AList
 */
template<class T>
void AQueue<T>::dequeue()
{
  // make sure queue is not empty before we try and access
  // the top item
  if (this->isEmpty())
  {
    ostringstream out;
    out << "Error: <AQueue>::dequeue() attempt to dequeue front item"
        << " from empty queue, size:  " << this->size;

    throw QueueEmptyException(out.str());
  }

  // simply increment the frontIndex
  this->frontIndex = (this->frontIndex + 1) % this->allocationSize;
  // decrement the size by 1
  this->size -= 1;
}

/**
 * @brief Queue to string
 *
 * Accessor method to construct and return a string representation
 * of the current values and status of this Queue instance.
 *
 * @returns string Returns the string constructed with the information
 *   about this Queue.
 */
template<class T>
string AQueue<T>::str() const
{
  ostringstream out;

  // stream queue information into the output stream
  out << "<queue> size: " << this->size << " front:[ ";

  // stream the current values of the queue to the output stream
  // the array is a circular buffer, so we use the size to
  // determine number of times loop should occur, and calculate
  // index to access as an offset from frontIndex, being careful to wrap
  // it around the buffer when it reaches the end
  for (int index = 0; index < this->size; index++)
  {
    // calculate the index in the circular buffer
    int queueIndex = (frontIndex + index) % allocationSize;

    // stream the value out
    out << values[queueIndex];

    // separate the values of the queue, last one does not need , separator
    if (queueIndex == backIndex)
    {
      out << " ";
    }
    else
    {
      out << ", ";
    }
  }
  out << "]:back";

  // convert the string stream into a concrete string to return
  return out.str();
}

/**
 * @brief Boolean equals operator
 *
 * Check if this Queue is equal to the right hand side (rhs) queue.
 * The queues are equal if their sizes are equal, and if all elements
 * in both queues are equal.
 *
 * @param rhs The other queue on the right hand side of the
 *   boolean comparison that we are comparing this Queue to.
 *
 * @returns bool true if the queues are equal, false if the are not.
 */
template<class T>
bool AQueue<T>::operator==(const Queue<T>& rhs) const
{
  // first the queues have to be of the same size, or else they
  // cannot be equal
  if (this->size != rhs.getSize())
  {
    return false;
  }

  // otherwise, queues are equal if all elements are equal.
  // compare each element, and if we find a pair that is not
  // equal then the answer is false
  for (int rhsIndex = 0; rhsIndex < rhs.getSize(); rhsIndex++)
  {
    int lhsIndex = (frontIndex + rhsIndex) % allocationSize;
    if (values[lhsIndex] != rhs[rhsIndex])
    {
      return false;
    }
  }

  // if we get to this point, all values were the same in both
  // queues, so the answer is true, the queues are equal
  return true;
}

/**
 * @brief Indexing operator
 *
 * Provide a way to index individual values in our private
 * internal array of integers.  This allows code to, for the
 * most part, treated an instance of our Queue as if it were
 * an array, though we also provide bounds checking to ensure
 * no illegal access beyond the queue bounds is attempted.
 *
 * @param index The index of the value it is desired to access from
 *   this Queue.  Index 0 should indicate front of queue, and
 *   index size - 1 is back item of queue.
 *
 * @returns int& Returns a reference to the requested Queue item at
 *   the requested index.
 *
 * @throws QueueMemoryBoundsException if a request for an index beyond
 *   the end of the array (or less than 0) is made.
 */
template<class T>
T& AQueue<T>::operator[](int index) const
{
  // first check that the requsted index is legally
  // within the bounds of the current size of our queue
  if ((index < 0) or (index >= this->size))
  {
    ostringstream out;
    out << "Error: <AQueue::operator[]> illegal bounds access, queue size: " << this->size << " tried to access index address: " << index;

    throw QueueMemoryBoundsException(out.str());
  }

  // otherwise it is safe to return the reference to this value in
  // order for queue to be compatible with other queue
  // implementations, the values is a circular bufer so we need to
  // interpret index 0 as front of queue, pointed to by frontIndex,
  // and the back item is at the backIndex of the array.
  int queueIndex = (frontIndex + index) % allocationSize;
  return values[queueIndex];
}

/**
 * @brief Clear out queue
 *
 * Clear or empty out the queue.  Return the queue back
 * to an empty queue.
 */
template<class T>
void AQueue<T>::clear()
{
  // if values is not null, it points to a dynamic block of memory, so
  // delete that block.
  if (values != nullptr)
  {
    delete[] values;
    values = nullptr;
  }

  // make sure size and allocation are both reading as 0 now
  this->size = 0;
  allocationSize = 0;
  this->frontIndex = 0;
  this->backIndex = -1;
}

/**
 * @brief Grow queue allocation
 *
 * Private member method that will increase the memory allocation if
 * the queue is currently at capacity.  To do this, we double the
 * current allocation, copy all of the values from the original block
 * of memory to the new block of memory, then delete the old block
 * that is no longer needed.  This method is called by methods that
 * need to grow the queue, to ensure we have enough allocated capacity
 * to accommodate the growth.
 */
template<class T>
void AQueue<T>::growQueueIfNeeded()
{
  // if size is still less than what we have allocated, we still have room
  // to grow at least one or more items in sizes
  if (this->size < allocationSize)
  {
    return;
  }

  // otherwise size is equal to our allocation, double the size of our allocation
  // to accommodate future growth, or make size 10 initially by default if
  // an empty queue is being grown
  int newAllocationSize;
  if (allocationSize == 0)
  {
    newAllocationSize = INITIAL_ALLOCATION_SIZE;
  }
  else
  {
    newAllocationSize = 2 * allocationSize;
  }

  // dynamically allocate a new block of values of the new size
  T* newValues = new T[newAllocationSize];

  // copy the values from the original memory to this new block of memory
  // we will just go ahead and copy the values in the possibly wrapped
  // original buffer to index 0 of the new block of values
  int oldIndex = frontIndex;
  for (int newIndex = 0; newIndex < this->size; newIndex++)
  {
    newValues[newIndex] = values[oldIndex];
    oldIndex = (oldIndex + 1) % allocationSize;
  }

  // we don't need the old block of memory anymore, be good managers of
  // memory and return it to the heap
  delete[] values;

  // now make sure we are using the new block of memory going forward for this
  // queue
  values = newValues;
  allocationSize = newAllocationSize;
  frontIndex = 0;
  backIndex = this->size - 1;
}

/**
 * @brief Cause specific instance compilations
 *
 * This is a bit of a kludge, but we can use normal make dependencies
 * and separate compilation by declaring template class Queue<needed_type>
 * here of any types we are going to be instantianting with the
 * template.
 *
 * https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
 * https://isocpp.org/wiki/faq/templates#separate-template-class-defn-from-decl
 */
template class AQueue<int>;
template class AQueue<string>;
template class AQueue<Job>;
