#include<bits/stdc++.h>
using namespace std;
vector<int> adj[30];
queue<int> q;
int visited[100];

void bfs(int u){
    visited[u] = 1;
    q.push(u);
    while(q.size()){
        int cur = q.front(); q.pop();
        cout << cur << " 방문\n";
        for(int v : adj[cur]){
            if(!visited[v]){
                visited[v] = visited[cur] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
    adj[10].push_back(12);
    adj[10].push_back(14);
    adj[10].push_back(16);

    adj[12].push_back(18);
    adj[12].push_back(20);

    adj[20].push_back(22);
    adj[20].push_back(24);
    bfs(10);

    cout << "10에서 24까지 최단 거리: " << visited[24] -1 << '\n';
}