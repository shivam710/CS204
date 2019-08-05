#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define si size()
#define endl "\n"
#define beg begin()
#define en end()
#define forl(i,a,n) for(int i=a;i<n;i++)


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
string division(string &a , string &b){
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
	b=r;
	if(b.si==0) b="0";
	return ans;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		string a,b;
		cin>>a>>b;
		cout<<division(a,b)<<endl<<b<<endl;
	}
	return 0;
}
