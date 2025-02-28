#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve() 
{
     int s;
     cin >> s;
     int sum = 0;
     int ans = 0;
     for (int i = 1; sum < s; i+=2) {
        sum += i;
        ans++;
     }
     cout << ans << endl;
}

signed main() 
{
    fastio();
    int t;
    cin >> t;
    while(t--) 
    {
        solve();
    }    
    return 0;
}