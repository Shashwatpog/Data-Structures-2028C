#include <iostream>
#include <iomanip>
#include <string>
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "Part.h"
#include <vector>

using namespace std;

vector<Part*> vect;

void showMenu()
{
    cout << endl;

    cout << "1: AddItem" << endl;
    cout << "2: GetItem" << endl; // need to fix
    cout << "3: IsInList" << endl;
    cout << "4: isEmpty" << endl;
    cout << "5: Size" << endl;
    cout << "6: SeeNext" << endl;
    cout << "7: SeePrev" << endl;
    cout << "8: SeeAt" << endl; // need to fix
    cout << "9: Reset" << endl;
    cout << "0: Exit" << endl;
}
    Part* createPart()
    {
        int S;
        int P;
        int Q;
        int L;
        string D;
        string U;
        cin.ignore();
        cout << "Create a Part:" << endl;
        cout << "SKU: ";
        cin >> S;
        cout << endl;
        cout << "Price: ";
        cin >> P;
        cout << endl;
        cout << "QOM: ";
        cin >> Q;
        cout << endl;
        cout << "Lead Time: " ;
        cin >> L;
        cout << endl;
        cout << "Description: ";
        cin >> D;
        cout << endl;
        cout << "UOM: ";
        cin >> U;
        cout << endl;
        if (Q == 0)
        {
            return(new Part(D, U, S, P, L));
        }
        return(new Part(D, U, S, P, L, Q));
    }

Part* FindPart()
{
    int sku = 0;
    cout << "Enter the SKU number of the part: ";
    cin >> sku;
    cout << endl;
    for (int i = 0; i < vect.size(); i++)
    {
        if (vect.at(i)->GetSKU() == sku)
        {
            return (vect.at(i));
        }
    }
    return (nullptr);
}

int main()
{
    int ans = 1;
    int MenuAns = 0;

    LinkedList<Part>* LList = new LinkedList<Part>();

    showMenu(); // gives choices
    cin >> MenuAns;

    Part* p = nullptr;
    bool e = true;
    int l = 0;

    while (ans != 0)
    {
        cout << endl;
        switch (MenuAns)
        {
        case 1: // add
            p = createPart();
            vect.push_back(p);
            LList->AddItem(p);
            break;
        case 2: // get
            p = FindPart();
            if (p == nullptr)
            {
                cout << "The SKU number does not match" << endl;
            }
            else {
                Part* RetPart = LList->GetItem(p);
                cout << RetPart->GetPartInfo() << endl;
            }
            break;
        case 3: // is in list
            e = LList->IsInList(FindPart());
            if (e) {
                cout << "part exists" << endl;
            }
            else {
                cout << "part doesn't exist" << endl;
            }
            break;
        case 4: // is empty
            e = LList->isEmpty();
            if (e) {
                cout << "list is empty." << endl;
            }
            else {
                cout << "list not empty." << endl;
            }
            break;
        case 5: // size
            cout << "List has " << LList->Size() << " parts in it." << endl;
            break;
        case 6: // see next
            p = LList->SeeNext();
            cout << p->GetPartInfo() << endl;
            break;
        case 7: // see prev
            try
            {
                p = LList->SeePrev();
                if (p == nullptr)
                {
                    cout << "You have reached past the head of the list" << endl;
                    break;
                }
                cout << p->GetPartInfo() << endl;
            }
            catch (EmptyListException ex)
            {
                cout << ex.what();
            }
            break;
        case 8: // see at
            cout << "Enter index in the list" << LList->Size() << endl;
            cin >> l;
            try
            {
                p = LList->SeeAt(l);
                cout << p->GetPartInfo() << endl;
            }
            catch (EndOfListException ex)
            {
                ex.what();
            }
            catch (EmptyListException ex)
            {
                ex.what();
            }
            break;
        case 9: // reset
            LList->Reset();
            break;
        }

        if (ans != 0)
        {
            showMenu(); // gives choices
            cin >> MenuAns;
        }
    }

    delete p;

    return 0;
}