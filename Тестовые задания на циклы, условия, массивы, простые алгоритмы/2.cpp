#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

template < typename T >
bool findInVec(vector<T> vec, T item){
  auto findMove = find(vec.begin(), vec.end(), item);

  if(findMove != vec.end()) return true;

  return false;
}

bool movef(string move, map<string, int> &currentCords, vector<vector<vector<string>>> &field, vector<vector<string>> &userField){
  //what direction check
  if (move == "l"){
    //if this move already been
    if(findInVec(field[currentCords["y"]][currentCords["x"]], move)){
      return true;
    }
    //add this move to history
    field[currentCords["y"]][currentCords["x"]].push_back(move);
    //show this move for user
    userField[currentCords["y"]][currentCords["x"]] = move;

    //move
    if(currentCords["x"] == 0){
      currentCords["x"] = 3;
    }else{
      currentCords["x"] -= 1;
    }
  }else if(move == "r"){
    if(findInVec(field[currentCords["y"]][currentCords["x"]], move)){
      return true;
    }
    field[currentCords["y"]][currentCords["x"]].push_back(move);
    userField[currentCords["y"]][currentCords["x"]] = move;

    if(currentCords["x"] == 3){
      currentCords["x"] = 0;
    }else{
      currentCords["x"] += 1;
    }
  }else if(move == "d"){
    if(findInVec(field[currentCords["y"]][currentCords["x"]], move)){
      return true;
    }
    field[currentCords["y"]][currentCords["x"]].push_back(move);
    userField[currentCords["y"]][currentCords["x"]] = move;

    if(currentCords["y"] == 3){
      currentCords["y"] = 0;
    }else{
      currentCords["y"] += 1;
    }
  }else if(move == "u"){
    if(findInVec(field[currentCords["y"]][currentCords["x"]], move)){
      return true;
    }
    field[currentCords["y"]][currentCords["x"]].push_back(move);
    userField[currentCords["y"]][currentCords["x"]] = move;

    if(currentCords["y"] == 0){
      currentCords["y"] = 3;
    }else{
      currentCords["y"] -= 1;
    }
  }

  cout << currentCords["y"] << " - " << currentCords["x"] << endl;

  return false;

}

void showFieldForUser(vector<vector<string>> userField){
  for(int i = 0; i < userField.size(); i++){
    cout << "[ ";
    for(int j = 0; j < userField.size(); j++){
      cout << userField[i][j] << " ";
    }
    cout << "]" << endl;
  }
}

void showMainField(vector<vector<vector<string>>> field){
  for(int i = 0; i < field.size(); i++){
    cout << "[ ";
    for(int j = 0; j < field[i].size(); j++){
      cout << "[";
      for(int k = 0; k < field[i][j].size(); k++){
        cout << field[i][j][k] << ",";
      }
      cout << "] ";
    }
    cout << "]" << endl;
  }
}

int main() {

  //main vector with history
  vector<vector<vector<string>>> field(4, vector<vector<string>>(4));

  //vector for user to show
  vector<vector<string>> userField(4, vector<string>(4, "#"));

  //vector with all posibility moves
  vector<string> moves = {"l", "r", "u", "d"};

  //map with current user cords
  map<string, int> currentCords = { {"y", 0}, {"x", 0} };

  //get first move
  string move;
  cout << "move: ";
  cin >> move;

  while(move != ""){
    if (findInVec(moves, move)){
      //check move for secondary
      if(movef(move, currentCords, field, userField)){
        cout << "again here!! [" << currentCords["y"] << " : " << currentCords["x"] << "]";
        //need write function for show main field!
        break;
      }

      //set current user position in field
      userField[currentCords["y"]][currentCords["x"]] = "o";
      //show field
      showFieldForUser(userField);
      showMainField(field);

      //get new move
      cout << "move: ";
      cin >> move; 
    }else{
      cout << "incorrect";
      break;
    }
  }
}
