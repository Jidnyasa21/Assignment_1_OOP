#include <iostream>
#include <string>
using namespace std;

class StringArray {
private:
    string* arr;
    int size;

public:
    StringArray(int n) : size(n) {
        arr = new string[size];
    }

    ~StringArray() {
        delete[] arr;
    }

    void inputLines() {
        cout << "Enter " << size << " lines:" << endl;
        for (int i = 0; i < size; ++i) {
            getline(cin, arr[i]);
        }
    }

    void checkString(const string& s) {
        int count = 0;
        for (int i = 0; i < size; ++i) {
            if (arr[i].find(s) != string::npos) {
                count++;
                cout << "Line " << i + 1 << ": " << arr[i] << endl;
            }
        }
        cout << "String found " << count << " times." << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of lines: ";
    cin >> n;
    cin.ignore();

    StringArray sa(n);
    sa.inputLines();

    string searchString;
    cout << "Enter string to search: ";
    getline(cin, searchString);

    sa.checkString(searchString);
    return 0;
}
