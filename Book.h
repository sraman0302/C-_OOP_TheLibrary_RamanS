#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED
#include "Member.h"
class Book {
 private:
  string name;
  string author;
  int count;
  vector<int> bookID;
  int id;

 public:
  vector<int> operator+(const Book& book);
  void borrow_book();
  friend void edit_book(Book book);
  void remove_book();
  void return_book();
  void display();
  void input();
  void set_BookID();
};

#endif  // BOOK_H_INCLUDED
