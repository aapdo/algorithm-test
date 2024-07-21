//https://www.acmicpc.net/problem/1159
#include<bits/stdc++.h>
using namespace std;

// counting 문제이다. 맵과 배열 둘다 가능.

map<char, int> mp;
int n;
string s;
bool f = false;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        mp[s[0]]++;
    }
    for(auto it : mp){
        if(it.second >= 5){
            cout << it.first;
            f = true;
        }
    }
    if(!f) cout << "PREDAJA";
}