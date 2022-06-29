/** @file APriorityQueue.cpp
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
 * operator<() is defined for the type T being managed, and that
 * it returns true when the lhs T value is higher priority than the
 * rhs T value.
 */
#include "APriorityQueue.hpp"
#include "Job.hpp"
#include "QueueException.hpp"
using namespace std;

// define macros to make it easier to access the base class protected
// members without all of the cruft
#define size AQueue<T>::size
#define allocationSize AQueue<T>::allocationSize
#define frontIndex AQueue<T>::frontIndex
#define backIndex AQueue<T>::backIndex
#define values AQueue<T>::values
#define growQueueIfNeeded() AQueue<T>::growQueueIfNeeded()

/**
 * @brief Default constructor
 *
 * Construct an empty queue.  The empty queue will have no allocated memory
 * nor any values.
 */
template<class T>
APriorityQueue<T>::APriorityQueue()
  : AQueue<T>()
{
}

/**
 * @brief Standard constructor
 *
 * Construct a queue of  values from a (statically) defined and
 * provided array of values.  We simply allocate a block of memory
 * dynamically large enough to hold the values, then copy the values
 * from the input parameter into our own private array of values.
 *
 * @param initSize The size of the input values were are given as well as the
 *   size of the new queue we are to construct.
 * @param initValues The (static) array of values to use to construct
 *   this Queue values with.
 */
template<class T>
APriorityQueue<T>::APriorityQueue(int initSize, T initValues[])
  : AQueue<T>(initSize, initValues)
{
}

/**
 * @brief Implement true modulo
 *
 * Unfortunately the C/C++ `%` operation actually gives the remainder
 * instead of the true modulo value.  Modulo of a positive number should always
 * be a positive remainder.  Thus
 *     -1 modulo 5 == 4.
 * But C/C++ '%' operation actually returns the remainder,
 *     -1 remainder 5 == -1 because -1 goes into 5 0 times with a remainder of -1
 * For our circular buffer, we want a true modulo operation, so we implement
 * as a private function to use in our enqueue() method.
 *
 * @param dividend The top number in the division/modulo operation we are
 *   performing.
 * @param divisor The bottom number in the divison/modulo operation.
 *
 * @returns int Returns true modulo of the division.  If the divisor is positive,
 *   we return a positive remainder.
 */
template<class T>
int APriorityQueue<T>::modulo(int dividend, int divisor)
{
  int remainder = dividend % divisor;

  if ((divisor > 0) and (remainder < 0))
  {
    remainder = divisor + remainder;
  }

  return remainder;
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
template class APriorityQueue<int>;
template class APriorityQueue<string>;
template class APriorityQueue<Job>;
