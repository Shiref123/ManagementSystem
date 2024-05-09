#include <iostream>
#include <vector>
#include <string>

// Base class
class ManagementSystem {
public:
    virtual void add() = 0;
    virtual void remove() = 0;
    virtual void display() const = 0;
};

// Book class
class Book {
protected:
    std::string isbn;
    std::string title;
    std::string author;
    int publicationYear;
public:
    Book(const std::string& isbn, const std::string& title, const std::string& author, int publicationYear)
        : isbn(isbn), title(title), author(author), publicationYear(publicationYear) {}

    const std::string& getTitle() const {
        return title;
    }
};

// Library class
class Library : public ManagementSystem {
private:
    std::vector<Book> books;
public:
    void add() override {
        std::string isbn, title, author;
        int publicationYear;

        std::cout << "Enter ISBN: ";
        std::cin >> isbn;
        std::cout << "Enter Title: ";
        std::cin >> title;
        std::cout << "Enter Author: ";
        std::cin >> author;
        std::cout << "Enter Publication Year: ";
        std::cin >> publicationYear;

        books.emplace_back(isbn, title, author, publicationYear);
    }

    void remove() override {
        if (books.empty()) {
            std::cout << "No books to remove." << std::endl;
            return;
        }

        std::string title;
        std::cout << "Enter the title of the book to remove: ";
        std::cin >> title;

        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getTitle() == title) {
                books.erase(it);
                std::cout << "Book removed successfully." << std::endl;
                return;
            }
        }

        std::cout << "Book not found." << std::endl;
    }

    void display() const override {
        if (books.empty()) {
            std::cout << "No books in the library." << std::endl;
            return;
        }

        std::cout << "Books in the library:" << std::endl;
        for (const auto& book : books) {
            std::cout << "Title: " << book.getTitle() << std::endl;
        }
    }
};

// User interface
void displayMenu() {
    std::cout << "1. Add Book" << std::endl;
    std::cout << "2. Remove Book" << std::endl;
    std::cout << "3. Display Books" << std::endl;
    std::cout << "4. Exit" << std::endl;
}

int main() {
    Library library;
    int choice;

    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                library.add();
                break;
            case 2:
                library.remove();
                break;
            case 3:
                library.display();
                break;
            case 4:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 4);

    return 0;
}
