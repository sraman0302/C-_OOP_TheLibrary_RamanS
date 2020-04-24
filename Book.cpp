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
  bool found;
  string mname, mbook, bookcheck = "Nill";
  cout << "\nEnter code of book intending to borrow for 3 hours (Limit 1 per "
          "user) ";

  cin >> bookcode;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  ofstream temp1;
  temp1.open("temp1.txt");

  ifstream book_file;
  book_file.open("Book.txt");

  if (book_file.is_open()) {
    while (book_file >> id >> name >> count >> author) {
      if (id == bookcode) {
        if ((id < 5000 && bookcode < 5000) ||
            (id >= 5000 && bookcode >= 5000)) {
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
            ofstream temp2;
            temp2.open("temp2.txt");
            ifstream member_file;
            member_file.open("Members.txt");
            count--;
            cout << "Enter Member ID: ";
            cin >> memcode;
            while (member_file >> mid >> mname >> mage >> mbook) {
              if (memcode == mid) {
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
        } else {
          cout << "\nBook cannot be issued due to degree status" << endl;
        }
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
    cout << "Error" << endl;
  }
  book_file.close();
  temp1.close();
  remove("Members.txt");
  remove("Book.txt");
  rename("temp1.txt", "Book.txt");
  rename("temp2.txt", "Members.txt");
}

void Book::return_book() {
  int found = 0, pos, n = 0, member_id, give = 0;
  cout << "Enter 4-digit code of user initiate return process: ";
  cin >> member_id;
  vector<int> members_id;
  vector<string> members_name;
  vector<string> members_book;
  vector<int> ages;
  ifstream member_file;
  string memname, membook;
  int memid, memage;
  member_file.open("Members.txt");
  if (member_file) {
    while (member_file >> memid >> name >> memage >> membook) {
      if (memid == member_id) {
        pos = n;
        found = 1;
      }

      ages.push_back(memage);
      members_id.push_back(memid);
      members_name.push_back(name);
      members_book.push_back(membook);
      n++;
    }
  }

  if (members_book[pos] != " ") {
    give = 1;
  }
  member_file.close();
  if (give == 1) {
    cout << "Do you want to display the books rented from the Library?";
    char ch;
    cin >> ch;
    if (ch == 'y') {
      cout << "\nDisplaying the rented books for reference" << endl;
      cout << "ID: " << members_id[pos] << " Name: " << members_name[pos]
           << "Book Borrowed " << members_book[pos] << endl;
    }
    cout << "Do you want the book ID from the list of books for easier return?";
    cin >> ch;
    if (ch == 'y') {
      display();
    }
    cout << "\nEnter code of book intending to borrow for 3 hours (Limit 1 per "
            "user)";
    int bookcode, bookpos;
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
        }
        book_name.push_back(name);
        book_quant.push_back(count);
        book_code.push_back(id);
        author_name.push_back(author);
        m++;
      }
      input_file.close();
    }
    if (found == 1) {
      cout << "Book code" << book_code[bookpos] << " labelled"
           << book_name[bookpos] << "issued to "
           << "User ID: " << members_id[pos] << " Named:" << members_name[pos]
           << endl;
      members_book[pos] == " ";
      cout << "Book successfully returned" << endl;
      book_quant[bookpos]++;

      ofstream member_update;
      member_update.open("Members.txt");
      if (member_update) {
        int i;
        for (i = 0; i < n; i++) {
          member_update << members_id[i];
          member_update << members_name[i];
          member_update << ages[i];
          member_update << members_book[i];
          member_update << endl;
        }
        member_update.close();
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
    } else {
      cout << "Invalid entry" << endl;
    }
  } else if (give == 0) {
    cout << "Error.\n Please make sure you have a books due and intending to a "
            "book available at the library."
         << endl;
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