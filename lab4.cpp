#include<bits/stdc++.h>

using namespace std;

int prec(string m){
	//This function sets the precedence order of the operators
	if(m=="^")return 3;
	else if(m=="*"||m=="/")return 2;
	else if(m=="+"||m=="-")return 1;
	//in all other cases u need to return -1
	else return -1;
}
vector <string> infixtopostfix(vector<string> exp)
{
    stack<string> opwala;
    opwala.push("END");
    vector <string> opera;
    for(int i = 0; i < exp.size(); i++)
    {

        if(exp[i]!="("&&exp[i]!=")"&&exp[i]!="*"&&exp[i]!="^"&&exp[i]!="-"&&exp[i]!="+"&&exp[i]!="/")
        opera.push_back(exp[i]);


        else if(exp[i] == "(")

        opwala.push("(");


        else if(exp[i] == ")")
        {
            while(opwala.top() != "END"&& opwala.top() != "(")
            {
                string s = opwala.top();
                opwala.pop();
               opera.push_back(s);
            }
            if(opwala.top() == "(")
            {
                string s = opwala.top();
                opwala.pop();
            }
        }

        else{
            while(opwala.top() != "END" && prec(exp[i]) <= prec(opwala.top()))
            {
            	if(prec(exp[i])==3&&prec(opwala.top())==3)break;
                string s = opwala.top();
                opwala.pop();
                opera.push_back(s);
            }
            opwala.push(exp[i]);
        }

    }
    while(opwala.top() != "END")
    {
        string s = opwala.top();
        opwala.pop();
        opera.push_back(s);
    }

    return opera;
}
struct 	evalTree
{
    string value;
    evalTree* left, *right;
};


bool IsaOperator(string s)
{
    if (s == "+" || s== "-" ||
            s == "*" || s == "/" ||
            s == "^")
        return 1;
    else return 0;
}

evalTree* newNode(string val)
{
    evalTree *temp = new evalTree;
    temp->left = temp->right = NULL;
    temp->value = val;
    return temp;
};


evalTree* constructTree(vector<string> pf)
{
    stack<evalTree *> st;
    evalTree *t, *t1, *t2;


    for (int i=0; i<pf.size(); i++)
    {

        if (IsaOperator(pf[i])==0)
        {
            t = newNode(pf[i]);
            st.push(t);
        }
        else
        {
            t = newNode(pf[i]);


            t1 = st.top();
            st.pop();
            t2 = st.top();
            st.pop();


            t->right = t1;
            t->left = t2;


            st.push(t);
        }
    }

    t = st.top();
    st.pop();

    return t;
}
int toInteger(string s)
{
    int num=stoi(s);

    return num;
}
int evaluation(evalTree* head)
{

    if (!head)
        return 0;


    if (!head->left && !head->right)
        return toInteger(head->value);


    int leftval = evaluation(head->left);

    int rightval = evaluation(head->right);


    if (head->value=="+")
        return leftval+rightval;

    if (head->value=="-")
        return leftval-rightval;

    if (head->value=="*")
        return leftval*rightval;
    if(head->value=="^"){
    	return pow(leftval,rightval);
    }

    return leftval/rightval;
}
int main(){
    unsigned long long int n;cin>>n;
    while(n--){
	unsigned long long int t;cin>>t;
	while(t--){
		int flag=1;
	string s;
	cin>>s;
	vector <string> v;
	for(int i=0;i<s.length();i++){
		if(s[i]=='('||s[i]==')'||s[i]=='*'||s[i]=='^'||s[i]=='-'||s[i]=='+'||s[i]=='/'){
			string res;
			res+=s[i];
			v.push_back(res);
		}
		else{
			string res;
			while(s[i]!='('&&s[i]!=')'&&s[i]!='*'&&s[i]!='^'&&s[i]!='-'&&s[i]!='+'&&s[i]!='/'&&i<s.length()){
				if(s[i]>='0'&&s[i]<='9'){
				res+=s[i];
				i++;
			}
			else{
				flag=0;
				break;
			}
			}
			i--;
			v.push_back(res);
		}
		if(flag==0)break;
	}
	if(flag){
	//cout<<v.size()<<"||";
	vector <string> o=infixtopostfix(v);
	//for(int i=0;i<o.size();i++)cout<<o[i]<<" ";
	//cout<<endl;
	evalTree*t = constructTree(o);

	//inorder(t);
	cout<<evaluation(t)<<endl;
}
else{
	cout<<"NOT A VALID INPUT"<<endl;
}
}
}

	return 0;


}
