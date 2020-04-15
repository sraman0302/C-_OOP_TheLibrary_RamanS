#ifndef UNDERGRADUATE_H_INCLUDED
#define UNDERGRADUATE_H_INCLUDED
#include "Member.h"

class Undergraduate : public Member {
 private:
  vector<int> undermem;

 public:
  string get_stdname();
  void stddisplay();
  void edit_std();
  void remove_member();
};
#endif  // UNDERGRADUATE_H_INCLUDED
