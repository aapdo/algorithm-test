#include<bits/stdc++.h>

using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}
int main(){
    // array, vector sort. O(nlogn)
    // sort(first, last, *customFunc)
    vector<int> a;
    int b[5];
    for(int i = 5; i >= 1; i--) b[i-1] = i;
    for(int i = 5; i >= 1; i--) a.push_back(i);
    // last는 마지막 다음 요소.
    sort(b, b + 5);
    sort(a.begin(), a.end());
    for(int i : b) cout << i << ' ';
    cout << '\n';
    for(int i : a) cout << i << ' ';
    cout << '\n';

    sort(b, b + 5, less<int>());
    sort(a.begin(), a.end(), less<int>());
    for(int i : b) cout << i << ' ';
    cout << '\n';
    for(int i : a) cout << i << ' ';
    cout << '\n';

    sort(b, b + 5, greater<int>());
    sort(a.begin(), a.end(), greater<int>());
    for(int i : b) cout << i << ' ';
    cout << '\n';
    for(int i : a) cout << i << ' ';
    cout << '\n';
    cout << '\n';

    vector<pair<int, int>> v;
    for (int i = 10; i >= 1; i--){
        v.push_back({i, 10 - i});
    }
    // 기본적으로 first, second 순으로 차례차례 오름차순 정렬
    sort(v.begin(), v.end());
    for(pair<int, int> it : v) cout << it.first << " : " << it.second << '\n';
    cout << '\n';

    // first는 내림차순으로 하고 싶다면?
    sort(v.begin(), v.end(), cmp);
    for(pair<int, int> it : v) cout << it.first << " : " << it.second << '\n';
    /*
    cmp 가 true가 되는 순서대로 정렬한다.
    {3, 10, 4, 11}
    10 < 4 -> false 이므로 4, 10 순서로 바꿈.
    3 < 4 -> true 이므로 그대로.
    */
    cout << '\n';
    v.clear();
    for (int i = 10; i >= 1; i--){
        v.push_back({i, 10 - i});
    }
    // stable 한 sort도 있다.
    stable_sort(v.begin(), v.end(), cmp);
    for(pair<int, int> it : v) cout << it.first << " : " << it.second << '\n';

    return 0;

}