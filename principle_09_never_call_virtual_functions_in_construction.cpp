#include <iostream>

// never call virtual function in construction and deconstruction function
// bad example !!!!

/*
class Transaction {
 public:
   Transaction() {
     init();  // notice: it called virtual function
   }
   virtual void logTransaction() const = 0;
 private:
   void init() {
     // ...
     logTransaction();  // a virtual function
   }
};
*/

// bad example end

// so the right way to deal with this

class Transaction {
 public:
   explicit Transaction(const std::string& logInfo);
   void logTransaction(const std::string& logInfo) const;
   // ...
};

Transaction::Transaction(const std::string& logInfo) {
  // ...
  logTransaction(logInfo);
}

class BuyTransaction: public Transaction {
 public:
   BuyTransaction(std::string& parameters)
     : Transaction(createLogString(parameters)) {
     // ...
   }
 private:
   static std::string createLogString(std::string& parameters);
};
