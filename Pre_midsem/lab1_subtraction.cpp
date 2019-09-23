#include <iostream>
#include <cstring>
#include <cstdlib>-
using namespace std;

//declaring subtraction function
char* sub(char*a,char*b)
{
	int p=strlen(a);
	int q=strlen(b);
	int sub[200];
	char* subt= (char*)(malloc(200*sizeof(char)));


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
    char sign='0'; //sign for negative case

    //placing the larger number to first

	for(int i=0;i<p;i++)
	{
		if((a[i]-'0')-(b[i]-'0')<0)
		{

			char *t=b;
			b=a;
			a=t;
			sign='-';
			break;
        }
        if((a[i]-'0')-(b[i]-'0')>0) break;
	}

	//adjusting new length
	p=strlen(a);
	q=strlen(b);
	int c=0;

	//subtracting
	for(int i=p-1;i>=0;i--)
	{
		if((a[i]-'0')-(b[i]-'0')-c>=0)
		{

			sub[i]= ((a[i]-'0')-(b[i]-'0')-c);
			c=0;

		}
		else if((a[i]-'0')-(b[i]-'0')-c<0)
		{
			sub[i]= ((a[i]-'0')-(b[i]-'0')+10-c);
			c=1;

		}
	}


    subt[0]=sign;
	subt[p+1]='\0';
	for(int i=0;i<p;i++)
    {
        subt[i+1]=sub[i]+'0';

    }
	return subt;
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		char a[100],b[100];
		cin>>a>>b;
		cout<<sub(a,b)<<endl;
	}
	return 0;

}
