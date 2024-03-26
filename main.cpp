#include <iostream>
#include <string>

// Abstract base class representing NetworkSecurity
class NetworkSecurity {
public:
    virtual std::string CheckSecurity() = 0;
};

// Concrete class representing Firewall
class Firewall : public NetworkSecurity {
private:
    std::string name;

public:
    Firewall(std::string n) : name(n) {}

    std::string CheckSecurity() override {
        return "Checking security by firewall " + name;
    }
};

// Concrete class representing Antivirus
class Antivirus : public NetworkSecurity {
private:
    std::string name;

public:
    Antivirus(std::string n) : name(n) {}

    std::string CheckSecurity() override {
        return "Checking security by antivirus " + name;
    }
};

// Function to perform security check
void PerformSecurityCheck(NetworkSecurity* s) {
    std::cout << s->CheckSecurity() << std::endl;
}

int main() {
    Firewall firewall("Firewall1");
    Antivirus antivirus("Antivirus1");

    PerformSecurityCheck(&firewall);
    PerformSecurityCheck(&antivirus);

    return 0;
}
