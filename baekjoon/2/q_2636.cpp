// https://www.acmicpc.net/problem/2636
#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[105][105]; 
int vis[105][105];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int cnt = 0;
int prevCnt = 0;
vector<pair<int, int>> v;
void dfs(int y, int x){
    vis[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m || vis[ny][nx] == 1) continue;
        if(a[ny][nx] == 1) {
            v.push_back({ny, nx});
            vis[ny][nx] = 1;
            cnt++;
        }
        else dfs(ny, nx);
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    int i = 0;
    while(true){
        memset(vis, 0, sizeof(vis));
        prevCnt = cnt;
        cnt = 0;
        dfs(0, 0);
        if(cnt == 0){
            break;
        }
        i++;
        for(auto it = v.begin(); it != v.end(); it++){
            a[it->first][it->second] = 0;
        }
    }


    cout << i << '\n' << prevCnt << '\n';

    
    return 0;
}