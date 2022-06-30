#include <bits/stdc++.h>
using namespace std;
string minWindow(string s, string t) {
    unordered_map<char,int> mymap;
    int len=0,hi=0,lo=0;
    for(int i=0;i<t.length();i++){
        mymap[t[i]]++;
    }
    string ans="";
    while(hi<s.length()){
        ans+=s[hi];
        if(len<t.length()){
            if(mymap.count(s[hi])!=0){
                mymap[s[hi]]--;
                if(mymap[s[hi]]==0){
                    len++;
                }
            }
            hi++;
            continue;
        }
        
        else if(len>=t.length()){
            while(len>=t.length()){
                ans=ans.substr(1);
                cout<<ans<<endl;
                if(mymap.count(s[lo])!=0){
                    mymap[s[lo]]++;
                    if(mymap[s[lo]]>0){
                        len--;
                    }
                }lo++;
            }
        }
        
        hi++;
    }return ans;
}
int main(){
    cout<<"asdfjs";
    minWindow("ADOBECODEBANC","ABC");
}