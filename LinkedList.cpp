//Mohammad Jawad
//10/21/2025
//for linked list implementation
#include "LinkedList.hpp"

/**
 * @brief Constructs a Node with a given value.
 */
template <class T>
Node<T>::Node(const T& val, Node* next)
    : value_(val)
    , next_(next)
{
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs)
    : size_ { 0 }
{
    // Perform the deep copy from the other list
    for (Node<T>* current = rhs.head_; current != nullptr; current = current->next_) {
        push_back(current->value_);
    }
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
{
    // 1. Check for self-assignment
    if (this == &other) {
        return *this;
    }

    // 2. Clear the current list's contents to prevent memory leaks
    clear();

    // 3. Perform the deep copy from the other list
    for (Node<T>* current = other.head_; current != nullptr; current = current->next_) {
        push_back(current->value_);
    }

    // 4. Return a reference to the current object to allow for chained assignments
    return *this;
}

/**
 * @brief Stringifies the underlying LinkedList
 * @return A string of the form "{'<node_content_1>', ...}" representing the LinkedList's contents
 */
template <class T>
std::string LinkedList<T>::toString() const
{
    std::stringstream ss;
    ss << "size: " << size() << " - ";
    ss << "{ ";

    Node<T>* p = head_;
    for (size_t i = 0; i < size(); i++) {
        ss << p->value_;

        if (i + 1 != size()) {
            ss << ", ";
        }
        p = p->next_;
    }

    ss << " }";
    return ss.str();
}

// YOUR CODE BELOW. DO NOT MODIFY ABOVE.
/**
* @brief Returns the number of elements in the list.
* @return The number of elements (size_t).
*/
template <class T>
size_t LinkedList<T>::size() const
{
    return size_;
}

/**
 * @brief Checks if the list is empty (ie. contains no elements).
 * @return true if the list is empty, false otherwise.
 */

template <class T>
bool LinkedList<T>::empty() const
{
    return size_ == 0;
}
/**
 * @brief Access the node pointing to the head of the linked list
 * @return A pointer to the head node (or nullptr if the list is empty)
 */
template <class T>
Node<T>* LinkedList<T>::head(){
    return head_;
}
/**
 * @brief Access the first element.
 * @return The first element's value (of type T, NOT the node).
 * @throws std::runtime_error if the list is empty.
 */
template <class T>
T LinkedList<T>::front(){
    if (empty())
    {
        throw std::runtime_error("front() called on an empty linked list.");
    }
    return head_->value_;
}
/**
* @brief Access the last element.
* @return The last element's value (of type T, , NOT the node).
* @throws std::runtime_error if the list is empty.
*/
template <class T>
T LinkedList<T>::back()
{
    if (empty()) 
    {
        throw std::runtime_error("List is empty");
    }
    Node<T>* current = head_;
    while (current -> next_ != nullptr)
    {
        current = current -> next_; //traversing to the back by while loop
    }
    return current -> value_;
}
    /**
     * @brief Access an element at a specific index.
     * @param index The zero-based index of the element (size_t).
     * @return The element's value at the given index (of type T).
     *
     * @throws std::out_of_range if the index is invalid (eg. too large).
     */
template <class T>
T LinkedList<T>::at(size_t index) const
{
    if (index >= size_)
    {
        throw std::out_of_range("Index exceeds range of linked list");
    }
    Node<T>* current = head_;
    for (size_t i = 0; i < index; i++)
    {
        current = current -> next_;
    }
    return current -> value_;
}
/**
     * @brief Adds an element to the end of the list.
     * @param value A const reference to the value (of type T)
     * to add to the end of the list
     */
template<class T>
void LinkedList<T>::push_back(const T& value)
{
    Node<T>* newNode = new Node<T>(value);
    if(empty())
    {
        head_ = newNode;
    }
    else
    {
        Node<T>* current = head_;
        while (current -> next_ != nullptr)
        {
            current = current -> next_;
        }
        current -> next = newNode;
    }
    size_++;

}
    /**
     * @brief Inserts an element at a specific index.
     * @param index The zero-based index to insert at (as a size_t).
     * @param value A const reference to the value (of type T) to insert.
     *
     * @throws std::out_of_range if the index is strictly greater than the size
     * @note That is, if we insert at index 1 when we have a list of length 1,
     *    that's fine! We just insert at the end. Inserting at index 2 would raise
     *    an error though.
     */
template<class T>
void LinkedList<T>::insert(size_t index, const T& value)
{
    if (index > size_)
    {
        throw std::out_of_range("Index exceeds range of linked list");
    }
    Node<T>* newNode = new Node<T>(value);
    if (index == 0)
    {
        newNode -> next_ = head_;
        head_ = newNode;
        if (size_ == 0) //if this is the only node added
        {
            tail_ = newNode;
        }
    }
    else
    {
        Node<T>* current = head_;
        for (size_t i = 0; i < index - 1; i++)
        {
            current = current -> next_;
        }
        current -> next = newNode;
    }
    size_++;
    

}
    /**
     * @brief Erases an element at a specific index.
     * @param index The zero-based index of the element to erase (as asize_t).
     *
     * @throws std::out_of_range if index is greater than or equal to the size
     */
template <class T>
void LinkedList<T>::erase(size_t index)
{
    if (index >= size_)
    {
        throw std::out_of_range("Index exceeds range of linked list");
    }
    Node<T>* deletePtr = nullptr;
    if (index == 0)
    {
        deletePtr = head_;
        head_ = head_ -> next_;

    }
    else{
        Node<T>* predecessor = head_;
        for (size_t i = 0; i < index - 1; i++)
        {
            predecessor = predecessor -> next_;
        }
        deletePtr = predecessor -> next_;
        predecessor -> next_ = deletePtr -> next_;

    }

    delete deletePtr;
    deletePtr = nullptr;
    --size_;
}
    /**
     * @brief Erases an element at a specific index.
     * @param index The zero-based index of the element to erase (as asize_t).
     *
     * @throws std::out_of_range if index is greater than or equal to the size
     */
template <class T>
void LinkedList<T>::clear()
{
    while(!empty())
    {
        erase(0);
    }
}
    /**
     * @brief Destructor: cleans up all nodes to prevent memory leaks.
     */
template <class T>
LinkedList<T>::~LinkedList()
{
    clear();
}