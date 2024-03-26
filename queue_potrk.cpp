#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <thread>

#include <condition_variable>

using namespace std;

class Node {
public:
    string data;
    Node* next;

    explicit Node(string val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node *front, *rear;
    mutex mtx;
    condition_variable cv;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void enQueue(string element) {
        Node *newNode = new Node(element);
        {
            lock_guard<mutex> guard(mtx);
            if (isEmpty()) {
                front = rear = newNode;
            } else {
                rear->next = newNode;
                rear = newNode;
            }
        }
        cv.notify_one(); 
        cout << "задача добавлена в очередь --- " << element << endl;
    }

    string deQueue() {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this] { return !isEmpty(); });
        string element = front->data;
        Node *temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr;
        }
        return element;
    }

    void display() {
        if (isEmpty()) {
            cout << "пусто" << endl;
            return;
        }
        Node *current = front;
        cout << "Front -> ";
        while (current != nullptr) {
            cout << current->data << "\t\n";
            current = current->next;
        }
        cout << " <- Rear" << endl;
    }
};


void fillIPAddresses(vector<string>& ipAddresses) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(0, 255);

    for (int i = 0; i < 10; ++i) {
        string ip;
        for (int j = 0; j < 4; ++j) {
            if (!ip.empty()) {
                ip += ".";
            }
            ip += to_string(distribution(gen));
        }
        ipAddresses.push_back(ip);
    }
}

void producer(Queue& q) {
    for (int i = 0; i < 10; ++i) {
        string event = "Event_" + to_string(i);
        q.enQueue(event);
        this_thread::sleep_for(chrono::seconds(1));
    }
}

void consumer(Queue& q, int id) {
    while (true) {
        string task = q.deQueue();
        cout << "поток " << id << " задача которая выполняется ---: " << task << endl;
        // Simulate processing time
        this_thread::sleep_for(chrono::seconds(3));
    }
}

int main() {
    vector<string> ipAddressArray;
    Queue q;

    fillIPAddresses(ipAddressArray);


    vector<thread> producerThreads;
    for (int i = 0; i < 2; ++i) {
        producerThreads.emplace_back(producer, ref(q));
    }


    vector<thread> consumerThreads;
    for (int i = 0; i < 3; ++i) {
        consumerThreads.emplace_back(consumer, ref(q), i + 1);
    }


    for (auto& thread : producerThreads) {
        thread.join();
    }


    for (auto& thread : consumerThreads) {
        thread.join();
    }

    return 0;
}
