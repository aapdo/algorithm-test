#include<bits/stdc++.h>
using namespace std;

bool a[10][10];
bool visited[10] = {};

void go(int v){
    if(visited[v]){
        return;
    }
    cout << v << "번 노드 방문";
    visited[v] = 1;
    for(int i = 0; i < 10; i++){
        // v랑 i번째가 연결되어 있고, 방문한적이 없으면 
        if(a[v][i] && !visited[i]){
            cout << " -> ";
            go(i);
        }
    }
}

int main(){
    a[1][2] = 1;
    a[1][3] = 1;
    a[3][4] = 1;

    a[2][1] = 1;
    a[3][1] = 1;
    a[4][3] = 1;

    memset(visited, 0, sizeof(visited));

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            // i -> j 가 연결되어 있고, i에 방문한적 없으면 
            if(a[i][j] && !visited[i]){
                cout << i << "번 째 노드부터 시작 -> ";
                go(i);
                cout << "\n";
            }
        }
    }
     
}