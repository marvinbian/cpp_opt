#include <iostream>

class Uncopyable {
 protected:
   Uncopyable() {}
   ~Uncopyable() {}

 private:
   Uncopyable(const Uncopyable&);
   Uncopyable& operator=(const Uncopyable&);
};

class HomeForScale : private Uncopyable {
  //... main text
};

/*
 * 在这种情况，当member成员函数或friend函数试图尝试拷贝HomeForScale对象时，编译
 * 器便会试着生成一个copy构造函数和一个copy assignment操作符，这些函数会尝试调
 * 用其base class的对应兄弟，那些调用会被拒绝，因为其base class的拷贝函数是
 * private的。
 */
