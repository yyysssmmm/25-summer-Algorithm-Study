// O(N^2) 알고리즘으로도 해결불가능한 문제 (N= ~1,000,000)
// O(NlogN) 알고리즘을 선택하여 사용 - 병합정렬 (Merge Sort), 퀵정렬 (Quick Sort), 힙 정렬, 내장함수 (퀵 정렬 기반?)

#include <iostream>
#include <vector>

using namespace std;

// 병합정렬 코드구현 

// vector<int> v_tmp;

// void partition(vector<int>& v, int start, int end);
// void merge(vector<int>& v, int start, int mid, int end);

// int main(){
//     cin.tie(NULL);
//     ios::sync_with_stdio(false);
//     int n;
//     int a;
//     int tmp;
//     vector<int> v;

//     cin >> n;

//     v_tmp.resize(n);

//     for (int i=0;i<n;i++){
//         cin >> a;
//         v.push_back(a);
//     }

//     partition(v, 0, n-1);

//     for (int i=0;i<n;i++)
//         cout << v[i] << "\n";
// }

// void merge(vector<int>& v, int start, int end){

//     int mid = (start + end) / 2;

//     int i = start;
//     int j = mid + 1;
//     int k = start;

//     while (i<=mid && j<=end){
//         if (v[i] <= v[j])
//             v_tmp[k++] = v[i++];
//         else
//             v_tmp[k++] = v[j++];    
//     }

//     int tmp = i>mid ? j : i;    // 삼항 연산자 (Ternary Operator) i.e.조건 연산자

//     while (k<=end)
//         v_tmp[k++] = v[tmp++];

//     for (i=start; i<=end; i++)
//         v[i] = v_tmp[i];
//     // 삼항 연산자 사용하지 않은 경우 코드: 

// }

// void partition(vector<int>& v, int start, int end){
    
//     int mid = (start + end) / 2;

//     if (start < end){
//         partition(v, start, mid);
//         partition(v, mid+1, end);
//         merge(v, start, end);
//     }
// }



// 퀵정렬 코드구현

void quickSort(vector<int>& v){
    
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    int a;
    vector<int> v;

    cin >> n;

    for (int i=0;i<n;i++){
        cin >> a;
        v.push_back(a);
    }

    quickSort(v);

    for (int i=0;i<n;i++)
        cout << v[i] << "\n";
}