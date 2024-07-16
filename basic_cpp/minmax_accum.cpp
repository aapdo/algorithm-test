#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // 뒤에 0은 다 더한 값에 추가로 더할 값.
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << sum << "\n\n";

    int maxi = *max_element(v.begin(), v.end());
    auto maxi_it = max_element(v.begin(), v.end());
    cout << maxi << ' ';
    // maximum index
    cout << (int) (maxi_it - v.begin()) << "\n\n";

    int mini = *min_element(v.begin(), v.end());
    auto mini_it = min_element(v.begin(), v.end());
    cout << mini << ' ';
    // minimum index 
    cout << (int) (mini_it - v.begin()) << '\n';

    return 0;
}