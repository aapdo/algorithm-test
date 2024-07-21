// https://www.acmicpc.net/problem/2559
#include<bits/stdc++.h>
using namespace std;

int n, k, s = 0;
int t[100003];
// 최대값을 구할 때에는 최소값을 먼저 설정하는 것이 중요하다.
// 최악의 경우 -100짜리가 10만번 나오면 -100 * 10만 = -1000만 정도 나옴.
int ret = -10000005;

int main(){
    cin >> n;
    cin >> k;
    for(int i = 0; i < n; i++) cin >> t[i];
    for(int i = 0; i < k; i++) s += t[i];
    if(ret < s) ret = s;
    // 그냥 psum 으로 풀어도 되긴 할듯 .
    for(int i = k; i < n; i++){
        s -= t[i-k];
        s += t[i];
        if(ret < s) ret = s;
        
    }

    cout << ret;


}