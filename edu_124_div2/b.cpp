#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define PB push_back;
#define REP(i, a, b) for(int i=a; i<=b; i++)
unsigned long long power(unsigned long long x, unsigned long long y)
{
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return power(x, y / 2) * power(x, y / 2);
    else
        return x * power(x, y / 2) * power(x, y / 2);
}
void solve() {
    int n;
    cin>>n;
    unsigned long long result = power(3, n-1);
    unsigned long long check = power(10, 9);
    if (result >= check) {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    unsigned long long val = 1;
    for (int i=0; i<n; i++) {
        cout<<val<<" ";
        val = val*3;
    }
    cout<<endl;
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