#include<iostream>
#include<vector>
#include<string>

using namespace std;

int white=0;
int blue=0;


string chk(vector<vector<int>>& origami, int x_a, int x_b, int y_a, int y_b){
    int sum=0;

    for (int i=x_a;i<=x_b;i++){
        for (int j=y_a;j<=y_b;j++){
            if (origami[i][j] == 1)
                sum += 1;
        }
    }

    if (sum==(x_b-x_a+1)*(y_b-y_a+1))
        return "blue";

    else if (sum==0)
        return "white";

    else
        return "fail";
}

void cut(vector<vector<int>>& origami, int x_a, int x_b, int y_a, int y_b){

    string cls = chk(origami, x_a, x_b, y_a, y_b);
    
    if (cls=="fail"){
        cut(origami, x_a, x_a + (x_b - x_a) / 2, y_a, y_a + (y_b - y_a) / 2);
        cut(origami, x_a, x_a + (x_b - x_a) / 2, y_a + (y_b - y_a) / 2 + 1, y_b);
        cut(origami, x_a + (x_b - x_a) / 2 + 1, x_b, y_a, y_a + (y_b - y_a) / 2);
        cut(origami, x_a + (x_b - x_a) / 2 + 1, x_b, y_a + (y_b - y_a) / 2 + 1, y_b);
    }

    else if (cls=="white")
        white += 1;

    else if (cls=="blue")
        blue += 1;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    int a;

    cin >> n;

    vector<vector<int>> origami(n,vector<int>(n));

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >> a;
            origami[i][j] = a;
        }
    }

    cut(origami, 0, n-1, 0, n-1);

    cout << white << "\n" << blue;
}