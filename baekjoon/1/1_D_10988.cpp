// https://www.acmicpc.net/problem/10988
#include<bits/stdc++.h>
using namespace std;
/**
 * 팰린드롬 = 회문 인지 체크
 * 앞으로 읽을 때와 거꾸로 읽을 때 똑같은 단어를 말함.
 * 
*/
string input;
int a[55], h;
bool flag = true;

int main(){
    memset(a, 0, sizeof(a));
    cin >> input;
    h = input.length()/2;
    for(int i =0; i < h; i++){
        if(input[i] - input[input.length()-1 - i] != 0){
            flag = false;
            break;
        }
    }
    if(flag) cout << "1";
    else cout << "0";
    
}