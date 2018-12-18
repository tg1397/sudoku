/*

NAME:Trisha Gagnon
FILE:stack.h
DESC:Header file for the stack class
DATE:Last updated 10/06

*/
#include <iostream>

using namespace std;

typedef int stack_Element;

class stack {

public:
  
  stack();

  void _create();

  void _destroy();

  void push(const stack_Element&);
  
  void pop();

  bool empty() const;
  
  stack_Element top() const;

private:

  struct node {
    stack_Element _data;
    node *next;
    node(stack_Element item, node *after);
    
  };
  node * _top;
};