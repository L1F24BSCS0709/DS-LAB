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
void infixToPostfix(char* exp)
{
    Stack<char> s(100);
    char postfix[50];
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
            postfix[j] = ch;
            j++;
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        {
            while (!s.isEmpty() && presedance(exp[i] >= presedance(ch)))
            {
                postfix[j] = s.pop();
                j++;
            }
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
            {
                postfix[j] = s.pop();
                j++;
            }
            s.pop();

            
        }
        
    }
    postfix[j] = '\0';
    while (!s.isEmpty())
    {
        postfix[j++] = s.pop();
    }
    cout << "Postfix Expression: " << postfix << endl;

}










int main()
{
   
    char exp[] = "(A+B+C*D)";
    infixToPostfix(exp);
    return 0;

}