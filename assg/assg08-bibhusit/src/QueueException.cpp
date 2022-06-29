/** @file QueueException.cpp
 * @brief Implement Exceptions that can be thrown by Queue instances.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Queues
 * @date   June 1, 2021
 *
 * Implement all exception methods that can be generated and thrown by Queue
 * instances.
 */
#include "QueueException.hpp"
#include <string>
using namespace std;

/**
 * @brief QueueEmptyException constructor
 *
 * Constructor for exceptions used for our
 * Queue  class.
 *
 * @param message The exception message thrown when an error occurs.
 */
QueueEmptyException::QueueEmptyException(const string& message)
{
  this->message = message;
}

/**
 * @brief QueueEmptyException destructor
 *
 * Destructor for exceptions used for our QueueEmptyException
 * class.
 */
QueueEmptyException::~QueueEmptyException() {}

/**
 * @brief QueueEmptyException message
 *
 * Accessor method to access/return message given when an exception occurs.
 *
 * @returns char* Returns a const old style c character array message for
 *   display/use by the process that catches this exception.
 */
const char* QueueEmptyException::what() const throw()
{
  // what expects old style array of characters, so convert to that
  return message.c_str();
}

/**
 * @brief QueueMemoryBoundsException constructor
 *
 * Constructor for exceptions used for our
 * Queue  class.
 *
 * @param message The exception message thrown when an error occurs.
 */
QueueMemoryBoundsException::QueueMemoryBoundsException(const string& message)
{
  this->message = message;
}

/**
 * @brief QueueMemoryBoundsException destructor
 *
 * Destructor for exceptions used for our QueueMemoryBoundsException
 * class.
 */
QueueMemoryBoundsException::~QueueMemoryBoundsException() {}

/**
 * @brief QueueMemoryBoundsException message
 *
 * Accessor method to access/return message given when an exception occurs.
 *
 * @returns char* Returns a const old style c character array message for
 *   display/use by the process that catches this exception.
 */
const char* QueueMemoryBoundsException::what() const throw()
{
  // what expects old style array of characters, so convert to that
  return message.c_str();
}