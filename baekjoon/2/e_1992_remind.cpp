// https://www.acmicpc.net/problem/1992
#include<bits/stdc++.h>
using namespace std;
#define y1 aaa
int n;
char a[128][128];
bool flag;
string s;
/*
string solution(int x1, int y1, int x2, int y2){
    int s = a[y1][x1];
    retr = s + '0';
    flag = false; 
    if(x2 - x1 < 2) return retr;
    for(int i = y1; i < y2; i++){
        for(int j = x1; j < x2; j++){
            flag = true;
            if(s != a[i][j]) {
                // 재귀
                flag = false;
                cout << x1 << " : " << y1 << " / " << x2 << " : " << y2 << '\n';
                cout << '\n';
                return "(" + solution(x1, y1, x2/2, y2/2) + solution(x2/2, y1, x2, y2/2)
                + solution(x1, y2/2, x2/2, y2) + solution(x2/2, y2/2, x2, y2) + ")";
            }
        }
    }
    if(flag) return retr;
}
*/
string solution(int y, int x, int size){
    if(size == 1) return string(1, a[y][x]);
    char b = a[y][x];
    string ret = "";
    bool flag = 0;
    for(int i = y; i < y + size; i++){
        for(int j = x; j < x + size; j++){
            if(b != a[i][j]){
                ret += '(';
                ret += solution(y, x, size/2);
                ret += solution(y, x + size / 2, size/2);
                ret += solution(y + size/2, x, size / 2);
                ret += solution(y + size / 2, x + size /2 , size /2);
                ret += ')';
                return ret;
            }
        }
    }
    return string(1, a[y][x]);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < n; j++){
            a[i][j] = s[j];
        }
    }
    cout << solution(0, 0, n);
    return 0;
}