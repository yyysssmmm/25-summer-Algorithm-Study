// # include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<tuple<string, int, int>> data;

    for (int i = 0; i < n; ++i) {
        string a;
        int b, c;
        cin >> a >> b >> c;
        data.push_back({a, b, c});
    }

    sort(data.begin(), data.end(), [](const auto& x, const auto& y){
        return get<1>(x) < get<1>(y);
    });

    for (const auto& t : data) {
        cout << (char) toupper(get<0>(t)[get<2>(t)-1]);
    }

    return 0;
}


// 다른사람의 정답 (doodle0)

// #include <algorithm>
// #include <cstdio>
// #include <vector>

// using namespace std;

// char upper(char c) {
//     if (c >= 'a' && c <= 'z') return c - 32;
//     return c;
// }

// int main() {
//     int n;
//     scanf("%d", &n);

//     vector<pair<int, char>> problems;
//     for (int i = 0; i < n; i++) {
//         char s[102];
//         int num, d;
//         scanf("%s%d%d", s, &num, &d);
//         problems.push_back({num, s[d - 1]});
//     }

//     sort(problems.begin(), problems.end());
    
//     for (auto [_, c] : problems) {
//         printf("%c", upper(c));
//     }
// }



// 다른사람의 답 (모범답안) (hjkim9911)

// #include <bits/stdc++.h>
// using namespace std;

// struct p {
// 	string s;
// 	int pn;
// 	int d;
// };

// bool cmp (p a, p b) {
// 	return a.pn < b.pn;
// }

// p arr[100];
// int N; string a; char c;

// int main() {
// 	cin >> N;
// 	for (int i = 0; i < N; i++) cin >> arr[i].s >> arr[i].pn >> arr[i].d;
// 	sort(arr, arr + N, cmp);
// 	for (int i = 0; i < N; i++) {
// 		c = arr[i].s[arr[i].d - 1];
// 		if (c >= 'a' && c <= 'z') c = 'A' + (c - 'a');
// 		cout << c;
// 	}
// }