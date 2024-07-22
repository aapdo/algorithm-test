// https://www.acmicpc.net/problem/1940
#include<bits/stdc++.h>
using namespace std;

int n, m, cnt=0;
int a[15005];

/*
조합을 재귀 형태로 만들어서 풀 수도 있다.
void combi(int start, vector<int> &v){
    if(v.size() == 2){
        if(a[v[0]] + a[v[1]] == m) cnt++;
        return;
    }
    for(int i = start + 1; i < n; i++){
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
}
*/
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    //vector<int> v;
    //combi(-1, v);

    // 두 개를 합쳐서 20만 이상이 나올 수가 없음.
    // 시간 초과가 타이트하면 이런 것도 해야 함.
    if(m > 200000) cout << 0; return 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] + a[j] == m) cnt++;
        }
    }
    cout << cnt;
}