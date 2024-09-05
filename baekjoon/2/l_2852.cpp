// https://www.acmicpc.net/problem/2852
// #include<bits/stdc++.h>
#include<iostream>
using namespace std;

int n, m, s, team, beforeWinner = 0, curWinner = 0, startTime = 0, t1 = 0, t2 = 0;
int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d %d:%d", &team, &m, &s);
        beforeWinner = curWinner;
        if(team == 1) curWinner++;
        else curWinner--; 

        if(beforeWinner == 0) startTime = m * 60 + s;
        if(curWinner == 0){
            // 0일 때라면 +나 -로 갈 때 .. 뭔가 어케 해야함. 
            if(beforeWinner > 0) t1 += (m*60 + s) - startTime;
            else if(beforeWinner < 0) t2 += (m*60 + s) - startTime;
            
            startTime = m*60 + s;
        }
    }
    if(curWinner > 0) t1 += (48*60) - startTime;
    else if(curWinner < 0) t2 += (48*60) - startTime;
    printf("%02d:%02d\n%02d:%02d\n", t1/60, t1%60, t2/60, t2%60);

    
    return 0;
}