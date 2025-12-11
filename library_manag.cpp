#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Book {
public:
    int id;
    char name[50];
    char author[50];
    int copies;

    void addBook() {
        cout << "Enter Book ID: ";
        cin >> id;
        cout << "Enter Book Name: ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "Enter Author Name: ";
        cin.getline(author, 50);
        cout << "Enter Copies: ";
        cin >> copies;

        ofstream f("library.dat", ios::binary | ios::app);
        f.write((char*)this, sizeof(*this));
        f.close();
        cout << "Book Added!\n";
    }

    void showBook() {
        cout << "ID: " << id << "\nName: " << name << "\nAuthor: " << author << "\nCopies: " << copies << "\n\n";
    }
};

void searchBook(int bid) {
    Book b;
    ifstream f("library.dat", ios::binary);
    bool found = false;

    while (f.read((char*)&b, sizeof(b))) {
        if (b.id == bid) {
            b.showBook();
            found = true;
        }
    }
    f.close();

    if (!found) cout << "Book Not Found!\n";
}

int main() {
    int ch, id;

    while (true) {
        cout << "\n=== LIBRARY MANAGEMENT ===\n";
        cout << "1. Add Book\n2. Search Book\n3. Exit\nEnter choice: ";
        cin >> ch;

        if (ch == 1) {
            Book b;
            b.addBook();
        }
        else if (ch == 2) {
            cout << "Enter Book ID: ";
            cin >> id;
            searchBook(id);
        }
        else if (ch == 3)
            break;
        else
            cout << "Invalid Choice.\n";
    }
}
