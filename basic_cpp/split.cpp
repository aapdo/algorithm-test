#include<bits/stdc++.h>
using namespace std;
vector<string> split(string input, string delimiter){
    vector<string> ret;
    long long pos = 0;
    string token = "";
    while( (pos = input.find(delimiter)) != string::npos){
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos+delimiter.length());
    }
    ret.push_back(input);
    return ret;
}

int main(){
    string s = "Hi my name is jy";
    vector<string> a = split(s, " ");
    for(string b: a) cout << b << '\n';

    // unsigned int 라서 int로 바꿔줘야함.
    cout << (int)a.size() << '\n';
}