#include "Book.h"

int Book::operator+(const Book& books) {}
void Book::borrow_book() {}
void Book::edit_book() {}
void Book::remove_book() {}
void Book::return_book() {}
void Book::display() {
  ifstream input_file;
  input_file.open("Book.txt");
  if (input_file) {
    while (input_file >> id >> name >> count) {
      if (count != 0) {
        cout << id << '\t' << name << '\t' << count << '\n';
      } else {
        continue;
      }
    }
    input_file.close();
  }
}

void Book::input() {
  ifstream cur_file;
  cur_file.open("Book.txt");
  while (cur_file >> id) {
    bookID.push_back(id);
  }
  cur_file.close();
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