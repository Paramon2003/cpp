#pragma once
#include <string>
#include <iostream>
using namespace std;

class Book {
public:
    Book(string title, string author);

    string getTitle() const;
    string getAuthor() const;
    bool getIsAvailable() const;
    bool getIsLost() const;

    void setAvailable(bool available);
    void setLost(bool lost);

    void displayInfo() const;

private:
    string title;
    string author;
    bool isAvailable;
    bool isLost;
};


