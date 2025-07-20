#include <iostream>
#include <vector>
#include <string>

using namespace std;

string chk(vector<vector<int>>& img, int x_a, int x_b, int y_a, int y_b){
    int sum=0;

    for (int i=x_a;i<=x_b;i++){
        for (int j=y_a;j<=y_b;j++){
            if (img[j][i] == 1)
                sum+=1;
        }
    }

    if (sum==(x_b-x_a+1)*(y_b-y_a+1))
        return "1";
    else if (sum==0) 
        return "0";
    else
        return "-1";
}

string compress(vector<vector<int>>& img, int x_a, int x_b, int y_a, int y_b){
    string s;

    string cls = chk(img, x_a, x_b, y_a, y_b);

    if (cls=="1" || cls=="0")
        s.append(cls);
    else{
        s.push_back('(');
        s.append(compress(img, x_a, x_a + (x_b-x_a)/2, y_a, y_a + (y_b-y_a)/2));
        s.append(compress(img, x_a + (x_b-x_a)/2 + 1, x_b, y_a, y_a + (y_b-y_a)/2));
        s.append(compress(img, x_a, x_a + (x_b-x_a)/2, y_a + (y_b-y_a)/2 + 1, y_b));
        s.append(compress(img, x_a + (x_b-x_a)/2 + 1, x_b, y_a + (y_b-y_a)/2 + 1, y_b));
        s.push_back(')');
    }

    return s;
}


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    string s;

    cin >> n;

    vector<vector<int>> img(n, vector<int>(n));

    for (int i=0;i<n;i++){
        cin >> s;
        for (int j=0;j<n;j++){
            img[i][j] = s[j] - '0';
        }
    }

    cout << compress(img, 0, n-1, 0, n-1);
}