#include "GreedyReader.h"
#include "Reader.h"
#include <random>

GreedyReader::GreedyReader(const std::string& name) : Reader(name) {}

bool GreedyReader::borrowBook(Book* book, time_t borrowDate) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution d(0.9);

    if (d(gen) && book->getIsAvailable()) {
        return Reader::borrowBook(book, borrowDate);
    }
    return false;
}

time_t GreedyReader::calculateReturnDate(time_t borrowDate) const {
    return borrowDate + 14 * 24 * 60 * 60;
}
