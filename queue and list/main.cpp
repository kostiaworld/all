


#include <iostream>

#include <thread>
#include "linced_list.h"
#include "queue.h"
#include <array>
#include <random>

using namespace std;

void fillIPAddresses(std::vector<std::string>& ipAddresses) {
    // Генератор случайных чисел для генерации номеров IP
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, 255);

    for (int i = 0; i < 10; ++i) {
        std::string ip;
        // Генерируем каждый из четырех октетов IP-адреса
        for (int j = 0; j < 4; ++j) {
            if (!ip.empty()) {
                ip += ".";
            }
            ip += std::to_string(distribution(gen));
        }
        ipAddresses.push_back(ip);
    }
}

int main() {
    linced_list a;
    a.add_node("15.215.105.75");
    a.add_node("241.110.111.14");
    a.add_node("212.119.128.0");
    a.add_node("8.147.179.197");
    a.add_node("164.127.195.136");
    a.add_node("175.110.87.33");
    a.add_node("175.110.87.33");
    a.add_node("175.110.87.33");
    a.add_node("175.110.87.33");
    a.add_node("175.110.87.33");

    a.add_to_beginning("777.777.777.14");

    a.display();
    a.test_remove_first_node(a);

    a.display();

    a.test_remove_nodes_with_value(a, "175.110.87.33");


    Queue q;
    vector<string> ipAddressArray;

    fillIPAddresses(ipAddressArray);

    for (int i = 0; i < 10; i++){
        q.enQueue(i+1, ipAddressArray[i]);
    };
    //q.display();


    for (int i = 0; i < 11; i++){
        q.deQueue();

    };
    q.display();


    for (int i = 0; i < 10; i++){
        q.enQueue(i+1, ipAddressArray[i]);
    };


    std::cout << "Buffered Data:" << std::endl;
    q.display();

    // Process the buffered data by dequeueing and displaying each element
    std::cout << "Processing Buffered Data:" << std::endl;
    while (!q.isEmpty()) {
        std::string processedData = q.deQueue();
        // Here you can perform processing on the data, such as printing or further manipulation
        std::cout << "Processed: " << processedData << std::endl;
    }
    return 0;
}

