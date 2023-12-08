#include <iostream>
#include <vector>

using std::string; 
using std::cin;
using std::cout;
using std::vector;


bool issymbol(char c){
  return c != ' ' && !isdigit(c) && c != '.' && !isalpha(c);
}

bool adj_to_symbol(vector<int> num_positions, string prev_line, string cur_line, string nxt_line){
  int size = num_positions.size();
  int len = cur_line.length();

  if(num_positions[size-1] < len-1){
    num_positions.push_back(num_positions[size-1] + 1);
    size++;
  }
  if(num_positions[0] > 0){
    num_positions.push_back(num_positions[0] - 1);
    size++;
  }

  for(int i = 0; i < size; i++){
    if(issymbol(prev_line[num_positions[i]]) || issymbol(cur_line[num_positions[i]]) || issymbol(nxt_line[num_positions[i]]))
      return true;
  }

  return false;
}

int main(){
  int result = 0;
  
  string cur_line;
  cin >> cur_line;
  
  unsigned int LEN = cur_line.length();

  string standard(LEN, '.');
  
  string prev_line = standard;
  string nxt_line;

  vector<int> num_positions;

  bool in_num = false;
  int num = 0;

  bool run = true;
  while(run){
    if(!(cin >> nxt_line)){
      nxt_line = standard;
      run = false;
    }

    for(unsigned int i=0; i < LEN; i++){
      if(isdigit(cur_line[i])){
        num = num*10 + (cur_line[i] - '0');
        num_positions.push_back(i);
        
        if(!in_num){ in_num = true; }

        if(i == LEN-1){
          if(adj_to_symbol(num_positions, prev_line, cur_line, nxt_line)){
            result += num;
          }

          in_num = false;
          num = 0;
          num_positions.clear();
        }
      }
      else{
        if(in_num){ // primeiro simbolo depois do numero
          if(adj_to_symbol(num_positions, prev_line, cur_line, nxt_line)){
            result += num;
          }

          in_num = false;
          num = 0;
          num_positions.clear();
        }
      }
    }

    prev_line = cur_line;
    cur_line = nxt_line;
  }

  cout << result << '\n';

  return 0;
}