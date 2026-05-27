#include <iostream>
#include "container.h"

using namespace std;

int main() {

    int mode;

    cout << "Select mode: 1 - Container<int>, 2 - Container<int*>\n";
    cin >> mode;

    if (mode == 1) {
        Container<int> c(3, 2);

        int choice;

        do {
            cout << "\n MENU: \n";
            cout << "1. Insert\n";
            cout << "2. Delete\n";
            cout << "3. Search\n";
            cout << "4. Print\n";
            cout << "5. Copy\n";
            cout << "0. Exit\n";
            cout << "Choose: ";
            cin >> choice;

            switch (choice) {

            case 1: {
                int val;
                cout << "Value: ";
                cin >> val;

                c.InsertElem(val);
                cout << "Inserted\n";
                break;
            }

            case 2: {
                int val;
                
                while (true) {
                    try {
                        cout << "Delete value: ";
                        cin >> val;

                        c.DeleteElem(val);
                        cout << "Deleted\n";
                        break;
                    }
                    catch (exception& e) {
                        cout << e.what() << endl;
                        cout << "Try another value\n";
                    }
                }
                break;
            }

            case 3: {
                int val;
                cout << "Search value: ";
                cin >> val;

                cout << "Index: " << c.SearchIdx(val) << endl;
                break;
            }

            case 4: {
                for (int i = 0; i < c.getCount(); i++) {
                    cout << c[i] << " ";
                }
                cout << endl;
                break;
            }

            case 5: {
                Container<int> copy = c;

                cout << "Copy:\n";
                for (int i = 0; i < c.getCount(); i++) {
                    cout << copy[i] << " ";
                }
                cout << endl;
                break;
            }

            }

        } while (choice != 0);
    }

    if (mode == 2) {
        Container<int*> c(2, 2);

        int choice;

        do {
            cout << "\n MENU: \n";
            cout << "1. Insert\n";
            cout << "2. Delete\n";
            cout << "3. Search\n";
            cout << "4. Print\n";
            cout << "5. Copy\n";
            cout << "0. Exit\n";
            cout << "Choose: ";
            cin >> choice;

            switch (choice) {

            case 1: {
                int* val = new int;
                cout << "Value: ";
                cin >> *val;

                c.InsertElem(val);
                cout << "Inserted\n";
                break;
            }

            case 2: {
                int val;

                while (true) {
                    try {
                        cout << "Delete value: ";
                        cin >> val;

                        int* temp = new int(val);
                        c.DeleteElem(temp);
                        delete temp;
                        cout << "Deleted\n";
                        break;
                    }
                    catch (exception& e) {
                        cout << e.what() << endl;
                        cout << "Try another value\n";
                    }
                }
                break;
            }

            case 3: {
                int val;
                cout << "Search value: ";
                cin >> val;

                int* temp = new int(val);
                cout << "Index: " << c.SearchIdx(temp) << endl;
                delete temp;
                break;
            }

            case 4: {
                for (int i = 0; i < c.getCount(); i++) {
                    cout << *c[i] << " ";
                }
                cout << endl;
                break;
            }

            case 5: {
                Container<int*> copy = c;

                cout << "Copy:\n";
                for (int i = 0; i < c.getCount(); i++) {
                    cout << *copy[i] << " ";
                }
                cout << endl;
                break;
            }

            }

        } while (choice != 0);
    }

    return 0;
}