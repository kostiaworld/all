#include <iostream>
#include <cstdlib> // For exit()
using namespace std;


struct FunctionCallInfo {
    int returnAddress; 
    int localVar1;     
    int localVar2;     

};


class Node {
public:
    FunctionCallInfo callInfo; 
    Node* link;

    
    Node(FunctionCallInfo info) {
        this->callInfo = info;
        this->link = nullptr;
    }
};


class Stack {
    Node* top; 

public:
   
    Stack() { top = nullptr; }

 
    void push(FunctionCallInfo info) {
        Node* temp = new Node(info); 

        if (!temp) {
            cout << "\nStack Overflow";
            exit(1);
        }

        temp->link = top; 
        top = temp;       
    }


    bool isEmpty() {
        return top == nullptr;
    }

    
    FunctionCallInfo peek() {
        if (!isEmpty())
            return top->callInfo;
        else {
            cout << "\nStack Underflow";
            exit(1);
        }
    }


    void pop() {
        if (top == nullptr) {
            cout << "\nStack Underflow" << endl;
            exit(1);
        }
        else {
            Node* temp = top;
            top = top->link; 
            delete temp;     
        }
    }
};

void functionA(Stack& callStack) {
    cout << "Inside function A" << endl;

   
    FunctionCallInfo info;
    info.returnAddress = 2; 
    info.localVar1 = 100;
    info.localVar2 = 200;


    callStack.push(info);
}

void functionB(Stack& callStack) {
    cout << "Inside function B" << endl;


    FunctionCallInfo info;
    info.returnAddress = 4;
    info.localVar1 = 300;
    info.localVar2 = 400;
    

    callStack.push(info);
}


int main() {
    Stack callStack; 


    functionA(callStack);
    functionB(callStack);


    FunctionCallInfo returnInfo;


    returnInfo = callStack.peek(); 
    cout << "Returning from function B" << endl;
    cout << "Local variables in B: " << returnInfo.localVar1 << ", " << returnInfo.localVar2 << endl;
    callStack.pop(); 


    returnInfo = callStack.peek();
    cout << "Returning from function A" << endl;
    cout << "Local variables in A: " << returnInfo.localVar1 << ", " << returnInfo.localVar2 << endl;
    callStack.pop(); 

    return 0;
}
