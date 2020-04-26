#ifndef UNDERGRADUATE_H_INCLUDED
#define UNDERGRADUATE_H_INCLUDED
#include "Member.h"

class Undergraduate : public Member {
 public:
  void stddisplay();
  void edit_std();
  void remove_member();
};
#endif  // UNDERGRADUATE_H_INCLUDED
