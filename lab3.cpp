#include<bits/stdc++.h>
#include <cstring>
#include <string> 
using namespace std; 
  

bool Balance(string p) 
{ 
    stack<char> s; 
    char x;
    long long int counter=0; 
  
     
    for (long long int i=0; i<p.length(); i++) 
    { 
        if (p[i]=='('||p[i]=='['||p[i]=='{'||p[i]=='<') 
        { 
          
            s.push(p[i]); 
            continue; 
        } 
	if (p[i]=='|')
	{
		if (s.empty()) 
		{
			s.push(p[i]);
			continue;
		}
     
		x=s.top();
		if(x=='|')
		{	
			s.pop();
			continue;
				
		}
		else
		{
			s.push(p[i]);
			continue;
		}
	
	}

  

        
        if (s.empty()) 
           return false; 
  
        switch (p[i]) 
        { 
        case ')': 
  
            
            x = s.top(); 
            s.pop(); 
            if (x=='{' || x=='['||x=='<') 
                return false; 
            break; 
  
        case '}': 
  
           
            x = s.top(); 
            s.pop(); 
            if (x=='(' || x=='['||x=='<') 
                return false; 
            break; 
  
        case ']': 
  
             
            x = s.top(); 
            s.pop(); 
            if (x =='(' || x == '{'||x=='<') 
                return false; 
            break; 

	case '>': 
  
            
            x = s.top(); 
            s.pop(); 
            if (x =='(' || x == '{'||x=='[') 
                return false; 
            break; 
	
	default:
        return false;		
			
        } 
    } 
  
    
    return (s.empty()); 
} 
  
 
int main() 
{ 
    long long int n;
    cin>>n;
    string p;
    while(n--)
    {
	cin>>p;
    	if (Balance(p)) 
        cout << "YES"<<endl; 
    	else
        cout << "NO"<<endl; 
    }
    return 0; 
} 

