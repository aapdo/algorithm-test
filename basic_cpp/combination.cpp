#include<bits/stdc++.h>
using namespace std;
/**
 * 순서가 상관 없을 때 뽑기
 * nCr = n! / ( n! * (n-r)! )
 * 
*/
int n = 5, k = 3, a[5] = {1, 2, 3, 4, 5};
void print(vector<int> b){
    for(int i : b) cout << i << ' ';
    // for(int i : b) cout << a[i] << ' ';
    cout << '\n';
}
// 외워라. 
void combi(int start, vector<int> b){
    if(b.size() == k){
        print(b);
        return;
    }
    for(int i = start + 1; i < n; i++){
        // 0 -> 0 1 -> 0 1 2
        b.push_back(i);
        combi(i, b);
        // 0 1 2 -> 0 1 로 바꾸고 다시 위로 올라감. 그러면 0 1 -> 0 1 3 
        b.pop_back();
    }
    return;
}

int main(){
    vector<int> b;
    combi(-1, b);

    cout << "--------------\n";

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){ // or j = i + 1; j < n
            for(int k = 0; k < j; k++){ // or k = j + 1; k < n 순서만 달라지는데 어차피 순서는 의미 없는 것이니까. 
                cout << i << " : " << j << " : " << k << '\n';
            }
        }
    }
    return 0;
}