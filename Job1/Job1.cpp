﻿// Job1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
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
    cout << "Введите " << stringCount << " строк(-у):\n";
    for (int i = 0; i < stringCount; i++)
    {
        cin >> str;
        int strSize = (int)str.size();
        if (strSize % 2 != 0)
        {
            strSize = strSize / 2;
            int j = 1;
            bool palindromeStatus = false;
            while ((palindromeStatus == false) and (j <= strSize))
            {
                if (str[strSize-j] != str[strSize+j])
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
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
