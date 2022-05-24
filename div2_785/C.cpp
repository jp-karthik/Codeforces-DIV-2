#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<long, long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int,int>> vpi;
typedef vector<pair<long long, long long>> vpll;

#define PB push_back
#define REP(i, a, b) for(int i=a; i<=b; i++)
#define sort(v) sort(v.begin(), v.end())
#define mod 1000000007
bool dec(int x, int y) {
    return x>y;
}
bool inc(int x, int y) {
    return x<y;
}

int n = 40005;
vi v;
vector<vector<int>> dp; 

void solve(int arg) {
    REP(i, 1, n) {
        string s = to_string(i);
        string r = s;
        reverse(r.begin(), r.end());
        if (r == s) {
            v.PB(i);
        }
    }
    dp = vector<vector<int>>(v.size()+1, vector<int>(n+1));
    for (int i=0; i<=v.size(); i++) { 
        dp[i][0] = 1;
    }
    for (int i=1; i<=n; i++) { 
        dp[0][i] = 0;
    }
    for (int i=1; i<=v.size(); i++) { 
        for (int j=1; j<=n; j++) { 
            if (v[i-1] <= j) {
                dp[i][j] = (dp[i-1][j] + dp[i][j-v[i-1]])%mod;
                continue;
            } else {
                dp[i][j] = (dp[i-1][j])%mod;
            }
        }
    }
    return;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    int arg = 1;
    cin>>t;
    solve(arg);
    while(t > 0) {
        int x;
        cin>>x;
        cout<<dp[v.size()][x]<<endl;

        t--;
        arg++;
    };
    return 0;
}