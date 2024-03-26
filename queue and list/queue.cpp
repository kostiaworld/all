#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>


#include "queue.h"

bool Queue::isEmpty() {
        return front == nullptr;
    }


void Queue::enQueue(int i, const string& d) {
    Node* newNode = new Node(i, d);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        std::cout << "Поступила задача: " << d << std::endl;
    }

string Queue::deQueue() {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return 0;
        }
        int id = front->id;
        string element = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr;
        }
        std::cout << "Выполнена задача " << id << "  содержание: " << element <<  std::endl;
        return element;
    }
void Queue::display() {
    if (isEmpty()) {
        cout << "Empty Queue" << endl;
        return;
    }
    Node* current = front;
    cout << "Front -> \n";
    while (current != nullptr) {
        cout << current->id << "\t";
        cout << current->data << "\t\n";
        current = current->next;
    }
    cout << " <- Rear" << endl;
}

