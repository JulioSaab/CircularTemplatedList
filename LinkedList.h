#ifndef CIRCULARTEMPLATEDLIST_LINKEDLIST_H
#define CIRCULARTEMPLATEDLIST_LINKEDLIST_H

#include <iostream>

// Templated Node
template <typename T>
struct Node {
    T* data;
    Node<T>* next;

    Node(T* d) : data(d), next(nullptr) {}
};

// Templated Circular LinkedList
template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    Node<T>* current;

public:
    LinkedList() : head(nullptr), tail(nullptr), current(nullptr) {}

    ~LinkedList() {
        if (!head) return;

        Node<T>* temp = head;
        do {
            Node<T>* nextNode = temp->next;
            delete temp->data;
            delete temp;
            temp = nextNode;
        } while (temp != head);

        head = tail = current = nullptr;
        std::cout << "\n[Playlist cleanup complete.]" << std::endl;
    }

    void insert(T* item) {
        Node<T>* newNode = new Node<T>(item);
        if (!head) {
            head = tail = newNode;
            tail->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    void displayList() const {
        if (!head) {
            std::cout << "[Playlist is empty.]" << std::endl;
            return;
        }

        std::cout << "\n--- Current Playlist ---" << std::endl;
        Node<T>* temp = head;
        int index = 1;
        do {
            std::cout << index++ << ". " << temp->data->toString() << std::endl;
            temp = temp->next;
        } while (temp != head);
        std::cout << "------------------------" << std::endl;
    }

    void playCurrent() {
        if (head) head->data->play();
        else std::cout << "[Playlist is empty.]" << std::endl;
    }

    void playNext() {
        if (!current) current = head;
        if (current) {
            current->data->play();
            current = current->next;
        } else {
            std::cout << "[Playlist is empty.]" << std::endl;
        }
    }
};

#endif // CIRCULARTEMPLATEDLIST_LINKEDLIST_H