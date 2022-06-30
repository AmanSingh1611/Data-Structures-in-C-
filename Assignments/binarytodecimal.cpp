#include <bits/stdc++.h>
using namespace std;
string minWindow(string s, string t) {
    if(s.length()<t.length()){
        return "";
    }
    unordered_map<char,int> mymap;
    int len=0,hi=0,lo=0,min=INT_MAX;
    for(int i=0;i<t.length();i++){
        mymap[t[i]]++;
    }
    string temp="",ans="";
    while(hi<s.length()){
        temp+=s[hi];
        if(len<mymap.size()){
            if(mymap.count(s[hi])!=0){
                mymap[s[hi]]--;
                if(mymap[s[hi]]==0){
                    len++;
                }
            }
        }
        
        if(len>=mymap.size()){
            while(len>=mymap.size()){
                cout<<temp<<" "<<len<<endl;
                if(len<=min){
                    ans=temp;
                    min=len;
                }
                if(mymap.count(s[lo])!=0){
                    mymap[s[lo]]++;
                    if(mymap[s[lo]]>0){
                        len--;
                    }
                }
                temp=temp.substr(1);
                lo++;
            }
        }
        hi++;
    }return ans;
}
int main(){
    minWindow("cabwefgewcwaefgcf","cae");
}