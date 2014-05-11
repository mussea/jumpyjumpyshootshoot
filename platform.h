#ifndef _PLATFORM_
#define _PLATFORM_

#include "character.h"


class Platform : public Character{
 public:
  Platform(int, int, int, int, int);
  bool checktouch(int, int, int, int);
};

#endif
