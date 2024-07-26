균형 이진 트리: 모든 노드의 왼쪽 하위트리와 오른쪽 하위 트리의 높이 차이가 1 이하인 트리
BST: 모든 노드의 왼쪽 자식 노드는 부모보다 작고, 오른쪽 자식 노드는 큰 값을 가지는 이진 트리 -> 불균형할 수 있음.
 --> avl tree, rb tree 등으로 바꿔서 균형잡히게 만듦.
리
## 그래프와 트리
### 그래프와 트리를 표현하는 방법
1. 인접 행렬
vertex 개수가 N일 때
NxN 행렬을 만듦. 
map[n][m] == 1 이면 노드 n과 m이 연결됨.
만약 map[n][n] == 1 이면 자기 자신으로 돌아오는 사이클이 있는 것.

```
const int n = 4;
const int m = 4;
bool a[n][m] ={
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 0},
    {1, 0, 0, 0}
};
n, m순서로 돌려도 되고 
for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++) 
}

이렇게 m, n 로 돌려도 된다. 근데 위 방식이 더 빠름. 메모리 캐싱 때문에.
for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++) 
}
```

2. 인접 리스트
linked list를 여러 개 만들어서 표현하는 방식.


인접 행렬과 인접 리스트 중 뭘 써야할까?
- 공간 복잡도
인접 행렬: O(V^2)
인접 리스트: O(V + E) 
 -> E가 들어간 이유는 연결된 정점만 리스트에 들어가니까.

- 시간 복잡도: 간선 한 개 찾기
인접 행렬: O(1)
인접 리스트: O(V) (최악)

- 시간 복잡도: 간선 모두 찾기
인접 행렬: O(V^2)
인접 리스트: O(V + E)

그래프가 희소하면 인접 리스트
그래프가 조밀할 때는 인접 행렬을 쓰는게 좋다.
-> 코테에서는 보통 희소하니까 문제에서 인접 행렬을 주는게 아니라면 인접 리스트를 쓰는게 더 좋다.


map의 형태로 그래프가 주어지는 경우가 있다.
지도를 인접 리스트나 인접 행렬로 바꿔서 푸는 것은 비효율적이다.
보통 문제에서는 4방향으로 탐색할 수 있다는 조건이 있다.

### 연결된 컴포넌트
연결된 컴포넌트는 연결된 하위 그래프를 의미함. 

1 - 2  3 - 4 - 5 6 - 7
이렇게 연결되어 있을 때 3이랑 5는 직접 연결되어 있지 않지만 4를 통해 지나갈 수 있어서 같은 컴포넌트다.
위에선 총 3개의 컴포넌트가 있다. 
컴포넌트 별로 번호를 부여하는 알고리즘을 flood fill 이라고 함.
## 그래프 탐색
### DFS
갈수 있을 때까지 탐색하고 돌아옴. 스택에 담거나 재귀를 사용함.

DFS(u, adj)
    u.visited = 1
    for v in adj[u]
        if u.visited = 0
            dfs(v, adj)

### BFS
레벨별로 탐색하는 것. 큐를 사용.
최단 거리 탐색이 가능하다.
visited 는 최단 거리를 담는 용도로도 사용된다.

BFS(G, u)
    u.visited = 1;
    queue q;
    q.push(u);
    while(q.size()){
        int u = q.front();
        q.pop();
        for v in G.adj[u]
            if(!v.visited) 
                v.visited = u.visited 1;
                q.push(v)
    }

### DFS, BFS 비교
시간 복잡도는 차이가 없다.
DFS: 메모리를 덜 씀. 절단점 등을 구할 수 있고 코드가 좀 더 짧으며 완전탐색의 경우에 많이 씀.
BFS: 메모리를 더 씀. 가중치가 같은 그래프 내에서 최단거리 찾기 가능. 코드가 더 김.

## 트리 순회
보통 이진 트리를 기반으로 설명함. 근데 일반적인 트리에서도 사용할 수 있음.

### 후위 순회
자식 노드를 모두 방문하고 자신을 방문함.
postorder( node )
    if(node.visited == false){
        postorder(node->left)
        postorder(node->right)
        node.visited = true
    }

### 전위 순회 
자신의 노드를 먼저 방문하고 자식 노드를 방문함. (dfs랑 비슷)
preorder( node )
    if(node.visited == false){
        node.visited = true
        preorder(node->left)
        preorder(node->right)
    }

### 중위 순회
왼쪽 자식 노드, 자기 자신, 오른쪽 자식 노드 순서로 방문함. 
inorder( node )
    if(node.visited == false){
        inorder(node->left)
        node.visited = true
        inorder(node->right)
    }
