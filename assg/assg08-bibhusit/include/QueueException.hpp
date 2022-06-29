/** @file QueueException.hpp
 * @brief Declare Exceptions that can be thrown by Queue instances.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Queues
 * @date   June 1, 2021
 *
 * Declare all exceptions that can be generated and thrown by Queue
 * instances.
 */
#ifndef _QUEUE_EXCEPTION_HPP_
#define _QUEUE_EXCEPTION_HPP_
#include <string>
using namespace std;

/** @class QueueEmptyException
 * @brief Queue Empty Exception for the Queue class.
 *
 * Exception to be thrown by our Queue class if attempt to access item
 * from top of an empty queue is attempted.
 *
 */
class QueueEmptyException : public exception
{
public:
  explicit QueueEmptyException(const string& message);
  ~QueueEmptyException();
  virtual const char* what() const throw();

private:
  /// Stores the particular message describing what caused the exception.
  string message;
};

/** @class QueueMemoryBoundsException
 * @brief Memory Bounds Exception for the Queue class.
 *
 * Exception to be thrown by our Queue class if an illegal memory
 * bounds access is attempted.  Not a normal exception, but for this
 * assignment we provide an indexing operator mostly for debugging
 * purposes of the queue
 *
 */
class QueueMemoryBoundsException : public exception
{
public:
  explicit QueueMemoryBoundsException(const string& message);
  ~QueueMemoryBoundsException();
  virtual const char* what() const throw();

private:
  /// Stores the particular message describing what caused the exception.
  string message;
};

#endif // _QUEUE_EXCEPTION_HPP_