#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <Math.h>
#include <Windows.h>

using namespace std;

class population {

private: 
    string type_loc, name_loc;
    int amount_p, year, number_inf;
    short month, day;

public:void vvod(string *name_loc, int *amount_p, int *year, short *month, short *day) {
    cout << "Введите название населенного пункта: ";
        cin >> *name_loc; 
    *amount_p = 2001 + rand() % 5000000;
    *year = 2000 + rand() % 21;
    *month = 1 + rand() % 12;
    *day =1 + rand() % 31;

}
public:void vivod(string *name_loc, int* amount_p, int* number_inf, string *type_loc, int* year, short* month, short* day) {
    cout << "Тип населенного пункта: " << *type_loc << endl; 
    cout << "Название населенного пункта: " << *name_loc << endl;
    cout << "Колическто населения: " << *amount_p << endl;
    cout << "Количество объектов инфраструктуры: " << *number_inf << endl;
    cout << "Дата переписи населения: " << *day << "." << *month << "." << *year << endl;

}
public: void vivod(string* name_loc, int* amount_p, int* number_inf, string* type_loc) {
    cout << "Тип населенного пункта: " << *type_loc << endl;
    cout << "Название населенного пункта: " << *name_loc << endl;
    cout << "Колическто населения: " << *amount_p << endl;
    cout << "Количество объектов инфраструктуры: " << *number_inf << endl;

}

public: void filtr(int amount_p, string *type_loc, int* number_inf) {
    if (amount_p >=20000)
    {
        *number_inf = 5000 + rand() % 10000;
        *type_loc = "Город";

    }
    else if (amount_p >= 2000 && amount_p <= 5000)
    {
        *number_inf = 100 + rand() % 500;
        *type_loc = "Поселок";

    }
    else if (amount_p > 5000 && amount_p < 20000)
    {
        *number_inf = 2000 + rand() % 4000;
        *type_loc = "Пгт";

    }

}
public: void dob(int* amount_p, int* number_inf, int* year, short* month, short* day) {
    int p;
    int i;
    cout << "Введите количество новых жителей: " << endl;
    cin >> p;
    *amount_p = *amount_p + p;
    cout << "Введите количество новых объектов инфраструктуры: " << endl;
    cin >> i;
    *number_inf = *number_inf + i;
    cout << "Введите обновленную дату переписи(ДД/ММ/ГГГГ): ";
    cin >> *year >> *month >> *day;
    cout << "Дата переписи населения: " << *day << "." << *month << "." << *year << endl;  
}
};


int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
  
    string fl = "myFile.txt";

    string type_loc, name_loc;
    int amount_p, year, number_inf;
    short month, day;
    char n, z, g;

    population k;

    k.vvod(&name_loc, &amount_p, &year, &month, &day);
    k.filtr(amount_p, &type_loc, &number_inf);
    k.vivod(&name_loc, &amount_p, &number_inf, &type_loc, &year, &month, &day);
    cout<< "Добавить жителей и объекты(y/n): ";
    cin >> z;
    if (z == 'y') {
        k.dob(&amount_p, &number_inf, &year, &month, &day);
        k.vivod(&name_loc, &amount_p, &number_inf, &type_loc);
    }
    
   
    ofstream fout(fl, ios_base::out | ios_base::trunc);
    if (!fout.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
    }
    else
    {
        cout << "Файл открыт!" << endl;
        fout.write((char*)&k, sizeof(population));
    }
    fout.close();

    cout << "Новый населенный пункт(y/n): ";
    cin >> n;
    if (n == 'y') {
        population l;

        l.vvod(&name_loc, &amount_p, &year, &month, &day);
        l.filtr(amount_p, &type_loc, &number_inf);
        l.vivod(&name_loc, &amount_p, &number_inf, &type_loc, &year, &month, &day);
        cout << "Добавить жителей и объекты(y/n): ";
        cin >> g;
        if (g == 'y') {
            l.dob(&amount_p, &number_inf, &year, &month, &day);
            l.vivod(&name_loc, &amount_p, &number_inf, &type_loc);
        }
    
        ofstream fout(fl, ios_base::out);
        if (!fout.is_open()) {
            cout << "Ошибка открытия файла!" << endl;
        }
        else
        {
            cout << "Файл открыт!" << endl;
            fout.write((char*)&l, sizeof(population));
        }
        fout.close();
    }

    cout << "Новый населенный пункт(y/n): ";
    cin >> n;
    if (n == 'y') {
        population k;

        k.vvod(&name_loc, &amount_p, &year, &month, &day);
        k.filtr(amount_p, &type_loc, &number_inf);
        k.vivod(&name_loc, &amount_p, &number_inf, &type_loc, &year, &month, &day);
        cout << "Добавить жителей и объекты(y/n): ";
        cin >> g;
        if (g == 'y') {
            k.dob(&amount_p, &number_inf, &year, &month, &day);
            k.vivod(&name_loc, &amount_p, &number_inf, &type_loc);
        }

        ofstream fout(fl, ios_base::out);
        if (!fout.is_open()) {
            cout << "Ошибка открытия файла!" << endl;
        }
        else
        {
            cout << "Файл открыт!" << endl;
            fout.write((char*)&k, sizeof(population));
        }
        fout.close();
    }

    return 0;
}
