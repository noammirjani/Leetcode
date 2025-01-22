#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <iostream>

class Book {
public:
    Book(const std::string& title, const std::vector<std::string>& pages)
        : title(title), pages(pages) {}

    std::string getTitle() const {
        return title;
    }

    std::string getPage(int pageNumber) const {
        if (pageNumber >= 0 && pageNumber < pages.size()) {
            return pages[pageNumber];
        }
        return "";
    }

    int getTotalPages() const {
        return pages.size();
    }

private:
    std::string title;
    std::vector<std::string> pages;
};

class BookReadingStatus {
public:
    BookReadingStatus(std::shared_ptr<Book> book)
        : book(book), currPage(0) {}

    int getCurrentPage() const {
        return currPage;
    }

    void nextPage() {
        if (currPage < book->getTotalPages() - 1) {
            currPage++;
        }
    }

    std::shared_ptr<Book> getBook() const {
        return book;
    }

private:
    std::shared_ptr<Book> book;
    int currPage;
};

class User {
public:
    User(const std::string& name)
        : name(name), currentBook("") {}

    void addBookToLibrary(std::shared_ptr<Book> book) {
        ownLibrary[book->getTitle()] = BookReadingStatus(book);
    }

    void removeBookFromLibrary(const std::string& bookTitle) {
        ownLibrary.erase(bookTitle);
    }

    void setActiveBook(const std::string& bookTitle) {
        if (ownLibrary.find(bookTitle) != ownLibrary.end()) {
            currentBook = bookTitle;
        }
    }

    std::string getCurrentPage() const {
        if (!currentBook.empty() && ownLibrary.find(currentBook) != ownLibrary.end()) {
            return ownLibrary.at(currentBook).getBook()->getPage(ownLibrary.at(currentBook).getCurrentPage());
        }
        return "";
    }

    void nextPage() {
        if (!currentBook.empty() && ownLibrary.find(currentBook) != ownLibrary.end()) {
            ownLibrary[currentBook].nextPage();
        }
    }

private:
    std::string name;
    std::unordered_map<std::string, BookReadingStatus> ownLibrary;
    std::string currentBook;
};

class Library {
public:
    void addUser(const std::string& userName) {
        users[userName] = std::make_unique<User>(userName);
    }

    void addBook(const std::string& bookTitle, const std::vector<std::string>& pages) {
        books[bookTitle] = std::make_shared<Book>(bookTitle, pages);
    }

    void addBookToUserLibrary(const std::string& userName, const std::string& bookTitle) {
        if (users.find(userName) != users.end() && books.find(bookTitle) != books.end()) {
            users[userName]->addBookToLibrary(books[bookTitle]);
        }
    }

    void removeBookFromUserLibrary(const std::string& userName, const std::string& bookTitle) {
        if (users.find(userName) != users.end()) {
            users[userName]->removeBookFromLibrary(bookTitle);
        }
    }

    void setActiveBook(const std::string& userName, const std::string& bookTitle) {
        if (users.find(userName) != users.end()) {
            users[userName]->setActiveBook(bookTitle);
        }
    }

    std::string getCurrentPage(const std::string& userName) const {
        if (users.find(userName) != users.end()) {
            return users.at(userName)->getCurrentPage();
        }
        return "";
    }

    void nextPage(const std::string& userName) {
        if (users.find(userName) != users.end()) {
            users[userName]->nextPage();
        }
    }

private:
    std::unordered_map<std::string, std::shared_ptr<Book>> books;
    std::unordered_map<std::string, std::unique_ptr<User>> users;
};

int main() {
    Library library;

    // Add users
    library.addUser("Alice");
    library.addUser("Bob");

    // Add books to the library
    library.addBook("Book1", {"Page 1 of Book1", "Page 2 of Book1", "Page 3 of Book1"});
    library.addBook("Book2", {"Page 1 of Book2", "Page 2 of Book2"});

    // Add books to users' libraries
    library.addBookToUserLibrary("Alice", "Book1");
    library.addBookToUserLibrary("Alice", "Book2");
    library.addBookToUserLibrary("Bob", "Book1");

    // Set active book for Alice
    library.setActiveBook("Alice", "Book1");

    // Display current page for Alice
    std::cout << "Alice is reading: " << library.getCurrentPage("Alice") << std::endl;

    // Move to next page
    library.nextPage("Alice");
    std::cout << "Alice is reading: " << library.getCurrentPage("Alice") << std::endl;

    // Set active book for Bob
    library.setActiveBook("Bob", "Book1");

    // Display current page for Bob
    std::cout << "Bob is reading: " << library.getCurrentPage("Bob") << std::endl;

    return 0;
}
