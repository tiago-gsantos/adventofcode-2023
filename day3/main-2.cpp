#include <iostream>
#include <vector>

using std::string; 
using std::cin;
using std::cout;
using std::vector;

vector<int> asterisk_index(vector<int> num_positions, vector<string> matrix, int len){
  vector<int> asterisk_idx = {-1, -1, -1};
  
  int size = num_positions.size();

  if(num_positions[size-1] < len-1){
    num_positions.push_back(num_positions[size-1] + 1);
    size++;
  }
  if(num_positions[0] > 0){
    num_positions.push_back(num_positions[0] - 1);
    size++;
  }

  for(int i = 0; i < size; i++){
    for(int j = 0; j < 3; j++){
      if(matrix[j][num_positions[i]] == '*'){
        asterisk_idx[j] = num_positions[i];
      }
    }
  }
  return asterisk_idx;
}

int main(){
  int result = 0;
  
  string first_line;
  cin >> first_line;
  
  unsigned int LEN = first_line.length();

  string standard(LEN, '.');

  vector<string> matrix(3, standard); // [prev, cur, next]
  matrix[1] = first_line;

  vector<vector<int>> symbol_matrix(3, vector<int>(LEN, 0));

  vector<int> num_positions;

  bool in_num = false;
  int num = 0;

  bool run = true;
  while(run){
    if(!(cin >> matrix[2])){
      matrix[2] = standard;
      run = false;
    }
    
    for(unsigned int i=0; i < LEN; i++){
      if(isdigit(matrix[1][i])){
        num = num*10 + (matrix[1][i] - '0');
        num_positions.push_back(i);
        
        if(!in_num){ in_num = true; }

        if(i == LEN-1){
          vector<int> asterisk_idx = asterisk_index(num_positions, matrix, LEN);
          for(int j = 0; j < 3; j++){
            if(asterisk_idx[j] == -1) continue;

            if(symbol_matrix[j][asterisk_idx[j]] == 0)
              symbol_matrix[j][asterisk_idx[j]] = num;
            else
              result += num * symbol_matrix[j][asterisk_idx[j]];
          }

          in_num = false;
          num = 0;
          num_positions.clear();
        }
      }
      else{
        if(in_num){ // primeiro simbolo depois do numero
          vector<int> asterisk_idx = asterisk_index(num_positions, matrix, LEN);
          for(int j = 0; j < 3; j++){
            if(asterisk_idx[j] == -1) continue;

            if(symbol_matrix[j][asterisk_idx[j]] == 0)
              symbol_matrix[j][asterisk_idx[j]] = num;
            else
              result += num * symbol_matrix[j][asterisk_idx[j]];
          }  

          in_num = false;
          num = 0;
          num_positions.clear();
        }
      }
    }

    matrix[0] = matrix[1];
    matrix[1] = matrix[2];

    symbol_matrix[0] = symbol_matrix[1];
    symbol_matrix[1] = symbol_matrix[2];
    symbol_matrix[2].assign(LEN, 0);
  }

  cout << result << '\n';

  return 0;
}