#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a {1, 2, 3, 3, 3, 4};
    // 숫자 3의 lower bound, upper bound 를 가리키는 it 를 리턴함.
    cout << lower_bound(a.begin(), a.end(), 3) - a.begin() << '\n';
    cout << upper_bound(a.begin(), a.end(), 3) - a.begin() << '\n';

    cout << &*lower_bound(a.begin(), a.end(), 3) << '\n';
    cout << &*a.begin() << '\n';
    cout << &*(a.begin() + 1) << '\n';
    cout << &*(upper_bound(a.begin(), a.end(), 3) - 1)<< '\n';


    // 3의 개수를 셀 수도 있음. 
    // 하지만 해당 값이 없는 경우 그냥 그 근방 지점을 반환하기 때문에 실제로 사용하기에는 조금 제한적임. 
    cout << upper_bound(a.begin(), a.end(), 3) - lower_bound(a.begin(), a.end(), 3) << '\n';
    
    return 0;
}