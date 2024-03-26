#include <iostream>
#include <string>

using namespace std;

class NetworkSecurity {
public:
    virtual string CheckSecurity() = 0;
};


class Firewall : public NetworkSecurity {
private:
    string name;

public:
    Firewall(string n) : name(n) {}

    string CheckSecurity() override {
        return "Checking security by firewall " + name;
    }
};


class Antivirus : public NetworkSecurity {
private:
    string name;

public:
    Antivirus(string n) : name(n) {}

    string CheckSecurity() override {
        return "Checking security by antivirus " + name;
    }
};


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
