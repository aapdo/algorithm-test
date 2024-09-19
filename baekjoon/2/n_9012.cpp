// https://www.acmicpc.net/problem/9012
#include<bits/stdc++.h>
using namespace std;
int t;
string s;
bool f;

int main(){
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> s;
        f = true;
        stack<char> stk;
        for(int j = 0; j < s.size(); j++){
            if(s[j] == '(') stk.push('(');
            else{
                if(!stk.empty() && stk.top() == '(') stk.pop();
                else{
                    f = false;
                    break;
                }
            }
        }

        if(!stk.empty()) f = false;
        if(f) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}