#include "Book.h"
#include "Graduate.h"
#include "Member.h"
#include "Undergraduate.h"

int main(void) { cout << "hi"; }

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