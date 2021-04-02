#include <iostream>
#include <map>
#include <vector>

using namespace std;

class myQ{
  private:
    map<int, vector<int>> dict;
  public:
    void push(int item, int priority){
      if (dict.find(priority) != dict.end()){
        auto it = dict.find(priority);
        it->second.push_back(item);
      }else{
        vector<int> tempVec = {item};
        dict.insert(make_pair(priority, tempVec));
      }
    }
    int pop(){
      int tempLastElem;
      if(!dict.empty()){
        auto endIt = dict.end();
        endIt--;
        if(endIt->second.size() == 1){
          tempLastElem = endIt->second[0];
          dict.erase(endIt);
        }else{
          tempLastElem = endIt->second[endIt->second.size()-1];
          endIt->second.erase(endIt->second.end()-1);
        }
      }else{
        cout << "queue is empty" << endl;
        exit(0);
      }
      return tempLastElem;
    }
    void printQueue(){
      if(!dict.empty()){
        cout << "{" << endl;
        for(auto it = dict.begin(); it != dict.end(); it++){
          cout << "  \"" <<  it->first << "\": [" << endl;
          for(int i = 0; i < it->second.size(); i++){
            cout << "    " << it->second[i] << endl;
          }
          cout << "  ]," << endl;
        }

        cout << "}" << endl;
      }else{
        cout << "queue is empty" << endl;
        exit(0);
      }
    }
    vector<int> getMax(){
      if(!dict.empty()){
        auto it = dict.begin();
        return it->second;
      }else{
        cout << "queue is empty" << endl;
        exit(0);
      }
    }
};

int main() {
  myQ myq;

  myq.push(10, 1);
  myq.push(11, 2);
  myq.push(12, 3);
  myq.push(13, 1);
  myq.push(15, 1);

  myq.pop();

  myq.printQueue();

  cout << myq.getMax()[0] << endl;
}
