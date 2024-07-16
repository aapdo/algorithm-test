#include<bits/stdc++.h>

using namespace std;

int main(){
    string s = "1";
    string s2 = "amumu";
    cout << atoi(s.c_str()) << '\n';
    // 정수가 아닌 문자열인 경우 0
    // 숫자인지 체크할 때에도 사용됨.
    cout << atoi(s2.c_str()) << '\n';

    string s = "1234";
    int num = stoi(s);
    cout << num << '\n';
    // 아래 코드는 에러가 발생함. 위에서는 0이 나와서 그냥 처리하면 되서 쉬움.
    // cout << stoi(s2) << '\n';

    return 0;

}