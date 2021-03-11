#include <iostream>
#include <map>
#include <fstream>
#include <string>
using namespace std;

multimap <string, string> getRoles(multimap <string, string> roles){
  ifstream inputF;
	inputF.open("input.txt");
	int strNumber = 0;
	string str;
	while (getline(inputF, str)) {
		int separatorPos = str.find('.');
		if (separatorPos != string::npos) {
			string role = str.substr(0, separatorPos + 1);
			roles.insert(make_pair(role, to_string(strNumber) + ") " + str.substr(separatorPos+1)));
		}
    strNumber++;
	}
	inputF.close();

  return roles;
}

void OutToFile(multimap <string, string> roles){
  ofstream outputF;
	outputF.open("output.txt");
  
  auto rolesIter = roles.begin();
	outputF << rolesIter->first << endl;
	outputF << rolesIter->second << endl;
	rolesIter++;

  auto rolesIter2 = roles.begin();
  while(rolesIter != roles.end()){
    if (rolesIter2->first == rolesIter->first) {
			outputF << rolesIter->second << endl;
		}
		else {
			outputF << endl;
			outputF << rolesIter->first << endl;
			outputF << rolesIter->second << endl;
		}
    rolesIter++;
  }
}

int main(){

	multimap <string, string> roles;

	roles = getRoles(roles);

	OutToFile(roles);
}