// C++ program to explain  
// multiple inheritance 
#include <iostream> 
#include <string>
using namespace std; 
  
// ----------Multiple

// // first base class 
// class Software{ 
//   public: 
//     Software() 
//     { 
//       cout << "I like  Software " << endl; 
//     } 
// }; 
  
// // second base class 
// class Hardware { 
//   public: 
//     Hardware() 
//     { 
//       cout << "I like Hardware" << endl; 
//     } 
// }; 
  
// // sub class derived from two base classes 
// class COE_CED: public Software, public Hardware { 
//   public:
//     COE_CED()
//     {
//         cout<<"Which Means I am A Computer Engineer";
//     }
// }; 
  
// // main function 
// int main() 
// {    
//     // creating object of sub class will 
//     // invoke the constructor of base classes 
//     COE_CED nitesh; 
//     return 0; 
// } 


//-------------------------- MultiLevel


class JEE_Main{ 
  public: 
  int a;
    JEE_Main() 
    { 
      cout << "mains Cleared!!" << endl; 
    } 
    ~JEE_Main()
    {
      cout<<a<<endl;
      cout<<"hello in jee main"<<endl;
    }
}; 
  
// second base class 
class JEE_Advanced : public JEE_Main{ 
     
  public: 
    
    JEE_Advanced() 
    { 
      cout << "advanced Cleared" << endl; 
    } 
    ~JEE_Advanced()
    {
      cout<<a<<endl;
      cout<<"hello in jee adv"<<endl;
     
      
    }
}; 
  
// sub class derived from two base classes 
class IIITDM:  public JEE_Advanced { 
  public:
    IIITDM()
    {
        cout<< "in IIITDM!!?? :P\n";
    }
    ~IIITDM()
    {
      cout<<a<<endl;
      cout<<"hello in iiitdm"<<endl;
      //cout<<"a+b is "<<a+b<<endl;
    }
}; 
  
// main function 
int main() 
{    
    // creating object of sub class will 
    // invoke the constructor of base classes 
    IIITDM pavam; 
    return 0; 
} 



