#include <iostream>
#include <string>
#include <random>

using namespace std;

void password_generator() {
    // character set (letters, digits, symbols)
    string characters = "abcdefghijklmnopqrstuvwxyz"
                        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                        "0123456789"
                        "!@#$%^&*()";

    int length, count;
    cout << "Enter your desired password length: ";
    cin >> length;
    cout << "How many passwords do you want to generate: ";
    cin >> count;

    // random device and generator (better than rand())
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> dist(0, characters.size() - 1);

    // generate passwords
    for (int i = 0; i < count; i++) {
        string password = "";
        for (int j = 0; j < length; j++) {
            password += characters[dist(generator)];
        }
        cout << "Password " << i + 1 << ": " << password << endl;
    }
}

int main() {
    password_generator();
    return 0;
}
