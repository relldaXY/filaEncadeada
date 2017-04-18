//!  Copyright [2017] <Copyright relldaXY>"

#include <cstdint>
#include <stdexcept>

namespace structures {


template<typename T>
//! Class Linked queue
/*!
 *  This is a queue linked by reference. It has functions like enqueue, dequeue 
 *  that are the same used on linked list but with names like "push back" and
 *  "pop front" respectively.
*/
class LinkedQueue {
 public:
    LinkedQueue() {
        head = NULL;
        tail = NULL;
        size_ = -1;
    }

    ~LinkedQueue() {
        clear();
    }
    //! method clear.
    /*!
        clear until to empty queue.
    */
    void clear() {
        while (!empty()) {
            dequeue();
        }
        size_ = -1;
    }
    //! method enqueue.
    /*!
        insert into queue by back.
    */
    void enqueue(const T& data) {
        Node* newNode =  new Node(data, NULL);
        if (empty()) {
            size_ = 0;
            head = newNode;
            tail = head;
        } else {
            tail = head;
            for (int i = 1; i <= size_; i++) {
                tail = tail->next();
            }
            tail->next(newNode);
            tail = newNode;
            size_++;
        }
    }
    //! method dequeue.
    /*!
        pop data from back of queue.
    */
    T dequeue() {
        if (empty()) {
            throw std::out_of_range("Empty List");
        } else {
            Node* quitNode;
            T data;
            data = head->data();
            quitNode = head;
            head = quitNode->next();
            delete quitNode;
            size_--;
            return data;
        }
    }
    //! method front.
    /*!
        return data from head of queue.
    */
    T& front() const {
        if (empty()) {
            throw std::out_of_range("Empty list");
        }
        return head->data();
    }
    //! method back.
    /*!
        return data from back of queue.
    */
    T& back() const {
        if (empty()) {
            throw std::out_of_range("Empty list");
        }
        return tail->data();
    }
    //! method empty.
    /*!
        vrrify if queue is empty.
    */
    bool empty() const {
        return size_ == -1;
    }
    //! method size.
    /*!
        to know the size of queue.
    */
    std::size_t size() const {
        return (size_+1);
    }

 private:
    class Node {  // Elemento
     public:
        explicit Node(const T& data):
            data_{data}
        {}

        Node(const T& data, Node* next):
            data_{data},
            next_{next}
        {}

        T& data() {  // getter: dado
            return data_;
        }

        const T& data() const {  // getter const: dado
            return data_;
        }

        Node* next() {  // getter: próximo
            return next_;
        }

        const Node* next() const {  // getter const: próximo
            return next_;
        }

        void next(Node* node) {   // setter: próximo
            next_ = node;
        }

     private:
        T data_;
        Node* next_{nullptr};
    };
    Node* head;  // nodo-cabeça
    Node* tail;   // nodo-fim
    std::size_t size_;  // tamanho
};

}  // namespace structures


