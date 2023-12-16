#ifndef _QUEUE_CLASS_H_
#define _QUEUE_CLASS_H_
#pragma GCC system_header

#include <iostream>
using namespace std;

class nullptr_exception : public std::exception {
    private:

        string errorMessage;

    public:

        nullptr_exception(const char* message) : errorMessage(message) {}

        const char* what() const noexcept override {
            return errorMessage.c_str();
        }

};

template <typename T>

class Queue {

    private:

        struct Node {

            T data;
            Node* next;
            Node(const T& d) : data(d), next(nullptr) {}
            
        };

        int size_queue {
            this -> size_queue = 0
        };

        Node* front {
            this -> front = nullptr
        };

        Node* back {
            this -> back = nullptr
        };

    public:

        Queue() {}

        Queue(const Queue& other) : front(nullptr), back(nullptr) {
            Node* temp = other.front;
            while (temp != nullptr) {
                add(temp -> data);
                temp = temp -> next;
                delete temp;
            }
        }

        bool Empty() const {
            return front == nullptr;
        }
        

        void Add(const T& data) {
            Node* newNode = new Node(data);
            if (Empty()) {
                front = newNode;
                back = newNode;
            } 
            else {
                back -> next = newNode;
                back = newNode;
            }
            size_queue += 1;
            return ;
        }


        void Pop() {
            if (Empty()) {
                return ;
            }
            Node* temp = front;
            front = front -> next;
            delete temp;
            if (front == nullptr) {
                back = nullptr;
            }
            size_queue -= 1;
            return ;
        }

        T Size() {
            return this -> size_queue;
        }
        
        virtual ~Queue() {
            while (Empty() != 1) {
                Pop();
            }
        }

        T Front() const {
            if (Empty()) {
                throw nullptr_exception("Front element has nothing in there.");

            }
            return front -> data;
        }

        T Back() const {
            if (Empty()) {
                throw nullptr_exception("Back element has nothing in there.");
            }
            return back -> data;
        }

};
#endif
