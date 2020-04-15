#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED
#include "Member.h"
class Book {
 private:
  string name;
  string author;
  string count;
  vector<string> books;
  int id;

 public:
  int operator+(const Book& books);
  void borrow_book();
  void edit_book();
  void remove_book();
  void return_book();
  void display();
  void input();
  void set_author();
};

#endif  // BOOK_H_INCLUDED
