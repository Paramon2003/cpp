
#pragma once
#include "Book.h"
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <ctime>
using namespace std;

class Reader {
public:
    Reader(string name);
    virtual ~Reader() = default;

    string getName() const;
    const vector<Book*>& getBorrowedBooks() const;
    const map<string, time_t>& getReturnDates() const;

    virtual bool borrowBook(Book* book, time_t borrowDate);
    virtual bool returnBook(Book* book, time_t returnDate);
    virtual time_t calculateReturnDate(time_t borrowDate) const;

protected:
    string name;
    vector<Book*> borrowedBooks;
    map<string, time_t> returnDates;
};

