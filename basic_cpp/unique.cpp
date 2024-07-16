#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v; // 1 1 2 2 3 3 4 4 5 5
    for (int i = 1; i <= 5; i++){
        v.push_back(i);
        v.push_back(i);
    }
    for(int i : v) cout << i << ' ';
    cout << '\n';
    // 중복되지 않은 요소로 채운 후 그 다음 이터레이터 리턴.
    // O(n)
    // 1 2 3 4 5 3 4 4 5 5 가 되는데, 
    auto it = unique(v.begin(), v.end()); 
    cout << it - v.begin() << '\n'; // 5가 나오는데 5부터 중복되는 애들이 있다는 뜻임.
    // 앞부터 중복되지 않게 채우고 나머지 요소는 그대로. 
    for(int i : v) cout << i << ' '; // 1 2 3 4 5 3 4 4 5 5
    cout << "\n\n";
    for (int i = 0; i < it - v.begin(); i++){
        cout << v[i] << ' ';
    }
    cout << '\n';
    // or erase 를 써서 0~중복 없는 곳까지 빼고 지울 수 있음.
    // erase(from, to);
    // it는 중복될 수도 있는 지점 시작하는 it, end는 끝. 즉 중복되지 않는 요소 빼고 전부 날림.
    v.erase(it, v.end());


    /*
    앞에서부터 차근차근 없애는 것이기 때문에 sort를 이용한 다음 사용해야함.
    */
    
    v = {2, 1, 1, 2, 2, 3, 4, 4, 6, 5, 5, 6};
    it = unique(v.begin(), v.end());
    for(int i : v) cout << i << ' '; // 2 1 2 ...
    cout << "\n\n";

    v = {2, 1, 1, 2, 2, 3, 4, 4, 6, 5, 5, 6};
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i : v) cout << i << ' '; // 2 1 2 ...
    cout << "\n";



    return 0;
    
}