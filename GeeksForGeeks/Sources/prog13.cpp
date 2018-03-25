#include "../Headers/MainHeader.h"

using namespace std;

bool isOperand(int c)
{
	if((c>='a' && c<='z') || (c>='A' && c<='Z'))
		return true;
	return false;
}

int opPrecedence(int c)
{
	switch(c)
	{
	case '+':
	case '-':
		return 1;
		break;
	case '*':
	case '/':
		return 2;
		break;
	case '^':
		return 3;
		break;
	case '(':
		return 0;
	default:
		return 100;
	}
}

void InfixToPostfix()
{
	string s;
	cin>>s;

	//string assumes that expression does not have spaces and operands are 1 character in length
	string outString;
	int index = 0;

	MyStack stk(20); //initializing stack

	while(index<s.length())
	{
		if(isOperand(s[index]))
		{
			outString.push_back(s[index]);
		}
		else if(s[index]=='(')
		{
			stk.push(s[index]);
		}
		else if(s[index]==')')
		{
			while(!stk.isEmpty() && stk.getTop()!='(')
			{
				outString.push_back(stk.pop());
			}
			stk.pop(); // to remove extra ')'
		}
		else //operator case
		{
			while(!stk.isEmpty() && opPrecedence(s[index])<=opPrecedence(stk.getTop()))
			{
				outString.push_back(stk.pop());
			}
			stk.push(s[index]);
		}

		index++;
	}

	while(!stk.isEmpty())
	{
		outString.push_back(stk.pop());
	}

	cout<<"PostFix Notation of Expression:"<<outString<<endl;

}
