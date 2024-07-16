#include<bits/stdc++.h>
using namespace std;

int main(){
    const int mxy = 3;
    const int mxx = 4;
    int a[mxy][mxx];
    for (int i = 0; i < mxy; i++)
    {
        for (int j = 0; j < mxx; j++)
        {
            a[i][j] = (i + j);
        }
    }

    // good
    for (int i = 0; i < mxy; i++)
    {
        for (int j = 0; j < mxx; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

    // bad
    // 배열은 2차원이어도 메모리에는 일직선으로 연결되어 있으니까 캐시 히트율이 높이지기 위해서는 이렇게 해야함.
    for (int i = 0; i < mxx; i++)
    {
        for (int j = 0; j < mxy; j++)
        {
            cout << a[j][i] << ' ';
        }
        cout << '\n';
    }
    
    
}