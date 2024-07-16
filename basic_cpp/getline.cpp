#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    string s;
    string bufferFlush;
    cin >> t;
    // 위 입력으로 인해 버퍼에 \n가 남게 됨. 그걸 플러쉬하고 받아야함.
    getline(cin, bufferFlush);
    for (int i = 0; i < t; i++)
    {
        getline(cin, s);
        cout << s << "\n";
    }
    

    return 0;
}