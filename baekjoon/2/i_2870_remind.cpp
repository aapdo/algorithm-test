// https://www.acmicpc.net/problem/2870
#include<bits/stdc++.h>
using namespace std;
string s, tmp_s;
int n, tmp;
// 10글자가 넘으면 int 불가,
// 100글자가 넘으면 long long 불가 
vector<string> v;
void pushV(string s){
    if(s.size() == 0) return;
    int idx = -1;
    if(s[0] != '0') v.push_back(s);
    else{
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '0'){
                idx = i;
                break;
            }
        }
        //cout << "idx: " << idx << '\n';
        if(idx == -1){
            v.push_back("0");
        }else{
            s.erase(s.begin(), s.begin() + idx);
            v.push_back(s);
        }
    }
}
// true 가 나오면 스왑함 
bool cmp(string a, string b){
    if(a.size() == b.size()){
        return a < b;
    }
    return a.size() < b.size();
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> s;
        tmp_s = "";
        for(int j = 0; j < s.size(); j++){
            if(0 <= s[j] - '0' && s[j] - '0' <= 9){
                tmp_s += s[j];
            }else{
                pushV(tmp_s);
                tmp_s = "";
            }
        }
        pushV(tmp_s);
    }
    sort(v.begin(), v.end(), cmp);
    //sort(v.begin(), v.end());
    for(string it : v){
        cout << it << '\n';
    }
    
    return 0;
}