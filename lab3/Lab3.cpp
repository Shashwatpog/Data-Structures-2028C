#include <iostream>
#include "ComplexNumber.h"
using namespace std;  


int main() {
    char choice = 'y';

    while (true){
        double x, y;
        cout << "Enter the real part of the complex number: ";
        cin >> x;
        cout << "Enter the imaginary part of the complex number: ";
        cin >> y;

        ComplexNumber complex1(x, y);
        ComplexNumber complex2;

        int operation;
        cout << "\nChoose an operation to perform:" << endl;
        cout << "1. +" << endl;
        cout << "2. -" << endl;
        cout << "3. *" << endl;
        cout << "4. /" << endl;
        cout << "Enter your choice(1/2/3/4): ";
        cin >> operation;

        if (operation == 1) {
            cout << "\nEnter the real part of the 2nd complex number: ";
            cin >> x;
            cout << "Enter the imaginary part of the 2nd complex number: ";
            cin >> y;
            complex2 = ComplexNumber(x, y);
            complex1 += complex2;
            cout << "Result : ";
            complex1.print();
         
        }
        else if (operation == 2) {
            cout << "\nEnter the real part of the 2nd complex number: ";
            cin >> x;
            cout << "Enter the imaginary part of the 2nd complex number: ";
            cin >> y;
            complex2 = ComplexNumber(x, y);
            complex1 -= complex2;
            cout << "Result : ";
            complex1.print();
            
        }
        else if (operation == 3) {
            cout << "\nEnter number for multiplication : ";
            cin >> y;
            complex1 *= y;
            cout << "Result : ";
            complex1.print();
           
        }

        else if (operation == 4) {
            cout << "\nEnter number for division: ";
            cin >> y;
            complex1 /= y;
            cout << "Result : ";
            complex1.print();
            
        }
        else{
            cout << "Invalid choice." << endl;
        }
        cout << "\nDo you wish to continue? (y/n): ";
        cin >> choice;
        if (choice == 'y') {
            continue;
        }
        else {
            break;
        }
    }

    return 0;
}
