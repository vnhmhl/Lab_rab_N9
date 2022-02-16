#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> // подключаем строки
#include <fstream> // подключаем файлы

using namespace std;
int main()
{
    setlocale(LC_ALL, "");  //Русификация, чтобы кириллица вводилась и выводилась из файла правильно
    FILE* f1;
    FILE* f2;

    f1 = fopen("lab9_F1.txt", "w");    //открываем файл для записи

    //Записываем 10 строк в файл так, чтобы некоторые начинались и заканчивались на одну и ту же букву
    fputs("е Это первая строка е\n", f1);     //есть
    fputs("это вторая строка. ура\n", f1);
    fputs("р Это третья строка е\n", f1);
    fputs("это четвёртая строка. урэ\n", f1); //есть
    fputs("привет это пятая строка пока\n", f1);
    fputs("ура это шестая строка строка. я пойду\n", f1); //есть
    fputs("лира это седьмая строка лимонл\n", f1);        //есть
    fputs("это восьмая строка. ура\n", f1);
    fputs("девятая строка дома-дом\n", f1);
    fputs("это десятая строка. ура\n", f1);
    fclose(f1);

    f1 = fopen("lab9_F1.txt", "r"); //чтение
    f2 = fopen("lab9_F2.txt", "w"); //запись
    string str;
    char start, end;
    ifstream file(f1);
    while (getline(file, str))
    {
        start = str[0];
        end = str[str.size() - 1];
        if (start == end)
        {
            fputs(str.data(), f2);
            fputs("\n", f2);
        }
    }
    fclose(f1);
    fclose(f2);

    f2 = fopen("lab9_F2.txt", "r");
    char a;
    int count = 0;
    ifstream r(f2);
    while (r >> a) count++;
    r.close();

    cout << "Кол-во символов во втором файле: " << count;
}

