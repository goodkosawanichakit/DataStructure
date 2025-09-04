#include <bits/stdc++.h>
#include <stack>

bool ismatch(char o, char c) {
  switch (o) {
  case '(': return c == ')';
  case '{': return c == '}';
  case '[': return c == ']';
  case '<': return c == '>';
  default: return false;
  }
}

void isvalid(std::string s) {
  int valid_count = 0;
  bool is_valid = true;
  std::stack<char> paren;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '<' && i + 1 < s.size() && s[i + 1] == '<') {
      i++; 
      continue;
    }
    if (s[i] == '>' && i + 1 < s.size() && s[i + 1] == '>') {
      i++;
      continue;
    }

    if (s[i] == '(' || s[i] == '{' || s[i] == '[' || s[i] == '<') {
      paren.push(s[i]);
    } else if (s[i] == ')' || s[i] == '}' || s[i] == ']' || s[i] == '>') {
      if (paren.empty()) {
        std::cout << "Not matched\n" << valid_count << " matched\n";
        return;
      }
      char top = paren.top();
      if (ismatch(top, s[i])) {
        paren.pop();
        valid_count++;
      } else {
        std::cout << "Not matched\n" << valid_count << " matched\n";
        return;
      }
    } else {
      continue;
    }
  }

  if (paren.empty()) std::cout << valid_count << " matched\n";
  else std::cout << "Not matched\n" << valid_count << " matched\n";
}

int main() {
  std::string a;
  getline(std::cin, a);
  isvalid(a);
  return 0;
}
