// https://www.acmicpc.net/problem/14502
/* 방법1: 64C3 벽을 칠 곳 3곳을 그냥 정하고 그렇게 했다 치고 2를 bfs로 확산시킴. 그 담에 0의 개수를 센다. */
/*
 0  1  2  3  4
 5  6  7  8  9
10 11 12 13 14
*/
#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[10][10];
int base[10][10];
int v[10][10];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int cnt = 0;
int maxi = -1;
void dfs(int y, int x){
    v[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny >= n || ny < 0 || nx >= m || nx < 0) continue;
        if(a[ny][nx] == 0){
            a[ny][nx] = a[y][x]+1;
            dfs(ny, nx);
        } 
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> base[i][j];
        }
    }
    memcpy(a, base, sizeof(a));
    // 0~n*m 사이에서 중복 불가, 순서 상관 없이 3개 뽑기
    for(int i = 0; i < n*m; i++){
        if(a[i / m][i % m] != 0) continue;

        for(int j = i+1; j < n*m; j++){
            if(a[j / m][j % m] != 0) continue;

            for(int k = j+1; k < n*m; k++){
                if(a[k / m][k % m] != 0) continue;
                a[i/m][i%m] = 3;
                a[j/m][j%m] = 3;
                a[k/m][k%m] = 3;
                memset(v, 0, sizeof(v));
                
                for(int ii = 0; ii < n; ii++){
                    for(int jj = 0; jj < m; jj++){
                        if(a[ii][jj] != 2) continue;
                        dfs(ii, jj);
                    }
                }

                cnt = 0;
                for(int ii = 0; ii < n; ii++){
                    for(int jj = 0; jj < m; jj++){
                        if(a[ii][jj] == 0) cnt++;
                    }
                }
                if(maxi < cnt) maxi = cnt;

                memcpy(a, base, sizeof(a));
            }
        }
    }
    cout << maxi << '\n';
    return 0;
}