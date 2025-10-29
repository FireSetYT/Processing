#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cctype>
#include <windows.h>

using namespace std;


bool getBoolValue() {
    string input;
    while (true) {
        cout << "Введіть булеве значення (0 або 1): ";
        getline(cin, input);

        if (input.empty()) {
            cout << "Помилка: порожнє значення!\n";
            continue;
        }

        if (input == "0") return false;
        else if (input == "1") return true;
        else cout << "Помилка: введіть лише 0 або 1!\n";
    }
}


char getCharValue() {
    string input;
    while (true) {
        cout << "Введіть символ (a-f): ";
        getline(cin, input);

        if (input.empty()) {
            cout << "Помилка: порожнє значення!\n";
            continue;
        }

        if (input.size() == 1 && input[0] >= 'a' && input[0] <= 'f')
            return input[0];
        else
            cout << "Помилка: потрібно ввести один символ у діапазоні a-f!\n";
    }
}


float getFloatValue() {
    string input;
    float value;
    while (true) {
        cout << "Введіть дробове число: ";
        getline(cin, input);

        if (input.empty()) {
            cout << "Помилка: порожнє значення!\n";
            continue;
        }

        istringstream iss(input);
        if (iss >> value && iss.eof())
            return value;
        else
            cout << "Помилка: введіть коректне дробове число (використовуйте крапку для відокремлення дробової частини)!\n";
    }
}


short getShortValue() {
    string input;
    int temp;
    while (true) {
        cout << "Введіть ціле число (-32768 до 32767): ";
        getline(cin, input);

        if (input.empty()) {
            cout << "Помилка: порожнє значення!\n";
            continue;
        }

        istringstream iss(input);
        if (iss >> temp && iss.eof() && temp >= -32768 && temp <= 32767)
            return static_cast<short>(temp);
        else
            cout << "Помилка: введіть ціле число в межах типу short!\n";
    }
}


int main() {

    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "uk_UA.UTF-8");

    bool boolValue = getBoolValue();
    cout << "Булеве значення: " << (boolValue ? "true" : "false") << "\n";

    char charValue = getCharValue();
    cout << "Символ: " << charValue << "\n";

    float floatValue = getFloatValue();
    cout << "Дробове число: " << floatValue << "\n";

    short shortValue = getShortValue();
    cout << "Ціле число: " << shortValue << "\n";
    return 0;
}
