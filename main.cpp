#include "Book.h"
#include "Graduate.h"
#include "Member.h"
#include "Undergraduate.h"

int main(void) {
  Book b;
  Member m;
  Undergraduate ug;
  Graduate grad;
  bool mainchoice = true;
  while (mainchoice == true) {
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

    if (ch == 1) {
      cout << "\n1: Enter a new member";
      cout << "\n2: Display current "
              "members";
      cout << "\n3: Edit the details of an existing member";
      cout << "\n4: Remove a member";
      cout << "5. Exit section" << endl;
      int memch;
      cout << "\nEnter your choice: ";
      cin >> memch;

      if (memch == 1) {
        b.input();

      } else if (memch == 2) {
        cout << "1. Display all Members" << endl;
        cout << "2.Display Undergraduate Members" << endl;
        cout << "3. Display Graduate Members" << endl;
        cout << "4. Exit section" << endl;
        int disch;
        cout << "Display choice: ";
        cin >> disch;
        if (disch == 1) {
          b.display();
        } else if (disch == 2) {
          ug.stddisplay();
        } else if (disch == 3) {
          grad.grad_display();
        }
      } else if (memch == 4) {
        cout << "Section exit" << endl;
      }
    }
  }
}

void edit_book(Book book) {
  int getid, found = 0, n = 0, i, pos;
  vector<string> bookname;
  vector<string> bookauthor;
  vector<int> bookcount;
  vector<int> bookID;
  cout << "Enter ID of Book to be edited:";
  cin >> getid;
  ifstream input_file;

  input_file.open("Book.txt");
  if (input_file) {
    while (input_file >> book.id >> book.name >> book.author >> book.count) {
      bookID.push_back(book.id);
      if (getid == book.id) {
        pos = n;
        found = 1;

        bookname.push_back(book.name);
        bookauthor.push_back(book.author);
        bookcount.push_back(book.count);
        n++;
      }
    }

    if (found == 1) {
      cout << "Do you want to edit the book title ?(y/n)";
      char ch;
      cin >> ch;
      if (ch == 'y') {
        cout << "Enter new title: ";
        cin >> bookname[pos];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      } else {
        cout << endl;
      }
      cout << "Do you want to edit your age?(y/n)";

      cin >> ch;
      if (ch == 'y') {
        cout << "\nEdit author name:";
        cin >> bookauthor[pos];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      } else {
        cout << endl;
      }
      cout << "Do you want to update the stock?(y/n)";

      cin >> ch;
      if (ch == 'y') {
        cout << "\nEnter new count value:";
        cin >> bookcount[pos];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      } else {
        cout << endl;
      }
    } else {
      cout << "Member not found";
    }
  }

  input_file.close();
  ofstream up_file;
  up_file.open("Book.txt");
  for (i = 0; i < n; i++) {
    up_file << bookID[i];
    up_file << bookname[i];
    up_file << bookauthor[i];
    up_file << bookcount[i];
    up_file << endl;
  }
  up_file.close();
}