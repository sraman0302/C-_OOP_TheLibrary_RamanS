#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED
#include "Member.h"
class Book {
 private:
  string name, author, memname;
  int id, memid, count;
  vector<int> bookID;

 public:
  void display();
  void borrow_book();
  void return_book();
  void input();
  void set_BookID();
  void remove_book();
  friend void edit_book(Book book);
  vector<int> operator+(const Book& book);
};
#endif  // BOOK_H_INCLUDED
