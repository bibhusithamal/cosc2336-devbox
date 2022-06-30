/** @file test-AQueue.cpp
 * @brief Unit tests for Assignment Queues
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Queues
 * @date   June 1, 2021
 *
 * Tests of the array based implementation of the Queue API.
 */
#include "AQueue.hpp"
#include "QueueException.hpp"
#include "catch.hpp"
#include <cmath>
#include <iostream>
using namespace std;

/** Task 1: Test AQueue front() member method basic functionality.
 */

TEST_CASE("AQueue test front() member method basic functionality", "[task1]")
{
  SECTION("test front on a queue of integer values")
  {
    // front value of queue of size 1
    int values1[] = {7};
    AQueue<int> queue1(1, values1);
    CHECK(queue1.getSize() == 1);
    CHECK_FALSE(queue1.isEmpty());
    CHECK(queue1.front() == 7);
    CHECK(queue1.str() == "<queue> size: 1 front:[ 7 ]:back");

    // front value of queue of size 2
    int values2[] = {11, 7};
    AQueue<int> queue2(2, values2);
    CHECK(queue2.getSize() == 2);
    CHECK_FALSE(queue2.isEmpty());
    CHECK(queue2.front() == 11);
    CHECK(queue2.str() == "<queue> size: 2 front:[ 11, 7 ]:back");

    // front value of queue of size 3
    int values3[] = {42, 11, 7};
    AQueue<int> queue3(3, values3);
    CHECK(queue3.getSize() == 3);
    CHECK_FALSE(queue3.isEmpty());
    CHECK(queue3.front() == 42);
    CHECK(queue3.str() == "<queue> size: 3 front:[ 42, 11, 7 ]:back");

    // attempt to peek at front of empty queue should cause a complaint
    AQueue<int> empty;
    CHECK_THROWS_AS(empty.front(), QueueEmptyException);
  }

  SECTION("test front on a queue of string values")
  {
    // front value of queue of size 1
    string values1[] = {"golf"};
    AQueue<string> queue1(1, values1);
    CHECK(queue1.getSize() == 1);
    CHECK_FALSE(queue1.isEmpty());
    CHECK(queue1.front() == "golf");
    CHECK(queue1.str() == "<queue> size: 1 front:[ golf ]:back");

    // front value of queue of size 2
    string values2[] = {"kilo", "golf"};
    AQueue<string> queue2(2, values2);
    CHECK(queue2.getSize() == 2);
    CHECK_FALSE(queue2.isEmpty());
    CHECK(queue2.front() == "kilo");
    CHECK(queue2.str() == "<queue> size: 2 front:[ kilo, golf ]:back");

    // front value of queue of size 3
    string values3[] = {"thanks-for-the-fish", "kilo", "golf"};
    AQueue<string> queue3(3, values3);
    CHECK(queue3.getSize() == 3);
    CHECK_FALSE(queue3.isEmpty());
    CHECK(queue3.front() == "thanks-for-the-fish");
    CHECK(queue3.str() == "<queue> size: 3 front:[ thanks-for-the-fish, kilo, golf ]:back");

    // attempt to peek at front of empty queue should cause a complaint
    AQueue<string> empty;
    CHECK_THROWS_AS(empty.front(), QueueEmptyException);
  }
}

/** Task 2: Test AQueue dequeue() member method basic functionality.
 */
/*
TEST_CASE("AQueue test dequeue() member method basic functionality", "[task2]")
{
  SECTION("test dequeue on a queue of integer values")
  {
    // initially queue has 3 items on it
    int values[] = {42, 11, 7};
    AQueue<int> queue(3, values);
    CHECK(queue.getSize() == 3);
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.front() == 42);
    CHECK(queue.str() == "<queue> size: 3 front:[ 42, 11, 7 ]:back");

    // dequeue the front item
    queue.dequeue();
    CHECK(queue.getSize() == 2);
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.front() == 11);
    CHECK(queue.str() == "<queue> size: 2 front:[ 11, 7 ]:back");

    // dequeue the next item, queue size reduced to 1 item now
    queue.dequeue();
    CHECK(queue.getSize() == 1);
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.front() == 7);
    CHECK(queue.str() == "<queue> size: 1 front:[ 7 ]:back");

    // dequeue the next item, queue should be empty now
    queue.dequeue();
    CHECK(queue.getSize() == 0);
    CHECK(queue.isEmpty());
    CHECK(queue.str() == "<queue> size: 0 front:[ ]:back");

    // attempt to dequeue from empty queue should cause complaints
    CHECK_THROWS_AS(queue.dequeue(), QueueEmptyException);
  }

  SECTION("test dequeue on a queue of string values")
  {
    // initially queue has 3 items on it
    string values[] = {"life-universe-everything", "kilo", "golf"};
    AQueue<string> queue(3, values);
    CHECK(queue.getSize() == 3);
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.front() == "life-universe-everything");
    CHECK(queue.str() == "<queue> size: 3 front:[ life-universe-everything, kilo, golf ]:back");

    // dequeue the front item
    queue.dequeue();
    CHECK(queue.getSize() == 2);
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.front() == "kilo");
    CHECK(queue.str() == "<queue> size: 2 front:[ kilo, golf ]:back");

    // dequeue the next item, queue size reduced to 1 item now
    queue.dequeue();
    CHECK(queue.getSize() == 1);
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.front() == "golf");
    CHECK(queue.str() == "<queue> size: 1 front:[ golf ]:back");

    // dequeue the next item, queue should be empty now
    queue.dequeue();
    CHECK(queue.getSize() == 0);
    CHECK(queue.isEmpty());
    CHECK(queue.str() == "<queue> size: 0 front:[ ]:back");

    // attempt to dequeue from empty queue should cause complaints
    CHECK_THROWS_AS(queue.dequeue(), QueueEmptyException);
  }
}
*/

/** Task 3: Test AQueue enqueue() member method basic functionality.
 */
/*
TEST_CASE("AQueue test enqueue() member method basic functionality", "[task3]")
{
  SECTION("test dequeue on a queue of integer values")
  { // initially queue is empty
    AQueue<int> queue;
    CHECK(queue.getSize() == 0);
    CHECK(queue.isEmpty());
    CHECK(queue.str() == "<queue> size: 0 front:[ ]:back");

    // enqueue item on back of empty queue
    queue.enqueue(7);
    CHECK(queue.getSize() == 1);
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.front() == 7);
    CHECK(queue.str() == "<queue> size: 1 front:[ 7 ]:back");

    // enqueue item where queue grows to size 2
    queue.enqueue(11);
    CHECK(queue.getSize() == 2);
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.front() == 7);
    CHECK(queue.str() == "<queue> size: 2 front:[ 7, 11 ]:back");

    // enqueue item where queue grows to size 3
    queue.enqueue(42);
    CHECK(queue.getSize() == 3);
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.front() == 7);
    CHECK(queue.str() == "<queue> size: 3 front:[ 7, 11, 42 ]:back");
  }
}
*/

/** Task 3: Test AQueue<int> concrete array implementation of queue of integers
 * Once you have completed task 3, uncomment the final 2 set of tests
 * cases to more extensively test the AQueue class implementation.
 */
/*
TEST_CASE("AQueue<int> test integer queue concrete array implementation", "[task3]")
{
  SECTION("test empty queue is empty")
  {
    // empty queues should be empty
    AQueue<int> empty;
    CHECK(empty.getSize() == 0);
    CHECK(empty.getAllocationSize() == 0); // only for AQueue
    CHECK(empty.isEmpty());
    CHECK(empty.str() == "<queue> size: 0 front:[ ]:back");

    // empty queues should compare as being equal
    AQueue<int> otherEmpty;
    CHECK(otherEmpty == empty);
    CHECK(empty == otherEmpty);

    // empty queues should complain if asked to get a value from them
    CHECK_THROWS_AS(empty.front(), QueueEmptyException);
    CHECK_THROWS_AS(empty[0], QueueMemoryBoundsException);

    // empty queue can be cleared and is still empty
    empty.clear();
    CHECK(empty.getSize() == 0);
    CHECK(empty.getAllocationSize() == 0); // only for AQueue<>
    CHECK(empty.isEmpty());
    CHECK(empty.str() == "<queue> size: 0 front:[ ]:back");
  }

  SECTION("test enqueue, dequeue and front general functionality")
  {
    // start with emtpy queue
    AQueue<int> queue;
    CHECK(queue.getSize() == 0);
    CHECK(queue.getAllocationSize() == 0); // only for AQueue
    CHECK(queue.isEmpty());
    CHECK(queue.str() == "<queue> size: 0 front:[ ]:back");

    // enqueue an item on empty queue
    queue.enqueue(5);
    CHECK(queue.getSize() == 1);
    CHECK(queue.getAllocationSize() == 10); // only for AQueue
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.front() == 5);
    CHECK(queue.str() == "<queue> size: 1 front:[ 5 ]:back");

    // enqueue a second  item on queue
    queue.enqueue(8);
    CHECK(queue.getSize() == 2);
    CHECK(queue.getAllocationSize() == 10); // only for AQueue
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.front() == 5);
    CHECK(queue.str() == "<queue> size: 2 front:[ 5, 8 ]:back");

    // enqueue a third item on queue
    queue.enqueue(15);
    CHECK(queue.getSize() == 3);
    CHECK(queue.getAllocationSize() == 10); // only for AQueue
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.front() == 5);
    CHECK(queue.str() == "<queue> size: 3 front:[ 5, 8, 15 ]:back");

    // test dequeue of queue with more than 1 item
    queue.dequeue();
    CHECK(queue.getSize() == 2);
    CHECK(queue.getAllocationSize() == 10); // only for AQueue
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.front() == 8);
    CHECK(queue.str() == "<queue> size: 2 front:[ 8, 15 ]:back");

    // enqueue 2 itmes on
    queue.enqueue(1);
    CHECK(queue.front() == 8);
    queue.enqueue(3);
    CHECK(queue.getSize() == 4);
    CHECK(queue.getAllocationSize() == 10); // only for AQueue
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.front() == 8);
    CHECK(queue.str() == "<queue> size: 4 front:[ 8, 15, 1, 3 ]:back");

    // dequeue back to 1 item
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    CHECK(queue.getSize() == 1);
    CHECK(queue.getAllocationSize() == 10); // only for AQueue
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.front() == 3);
    CHECK(queue.str() == "<queue> size: 1 front:[ 3 ]:back");

    // make queue empty again
    queue.dequeue();
    CHECK(queue.getSize() == 0);
    CHECK(queue.getAllocationSize() == 10); // only for AQueue
    CHECK(queue.isEmpty());
    CHECK(queue.str() == "<queue> size: 0 front:[ ]:back");

    // should complain if we try and dequeue an empty queue
    CHECK_THROWS_AS(queue.dequeue(), QueueEmptyException);

    // enqueue on 10 items
    for (int index = 1; index <= 10; index++)
    {
      queue.enqueue(pow(index, 3));
    }
    CHECK(queue.getSize() == 10);
    CHECK(queue.getAllocationSize() == 10); // only for AQueue
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.str() == "<queue> size: 10 front:[ 1, 8, 27, 64, 125, 216, 343, 512, 729, 1000 ]:back");

    // Array based queue should double in size, only for AQueue tests
    queue.enqueue(pow(11, 3));
    CHECK(queue.getSize() == 11);
    CHECK(queue.getAllocationSize() == 20); // only for AQueue
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.str() == "<queue> size: 11 front:[ 1, 8, 27, 64, 125, 216, 343, 512, 729, 1000, 1331 ]:back");
  }

  SECTION("test clear of queue")
  {
    // create queue of 11 values
    AQueue<int> queue;
    for (int index = 1; index <= 11; index++)
    {
      queue.enqueue(pow(index, 3));
    }
    CHECK(queue.getSize() == 11);
    CHECK(queue.getAllocationSize() == 20); // only for AQueue
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.str() == "<queue> size: 11 front:[ 1, 8, 27, 64, 125, 216, 343, 512, 729, 1000, 1331 ]:back");

    // clear the queue
    queue.clear();
    CHECK(queue.getSize() == 0);
    CHECK(queue.getAllocationSize() == 0); // only for AQueue
    CHECK(queue.isEmpty());
    CHECK(queue.str() == "<queue> size: 0 front:[ ]:back");

    // should be equal to an empty queue
    AQueue<int> empty;
    CHECK(empty == queue);
    CHECK(queue == empty);
  }

  SECTION("test array based constructor")
  {
    int values[] = {1, 3, -2, -4, 7};
    AQueue<int> queue(5, values);

    // nonempty queue should not be empty
    CHECK(queue.getSize() == 5);
    CHECK(queue.getAllocationSize() == 5); // only for AQueue<>
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.str() == "<queue> size: 5 front:[ 1, 3, -2, -4, 7 ]:back");

    // test access to front and back
    CHECK(queue.front() == 1);

    // test indexing access
    CHECK(queue[0] == 1);
    CHECK(queue[1] == 3);
    CHECK(queue[2] == -2);
    CHECK(queue[3] == -4);
    CHECK(queue[4] == 7);
    CHECK_THROWS_AS(queue[-1], QueueMemoryBoundsException);
    CHECK_THROWS_AS(queue[5], QueueMemoryBoundsException);
    queue[2] = 42;
    CHECK(queue[2] == 42);
    CHECK(queue.str() == "<queue> size: 5 front:[ 1, 3, 42, -4, 7 ]:back");

    // test inserting on queue, and that queue allocation grows as expected
    queue.enqueue(22);
    CHECK(queue.getSize() == 6);
    CHECK(queue.getAllocationSize() == 10); // only for AQueue<>
    CHECK(queue.front() == 1);
    CHECK(queue.str() == "<queue> size: 6 front:[ 1, 3, 42, -4, 7, 22 ]:back");

    queue.enqueue(38);
    CHECK(queue.getSize() == 7);
    CHECK(queue.getAllocationSize() == 10); // only for AQueue<>
    CHECK(queue.front() == 1);
    CHECK(queue.str() == "<queue> size: 7 front:[ 1, 3, 42, -4, 7, 22, 38 ]:back");
  }

  SECTION("test copy constructor")
  {
    int values[] = {3, 1, 4, 2};
    AQueue<int> queue(4, values);
    AQueue<int> copy = queue;

    // copy should be equal to the queue
    CHECK(copy == queue);
    CHECK(queue == copy);

    // copy is no longer equal
    queue.enqueue(5);
    CHECK_FALSE(copy == queue);
    CHECK_FALSE(queue == copy);

    // now they are the same again
    copy.enqueue(5);
    CHECK(copy == queue);
    CHECK(queue == copy);

    // now they are no longer equal, copy is 2 shorter
    copy.dequeue();
    copy.dequeue();
    CHECK_FALSE(copy == queue);
    CHECK_FALSE(queue == copy);
  }
}
*/

/** Task 3: Test AQueue<string> concrete array implementation of queue of strings
 * Once you have completed task 3, uncomment the final 2 set of tests
 * cases to more extensively test the AQueue class implementation.
 */
/*
TEST_CASE("AQueue<string> test string queue concrete array implementation", "[task3]")
{
  SECTION("test empty queue is empty")
  {
    // empty queues should be empty
    AQueue<string> empty;
    CHECK(empty.getSize() == 0);
    CHECK(empty.getAllocationSize() == 0); // only for AQueue
    CHECK(empty.isEmpty());
    CHECK(empty.str() == "<queue> size: 0 front:[ ]:back");

    // empty queues should compare as being equal
    AQueue<string> otherEmpty;
    CHECK(otherEmpty == empty);
    CHECK(empty == otherEmpty);

    // empty queues should complain if asked to get a value from them
    CHECK_THROWS_AS(empty.front(), QueueEmptyException);
    CHECK_THROWS_AS(empty[0], QueueMemoryBoundsException);

    // empty queue can be cleared and is still empty
    empty.clear();
    CHECK(empty.getSize() == 0);
    CHECK(empty.getAllocationSize() == 0); // only for AQueue<>
    CHECK(empty.isEmpty());
    CHECK(empty.str() == "<queue> size: 0 front:[ ]:back");
  }

  SECTION("test enqueue, dequeue and front general functionality")
  {
    // start with empty queue
    AQueue<string> queue;
    CHECK(queue.getSize() == 0);
    CHECK(queue.getAllocationSize() == 0); // only for AQueue
    CHECK(queue.isEmpty());
    CHECK(queue.str() == "<queue> size: 0 front:[ ]:back");

    // enqueue an item on empty queue
    queue.enqueue("echo");
    CHECK(queue.getSize() == 1);
    CHECK(queue.getAllocationSize() == 10); // only for AQueue
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.front() == "echo");
    CHECK(queue.str() == "<queue> size: 1 front:[ echo ]:back");

    // enqueue a second  item on queue
    queue.enqueue("hotel");
    CHECK(queue.getSize() == 2);
    CHECK(queue.getAllocationSize() == 10); // only for AQueue
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.front() == "echo");
    CHECK(queue.str() == "<queue> size: 2 front:[ echo, hotel ]:back");

    // enqueue a third item on queue
    queue.enqueue("oscar");
    CHECK(queue.getSize() == 3);
    CHECK(queue.getAllocationSize() == 10); // only for AQueue
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.front() == "echo");
    CHECK(queue.str() == "<queue> size: 3 front:[ echo, hotel, oscar ]:back");

    // test dequeue of queue with more than 1 item
    queue.dequeue();
    CHECK(queue.getSize() == 2);
    CHECK(queue.getAllocationSize() == 10); // only for AQueue
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.front() == "hotel");
    CHECK(queue.str() == "<queue> size: 2 front:[ hotel, oscar ]:back");

    // enqueue 2 itmes on
    queue.enqueue("alpha");
    CHECK(queue.front() == "hotel");
    queue.enqueue("charlie");
    CHECK(queue.getSize() == 4);
    CHECK(queue.getAllocationSize() == 10); // only for AQueue
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.front() == "hotel");
    CHECK(queue.str() == "<queue> size: 4 front:[ hotel, oscar, alpha, charlie ]:back");

    // dequeue back to 1 item
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    CHECK(queue.getSize() == 1);
    CHECK(queue.getAllocationSize() == 10); // only for AQueue
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.front() == "charlie");
    CHECK(queue.str() == "<queue> size: 1 front:[ charlie ]:back");

    // make queue empty again
    queue.dequeue();
    CHECK(queue.getSize() == 0);
    CHECK(queue.getAllocationSize() == 10); // only for AQueue
    CHECK(queue.isEmpty());
    CHECK(queue.str() == "<queue> size: 0 front:[ ]:back");

    // should complain if we try and dequeue an empty queue
    CHECK_THROWS_AS(queue.dequeue(), QueueEmptyException);

    // enqueue on 10 items
    for (int index = 1; index <= 10; index++)
    {
      queue.enqueue("string-" + to_string(int(pow(index, 3))));
    }
    CHECK(queue.getSize() == 10);
    CHECK(queue.getAllocationSize() == 10); // only for AQueue
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.str() == "<queue> size: 10 front:[ string-1, string-8, string-27, string-64, string-125, string-216, string-343, "
                         "string-512, string-729, string-1000 ]:back");

    // Array based queue should double in size, only for AQueue tests
    queue.enqueue("string-" + to_string(int(pow(11, 3))));
    CHECK(queue.getSize() == 11);
    CHECK(queue.getAllocationSize() == 20); // only for AQueue
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.str() == "<queue> size: 11 front:[ string-1, string-8, string-27, string-64, string-125, string-216, string-343, string-512,
   string-729, string-1000, string-1331 ]:back");
  }

  SECTION("test clear of queue")
  {
    // create queue of 11 values
    AQueue<string> queue;
    for (int index = 1; index <= 11; index++)
    {
      queue.enqueue("string-" + to_string(int(pow(index, 3))));
    }
    CHECK(queue.getSize() == 11);
    CHECK(queue.getAllocationSize() == 20); // only for AQueue
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.str() == "<queue> size: 11 front:[ string-1, string-8, string-27, string-64, string-125, string-216, string-343, "
                         "string-512, string-729, string-1000, string-1331 ]:back");

    // clear the queue
    queue.clear();
    CHECK(queue.getSize() == 0);
    CHECK(queue.getAllocationSize() == 0); // only for AQueue
    CHECK(queue.isEmpty());
    CHECK(queue.str() == "<queue> size: 0 front:[ ]:back");

    // should be equal to an empty queue
    AQueue<string> empty;
    CHECK(empty == queue);
    CHECK(queue == empty);
  }

  SECTION("test array based constructor")
  {
    string values[] = {"alpha", "charlie", "neg-bravo", "neg-delta", "golf"};
    AQueue<string> queue(5, values);

    // nonempty queue should not be empty
    CHECK(queue.getSize() == 5);
    CHECK(queue.getAllocationSize() == 5); // only for AQueue<>
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.str() == "<queue> size: 5 front:[ alpha, charlie, neg-bravo, neg-delta, golf ]:back");

    // test access to front and back
    CHECK(queue.front() == "alpha");

    // test indexing access
    CHECK(queue[0] == "alpha");
    CHECK(queue[1] == "charlie");
    CHECK(queue[2] == "neg-bravo");
    CHECK(queue[3] == "neg-delta");
    CHECK(queue[4] == "golf");
    CHECK_THROWS_AS(queue[-1], QueueMemoryBoundsException);
    CHECK_THROWS_AS(queue[5], QueueMemoryBoundsException);
    queue[2] = "life-universe-everything";
    CHECK(queue[2] == "life-universe-everything");
    CHECK(queue.str() == "<queue> size: 5 front:[ alpha, charlie, life-universe-everything, neg-delta, golf ]:back");

    // test inserting on queue, and that queue allocation grows as expected
    queue.enqueue("victor");
    CHECK(queue.getSize() == 6);
    CHECK(queue.getAllocationSize() == 10); // only for AQueue<>
    CHECK(queue.front() == "alpha");
    CHECK(queue.str() == "<queue> size: 6 front:[ alpha, charlie, life-universe-everything, neg-delta, golf, victor ]:back");

    queue.enqueue("zulu");
    CHECK(queue.getSize() == 7);
    CHECK(queue.getAllocationSize() == 10); // only for AQueue<>
    CHECK(queue.front() == "alpha");
    CHECK(queue.str() == "<queue> size: 7 front:[ alpha, charlie, life-universe-everything, neg-delta, golf, victor, zulu ]:back");
  }

  SECTION("test copy constructor")
  {
    string values[] = {"charlie", "alpha", "delta", "bravo"};
    AQueue<string> queue(4, values);
    AQueue<string> copy = queue;

    // copy should be equal to the queue
    CHECK(copy == queue);
    CHECK(queue == copy);

    // copy is no longer equal
    queue.enqueue("echo");
    CHECK_FALSE(copy == queue);
    CHECK_FALSE(queue == copy);

    // now they are the same again
    copy.enqueue("echo");
    CHECK(copy == queue);
    CHECK(queue == copy);

    // now they are no longer equal, copy is 2 shorter
    copy.dequeue();
    copy.dequeue();
    CHECK_FALSE(copy == queue);
    CHECK_FALSE(queue == copy);
  }
}
*/
