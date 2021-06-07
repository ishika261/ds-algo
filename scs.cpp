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
    string s1, s2,s3;
    cin>>s1>>s2;
    int m=s1.size();
    int n=s2.size();
    vecv dp( m+1, v(n+1,0) );

    fr(i,1,m+1)
    {
        fr(j,1,n+1)
        {
            if(s1[i-1]==s2[j-1])
            {
                s3.push_back(s1[i-1]); 
                dp[i][j]= 1+dp[i-1][j-1];
            }
            else dp[i][j]= min(dp[i][j-1], dp[i-1][j]);
        }
    }

    cout<<dp[m][n]<<endl;
    //cout<<s3;
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