#include <iostream>
#include <vector>

using std::string; 
using std::cin;
using std::cout;
using std::vector;

vector<string> colors = {"red", "green", "blue"};
vector<int> num_cubes = {12, 13, 14};

int getnumber(char *&idx){
  int num = 0;
  
  while(*idx != ' '){
    num = num * 10 + (*idx - '0'); 
    idx++;
  }

  return num;
}

int getcolor(char *&idx){
  for(size_t i = 0; i < colors.size(); i++){
    if(*idx == colors[i][0]){
      idx += colors[i].size();
      return i;
    }
  }

  return -1; // never happens
}

vector<int> parser(string line){
  char *idx = &line[8];
  
  vector<int> max_values = {0, 0, 0};
  
  int num = 0;
  int color = -1;

  while(*idx != '\0'){
    if(*idx == ' ' || *idx == ',' || *idx == ';')
      idx++;
    else{
      num = getnumber(idx);
      idx++; //ignore space
      color = getcolor(idx);
    
      if(color != -1) 
        max_values[color] = std::max(max_values[color], num);
    }
  }

  return max_values;
}

int main(){
  int result = 0;
  int id = 1;
  
  vector<int> game_data = {0, 0, 0};

  string line;

  while(std::getline(cin, line)){
    game_data = parser(line);

    result += game_data[0]*game_data[1]*game_data[2];

    id++;   
  }

  cout << result << '\n';

  return 0;
}