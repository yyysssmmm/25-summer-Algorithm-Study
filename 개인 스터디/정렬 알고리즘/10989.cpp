// O(N^2), O(NlogN) 알고리즘으로도 해결불가능한 문제 (N= ~10,000,000)
// O(N) 알고리즘을 선택하여 사용 - 계수정렬 (Counting Sort), 기수정렬 (Radix Sort), 버킷정렬 (Bucket Sort)


#include <iostream>
#include <vector>

using namespace std;

// 계수정렬 (사용가능 조건: 정렬대상 값들을 배열 인덱스에 넣을 수 있어야하므로 모두 0이상 정수여야함)

// Stable Counting Sort (메모리 비효율적, 문제통과 x)
// int main(){
//     cin.tie(NULL);
//     ios::sync_with_stdio(false);

//     int n;
//     int a;
//     int cumsum;
//     vector<int> A,B,C;

//     cin >> n;

//     B.resize(10001);
//     C.resize(n);

//     for (int i=0;i<n;i++){
//         cin >> a;
//         A.push_back(a);
//         B[a]++;
//     }

//     for (int i=1;i<B.size();i++){
//         B[i] += B[i-1];
//     }

//     for (int i=A.size()-1;i>=0;i--){
//         C[B[A[i]]-1] = A[i];
//         B[A[i]]-=1;
//     }

//     for (int i=0;i<n;i++)
//         cout << C[i] << "\n";
// }

// Unstable Counting Sort (배열 3개가 아니라 1개만 사용하므로 메모리 효율적, 문제통과 o)
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
