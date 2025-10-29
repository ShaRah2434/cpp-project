#include <iostream>
#include <iomanip>

using namespace std;

struct book{
  string ISBN, title, author;
  double price;
  int stock;
};

void addBook(book books[], int &bookCount);
void displayBooks(const book books[], int bookCount);
int searchBook(const book books[], int bookCount, string keyword);


int main(){
  book books[100];
  int bookCount = 0;

  return 0;
}

void addBook(book books[], int &bookCount){
  cout << "\n-----Add New Book-----\n";

  cout << "Enter ISBN: ";
  getline(cin, books[bookCount].ISBN);

  cout << "Enter Title: ";
  getline(cin, books[bookCount].title);

  cout << "Enter Author: ";
  getline(cin,books[bookCount].author);

  cout << "Enter Price: ";
  cin >> books[bookCount].price;
  getline(cin >> ws, books[bookCount].title);

  cout << "Enter Stock Quantity: ";
  cin >> books[bookCount].stock;

  if(books[bookCount].price <= 0 || books[bookCount].stock < 0){
    cout << "Invalid input. Price must be > 0 while Stock >= 0.\n";
    return;
  }

  bookCount++;
  cout << "Book succesfully added !\n";

}

void displayBooks(const book books[], int bookCount){
  cout << "\n-----Book List-----\n";
  if(bookCount == 0){
    cout << "No books in inventory\n";
    return;
  }

  for(int i=0; i<bookCount; i++){
    cout << i+1 << ". " << books[i].title << " by " << books[i].author << endl
    << " ISBN: " << books[i].ISBN
    << " | Price: RM" << books[i].price
    << " | Stock: " << books[i].stock << endl;
  }

}

int searchBook(const book books[], int bookCount, string keyword){
  for(int i=0; i<bookCount; i++){
    if(books[i].ISBN == keyword || books[i].title == keyword){
      cout << "\nBook found: \n";
      cout << "Title: " << books[i].title << endl;
      cout << "Author: " << books[i].author << endl;
      cout << "Price: RM" << books[i].price << endl;
      cout << "Stock: " << books[i].stock << endl;
      return i;
    }
  }

  cout << "Book not found\n";
  return -1;
}
