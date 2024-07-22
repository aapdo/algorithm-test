// https://www.acmicpc.net/problem/1629
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a, b, c, base;
ll solve(ll a, ll b){
    if(b == 1) return base;
    ll ret = solve(a, b/2);
    ret = (ret * ret) % c;
    if(b & 1) ret = (ret * a) % c;
    return ret;
}

int main(){
    cin >> a >> b >> c;
    // a ** b  % c
    base = a % c;
    cout << solve(a, b);

}
/* dp 를 썼는데 이러면 메모리 초과가 난다.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a, b, c, ret;
map<int, int> mp;
ll solve(ll a, ll b){
    if(mp[b] != 0){
        return mp[b];
    }
    // mp[b] = a^b mod c
    // sovle(a, b/2, c) = a^(b/2) mod c
    // sovle(a, b/2 + 1, c) = a^(b/2 + 1) mod c
    ll ret = solve(a, b/2);
    // ret * ret 을 하는데, 만약 c가 21억이어서 ret이 20억이라면?
    // overflow가 생긴다. 
    ret = (ret*ret) % c;
    if(b & 1) ret = (ret * (a % c)) % c;
    return ret;
}

int main(){
    cin >> a >> b >> c;
    // a ** b  % c
    mp[0] = 0;
    mp[1] = a % c;
    cout << solve(a, b);
}
*/