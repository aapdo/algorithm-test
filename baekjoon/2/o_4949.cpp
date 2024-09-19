// https://www.acmicpc.net/problem/4949

#include<bits/stdc++.h>
using namespace std;
bool f;
string s;
int main(){
    while(true){
        getline(cin, s, '\n');
        //cin.ignore();
        if(s.size() == 1 && s[0] == '.') break;
        f = true;
        stack<char> stk;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[') stk.push(s[i]);
            else if(s[i] == ']'){
                if(!stk.empty() && stk.top() == '[') stk.pop();
                else{
                    f = false;
                    break;
                }
            }else if(s[i] == ')'){
                if(!stk.empty() && stk.top() == '(') stk.pop();
                else{
                    f = false;
                    break;
                }
            }
        }
        if(!stk.empty()) f = false;
        if(f) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}