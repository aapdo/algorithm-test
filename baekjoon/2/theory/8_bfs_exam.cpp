#include<bits/stdc++.h>
using namespace std;
int a[105][105], visited[105][105];
int n, m, ret = 0, sy, sx, ey, ex;
const int dy[] = {-1 , 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
queue<pair<int, int>> q;
void bfs(int y, int x){
    q.push({y, x});
    // 종종 초기에 visited 처리를 안하는 경우가 있는데 이걸 무조건 해야 한다.
    // 양방향 간선으로 초기 상태로 돌아올 수도 있다면 따로 처리를 해줘야하는 불편함이 생긴다.
    visited[y][x] = 1;
    while(q.size()){
        int cury = q.front().first;
        int curx = q.front().second;
        // tie(cury, curx) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = cury + dy[i];
            int nx = curx + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(!visited[ny][nx] && a[ny][nx]){
                visited[ny][nx] = visited[cury][curx] + 1;
                if(ny == ey && nx == ex){
                    cout << visited[ny][nx] - 1;
                    break;
                }
                q.push({ny, nx});
            }
        }
    }
}
int main(){
    cin >> n >> m >> sy >> sx >> ey >> ex;
    for(int i = 0; i < n; i++){
        for(int j =0; j < n; j++){
            cin >> a[i][j];
        }
    }
    bfs(sy, sx);

}