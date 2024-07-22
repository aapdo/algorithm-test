// https://www.acmicpc.net/problem/1213
#include<bits/stdc++.h>
using namespace std;

/**
 * 팰린드롬 만들기.
 * 일단 불가능한 경우는 어떤 경우일까?
 * 전체 문자열이 짝수 개인 경우 -> 모든 문자가 짝수개있어야함.
 * 전체 문자열이 홀수 개인 경우 -> 문자 중에 하나만 홀수개 있어야 하고 그게 중간에 나와야함..
*/
string s, ret;
int a[26], cnt = 0, flag;
char center;
int main(){
    cin >> s;
    memset(a, 0, sizeof(a));
    for(int i = 0; i < s.size(); i++){
        a[s[i]-'A']++;
    }

    for(int i = 25; i >= 0; i--){
        // a[i]가 홀수면
        if(a[i]){
            if(a[i] & 1){
                // i번째 녀석이 center에 와야함.
                center = char(i+'A');
                a[i]--;
                // 홀수가 2개 이상이면 생성 불가
                if(++cnt == 2) break;
            }
            for(int j = 0; j < a[i]; j+=2){
                ret = char(i+'A') + ret;
                ret += char(i+'A');
            }
            
        }
   }
   if(cnt == 1) ret.insert(ret.begin() + ret.size()/2, center);
   if(cnt == 2) cout << "I'm Sorry Hansoo";
   else cout << ret;
}