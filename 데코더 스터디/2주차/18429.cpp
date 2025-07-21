// 내가 직접 작성한 비효율적인 코드 (백트래킹 내용을 저장하고 다시 비교하므로 시간 낭비 있음)

// #include <iostream>
// #include <vector>

// using namespace std;


// vector<int> is_used;
// vector<int> stack;
// vector<vector<int>> candidates;

// void permutation(vector<int>& v){
//     if (stack.size()==v.size()){
//         candidates.push_back(stack);
//         return ;
//     }

//     for (int i=0;i<v.size();i++){
//         if (!is_used[i]){
//             stack.push_back(v[i]);
//             is_used[i] = 1;
//             permutation(v);
//             is_used[i] = 0;
//             stack.pop_back();
//         }
//     }
// }

// int main(){
//     cin.tie(NULL);
//     ios::sync_with_stdio(false);

//     int n, k;

//     cin >> n >> k;

//     vector<int> v(n);
//     is_used.resize(n);

//     for (int i=0;i<n;i++)
//         cin >> v[i];

//     permutation(v);

//     int cnt=0;
//     for (int i=0;i<candidates.size();i++){
//         int gain = 0;
//         int chk = 0;
//         for (int weight : candidates[i]){
//             gain += weight;
//             gain -= k;
//             if (gain<0){
//                 chk = 1;
//                 break;
//             }
//         }
//         if (chk==0)
//             cnt += 1;
//     }

//     cout << cnt;
// }


// chatGPT가 백트래킹 과정 자체에 조건 만족하는지 비교하도록 수정해준 계산 효율적인 코드 

#include <iostream>
#include <vector>

using namespace std;

vector<int> is_used;
vector<int> stack;
int cnt = 0;
int n, k;
vector<int> v;

void permutation(int depth, int gain) {
    if (gain < 0)
        return;  // 조건 위배 → 조기 종료

    if (depth == n) {
        cnt += 1;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!is_used[i]) {
            is_used[i] = 1;
            permutation(depth + 1, gain + v[i] - k);
            is_used[i] = 0;
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    v.resize(n);
    is_used.resize(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    permutation(0, 0);
    cout << cnt;
}
