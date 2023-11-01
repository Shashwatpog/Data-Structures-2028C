#include <iostream>
#include <string>
#include <stdexcept>

// Define a custom exception class for a full shelf
class FullShelfException : public std::runtime_error {
public:
    FullShelfException() : std::runtime_error("Shelf is full. Cannot add more movies.") {}
};

// Define a custom exception class for an empty shelf
class EmptyShelfException : public std::runtime_error {
public:
    EmptyShelfException() : std::runtime_error("Shelf is empty. Cannot remove a movie.") {}
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

// Define a class to represent a shelf of movies
class MovieShelf {
public:
    // Constructor to initialize an empty shelf
    MovieShelf() : numMovies_(0) {}

    // Function to add a movie to the shelf
    void addMovie(const Movie& movie) {
        if (numMovies_ < MAX_MOVIES) {
            movies_[numMovies_] = movie;
            numMovies_++;
        }
        else {
            throw FullShelfException(); // Throw a FullShelfException when the shelf is full
        }
    }

    // Function to remove a movie from the shelf (assume removing the last one)
    Movie removeMovie() {
        if (numMovies_ > 0) {
            numMovies_--;
            return movies_[numMovies_];
        }
        else {
            throw EmptyShelfException(); // Throw an EmptyShelfException when the shelf is empty
        }
    }

    // Function to get the number of movies on the shelf
    int getNumMovies() const {
        return numMovies_;
    }

private:
    static const int MAX_MOVIES = 3; // Global constant for the maximum number of movies
    Movie movies_[MAX_MOVIES];        // Array to hold movies
    int numMovies_;                   // Number of movies currently on the shelf
};

int main() {
    MovieShelf shelf;
    int choice;

    while (true) {
        std::cout << "Press 1 to add a movie to the shelf." << std::endl;
        std::cout << "Press 2 to remove a movie from the shelf." << std::endl;
        std::cout << "Press 3 to see how many movies are currently on the shelf." << std::endl;
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

                // Create a new Movie object and add it to the shelf
                Movie movie(title, year);
                shelf.addMovie(movie);
                break;
            }
            case 2: {
                // Remove a movie from the shelf and display its details
                Movie removedMovie = shelf.removeMovie();
                std::cout << "Removed Movie: " << removedMovie.getTitle() << " (" << removedMovie.getYear() << ")" << std::endl;
                break;
            }
            case 3: {
                // Display the number of movies on the shelf
                std::cout << "Number of movies on the shelf: " << shelf.getNumMovies() << std::endl;
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
        catch (const FullShelfException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        catch (const EmptyShelfException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}
