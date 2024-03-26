//
// Created by Константин Пахомов on 2024-03-21.
//

#ifndef UNTITLED4_QUEUE_H
#define UNTITLED4_QUEUE_H

#include <iostream>

using namespace std;

struct Node {
    int id;
    string data;
    Node* next;

    Node(int i, const string& n) : id(i), data(n), next(nullptr) {}
};

class Queue {
private:
    Node *front, *rear;

public:
    Queue() : front(nullptr), rear(nullptr) {};
    bool isEmpty();
    void enQueue(int i, const string& d);
    string deQueue();
    void display();
};



#endif //UNTITLED4_QUEUE_H
