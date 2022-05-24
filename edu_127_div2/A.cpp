#include <bits/stdc++.h>
using namespace std;
// -------------------
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<long, long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int,int>> vpi;
typedef vector<pair<long long, long long>> vpll;
// --------------------
#define PB push_back
#define REP(i, a, b) for(int i=a; i<=b; i++)
#define sort(v) sort(v.begin(), v.end())
//------------------
bool dec(int x, int y) {
    return x>y;
}
bool inc(int x, int y) {
    return x<y;
}
//-----------------
void solve(int arg) {
    string s;
    cin>>s;

    ll cA = 0;
    ll cB = 0;
    ll n = s.length();

    if (n == 1) {
        cout<<"NO"<<endl;
        return;
    }

    if (s.length() >= 2) {
        if (s[n-1] != s[n-2]) {
            cout<<"NO"<<endl;
            return;
        }
    }
    for (int i=0; i<s.length(); i++) {
        if (s[i] == 'a') {
            if (cB == 1) {
                cout<<"NO"<<endl;
                return;
            }
            cA++;
            cB = 0;
        }
        if (s[i] == 'b') {
            if (cA == 1) {
                cout<<"NO"<<endl;
                return;
            }
            cB++;
            cA = 0;
        }
    }
    cout<<"YES"<<endl;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    int arg = 1;
    cin>>t;
    while(t > 0) {
        solve(arg);
        t--;
        arg++;
    };
    return 0;
}