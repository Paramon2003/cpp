#include "ForgetfulReader.h"
#include "Reader.h"
#include <random>
#include <algorithm>

ForgetfulReader::ForgetfulReader(const std::string& name) : Reader(name) {}

bool ForgetfulReader::returnBook(Book* book, time_t returnDate) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution d(0.2);

    if (d(gen)) {
        book->setLost(true);
        borrowedBooks.erase(std::remove(borrowedBooks.begin(), borrowedBooks.end(), book), borrowedBooks.end());
        returnDates.erase(book->getTitle());
        return false;
    }

    return Reader::returnBook(book, returnDate);
}

time_t ForgetfulReader::calculateReturnDate(time_t borrowDate) const {
    return borrowDate + 28 * 24 * 60 * 60;
}
