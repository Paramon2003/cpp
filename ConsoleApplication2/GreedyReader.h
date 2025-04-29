#pragma once
#ifndef GREEDYREADER_H
#define GREEDYREADER_H

#include "Reader.h"
#include "Book.h"
#include <string>
#include <ctime>

class GreedyReader : public Reader {
public:
    GreedyReader(const std::string& name);

    bool borrowBook(Book* book, time_t borrowDate) override;
    time_t calculateReturnDate(time_t borrowDate) const override;
};

#endif
