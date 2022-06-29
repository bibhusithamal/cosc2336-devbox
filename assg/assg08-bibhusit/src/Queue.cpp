/** @file Queue.cpp
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
 * Implementation of Queue base class concrete member functions
 * and friend functions.
 */
#include "Queue.hpp"
#include "Job.hpp"
#include <iostream>
using namespace std;

/**
 * @brief Size accessor
 *
 * Accessor method to get the current size of this Queue of values.
 *
 * @returns int Returns the current size of the queue of values.
 */
template<class T>
int Queue<T>::getSize() const
{
  return size;
}

/**
 * @brief Check if empty queue
 *
 * Accessor method to test if the Queue is currently
 * empty or not.
 *
 * @returns bool Returns true if the Queue is currently
 *   empty, or false if it has 1 or more items.
 */
template<class T>
bool Queue<T>::isEmpty() const
{
  // can simply test size, if it is equal to 0, then it is true the
  // queue is empty, if it is not equal, then the answer is false
  return size == 0;
}

/**
 * @brief Overload output stream operator for Queue type.
 *
 * Overload the output stream operator so that we can display current
 * values of a Queue on standard output.  We can define this in the
 * base class because concrete derived classes must implement the
 * actual str() method that is used here to represent the
 * queue as a string object output.
 *
 * @param out The output stream we should send the representation
 *   of the current Queue to.
 * @param rhs The Queue object to create and return a string
 *   representation of on the output stream.
 *
 * @returns ostream& Returns a reference to the originaly provided
 *   output stream, but after we  have inserted current Queue
 *   values / representation onto the stream
 */
template<typename U>
ostream& operator<<(ostream& out, const Queue<U>& rhs)
{
  // reuse Queue str() method to stream to output stream
  out << rhs.str();

  // return the modified output stream as our result
  return out;
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
template ostream& operator<<<int>(ostream&, const Queue<int>&);
template ostream& operator<<<string>(ostream&, const Queue<string>&);

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
template class Queue<int>;
template class Queue<string>;
template class Queue<Job>;
