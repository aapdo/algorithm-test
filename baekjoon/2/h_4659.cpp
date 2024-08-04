// https://www.acmicpc.net/problem/4659
#include<bits/stdc++.h>
using namespace std;
//char s[30];
string s;
bool flag, f1, f2, f3;
int three;
// prev 를 사용하는 것도 좋다 .
int main(){
    while(true){
        cin >> s;
        if(s.compare("end") == 0) break;
        f2 = false;
        f1 = f3 = true;
        three = 0;
        for(int i = 0; i < 30; i++){
            if(s[i] == '\0'){
                break;
            }
            if(s[i] == s[i + 1] && (s[i] != 'e' && s[i] != 'o')) {
                f1 = false;
                break;
            }
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                f2 = true;
                if(three >= 0) three++;
                else three = 1;
            }else{
                if(three <= 0) three--;
                else three = -1;
            }
            //cout << three << '\n';
            if(three == 3 || three == -3){
                f3 = false;
                break;
            }

        }
        cout << '<' << s << "> ";
        if(f1 && f2 && f3) cout << "is acceptable.\n";
        else cout << "is not acceptable.\n"; 
    }
    return 0;
}