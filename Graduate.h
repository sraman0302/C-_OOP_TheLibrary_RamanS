#ifndef GRADUATE_H_INCLUDED
#define GRADUATE_H_INCLUDED
#include "Member.h"
class Graduate : public Member {
  public:
  string get_gradname();
  void grad_display();
  void edit_grad();
  void remove_gradmember();
};
#endif  // GRADUATE_H_INCLUDED
