#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define PB push_back;
#define REP(i, a, b) for(int i=a; i<=b; i++)
long long power(int base, int exp) {
    int result = 1;
    for (int i=0; i<exp; i++) {
        result *= base;
    }
    return result;
}
void solve() {
    long long n;
    cin>>n;
    cout<<power(2, n)-1<<endl;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t > 0) {
        solve(); 
        t--;
    };
    return 0;
}