#include <iostream>
#include <math.h>

using namespace std;

int s=0;
void Hanoi(int n, int start, int mid, int end){
    if (n==1){
        cout << start << " " << end << "\n";
        s+=1;
    }
    else{
        Hanoi(n-1, start, end, mid);
        Hanoi(1, start, mid, end);
        Hanoi(n-1, mid, start, end);
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;

    cin >> n;

    int sum = pow(2,n) - 1;

    cout << sum << "\n";
    Hanoi(n, 1, 2, 3);
}


// 다른사람의 정답 (점화식 풀어서 개수 안세고 배열에 저장해서 푸는 방식) (jj131210)

// #include <bits/stdc++.h>
// using namespace std;

// vector<pair<int,int>> p;

// void f(int a,int b,int c,int n){
//     if(n==1){
//         p.push_back({a,c});
//         return;
//     }
// 	f(a,c,b,n-1);
//     p.push_back({a,c});
//     f(b,a,c,n-1);
// }

// int main(){
// 	int n;
//     cin>>n;
//     f(1,2,3,n);
//     cout<<p.size()<<'\n';
//     for(auto c : p){
//         cout<<c.first<<' '<<c.second<<'\n';
//     }
// }