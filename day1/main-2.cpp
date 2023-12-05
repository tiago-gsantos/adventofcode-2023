#include <iostream>
#include <vector>

using std::string; 
using std::cin;
using std::cout;
using std::vector;

vector<string> numbers = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main(){
  
  int result = 0;

  string line;
  while(cin >> line){
    int first_digit = -1, second_digit = -1;
    int len = line.length();

    for(int i = 0; i < len; i++){ 
      if(std::isdigit(line[i])){
        first_digit = line[i] - '0';
        break;
      }
      for(int num = 0; num <= 8; num++){
        int len_number = numbers[num].length();
        if(numbers[num] == line.substr(i, len_number)){
          first_digit = num + 1;
          break;
        }
      }
      if(first_digit != -1) break;
    }

    for(int i = len; i >= 0; i--){
      if(std::isdigit(line[i])){
        second_digit = line[i] - '0';
        break;
      }
      for(int num = 0; num <= 8; num++){
        int len_number = numbers[num].length();
        if(i-len_number+1 >= 0 && numbers[num] == line.substr(i-len_number+1, len_number)){
          second_digit = num + 1;
          break;
        }
      }
      if(second_digit != -1) break;
    }
    
    result += (first_digit*10 + second_digit);
  }

  cout << result << '\n';

  return 0;
}