// https://www.acmicpc.net/problem/10808
#include<bits/stdc++.h>
using namespace std;
/**
 * 개수를 세는 것은 map 또는 array 를 사용하는 것이 좋음.
 * map: string이 key가 되는 경우나 저장해야 되는 것이 띄엄띄엄 있으면 이게 좋음.
 * array: 연속하거나 int, char의 개수를 세야할 때 좋음. 
*/

/*
int a[26];
string input;
int main(){
    cin >> input;
    memset(a, 0, sizeof(a));
    for(int i = 0; i < input.length(); i++){
        a[input[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++){
        cout << a[i] << ' ';
    }
    
}
*/

map<char, int> mp;
string input;
int main(){
    cin >> input;
    for(int i = 0; i < 26; i++){
        mp[i+97] = 0;
    }
    for(int i = 0; i < input.length(); i++){
        mp[input[i]]++;
    }
    for(auto it: mp){
        cout << it.second << ' ';
    }
}