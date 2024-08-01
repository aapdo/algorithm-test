// https://www.acmicpc.net/problem/2468
#include<bits/stdc++.h>
using namespace std;
int n, x, y, ret = 1, cnt, rain ;
int a[103][103], visited[103][103];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0 , -1};

void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if(!visited[ny][nx] && a[ny][nx] > rain) dfs(ny, nx);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    for(rain = 1; rain < 101; rain++){
        cnt = 0;
        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j] && a[i][j] > rain){
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        if(ret < cnt) ret = cnt;
    }
    cout << ret;
}
