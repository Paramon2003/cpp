#include "Book.h"

Book::Book(string title, string author) : title(title), author(author), isAvailable(true), isLost(false) {
}

string Book::getTitle() const {
    return title;
}
string Book::getAuthor() const { 
    return author; 
}
bool Book::getIsAvailable() const {
    return isAvailable; 
}
bool Book::getIsLost() const { 
    return isLost; 
}
void Book::setAvailable(bool available) { 
    isAvailable = available; 
}
void Book::setLost(bool lost) { 
    isLost = lost;
}

void Book::displayInfo() const {
    cout << title << " by " << author << endl;
}