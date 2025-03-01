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

signed main() 
{
    fastio();

    int n;
    cin >> n;
    int ult;
    for (int i = 1; i <= n; i++) 
    {
        int a;
        cin >> a;
        if (i == 1) 
        {
            ult = a;
            continue;
        }
        if (ult >= a) 
        {
            cout << "No\n";
            return 0;
        }
        
        ult = a;
    }
    cout << "Yes\n";
  
    return 0;
}