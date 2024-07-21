// https://www.acmicpc.net/problem/9996
#include<bits/stdc++.h>
using namespace std;

/**
 * 검색과 관련된 문제임.
 * a*d 는 abcd, abbd, aabd 등등 과 매칭될 수 있음.
*/
int n;
string s, temp, l, r;
bool f;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> s;
    // find를 사용할 수 있다.
    int pos = s.find('*');
    l = s.substr(0, pos);
    // 인자를 하나만 넣으면 시작지점부터 끝까지.
    r = s.substr(pos+1);

    /*
    아래처럼 풀게 되면
    ab*ab 일 때 ab가 맞다고 판명난다. 
    size 로 반례를 찾는 것에 익숙해지자. . 
    for(int i = 0; i < n; i++){
        cin >> temp;
        f = true;
        for(int j = 0; j < l.length(); j++){
            if(temp[j] != l[j]){
                f = false;
                break;
            }
        }

        for(int j = 0; j < r.length(); j++){
            if(temp[temp.length() - 1 - j] != r[r.length() -1 - j]){
                f = false;
                break;
            }
        }

        if(f) cout << "DA\n";
        else cout << "NE\n";
    }
    */
    for(int i = 0; i < n; i++){
        cin >> temp;
        f = true;
        if(l.size() + r.size() > temp.size()){
            cout << "NE\n";
        }else{
            if(l == temp.substr(0, l.size()) && r == temp.substr(temp.size() - r.size())) cout << "DA\n";
            else cout << "NE\n";
        }

    } 
}