#include "Reader.h"
#include "Book.h"
#include <random>
#include <algorithm>
#include <ctime>

Reader::Reader(string name) : name(name) {
}

string Reader::getName() const {
    return name;
}

const vector<Book*>& Reader::getBorrowedBooks() const {
    return borrowedBooks;
}

const map<string, time_t>& Reader::getReturnDates() const {
    return returnDates;
}

bool Reader::borrowBook(Book* book, time_t borrowDate) {
    if (book && book->getIsAvailable()) {
        book->setAvailable(false);
        borrowedBooks.push_back(book);
        returnDates[book->getTitle()] = calculateReturnDate(borrowDate);
        return true;
    }
    return false;
}

bool Reader::returnBook(Book* book, time_t returnDate) {
    if (book) {
        auto it = find(borrowedBooks.begin(), borrowedBooks.end(), book);

        if (it != borrowedBooks.end()) {
            borrowedBooks.erase(it);
            returnDates.erase(book->getTitle());

            random_device rd;
            mt19937 gen(rd());
            bernoulli_distribution d(0.05);

            if (d(gen)) {
                book->setLost(true);
                return false;
            }

            book->setAvailable(true);
            return true;
        }
    }
    return false;
}

time_t Reader::calculateReturnDate(time_t borrowDate) const {
    return borrowDate + 14 * 24 * 60 * 60;
}
