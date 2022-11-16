#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
    int stringCount, palindromeCount = 0;
    const int stringLength = 100;
    string str;
    cout << "Введите кол-во строк(>0): ";
    cin >> str;
    try {
        stringCount = stoi(str);
    }
    catch (...) {
        cout << "Упс... Ошибочка.";
        return 0;
    }
    if (stringCount <= 0) {
        cout << "Упс... Ошибочка.";
        return 0;
    }
    char** strLib = new char* [stringCount];
    cout << "Введите " << stringCount << " строк(-у):\n";
    for (int i = 0; i < stringCount; i++) {
        cout << i + 1 << " строка:  ";
        strLib[i] = new char[stringLength];
        cin.ignore();
        cin.getline(strLib[i], stringLength, '\n');
    }
    for (int i = 0; i < stringCount; i++)
    {
        int strSize = strlen(strLib[i]);
        if (strSize % 2 != 0)
        {
            strSize = strSize / 2;
            int j = 1;
            bool palindromeStatus = false;
            while ((palindromeStatus == false) and (j <= strSize))
            {
                if (strLib[i][strSize - j] != strLib[i][strSize + j])
                {
                    palindromeStatus = true;
                }
                else
                {
                    j++;
                }
            }
            if (palindromeStatus == false)
            {
                palindromeCount++;
            }
        }
    }
    cout << "--------------------------------------------------------------------"
        "-------------------------\n";
    cout << "Итого: (" << palindromeCount << '/' << stringCount << ")\n";
    cout << "--------------------------------------------------------------------"
        "-------------------------\n";
    for (int i = 0; i < stringCount; i++)
    {
        delete[] strLib[i];
    }
