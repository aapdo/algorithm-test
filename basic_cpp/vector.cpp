#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    for(int i = 0; i <= 10; i++) v.push_back(i);
    for(int i : v) cout << i << ' ';
    cout << '\n';

    // 시작부터 3개의 요소 삭제
    // erase(from, to) 여기서 [from, to)임. v.begin() + 3 이 가리키는 것은 idx 3인데 0~2만 삭제됨.
    v.erase(v.begin(), v.begin() + 3);    
    for(int i : v) cout << i << ' ';
    cout << '\n';
    
    // it find(from, to, value);
    auto a = find(v.begin(), v.end(), 100);
    if(a == v.end()) cout << "not found\n";

    fill(v.begin(), v.end(), 10);
    for(int i : v) cout << i << ' ';
    cout << '\n';

    v.clear();
    cout << "아무것도 없음.\n";
    for(int i : v) cout << i << ' ';
    cout << "\n\n";
    
    // size = 5, value = 100
    vector<int> v2(5, 100);
    for(int i : v2) cout << i << ' ';
    cout << '\n';

    // 2dimension vector
    // vector 안에 vector가 있는 형태
    vector<vector<int>> v2d;
    for(int i = 0; i < 10; i++){
        vector<int> temp;
        v2d.push_back(temp);
    }
    // 초기화할 때 2차원으로 바로 넣기.
    vector<vector<int>> v2d_2(10, vector<int>(10, 0));
    // v3는 10개짜리 배열.
    vector<int> v3[10];
    v3[0].push_back(1);

}