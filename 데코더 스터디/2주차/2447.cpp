#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> img;

void Star(int n, int a, int b){

    if (n==1)
        return ;

    for (int i=a;i<a+n;i+=n/3){
        for (int j=b;j<b+n;j+=n/3){
            if ((i==a+n/3) && (j==b+n/3)){
                for (int k=i;k<=i+n/3-1;k++)
                    for (int l=j;l<=j+n/3-1;l++)
                        img[k][l] = ' ';
            }
            else{
                Star(n/3, i, j);
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;

    cin >> n;

    img.resize(n+1, vector<char>(n+1, '*'));

    Star(n, 1, 1);

    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cout << img[j][i];
        }
        cout << "\n";
    }
}