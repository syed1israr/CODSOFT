#include <iostream>
#include <string>
#include <ctime>

class Library {
public:
    double Penalty_amount;
    time_t duedate;
    std::string title;
    std::string author;
    std::string isbn;
    bool available;

   
    Library(const std::string& title, const std::string& author, const std::string& isbn)
        : Penalty_amount(0.0), title(title), author(author), isbn(isbn), available(true) {
    }

    bool is_available() const {
        return available;
    }

    void check_out() {
        if (available) {
            available = false;
            time_t currentTime;
            time(&currentTime);
            duedate = currentTime + 7 * 24 * 60 * 60; 
            std::cout << "Book checked out" << std::endl;
        } else {
            std::cout << "Book is not available" << std::endl;
        }
    }

    void return_book() {
        if (!available) {
            available = true;
            time_t currentTime;
            time(&currentTime);

            if (currentTime > duedate) {
                const double finePerDay = 0.50;
                double daysLate = static_cast<double>(currentTime - duedate) / (24 * 60 * 60); 
                double fine = daysLate * finePerDay;
                Penalty_amount += fine;
                std::cout << "Book returned late. Fine: $" << fine << std::endl;
            } else {
                std::cout << "Book returned on time" << std::endl;
            }
        } else {
            std::cout << "Book is already in the library" << std::endl;
        }
    }

    void display() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "ISBN: " << isbn << std::endl;
        if (available) {
            std::cout << "Available" << std::endl;
        } else {
            std::cout << "Not available" << std::endl;
        }
    }
};

int main() {
    Library book("Bible of Love", "syed faraz", "978-3-16-148410-0");
    book.display();
    if (book.is_available()) {
        book.check_out();
    }
    book.display();
    book.return_book();
    book.display();

    return 0;
}
