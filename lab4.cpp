#include<bits/stdc++.h>

using namespace std;

int prec(string m){
    //This function sets the precedence order of the opstrtors
    if(m=="^")return 3;
    else if(m=="*"||m=="/")return 2;
    else if(m=="+"||m=="-")return 1;
    //in all other cases u need to return -1
    else return -1;
}
vector <string> infixToPostfix(vector<string> exp)
{
    stack<string> opstack;
    opstack.push("END");
    vector <string> opstr;
    for(int i = 0; i < exp.size(); i++)
    {

        if(exp[i]!="("&&exp[i]!=")"&&exp[i]!="*"&&exp[i]!="^"&&exp[i]!="-"&&exp[i]!="+"&&exp[i]!="/")
        opstr.push_back(exp[i]);


        else if(exp[i] == "(")

        opstack.push("(");


        else if(exp[i] == ")")
        {
            while(opstack.top() != "END"&& opstack.top() != "(")
            {
                string s = opstack.top();
                opstack.pop();
               opstr.push_back(s);
            }
            if(opstack.top() == "(")
            {
                string s = opstack.top();
                opstack.pop();
            }
        }

        else{
            while(opstack.top() != "END" && prec(exp[i]) <= prec(opstack.top()))
            {
                if(prec(exp[i])==3&&prec(opstack.top())==3)break;
                string s = opstack.top();
                opstack.pop();
                opstr.push_back(s);
            }
            opstack.push(exp[i]);
        }

    }
    while(opstack.top() != "END")
    {
        string s = opstack.top();
        opstack.pop();
        opstr.push_back(s);
    }

    return opstr;
}
struct  evalTree
{
    string value;
    evalTree* left, *right;
};


bool Isaopstrtor(string s)
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

        if (Isaopstrtor(pf[i])==0)
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
int StrtoInt(string s)
{
    int num=stoi(s);

    return num;
}
int eval(evalTree* head)
{

    if (!head)
        return 0;


    if (!head->left && !head->right)
        return StrtoInt(head->value);


    int leftval = eval(head->left);

    int rightval = eval(head->right);


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
    while(n--)
    {
        unsigned long long int t;cin>>t;
         while(t--)
         {
              int flag=1;
             string s;
             cin>>s;
             vector <string> v;
             char prev=0;
             for(int i=0;i<s.length();i++)
             {
                 if(s[i]=='('||s[i]==')'||s[i]=='*'||s[i]=='^'||s[i]=='-'||s[i]=='+'||s[i]=='/')
                 {

                      string res;
                      res+=s[i];
                     if(s[i]=='-'&&prev=='(')
                     {
                        v.push_back("0");
                     }
                    prev=s[i];

                    v.push_back(res);
                 }
                 else
                 {

                    string res;
                    while(s[i]!='('&&s[i]!=')'&&s[i]!='*'&&s[i]!='^'&&s[i]!='-'&&s[i]!='+'&&s[i]!='/'&&i<s.length())
                    {
                        if(s[i]>='0'&&s[i]<='9')
                         {
                              res+=s[i];
                              i++;
                         }
                         else
                         {
                            flag=0;
                             break;
                         }
                    }
                    i--;
                    v.push_back(res);

                 }
                if(flag==0)break;
             }
            if(flag)
            {

                 vector <string> o=infixToPostfix(v);

                evalTree*t = constructTree(o);

                cout<<eval(t)<<endl;
            }
            else
            {
                cout<<"INVALID INPUT"<<endl;
            }
        }
    }

    return 0;

}
