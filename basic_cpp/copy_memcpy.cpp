#include<bits/stdc++.h>

using namespace std;
int main(){
    // memcpy() copy() is deep copy
    // void* memcpy(void* destination, const void* source, size_t num)
    int v[3] = {1, 2, 3};
    int ret[3];
    memcpy(ret, v, sizeof(v));
    cout << ret[1] << '\n';
    ret[1] = 100;
    cout << ret[1] << '\n';
    cout << v[1] << '\n';

    // memcpy vector는 deep copy 아님.
    // memcpy는 array에만 사용 가능.
    vector<int> v1{1,2,3};
    vector<int> ret1(3);
    if(is_trivial<vector<int>>()){
        cout << "vector can copy!\n";
        memcpy(&ret1, &v1, 3 * sizeof(int));
        ret1[1] = 100;
        cout << ret1[1] << '\n';
        cout << v1[1] << '\n';
    }

    // =============================== //

    // copy는 array vector에 모두 가능. memcpy와 같은 동작
    // copy(first, last, result)
    copy(v1.begin(), v1.end(), ret1.begin());
    ret1[1] = 100;
    cout << ret1[1] << '\n';
    cout << v1[1] << '\n';


    return 0;
}