/** @file test-LQueue.cpp
 * @brief Unit tests for Assignment Queues
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Queues
 * @date   June 1, 2021
 *
 * Tests of the linked list based implementation of the Queue API.
 */
#include "LQueue.hpp"
#include "QueueException.hpp"
#include "catch.hpp"
#include <iostream>
using namespace std;

/** Test LQueue<int> concrete linked list implementation of queue of integers
 */
TEST_CASE("LQueue<int> test integer queue concrete linked list implementation", "[task0]")
{
  SECTION("test empty queue is empty")
  {
    // empty queues should be empty
    LQueue<int> empty;
    CHECK(empty.getSize() == 0);
    CHECK(empty.isEmpty());
    CHECK(empty.str() == "<queue> size: 0 front:[ ]:back");

    // empty queues should compare as being equal
    LQueue<int> otherEmpty;
    CHECK(otherEmpty == empty);
    CHECK(empty == otherEmpty);

    // empty queues should complain if asked to get a value from them
    CHECK_THROWS_AS(empty.front(), QueueEmptyException);
    CHECK_THROWS_AS(empty[0], QueueMemoryBoundsException);

    // empty queue can be cleared and is still empty
    empty.clear();
    CHECK(empty.getSize() == 0);
    CHECK(empty.isEmpty());
    CHECK(empty.str() == "<queue> size: 0 front:[ ]:back");
  }

  SECTION("test enqueue, dequeue and front general functionality")
  {
    // start with emtpy queue
    LQueue<int> queue;
    CHECK(queue.getSize() == 0);
    CHECK(queue.isEmpty());
    CHECK(queue.str() == "<queue> size: 0 front:[ ]:back");

    // enqueue an item on empty queue
    queue.enqueue(5);
    CHECK(queue.getSize() == 1);
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.front() == 5);
    CHECK(queue.str() == "<queue> size: 1 front:[ 5 ]:back");

    // enqueue a second  item on queue
    queue.enqueue(8);
    CHECK(queue.getSize() == 2);
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.front() == 5);
    CHECK(queue.str() == "<queue> size: 2 front:[ 5, 8 ]:back");

    // enqueue a third item on queue
    queue.enqueue(15);
    CHECK(queue.getSize() == 3);
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.front() == 5);
    CHECK(queue.str() == "<queue> size: 3 front:[ 5, 8, 15 ]:back");

    // test dequeue of queue with more than 1 item
    queue.dequeue();
    CHECK(queue.getSize() == 2);
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.front() == 8);
    CHECK(queue.str() == "<queue> size: 2 front:[ 8, 15 ]:back");

    // enqueue 2 itmes on
    queue.enqueue(1);
    CHECK(queue.front() == 8);
    queue.enqueue(3);
    CHECK(queue.getSize() == 4);
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.front() == 8);
    CHECK(queue.str() == "<queue> size: 4 front:[ 8, 15, 1, 3 ]:back");

    // dequeue back to 1 item
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    CHECK(queue.getSize() == 1);
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.front() == 3);
    CHECK(queue.str() == "<queue> size: 1 front:[ 3 ]:back");

    // make queue empty again
    queue.dequeue();
    CHECK(queue.getSize() == 0);
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
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.str() == "<queue> size: 10 front:[ 1, 8, 27, 64, 125, 216, 343, 512, 729, 1000 ]:back");

    // Array based queue should double in size, only for LQueue tests
    queue.enqueue(pow(11, 3));
    CHECK(queue.getSize() == 11);
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.str() == "<queue> size: 11 front:[ 1, 8, 27, 64, 125, 216, 343, 512, 729, 1000, 1331 ]:back");
  }

  SECTION("test clear of queue")
  {
    // create queue of 11 values
    LQueue<int> queue;
    for (int index = 1; index <= 11; index++)
    {
      queue.enqueue(pow(index, 3));
    }
    CHECK(queue.getSize() == 11);
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.str() == "<queue> size: 11 front:[ 1, 8, 27, 64, 125, 216, 343, 512, 729, 1000, 1331 ]:back");

    // clear the queue
    queue.clear();
    CHECK(queue.getSize() == 0);
    CHECK(queue.isEmpty());
    CHECK(queue.str() == "<queue> size: 0 front:[ ]:back");

    // should be equal to an empty queue
    LQueue<int> empty;
    CHECK(empty == queue);
    CHECK(queue == empty);
  }

  SECTION("test array based constructor")
  {
    int values[] = {1, 3, -2, -4, 7};
    LQueue<int> queue(5, values);

    // nonempty queue should not be empty
    CHECK(queue.getSize() == 5);
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
    CHECK(queue.front() == 1);
    CHECK(queue.str() == "<queue> size: 6 front:[ 1, 3, 42, -4, 7, 22 ]:back");

    queue.enqueue(38);
    CHECK(queue.getSize() == 7);
    CHECK(queue.front() == 1);
    CHECK(queue.str() == "<queue> size: 7 front:[ 1, 3, 42, -4, 7, 22, 38 ]:back");
  }

  SECTION("test copy constructor")
  {
    int values[] = {3, 1, 4, 2};
    LQueue<int> queue(4, values);
    LQueue<int> copy = queue;

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

/** Test LQueue<string> concrete linked list implementation of queue of strings
 */
TEST_CASE("LQueue<string> test string queue concrete linked list implementation", "[task0]")
{
  SECTION("test empty queue is empty")
  {
    // empty queues should be empty
    LQueue<string> empty;
    CHECK(empty.getSize() == 0);
    CHECK(empty.isEmpty());
    CHECK(empty.str() == "<queue> size: 0 front:[ ]:back");

    // empty queues should compare as being equal
    LQueue<string> otherEmpty;
    CHECK(otherEmpty == empty);
    CHECK(empty == otherEmpty);

    // empty queues should complain if asked to get a value from them
    CHECK_THROWS_AS(empty.front(), QueueEmptyException);
    CHECK_THROWS_AS(empty[0], QueueMemoryBoundsException);

    // empty queue can be cleared and is still empty
    empty.clear();
    CHECK(empty.getSize() == 0);
    CHECK(empty.isEmpty());
    CHECK(empty.str() == "<queue> size: 0 front:[ ]:back");
  }

  SECTION("test enqueue, dequeue and front general functionality")
  {
    // start with empty queue
    LQueue<string> queue;
    CHECK(queue.getSize() == 0);
    CHECK(queue.isEmpty());
    CHECK(queue.str() == "<queue> size: 0 front:[ ]:back");

    // enqueue an item on empty queue
    queue.enqueue("echo");
    CHECK(queue.getSize() == 1);
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.front() == "echo");
    CHECK(queue.str() == "<queue> size: 1 front:[ echo ]:back");

    // enqueue a second  item on queue
    queue.enqueue("hotel");
    CHECK(queue.getSize() == 2);
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.front() == "echo");
    CHECK(queue.str() == "<queue> size: 2 front:[ echo, hotel ]:back");

    // enqueue a third item on queue
    queue.enqueue("oscar");
    CHECK(queue.getSize() == 3);
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.front() == "echo");
    CHECK(queue.str() == "<queue> size: 3 front:[ echo, hotel, oscar ]:back");

    // test dequeue of queue with more than 1 item
    queue.dequeue();
    CHECK(queue.getSize() == 2);
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.front() == "hotel");
    CHECK(queue.str() == "<queue> size: 2 front:[ hotel, oscar ]:back");

    // enqueue 2 itmes on
    queue.enqueue("alpha");
    CHECK(queue.front() == "hotel");
    queue.enqueue("charlie");
    CHECK(queue.getSize() == 4);
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.front() == "hotel");
    CHECK(queue.str() == "<queue> size: 4 front:[ hotel, oscar, alpha, charlie ]:back");

    // dequeue back to 1 item
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    CHECK(queue.getSize() == 1);
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.front() == "charlie");
    CHECK(queue.str() == "<queue> size: 1 front:[ charlie ]:back");

    // make queue empty again
    queue.dequeue();
    CHECK(queue.getSize() == 0);
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
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.str() == "<queue> size: 10 front:[ string-1, string-8, string-27, string-64, string-125, string-216, string-343, "
                         "string-512, string-729, string-1000 ]:back");

    // Array based queue should double in size, only for LQueue tests
    queue.enqueue("string-" + to_string(int(pow(11, 3))));
    CHECK(queue.getSize() == 11);
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.str() == "<queue> size: 11 front:[ string-1, string-8, string-27, string-64, string-125, string-216, string-343, "
                         "string-512, string-729, string-1000, string-1331 ]:back");
  }

  SECTION("test clear of queue")
  {
    // create queue of 11 values
    LQueue<string> queue;
    for (int index = 1; index <= 11; index++)
    {
      queue.enqueue("string-" + to_string(int(pow(index, 3))));
    }
    CHECK(queue.getSize() == 11);
    CHECK_FALSE(queue.isEmpty());
    CHECK(queue.str() == "<queue> size: 11 front:[ string-1, string-8, string-27, string-64, string-125, string-216, string-343, "
                         "string-512, string-729, string-1000, string-1331 ]:back");

    // clear the queue
    queue.clear();
    CHECK(queue.getSize() == 0);
    CHECK(queue.isEmpty());
    CHECK(queue.str() == "<queue> size: 0 front:[ ]:back");

    // should be equal to an empty queue
    LQueue<string> empty;
    CHECK(empty == queue);
    CHECK(queue == empty);
  }

  SECTION("test array based constructor")
  {
    string values[] = {"alpha", "charlie", "neg-bravo", "neg-delta", "golf"};
    LQueue<string> queue(5, values);

    // nonempty queue should not be empty
    CHECK(queue.getSize() == 5);
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
    CHECK(queue.front() == "alpha");
    CHECK(queue.str() == "<queue> size: 6 front:[ alpha, charlie, life-universe-everything, neg-delta, golf, victor ]:back");

    queue.enqueue("zulu");
    CHECK(queue.getSize() == 7);
    CHECK(queue.front() == "alpha");
    CHECK(queue.str() == "<queue> size: 7 front:[ alpha, charlie, life-universe-everything, neg-delta, golf, victor, zulu ]:back");
  }

  SECTION("test copy constructor")
  {
    string values[] = {"charlie", "alpha", "delta", "bravo"};
    LQueue<string> queue(4, values);
    LQueue<string> copy = queue;

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
