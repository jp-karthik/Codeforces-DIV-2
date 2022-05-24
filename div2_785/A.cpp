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

bool dec(int x, int y) {
    return x>y;
}
bool inc(int x, int y) {
    return x<y;
}

void solve(int arg) {
    string s;
    cin>>s;
    ll sum = 0;
    for (int i=0; i<s.length(); i++) {
        sum += s[i]-96;
    }
    int n = s.length();
    if (n == 1) {
        cout<<"Bob"<<" "<<(s[0]-96)<<endl;
        return;
    }
    if (n%2 == 0) {
        cout<<"Alice"<<" "<<sum<<endl;
        return;
    } else {
        cout<<"Alice"<<" "<<(sum-2*(min(s[0],s[n-1])-96))<<endl;
        return;
    }
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