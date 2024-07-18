#include<bits/stdc++.h>
using namespace std;
/**
 * 순서가 있는 뽑기 -> 순열
 * 순서가 없는 뽑기 -> 조합
 * 
 * next_permutation: 오름차순인 배열으로 순열을 만듦.
 * prev_permutation: 내림차순인 배열으로 순열을 만듦.
 * next_permutation(from, to) 여기서 [from, to) 이다. 
 * 
 * nPr = n! / (n-r)!
 * 
 * 재귀 함수를 이용하여 순열을 구현하는 것이 일반적이다.
*/

vector<int> v;

void printV(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << ' ';
    }
    cout << '\n';
}

void makePermutation(int n, int r, int depth){
    if(r == depth){
        printV(v);
        return;
    }
    for(int i = depth; i < n; i++){
        // 1 2 3 -> 1 3 2
        swap(v[i], v[depth]);
        // 1 3 2인 상태에서 다시 순열 만듦. 
        makePermutation(n, r, depth + 1);
        // 1 3 2 -> 1 2 3 으로 돌리고 그 다음 반복할 준비를함.
        swap(v[i], v[depth]);
    }
    return;

}

int main(){
    int a[3] = {1, 2, 3};
    for(int i = 0; i < 3; i++) v.push_back(a[i]);
    do{
        printV(v);
        // 이런식으로 2개만 뽑을 수도 있다. 
        for(int i = 0; i < 2; i++){
            //cout << v[i] << ' '; 
        }
    }while(next_permutation(v.begin(), v.end()));
    cout << "--------------------\n";
    v.clear();

    for(int i = 2; i >= 0; i--) v.push_back(a[i]);
    do{
        printV(v);
    }while(prev_permutation(v.begin(), v.end()));
}