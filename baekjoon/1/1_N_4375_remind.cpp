// https://www.acmicpc.net/problem/4375
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// n의 배수 중 모든 자릿수가 1로 된 것 중 가장 작은 것이 몇 자리수인지.
// n = 3, 3*37 -> 111 -> 답: 3
// mod 연산의 법칙으로 풀어야 한다. .

int n, ret, mod;
bool flag;
ll num;
int main(){
    while(scanf("%d", &n) != EOF){
        ret = 0;
        mod = 0;
        while(true){
            // 1 % n, 11 % n, 111 % n, ... , 11111... % n과 같은 값을 가짐. 
            mod = (mod * (10 % n) + 1) % n;
            ret++;
            if(mod == 0){
                cout << ret << '\n';
                break;
            }
        }
    }
    /*
    이렇게 해도 ll을 벗어나는 숫자가 나온다...
    ll check[10000];
    check[0] = 1;
    for(int i = 1; i < 20; i++){
        check[i] = (check[i-1]*10)+1;
    }
 
    while(scanf("%d", &n) != EOF){
        num = n;
        
        int j = 0;
        while(true){
            if(check[j] % num == 0){
                break;
            }
            j++;
        }
        cout << j+1 << '\n';

        시간 초과
        while(true){
            //cout << "num: " << num << '\n';
            check = num;
            ret = 0;
            flag = true;
            while(true){
                if(check % 10 != 1) {
                    flag = false; 
                    break;
                }
                check /= 10;
                ret++;
                if(check == 0) break;
            }
            //cout << "flag: " << flag << '\n';
            if(flag) {
                cout << ret << '\n'; 
                break;
            }
            num += n;
        }

    }
    */
}