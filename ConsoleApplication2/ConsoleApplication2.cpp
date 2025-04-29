#include "Library.h"
#include "GreedyReader.h"
#include "ForgetfulReader.h"
#include "Reader.h"
#include <iostream>
#include <locale>

int main() {
    setlocale(LC_ALL, "");
    std::wcout.imbue(std::locale(""));
    Library library;

    library.addBook("The Great Gatsby", "F. Scott Fitzgerald");
    library.addBook("To Kill a Mockingbird", "Harper Lee");
    library.addBook("1984", "George Orwell");
    library.addBook("Pride and Prejudice", "Jane Austen");
    library.addBook("The Hobbit", "J.R.R. Tolkien");

    library.addReader(new Reader("Вася"));
    library.addReader(new GreedyReader("Глаша"));
    library.addReader(new ForgetfulReader("Вова"));

    for (int i = 0; i < 5; ++i) {
        std::cout << "\n=== День " << i + 1 << " ===" << std::endl;
        library.borrowBookProcess();
        library.returnBookProcess();
    }

    library.generateReports();

    library.clear();

    return 0;
}
