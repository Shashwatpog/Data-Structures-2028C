#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <queue>

class stack_underflow : public std::exception {
public:
    const char* what() const noexcept override {
        return "Stack underflow.";
    }
};

class stack_overflow : public std::exception {
public:
    const char* what() const noexcept override {
        return "Stack overflow.";
    }
};

class queue_underflow : public std::exception {
public:
    const char* what() const noexcept override {
        return "Queue underflow.";
    }
};

class queue_overflow : public std::exception {
public:
    const char* what() const noexcept override {
        return "Queue overflow.";
    }
};

template <typename Temp>
class Stack {
private:
    Temp** data;
    int size;
    int top;

public:
    Stack(int size) : size(size), top(-1) {
        data = new Temp * [size];
    }

    ~Stack() {
        makeEmpty();
        delete[] data;
    }

    void push(Temp* item) {
        if (top == size - 1)
            throw stack_overflow();
        data[++top] = item;
    }

    void pop() {
        if (top == -1)
            throw stack_underflow();
        delete data[top--];
    }

    Temp* topValue() const {
        if (top == -1)
            throw stack_underflow();
        return data[top];
    }

    int length() const {
        return top + 1;
    }

    void makeEmpty() {
        while (top >= 0) {
            delete data[top--];
        }
    }
};

template <typename Temp>
class Queue {
private:
    Temp** data;
    int capacity;
    int front;
    int rear;

public:
    Queue(int capacity) : capacity(capacity), front(0), rear(-1) {
        data = new Temp * [capacity];
    }

    ~Queue() {
        makeEmpty();
        delete[] data;
    }

    void enqueue(Temp* item) {
        if (length() == capacity)
            throw queue_overflow();
        rear = (rear + 1) % capacity;
        data[rear] = item;
    }

    void dequeue() {
        if (isEmpty())
            throw queue_underflow();
        delete data[front];
        front = (front + 1) % capacity;
    }

    Temp* frontValue() const {
        if (isEmpty())
            throw queue_underflow();
        return data[front];
    }

    int length() const {
        return (rear - front + 1 + capacity) % capacity;
    }

    bool isEmpty() const {
        return length() == 0;
    }

    void makeEmpty() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

std::string reverse_stack(std::string str) {
    Stack<char> charStack(str.length());

    std::string reverse_string = "";

    for (char c : str) {
        if (c != ' ') {
            charStack.push(new char(c));
        }
        else {
            while (charStack.length() > 0) {
                reverse_string += *charStack.topValue();
                charStack.pop();
            }
            reverse_string += ' ';
        }
    }

    while (charStack.length() > 0) {
        reverse_string += *charStack.topValue();
        charStack.pop();
    }

    return reverse_string;
}

std::string reverse_queue(std::string str) {
    Queue<char> charQueue(str.length());

    std::string reverse_string = "";

    for (char c : str) {
        if (c != ' ') {
            charQueue.enqueue(new char(c));
        }
        else {
            while (!charQueue.isEmpty()) {
                reverse_string += *charQueue.frontValue();
                charQueue.dequeue();
            }
            reverse_string += ' ';
        }
    }

    while (!charQueue.isEmpty()) {
        reverse_string += *charQueue.frontValue();
        charQueue.dequeue();
    }

    return reverse_string;
}




int main() {
    char choice;
    do {
        std::cout << "Choose an option:\n";
        std::cout << "1. -> Process data from a file\n";
        std::cout << "2. -> Enter a line of text to reverse\n";
        std::cout << "3. -> Quit the program\n";
        std::cout << "-> Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case '1': {
            std::string filename;
            std::cout << "Enter filename: ";
            std::cin.ignore();
            std::getline(std::cin, filename);

            std::fstream file(filename);
            if (!file.is_open()) {
                std::cerr << "Invalid Input: File not found. Please try again.\n";
                break;
            }

            std::string line;
            while (std::getline(file, line)) {
                std::string reverse_line = reverse_stack(line);
                std::cout << reverse_line << "\n";
            }
            file.close();
            break;
        }

        case '2': {
            std::cout << "Enter a line of text :";
            std::cin.ignore();
            std::string input_line;
            std::getline(std::cin, input_line);
            std::string reverse_line = reverse_stack(input_line);
            std::cout << "Reversed line: " << reverse_line << "\n";
            break;
        }

        case '3':
            std::cout << "Goodbye";
            return 0;

        default:
            std::cerr << "Invalid input";
        }

        std::cout << "Continue? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
