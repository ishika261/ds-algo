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
//vecv dp(N, v(N,-1));

// int lcs(string s1, string s2, int m, int n)
// {
//     if(m==0||n==0) return dp[m][n]=0;

//     if(dp[m][n]==-1)
//     {
//         if(s1[m-1]==s2[n-1]) 
//             return dp[m][n]=1+lcs(s1,s2,m-1,n-1);
//         else 
//             return dp[m][n]= max(lcs(s1,s2,m-1,n), lcs(s1,s2,m,n-1));
//     }

//     else return dp[m][n];

// }
void solve()
{
    string s1, s2,s3;
    cin>>s1>>s2;

    int m=s1.size();
    int n=s2.size();

    //int ans = lcs(s1,s2,m,n);

    vecv dp( m+1, v(n+1,0) );

    fr(i,1,m+1)
    {
        fr(j,1,n+1)
        {
            if(s1[i-1]==s2[j-1]) 
            {
                dp[i][j]= 1+dp[i-1][j-1];
            }
            else 
                dp[i][j]= max(dp[i][j-1], dp[i-1][j]);
        }
    }

    i=m , j=n;


    while(i>0&&j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            s3.push_back(s1[i-1]);
            i--;
            j--;
        }

        else if(dp[i-1][j]>dp[i][j-1])i--;
        else j--;
        
    }
    cout<<dp[m][n]<<endl;
    reverse(all(s3));

    cout<<s3<<" hello "<<endl;


    // supersequence
    string s4;
    i=0;
    j=0;
    ll k=0;
    while(i<m || j<n || k<s3.size())
    {
        if(s3[k] == s1[i] && s3[k]==s2[j])
        {
            s4.push_back(s3[k]);
            k++;
            i++;
            j++;
        }

        else if(s3[k] != s1[i])
        {
            s4.push_back(s1[i]);
            i++;
        }

        else if(s3[k]!=s2[j])
        {
            s4.push_back(s2[j]);
            j++;
        }
    }
    //cout<<s4<<endl;

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