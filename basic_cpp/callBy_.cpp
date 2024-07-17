#include<bits/stdc++.h>
using namespace std; 

vector<int> v(3, 0); 

/**
 * 값에 의한 호출의 경우 원본은 변경되지 않는다. 
*/
void go(vector<int> v){
    v[1] = 100; 
}

/**
 * 참조에 의한 호출의 경우 원본도 변경된다. 
*/
void go2(vector<int> &v){
    v[1] = 100;
}

/**
 * primitive 타입의 경우 call by value가 좋다.
 * 복사가 일어나지만 간단하고, 코스트가 적다. 함수 블럭 내부에 있어서 오히려 더 빠르다.
 * 
 * 하지만 struct나 많은 요소를 가진 배열, 객체 등은 참조가 낫다.
 * 복사하는데 코스트가 많이 들기 때문에.
 * 
*/

int main(){ 
    go(v);
    for(int i : v) cout << i << '\n'; 

    go2(v);
    for(int i : v) cout << i << '\n'; 
}