#include<bits/stdc++.h>
using namespace std;

/**
 * heap은 완전 이진트리로 최소힙과 최대힙이 있음.
 * 삽입 삭제 수정 탐색 O(logN)
 * 최대 힙은 루트에 최대값, 최소힙은 루트에 최소값
 * pq는 기본적으로 max heap을 사용한다. 
 * 그니까 큰 값이 우선순위가 높게 된다.
*/
struct Point{
    int y, x;
    Point(int y, int x) : y(y), x(x) {}
    Point(){y = -1; x = -1;}
    // < 연산자 오버로딩인데 x > a.x 로 만듦.
    // 비교 연산자가 true를 반환하는 요소를 더 낮다고 판단함.
    // Point a < Point b 이렇게 연산했을 때 true가 나오면 b가 우선순위가 높음.
    // Point a < Point b 를 했을 때 a의 x가 더 크면 true가 나옴.
    // 그니까 x가 더 큰게 우선 순위가 낮다고 정의하는 거임.
    bool operator < (const Point &a) const{
        return x > a.x;
    }
};
// 최소 힙 구조를 만들 때 사용함.
// priority_queue<int, vector<int>, cmp> pq;
struct cmp{
    bool operator () (const int& a, const int& b){
        return a > b;
    }
};
int main(){
    priority_queue<int, vector<int>, greater<int> > pq; //오름차순
    priority_queue<int> pq2; // 내림차순
    priority_queue<int, vector<int>, less<int> > pq3; // 내림차순
    priority_queue<int, vector<int>, cmp> pq4; // 최소힙 -> 작은게 우선순위 높음. 
    for(int i = 5; i >= 1; i--){
        pq.push(i);
        pq2.push(i);
        pq3.push(i);
    }
    while(pq.size()){
        cout << pq.top() << " : " << pq2.top() << " : " << pq3.top() << '\n';
        pq.pop(); pq2.pop(); pq3.pop();
    }
    cout << '\n';

    // Point를 만들 때에는 x가 더 큰 녀석이 우선순위가 낮음.
    priority_queue<Point> pqPoint;
    pqPoint.push({1, 1});
    pqPoint.push({2, 2});
    pqPoint.push({3, 3});
    pqPoint.push({4, 4});
    pqPoint.push({5, 5});
    pqPoint.push({6, 6});
    pqPoint.push({6, 7});
    // 출력해보면 제일 작은 녀석이 나옴. 
    cout << pqPoint.top().x << '\n';
    return 0;
}