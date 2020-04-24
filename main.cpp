#include "Book.h"
#include "Graduate.h"
#include "Member.h"
#include "Undergraduate.h"
int main(void) {
  while (true) {
    Book b;
    Member m;
    Undergraduate ug;
    Graduate grad;
    cout << endl << endl;
    cout << "==============================" << endl;
    cout << "\t  Main Menu" << endl;
    cout << "==============================" << endl;
    cout << "1. Library Members" << endl;
    cout << "2. Library Books" << endl;
    cout << "3. Exit the menu" << endl;
    cout << "Enter your choice: ";
    int ch;
    cin >> ch;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (ch == 1) {
      cout << "\n1: Enter a new member";
      cout << "\n2: Display current "
              "members";
      cout << "\n3: Edit the details of an existing member";
      cout << "\n4: Remove a member";
      cout << "\n5. Exit section" << endl;
      int memch;
      cout << "\nEnter your choice: ";
      cin >> memch;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      if (memch == 1) {
        m.input();

      } else if (memch == 2) {
        cout << "1. Display all Members" << endl;
        cout << "2.Display Undergraduate Members" << endl;
        cout << "3. Display Graduate Members" << endl;
        cout << "4. Exit section" << endl;
        int disch;
        cout << "Display choice: ";
        cin >> disch;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (disch == 1) {
          m.display();
        } else if (disch == 2) {
          ug.stddisplay();
        } else if (disch == 3) {
          grad.grad_display();
        } else if (disch == 4) {
          cout << "Section exit" << endl;
        } else {
          cout << "Incorrect Choice" << endl;
        }
      } else if (memch == 3) {
        cout << "1. Edit Undergradute Member" << endl;
        cout << "2. Edit Graduate Members" << endl;

        cout << "3. Exit section" << endl;
        int edch;
        cout << "Edit Menu choice: ";
        cin >> edch;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (edch == 1) {
          ug.edit_std();
        } else if (edch == 2) {
          grad.edit_grad();
        } else if (edch == 3) {
          cout << "Section exit" << endl;
        } else {
          cout << "Incorrect Choice" << endl;
        }
      } else if (memch == 4) {
        cout << "1. Remove Undergradute Member" << endl;
        cout << "2. Remove Graduate Member" << endl;

        cout << "3. Exit section" << endl;
        int remch;
        cout << "Remove Menu choice: ";
        cin >> remch;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (remch == 1) {
          ug.remove_member();
        } else if (remch == 2) {
          grad.remove_gradmember();
        } else if (remch == 3) {
          cout << "Section exit" << endl;
        } else {
          cout << "Incorrect Choice" << endl;
        }
      } else if (memch == 5) {
        cout << "\nMember Section Exit" << endl;
      } else {
        cout << "\nInvalid Choice" << endl;
      }
    } else if (ch == 2) {
      cout << "\n1. Display books with details" << endl;
      cout << "2: Borrow a book" << endl;
      cout << "3: Return a book" << endl;
      cout << "4. Add a book" << endl;
      cout << "5.Remove a book" << endl;
      cout << "6.Edit the details of a book" << endl;
      cout << "7. Exit section" << endl;
      int bookch;
      cout << "Enter your choice: ";
      cin >> bookch;
      if (bookch == 1) {
        b.display();

      } else if (bookch == 2) {
        b.borrow_book();
      } else if (bookch == 3) {
        b.return_book();
      } else if (bookch == 4) {
        b.input();
      } else if (bookch == 5) {
        b.remove_book();

      } else if (bookch == 6) {
        edit_book(b);
      } else if (bookch == 7) {
        cout << "Exit section" << endl;
      } else {
        cout << "Invalid Choice" << endl;
      }
    } else if (ch == 3) {
      cout << "Exit Library " << endl;
      break;
    } else {
      cout << "Invalid choice" << endl;
    }
  }
  return 0;
}

void edit_book(Book book) {
  char ch;
  int getid;
  bool filecheck;
  ofstream temp;
  temp.open("temp.txt");
  ifstream book_file;
  book_file.open("Book.txt");
  if (book_file) {
    if (temp) {
      filecheck = true;
    }
  }
  if (filecheck) {
    cout << "Enter Book ID to be edited: ";
    cin >> getid;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (book_file >> book.id >> book.name >> book.count >> book.author) {
      if (book.id == getid) {
        cout << "Book Title: " << book.name;

        cout << endl;
        int ch1;
        cout << "1.Edit Book Title" << endl;
        cout << "2.Edit Count" << endl;
        cout << "3.Edit Author Last Name " << endl;

        cout << "\nYour Choice: ";
        cin >> ch1;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (ch1) {
          case 1:
            cout << "\nEnter New Book Title: ";
            cin >> book.name;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Section Edited Book ID: " << book.id << endl;
            break;
          case 2:
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
      temp << book.id;
      temp << " ";
      temp << book.name;
      temp << " ";
      temp << book.count;
      temp << " ";
      temp << book.author;
      temp << endl;
      temp.close();
      book_file.close();
    }
    remove("Book.txt");
    rename("temp.txt", "Book.txt");
  } else {
    cout << "Error. Try again later." << endl;
  }
}
