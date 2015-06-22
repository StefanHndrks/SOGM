#include <iostream>
using namespace std;

int main()
{
  int jaar = 2014;
  int* jaarPtr1;
  int* jaarPtr2;

  jaarPtr1 = &jaar;

  cout << "jaar:                 " << jaar      << "\n";
  cout << "jaarPtr1:             " << jaarPtr1  << "\n";
  cout << "jaarPtr1 dereference: " << *jaarPtr1 << "\n" << endl;

  cout << "doing *jaarPtr1 = 2015" << "\n" << endl;
  *jaarPtr1 = 2015;

  cout << "jaar:                 " << jaar << "\n" << endl;

  cout << "doing jaarPtr2 = jaarPtr1" << "\n" << endl;
  jaarPtr2 = jaarPtr1;

  cout << "jaarPtr2:             " << jaarPtr2  << "\n";
  cout << "jaarPtr2 dereference: " << *jaarPtr2 << "\n" << endl;

  cout << "doing *jaarPtr2 = 2016" << "\n" << endl;
  *jaarPtr2 = 2016;

  cout << "jaar:                 " << jaar << "\n" << endl;

  return 0;
}
