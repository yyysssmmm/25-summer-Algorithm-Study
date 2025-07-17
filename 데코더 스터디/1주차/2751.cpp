// <algorithm> 헤더의 내장 함수 이용한 방법 

#include <iostream>
#include <algorithm>
#include <vector> 

using namespace std;

int main(){

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    int a;

    vector<int> L;

    cin >> n;

    for (int i=1;i<=n;i++){
        cin >> a;
        L.push_back(a);
    }

    sort(L.begin(), L.end());
    for (int i=0; i<n; i++)
        cout << L[i] << "\n";   // endl로 줄바꿈하면 버퍼 flush하는데 시간 오래걸려서 시간초과 뜸 
 
    return 0;
}