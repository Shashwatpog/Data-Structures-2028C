#include <iostream>
#include <string>
#include <stdexcept>

// Define a custom exception class for a full collection
class FullCollectionException : public std::runtime_error {
public:
    FullCollectionException() : std::runtime_error("Collection is full. Cannot add more items.") {}
};

// Define a custom exception class for an empty collection
class EmptyCollectionException : public std::runtime_error {
public:
    EmptyCollectionException() : std::runtime_error("Collection is empty. Cannot remove an item.") {}
};

// Define a templated class to represent an entertainment collection
template <typename T>
class EntertainmentCollection {
public:
    // Constructor to initialize an empty collection
    EntertainmentCollection() : numItems_(0) {}

    // Function to add an item to the collection
    void addItem(const T& item) {
        if (numItems_ < MAX_ITEMS) {
            items_[numItems_] = item;
            numItems_++;
        }
        else {
            throw FullCollectionException(); // Throw a FullCollectionException when the collection is full
        }
    }

    // Function to remove an item from the collection (assume removing the last one)
    T removeItem() {
        if (numItems_ > 0) {
            numItems_--;
            return items_[numItems_];
        }
        else {
            throw EmptyCollectionException(); // Throw an EmptyCollectionException when the collection is empty
        }
    }

    // Function to get the number of items in the collection
    int getNumItems() const {
        return numItems_;
    }

private:
    static const int MAX_ITEMS = 10; // Global constant for the maximum number of items
    T items_[MAX_ITEMS];             // Array to hold items
    int numItems_;                   // Number of items currently in the collection
};

// Define a class to represent a movie
class Movie {
public:
    Movie(std::string title = "", int year = 0) : title_(title), year_(year) {}

    // Getter functions for movie details
    std::string getTitle() const {
        return title_;
    }

    int getYear() const {
        return year_;
    }

private:
    std::string title_;
    int year_;
};

int main() {
    EntertainmentCollection<Movie> movieCollection;
    int choice;

    while (true) {
        std::cout << "Press 1 to add a movie to the collection." << std::endl;
        std::cout << "Press 2 to remove a movie from the collection." << std::endl;
        std::cout << "Press 3 to see how many movies are currently in the collection." << std::endl;
        std::cout << "Press 4 to quit." << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        try {
            switch (choice) {
            case 1: {
                std::string title;
                int year;
                std::cout << "Enter movie title: ";
                std::cin.ignore(); // Clear the input buffer
                std::getline(std::cin, title);
                std::cout << "Enter movie year: ";
                std::cin >> year;

                // Create a new Movie object and add it to the collection
                Movie movie(title, year);
                movieCollection.addItem(movie);
                break;
            }
            case 2: {
                // Remove a movie from the collection and display its details
                Movie removedMovie = movieCollection.removeItem();
                std::cout << "Removed Movie: " << removedMovie.getTitle() << " (" << removedMovie.getYear() << ")" << std::endl;
                break;
            }
            case 3: {
                // Display the number of movies in the collection
                std::cout << "Number of movies in the collection: " << movieCollection.getNumItems() << std::endl;
                break;
            }
            case 4:
                // Quit the program
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
            }
        }
        catch (const FullCollectionException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        catch (const EmptyCollectionException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}
