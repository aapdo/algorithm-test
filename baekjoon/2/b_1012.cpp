// https://www.acmicpc.net/problem/1012
#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int tc, n, m, k, y, x, ret;
int a[55][55], visited[55][55];
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> tc;
    for(int i = 0; i < tc; i++){
        cin >> m >> n >> k;
        memset(a, 0, sizeof(a));
        memset(visited, 0, sizeof(visited));
        for(int j = 0; j < k; j++){
            cin >> x >> y;
            a[y][x] = 1;
        }
        ret = 0;
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                if(!visited[j][k] && a[j][k]) {
                    ret++;
                    dfs(j, k);
                }
            }
        }
        cout << ret << '\n';
    }
}