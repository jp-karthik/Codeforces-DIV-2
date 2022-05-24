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
    ll n, k;
    cin>>n>>k;
    string s;
    vi v(n);
    cin>>s;

    if (k%2 == 0) {
        for (int i=0; i<n; i++) {
            if (k <= 0) {
                
                break;
            } 
            if (s[i] == '0') {
                v[i]++;
                k--;
                s[i] = '1';
            }
        }
        v[0] += 2*(k/2);
        if (k%2 == 1) {
            v[n-1]++;
            k--;
            s[n-1] = '0';
        }
        cout<<s<<endl;
        for (auto x: v) {
            cout<<x<<" ";
        }
        cout<<endl;
    } else {
        for (int i=0; i<n; i++) {
            if (k <= 0) {
                while (i<n) {
                    if (s[i] == '1') {
                        s[i] = '0';
                    } else {
                        s[i] = '1';
                    }
                    i++;
                }
                break;
            } 
            if (s[i] == '1') {
                v[i]++;
                k--;
            }
            if (s[i] == '0') {
                s[i] = '1';
            }
        }
        v[0] += 2*(k/2);
        if (k%2 == 1) {
            v[n-1]++;
            k--;
            s[n-1] = '0';
        }
        cout<<s<<endl;
        for (auto x: v) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t > 0) {
        int arg = 0;
        solve(arg);
        t--;
        arg++;
    };
    return 0;
}