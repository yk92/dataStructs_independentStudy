#ifndef S_LINKED_LIST_HPP
#define S_LINKED_LIST_HPP
#include <cstddef>
#include <iostream>

template<class ItemType>
struct Node {
    ItemType elem;
    Node<ItemType>* next;   
};


template <class ItemType>
class SLinkedList {
  public:
    SLinkedList();
    ~SLinkedList();
    bool empty() const;
    const ItemType& front() const;
    const ItemType& back() const;
    void addFront(const ItemType& item);
    void addBack(const ItemType& item);
    void removeFront();
    void print();
    
  private:
    Node<ItemType>* head;
    Node<ItemType>* tail;
};

template<class ItemType>
SLinkedList<ItemType>::SLinkedList()
: head(NULL), tail(NULL) { }

template<class ItemType>
bool SLinkedList<ItemType>::empty() const
{
    return head == NULL;
}

template <class ItemType>
const ItemType& SLinkedList<ItemType>::back() const
{
    return tail->elem;
}

template<class ItemType>
const ItemType& SLinkedList<ItemType>::front() const
{
    return head->elem;
}

template<class ItemType>
SLinkedList<ItemType>::~SLinkedList()
{
    while ( !empty() )
        removeFront();
}

template<class ItemType>
void SLinkedList<ItemType>::addFront(const ItemType& item)
{
    Node<ItemType>* temp = new Node<ItemType>;
    if (head == NULL ){
        temp->elem = item;
        temp->next = head;
        head = tail = temp;
    }
    else if ( head->next == NULL ){
        temp->elem = item;
        temp->next = head;
        tail = head;
        head = temp;
    }
    else{
        temp->elem = item;
        temp->next = head;
        head = temp;
    }
}

template<class ItemType>
void SLinkedList<ItemType>::addBack(const ItemType& item)
{
    Node<ItemType>* temp = new Node<ItemType>;
    temp->elem = item;
    temp->next = NULL;
    tail->next = temp;
    tail = temp;
}
template<class ItemType>
void SLinkedList<ItemType>::removeFront()
{
    Node<ItemType>* old = head;
    head = old->next;
    delete old;
}

template<class ItemType>
void SLinkedList<ItemType>::print()
{
    Node<ItemType>* temp = new Node<ItemType>;
    temp = head;
    
    while ( temp->next != NULL ) {
        std::cout << temp->elem << " " << std::endl;
        temp = temp->next;
    }
    
    std::cout << temp->elem << std::endl;
}



#endif
