#include<bits/stdc++.h>
using namespace std;

int main(){
    // 중복을 허용하지 않음. pair, int 등을 넣을 수 있음.
    set<pair<string, int>> st;
    st.insert({"test", 1});
    st.insert({"test", 1});
    st.insert({"test", 1});
    st.insert({"test", 1});

    cout << st.size() << "\n\n";

    set<int> st2;
    st2.insert(2);
    st2.insert(1);
    st2.insert(2);
    for(auto it : st2) cout << it << '\n';

    // multiset은 중복이 가능. 
    multiset<int> s;
    for (int i = 5; i >= 1; i++){
        s.insert(i);
        s.insert(i);
    }
    for(int it : s ) cout << it << ' ';
    cout << '\n';

    return 0;
}