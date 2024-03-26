#include <iostream>
#include <cstdlib> // For exit()
using namespace std;

// Structure to hold function call information
struct FunctionCallInfo {
    int returnAddress; // Address to return to after the function call
    int localVar1;     // Example local variable 1
    int localVar2;     // Example local variable 2
    // Add more local variables as needed
};

// Node class for linked list
class Node {
public:
    FunctionCallInfo callInfo; // Function call information
    Node* link;

    // Constructor
    Node(FunctionCallInfo info) {
        this->callInfo = info;
        this->link = nullptr;
    }
};

// Stack class
class Stack {
    Node* top; // Pointer to the top of the stack

public:
    // Constructor to initialize top as NULL
    Stack() { top = nullptr; }

    // Push operation to add a function call information to the top of the stack
    void push(FunctionCallInfo info) {
        Node* temp = new Node(info); // Create a new node

        // Check for memory allocation failure
        if (!temp) {
            cout << "\nStack Overflow";
            exit(1);
        }

        temp->link = top; // Link new node to the top
        top = temp;       // Update top to point to the new node
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Function to return the function call information at the top of the stack
    FunctionCallInfo peek() {
        if (!isEmpty())
            return top->callInfo;
        else {
            cout << "\nStack Underflow";
            exit(1);
        }
    }

    // Function to remove the top function call information from the stack
    void pop() {
        if (top == nullptr) {
            cout << "\nStack Underflow" << endl;
            exit(1);
        }
        else {
            Node* temp = top;
            top = top->link; // Update top to point to the next node
            delete temp;     // Delete the node
        }
    }
};

// Function to demonstrate function calls and returns
void functionA(Stack& callStack) {
    cout << "Inside function A" << endl;

    // Storing function call information
    FunctionCallInfo info;
    info.returnAddress = 2; // Address to return to after function A completes
    info.localVar1 = 100;
    info.localVar2 = 200;
    // Add more local variables or data as needed

    callStack.push(info);
}

void functionB(Stack& callStack) {
    cout << "Inside function B" << endl;

    // Storing function call information
    FunctionCallInfo info;
    info.returnAddress = 4; // Address to return to after function B completes
    info.localVar1 = 300;
    info.localVar2 = 400;
    // Add more local variables or data as needed

    callStack.push(info);
}

// Main function
int main() {
    Stack callStack; // Creating a stack to manage function calls

    // Function calls
    functionA(callStack);
    functionB(callStack);

    // Function returns
    FunctionCallInfo returnInfo;

    // Returning from function B
    returnInfo = callStack.peek(); // Get function call information from the top of the stack
    cout << "Returning from function B" << endl;
    cout << "Local variables in B: " << returnInfo.localVar1 << ", " << returnInfo.localVar2 << endl;
    callStack.pop(); // Remove function call information from the stack

    // Returning from function A
    returnInfo = callStack.peek(); // Get function call information from the top of the stack
    cout << "Returning from function A" << endl;
    cout << "Local variables in A: " << returnInfo.localVar1 << ", " << returnInfo.localVar2 << endl;
    callStack.pop(); // Remove function call information from the stack

    return 0;
}
