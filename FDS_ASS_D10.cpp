/*Implement C++ program for expression conversion as infix to postfix and its evaluation using stack based on given conditions
i. Operands and operator, both must be single character.
ii. Input Postfix expression must be in a desired format.
iii. Only '+', '-', '*' and '/ ' operators are expected.*/
#include <iostream>
#include <string>
using namespace std;

class stack
{
    char *arr;
    int top = -1;

public:
    stack()
    {
        arr = new char[100];
        top = -1;
    }

    void push(char x)
    {
        top++;
        arr[top] = x;
    }

    void pop()
    {
        top--;
    }

    char Top()
    {
        return arr[top];
    }

    bool empty()
    {
        return top == -1;
    }
};

class intstack
{
    int *arr;
    int top = -1;

public:
    intstack()
    {
        arr = new int[100];
        top = -1;
    }

    void push(int x)
    {
        top++;
        arr[top] = x;
    }

    void pop()
    {
        top--;
    }

    int Top()
    {
        return arr[top];
    }

    bool empty()
    {
        return top == -1;
    }
};

int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int postfixEvaluation(string s)
{
    intstack st1;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] <= 'Z' && s[i] >= 'A'))
        {
            int x;
            cout << "Enter the value of " << s[i] << " : ";
            cin >> x;
            st1.push(x);
        }
        else
        {
            int op2 = st1.Top();
            st1.pop();
            int op1 = st1.Top();
            st1.pop();
            switch (s[i])
            {
            case '+':
                st1.push(op1 + op2);
                break;
            case '-':
                st1.push(op1 - op2);
                break;
            case '/':
                st1.push(op1 / op2);
                break;
            case '*':
                st1.push(op1 * op2);
                break;
            }
        }
    }
    return st1.Top();
}

string infixToPostfix(string s)
{
    string ans;
    stack st;
    for (int i = 0; i < s.length(); i++)
    {

        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] <= 'Z' && s[i] >= 'A'))
        {
            ans += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.Top() != '(')
            {
                ans += st.Top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && (s[i] == '^' ? prec(st.Top()) > prec(s[i]) : prec(st.Top()) >= prec(s[i])))
            {
                ans += st.Top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty())
    {
        ans += st.Top();
        st.pop();
    }

    return ans;
}

int main()
{
    string s;
    char cont = 'y';
    while (cont == 'y')
    {
        cout << "Enter the infix Expression: ";
        cin >> s;
        cout << "The postfix expression is: " << infixToPostfix(s) << endl;
        int ans = postfixEvaluation(infixToPostfix(s));
        cout << "The ans after postfix evaluation is: " << ans << endl;
        cout << "Do you want to continue? (y/n): ";
        cin >> cont;
    }
    if (cont == 'n')
    {
        cout << "Program Ended Successfully!!!" << endl;
    }
    return 0;
}