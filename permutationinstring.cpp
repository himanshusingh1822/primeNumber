#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> a,vector<int> b);

int main() {
   int t;
   cin >> t;
   while(t--){
    string s1,s2;
    cin >> s1 >> s2;
    vector<int> v1(26,0);
    for(int i=0;i<s1.size();i++){
        v1[s1[i]-'a']++;
    }
    bool flag=0;
    vector<int> v2(26,0);
    int i=0,j=0;
    while(j<s2.size()){
        v2[s2[j]-'a']++;
        if(j-i+1==s1.size()){
            if(check(v1,v2))flag=1;
        }
        if((j-i+1) < s1.size())j++;
        else{
            v2[s2[i]-'a']--;
            i++;
            j++;
        }
        
    }
    if(flag){
        cout << "True" << endl;
    }
        else {
            cout << "False" << endl;
        }
   }
    return 0;
}

bool check(vector<int> a,vector<int> b){
    for(int i=0;i<26;i++){
        if(a[i]!=b[i])return 0;
    }
    return 1;
}