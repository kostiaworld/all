#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Базовый класс представляющий инструмент безопасности
class SecurityTool {
protected:
    string name;

public:
    SecurityTool(string n) : name(n) {}

    void Use() {
        cout << "Using " << name << endl;
    }
};

// Класс представляющий антивирус, наследуемый от SecurityTool
class Antivirus : public SecurityTool {
private:
    string version;

public:
    Antivirus(string n, string v) : SecurityTool(n), version(v) {}

    void Scan() {
        cout << "Scanning for viruses" << endl;
    }

    void ShowVersion() {
        cout << "Antivirus version: " << version << endl;
    }
};

// Класс представляющий брандмауэр, также наследуемый от SecurityTool
class Firewall : public SecurityTool {
private:
    vector<int> ports;

public:
    Firewall(string n, vector<int> p) : SecurityTool(n), ports(p) {}

    void BlockPort(int port) {
        cout << "Blocking port " << port << endl;
    }

    void ShowPorts() {
        cout << "Blocked ports: ";
        for (int port : ports) {
            cout << port << " ";
        }
        cout << endl;
    }
};

int main() {
    // Создание объекта класса Antivirus
    Antivirus av("Antivirus", "v1.0");

    // Использование методов из класса SecurityTool
    av.Use();

    // Использование специфического метода из класса Antivirus
    av.Scan();

    // Вывод версии антивируса
    av.ShowVersion();

    // Создание объекта класса Firewall
    vector<int> ports = {80, 443};
    Firewall fw("Firewall", ports);

    // Использование методов из класса SecurityTool
    fw.Use();

    // Использование специфического метода из класса Firewall
    fw.BlockPort(8080);

    // Вывод заблокированных портов
    fw.ShowPorts();

    return 0;
}
