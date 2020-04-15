#ifndef MEMBER_H_INCLUDED
#define MEMBER_H_INCLUDED
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
class Member {
 protected:
  string name;
  int age, id;
  vector<int> membersID;

 private:
  static int count;

 public:
  string get_name();
  void set_ID();
  void display();
  virtual void input();
  vector<int> operator+(const Member& members);
  static int member_count();
};

#endif  // MEMBER_H_INCLUDED
