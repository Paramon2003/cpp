#ifndef FORGETFULEADER_H
#define FORGETFULREADER_H

#include <string>
#include "Book.h"
#include "Reader.h"
#include <iostream>
#include "Library.h"


class ForgetfulReader : public Reader
{
public:
    ForgetfulReader(const std::string& name);

    bool returnBook(Book* book, time_t returnDate) override;
    time_t calculateReturnDate(time_t borrowDate) const override;
};

#endif 

