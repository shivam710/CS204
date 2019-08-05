#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
//declare sum function
char* summ(char*a,char*b)
{
	int p=strlen(a);
	int q=strlen(b);
	int sum[200];
	char * sums=(char*)(malloc (200*sizeof(char)));


    //making string of equal length
	if(p-q>0)
	{
		for(int i=q;i>=0;i--)
		{
			b[i+p-q]=b[i];
		}
		for(int i=0;i<p-q;i++)
		{
			b[i]='0';
		}
	}
	if(p-q<0)
	{
		for(int i=p;i>=0;i--)
		{
			a[i+q-p]=a[i];
		}
		for(int i=0;i<q-p;i++)
		{
			a[i]='0';
		}
	}
    //setting new length
	p=strlen(a);
	q=strlen(b);
	int rem=0;

	//adding both strings
	for(int i=p-1;i>=0;i--)
	{
		if((a[i]-'0')+(b[i]-'0')+rem<10)
		{

			sum[i+1]= ((a[i]-'0')+(b[i]-'0')+rem);
			rem=0;

		}
		else if((a[i]-'0')+(b[i]-'0')+rem>=10)
		{
			sum[i+1]= ((a[i]-'0')+(b[i]-'0')-10+rem);
			rem=1;

		}
	}
	sum[0]=rem;
	sums[p+1]='\0';
	for(int i=0;i<p+1;i++)
    {
        sums[i]=sum[i]+'0';
    }
	return sums;
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		char a[100],b[100];
		cin>>a>>b;
		cout<<summ(a,b)<<endl;
	}
	return 0;

}
