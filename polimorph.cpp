#include <iostream>
#include <string>

using namespace std;
// Abstract base class representing NetworkSecurity
class NetworkSecurity {
public:
    virtual string CheckSecurity() = 0;
};

// Concrete class representing Firewall
class Firewall : public NetworkSecurity {
private:
    string name;

public:
    Firewall(string n) : name(n) {}

    string CheckSecurity() override {
        return "Checking security by firewall " + name;
    }
};

// Concrete class representing Antivirus
class Antivirus : public NetworkSecurity {
private:
    string name;

public:
    Antivirus(string n) : name(n) {}

    string CheckSecurity() override {
        return "Checking security by antivirus " + name;
    }
};

// Function to perform security check
void PerformSecurityCheck(NetworkSecurity* s) {
    cout << s->CheckSecurity() << endl;
}

int main() {
    Firewall firewall("Firewall1");
    Antivirus antivirus("Antivirus1");

    PerformSecurityCheck(&firewall);
    PerformSecurityCheck(&antivirus);

    return 0;
}
