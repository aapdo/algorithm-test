#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<string> stk;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stk.push("um");
    stk.push("jun");
    stk.push("sik");
    stk.push("화이팅");
    while(stk.size()){
        cout << stk.top() << '\n';
        stk.pop();
    }
    return 0;

}