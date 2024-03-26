//
// Created by Константин Пахомов on 2024-03-10.
//

#ifndef UNTITLED4_LINCED_LIST_H
#define UNTITLED4_LINCED_LIST_H

#include <iostream>

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

    void add_node(string i);
    void add_to_beginning(string n);
    void display();
    void remove_first_node();
    bool is_empty();
    static void test_remove_first_node(linced_list &list);
    void remove_nodes_with_value(string value);
    void test_remove_nodes_with_value(linced_list &list, string value);


};
#endif //UNTITLED4_LINCED_LIST_H
