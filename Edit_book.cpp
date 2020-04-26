
#include "Book.h"
// Friend Function
void edit_book(Book book) {
  int getid, ch1;
  bool filecheck, found = false;
  // Temp File created to hold every Data and renamed later
  ofstream temp;
  temp.open("temp.txt");

  ifstream book_file;
  book_file.open("Book.txt");
  // Check if both files are good
  if (book_file) {
    if (temp) {
      filecheck = true;
    }
  }
  if (filecheck) {
    // User Entry to Edit Specific Book
    cout << "Enter Book ID to be edited: ";
    cin >> getid;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (!book_file.eof()) {
      getline(book_file, book.name, '\t');
      getline(book_file, book.author, '\t');
      book_file >> book.id >> book.count;
      if (book.id == getid) {
        found = true;
        cout << "Book Title: " << book.name;

        cout << endl;
        // Edit Menu Option Display
        cout << "1.Edit Book Title" << endl;
        cout << "2.Edit Count" << endl;
        cout << "3.Edit Author Last Name " << endl;

        cout << "\nYour Choice: ";
        cin >> ch1;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (ch1) {
          case 1:
            // Changes Value of Title
            cout << "\nEnter New Book Title: ";
            cin >> book.name;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // Display
            cout << "Section Edited Book ID: " << book.id << endl;
            break;
          case 2:
            // Changes Value of Count
            cout << "\nEnter New Book Quantity: ";
            cin >> book.count;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Section Edited Book ID: " << book.id << endl;
            break;
          case 3:
            cout << "\nEnter New Author Name: ";
            cin >> book.author;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Section Edited Book ID: " << book.id << endl;
            break;
          default:
            cout << "\nIncorrect Choice. Edit Section Failed." << endl;
            break;
        }
      }

      // Feed Info from Book File to temp File. Done after switch runs. Hence
      // Regardless if found, all book data is thrown to temp file during the
      // loop.
      temp << book.name;
      temp << "\t";
      temp << book.author;
      temp << "\t";
      temp << book.id;
      temp << " ";
      temp << book.count;
      temp.close();
      book_file.close();
    }
    // Found Check
    if (!found) {
      cout << "\nBook Not Found" << endl;
    }
    // Remove orginal File as the edit has not been applied
    remove("Book.txt");
    // Rename as Edit is stored in temp file
    rename("temp.txt", "Book.txt");
  } else {
    cout << "Error. Try again later." << endl;
  }
}