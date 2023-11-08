#include "BST.h"
#include "BST.cpp"
#include "Word.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <random>
#include <fstream>

using namespace std;

BST<Word>* WordTree;

template <class T>
void printBT(const std::string& prefix, const Node<T>* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "|-" : "|_" );

        std::cout << node->data << std::endl;

        printBT( prefix + (isLeft ? "|   " : "    "), node->right, true);
        printBT( prefix + (isLeft ? "|   " : "    "), node->left, false);
    }
}

template <class T>
void printBT(const Node<T>* node) 
{
    printBT("", node, false);    
}

bool exists(const string& fileName) 
{
    ifstream infile(fileName.c_str());
    return infile.good();
}

void BodyFunction() 
{
    string fileName;
    ifstream targetFile;
    cout << "Enter the File Name: ";
    cin >> fileName;

    targetFile.open(fileName);

    while (!targetFile)
    {
        cout << "Invalid file name" << endl;
        cout << "Enter File Name again: ";
        cin >> fileName;
        targetFile.open(fileName);
    }

    string contentsWatch = ""; 

    while (contentsWatch != "Contents:" && contentsWatch != "Contents: " && contentsWatch != "Contents:\r" && contentsWatch != "Contents: \r")
    {
        getline(targetFile, contentsWatch);
    }

    int flag = 0;
    string w;
    string w1;

    while (!targetFile.eof())
    {
        targetFile >> w;
        w1 = "";
        for (int i = 0; i < w.length(); i++)
        {
			if (!isalpha(w.at(i))){
				continue;
			}
            w.at(i) = tolower(w.at(i));
            w1 += w.at(i);
        }
		Word tempWord = Word(w1, 1);
        try {
            WordTree->Find(tempWord);
        }
		catch(EmptyTreeException ex){
            WordTree->Insert(tempWord);
            continue;
		}
		
        Word* WordLocation = WordTree->Find(tempWord);
        if (WordLocation == nullptr)
        {
            WordTree->Insert(tempWord);
        }
        else
        {
            if (tempWord.getWord() == "me")
            {
                int x = 1;
            }
            WordLocation->setFreq(WordLocation->getFreq() + 1);
        }
    }

    printBT(WordTree->getRoot());

    targetFile.close(); 

}

void OptionMenu() {

    int menuans = 0;
    string search = "";
    Word searchword;
    Word* searchloc;
    while (menuans == 0)
    {
        cout << endl;
        cout << "What would you like to do next?" << endl;
        cout << "1. Search for a word" << endl;
        cout << "2. GetAllAscending" << endl;
        cout << "3. GetAllDescending" << endl;

        cin >> menuans;

        switch (menuans) {
        case 1: 
            cout << endl;
            cout << "Word to search for?" << endl;
            cout << "> ";
            cin >> search;
            cout << endl;
            searchword = Word(search, 0);
            searchloc = WordTree->Find(searchword);
            if (searchloc == nullptr)
            {
                cout << "The word you searched for was not in the tree." << endl;
            }
            else
            {
                cout << "Given word appeared " << searchloc->getFreq() << " times." << endl;
            }
            break;
        case 2: 
            cout << endl;
            WordTree->PrintVect(WordTree->GetAllAscending());
            break;
        case 3: 
            cout << endl;
            WordTree->PrintVect(WordTree->GetAllDescending());
            break;
        }

        cout << endl;
        cout << "Would you like to select another option?" << endl;
        cout << "(0) Yes" << endl;
        cout << "(1) No" << endl;

        cin >> menuans;
    }
}

int main()
{
    WordTree = new BST<Word>();
    char anotherBook = 'Y'; 
   
    BodyFunction();
    OptionMenu();

    cout << endl;
    cout << "Would you like to process another file?(Y/N): ";
    cin >> anotherBook;
    while (anotherBook == 'Y') 
    {
        WordTree->EmptyTree();
        BodyFunction(); 
        OptionMenu();

        cout << endl;
        cout << "Would you like to process another file?(Y/N): ";
        cin >> anotherBook;
        while (anotherBook != 'Y' && anotherBook != 'N') 
        {
            cout << "Enter Y or N: ";
            cin >> anotherBook;
        }
    }
    
    return 0;
}