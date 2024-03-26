#include <iostream>
#include <cstdlib>
using namespace std;


struct Operation {
    char action;
    int value;
};


class Node {
public:
    Operation operation;
    Node* link;


    Node(Operation op) {
        this->operation = op;
        this->link = nullptr;
    }
};


class Stack {
    Node* top;

public:

    Stack() { top = NULL; }


    void push(Operation op) {
        Node* temp = new Node(op);


        if (!temp) {
            cout << "\nStack Overflow";
            exit(1);
        }

        temp->link = top;
        top = temp;
    }


    bool isEmpty() {
        return top == NULL;
    }


    Operation pop() {
        if (isEmpty()) {
            cout << "\nStack Underflow" << endl;
            exit(1);
        }
        else {
            Node* temp = top;
            Operation op = top->operation;
            top = top->link;
            delete temp;
            return op;
        }
    }


    void display() {
        if (isEmpty()) {
            cout << "\nStack Underflow";
            exit(1);
        }
        else {
            Node* temp = top;
            while (temp != NULL) {
                cout << "(" << temp->operation.action << ", " << temp->operation.value << ")";
                temp = temp->link;
                if (temp != NULL)
                    cout << " -> ";
            }
        }
    }
};


int main() {
    Stack undoStack;
    Stack redoStack;


    Operation op1 = {'A', 10};
    undoStack.push(op1);
    Operation op2 = {'A', 20};
    undoStack.push(op2);
    Operation op3 = {'A', 30};
    undoStack.push(op3);
    Operation op4 = {'A', 40};
    undoStack.push(op4);
    Operation op5 = {'A', 50};
    undoStack.push(op5);
    Operation op6 = {'A', 60};
    undoStack.push(op6);


    cout << "наши действия" << endl;
    undoStack.display();


    cout << "\nвозврашяемся на два хода назад." << endl;
    Operation undoneOp = undoStack.pop();
    redoStack.push(undoneOp);
    Operation undone1p = undoStack.pop();
    redoStack.push(undone1p);

    cout << "после возвращения" << endl;
    undoStack.display();
    cout << endl;


    cout << "откатываемся." << endl;
    Operation redoneOp = redoStack.pop();
    undoStack.push(redoneOp);

    cout << "после возврата" << endl;
    undoStack.display();

    return 0;
}
