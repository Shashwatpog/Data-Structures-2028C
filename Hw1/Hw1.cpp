#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

// Function to calculate letter frequency
void calculate_letter_frequency(const string& text, double letter_frequency[]) {
    int total_letters = 0;

    for (char c : text) {
        if (isalpha(c)) {
            char lower_c = tolower(c);
            letter_frequency[lower_c - 'a']++;
            total_letters++;
        }
    }

    for (int i = 0; i < 26; i++) {
        letter_frequency[i] = (letter_frequency[i] / total_letters) * 100.0;
    }
}
int calcWordcount(string file_name){
    fstream data;
    data.open(file_name);
    string  word;
    int word_count = 0;
    while (data >> word) {
        word_count++;
    }
    data.close();
    return word_count;
}

int main() {
    while (true) {
        // Take file as input
        string file_name;
        cout << "Enter the name of the file to be processed (or 'quit' to exit): ";
        cin >> file_name;

        if (file_name == "quit") {
            break;
        }

        // Opening file & if file does not exist -> show error message
        fstream file;
        file.open(file_name, ios::in);
        if (file.fail()) {
            cout << "File does not exist" << endl;
            continue;
        }

        // Reading data from file
        string title, author_name, line;
        getline(file, title);
        getline(file, author_name);

        stringstream buffer;
        buffer << file.rdbuf();
        string contents = buffer.str();

        
        int line_count = 0;
        int word_count = calcWordcount(file_name);
        for (char c : contents) {
            if (c == '\n') {
                line_count++;
            }
        }
        

        double letter_frequency[26] = { 0.0 };
        calculate_letter_frequency(contents, letter_frequency);

        // Opening catalog file to store data
        ofstream catalog_file;
        catalog_file.open("CardCatalog.txt", ios::app);

        if (catalog_file.is_open()) {
            catalog_file << "Title: " << title << "\n";
            catalog_file << "Full Author: " << author_name << "\n";
            size_t space_pos = author_name.find(' ');
            if (space_pos != string::npos) {
                catalog_file << "Author First Name: " << author_name.substr(0, space_pos) << "\n";
                catalog_file << "Author Last Name: " << author_name.substr(space_pos + 1) << "\n";
            }
            catalog_file << "Word count: " << word_count << "\n";
            catalog_file << "Line count: " << line_count << "\n\n";

            catalog_file.close();
        }
        else {
            cout << "Error: Failed to open CardCatalog.txt for writing." << endl;
        }

        // Asking user if they want to see the letter frequency
        string show_frequency;
        cout << "Do you want to see the letter frequency? (yes/no): ";
        cin >> show_frequency;

        if (show_frequency == "yes") {
            cout << title << " letter frequency:" << endl;
            for (int i = 0; i < 26; i++) {
                cout << static_cast<char>('a' + i) << ": " << letter_frequency[i] << "%" << endl;
            }
        }

        // Asking the user if they want to repeat the process with a different file
        string another_book;
        cout << "Do you wish to process another book? (yes/no): ";
        cin >> another_book;

        if (another_book != "yes") {
            break;
        }
    }

    return 0;
}
