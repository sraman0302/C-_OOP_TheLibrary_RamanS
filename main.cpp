#include "Book.h"
#include "Graduate.h"
#include "Member.h"
#include "Undergraduate.h"
int main(void) {
  // Main Menu
  while (true) {
    // Declare Object
    Book b;
    Member m;
    Undergraduate ug;
    Graduate grad;
    cout << endl << endl;
    // Display
    cout << "==============================" << endl;
    cout << "\t  Main Menu" << endl;
    cout << "==============================" << endl;
    cout << "1. Library Members" << endl;
    cout << "2. Library Books" << endl;
    cout << "3. Exit the menu" << endl;
    cout << "\nEnter your choice: ";
    int ch;
    cin >> ch;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Member Menu

    if (ch == 1) {
      int memch;

      // Display Member Menu Options

      cout << "\n1: Enter a new member";
      cout << "\n2: Display current "
              "members";
      cout << "\n3: Edit the details of an existing member";
      cout << "\n4: Remove a member";
      cout << "\n5. Information Access";
      cout << "\n6. Exit section" << endl;
      cout << "\nEnter your choice: ";

      cin >> memch;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      // Input function call in Member Class

      if (memch == 1) {
        m.input();

      } else if (memch == 2) {  // Display Function Menu
        int disch;
        cout << "1. Display all Members" << endl;
        cout << "2.Display Undergraduate Members" << endl;
        cout << "3. Display Graduate Members" << endl;
        cout << "4. Exit section" << endl;

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
      } else if (memch == 3) {  // Member Choice #3 - Edit Members
        int edch;

        cout << "1. Edit Undergradute Member" << endl;
        cout << "2. Edit Graduate Members" << endl;
        cout << "3. Exit section" << endl;
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
      } else if (memch == 4) {  // Remove Member Menu
        int remch;

        cout << "1. Remove Undergradute Member" << endl;
        cout << "2. Remove Graduate Member" << endl;
        cout << "3. Exit section" << endl;
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
      } else if (memch ==
                 5) {  // Static Function and Overloading Operator Usage Menu
        cout << "\n1.View Member ID's" << endl;
        cout << "2.View Amount of Members created in this run" << endl;
        int acc_ch, i;
        char ch1;
        cout << "Enter your choice: ";
        cin >> acc_ch;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (acc_ch == 1) {
          cout << "The following contains senstive information. Do you still "
                  "want to view the ID's?(y/n) ";
          cin >> ch1;
          cin.ignore(numeric_limits<streamsize>::max(), '\n');

          if (ch1 == 'y') {
            vector<int> ID;
            Member m1, m2;  // Operator Overloading
            ID = m1 + m2;
            int size = ID.size();

            cout << "\nMember's ID:" << endl;
            cout << "-------------" << endl;
            for (i = 0; i < size; i++) {
              cout << i + 1 << ". " << ID[i] << endl;
            }

          } else {
            cout << "\nAccess Menu Exit";
          }
        } else if (acc_ch == 2) {
          int count_newmembers;
          count_newmembers = m.member_count();  // Static Member Usage
          cout << "Number of New Members Welcomed Today: " << count_newmembers
               << endl;
        }

        else {
          cout << "\nInvalid choice" << endl;
        }

      } else if (memch == 6) {
        cout << "\nMember Section Exit" << endl;
      } else {
        cout << "\nInvalid Choice" << endl;
      }
    } else if (ch == 2) {  // Book Menu
      int bookch;

      cout << "\n1. Display books with details" << endl;
      cout << "2: Borrow a book" << endl;
      cout << "3: Return a book" << endl;
      cout << "4. Add a book" << endl;
      cout << "5. Remove a book" << endl;
      cout << "6. Edit the details of a book" << endl;
      cout << "7. Access Information" << endl;
      cout << "8. Exit section" << endl;
      cout << "Enter your choice: ";
      cin >> bookch;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      if (bookch == 1) {
        b.display();
      } else if (bookch == 2) {
        b.borrow_book();
      } else if (bookch == 3) {
        b.return_book();
        remove("temp.txt");
      } else if (bookch == 4) {
        b.input();
      } else if (bookch == 5) {
        b.remove_book();

      } else if (bookch == 6) {
        edit_book(b);

      } else if (bookch == 7) {  // Operator Overloading
        int info_ch;
        cout << " Information Access." << endl;
        cout << "\n1. View Book ID's" << endl;
        cout << "2. Exit Section" << endl;
        cout << "Enter Choice: ";
        cin >> info_ch;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (info_ch == 1) {
          Book b1, b2;
          vector<int> book;
          book = b1 + b2;  // Operator Overloading
          int i, size;
          size = book.size();
          cout << "\n   ID" << endl;
          cout << "----------" << endl;
          for (i = 0; i < size; i++) {
            cout << i + 1 << ". " << book[i] << endl;
          }
        } else if (info_ch == 2) {
          cout << "\nExit Section" << endl;
        } else {
          cout << "Invalid Choice" << endl;
        }
      }

      else if (bookch == 8) {
        cout << "Exit section" << endl;
      } else {
        cout << "Invalid Choice" << endl;
      }
    } else if (ch == 3) {
      cout << "Thanks for using the Library" << endl;

      cout << "Exit Library.\nBYE! " << endl;
      break;
    } else {
      cout << "Invalid choice" << endl;
    }
  }
  return 0;
}

// Friend Function
void edit_book(Book book) {
  int getid, ch1;
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
