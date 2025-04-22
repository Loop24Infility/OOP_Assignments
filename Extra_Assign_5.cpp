#include <bits/stdc++.h>
using namespace std;

class Books 
{
    string author, title, publisher;
    float price;
    int stock;

    public:
    Books(string a, string t, string p, float pr, int s) 
    {
        author = a;
        title = t;
        publisher = p;
        price = pr;
        stock = s;
    }

    void displayDetails() 
    {
        cout<<"Title: "<<title<<endl;
        cout<<"Author: "<<author<<endl;
        cout<<"Publisher: "<<publisher<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Stock: "<<stock<<"copies"<<endl;
    }

    bool purchaseBook(string t, string a, int copies) 
    {
        if (title == t && author == a) 
        {
            if (stock >= copies) 
            {
                cout<<"Book is available."<<endl;
                cout<<"Total cost: " <<price * copies<<endl;
                stock -= copies;
                return true;
            } 

            else 
            {
                cout << "Required copies not in stock." << endl;
                return true;
            }
        } 

        else 
        {
            return false;
        }
    }
};

int main() 
{
    
    vector<Books> inventory = 
    {
        Books("Ansh", "English", "Self", 10.5, 5),
        Books("Author2", "Title2", "Publisher2", 15.0, 3),
        Books("Author3", "Title3", "Publisher3", 20.0, 2)
    };

    string searchTitle, searchAuthor;
    int copies;

    cout<<"Enter the title of the book: ";
    getline(cin, searchTitle);

    cout<<"Enter the author of the book: ";
    getline(cin, searchAuthor);

    cout<<"Enter the number of copies required: ";
    cin>>copies;

    bool found = false;
    
    for (auto& book : inventory) 
    {
        if (book.purchaseBook(searchTitle, searchAuthor, copies)) 
        {
            found = true;
            break;
        }
    }

    if (!found) 
    {
        cout << "Book not found in inventory." << endl;
    }

    return 0;
}