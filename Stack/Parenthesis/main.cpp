#include <iostream>
#include <stack>
#include <string>
#include <map>

std::map<char, char> paren = {
  {'(', ')'},
  {'{', '}'},
  {'[', ']'},
};

/*
Input: 
  >110(20{[]})<
Output:
  Not match
  0 match
*/

void ismatch(std::string &input) {
  std::stack<char> stack;
  for(char c: input) {
    if(open_paren.find(c) != std::string::npos) stack.push(c);
  }
  
}

int main() {
  std::string input = "100(200{[]})";
  ismatch(input);
  return 0;
}