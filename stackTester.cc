#include "stack.h"

int main() {
  stack s;
  s.push(4);
  int top = s.top();
  cout << top << endl;
  s.push(12);
  top = s.top();
  cout << top << endl;
  s.pop();
  top = s.top();
  cout << top << endl;
}