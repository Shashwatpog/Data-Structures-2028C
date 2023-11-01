#include <iostream>
#include <string>

using namespace std;

class Show {
protected:
    string title;
    string genre;

public:
    // Default constructor
    Show() {
        title = "";
        genre = "";
    }

    // Overload constructor
    Show(const string& _title, const string& _genre) {
        title = _title;
        genre = _genre;
    }

    // Getters and setters
    string getTitle() const {
        return title;
    }

    void setTitle(const string& _title) {
        title = _title;
    }

    string getGenre() const {
        return genre;
    }

    void setGenre(const string& _genre) {
        genre = _genre;
    }

    // Virtual function for Play
    virtual void Play() {
        // To be overridden in derived classes
    }

    // Non-virtual function for Details
    void Details() const {
        cout << "Title: " << title << endl;
        cout << "Genre: " << genre << endl;
        cout << endl;
    }
};

class TVShow : public Show {
private:
    int** episodes; // 2D array to hold seasons and episodes
    int maxEpisodes; // Maximum number of episodes per season
    int seasons; // Number of seasons

public:
    // Constructor for TVShow
    TVShow(const string& _title, const string& _genre, int _seasons)
        : Show(_title, _genre), seasons(_seasons) {
        // Input for the maximum number of episodes per season
        cout << "Enter the maximum number of episodes per season: ";
        cin >> maxEpisodes;

        // Allocate memory for the 2D array
        episodes = new int* [seasons];
        for (int i = 0; i < seasons; ++i) {
            episodes[i] = new int[maxEpisodes];
        }

        // Initialize episodes array (you can modify this as needed)
        for (int i = 0; i < seasons; ++i) {
            for (int j = 0; j < maxEpisodes; ++j) {
                episodes[i][j] = i * maxEpisodes + j + 1; // Assigning episode values
            }
        }
    }

    // Destructor to deallocate memory
    ~TVShow() {
        for (int i = 0; i < seasons; ++i) {
            delete[] episodes[i];
        }
        delete[] episodes;
    }

    void Play() override {
        int season, episode;
        cout << "Enter the season number (1-" << seasons << "): ";
        cin >> season;
        if (season < 1 || season > seasons) {
            cout << "Invalid season number." << endl;
            return;
        }

        cout << "Enter the episode number (1-" << maxEpisodes << "): ";
        cin >> episode;
        if (episode < 1 || episode > maxEpisodes) {
            cout << "Invalid episode number." << endl;
            return;
        }

        
        cout << "Playing season " << season << ", episode " << episode << ": " << "...." << endl;
    }

    void Details() const {
        Show::Details();
        cout << "Number of Seasons: " << seasons << endl;
        cout << "Maximum number of episodes per season: " << maxEpisodes << endl;
        cout << endl;
    }
};

class Movie : public Show {
private:
    string openingCredits;

public:
    // Constructor for Movie
    Movie(const string& _title, const string& _genre, const string& _openingCredits)
        : Show(_title, _genre), openingCredits(_openingCredits) {}

    // Getter for openingCredits
    string getOpeningCredits() const {
        return openingCredits;
    }

    // Setter for openingCredits
    void setOpeningCredits(const string& _openingCredits) {
        openingCredits = _openingCredits;
    }

    void Play() override {
        cout << "Opening Credits: " << openingCredits << endl;
    }
};

// Function to call details and play functions
void TestShow(Show* show) {
    show->Details();
    show->Play();
}

int main() {
    while (true) {
        cout << "Choose an option:" << endl;
        cout << "Press 1 for an instance of Show" << endl;
        cout << "Press 2 for an instance of Movie" << endl;
        cout << "Press 3 for an instance of TV Show" << endl;
        cout << "Press 4 for an instance of a MOVIE declared as a Show" << endl;
        cout << "Press 5 for an instance of a TV Show declared as a Show" << endl;
        cout << "Press 6 to exit" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            string title, genre;
            cout << "Enter title: ";
            cin >> title;
            cout << "Enter genre: ";
            cin >> genre;
            Show show(title, genre);
            TestShow(&show);
        }
        else if (choice == 2) {
            string title, genre, openingCredits;
            cout << "Enter title: ";
            cin >> title;
            cout << "Enter genre: ";
            cin >> genre;
            cout << "Enter opening credits: ";
            cin >> openingCredits;
            Movie movie(title, genre, openingCredits);
            TestShow(&movie);
        }
        else if (choice == 3) {
            string title, genre;
            int seasons;
            cout << "Enter title: ";
            cin >> title;
            cout << "Enter genre: ";
            cin >> genre;
            cout << "Enter number of seasons: ";
            cin >> seasons;
            TVShow tvShow(title, genre, seasons);
            TestShow(&tvShow);
        }
        else if (choice == 4) {
                string title, genre, openingCredits;
                cout << "Enter title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter genre: ";
                getline(cin, genre);
                cout << "Enter opening credits: ";
                getline(cin, openingCredits);

                Movie movie(title, genre, openingCredits);
                Show* show = &movie;
                TestShow(show);
        }
        else if (choice == 5) {
            
                string title, genre;
                int seasons;
                cout << "Enter title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter genre: ";
                getline(cin, genre);
                cout << "Enter number of seasons: ";
                cin >> seasons;

                TVShow tvShow(title, genre, seasons);
                TestShow(&tvShow);
            

        }
        else if (choice == 6) {
            break;
        }

        cout << "Do you wish to continue (y/n)? ";
        char cont;
        cin >> cont;
        if (cont != 'y' && cont != 'Y') {
            break;
        }
    }

    return 0;
}
