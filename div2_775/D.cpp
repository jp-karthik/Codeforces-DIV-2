#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define PB push_back;
#define REP(i, a, b) for(int i=a; i<=b; i++)
void solve() {
    int n, c;
    cin>>n>>c;
    vector<int> nums(n);
    for (int i=0; i<n; i++) {
        cin>>nums[i];
    }
    bool result = 1;
    sort(nums.begin(), nums.end());
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            if ( !count(nums.begin(), nums.end(), nums[j]/nums[i]) ){
                result = 0;
                break;
            } 
        }
    }
    if (result == 0) {
        cout<<"No"<<endl;
    } else {
        cout<<"Yes"<<endl;
    }
}
int main() {
    int t;
    cin>>t;
    while(t > 0) {
        solve(); 
        t--;
    };
    return 0;
}