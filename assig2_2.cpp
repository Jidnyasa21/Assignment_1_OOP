#include <iostream>
#include <string>
using namespace std;

class StringReplacer {
private:
    string* arr;
    int size;

public:
    StringReplacer(int n) : size(n) {
        arr = new string[size];
    }

    ~StringReplacer() {
        delete[] arr;
    }

    void inputLines() {
        cout << "Enter " << size << " lines:" << endl;
        for (int i = 0; i < size; ++i) {
            getline(cin, arr[i]);
        }
    }

    void replaceString(const string& s1, const string& s2) {
        for (int i = 0; i < size; ++i) {
            size_t pos = arr[i].find(s1);
            while (pos != string::npos) {
                arr[i].replace(pos, s1.length(), s2);
                pos = arr[i].find(s1, pos + s2.length());
            }
        }
    }

    void displayArray() {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter number of lines: ";
    cin >> n;
    cin.ignore();

    StringReplacer sr(n);
    sr.inputLines();

    string s1, s2;
    cout << "Enter string to replace: ";
    getline(cin, s1);
    cout << "Enter replacement string: ";
    getline(cin, s2);

    sr.replaceString(s1, s2);
    cout << "Updated Array:" << endl;
    sr.displayArray();
    return 0;
}
