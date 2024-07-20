// https://www.acmicpc.net/problem/2309
#include<bits/stdc++.h>
using namespace std;

/**
 * 9개의 원소 중 7개를 더해서 100이 되는 것을 찾아야 한다.
 * 
 * 1. prefix sum 사용하기
 * 연달아 있지 않을 수 있음. 이건 기각.
 * 
 * 2. 9C2 만큼 브루트 포스
 * 9C2 = 9! / 2! 7! = 36개의 경우의 수만 탐색하면 됨.
 *
*/

vector<int> v;
int temp, n = 9, sum = 0, a = 0, b = 0;
bool flag = false;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i = 0; i < n; i++){
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += v[i];
    }
    
    // combination 인데 0~8 중 고려하지 않을 것 2개만 고르면 된다.
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            a = i;
            b = j;
            if(sum - v[i] - v[j] == 100){
                flag = true;
                break;
            }
        }
        if(flag){
            break;
        }
    }
    for(int i = 0; i < n; i++){
        if(i != a && i != b){
            cout << v[i] << '\n';
        }
    }
}