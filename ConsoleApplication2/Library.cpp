#include "Library.h"
#include <random>
#include <iostream>

void Library::addBook(const string title, const string author) {
    books.push_back(new Book(title, author)); 
}

void Library::addReader(Reader* reader) {
    readers.push_back(reader);  
}

void Library::clear() {
    for (Book* book : books) {
        delete book;
    }
    books.clear();

    for (Reader* reader : readers) {
        delete reader;
    }
    readers.clear();
}

void Library::borrowBookProcess() {
    if (books.empty() || readers.empty()) return;

    time_t now = time(nullptr);

    for (auto& reader : readers) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distr(0, books.size() - 1);
        int randomIndex = distr(gen);

        Book* book = books[randomIndex];

        if (book && book->getIsAvailable()) {
            if (reader->borrowBook(book, now)) {
                cout << reader->getName() << " взял(а) " << book->getTitle() << endl;
            }
        }
        else {
            for (auto& b : books) {
                if (b && b->getIsAvailable()) {
                    if (reader->borrowBook(b, now)) {
                        std::cout << reader->getName() << " взял(а) другую книгу: " << b->getTitle() << std::endl;
                        break;
                    }
                }
            }
        }
    }
}

void Library::returnBookProcess() {
    if (readers.empty()) return;

    time_t now = time(nullptr);

    for (auto& reader : readers) {
        auto borrowedBooks = reader->getBorrowedBooks();
        if (!borrowedBooks.empty()) {
            Book* book = borrowedBooks[0];
            bool returned = reader->returnBook(book, now);

            if (returned) {
                cout << reader->getName() << " вернул(а) " << book->getTitle() << endl;

               
                auto returnDates = reader->getReturnDates();
                auto it = returnDates.find(book->getTitle());
                if (it != returnDates.end()) {
                    if (now > it->second) {
                        cout << "  (вернул(а) позднее)" << endl;
                    }
                }
            }
            else {
                cout << reader->getName() << " потерял(а) " << book->getTitle() << endl;
            }
        }
    }
}

void Library::generateReports() const {
    cout << "\n=== Отчет Библиотеки ===" << endl;

    int availableCount = 0;
    for (const auto& book : books) {
        if (book && book->getIsAvailable() && !book->getIsLost()) {
            availableCount++;
        }
    }
    cout << "Доступные книги: " << availableCount << endl;

    int borrowedCount = 0;
    for (const auto& book : books) {
        if (book && !book->getIsAvailable() && !book->getIsLost()) {
            borrowedCount++;
        }
    }
    cout << "Книги на руках: " << borrowedCount << endl;

    int lostCount = 0;
    for (const auto& book : books) {
        if (book && book->getIsLost()) {
            lostCount++;
        }
    }
    cout << "Потерянные книги: " << lostCount << endl;

    cout << "\nЧитатели и их книги:" << endl;
    for (const auto& reader : readers) {
        cout << reader->getName() << ":" << endl;
        for (const auto& book : reader->getBorrowedBooks()) {
            cout << "  - " << book->getTitle();

            auto returnDates = reader->getReturnDates();
            auto it = returnDates.find(book->getTitle());
            if (it != returnDates.end()) {
                time_t now = time(nullptr);
                if (now > it->second) {
                    cout << " (overdue)";
                }
            }

            cout << endl;
        }
        if (reader->getBorrowedBooks().empty()) {
            cout << "  (нет взятых книг)" << endl;
        }
    }
}
