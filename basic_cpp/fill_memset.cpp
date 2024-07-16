#include<bits/stdc++.h>
using namespace std;

int a[10];
int b[10][10];
int main(){
    // fill은 모든 숫자로 가능. O(N)
    // memset은 -1, 0으로만 가능. 
    // void fill(first, last, val);
    fill(&a[0], &a[10], 100);
    // fill(a, a + 10, 100);
    for(int i = 0; i < 10; i++){
        cout << a[i] << " ";
    }
    cout << '\n';
    fill(&b[0][0], &b[9][10], 2);
    // fill(b, b + 10 * 10, 100);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << '\n';
    }

    memset(a, -1, sizeof(a));

    for(int i = 0; i < 10; i++){
        cout << a[i] << " ";
    }
    cout << '\n';
    memset(b, 0, sizeof(b));
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << '\n';
    }
    // 아래는 불가능함. 
    memset(a, 'a', sizeof(a));
    for (int i = 0; i < 10; i++) cout << a[i] << ' '; //aaa ...
    cout << '\n';

    return 0;
    
}