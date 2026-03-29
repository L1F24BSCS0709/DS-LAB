#include <iostream>
using namespace std;

template<class T>
class Stack
{
    T* arr;
    int size;
    int top;

public:

    Stack(int ssize)
    {
        size = ssize;
        arr = new T[size];
        top = -1;
    }

    bool isEmpty()
    {
        return (top == -1);
    }

    bool isFull()
    {
        return (top == size - 1);
    }

    void push(T value)
    {
        if (!isFull())
            arr[++top] = value;
        else
            cout << "Stack is Full";
    }

    T pop()
    {
        T temp = arr[top];
        top--;
        return temp;
    }

    T peek()
    {
        return arr[top];
    }
};

int presedance(char op)
{
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}
void reverseExp(char* &exp)
{
    Stack<char> s(100);
    for (int i = 0; exp[i] != '\0'; i++)
    {
        s.push(exp[i]);
    }
    int j = 0;
    while (!s.isEmpty())
    {
        char ch = s.pop();

        if (ch == '(')
            exp[j++] = ')';
        else if (ch == ')')
            exp[j++] = '(';
        else
            exp[j++] = ch;
    }
    exp[j] = '\0';
}
void infixToPrefix(char* exp)
{
    Stack<char> s(100);
    reverseExp(exp);
    char* prefix=new char[100];
    int j = 0;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        char ch = exp[i];
        if (ch == '(')
        {
            s.push(ch);
        }
        else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            prefix[j] = ch;
            j++;
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        {
            while (!s.isEmpty() && presedance(s.peek()) > presedance(ch))
            {
                prefix[j] = s.pop();
                j++;
            }
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
            {
                prefix[j] = s.pop();
                j++;
            }
            s.pop();


        }

    }
    while (!s.isEmpty())
    {
        prefix[j++] = s.pop();
    }
    prefix[j] = '\0';

    reverseExp(prefix);
    cout << "Prefix Expression: " << prefix << endl;

}










int main()
{
    
    char exp[] = "(A+B+C*D)";
    infixToPrefix(exp);
    return 0;

}