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
void buyBook(book books[], int &bookCount);
       
   
int main(){
  book books[100];
  int bookCount = 0;

  int choice;

    do {
        cout << "\n----- Bookstore Inventory and Sales System -----";
        cout << "\n1. Add A New Book";
        cout << "\n2. Display All Books Available";
        cout << "\n3. Search for A Book";
        cout << "\n4. Buy A Book";
        cout << "\n5. Show Sales Report";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(book books[], int &bookCount); break;
            case 2: displayBooks(const book books[], int bookCount); break;
            case 3: searchBook(const book books[], int bookCount, string keyword); break;
            case 4: buyBook(book books[], int &bookCount); break;
            case 5: showReport(); break;
            case 6: cout << "\nExiting program..."; break;
            default: cout << "\nInvalid choice. Try again.";
        }
         } while (choice != 6);

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

void buyBook(book books[], int &bookCount){
    
    cout << "----- Purchase Book -----\n";
    if (bookCount == 0){
      cout << "No books available to purchase.\n";
      return;
      
    }
    string isbn;
  cout << "Enter ISBN of the book to buy: ";
  getline(cin, isbn);
    int index = searchBook(books, bookCount, isbn);
    if (index == -1){ 
      cout << "Cannot process purchase.\n"; 
      return;
      
    }
    int quantity; 
  cout << "Enter quantity to buy: ";
  cin >> quantity;
  cin.ignore();
    if (quantity <= 0){
      cout << "Invalid quantity.\n";
      return;
      
    }
    if (quantity > books[index].stock){
      cout << "Stock not enough! Available: "<<books[index].stock<<"\n";
      return;
      
    }
    double totalPrice = quantity * books[index].price;
    books[index].stock -= quantity;
    cout << "\nPurchase Successful!\n";
    cout << "You bought: " << books[index].title << "\n";
    cout << "Quantity: " << quantity << "\n";
    cout << "Total Price: RM" << fixed << setprecision(2) << totalPrice << "\n";
    cout << "Remaining Stock: " << books[index].stock << "\n";
}


