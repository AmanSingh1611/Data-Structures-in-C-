#include <map>
#include <string>
#include <vector>
string uniqueChar(string str) {
	// Write your code here
	map<char,int> exists;
    vector<char> ans;
    int index = 0;
    for(int i=0;str[i]!='\0';i++){
        exists[str[i]]=0;
    }
    for(int i=0;str[i]!='\0';i++){ 
        exists[str[i]]++;
	}for(int i=0;str[i]!='\0';i++){
        if(exists[str[i]]==1){
            ans.push_back(str[i]);
        }
    }for(int i=0;i<ans.size();i++){
        str[i]=ans[i];
    }str[ans.size()]='\0';
    return str;
}