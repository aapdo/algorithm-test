// https://www.acmicpc.net/problem/2979
#include<bits/stdc++.h>
using namespace std;

/**
 * 도착 시간 떠난 시간.. 에서 떠난 시간은 미만으로 풀어야된다.
*/
int a[4], b, c, ret = 0;
int f[105];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    a[0] = 0;

    cin >> a[1] >> a[2] >> a[3];
    a[2] *= 2;
    a[3] *= 3;
    memset(f, 0, sizeof(f));
    for(int i = 0; i < 3; i++){
        cin >> b >> c; 
        for(int j = b; j < c; j++){
            f[j]++;
        }
    }
    for(int i = 0; i < 102; i++){
        ret += a[f[i]];
    }
    cout << ret << '\n';
}