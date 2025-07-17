// 내풀이: 내장함수가 아닌 계수정렬 사용 

#include <iostream>
#include <vector>

using namespace std;

struct p{
    int age;
    string name;
};

struct tmp{
    int cnt=0;
    vector<string> name;
};

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;

    cin >> n;

    p member[100001];
    tmp b[201];

    for (int i=0;i<n;i++){
        cin >> member[i].age >> member[i].name;
        b[member[i].age].cnt ++;
        b[member[i].age].name.push_back(member[i].name);
    }
    
    for (int i=0;i<201;i++){
        for (int j=0;j<b[i].cnt;j++){
            cout << i << ' ' << b[i].name[j] << "\n";
        }
    }
}


// 다른사람 풀이 (shushu0730): 내장함수 사용

// using namespace std;
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <utility> 

// struct Info
// {
//     int age;
//     string name;
// };

// int main()
// {
//     long long N;
//     cin >> N;

//     vector<pair<Info, long long>> v;

//     for (int i = 0; i < N; i++)
//     {
//         Info info;
//         cin >> info.age >> info.name;

//         v.push_back({ info, i + 1 });
//     }

//     sort(v.begin(), v.end(), [](const pair<Info, long long>& a, const pair<Info, long long>& b)
//         {
//             if (a.first.age != b.first.age) 
//                 return a.first.age < b.first.age; 
//             return a.second < b.second;
//         });

//     for (auto& it : v)
//     {
//         cout << it.first.age << " " << it.first.name << '\n';
//     }
//  }
