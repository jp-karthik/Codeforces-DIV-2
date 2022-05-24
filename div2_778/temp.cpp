#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define PB push_back;
#define REP(i, a, b) for(int i=a; i<=b; i++)
void solve() {
    vector<int> nums = {1, 2, 3, 4};
    vector<int>::iterator idx = max_element(nums.begin(), nums.end());
    nums.erase(idx);
    REP(i, 0, nums.size()-1) cout<<nums[i]<<endl;
}
int main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int t;
    cin>>t;
    while(t > 0) {
        solve(); 
        t--;
    };
    return 0;
}