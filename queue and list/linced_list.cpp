//
// Created by Константин Пахомов on 2024-03-10.
//

#include "linced_list.h"

#include <iostream>

using namespace std;

void linced_list::add_node(string n) {
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
void linced_list::add_to_beginning(string n)
{
    ll_node *tmp = new ll_node;
    tmp->data = n;
    tmp->next = head;

    head = tmp;

    if (tail == NULL)
    {
        // If the list is empty, update the tail to point to the new node
        tail = tmp;
    }
}

void linced_list::display(){
    ll_node *current = head;
    while (current != NULL)
    {
        cout << current->data << " \n";
        current = current->next;
    }
    cout << endl;
}
void linced_list::remove_first_node()
{
    if (head != NULL)
    {
        ll_node *tmp = head;
        head = head->next;
        delete tmp;
        if (head == NULL)
        {
            // If the list becomes empty, update the tail to NULL
            tail = NULL;
        }
    }
}

// Function to check if the linked list is empty
bool linced_list::is_empty()
{
    return (head == NULL);
}


void linced_list::test_remove_first_node(linced_list &list)
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


void linced_list::remove_nodes_with_value(string value)
{
    ll_node *current = head;
    ll_node *prev = NULL;

    while (current != NULL)
    {
        if (current->data == value)
        {
            // Node with the specified value found, remove it
            if (prev == NULL)
            {
                // If it's the first node, update the head
                head = current->next;
            }
            else
            {
                // If it's not the first node, update the previous node's next pointer
                prev->next = current->next;
            }

            // Check if the node being removed is the tail
            if (current == tail)
            {
                tail = prev;
            }

            // Delete the node
            delete current;

            // Move to the next node
            current = (prev == NULL) ? head : prev->next;
        }
        else
        {
            // Move to the next node
            prev = current;
            current = current->next;
        }
    }
}

void linced_list::test_remove_nodes_with_value(linced_list &list, string value)
{
    cout << "Linked List before removing nodes with value " << value << ": \n";
    list.display();

    cout << "Removing nodes with value " << value << "." << endl;
    list.remove_nodes_with_value(value);

    cout << "Linked List after removing nodes with value " << value << ": \n";
    list.display();
}