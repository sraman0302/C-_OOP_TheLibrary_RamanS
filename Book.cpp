#include "Book.h"

vector<int> Book::operator+(const Book& book) {
  ifstream input_file;
  int ID;
  input_file.open("Members.txt");
  if (input_file) {
    while (input_file >> ID) {
      bookID.push_back(ID);
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
  bool found, filecheck;
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
    while (book_file >> id >> name >> count >> author) {
      if (id == bookcode) {
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
          while (member_file >> mid >> mname >> mage >> mbook) {
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

          temp2 << mid;
          temp2 << " ";
          temp2 << mname;
          temp2 << " ";
          temp2 << mage;
          temp2 << " ";

          temp2 << mbook;
          temp2 << endl;
        }
        member_file.close();
        temp2.close();
      }
      temp1 << id;
      temp1 << " ";
      temp1 << name;
      temp1 << " ";
      temp1 << count;
      temp1 << " ";
      temp1 << author;
      temp1 << endl;
    }
  } else {
    cout << "Error. Try again Later." << endl;
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

  bool filecheck;
  int memid, memage;
  char ch;

  int found = 0, pos, n = 0, member_id;
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
    while (member_file >> memid >> memname >> memage >> membook) {
      if (memid == member_id) {
        if (membook.compare(bookcheck) != 0) {
          cout << "\nMember: " << name << " borrowed " << membook << endl;
          cout << "Return " << membook << " ?(y/n) ";
          cin >> ch;
          if (ch == 'y') {
            while (book_file >> id >> name >> count >> author) {
              if (membook.compare(name) == 0) {
                count++;
                cout << "\nBook returned" << endl;
                membook = bookcheck;
              }
              temp1 << id;
              temp1 << " ";
              temp1 << name;
              temp1 << " ";
              temp1 << count;
              temp1 << " ";
              temp1 << author;
              temp1 << endl;
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
      temp2 << memid;
      temp2 << " ";
      temp2 << memname;
      temp2 << " ";
      temp2 << memage;
      temp2 << " ";
      temp2 << membook;
      temp2 << endl;
    }
    temp2.close();
    member_file.close();
    remove("Members.txt");
    rename("temp2.txt", "Members.txt");
  } else {
    cout << "Error. Try again later" << endl;
  }
}

void Book::remove_book() {
  char ch;
  cout << "Do you want to display the list books? (y,n)";
  cin >> ch;
  if (ch == 'y') {
    display();
  }
  cout << "\nEnter code of book intending to delete from database: ";
  int bookcode, bookpos, found;
  cin >> bookcode;

  ifstream input_file;
  input_file.open("Book.txt");
  vector<string> book_name;
  vector<int> book_code;
  vector<string> author_name;
  vector<int> book_quant;
  int m;
  if (input_file) {
    found = 0;
    while (input_file >> id >> name >> author >> count) {
      if (id == bookcode) {
        bookpos = m;
        found = 1;
        cout << "\nBook Record Found" << endl;
        cout << "Book ID: " << id << endl;
        cout << "Book Title" << name << endl;
        cout << "Book Author" << author << endl;
        cout << "Do you want to Erase Book " << id
             << "?\nhis process "
                "cannot be reversed(y/n): ";
        cin >> ch;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (ch == 'y') {
          cout << "Book " << id << " Deleted" << endl;
          continue;
        } else if (ch == 'n') {
          cout << "Not Deleted" << endl;
        } else {
          cout << "Error." << endl;
        }
      }
      book_name.push_back(name);
      book_quant.push_back(count);
      book_code.push_back(id);
      author_name.push_back(author);
      m++;
    }
    input_file.close();
  }

  ofstream book_update;
  book_update.open("Book.txt");
  if (book_update) {
    int i;
    for (i = 0; i < m; i++) {
      book_update << book_code[i];
      book_update << book_name[i];
      book_update << author_name[i];
      book_update << book_quant[i];
      book_update << endl;
    }
    book_update.close();
  }
}

void Book::display() {
  ifstream input_file;
  input_file.open("Book.txt");

  cout << "====================================" << endl;
  cout << "ID\t BOOK TITLE\tQUANTITY\tAUTHOR" << endl;
  cout << "====================================" << endl;
  if (input_file) {
    while (input_file >> id >> name >> count >> author) {
      cout << id << '\t' << name << '\t' << count << '\t' << author << '\n';
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
      cout << "Book ID: " << id;
      ofile << id;
      ofile << " ";
      cout << "Enter Book title:";
      cin >> name;

      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      ofile << name;
      ofile << " ";
      cout << "Enter Quantity to be stored: ";
      cin >> count;
      ofile << count;
      ofile << " ";
      cout << "Enter Author Last Name: ";
      cin >> author;
      ofile << author;
      ofile << " ";
      ofile << endl;
    }
  }
}
void Book::set_BookID() {
  srand(time(nullptr));
  // operator+(Book);
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
      int i, found = 0, n = bookID.size();
      for (i = 0; i < n; i++) {
        if (id == bookID[i]) {
          found = 1;
        }
      }
      if (found == 0 || bookID.size() == 0) {
        break;
      }
    }
    break;
  }
}