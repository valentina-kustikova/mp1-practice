#include "includes.h"
#include "conio.h"

int main()
{
    calendar note;
    int control;
    do {
        cout << "ICS PROcalendar manager (c) 2019" << endl;
        cout << "1 - Add , 2 - Remove, 3 - Print, 4 - Writre calendar to file, 5 - Read calendar from file, 6 - Exit" << endl;
        do {
            cin >> control;
        } while (control > 7);

        switch (control)
        {
        case 1:
            note.create();
            cout << "Press any cay to continue" << endl;
            _getch();
            system("cls");
            break;
        case 2:
            note.remove();
            getchar();
            cout << "Press any cay to continue" << endl;
            _getch();
            system("cls");
            break;
        case 3:
            note.print();
            getchar();
            cout << "Press any cay to continue" << endl;
            _getch();
            system("cls");
            break;
        case 4:
            note.fwrite();
            cout << "Press any cay to continue" << endl;
            _getch();
            system("cls");
            break;
        case 5:
            note.fread();
            cout << "Press any cay to continue" << endl;
            _getch();
            system("cls");
            break;
        }
    } while (control != 6);
}