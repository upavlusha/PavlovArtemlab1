#include <iostream>

using namespace std;

char* _strstr(const char* string, const char* strCharSet) {
    if (*strCharSet == '\0') {
        return (char*)string;
    }

    for (int i = 0; string[i] != '\0'; i++) {
        int j = 0;
        while (string[i + j] != '\0' && strCharSet[j] != '\0' && string[i + j] == strCharSet[j]) {
            j++;
        }
        if (strCharSet[j] == '\0') {
            return (char*)(string + i);
        }
    }

    return nullptr;
}

bool isLatinLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y';
}

int main() {
    char textA[301] = "Hello programming world";
    char patternA[100] = "program";

    cout << "=== Задача А ===" << endl;
    char* result = _strstr(textA, patternA);
    if (result != nullptr) {
        cout << "Результат: " << result << endl;
    } else {
        cout << "Подстрока не найдена" << endl;
    }

    cout << "\n=== Задача В ===" << endl;
    cout << "Введите строку: ";

    char str[301];
    cin.getline(str, 301);

    int totalLatinWords = 0;
    int balancedWords = 0;

    int i = 0;
    while (str[i] != '\0') {
        while (str[i] == ' ') {
            i++;
        }

        if (str[i] == '\0') {
            break;
        }

        bool onlyLatin = true;
        int vowels = 0;
        int consonants = 0;

        while (str[i] != ' ' && str[i] != '\0') {
            if (isLatinLetter(str[i])) {
                if (isVowel(str[i])) {
                    vowels++;
                } else {
                    consonants++;
                }
            } else {
                onlyLatin = false;
            }
            i++;
        }

        if (onlyLatin) {
            totalLatinWords++;
            if (vowels == consonants) {
                balancedWords++;
            }
        }
    }

    cout << "Слов только из латинских букв: " << totalLatinWords << endl;
    cout << "С равным числом гласных и согласных: " << balancedWords << endl;

    return 0;
}


