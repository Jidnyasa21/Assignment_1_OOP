#include <iostream>
#include <string>
using namespace std;

class Library {
private:
    int accessionNumber, yearOfPublication;
    string author, title, publisher;
    double cost;

public:
    Library() {}
    ~Library() {}

    void inputData() {
        cout << "Enter Accession Number: ";
        cin >> accessionNumber;
        cout << "Enter Author Name: ";
        cin.ignore();
        getline(cin, author);
        cout << "Enter Title of the Book: ";
        getline(cin, title);
        cout << "Enter Year of Publication: ";
        cin >> yearOfPublication;
        cout << "Enter Publisher Name: ";
        cin.ignore();
        getline(cin, publisher);
        cout << "Enter Cost of the Book: ";
        cin >> cost;
    }

    void displayData() {
        cout << "Accession Number: " << accessionNumber << endl;
        cout << "Author: " << author << endl;
        cout << "Title: " << title << endl;
        cout << "Year of Publication: " << yearOfPublication << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Cost: Rs. " << cost << endl;
    }
};

int main() {
    Library l;
    l.inputData();
    l.displayData();
    return 0;
}
