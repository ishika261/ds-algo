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
const int N = 1e3 + 1;
ll i, j;
ll n , m;
vecv dp(N,v(N,-1));
vecv a(N,v(N));

ll fill(int i , int j)
{
    if(i==n||j==m) return 1e9;

    if(j==m-1) return dp[i][j]=a[i][j];
    if(dp[i][j]!=-1) return dp[i][j];

    if(i==0 ) return dp[i][j]= max(fill(i,j+1), fill(i+1,j+1))+a[i][j];
    if(i==n-1) return dp[i][j]= max(fill(i,j+1), fill(i-1,j+1))+a[i][j];
    else return dp[i][j]= max( {fill(i,j+1), fill(i+1,j+1), fill(i-1,j+1)} )+a[i][j];
}

void solve()
{
    cin>>n>>m;

    fr(i,0,n)
        fr(j,0,m) cin>>a[i][j];


    int ans=INT_MIN, val;

    fr(i,0,n)
    {
        val = fill(i,0);
        ans=max(ans,val);
    }
    
    // fr(i,0,n)
    // { 
    //     fr(j,0,m) cout<<dp[i][j]<<" ";

    //     cout<<endl;
    // }
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
    ll t=1; //cin>>t;
    while(t--) solve();
    return 0;
}