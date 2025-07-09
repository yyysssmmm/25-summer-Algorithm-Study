// 서버시간 고려해야하는듯? (현재한국시간 <> 저지사이트 기준 시간?)
#include <iostream>
#include <ctime>

using namespace std;

int main(){
    struct tm *t;
    time_t now = time(0);
    t = localtime(&now);
    
    cout << t->tm_year + 1900 << "-";
    cout.width(2);
    cout.fill('0');
    cout << t->tm_mon + 1 << "-";
    cout.width(2);
    cout.fill('0');
    cout << t->tm_mday + 1;

    return 0;
}