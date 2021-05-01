#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

vector <ll> Sieve(ll n) 
{ 
    vector<ll> ans;
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime));
  
    for (ll p=2; p*p<=n; p++) 
    if (prime[p] == true) 
    for (ll i=p*p; i<=n; i += p)
    prime[i] = false; 
        
  	for (ll p=2; p<=n; p++) 
    if (prime[p]) 
    ans.push_back(p);
	return ans;
}

int main()
{
	IOS;
	ll t;
	cin>>t;
	vector<ll> pr=Sieve(5000000);
	ll r[5000001],s[5000001];
    memset(r,0,sizeof(r));
    memset(r,0,sizeof(r));
    for(ll i=0;i<pr.size();i++) r[pr[i]]=1;
	for(ll p=2;p<=5000000;p++)
    {
		if(r[p]==1) {s[p]=s[p-1]+r[p]; continue;}
		for(ll i=0;i<pr.size();i++)
    	{
    	    if(p%pr[i]==0)
    	    {
    	        ll x=p/pr[i];
    	        r[p]=r[x]+1;
    	        s[p]=s[p-1]+r[p];
    	        break;
    	    }
		}
	}
	while(t--)
	{
		ll a,b; cin>>a>>b;
		cout<<s[a]-s[b];
		cout<<"\n";
	}
	return 0;
}
