#include "Book.h"

vector<int> Book::operator+(const Book& book) {
  ifstream input_file;
  int ID;
  input_file.open("Book.txt");
  if (input_file) {
    while (!input_file.eof()) {
      getline(input_file, name, '\t');
      getline(input_file, author, '\t');
      input_file >> id >> count;

      bookID.push_back(id);
    }
  }
  return bookID;
}
void Book::borrow_book() {
  cout << "\nDo you want to display the books available at the Library?(y/n)";
  char ch;
  cin >> ch;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  if (ch == 'y') {
    cout << "\nDisplaying the available books for reference" << endl;
    display();
  }
  int bookcode, memcode, mid, mage;
  bool found = false, filecheck;
  string mname, mbook, bookcheck = "Nill";
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
      getline(book_file, name, '\t');
      getline(book_file, author, '\t');
      book_file >> id >> count;
      if (id == bookcode) {
        found = true;
        if (count > 0) {
          cout << "\nBook ID: " << id << "\nTitle: " << name
               << " is available on a loan for 3 hours";
          cout << "\nDo you want to borrow " << name << " ?";
          cin >> ch;
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
          cout << "\nBook out of stock" << endl;
          break;
        }
        if (ch == 'y') {
          count--;
          cout << "Enter Member ID: ";
          cin >> memcode;
          while (!member_file.eof()) {
            getline(member_file, mname, '\t');
            getline(member_file, mbook, '\t');
            member_file >> mid >> mage;
            if (memcode == mid) {
              if ((mid < 5000 && bookcode < 5000) ||
                  (mid >= 5000 && bookcode >= 5000)) {
                if (mbook.compare(bookcheck) == 0) {
                  cout << "Member Found!" << endl;
                  cout << "\nMember " << mid << "\nName: " << mname << endl;
                  cout << "\nBook : " << name << " has been issued to " << mname
                       << endl;
                  mbook = name;
                } else {
                  cout << mname << " has already borrowed " << mbook;
                  cout << "Do you want to return " << mbook
                       << " and return back to this section?(y/n) ";
                  cin >> ch;
                  if (ch == 'y') {
                    return_book();
                  }
                }
              } else {
                cout << "\nBook reserved for alternate degree seeking student."
                     << endl;
              }
            }
          }

          temp2 << mname;
          temp2 << "\t";
          temp2 << mbook;
          temp2 << "\t";
          temp2 << mid;
          temp2 << " ";
          temp2 << mage;
        }
        member_file.close();
        temp2.close();
      }
      temp1 << name;
      temp1 << "\t";
      temp1 << author;
      temp1 << "\t";
      temp1 << id;
      temp1 << " ";
      temp1 << count;
    }
  } else {
    cout << "Error. Try again Later." << endl;
  }
  if (!found) {
    cout << "\nUser Not Found" << endl;
  }
  book_file.close();
  temp1.close();
  remove("Members.txt");
  remove("Book.txt");
  rename("temp1.txt", "Book.txt");
  rename("temp2.txt", "Members.txt");
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

  string memname, membook, bookcheck = "Nill";

  bool filecheck, found = false;
  int memid, memage;
  char ch;

  int member_id;
  cout << "Enter 4-digit code of user initiate return process: ";
  cin >> member_id;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
      getline(member_file, memname, '\t');
      getline(member_file, membook, '\t');
      member_file >> memid >> memage;
      if (memid == member_id) {
        found = true;
        if (membook.compare(bookcheck) != 0) {
          cout << "\nMember: " << name << " borrowed " << membook << endl;
          cout << "Return " << membook << " ?(y/n) ";
          cin >> ch;
          if (ch == 'y') {
            while (!book_file.eof()) {
              getline(book_file, name, '\t');
              getline(book_file, author, '\t');
              book_file >> id >> count;
              if (membook.compare(name) == 0) {
                count++;
                cout << "\nBook returned" << endl;
                membook = bookcheck;
              }

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
          cout << "\nMember not issued any book" << endl;
        }
      }
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
  } else {
    cout << "Error. Try again later" << endl;
  }
  if (!found) {
    cout << "\nUser Not Found" << endl;
  }
}

void Book::remove_book() {
  char ch;
  cout << "Do you want to display the list books? (y,n)";
  cin >> ch;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  if (ch == 'y') {
    display();
  }
  cout << "\nEnter code of book intending to delete from database: ";
  int bookcode;
  cin >> bookcode;
  bool filecheck;
  ofstream temp1;
  temp1.open("temp.txt");
  ifstream input_file;
  input_file.open("Book.txt");
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
          cout << name << " Erased from Library" << endl;
          continue;
        }
      }
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
  }
}

void Book::display() {
  ifstream input_file;
  input_file.open("Book.txt");

  cout << "=======================================================" << endl;
  cout << "ID\t BOOK TITLE\t\tAUTHOR\t\tQUANTITY" << endl;
  cout << "=======================================================" << endl;

  if (input_file) {
    while (!input_file.eof()) {
      getline(input_file, name, '\t');
      getline(input_file, author, '\t');
      input_file >> id >> count;
      cout << left << setw(10) << id << left << setw(22) << name << left
           << setw(19) << author << left << setw(10) << count;
      cout << "\n-------------------------------------------------------"
           << endl;
    }
    input_file.close();
  } else {
    cout << "Error" << endl;
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

      ofile << name;
      ofile << "\t";
      ofile << author;
      ofile << "\t";
      ofile << id;
      ofile << " ";
      ofile << count;

      ofile.close();
    }
  }
}
void Book::set_BookID() {
  srand(time(nullptr));
  Book b1, b2;
  vector<int> IDs;
  IDs = b1 + b2;

  while (true) {
    cout << "Is the following book intended for an undergraduate student "
            "(y/n): ";
    char ch;
    cin >> ch;
    while (true) {
      if (ch == 'y') {
        id = rand() % 4000 + 1000;

      } else if (ch == 'n') {
        id = rand() % 5000 + 5000;
      } else {
        cout << "Invalid Choice.";
      }
      int i, found = 0, n = IDs.size();
      for (i = 0; i < n; i++) {
        if (id == IDs[i]) {
          found = 1;
        }
      }
      if (found == 0 || n == 0) {
        break;
      }
    }
    break;
  }
}