#include "Labs/Labs.h"
#include <iostream>
using namespace std;

int main()
{
    int choice = 0;
    do {
        cout << "\nCENG203 - Data Structures" << endl;
        cout << " 6. Week 6 - Trees and BSTs" << endl;
        cout << " 0. Exit" << endl;
        cout << "Choice: ";
        if (!(cin >> choice))
            break;

        switch (choice) {
        case 6:  runWeek06(); break;
        case 0:  cout << "Bye." << endl; break;
        default: cout << "Not available in this build." << endl; break;
        }
    } while (choice != 0);

    return 0;
}
