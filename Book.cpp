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

      ages.push_back(memage);
      members_id.push_back(memid);
      members_name.push_back(name);
      members_book.push_back(membook);
      n++;
    }
  }
  if (members_book[pos] == " ") {
    borrow = 1;
  }
  member_file.close();
  if (borrow == 1) {
    cout << "Do you want to display the books available at the Library?";
    char ch;
    cin >> ch;
    if (ch == 'y') {
      cout << "\nDisplaying the available books for reference" << endl;
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
        if ((id == bookcode) && (count > 0)) {
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
      members_book[pos] == book_name[bookpos];
      cout << "Book due to be returned in 3 hours" << endl;
      book_quant[bookpos]--;

      ofstream member_update;
      member_update.open("members.txt");
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
  } else if (borrow == 0) {
    cout
        << "Error.\n Please make sure you have no books due and intending to a "
           "book available at the library."
        << endl;
  }
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
  member_file.open("members.txt");
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
      member_update.open("members.txt");
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
    // books.erase(books.begin() + pos);
    cout << "Book code" << book_code[bookpos] << " labelled"
         << book_name[bookpos] << "has been erased successfully. ";

    book_quant.erase(book_quant.begin() + bookpos);
    book_name.erase(book_name.begin() + bookpos);
    book_code.erase(book_code.begin() + bookpos);
    author_name.erase(author_name.begin + bookpos);

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

  else if (found == 0) {
    cout << "Error.\n Please make sure you have the book exists" << endl;
  }
}

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
// edit is friend class
void Book::edit_book() {}