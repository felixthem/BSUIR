//
//  main.cpp
//  laba15
//
//  Created by Danil Dubovik on 01.12.18.
//  Copyright © 2018 Danil Dubovik. All rights reserved.
//

#include <iostream>
#define n 3


using namespace std;

struct book
{
    int number, year, pages;
    string* author, * title, * publish;

};

void Sort(book* MainData)
{
    book temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (MainData[j].author[0] > MainData[j + 1].author[0])
            {
                temp = MainData[j];
                MainData[j] = MainData[j + 1];
                MainData[j + 1] = temp;
            }
        }
    }
}

void AfterYear(book* MainData)
{
    int y;
    cout << "Input year = ";
    cin >> y;
    for (int i = 0; i < n; i++) {
        if (MainData[i].year >= y) {
            cout << MainData[i].author << " " << MainData[i].title << endl;
        }
    }
}

void InitData()
{
    book Data[n] = {
        {345, 1890, 300, "Ivan Makarov", "Duck", "ABC"},
        {838, 1900, 580, "Vladimir Ulianov", "My life", "Germanpublish"},
        {4783, 2000, 580, "f", "Rich", "Haul"},
    };

    book* MainData = new book[n];
    for (int i = 0; i < n; i++)
    {
        MainData[i] = Data[i];
    }
    Sort(MainData);
    AfterYear(MainData);

}




int main()
{
    InitData();
}