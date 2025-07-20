// 뭔가 DFS랑 비슷한 느낌인듯? 그래서 스택 구조나 트리구조 사용하면 되려나? 

#include <iostream>
#include <vector>

using namespace std;

vector<int> is_used;
vector<int> stack;

void backtrack(int n, int m, int depth){
    if (depth==m){
        for (int i=0;i<stack.size();i++){
            cout << stack[i] << " ";
        }
        cout << "\n";

        stack.pop_back();
        return ;
    }
    for (int i=1;i<=n;i++){
        if (!is_used[i]){
            stack.push_back(i);
            is_used[i] = 1; 
            backtrack(n, m, stack.size());
            is_used[i] = 0;
        }
    }
    if (stack.size()!=0)
        stack.pop_back();
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;

    cin >> n >> m;

    is_used.resize(n+1);

    backtrack(n, m, stack.size());
}