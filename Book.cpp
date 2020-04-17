#include "Book.h"

vector<int> Book::operator+(const Book& book) {
  ifstream input_file;
  int ID;
  input_file.open("members.txt");
  if (input_file) {
    while (input_file >> ID) {
      bookID.push_back(ID);
    }
  }
  return bookID;
}
void Book::borrow_book() {
  int found = 0, pos, n = 0, member_id, borrow = 0;
  cout << "Enter 4-digit code of user: ";
  cin >> member_id;
  vector<int> members_id;
  vector<string> members_name;
  vector<string> members_book;
  vector<int> ages;
  ifstream member_file;
  string memname, membook;
  int memid, memage;
  member_file.open("members.txt");
  if (member_file) {
    while (member_file >> memid >> name >> memage >> membook) {
      if (memid == member_id) {
        pos = n;
        found = 1;
      }
      if (membook == " ") {
        borrow = 1;
      }
      ages.push_back(memage);
      members_id.push_back(memid);
      members_name.push_back(name);
      members_book.push_back(membook);
      n++;
    }
  }
  member_file.close();
  if (borrow == 1) {
    cout << "Do you want to display the books available at the Library?";
    char ch;
    cin >> ch;
    if (ch == 'y') {
      cout << "\nDisplaying the available books for reference" << endl;
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

    if (input_file) {
      n = 0, found = 0;
      while (input_file >> id >> name >> author >> count) {
        if (id == bookcode) {
          bookpos = n;
          found = 1;
        }
        book_name.push_back(name);
        book_quant.push_back(count);
        book_code.push_back(id);
        author_name.push_back(author);
      }
      input_file.close();
    }
    if (found = 1) {
      cout << "Book code" << book_code[pos] << " labelled" << book_name[pos]
           << "issued to "
           << "User ID: ";
    }
  }
}
void Book::return_book() {}
void Book::edit_book() {}
void Book::remove_book() {}

void Book::display() {
  ifstream input_file;
  input_file.open("Book.txt");
  if (input_file) {
    while (input_file >> id >> name >> author >> count) {
      if (count != 0) {
        cout << id << '\t' << name << '\t' << author << '\t' << count << '\n';
      } else {
        continue;
      }
    }
    input_file.close();
  }
}

void Book::input() {
  ofstream ofile;
  ofile.open("Book.txt", ios::app);
  if (ofile) {
    set_BookID();
    cout << "Book ID: " << id;
    cout << "Enter your name:";
    cin >> name;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    ofile << name;
    cout << "Enter age";
    cin >> count;
    ofile << count;
    ofile << endl;
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
      if (found == 0) {
        break;
      }
    }
  }
}