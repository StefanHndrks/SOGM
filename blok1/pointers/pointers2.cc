#include <iostream>
using namespace std;

void incrPtr(int* ptrVar) {
  *ptrVar = *ptrVar + 1;
  cout << "incrPtr: " << *ptrVar << endl;
}

void incrVal(int valVar) {
  valVar = valVar + 1;
  cout << "incrVal: " << valVar << endl;
}

int main()
{
  int variable = 0;

  cout << "variable:" << variable << "\n\n";
  cout << "doing incrVal(variable)" << endl;

  incrVal(variable);

  cout << "\nvariable:" << variable << "\n\n";
  cout << "doing incrPtr(&variable)" << endl;

  incrPtr(&variable);

  cout << "\nvariable:" << variable << endl;

  return 0;
}
