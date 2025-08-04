#include <iostream>
#include <stack>

int is_valid(std::string &expression){
  std::stack<char> arr;

  for(char s: expression){
    if(s == '('){
      arr.push(s);
    } 
    else if(s == ')'){
      if(arr.empty()){
        return 1;
      }
      if(arr.top() == '('){
        arr.pop();
      } 
      else{
        return 1;
      }
    }
  }
  
  if(!arr.empty()){
    return 1;
  }

  return 0;
}

int main(){
  std::string input;
  std::getline(std::cin, input);
  int result = is_valid(input);

  if(result == 1){
    std::cout << "Error\n";
  } else {
    std::cout << "Pass\n";
  }

  return 0;
}