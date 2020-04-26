#include "Book.h"
// Book Menu
void Book::display() {
  ifstream input_file;
  input_file.open("Book.txt");

  // Display Format

  cout << "===================================================================="
          "================="
          "===="
       << endl;
  cout << "ID\t\t\tBOOK TITLE\t\t\t\tAUTHOR\t\tQUANTITY" << endl;
  cout << "===================================================================="
          "================="
          "===="
       << endl;

  if (input_file) {
    while (!input_file.eof()) {
      // Retrieve Prior Information from .txt File

      getline(input_file, name, '\t');
      getline(input_file, author, '\t');
      input_file >> id >> count;

      // Adequate Spacing being made for better Tabular Representation

      cout << left << setw(10) << id << left << setw(50) << name << left
           << setw(20) << author << left << setw(10) << count;
      cout << "\n--------------------------------------------------------------"
              "-------------------------"
           << endl;
    }
    input_file.close();
  } else {
    throw runtime_error("\nError! Unable to open Essential files\n ");
  }
}

void Book::borrow_book() {
  cout << "\nDo you want to display the books available at the Library?(y/n)";
  char ch;
  cin >> ch;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  if (ch == 'y') {
    cout << "\nDisplaying the available books for reference" << endl;
    display();  // Calls The Display Function
  }
  int bookcode, memcode, mage;
  bool found = false, filecheck;
  string mbook, bookcheck = "Nil";

  cout << "\nEnter code of book intending to borrow for 3 hours (Limit 1 per "
          "user) ";
  cin >> bookcode;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  ofstream temp1;
  temp1.open("temp1.txt");

  ifstream book_file;
  book_file.open("Book.txt");

  ofstream temp2;
  temp2.open("temp2.txt");

  ifstream member_file;
  member_file.open("Members.txt");

  if (book_file.is_open()) {
    if (member_file.is_open()) {
      if (temp1.is_open()) {
        if (temp2.is_open()) {
          filecheck = true;
        }
      }
    }
  }

  if (filecheck) {
    while (!book_file.eof()) {
      // Retrieve Information
      getline(book_file, name, '\t');
      getline(book_file, author, '\t');
      book_file >> id >> count;
      // Check ID Match
      if (id == bookcode) {
        found = true;
        if (count > 0) {
          cout << "\nBook ID: " << id << "\nTitle: " << name
               << " is available on a loan for 3 hours";
          cout << "\nDo you want to borrow " << name << " ?";
          cin >> ch;
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {  // If Count is Zero. Book Cannot Be Borrowed
          cout << "\nBook out of stock" << endl;
          break;
        }
        if (ch == 'y') {
          cout << "Enter Member ID: ";
          cin >> memcode;
          cin.ignore(numeric_limits<streamsize>::max(), '\n');

          // Retrieve Information
          while (!member_file.eof()) {
            getline(member_file, memname, '\t');
            getline(member_file, mbook, '\t');
            member_file >> memid >> mage;
            // Member ID Matches
            if (memcode == memid) {
              // Check if Book would be borrowed to adequate Classmen/Degree
              // Student
              if ((memid < 5000 && bookcode < 5000) ||
                  (memid >= 5000 && bookcode >= 5000)) {
                // Checking if User has no Book Borrowed Previously i.e. Nil
                if (mbook.compare(bookcheck) == 0) {
                  cout << "Member Found!" << endl;
                  cout << "\nMember " << memid << "\nName: " << memname << endl;
                  cout << "\nBook : " << name << " has been issued to "
                       << memname << endl;
                  count--;  // Decrease Count Value by 1

                  mbook = name;  // Storing Book name to Member Book to be saved
                                 // Later
                } else {         // User has a book borrowed
                  cout << memname << " has already borrowed " << mbook << endl;
                  cout << "Please return " << mbook << " to rent " << name
                       << " for 3 hours." << endl;
                }
              } else {
                cout << "\nBook reserved for alternate degree seeking student."
                     << endl;  // If book,member ID is out of bound
              }
            }
            // Store Member ID Regardless
            temp2 << memname;
            temp2 << "\t";
            temp2 << mbook;
            temp2 << "\t";
            temp2 << memid;
            temp2 << " ";
            temp2 << mage;
          }
        }
        // Close Member and Member-Temp File
        member_file.close();
        temp2.close();
      }
      // Store Book Data Regardless
      temp1 << name;
      temp1 << "\t";
      temp1 << author;
      temp1 << "\t";
      temp1 << id;
      temp1 << " ";
      temp1 << count;
    }
    // Book and Temp Book File Closed
    book_file.close();
    temp1.close();
    // Delete Previous Member and Book Files
    remove("Members.txt");
    remove("Book.txt");
    // Rename Temp as it holds new Information for Book and Member
    rename("temp1.txt", "Book.txt");
    rename("temp2.txt", "Members.txt");
    if (!found) {
      cout << "\n\t\tRecord Not Found" << endl;
    }
  } else {
    throw runtime_error("\nError! Unable to open Essential files\n ");
  }
}

void Book::return_book() {
  ofstream temp1;
  temp1.open("temp.txt");

  ofstream temp2;
  temp2.open("temp2.txt");

  ifstream member_file;
  member_file.open("Members.txt");

  ifstream book_file;
  book_file.open("Book.txt");

  string membook, bookcheck = "Nil";

  bool filecheck, found = false;
  int memage;
  char ch;

  int member_id;
  cout << "Enter 4-digit code of user initiate return process: ";
  cin >> member_id;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  // File Status Check
  if (book_file.is_open()) {
    if (member_file.is_open()) {
      if (temp1.is_open()) {
        if (temp2.is_open()) {
          filecheck = true;
        }
      }
    }
  }

  if (filecheck) {
    while (!member_file.eof()) {
      // Retrieve Data
      getline(member_file, memname, '\t');
      getline(member_file, membook, '\t');
      member_file >> memid >> memage;
      // If Match
      if (memid == member_id) {
        found = true;
        // Check if User Has a Book Borrowed
        if (membook.compare(bookcheck) != 0) {
          cout << "\nMember: " << memname << " borrowed " << membook << endl;
          cout << "Return " << membook << " ?(y/n) ";
          cin >> ch;
          if (ch == 'y') {
            // Load Book Data
            while (!book_file.eof()) {
              getline(book_file, name, '\t');
              getline(book_file, author, '\t');
              book_file >> id >> count;
              // Match Book Name in Library and User Borrowed Book
              if (membook.compare(name) == 0) {
                count++;  // Increment by 1 for Quantity
                cout << "\nBook returned" << endl;
                membook = bookcheck;  // Reset User Borrowed Book to Nil
              }

              // Store Data in Temp File
              temp1 << name;
              temp1 << "\t";
              temp1 << author;
              temp1 << "\t";
              temp1 << id;
              temp1 << " ";
              temp1 << count;
            }
            temp1.close();
            book_file.close();
            remove("Book.txt");
            rename("temp.txt", "Book.txt");
          }
        } else {
          cout << "\n" << memname << " not issued any book" << endl;
        }
      }
      // Store Member Data in Temp
      temp2 << memname;
      temp2 << "\t";
      temp2 << membook;
      temp2 << "\t";
      temp2 << memid;
      temp2 << " ";
      temp2 << memage;
    }
    temp2.close();
    member_file.close();
    remove("Members.txt");
    rename("temp2.txt", "Members.txt");

    if (!found) {
      cout << "\nUser Not Found" << endl;
    }
  } else {
    throw runtime_error("\nError! Unable to open Essential files\n ");
  }
}

void Book::input() {
  ofstream ofile;
  ofile.open("Book.txt", ios::app);
  if (ofile) {
    set_BookID();
    if (id != 0) {
      cout << "Unique ID Code: " << id << endl;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      cout << "Enter Book Title:";
      getline(cin, name);

      cout << "Enter Author's Name: ";

      getline(cin, author);

      cout << "\nEnter Quantity: ";
      cin >> count;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      // Store Data in Book File
      ofile << name;
      ofile << "\t";
      ofile << author;
      ofile << "\t";
      ofile << id;
      ofile << " ";
      ofile << count;

      ofile.close();
    }
  } else {
    throw runtime_error("\nError! Unable to open Essential files\n ");
  }
}
void Book::set_BookID() {
  srand(time(nullptr));
  // Operator Overloading
  Book b1, b2;
  vector<int> IDs;
  IDs = b1 + b2;

  while (true) {
    cout << "Is the following book intended for an undergraduate student "
            "(u/g): ";
    char ch;
    cin >> ch;
    ch = tolower(ch);  // Support U/G Entry
    while (true) {
      if (ch == 'u') {
        id = rand() % 4000 + 1000;

      } else if (ch == 'g') {
        id = rand() % 5000 + 5000;
      } else {
        cout << "Invalid Choice.";
        cout << "Enter U/G only";
        cin >> ch;
        ch = tolower(ch);
        continue;
      }
      int i, found = 0, n = IDs.size();
      for (i = 0; i < n; i++) {
        if (id == IDs[i]) {
          found = 1;  // Reiterates if Duplication is Found
        }
      }
      if (found == 0 || n == 0) {
        break;  // Breaks if ID is Unique
      }
    }
    break;
  }
}

void Book::remove_book() {
  char ch;
  cout << "Do you want to display the list books? (y,n)";
  cin >> ch;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  if (ch == 'y') {
    display();  // Display Function Called
  }
  cout << "\nEnter code of book intending to delete from database: ";
  int bookcode;
  cin >> bookcode;
  bool filecheck;

  ofstream temp1;
  temp1.open("temp.txt");

  ifstream input_file;
  input_file.open("Book.txt");
  // File Status Check
  if (input_file) {
    if (temp1) {
      filecheck = true;
    }
  }

  if (filecheck) {
    while (!input_file.eof()) {
      getline(input_file, name, '\t');
      getline(input_file, author, '\t');
      input_file >> id >> count;
      if (id == bookcode) {
        cout << "\nFound." << endl;
        cout << "Book ID: " << id << endl;
        cout << "Title: " << name << endl;
        cout << "Do you want to Erase this Book from the library? (This "
                "process cannot be reversed)(y/n)";
        cin >> ch;
        if (ch == 'y') {
          // Skips Iteration if Remove
          cout << name << " Erased from Library" << endl;
          continue;
        }
      }
      // Store Regardless
      temp1 << name;
      temp1 << "\t";
      temp1 << author;
      temp1 << "\t";
      temp1 << id;
      temp1 << " ";
      temp1 << count;
    }
    input_file.close();
    temp1.close();
    remove("Book.txt");
    rename("temp.txt", "Book.txt");
  } else {
    throw runtime_error("\nError! Unable to open Essential files\n ");
  }
}

vector<int> Book::operator+(const Book& book) {
  ifstream input_file;
  input_file.open("Book.txt");
  if (input_file) {
    while (!input_file.eof()) {
      // Retrieve Data
      getline(input_file, name, '\t');
      getline(input_file, author, '\t');
      input_file >> id >> count;

      bookID.push_back(id);
    }
  } else {
    throw runtime_error("\nError! Unable to open Essential files\n ");
  }
  return bookID;
}

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