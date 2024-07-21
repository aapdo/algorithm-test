// https://www.acmicpc.net/problem/9375
#include<bits/stdc++.h>
using namespace std;

int n, m, ret;
map<string, int> mp;
string s;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> m;
        mp.clear();
        ret = 1;
        for(int j = 0; j < m; j++){
            cin >> s;
            cin >> s;
            mp[s]++;
        }
        for(auto it : mp){
            ret *= (it.second + 1);
        }
        cout << ret-1 << '\n';
    }

}