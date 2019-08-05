#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
//single element multiple
char* multiple(char*a,char c)
{
    int p=strlen(a);
    int b=c-'0';
    char* m=(char*)(malloc (100*sizeof(char)));

    int carry=0;
    for(int i=p-1;i>=0;i--)
    {
        m[i+1]=(((a[i]-'0')*b+carry)%10)+'0';
        carry=((a[i]-'0')*b+carry)/10;
    }
    m[0]=carry+'0';
    m[p+1]='\0';
    return m;
}


//addition function
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

//final product
char* multiples(char*a,char*b)
{
    char prod[100][100];
    char* final_product=(char*)(malloc (200*sizeof(char)));
    int q=strlen(b);

    for(int i=0;i<strlen(b);i++)
    {

        strcpy(prod[i],multiple(a,b[i]));

        int p=strlen(prod[i]);
        for(int j=p;j<p+q-i-1;j++)
        {
            prod[i][j]='0';

        }
        prod[i][p+q-i-1]='\0';

    }
    final_product=prod[0];
    for(int i=1;i<strlen(b);i++)
    {
        final_product=summ(final_product,prod[i]);

    }
    return final_product;

}




int main()
{
    int t;
	cin>>t;
	while(t--){
		char a[100],b[100];
		cin>>a>>b;
		cout<<multiples(a,b)<<endl;
	}
	return 0;
}
