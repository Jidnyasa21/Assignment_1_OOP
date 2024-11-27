#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string title;
    double price;
    string author;

public:
    void getData() {
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
        cout << "Enter author's name: ";
        cin.ignore();
        getline(cin, author);
    }

    void displayData() {
        cout << "Title: " << title << endl;
        cout << "Price: Rs. " << price << endl;
        cout << "Author: " << author << endl;
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
    double playingTime;

public:
    void getData() {
        Publication::getData();
        cout << "Enter playing time (in hours): ";
        cin >> playingTime;
    }

    void displayData() {
        Publication::displayData();
        cout << "Playing Time: " << playingTime << " hours" << endl;
    }
};

int main() {
    Book b;
    Ebook e;

    cout << "Enter data for book:" << endl;
    b.getData();
    cout << "\nEnter data for eBook:" << endl;
    e.getData();

    cout << "\nBook Details:" << endl;
    b.displayData();
    cout << "\nEBook Details:" << endl;
    e.displayData();

    return 0;
}
