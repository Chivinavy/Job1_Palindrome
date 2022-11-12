#include <iostream>
#include <string>
using namespace std;

int main()
{
    int stringCount, palindromeCount = 0;
    string str;
    cout << "Введите кол-во строк(>0): ";
    cin >> str;
    try
    {
        stringCount = stoi(str);
    }
    catch (...)
    {
        cout << "Упс... Ошибочка.";
        return 0;
    }
    if (stringCount <= 0)
    {
        cout << "Упс... Ошибочка.";
        return 0;
    }
    string* strLib = new string[stringCount];
    cout << "Введите " << stringCount << " строк(-у):\n";
    for (int i = 0; i < stringCount; i++)
    {
        cout << i + 1 << " строка: ";
        cin >> str;
        strLib[i] = str;
    }
    for (int i = 0; i < stringCount; i++)
    {
        int strSize = (int)strLib[i].size();
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
    cout << "---------------------------------------------------------------------------------------------\n";
    cout << "Итого: (" << palindromeCount << '/' << stringCount << ")\n";
    cout << "---------------------------------------------------------------------------------------------\n";
    delete[] strLib;
}