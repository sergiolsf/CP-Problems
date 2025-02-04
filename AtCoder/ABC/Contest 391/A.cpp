#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

signed main() {
    fastio();
    string s;
    cin >> s;
    if (s == "N") cout << "S" << endl;
    if (s == "S") cout << "N" << endl;
    if (s == "E") cout << "W" << endl;
    if (s == "W") cout << "E" << endl;
    if (s == "NE") cout << "SW" << endl;
    if (s == "SW") cout << "NE" << endl;
    if (s == "NW") cout << "SE" << endl;
    if (s == "SE") cout << "NW" << endl;

    
  
    return 0;
}