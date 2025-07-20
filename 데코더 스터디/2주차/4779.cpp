#include <iostream>
#include <math.h>
#include <vector>
#include <string>

using namespace std;

void makeCantor(string& s, int start, int end);

string Cantor(int n){
    if (n==0)
        return "-";

    else{
        string s(pow(3,n), ' ');    // ' ' 대신 " "하면 에러뜨므로 조심 (''는 letter단위, ""는 sentence단위 인듯)

        int start = 0;
        int end = pow(3,n)-1;

        makeCantor(s, start, end);

        return s;
    }
}

void makeCantor(string& s, int start, int end){

    if (end-start+1 == 3){
        s[start] = '-';
        s[end] = '-';
    }

    else{
        makeCantor(s, start, start + (end-start+1)/3 - 1);
        makeCantor(s, start + 2*(end-start+1)/3, end);
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    while(cin >> n){
        cout << Cantor(n) << "\n";
    }
}

// 다른사람의 답 (erncard)

// #include <iostream>
// #include <math.h>

// using namespace std;

// void cantor(int n){
//     if(n==1){
//         cout<<'-';
//     }
//     else{
//         cantor(n/3); //왼쪽
//         for(int i=0;i<n/3;i++){
//             cout<<' ';
//         }
//         cantor(n/3);
//     }
// }

// int main(){
//     int n;
//     while(1){
//         cin >>n;
//         if(cin.eof()) break; //파일끝
//         else {
//             cantor(pow(3,n));
//             cout<<'\n';
//         }
//     }
// }