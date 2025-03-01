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

#define MAXN 1000010
int label[MAXN], cesta[MAXN], pombo[MAXN];

signed main() 
{
    fastio();
    int N, Q;
    cin >> N >> Q;
    for(int i=1; i <= N; i++)
    {
        label[i] = i;
        cesta[i] = i;
        pombo[i] = i;
    }

    while (Q--)
    {
        int p;
        cin >> p;
        if (p == 1)
        {
            int a, b;
            cin >> a >> b;
            pombo[a] = label[b];
        } 
        else if (p == 2)
        {
            int a, b;
            cin >> a >> b;
            int la = label[a], lb = label[b];
            label[a] = lb;
            label[b] = la;
            cesta[la] = b;
            cesta[lb] = a;
        } 
        else 
        {
            int a;
            cin >> a;
            cout << cesta[pombo[a]] << endl;
        }
    }

    return 0;
}
