#include<bits/stdc++.h>
using namespace std;

struct Test{
    int a, b;
    double c, d, e;
};
void print(Test test){
    cout << test.a << " " << test.b << " " << test.c << " " << test.c << " " << test.d << " " << test.e << '\n';
}
// 구조체 비교 함수를 만들 때에는 반드시 < 연산자를 사용해서 비교하도록 만들어야 함.
bool compare(Test a, Test b){
    if(a.a == b.a) return a.b < b.b;
    return a.a < b.a;
}

// point를 정의할 때 < 를 오버로딩해서 정렬할 때 기준으로 만들 수 있음.
// sort 함수 자체가 < 오퍼레이터를 사용함. 반드시 <로 구현해야함. 
struct Point{
    int y, x;
    Point(int y, int x) : y(y), x(x) {}
    Point(){y = -1; x = -1;}
    // x가 같으면 y로 정렬. x가 먼저임.
    bool operator < (const Point &a) const{
        if(x == a.x) return y < a.y;
        return x < a.x;
    }
};

// 변수가 3개라면?
struct Point3D{
    int y, x, z;
    Point3D(int y, int x, int z) : y(y), x(x), z(z) {}
    Point3D(){y = -1, x = -1, z = -1;}
    bool operator < (const Point3D &a) const{
        if(x == a.x){
            if(y == a.y) return z < a.z;
            return y > a.y;
        }
    }

};

int main(){
    Test test = {1, 1, 1, 1, 1};
    print(test);
    vector<Test> ret;
    ret.push_back({1,2,3,4,5});
    ret.push_back({1,2,3,6,7});
    ret.push_back({});
    ret.push_back({1, 3});
    for(Test test: ret) print(test);

    vector<Point> vp;
    for(int i = 10; i >= 1; i--){
        vp.push_back({i, 10-i});
    }
    sort(vp.begin(), vp.end());
    for(auto it : vp) cout << it.y << " : " << it.x << '\n';
    return 0;
}