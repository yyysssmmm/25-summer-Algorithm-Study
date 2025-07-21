// sol1) 단순 재귀 

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;


vector<vector<ll>> matmul(const vector<vector<ll>>& a, const vector<vector<ll>>& b){
    vector<vector<ll>> ans(a.size(), vector<ll>(a.size()));

    int n = a.size();

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            ll s = 0;
            for (int k=0;k<n;k++){
                s += (a[i][k] % 1000) * (b[k][j] % 1000);
                s = s % 1000;
            }
            ans[i][j] = s;
        }
    }

    return ans;
}


vector<vector<ll>> matpow(vector<vector<ll>>& v, ll b){
    if (b==1){
        return v;
    }

    vector<vector<ll>> half = matpow(v, b/2);

    if (b%2==1)
        return matmul(matmul(half, half), v);
    else
        return matmul(half, half);
}


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    ll b;

    cin >> n >> b;

    vector<vector<ll>> v(n, vector<ll>(n));
    vector<vector<ll>> ans;

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >> v[i][j];
            v[i][j] = v[i][j] % 1000;
        }
    }

    ans = matpow(v, b);

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
} 


// sol2) 고유값 분해 성질 활용 (chatGPT 제공)
// (표준라이브러리가 아니므로 백준에서는 컴파일 에러 발생 & 부동소수점 오차 위험으로 좋은 풀이는 아닌듯. 참고만 하면 좋을듯?)

// #include <iostream>
// #include <Eigen/Dense>
// #include <cmath>

// using namespace std;
// using namespace Eigen;

// int main() {
//     int n;
//     long long b;

//     cin >> n >> b;

//     MatrixXd A(n, n);
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             double val;
//             cin >> val;
//             A(i, j) = val;
//         }
//     }

//     // 고유값 분해
//     Eigen::EigenSolver<MatrixXd> es(A);
//     MatrixXd P = es.eigenvectors().real();         // 고유벡터 (실수부)
//     MatrixXd D = es.eigenvalues().real().asDiagonal(); // 대각행렬 (실수부)

//     // D^b 계산 (고유값 거듭제곱)
//     for (int i = 0; i < n; i++) {
//         D(i, i) = pow(D(i, i), b);
//     }

//     // A^b = P * D^b * P^-1
//     MatrixXd A_pow = P * D * P.inverse();

//     // 출력 (mod 1000)
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             long long val = static_cast<long long>(round(A_pow(i, j))) % 1000;
//             if (val < 0) val += 1000;
//             cout << val << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }



