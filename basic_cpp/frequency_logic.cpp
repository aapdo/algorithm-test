#include<bits/stdc++.h>
using namespace std;

// 2차원 배열 90도 회전하기. array로는 어렵고 벡터로 하는게 편함.
// 외우기 힘들어도 right 하나는 외우자.
void rotate_left_90(vector<vector<int>> &key){
    int n = key.size();
    int m = key[0].size();
    vector<vector<int>> temp(m, vector<int>(n,0));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            temp[i][j] = key[j][m - i - 1];
        }
    }
    key.resize(m);
    key[0].resize(n);

    key = temp;
    return;
}

void rotate_right_90(vector<vector<int>> &key){
    int n = key.size();
    int m = key[0].size();
    vector<vector<int>> temp(m, vector<int>(n, 0));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            temp[i][j] = key[n - j - 1][i];
        }
    }
    key.resize(m);
    key[0].resize(n);

    key = temp;
    return;
}

// n = m 인 경우. 이건 꼭 외우자.
void rotate_right_90_nm(vector<vector<int>> &key){
    int n = 3;
    vector<vector<int>> temp(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            temp[i][j] = key[n - j - 1][i];
        }
    }
    key = temp;
    return;
}

// 대칭 만들기 
void symmetric(vector<vector<int>> &v){
    int b[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            b[j][i] = v[i][j];
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << b[i][j] << " ";
        }
        cout << '\n';
    }
}
// 진법 변환
void dec_to_bin(){
    vector<int> v;
    int n = 100;
    // b를 3으로 바꾸면 3진수. 
    int b = 2;
    while(n > 1){
        v.push_back(n % b);
        n /= b;
    }
    if(n == 1) v.push_back(1);
    reverse(v.begin(), v.end());
    for(int a: v){
        // if(a >= 10) 조건은 16진법 변환을 위해 필요함.
        if(a >= 10) cout << char(a+55);
        else cout << a;
    }
    return;
}

/**
 * 자주 나오는 숫자
 * 10! = 3628800
 * 2^10 = 1024
 * 3^10 = 59049
 * 
 * 실수 연산 후 ==을 사용하면 정확하지 않을 수 있다.
 * 0.1 + 0.1 + 0.1 + 0.1 - 1 < 1e-9 처럼 써서 오차율 내로 들어오는지 체크하는 식으로 해라.
*/

int main(){
    // 1차원 배열 회전
    vector<int> v = {1, 2, 3, 4, 5, 6};
    // first, middle, last
    // shift left
    rotate(v.begin(), v.begin() + 2, v.end());
    for(int i : v) cout << i << ' ';
    cout << '\n';
    v.clear();
    // 시계 방향은 rbegin, rend를 쓰면 된다.
    for(int i = 1; i <= 6; i++) v.push_back(i);
    rotate(v.rbegin(), v.rbegin() + 1, v.rend());
    for(int i : v) cout << i << ' ';
    cout << "\n\n";

    vector<vector<int>> a = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
    };
    int n = 3, m = 4;
    rotate_right_90(a); 
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){ 
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }

    
}