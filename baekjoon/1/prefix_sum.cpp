/**
 * 
 * array에 1번째부터 요소를 채워야 편함.
 * prefix sum은
 * idx: 0 1 2 3 4 5
 * val: 0 3 2 4 7 9
 * 일 때
 * psum[1] = arr[1]
 * psum[2] = arr[1] + arr[2]
 * psum[3] = arr[1] + arr[2] + arr[3] 
 * subfix sum은 대회에는 나오긴 하지만 코테엔 잘 안나옴.
*/

/**
 * 문제 
 * 입력:
 * n: 주어진 숫자 카드들, m: 합을 구해야하는 구간의 개수
 * 숫자 n개
 * 구간은 1 3, 1 5 이렇게 주어지는데 그럼 1~5번째 카드의 수 합을 구하면 됨.
 * 
 * 이 문제는 구간 쿼리. 어떤 구간 안에 포함된 수의 합을 구하는 것.
 * 구간 쿼리는 psum과 펜윅트리를 생각해야 한다.
 * 동적 배열일 때는 펜윅트리, 정적 배열일 때에는 psum을 써야 한다.
 * 8 3
 * 1 2 3 4 5 6 7 8
 * 1 4
 * 1 5
 * 3 5
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> split(string input, string delimiter){
    vector<int> ret;
    long long pos = 0;
    string token = "";
    while((pos = input.find(delimiter)) != string::npos){
        token = input.substr(0, pos);
        ret.push_back(atoi(token.c_str()));
        input.erase(0, pos + delimiter.length());
    }
    return ret;
}
int n, m, s, e;
string inputStr;
vector<int> v;
int psum[100005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(psum, 0, sizeof(psum));
    cin >> n >> m;
    // buffer에 \n가 남아있어서 .. 
    getline(cin, inputStr);
    getline(cin, inputStr);
    v = split(inputStr, " ");
    for(int i = 0; i < n; i++){
        psum[i+1] = psum[i] + v[i]; 
    }

    for(int i = 0; i < m; i++){
        cin >> s >> e;
        cout << psum[e] - psum[s-1] << '\n';
    }
}