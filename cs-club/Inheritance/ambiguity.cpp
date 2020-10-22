#include <iostream>
#include <string> 
using namespace std;


// // class ComicFan {
// //    public:
// //       void setName(string n) {
// //          hero = n;
// //       }
// //       void setPower(string p) {
// //          power = p;
// //       }
// //       string getDetails()
// //       {
// //       return "\nName: "+ hero +" Power: " + power;
// //       }
// //    protected:
// //       string hero;
// //       string power;
// // };


// // class Marvel {
// //    public:
// //       void Win(){
// //           cout<<"Marvel Wins"<<endl;
// //       }
// // };
// // class DC  {
// //    public:
// //       void Win(){
// //           cout<<"DC Wins"<<endl;
// //       }
// // };

// // class Otaku: public Marvel , public DC {
// //     public:
// //     Otaku()
// //     {
// //         cout<<"I say ";
// //     }
// // };

// // int main(void) {
// //    Otaku Nitesh;
 
// //       // Print the area of the object.
// //    //cout << "Lets See: " << endl;

// //     //Nitesh.Marvel::Win();
// //     Nitesh.Win();
// //    return 0;
// // }

// ///-------------------- Overiding

// class JEE_Main{ 
//   public: 
//     JEE_Main() 
//     { 
//       cout << "mains Cleared!!" << endl; 
//     }

//     void Wow()
//     {
//         cout<<" Mains ?"<<endl;
//     } 
// }; 
  
// // second base class 
// class JEE_Advanced : public JEE_Main{ 
//   public: 
//     JEE_Advanced() 
//     { 
//       cout << "advanced Cleared" << endl; 
//     }

//     void Wow()
//     {
//         cout<<" Advance ?"<<endl;
//     } 

// }; 
  
// // sub class derived from two base classes 
// class IIITDM:  public JEE_Advanced { 
//   public:
//     IIITDM()
//     {
//         cout<< "in IIITDM!!?? :P\n";
//     }
// }; 
  
// // main function 
// int main() 
// {    
//     // creating object of sub class will 
//     // invoke the constructor of base classes 
//     IIITDM pavam; 
//     pavam.Wow();
//     return 0; 
// } 

class Student
    {  
        public :
        char a;
        int b;
        Student()
        {
           // a = 1;
            b = 2;
        }
        void hi(){
            cout<<"a\n"<<a;
        }
 };

//main function 
int main() 
{    
    
    Student S;
    S.
    cout<<"b :"<<S.b<<endl;
    return 0; 
}