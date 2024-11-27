#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string title, author;
    double price;

public:
    void getData() {
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter author: ";
        getline(cin, author);
        cout << "Enter price: ";
        cin >> price;
    }

    void displayData() {
        cout << "Title: " << title << "\nAuthor: " << author << "\nPrice: Rs. " << price << endl;
    }
};

class Book : public Publication {
private:
    int pageCount;

public:
    void getData() {
        Publication::getData();
        cout << "Enter page count: ";
        cin >> pageCount;
    }

    void displayData() {
        Publication::displayData();
        cout << "Page Count: " << pageCount << endl;
    }
};

class Ebook : public Publication {
private:
    double playTime;

public:
    void getData() {
        Publication::getData();
        cout << "Enter play time (hours): ";
        cin >> playTime;
    }

    void displayData() {
        Publication::displayData();
        cout << "Play Time: " << playTime << " hours" << endl;
    }
};

int main() {
    Book b;
    Ebook e;

    cout << "Enter book details:" << endl;
    b.getData();
    cout << "\nEnter eBook details:" << endl;
    e.getData();

    cout << "\nBook Details:" << endl;
    b.displayData();
    cout << "\nEBook Details:" << endl;
    e.displayData();

    return 0;
}
