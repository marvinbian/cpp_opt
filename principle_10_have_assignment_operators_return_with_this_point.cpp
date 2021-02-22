#include <iostream>

// for deal with x = y = z, operator = and += should return *this

class Widget {
 public:
   // ...
   Widget& operator=(const Widget& rhs) {
      // ...
      this->get = rhs.get;
      return* this;
   }

   Widget& operator+=(const Widget& rhs) {
     // ...
     this->get += rhs.get;
     return* this;
   }

 private:
   int get = 0;
};
