#pragma once

#include "Book.h"
#include "Reader.h"
#include <vector>
#include <string>
using namespace std;

class Library {
public:
    void addBook(const string title, const string author);
    void addReader(Reader* reader);

    void borrowBookProcess();
    void returnBookProcess();
    void generateReports() const;
    void clear();

private:
    vector<Book*> books;
    vector<Reader*> readers;
};