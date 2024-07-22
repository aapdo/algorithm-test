// https://www.acmicpc.net/problem/3986
#include<bits/stdc++.h>
using namespace std;
int n, ret = 0, cnt = 0, start, flag, even;
string s;
stack<char> stk;
// 90도 돌리기, 리버스, 이어붙이기. 
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        // A와 B의 개수가 모두 짝수여야 함. -> 전체 문자열 길이도 짝수
        if(s.size() & 1) continue;
        // stack으로 풀기 
        while(!stk.empty()) stk.pop();
        for(int j = 0; j < s.size(); j++){
            if(stk.size() && stk.top() == s[j]) stk.pop();
            else stk.push(s[j]);
            /*
            if(stk.empty()) stk.push(s[j]);
            else{
                if(stk.top() == s[j]) stk.pop();
                else stk.push(s[j]);
            }
            */
        }
        if(stk.empty()) ret++;

    }
    cout << ret;
}