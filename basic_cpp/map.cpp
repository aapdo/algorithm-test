#include<bits/stdc++.h>
using namespace std;

int main(){
    // rb tree 로 구현되어 있음. 삽입, 삭제, 수정, 탐색 O(logN)
    string a[] = {"jy", "zeus", "kiin"};
    map<string, int> mp;
    for (int i = 0; i < 3; i++)
    {
        mp.insert({a[i], i + 1});
        mp[a[i]] = i + 1;
    }

    cout << mp["jy"] << '\n';
    mp.erase("jy");

    auto it = mp.find("jy");
    if(it == mp.end()){
        cout << "can't find jy.\n";
    }
    mp["jy"] = 100;

    it = mp.find("jy");
    if(it != mp.end()){
        cout << (*it).first << " : " << (*it).second << '\n';
    }
    for(auto it : mp){
        cout << (it).first << " : " << it.second << '\n';
    }
    for(auto it = mp.begin(); it != mp.end(); it++){
        cout << (*it).first << " : " << (*it).second << '\n';
    }
    mp.clear();

    // 주의사항: 참조만 해도 해당 요소가 생성됨.
    cout << '\n';
    cout << mp["test"] << '\n';
    for(auto it : mp) cout << it.first << " " << it.second << '\n';

    // 따라서 값이 있는지 찾는 방법은 아래처럼도 가능함.
    // 다만 0이라는 값이 할당되지 않은 것이 확실할 때에만 사용 가능.
    // 정석은 find를 사용하는 것임.
    cout << '\n';
    if(mp["faker"] == 0){
        mp["faker"] = 10000;
    }
    for(auto it : mp) cout << it.first << " " << it.second << '\n';

    /*
        unordered map은 hash table을 기반으로 설계되어 있음.
        탐색, 삽입, 삭제에 평균 O(1), 최악 O(n)
        최악의 경우 O(n)이라서 시간초과가 날 수 있음. map 사용을 권장.
    */
    cout << '\n';
    unordered_map<string, int> umap;
    umap["bcd"] = 1;
    umap["aaa"] = 1;
    umap["aba"] = 1;
    for(auto it : umap) cout << it.first << " : " << it.second << '\n';
    
}