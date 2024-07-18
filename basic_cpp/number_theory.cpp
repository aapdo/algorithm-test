#include<bits/stdc++.h>
using namespace std;

// 최대 공약수 구하기.
int gcd(int a, int b){
    if(a == 0) return b;
    return gcd(b % a, a);
}
// 최대 공배수 구하기
int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}
/**
 * 모듈러 연산: 어디선가 봤던 기억이... 
 * [(a mod n) + (b mod n)] mod n = (a+b) mod n
 * [(a mod n) - (b mod n)] mod n = (a-b) mod n
 * [(a mod n) * (b mod n)] mod n = (a*b) mod n
*/

// 에라토스테네스의 체
const int max_n = 40;
bool che[max_n + 1];
// max_n 까지의 소수를 만드는 함수.
vector<int> era(int mx_n){
    vector<int> v;
    for(int i = 2; i <= mx_n; i++){
        if(che[i]) continue;
        for(int j = 2 * i; j <= mx_n; j += i){
            che[j] = 1;
        }
    }
    for(int i = 2; i <= mx_n; i++) if(che[i] == 0) v.push_back(i);
    return v;
}
// 위는 일정 크기 이상이 되면 쓰기 어렵다. 이럴 땐 일일히 체크하는 함수를 만들어야함.
bool isPrime(int n){
    if(n <= 1) return 0;
    else if(n == 2) return 1;
    else if(n % 2 == 0) return 0;
    for (int i = 3; i * i <= n; i++){
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(){

    // 등차 수열의 합
    int n = 5, ret = 0;
    for(int i = 1; i <= n; i++){
        ret += i;
    }
    cout << ret << '\n';
    cout << n * (n + 1) / 2 << '\n';
    // 등차 수열의 합 공식: Sn = n(a+l)/2 a:초항 l: 끝항 
    int a = 3, l = 23;
    cout << n * (a + l) / 2 << '\n';

    // 등비 수열의 합
    // a(r^n -1) / r - 1  or a/(1-r)
    a = 1; n = 4;
    int r = 2; 
    vector<int> v;
    cout << a * ((int)pow(2, n) - 1) / (r-1);
    cout << '\n';
    for(int i = 0; i < n; i++){
        v.push_back(a);
        a *= r;
    }
    for(int i: v) cout << i << ' ';
    cout << '\n';

    // 승수 구하기
    n = 4;
    // double 타입으로 리턴함. 
    int pow_2 = (int)pow(2, n);
    cout << pow_2 << '\n';
    
    // 제곱근 구하기
    n = 16;
    ret = (int)sqrt(n);
    cout << ret << '\n';

}