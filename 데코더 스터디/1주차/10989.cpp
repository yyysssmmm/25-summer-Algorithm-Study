// 메모리 초과 문제 발생, 즉 공간복잡도 고려 필요 => 따라서 counting sort 알고리즘으로 해결해야함 

#include <iostream>
#include <vector>

using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    int a;
    int cumsum;
    vector<int> B;

    cin >> n;

    B.resize(10001);

    for (int i=0;i<n;i++){
        cin >> a;
        B[a]++;
    }

    for (int i=0;i<B.size();i++){
        for (int j=0;j<B[i];j++)
            cout << i << "\n";
    }
}
