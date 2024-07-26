#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int a[102][102];
int visited[102][102];
int n, m, cnt = 0;
void dfs(int y, int x){
    visited[y][x] = 1;

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if(!visited[ny][nx] && a[ny][nx]) dfs(ny, nx);
    }

}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && a[i][j]){ 
                dfs(i, j);
                cnt++;
            }

        }
    }

    cout << cnt << '\n';

}