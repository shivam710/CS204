#include<bits/stdc++.h>
using namespace std;

struct Stack
{
    int *arr;
    int capacity;
    int top;
};

struct Stack* newStack(int size)
{
    struct Stack* temp=(struct Stack*)malloc(sizeof(struct Stack));
    int arr[size];
    temp->arr=arr;
    temp->capacity=size;
    return temp;


};

void clearStack(struct Stack* temp)
{
    delete temp->arr;
};

bool isempty(struct Stack* st)
{
    return (st->top==-1);
}

int size(struct Stack* st)
{
    return st->top+1;
}

bool Isfull(struct Stack* st)
{
    return st->top==st->capacity-1;
}

void push(struct Stack* st,int key)
{
    if(Isfull(st))
    {
        exit(EXIT_FAILURE);
    }
    else
    {
        st->arr[++(st->top)]=key;
    }

}

int pop(struct Stack* st)
{
    if(isempty(st))
    {
         exit(EXIT_FAILURE);
    }
    else
    {
        return st->arr[(st->top)--];
    }
}

int main()
{
	struct Stack* st=newStack(3);

	push(st,1);
	push(st,2);

	pop(st);
	pop(st);

	push(st,3);

	if(!isempty(st))cout << "Top element is: " << st->arr[st->top]<< endl;
	cout << "Stack size is " << size(st) << endl;

	pop(st);

	if (isempty(st))
		cout << "Stack Is Empty\n";
	else
		cout << "Stack Is Not Empty\n";

	return 0;
}
