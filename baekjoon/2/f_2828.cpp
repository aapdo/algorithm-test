// https://www.acmicpc.net/problem/2828
#include<bits/stdc++.h>
using namespace std;
int n, m, j_, t, l, r, ret = 0;
int a[15];
int main(){
    cin >> n >> m >> j_;
    memset(a, 0, sizeof(a));
    // 0번은 고려 x
    l = 1;
    r = 1 + m - 1;
    for(int i = 1; i < m + 1; i++){
        a[i] = 1;
    }

    for(int i = 0; i < j_; i++){
        cin >> t;
        if(l <= t && t <= r) continue;
        if(l > t){
            r = r - (l-t);
            ret += l-t;
            l = t;
        }
        if(r < t){
            l = l + t-r;
            ret += t-r;
            r = t;
        }
    }
    cout << ret;
    return 0;
}