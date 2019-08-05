#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define se second
#define si size()
#define popb pop_back()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define beg begin()
#define en end()
#define forl(i,a,n) for(int i=a;i<n;i++)

ll mod=1e9+7;
ll power(ll num,ll r){
    if(r==0) return 1;
    if(r==1) return num%mod;
    ll ans=power(num,r/2)%mod;
    if(r%2==0) {
        return (ans*ans)%mod;
    } return (((ans*ans)%mod)*num)%mod;
}
ll modinv(ll num){
    return power(num,mod-2);
}

string add_one(string a){
	reverse(a.beg,a.en);
	int n=a.si;
	int carry=0;
	int sum=(a[0]-'0')+1;
	carry=sum/10;
	a[0]=(sum%10+'0');
	forl(i,1,n){
		if(carry==0) {reverse(a.beg,a.en); return a;}
		else{
			sum=(a[i]-'0')+carry;
			a[i]=(sum%10+'0');
			carry=sum/10;
		}
	}
	if(carry) a+=(carry+'0');
	reverse(a.beg,a.en);
	return a;
}
bool small(string a,string b){
	int n1=a.si,n2=b.si;
	if(n1<n2) return true;
	if(n1>n2) return false;
	forl(i,0,n1){
		if(a[i]<b[i]) return true;
		else if(a[i]>b[i]) return false;
	}
	return false;
}
bool esmall(string a,string b){
	int n1=a.si,n2=b.si;
	if(n1<n2) return true;
	if(n1>n2) return false;
	forl(i,0,n1){
		if(a[i]<b[i]) return true;
		else if(a[i]>b[i]) return false;
	}
	return true;	
}
string subtraction(string a,string b){
	string ans="";
	if(small(a,b)) {swap(a,b);}
	int n1=a.si,n2=b.si;
	reverse(a.beg,a.en);
	reverse(b.beg,b.en);
	int carry=0;
	forl(i,0,n2){
		int sub=(a[i]-'0')-(b[i]-'0')-carry;
		if (sub < 0){  
			sub+=10; 
            carry = 1; 
        } 
        else carry = 0; 
        ans.pb(sub + '0'); 
	}
	forl(i,n2,n1){
		int sub = ((a[i]-'0') - carry);
        if (sub < 0){ 
        	sub = sub + 10; 
            carry = 1; 
        } 
        else carry = 0;
        ans.pb(sub + '0'); 
    } 
    reverse(ans.beg,ans.en); 
    return ans; 
}
string division(string a , string b){
	string ans="";
	string zero="0";
	if(small(a,b)) return zero;
	string r=a.substr(0,b.si);
	if(small(r,b)) r+=a[b.si];
	int sz=r.si;
	while(esmall(b,r)){
		int i=0;
		while(esmall(b,r)){
			r=subtraction(b,r);
			int count=0;
			forl(j,0,r.si){
				if(r[j]!='0') break;
				else count++;
			}
			if(count<r.si) r=r.substr(count,r.si-count);
			else r="";
			i++;
		}
		ans+=(i+'0');
		if(sz>=a.si) break;
		r+=a[sz];
		sz++;
		int count=0;
    	forl(j,0,r.si){
			if(r[j]!='0') break;
			else count++;
		}
		if(count<r.si) r=r.substr(count,r.si-count);
		else r="";
		while(small(r,b)&&sz<a.si){
			r+=a[sz];
			sz++;
			ans+='0';
			int count=0;
			forl(j,0,r.si){
				if(r[j]!='0') break;
				else count++;
			}
			if(count<r.si) r=r.substr(count,r.si-count);
			else r="";
		}
	}
	if(r.si==0) r="0";
	return r;
}
bool is_prime(string a){
	int n=a.si;
	string b="2";
	while(b.si<=(n/2+1)&&small(b,a)){
		//add_one(b);
		string r=division(a,b);
		if(r=="0") return false;
		b=add_one(b);
	}
	return true;
}
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--){
		string a;
		cin>>a;
		if(is_prime(a)) cout<<"Prime"<<endl;
		else cout<<"Not a Prime"<<endl;
	}
	return 0;
}