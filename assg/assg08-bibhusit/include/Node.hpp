/** @file Node.hpp
 * @brief Definition of the Node class used by LList linked lists.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Linked Lists
 * @date   June 1, 2021
 *
 * Definition of Node class used by LList linked list implementations
 * and supporting iteration classes.  Simplifies inclusion circular
 * references to put this structure definition in its own file.
 */
#ifndef _NODE_HPP_
#define _NODE_HPP_

/** @class Node
 * @brief A simple Node structure type to be used to hold values
 *   in our linked list implemented of the List ADT.
 */
template<class T>
struct Node
{
public:
  /// @brief the actual date value of type T this node contains.
  T value;

  /// @brief A pointer to the next node of the linked list, or
  ///    nullptr if this node is the back node or not linked
  ///    to another node.
  Node<T>* next;
};

#endif // define _NODE_HPP_
