// https://www.acmicpc.net/problem/2583
#include<bits/stdc++.h>
using namespace std;
#define y1 aaaa

int n, m, k, x1, x2, y1, y2;
int a[105][105], visited[105][105];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
vector<int> ret;
int mx = 0;
void bfs(int y, int x){
    queue<pair<int, int>> q;
    visited[y][x] = 1;
    q.push({y, x});
    mx = 0;
    while(q.size()){
        tie(y, x) = q.front(); q.pop();
        mx++;
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(!visited[ny][nx] && !a[ny][nx]) {
                q.push({ny, nx});
                visited[ny][nx] = 1;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n >> k;
    memset(a, 0, sizeof(a));
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < k; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = m - y2; j < m - y1; j++){
            for(int ij = x1; ij < x2; ij++){
                a[j][ij] = 1;
            }
        }
        /*
        // 뒤집어서 만들어도 사실 상관 없음. 
        cin >> x1 >> y1 >> x2 >> y2;
        for(int x = x1; x < x2; x++){
            for(int y = y1; y < y2; y++){
                a[y][x] = 1;
            }
        }
        */
    }
    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if(visited[i][j] == 0 && a[i][j] == 0){
                bfs(i, j);
                if(mx) ret.push_back(mx);
            }
        }
    }

    sort(ret.begin(), ret.end());
    cout << ret.size() << '\n';    
    for(auto it : ret){
        cout << it << ' ';
    }

}