
#include <iostream>
#include <array>
#include <random>

using namespace std;

struct ll_node{
    string data;
    ll_node *next;
};

class linced_list {
private:
    ll_node *head, *tail;

public:
    linced_list() {
        head = NULL;
        tail = NULL;
    }

    void add_node(string n) {
        ll_node *tmp = new ll_node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }
    void add_to_beginning(string n)
    {
        ll_node *tmp = new ll_node;
        tmp->data = n;
        tmp->next = head;

        head = tmp;

        if (tail == NULL)
        {

            tail = tmp;
        }
    }

    void display(){
        ll_node *current = head;
        while (current != NULL)
        {
            cout << current->data << " \n";
            current = current->next;
        }
        cout << endl;
    }
    void remove_first_node()
    {
        if (head != NULL)
        {
            ll_node *tmp = head;
            head = head->next;
            delete tmp;
            if (head == NULL)
            {

                tail = NULL;
            }
        }
    }


    bool is_empty()
    {
        return (head == NULL);
    }


    void test_remove_first_node(linced_list &list)
    {
        cout << "Linked List before removing the first node: \n";
        list.display();

        if (!list.is_empty())
        {
            cout << "Removing the first node." << endl;
            list.remove_first_node();
            cout << "Linked List after removing the first node: \n";
            list.display();
        }
        else
        {
            cout << "Linked List is empty. Cannot remove the first node." << endl;
        }
    }


    void remove_nodes_with_value(string value)
    {
        ll_node *current = head;
        ll_node *prev = NULL;

        while (current != NULL)
        {
            if (current->data == value)
            {

                if (prev == NULL)
                {

                    head = current->next;
                }
                else
                {

                    prev->next = current->next;
                }


                if (current == tail)
                {
                    tail = prev;
                }


                delete current;


                current = (prev == NULL) ? head : prev->next;
            }
            else
            {

                prev = current;
                current = current->next;
            }
        }
    }

    void test_remove_nodes_with_value(linced_list &list, string value)
    {
        cout << "Linked List before removing nodes with value " << value << ": \n";
        list.display();

        cout << "Removing nodes with value " << value << "." << endl;
        list.remove_nodes_with_value(value);

        cout << "Linked List after removing nodes with value " << value << ": \n";
        list.display();
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

int main(){

    linced_list a;
    vector<string> ipAddressArray;

    fillIPAddresses(ipAddressArray);

    for (int i = 0; i < 10; i++){
        a.add_node(ipAddressArray[i]);
    };

    a.add_to_beginning("777.777.777.14");


    a.test_remove_first_node(a);
    a.add_node("777.777.777.14");
    a.add_node("777.777.777.14");
    a.add_node("777.777.777.14");
    a.add_node("777.777.777.14");
    a.add_node("777.777.777.14");


    a.test_remove_nodes_with_value(a, "777.777.777.14");
}
