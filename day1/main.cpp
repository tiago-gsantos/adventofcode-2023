#include <iostream>

using std::string; 
using std::cin;
using std::cout;

int main(){
  
  int result = 0;
  
  string line;
  while(cin >> line){
    int fwd_it = 0;
    while(!std::isdigit(line[fwd_it])){ fwd_it++; }

    int rev_it = line.length();
    while(!std::isdigit(line[rev_it])){ rev_it--; };
    
    result += ((line[fwd_it] - '0')*10 + (line[rev_it] - '0'));
  }

  cout << result << '\n';

  return 0;
}