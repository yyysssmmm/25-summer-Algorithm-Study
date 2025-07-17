// 내가 처음 작성한 코드 (정렬한 후 일일이 비교해서 찾아주는 비효율적 코드 -> 시간초과)

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main(){
//     cin.tie(NULL);
//     ios::sync_with_stdio(false);

//     int n, a;
//     cin >> n;

//     vector<int> v;
//     vector<int> v_original;

//     for (int i=0;i<n;i++){
//         cin >> a;
//         v.push_back(a);
//         v_original.push_back(a);
//     }

//     sort(v.begin(), v.end());

//     vector<pair<int, int>> encoded;

//     int tmp=0, chk=0;
//     for (int i=0;i<n-1;i++){
//         if (v[i+1]==v[i]){
//             chk=1;
//         }
//         else{
//             chk=0;
//         }

//         if (chk==0){
//             encoded.push_back({tmp++, v[i]});
//         }   
//         else{
//             encoded.push_back({tmp, v[i]});
//         }       
//     }
//     encoded.push_back({tmp, v[n-1]});

//     for (int i=0;i<n;i++){
//         for (int j=0;j<n;j++){
//             if (v_original[i]==encoded[j].second){
//                 cout << encoded[j].first << " ";
//                 break;
//             }   
//         }
//     }
// }


// 관련 내장 함수 찾아본 후 적용해서 바꾼 코드 (중복제거는 직접 구현함)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, a;
    cin >> n;

    vector<int> v;
    vector<int> v_original;

    for (int i=0;i<n;i++){
        cin >> a;
        v.push_back(a);
        v_original.push_back(a);
    }

    sort(v.begin(), v.end());

    vector<int> drop_duplicated;

    drop_duplicated.push_back(v[0]);
    for (int i=1;i<n;i++){
        if (v[i]!=v[i-1]){
            drop_duplicated.push_back(v[i]);
        }       
    }

    for (int i=0;i<n;i++){
        auto it = lower_bound(drop_duplicated.begin(), drop_duplicated.end(), v_original[i]);
        cout << it - drop_duplicated.begin() << " ";
    }
}