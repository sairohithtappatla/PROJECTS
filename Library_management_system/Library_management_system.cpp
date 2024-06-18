#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class Book {
public:
    int id;
    std::string title;
    std::string author;
    bool isIssued;

    Book(int id, std::string title, std::string author) 
        : id(id), title(title), author(author), isIssued(false) {}
};

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(int id, std::string title, std::string author) {
        books.push_back(Book(id, title, author));
        std::cout << "Book added successfully!" << std::endl;
    }

    void viewBooks() {
        std::cout << std::setw(5) << "ID" << std::setw(30) << "Title" << std::setw(30) << "Author" << std::setw(10) << "Status" << std::endl;
        for (const auto& book : books) {
            std::cout << std::setw(5) << book.id << std::setw(30) << book.title << std::setw(30) << book.author 
                      << std::setw(10) << (book.isIssued ? "Issued" : "Available") << std::endl;
        }
    }

    void issueBook(int id) {
        for (auto& book : books) {
            if (book.id == id) {
                if (!book.isIssued) {
                    book.isIssued = true;
                    std::cout << "Book issued successfully!" << std::endl;
                } else {
                    std::cout << "Book is already issued!" << std::endl;
                }
                return;
            }
        }
        std::cout << "Book not found!" << std::endl;
    }

    void returnBook(int id) {
        for (auto& book : books) {
            if (book.id == id) {
                if (book.isIssued) {
                    book.isIssued = false;
                    std::cout << "Book returned successfully!" << std::endl;
                } else {
                    std::cout << "Book is not issued!" << std::endl;
                }
                return;
            }
        }
        std::cout << "Book not found!" << std::endl;
    }
};

void showMenu() {
    std::cout << "Library Management System" << std::endl;
    std::cout << "1. Add Book" << std::endl;
    std::cout << "2. View Books" << std::endl;
    std::cout << "3. Issue Book" << std::endl;
    std::cout << "4. Return Book" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    Library library;
    int choice, id;
    std::string title, author;

    while (true) {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter book ID: ";
                std::cin >> id;
                std::cin.ignore(); // To ignore newline character after integer input
                std::cout << "Enter book title: ";
                std::getline(std::cin, title);
                std::cout << "Enter book author: ";
                std::getline(std::cin, author);
                library.addBook(id, title, author);
                break;
            case 2:
                library.viewBooks();
                break;
            case 3:
                std::cout << "Enter book ID to issue: ";
                std::cin >> id;
                library.issueBook(id);
                break;
            case 4:
                std::cout << "Enter book ID to return: ";
                std::cin >> id;
                library.returnBook(id);
                break;
            case 5:
                std::cout << "Exiting..." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
        }
    }

    return 0;
}
