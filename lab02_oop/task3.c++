#include <iostream>
#include <string>

using namespace std;

class Lib
{
private:
    string books[100];
    string borrowed[100];
    int bookCount;
    int borrowedCount;

public:
    Lib()
    {
        bookCount = 0;
        borrowedCount = 0;
    }

    void add(string book)
    {
        if (bookCount < 100)
        {
            books[bookCount++] = book;
            cout << "Book added: " << book << "\n";
        }
        else
        {
            cout << "Library full!\n";
        }
    }

    void lend(string book)
    {
        for (int i = 0; i < bookCount; i++)
        {
            if (books[i] == book)
            {
                borrowed[borrowedCount++] = book;
                for (int j = i; j < bookCount - 1; j++)
                {
                    books[j] = books[j + 1];
                }
                bookCount--;
                cout << "Book borrowed: " << book << "\n";
                return;
            }
        }
        cout << "Book not available.\n";
    }

    void ret(string book)
    {
        for (int i = 0; i < borrowedCount; i++)
        {
            if (borrowed[i] == book)
            {
                books[bookCount++] = book;
                for (int j = i; j < borrowedCount - 1; j++)
                {
                    borrowed[j] = borrowed[j + 1];
                }
                borrowedCount--;
                cout << "Book returned: " << book << "\n";
                return;
            }
        }
        cout << "Book not in borrowed list.\n";
    }

    void show()
    {
        cout << "Available Books:\n";
        for (int i = 0; i < bookCount; i++)
        {
            cout << "- " << books[i] << "\n";
        }
        cout << "Borrowed Books:\n";
        for (int i = 0; i < borrowedCount; i++)
        {
            cout << "- " << borrowed[i] << "\n";
        }
    }
};

int main()
{
    Lib library;
    int choice;
    string book;

    do
    {
        cout << "\n1. Add Book\n2. Borrow Book\n3. Return Book\n4. View Books\n5. Exit\nChoose: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "Enter book name: ";
            getline(cin, book);
            library.add(book);
            break;
        case 2:
            cout << "Enter book to borrow: ";
            getline(cin, book);
            library.lend(book);
            break;
        case 3:
            cout << "Enter book to return: ";
            getline(cin, book);
            library.ret(book);
            break;
        case 4:
            library.show();
            break;
        case 5:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
