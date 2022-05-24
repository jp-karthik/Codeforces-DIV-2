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

    int n = s.length();
    ll u = 1;

    vector<int> v(n);
    for (int i=0; i<n; i++) v[i] = (int)s[i];

    sort(v); //O(nlogn)

    for (int i=0; i<n-1; i++) {
        if (v[i] != v[i+1]) {
            u++;
        }
    }

    if (u == 2) {
        for (int i=0; i<s.length()-1; i++) {
            if (s[i] != s[i+1]) {
                continue;
            } else {
                cout<<"NO"<<endl;
                return;
            }
        }
        cout<<"YES"<<endl;
        return;
    }   

    unordered_map<char, bool> bucket;
    for (int i=0; i<u; i++) { //O(nlogn)
        if (bucket.find(s[i]) == bucket.end()) {
            bucket[s[i]] = true;
            continue;
        } else {
            cout<<"NO"<<endl;
            return;
        }
    }
    for (int i=u; i<n; i++) { //O(n)
        if (s[i] == s[i-u]) {
            continue;
        } else {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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
    while(t > 0) {
        solve(arg);
        t--;
        arg++;
    };
    return 0;
}