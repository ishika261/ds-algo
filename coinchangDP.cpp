#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define ft first
#define sd second
 
#define v vector<ll>
#define vecv vector<v>
#define all(a) a.begin(),a.end()
#define mx(a) *max_element(all(a))
#define mn(a) *min_element(all(a))
 
#define err() cout<<"=================="<<endl;
#define err1(a) cout<<#a<<" "<<a<<endl;
#define err2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl;

#define err3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl;

#define fr(i, a, b) for(i=a; i<b; i++)
#define rf(i, a, b) for(i=a; i>=b; i--)
const int N = 1e6 + 1;
ll i, j;

void solve()
{
    ll n,w; cin>>n>>w;
    v c (n);

    fr(i,0,n)cin>>c[i];

    vecv dp(n+1 , v(w+1,-1));


    fr(i,0,n+1)
    {
        fr(j,0,w+1)
        {
            if(i==0) dp[i][j]=INT_MAX;
            if(j==0) dp[i][j]=0;

            if(dp[i][j]==-1)
            {
                if(c[i-1]>j) dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=min(dp[i-1][j],1+ dp[i][j-c[i-1]] );
            }

        }
    }


    fr(i,0,n+1)
    {
        fr(j,0,w+1) cout<<dp[i][j]<<" ";

        cout<<endl;
    }                                                 
    if(dp[n][w]==INT_MAX) cout<<"-1\n";
    else 
    cout<<dp[n][w]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout); 
    #endif
    ll t=1; //cin>>t;
    while(t--) solve();
    return 0;
}