#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10];
int visited[10];
void dfs(int u){
    visited[u] = 1;
    cout << u << "에 방문\n";

    for(int v : adj[u]){
        if(!visited[v]) dfs(v);
    }
    cout << u << "로부터 시작된 함수가 종료됨.\n";
}
int main(){
    /*
    1 -> 2 <-> 4
            -> 5
      -> 3
    */
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);
    adj[4].push_back(2);

    dfs(1);

}