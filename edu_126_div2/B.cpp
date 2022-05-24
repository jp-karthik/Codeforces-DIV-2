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
void solve() {
    int n;
    cin>>n;

    vll nums(n);
    for (int i=0; i<n; i++) cin>>nums[i];

    for (int i=0; i<n; i++) {

        int min = INT_MAX;
        int count2 = 0;
        int t = nums[i];
        if (t == 0) {
            cout<<0<<" ";
            continue;
        }
        if (t%32768 == 0) {
            cout<<1<<" ";
            continue;
        }
        while (t%2 == 0 && t != 0) {
            t = t/2;
            count2++;
        }
        min = 15-count2;
        for (int j=1; j<=15; j++) {
            int curr = (nums[i]+1)%32768;
            int t = curr;
            int count  = 0;
            if (t == 0) {
                if (min > j) {
                    min = j;
                }
                nums[i] = curr;
                continue;
            }
            while (t%2 == 0 && t != 0) {
                t = t/2;
                count++;
            }
            int r = 15-count+j;
            if (min > r) {
                min = r;
            }
            nums[i] = curr;
        }
        cout<<min<<" ";
    }
    cout<<endl;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        solve();
    return 0;
}