/** @file LQueue.cpp
 * @brief Concrete link list based implementation of Queue ADT.
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
 * deletes these nodes when the value is popped back off.  The Node
 * structure defined in the Node.hpp header file is used by this queue
 * and is private to this queue member functions.  We use the back of
 * the linked list to enqueue items onto the queue, and the front of
 * the list to dequeue items from.  This is the natural interpretation
 * of the queue, and since we are only removing from the front, both
 * enqueue and dequeue are constant time O(1) operations.
 */
#include "LQueue.hpp"
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
LQueue<T>::LQueue()
{
  // Empty queue has size 0 and top is null
  this->size = 0;
  frontNode = nullptr;
  backNode = nullptr;
}

/**
 * @brief Standard constructor
 *
 * Construct a queue of values from a (statically) defined and
 * provided array of values.  We need to dynamically construct
 * a node for each value in the array and create a linked queue of these
 * nodes.
 *
 * @param size The size of the input values we are given as well as the
 *   size of the new queue we are to construct.
 * @param values The (static) array of values to use to construct
 *   this new Queue of values with.
 */
template<class T>
LQueue<T>::LQueue(int size, T values[])
{
  // Make sure queue is empty before copying values from array.
  // Empty queue has size 0 and top is null
  this->size = 0;
  frontNode = nullptr;
  backNode = nullptr;

  // iterate through the array reusing member functions to
  // simply insert new values one-by-one on the back.
  for (int index = 0; index < size; index++)
  {
    enqueue(values[index]);
  }
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
 * @param queue The other Queue type we are to make a copy of in this
 *   constructor.
 */
template<class T>
LQueue<T>::LQueue(const LQueue<T>& queue)
{
  // Make sure queue is empty before copying values from other queue.
  // Empty queue has size 0 and top is null
  this->size = 0;
  frontNode = nullptr;
  backNode = nullptr;

  // if the other queue is not empty, then we need to iterate through
  // its values and insert them into the back of this queue
  for (int index = 0; index < queue.getSize(); index++)
  {
    enqueue(queue[index]);
  }
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
LQueue<T>::~LQueue()
{
  // call clear to do actual work to deallocate any allocation
  // before we destruct
  clear();
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
T LQueue<T>::front() const
{
  // make sure queue is not empty before we try and access
  // the front item
  if (this->isEmpty())
  {
    ostringstream out;
    out << "Error: <LQueue>::top() attempt to get item"
        << " from empty queue, size:  " << this->size;

    throw QueueEmptyException(out.str());
  }

  // otherwise safe to return the top item
  return frontNode->value;
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
string LQueue<T>::str() const
{
  ostringstream out;

  // stream queue information into the output stream
  out << "<queue> size: " << this->size << " front:[ ";

  // stream the current values of the queue to the output stream
  Node<T>* current = frontNode;
  while (current != nullptr)
  {
    // put value out to the stream
    out << current->value;

    // advance to the next value
    current = current->next;

    // separate for next value, or just space if no more values
    if (current == nullptr)
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
 * Check if this Queue is equal to the right hand side (rhs)
 * queue.  The queues are equal if their sizes are equal, and if
 * all elements in both queues are equal.
 *
 * @param rhs The other queue on the right hand side of the
 *   boolean comparison that we are comparing this Queue to.
 *
 * @returns bool true if the queues are equal, false if the are not.
 */
template<class T>
bool LQueue<T>::operator==(const Queue<T>& rhs) const
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
  for (int index = 0; index < this->size; index++)
  {
    if (this->operator[](index) != rhs[index])
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
 * linked queue of values.  This allows code to, for the
 * most part, treated an instance of our Queue as if it were
 * an array, though we also provide bounds checking to ensure
 * no illegal access beyond the queue bounds is attempted.
 *
 * @param index The index of the value it is desired to access from
 *   this Queue.
 *
 * @returns int& Returns a reference to the requested Queue item at
 *   the requested index.
 *
 * @throws QueueMemoryBoundsException if a request for an index beyond
 *   the end of the array (or less than 0) is made.
 */
template<class T>
T& LQueue<T>::operator[](int index) const
{
  // first check that the requsted index is legally
  // within the bounds of the current size of our queue
  if ((index < 0) or (index >= this->size))
  {
    ostringstream out;
    out << "Error: <LQueue::operator[]> illegal bounds access, queue size: " << this->size << " tried to access index address: " << index;

    throw QueueMemoryBoundsException(out.str());
  }

  // otherwise it is safe to return the reference to the value, but
  // we have to do some work to find it first
  Node<T>* current = frontNode;
  for (int currentIdx = 0; currentIdx < index; currentIdx++)
  {
    // advance to next node until we reach the index'th node of
    // this queue
    current = current->next;
  }

  // return the reference to the value in the index'th node of the
  // queue
  return current->value;
}

/**
 * @brief Clear out queue
 *
 * Clear or empty out the queue.  Return the queue back
 * to an empty queue.
 */
template<class T>
void LQueue<T>::clear()
{
  // if the queue is not empty, we need to deallocate and return the nodes
  // back to the heap
  if (not this->isEmpty())
  {
    Node<T>* current = frontNode;

    // iterate through the nodes of the queue to delete them
    while (current != nullptr)
    {
      // remember this node to delete while advancing
      // to next node for next iteration
      Node<T>* nodeToDelete = current;
      current = current->next;

      // now safe to free up the memory of this node
      delete nodeToDelete;
    }
  }

  // make sure size is now 0 and top is null again
  this->size = 0;
  frontNode = nullptr;
  backNode = nullptr;
}

/**
 * @brief Enqueue value on back of queue
 *
 * Enqueue the value to the back of this Queue.
 *
 * @param value The value to enqueue on back of the current queue.
 */
template<class T>
void LQueue<T>::enqueue(const T& value)
{
  // dynamically allocate a new Node to hold the value
  Node<T>* newNode = new Node<T>;
  newNode->value = value;
  newNode->next = nullptr;

  // if queue is currently empty, this node becomes the front and back
  if (this->isEmpty())
  {
    frontNode = newNode;
  }
  // otherwise at least one node, so just make this the new back node
  else
  {
    backNode->next = newNode;
  }

  // this new node is always the new back node
  backNode = newNode;

  // queue has now grown by 1 item, don't forget to update size member
  // variable
  this->size += 1;
}

/**
 * @brief Dequeue queue front item
 *
 * Dequeue the item from the front of the queue.  This operation is
 * O(1) constant time because we dequeue from the front of our singly
 * linked list.
 */
template<class T>
void LQueue<T>::dequeue()
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

  // remember current front
  Node<T>* nodeToDelete = frontNode;

  // move to new front
  frontNode = frontNode->next;

  // delete the node we removed
  delete nodeToDelete;

  // update queue size since we just removed a node
  this->size -= 1;

  // queue could have become empty, so if it did make sure backNode
  // is updated as well
  if (this->isEmpty())
  {
    frontNode = nullptr;
    backNode = nullptr;
  }
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
template class LQueue<int>;
template class LQueue<string>;
template class LQueue<Job>;
