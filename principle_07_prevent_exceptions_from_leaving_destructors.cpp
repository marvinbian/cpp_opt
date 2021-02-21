#include <iostream>

/* sample case for database connect */

class DBConnection{
 public:
   //...
   static DBConnection create();

   void close();
};

class DBConn {
 public:
   //...
   ~DBConn() {
     db.close();
   }

 private:
   DBConnection db;
};

//----------------------------------------
//better for deconstruction

DBConn::~DBConn() {
  try { db.close(); }
  catch (...) {
    // error deal
    std::abort();
  }
}

//----------------------------------------
//more better for deconstruction

class DBConn {
 public:
   //...
   void close() {
     db.close();
     closed = true;
   }
   ~DBConn() {
     if (!closed) {
       try {
         db.close();
       }
       catch (...) {
         // error deal

       }
     }
   }

 private:
   DBConnection db;
   bool closed = false;
};

