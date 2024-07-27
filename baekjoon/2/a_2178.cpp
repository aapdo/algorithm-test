// https://www.acmicpc.net/problem/2178
#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0 , 1, 0};
const int dx[] = {0, 1, 0, -1};

int n, m, cury, curx;
int a[105][105], visited[105][105];
string s;
queue<pair<int, int>> q;
void bfs(int y, int x){
    q.push({y, x});
    visited[y][x] = 1;
    while(q.size()){
        tie(cury, curx) = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int ny = cury + dy[i];
            int nx = curx + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(!visited[ny][nx] && a[ny][nx]){
                q.push({ny, nx});
                visited[ny][nx] = visited[cury][curx] + 1;
            }
            if(ny == n - 1 && nx == m - 1){
                return;
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++){
            a[i][j] = int(s[j] - '0');
            // scanf("%1d", &a[i][j]);
            // 이렇게도 할 수 있다.
        }
    }
    bfs(0, 0);
    cout << visited[n-1][m-1];
    
}