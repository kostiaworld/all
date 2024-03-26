#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <thread>

#include <mutex>

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

public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void enQueue(string element) {
        Node *newNode = new Node(element);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        lock_guard<mutex> guard(mtx);
        cout << "задача добавлена в очередь " << element << endl;
    }

    string deQueue() {
        if (isEmpty()) {
            cout << "пусто" << endl;
            return "";
        }
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

    void processEvents() {
        while (true) {
            if (!isEmpty()) {
                string element;
                {
                    lock_guard<mutex> guard(mtx);
                    element = deQueue();
                }
                cout << "выполняется: " << element << endl;
                // Simulate processing time
                this_thread::sleep_for(chrono::seconds(5));
                cout << "завершил выполнение: " << element << endl;
            } else {
                // Sleep if the queue is empty
                this_thread::sleep_for(chrono::milliseconds(100));
            }
        }
    };
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

int main() {
    vector<string> ipAddressArray;
    Queue q;

    fillIPAddresses(ipAddressArray);


    thread eventProcessorThread(&Queue::processEvents, &q);


    for (int i = 0; i < 10; ++i) {
        string event = "Event_" + to_string(i);
        q.enQueue(event);
        this_thread::sleep_for(chrono::seconds(1));
    }

    eventProcessorThread.join();

    return 0;
}
