#include<iostream>
#include<string>
using namespace std;
class Stack
{
	protected:
	int top,size;
	char *array;
	public:
		Stack(){top=-1;}
		Stack(int size)
		{
			top=-1;
			this->size=size;
			array = new char[size];
		}
		bool IsEmpty()
		{
			if(top==-1)
			return true;
			else 
			return false;
		}
		bool IsFull()
		{
			if(top==size-1)
			return true;
			else
			return false;	
		}
		void push(char character)
		{
			if(IsFull())
			cout<<"\n sorry, the array is full";
			else
			{
				++top;
				array[top]= character;
				
			}
		}
		char pop()
		{
			char element;
			if(IsEmpty())
			cout<<"\n Sorry , there is no element\n";
			else
			{
				element=array[top--];
				return element;
			}
		}
		char topEle()
		{
			if(IsEmpty())
			cout<<"\n Sorry, empty array \n";
			else
			return array[top];
			
		}
	
};
class Conversion: public Stack
{
	
public:
	bool IsOperator(char c)
	{
		if(c== '+' || c == '-' || c == '*' || c == '/')
		return true;

	    return false; 
	}
	bool IsOperand(char c)
	{
		if(c >= '0' && c <= '9') return true;
	    if(c >= 'a' && c <= 'z') return true;
	    if(c >= 'A' && c <= 'Z') return true;
	    else
     	return false;
	}
	int getOperatorPriority(char Operator)
	{
		int priority ; 
	switch(Operator)
	{
	case '+':
		priority=1;
		break;
	case '-':
		priority = 1;
		break;
	case '*':
		priority=2;
		break;
	case '/':
		priority = 2;
		break;
	
	}
	return priority;
	}
	
	
	bool IsRightAssociative(char Operator)
	{
		if (Operator== '^') {
           return true;
           }
           return false; 
	}
	bool HasHigherPrecedence(char op1, char op2)
     {   
	 
	 
	int op1Priority = getOperatorPriority(op1);
	int op2Priority = getOperatorPriority(op2);

	
	if(op1Priority == op2Priority)
	{
		if(IsRightAssociative(op1)) 
		return false;
		else return true;
	}
	return op1Priority > op2Priority ?  true: false;
  }
  
  string Infix_Postfix(string expression)
  {
  	Stack s(expression.length());

  	string postfix ="";
  	
  
  	for(int i=0;i<expression.length();i++)
  	  {
  	  	if(expression[i] == ' ' || expression[i] == ',') 
			continue; 
         if(IsOperator(expression[i]))
	    {
	    
	    	
	         while(!s.IsEmpty() && s.topEle() != '(' && HasHigherPrecedence(s.topEle(),expression[i]))
			{
				postfix+= s.topEle();
				s.pop();
				
			}
			
			s.push(expression[i]);
	   }
		// Else if character is an operand
		else if(IsOperand(expression[i]))
		{
		
			postfix +=expression[i];
		}

		else if (expression[i] == '(') 
		{
			s.push(expression[i]);
		}

		else if(expression[i] == ')') 
		{
			while(!s.IsEmpty() && s.topEle() !=  '(') {
				postfix += s.topEle();
				s.pop();
				
			}
			
			s.pop();
		}
	}
	while(!s.IsEmpty()) 
	{
		postfix += s.topEle();
		s.pop();
	
	}

	return postfix;
}
	
};



int main()
{
	string expression; 
	cout<<"Enter Infix Expression \n";
	cin>>expression;
    Conversion c;
	string postfix ;	
postfix=
	c.Infix_Postfix(expression);
		cout<<"After Conversion from Infix to PostFix : "<<postfix<<"\n";
	return 0;
}
