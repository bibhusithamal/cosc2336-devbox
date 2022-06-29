/** @file test-LPriorityQueue.cpp
 * @brief Unit tests for Assignment Queues
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Queues
 * @date   June 1, 2021
 *
 * Tests of the array based implementation of the Priority Queue API.
 */
#include "Job.hpp"
#include "LPriorityQueue.hpp"
#include "QueueException.hpp"
#include "catch.hpp"
#include <iostream>
using namespace std;

/** Task 5: Test LPriorityQueue<int> concrete array implementation of
 * priority queue of integers
 */
/*
TEST_CASE("LPriorityQueue<int> test integer priority queue concrete array implementation", "[task5]")
{
  LPriorityQueue<int> priorityQueue;

  // priority queue is initially empty
  CHECK(priorityQueue.isEmpty());
  CHECK(priorityQueue.getSize() == 0);
  CHECK(priorityQueue.str() == "<queue> size: 0 front:[ ]:back");
  CHECK_THROWS_AS(priorityQueue.front(), QueueEmptyException);
  CHECK_THROWS_AS(priorityQueue.dequeue(), QueueEmptyException);

  // test case 1 insertion into empty priority queue
  priorityQueue.enqueue(5);
  CHECK_FALSE(priorityQueue.isEmpty());
  CHECK(priorityQueue.getSize() == 1);
  CHECK(priorityQueue.str() == "<queue> size: 1 front:[ 5 ]:back");
  CHECK(priorityQueue.front() == 5);

  // test case 2 new node is highest priority and should end up on front
  priorityQueue.enqueue(10);
  CHECK_FALSE(priorityQueue.isEmpty());
  CHECK(priorityQueue.getSize() == 2);
  CHECK(priorityQueue.str() == "<queue> size: 2 front:[ 10, 5 ]:back");
  CHECK(priorityQueue.front() == 10);

  // Test case 3 new node ends up somewhere in middle of the queue
  priorityQueue.enqueue(7);
  CHECK_FALSE(priorityQueue.isEmpty());
  CHECK(priorityQueue.getSize() == 3);
  CHECK(priorityQueue.str() == "<queue> size: 3 front:[ 10, 7, 5 ]:back");
  CHECK(priorityQueue.front() == 10);

  // Test case 3+/4 need to correctl handle when new node ends up on the end
  priorityQueue.enqueue(3);
  CHECK_FALSE(priorityQueue.isEmpty());
  CHECK(priorityQueue.getSize() == 4);
  CHECK(priorityQueue.str() == "<queue> size: 4 front:[ 10, 7, 5, 3 ]:back");
  CHECK(priorityQueue.front() == 10);

  priorityQueue.enqueue(1);
  CHECK_FALSE(priorityQueue.isEmpty());
  CHECK(priorityQueue.getSize() == 5);
  CHECK(priorityQueue.str() == "<queue> size: 5 front:[ 10, 7, 5, 3, 1 ]:back");
  CHECK(priorityQueue.front() == 10);

  // equal priority, we can't see if this works on ints, but when
  // items of equal priority are put on queue, the first item should be ahead
  // of the new item in the resulting queue
  priorityQueue.enqueue(5);
  CHECK_FALSE(priorityQueue.isEmpty());
  CHECK(priorityQueue.getSize() == 6);
  CHECK(priorityQueue.str() == "<queue> size: 6 front:[ 10, 7, 5, 5, 3, 1 ]:back");
  CHECK(priorityQueue.front() == 10);

  // also test dequeue and clear still work.
  priorityQueue.dequeue();
  CHECK(priorityQueue.getSize() == 5);
  CHECK(priorityQueue.front() == 7);
  CHECK(priorityQueue.str() == "<queue> size: 5 front:[ 7, 5, 5, 3, 1 ]:back");

  priorityQueue.dequeue();
  priorityQueue.dequeue();
  CHECK(priorityQueue.getSize() == 3);
  CHECK(priorityQueue.front() == 5);
  CHECK(priorityQueue.str() == "<queue> size: 3 front:[ 5, 3, 1 ]:back");

  priorityQueue.clear();
  CHECK(priorityQueue.isEmpty());
  CHECK(priorityQueue.getSize() == 0);
  CHECK(priorityQueue.str() == "<queue> size: 0 front:[ ]:back");
  CHECK_THROWS_AS(priorityQueue.front(), QueueEmptyException);
  CHECK_THROWS_AS(priorityQueue.dequeue(), QueueEmptyException);
}
*/

/** Task 5: Test LPriorityQueue<string> concrete array implementation of
 * priority queue of string
 */
/*
TEST_CASE("LPriorityQueue<string> test string priority queue concrete array implementation", "[task5]")
{
  LPriorityQueue<string> priorityQueue;

  // priority queue is initially empty
  CHECK(priorityQueue.isEmpty());
  CHECK(priorityQueue.getSize() == 0);
  CHECK(priorityQueue.str() == "<queue> size: 0 front:[ ]:back");
  CHECK_THROWS_AS(priorityQueue.front(), QueueEmptyException);
  CHECK_THROWS_AS(priorityQueue.dequeue(), QueueEmptyException);

  // test case 1 insertion into empty priority queue
  priorityQueue.enqueue("echo");
  CHECK_FALSE(priorityQueue.isEmpty());
  CHECK(priorityQueue.getSize() == 1);
  CHECK(priorityQueue.str() == "<queue> size: 1 front:[ echo ]:back");
  CHECK(priorityQueue.front() == "echo");

  // test case 2 new node is highest priority and should end up on front
  priorityQueue.enqueue("juliet");
  CHECK_FALSE(priorityQueue.isEmpty());
  CHECK(priorityQueue.getSize() == 2);
  CHECK(priorityQueue.str() == "<queue> size: 2 front:[ juliet, echo ]:back");
  CHECK(priorityQueue.front() == "juliet");

  // Test case 3 new node ends up somewhere in middle of the queue
  priorityQueue.enqueue("golf");
  CHECK_FALSE(priorityQueue.isEmpty());
  CHECK(priorityQueue.getSize() == 3);
  CHECK(priorityQueue.str() == "<queue> size: 3 front:[ juliet, golf, echo ]:back");
  CHECK(priorityQueue.front() == "juliet");

  // Test case 3+/4 need to correctly handle when new node ends up on the end
  priorityQueue.enqueue("charlie");
  CHECK_FALSE(priorityQueue.isEmpty());
  CHECK(priorityQueue.getSize() == 4);
  CHECK(priorityQueue.str() == "<queue> size: 4 front:[ juliet, golf, echo, charlie ]:back");
  CHECK(priorityQueue.front() == "juliet");

  priorityQueue.enqueue("alpha");
  CHECK_FALSE(priorityQueue.isEmpty());
  CHECK(priorityQueue.getSize() == 5);
  CHECK(priorityQueue.str() == "<queue> size: 5 front:[ juliet, golf, echo, charlie, alpha ]:back");
  CHECK(priorityQueue.front() == "juliet");

  // equal priority, we can't see if this works on string, but when
  // items of equal priority are put on queue, the first item should be ahead
  // of the new item in the resulting queue
  priorityQueue.enqueue("echo");
  CHECK_FALSE(priorityQueue.isEmpty());
  CHECK(priorityQueue.getSize() == 6);
  CHECK(priorityQueue.str() == "<queue> size: 6 front:[ juliet, golf, echo, echo, charlie, alpha ]:back");
  CHECK(priorityQueue.front() == "juliet");

  // also test dequeue and clear still work.
  priorityQueue.dequeue();
  CHECK(priorityQueue.getSize() == 5);
  CHECK(priorityQueue.front() == "golf");
  CHECK(priorityQueue.str() == "<queue> size: 5 front:[ golf, echo, echo, charlie, alpha ]:back");

  priorityQueue.dequeue();
  priorityQueue.dequeue();
  CHECK(priorityQueue.getSize() == 3);
  CHECK(priorityQueue.front() == "echo");
  CHECK(priorityQueue.str() == "<queue> size: 3 front:[ echo, charlie, alpha ]:back");

  priorityQueue.clear();
  CHECK(priorityQueue.isEmpty());
  CHECK(priorityQueue.getSize() == 0);
  CHECK(priorityQueue.str() == "<queue> size: 0 front:[ ]:back");
  CHECK_THROWS_AS(priorityQueue.front(), QueueEmptyException);
  CHECK_THROWS_AS(priorityQueue.dequeue(), QueueEmptyException);
}
*/

/** Task 5: test PriorityQueue class on linked list based priority queue using Job objects
 */
/*
TEST_CASE("LPriorityQueue enqueue<Job> Test LPriorityQueue using Job items", "[task5]")
{
  LPriorityQueue<Job> priorityQueue;
  int nextId = 7; // just ot make unique starting id

  // priority queue is initially empty
  CHECK(priorityQueue.isEmpty());
  CHECK(priorityQueue.getSize() == 0);
  CHECK(priorityQueue.str() == "<queue> size: 0 front:[ ]:back");
  CHECK_THROWS_AS(priorityQueue.front(), QueueEmptyException);
  CHECK_THROWS_AS(priorityQueue.dequeue(), QueueEmptyException);

  // test case 1 insertion into empty priority queue
  // look in JobSimulator.hpp for Job constructor
  // Job(5, 0, 0) is Job(priority, serviceTime, startTime), we only use priority
  // for these tests
  priorityQueue.enqueue(Job(5, 0, 0, nextId++));
  CHECK_FALSE(priorityQueue.isEmpty());
  CHECK(priorityQueue.getSize() == 1);
  CHECK(priorityQueue.str() == "<queue> size: 1 front:[ (id: 7 priority: 5) ]:back");
  CHECK(priorityQueue.front().str() == "(id: 7 priority: 5)");

  // test case 2 new Job is highest priority and should end up on front
  priorityQueue.enqueue(Job(10, 5, 5, nextId++));
  CHECK_FALSE(priorityQueue.isEmpty());
  CHECK(priorityQueue.getSize() == 2);
  CHECK(priorityQueue.str() == "<queue> size: 2 front:[ (id: 8 priority: 10), (id: 7 priority: 5) ]:back");
  CHECK(priorityQueue.front().str() == "(id: 8 priority: 10)");

  // Test case 3 new Job ends up somewhere in middle of the queue
  priorityQueue.enqueue(Job(7, 1, 1, nextId++));
  CHECK_FALSE(priorityQueue.isEmpty());
  CHECK(priorityQueue.getSize() == 3);
  CHECK(priorityQueue.str() == "<queue> size: 3 front:[ (id: 8 priority: 10), (id: 9 priority: 7), (id: 7 priority: 5) ]:back");
  CHECK(priorityQueue.front().str() == "(id: 8 priority: 10)");

  // Test case 3+/4 need to correctl handle when new node ends up on the end
  priorityQueue.enqueue(Job(3, 4, 5, nextId++));
  CHECK_FALSE(priorityQueue.isEmpty());
  CHECK(priorityQueue.getSize() == 4);
  CHECK(priorityQueue.str() ==
        "<queue> size: 4 front:[ (id: 8 priority: 10), (id: 9 priority: 7), (id: 7 priority: 5), (id: 10 priority: 3) ]:back");
  CHECK(priorityQueue.front().str() == "(id: 8 priority: 10)");

  priorityQueue.enqueue(Job(1, 2, 3, nextId++));
  CHECK_FALSE(priorityQueue.isEmpty());
  CHECK(priorityQueue.getSize() == 5);
  CHECK(priorityQueue.str() == "<queue> size: 5 front:[ (id: 8 priority: 10), (id: 9 priority: 7), (id: 7 priority: 5), (id: 10 priority: "
                               "3), (id: 11 priority: 1) ]:back");
  CHECK(priorityQueue.front().str() == "(id: 8 priority: 10)");

  // equal priority, we insert another Job with priority 5, it should end up on
  // the queu after the existing Job with same priority if you implement your
  // enqueue function correctly
  priorityQueue.enqueue(Job(5, 9, 9, nextId++));
  CHECK_FALSE(priorityQueue.isEmpty());
  CHECK(priorityQueue.getSize() == 6);
  CHECK(priorityQueue.str() == "<queue> size: 6 front:[ (id: 8 priority: 10), (id: 9 priority: 7), (id: 7 priority: 5), (id: 12 priority: "
                               "5), (id: 10 priority: 3), (id: 11 priority: 1) ]:back");
  CHECK(priorityQueue.front().str() == "(id: 8 priority: 10)");
  CHECK(priorityQueue[2].getId() == 7);
  CHECK(priorityQueue[3].getId() == 12);
}
*/
