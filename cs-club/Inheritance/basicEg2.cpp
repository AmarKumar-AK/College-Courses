// normal Inheritance


#include <iostream>
#include <string> 
using namespace std;

// Base class
class ComicFan {
   public:
      void setName(string n) {
         hero = n;
      }
      void setPower(string p) {
         power = p;
      }
      string getDetails()
      {
      return "\nName: "+ hero +" Power: " + power;
      }
   protected:
      string hero;
      string power;
};

// Derived class
class Marvel: public ComicFan {
   public:
      
};
class DC: public ComicFan {
   public:
      
};

int main(void) {
   Marvel Otaku;
 
   Otaku.setName("Iron Man");
   Otaku.setPower("Billionare");

   // Print the area of the object.
   cout << "Details " << Otaku.getDetails() << endl;

   return 0;
}