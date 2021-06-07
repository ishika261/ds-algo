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

#define err3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<#c<<" "<<c<<endl;

#define fr(i, a, b) for(i=a; i<b; i++)
#define rf(i, a, b) for(i=a; i>=b; i--)
const int N = 1e3 + 1;
ll n , m;
vecv dp(N, v (N,-1) );
vecv a(N, v (N,-1) );

ll fill (ll i,ll j)
{
    //err2(i,j);
    if(i==n || j==m) return 1e9;
    else if( i==n-1 && j== m-1) return dp[i][j] = a[n-1][m-1];

    else if(dp[i][j] != -1) return dp[i][j];

    else 
        //return dp[i][j] = min(dp[i+1][j], dp[i][j+1])+ a[i][j];
        return dp[i][j] = min(fill( i+1, j) , fill(i,j+1) )+ a[i][j];
}

ll power(ll n)
{
    ll p =0;
    while(n%2==0)
    {
        n=n/2;
        p++;
    }
    return p;
}
void solve()
{
    ll i, j;
    cin>>n>>m;
    vecv b (n,v(m));

    ll x ;
    fr(i,0,n)
    {
        fr(j,0,m) 
        {
            cin>>x;
            b[i][j]= x;
            a[i][j]= power(x);
        }
    }

    fr(i,0,n)
    {
        fr(j,0,m) cout<<a[i][j]<<" ";

        cout<<endl;
    }

    fill(0,0);

    err();

    fr(i,0,n)
    {
        fr(j,0,m) cout<<dp[i][j]<<" ";

        cout<<endl;
    }

    err();

    fr(i,0,n)
    {
        fr(j,0,m) cout<<b[i][j]<<" ";

        cout<<endl;
    }

    i=0; j=0;
    ll ans=b[0][0];

    while(i<=n-1 && j<=m-1)
    {
        //err2(i,j);
        if( dp[i+1][j]<dp[i][j+1] && j<m-1 && i<n-1) 
        {
            ans*= b[i+1][j];
            cout<<"D";
            i++;
        }
        else if (dp[i+1][j]>=dp[i][j+1] && i<n-1 && j<m-1)
        {
            ans*= b[i][j+1];
            cout<<"R"; 
            j++;
        }

        else if (i==n-1 && j!= m-1)
        {
            ans*= b[i][j+1];
            cout<<"R"; 
            j++;
        }

        else if (j==m-1 && i!= n-1)
        {
            ans*= b[i+1][j];
            cout<<"D"; 
            i++;
        }

        else if(i==n-1 && j==m-1) break;

        //cout<<ans<<endl;
    }
    

    cout<<endl;
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout); 
    #endif
    ll t=1; cin>>t;
    while(t--) solve();
    return 0;
}