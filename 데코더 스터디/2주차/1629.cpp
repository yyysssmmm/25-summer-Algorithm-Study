// 단순히 무식하게 떠올려서 푼 나의 최초 코드 (시간초과 에러)

// #include <iostream>
// #include <math.h>
// #include <vector>

// using namespace std;

// int main(){
//     cin.tie(NULL);
//     ios::sync_with_stdio(false);

//     int a,b,c;

//     cin >> a >> b >> c;

//     vector<int> remainder;

//     int start=-1;
//     int r;

//     for (int i=1;i<=b;i++){
//         int power = pow(a, i);
//         r = power % c;

//         if (power >= c){
//             start = i;
//             break;
//         }
//     }

//     if (start == -1)
//         cout << r;
//     else{
//         int stop=-1;
//         for (int i=start;i<=b;i++){
//             int power = pow(a, i);
//             int r = power % c;
//             for (int j=0;j<remainder.size();j++){
//                 if (remainder[j]==r){
//                     stop = i;
//                     break;
//                 }
//             }
//             if (stop==-1)
//                 remainder.push_back(r);
//             else   
//                 break;
//         }

//         int T = stop - start;
//         cout << remainder[(b-start)%T];
//     }
// }



// 재귀적 분할정복 이용한 코드 (gpt로부터 아이디어 힌트 얻음)

#include <iostream>

using namespace std;

int ans(long long a, long long b, long long c){
    if (b==0)
        return 1;

    long long half = ans(a, b/2, c);
    long long result = (half * half) % c;

    if (b%2==1)
        result = (a * result) % c;

    return result;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    long long a,b,c;

    cin >> a >> b >> c;

    cout << ans(a,b,c) % c;
    
}

// 추가 아이디어: b가 소수라는 조건 추가되면 페르마 소정리 이용해서 시간 더 단축할 수 있을듯? 아니면 b에서 가장 가까운 소수 찾는 알고리즘 이용해서 시간단축 시도? 


// 다른사람의 정답 (anhwajack)
// #include <bits/stdc++.h>
// #define FASTIO  ios::sync_with_stdio(false);    cin.tie(nullptr);   cout.tie(nullptr);
// using namespace std;
// typedef long long ll;
// typedef pair<int,int> pii;
// ll A,B,C;

// ll proc(ll base, ll exponent){
//     ll result = 1;
//     while (exponent > 0){
//         if (exponent % 2 != 0){
//             result*=base;
//             exponent--;
//         }else{
//             base*=base;
//             exponent/=2;
//         }
//         result %= C;
//         base %= C;
//     }
//     return result %= C;
// }

// int main(){
//     FASTIO
//     cin >> A >> B >> C;
//     cout << proc(A,B) << "\n";
//     return 0;
// }


// 다른사람의 정답 (mwon)
// #include <stdio.h>
// #include <math.h>
// using namespace std;
// long long a,b,c,arr[100]={},s=1;
// long long f(long long n,long long k)
// {
// 	if(k==1)
// 	{
// 		return n%c;
// 	}
// 	if(k%2==1)
// 	{
// 		long long a= f(n,k/2);
// 		return a%c*a%c*n%c;
// 	}
// 	else
// 	{
// 		long long a= f(n,k/2);
// 		return a%c*a%c;
// 	}
// }
// int main()
// {
// 	scanf("%lld %lld %lld",&a,&b,&c);
// 	printf("%lld",f(a,b)%c);
// }