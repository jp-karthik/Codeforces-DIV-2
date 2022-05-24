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
    int n;
    cin>>n;

    vll v(n);
    REP(i, 0, n-1) cin>>v[i];

    sort(v); //O(nlogn)

    int f = 1;
    int lf = 1;

    for (int i=1; i<n; i++) {  //O(n)
        if (v[i] == v[i-1]) {
            lf++;
        } else {
            if (lf > f) f = lf;
            lf = 1;
        }
    }
    if (lf > f) f = lf;
   
    int K = f;
    int N = n;
    int op = 0;

    while (K < N) { //O(logn)
        op++; 

        if (K <= N/2){
            op += K;
            K += K;
        } else{
            op += N-K; 
            K += N-K;   
        }

    }
    cout<<op<<endl;
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