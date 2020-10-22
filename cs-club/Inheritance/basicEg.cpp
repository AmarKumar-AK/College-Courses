// Normal Inheritance


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
     
   protected:
      string hero;
      string power;
}co;

// Derived class
class Marvel: public ComicFan {
   public:
      string getDetails()
      {
      return hero +" " + power;
      }
};
class DC: public ComicFan {
   public:
      string getDetails()
      {
      return hero +" " +  power;
      }
};

int main(void) {
   DC Otaku;
 
   Otaku.setName("Iron Man");
   Otaku.setPower("Billionare");
   //co.hero="abc";
   //co.power="def";
   // Print the area of the object.
   cout << "Details " << Otaku.getDetails() << endl;
   
   //cout<<"another details : "<<Otaku.getDetails();

   return 0;
}