#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

bool sameFile(const string& a, const string& b) {
    error_code error;
    return filesystem::absolute(a).lexically_normal() == filesystem::absolute(b).lexically_normal()
        || filesystem::equivalent(a, b, error);
}

void showFile(const string& path) {
    ifstream f(path);
    cout << "\n" << path << ":\n";
    string s;
    while (getline(f, s)) {
        cout << s << '\n';
    }
}

int main() {
    string input, digits, letters;
    cout << "Путь к исходному файлу: ";
    getline(cin, input);
    cout << "Путь к файлу для строк из цифр: ";
    getline(cin, digits);
    cout << "Путь к файлу для строк из букв: ";
    getline(cin, letters);

    if (input.empty() || digits.empty() || letters.empty()) {
        cout << "Нужно указать все три пути\n";
        return 1;
    }

    if (sameFile(input, digits) || sameFile(input, letters) || sameFile(digits, letters)) {
        cout << "Укажите три разных файла\n";
        return 1;
    }

    ifstream from(input);
    if (!from) {
        cout << "Не удалось открыть исходный файл\n";
        return 1;
    }

    ofstream toDigits(digits);
    ofstream toLetters(letters);
    if (!toDigits || !toLetters) {
        cout << "Не удалось открыть выходные файлы\n";
        return 1;
    }

    string s;
    while (getline(from, s)) {
        if (!s.empty() && s.back() == '\r') {
            s.pop_back();
        }
        if (s.empty()) {
            continue;
        }

        bool onlyDigits = true;
        bool onlyLetters = true;
        for (char c : s) {
            if (c < '0' || c > '9') {
                onlyDigits = false;
            }
            if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
                onlyLetters = false;
            }
        }

        if (onlyDigits) {
            toDigits << s << '\n';
        } else if (onlyLetters) {
            toLetters << s << '\n';
        }
    }

    toDigits.close();
    toLetters.close();
    if (!from.eof() || !toDigits || !toLetters) {
        cout << "Ошибка чтения или записи\n";
        return 1;
    }

    cout << "Показать содержимое файлов? (1 — да): ";
    int show;
    if (cin >> show && show == 1) {
        showFile(input);
        showFile(digits);
        showFile(letters);
    }
}
