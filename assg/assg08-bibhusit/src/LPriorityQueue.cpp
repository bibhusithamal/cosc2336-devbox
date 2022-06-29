/** @file LPriorityQueue.cpp
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
#include "LPriorityQueue.hpp"
#include "Job.hpp"
#include "QueueException.hpp"
using namespace std;

// define macros to make it easier to access the base class protected
// members without all of the cruft
#define size LQueue<T>::size
#define frontNode LQueue<T>::frontNode
#define backNode LQueue<T>::backNode

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
template class LPriorityQueue<int>;
template class LPriorityQueue<string>;
template class LPriorityQueue<Job>;