#include<bits/stdc++.h>
using namespace std;
const int V = 10;
vector<int> adj[V];
bool visited[V] = {0, };
void go(int from){
    visited[from] = 1;

    cout << from << "에 방문 ";
    for(auto it = adj[from].begin(); it != adj[from].end(); it++){
        if(visited[*it]) continue;
        cout << "-> ";
        go(*it);
    }
    /*
    for(int to : adj[from]){
        if(visited[to]) continue;
        go(to);
    }
    */

   return;
}
int main(){
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[3].push_back(4);

    adj[2].push_back(1);
    adj[3].push_back(1);
    adj[4].push_back(3);

    for(int i = 0; i < V; i++){
        cout << i << " : ";
        for(int there : adj[i]){
            cout << there << " ";
        }
        cout << '\n';
    }

    for(auto li : adj){
        for(auto from: li){
            if(!visited[from]){
                cout << from << "에서 시작 -> ";
                go(from);
                cout << '\n';
            }
        }
    }

    /*
    for(int i = 0; i < V; i++){
        // adj[i].size() 로 비어있는지 체크. 
        if(adj[i].size() && visited[i] == 0) go(i);
    }
    */
}