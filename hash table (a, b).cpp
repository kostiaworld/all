#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct NodeH {
    string Key;
    string Value;
};

class HashTable {
private:
    vector<NodeH*> Table;
    int Capacity;

    int hashFunc(int a, const string& key) {
        int sum1 = 0;
        int sum2 = 0;
        for (char c : key) {
            sum1 += static_cast<int>(c);
        }

        for (char c : key) {
            sum2 += (static_cast<int>(c) % 2);
        }

        int ans = (sum1 + a * sum2) % Capacity;
        return ans;
    }

public:
    HashTable(int capacity) : Capacity(capacity) {
        Table.resize(Capacity, nullptr);
    }

    void Add(const string& key, const string& value) {
        int index = hashFunc(1, key);
        if (Table[index] != nullptr && Table[index]->Key == key) {
            // Update value if key already exists
            Table[index]->Value = value;
            return;
        }
        NodeH *node = new NodeH{key, value};
        if (Table[index] == nullptr) {
            Table[index] = node;
        } else {
            for (int i = 2; i < 32; ++i) {
                index = hashFunc(i, key);
                if (Table[index] == nullptr || Table[index]->Key == key) {
                    Table[index] = node;
                    break;
                }
            }
        }
    }

    pair<string, bool> Get(const string& key) {
        int index = hashFunc(1, key);
        if (Table[index] != nullptr && Table[index]->Key == key) {
            return {Table[index]->Value, true};
        }
        return {"", false};
    }
    void printTable()
    {
        for (int i = 0; i < 512; i++)
        {
            if (Table[i] != NULL)
            {
                cout << "name = " << Table[i]->Key
                     << "type = " << Table[i]->Value << endl;
            }
        }

    }


};

int main() {
    // Create a hash table to store blocked IP addresses
    HashTable blacklist(512);

    blacklist.Add("192.168.1.1", "Blocked");
    blacklist.Add("192.168.1.1", "444");
    blacklist.Add("192.158.8.7", "On hold");
    blacklist.Add("192.368.4.1", "Blocked");
    blacklist.Add("192.468.1.1", "On hold");
    blacklist.Add("192.598.1.9", "On hold");
    blacklist.Add("192.108.3.1", "Blocked");
    blacklist.Add("192.163.1.0", "Blocked");

    blacklist.Add("192.168.1.1", "Updated Status");
    blacklist.printTable();


    string input;
    cout << "Enter IP: ";
    cin >> input;

    // Check if the IP address is blocked
    auto result = blacklist.Get(input);
    if (result.second) {
        cout << "Status of IP address: " << result.first << endl;
    } else {
        cout << "IP address not found in the blocked list." << endl;
    }

    return 0;
}
