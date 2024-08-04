// https://www.acmicpc.net/problem/2910
#include<bits/stdc++.h>
using namespace std;
map<int, pair<int, int>> mp;
//vector<pair<int, int> v;
int n, c, t;
// true가 나오면 스왑함. 
bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
    return a.second.second > b.second.second || (a.second.second == b.second.second && a.second.first < b.second.first) ;
}
int main(){
    cin >> n >> c;
    for(int i = 0; i < n; i++){
        cin >> t;
        if(mp[t] == pair(0, 0)) mp[t] = pair(i, 0);
        mp[t].second++;
    }

    vector<pair<int, pair<int, int>>> v(mp.begin(), mp.end());
    sort(v.begin(), v.end(), cmp);

    for(auto it : v){
        for(int i = 0; i < it.second.second; i++){
            cout << it.first << ' ';
        }
    }


    return 0;
}