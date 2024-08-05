// https://www.acmicpc.net/problem/3474
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n, cnt, temp;
ll a[15];
int main(){
    a[0] = 1;
    for(int i = 1; i < 13; i++){
        a[i] = a[i-1] * 5;
    }
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cnt = 0;
        cin >> n;
        for(int j = 5; j <= n; j *= 5){
            cnt += n / j;
        }
        /*
        for(ll j = 4; j <= n; j++){
            여긴 시간초과 
            temp = j;
            while(temp % 5 == 0){
                temp /= 5;
                cnt++;
            }

            아래는 에러 
            for(int k = 13; k > 0; k--){
                if(j == a[k] || j % a[k] == 0){
                    cnt += k;
                    break;
                }
            }
            
        }
            */
        cout << cnt << '\n';
    }
    
    return 0;
}