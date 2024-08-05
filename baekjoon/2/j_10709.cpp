// https://www.acmicpc.net/problem/10709
#include<bits/stdc++.h>
using namespace std;
int h, w, pre;
int a[105][105];
string s;
int main(){
    cin >> h >> w;
    for(int i = 0; i < h; i++){
        cin >> s;
        for (int j = 0; j < w; j++)
        {
            if(s[j] == 'c') a[i][j] = 0;
            else a[i][j] = -1;
        }
    }
    for(int i = 0; i < h; i++){
        pre = -1;
        for (int j = 0; j < w; j++)
        {
            if(a[i][j] == 0) pre = -1;
            if(pre >= 0) a[i][j] = pre+1;
            pre = a[i][j];
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    
    
    return 0;
}