// O(N^2) 알고리즘으로도 해결 가능한 문제 (N= ~1000) - 버블정렬, 삽입정렬, 선택정렬 

#include <iostream>
#include <vector>

using namespace std;

// 버블정렬 코드구현 
// int main(){
//     cin.tie(NULL);
//     ios::sync_with_stdio(false);
//     int n;
//     int a;
//     int tmp;
//     vector<int> L;
    
//     cin >> n;

//     for (int i=0;i<n;i++){
//         cin >> a;
//         L.push_back(a);
//     }

//     for (int i=0;i<n;i++){
//         for (int j=0;j<n-i-1;j++){
//             if (L[j]>L[j+1]){
//                 tmp = L[j+1];
//                 L[j+1] = L[j];
//                 L[j] = tmp;
//             }
//         }
//     }

//     for (int i=0;i<n;i++)
//         cout << L[i] << "\n";
// }


// 삽입정렬 코드구현 

// int main(){
//     cin.tie(NULL);
//     ios::sync_with_stdio(false);

//     int n;
//     int a;
//     int tmp;
//     vector<int> v;

//     cin >> n;

//     for (int i=0;i<n;i++){
//         cin >> a;
//         v.push_back(a);
//     }

//     for (int i=1;i<n;i++){
//         for (int j=i;j>0;j--){
//             if (v[j-1]>v[j]){
//                 tmp = v[j];
//                 v[j] = v[j-1];
//                 v[j-1] = tmp;
//             }

//             else
//                 break;
//         }
//     }

//     for (int i=0;i<n;i++){
//         cout << v[i] << "\n";
//     }

// }


// 선택정렬 코드구현

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    int a;
    int tmp;
    int min_idx;
    vector<int> v;

    cin >> n;

    for (int i=0;i<n;i++){
        cin >> a;
        v.push_back(a);
    }

    for (int i=0;i<n-1;i++){
        min_idx = i;
        for (int j=i;j<n;j++){
            if (v[j]<v[min_idx])
                min_idx=j;
        }
        tmp = v[i];
        v[i] = v[min_idx];
        v[min_idx] = tmp;
    }

    for (int i=0;i<n;i++)
        cout << v[i] << "\n";
}