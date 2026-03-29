
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
int postfixEvaluation(const char* exp)
{
    Stack<int> s(30);
    int answer = 0;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] >= '0' && exp[i] <= '9')
        {
            s.push(exp[i]-'0');
        }
        else
            if (exp[i] == '+')
            {
                int d1 = s.pop();
                int d2 = s.pop();
                answer = d1 + d2;
                s.push(answer);
            }
            else if (exp[i] == '-')
            {
                int d1 = s.pop();
                int d2 = s.pop();
                answer = d2 - d1;
                s.push(answer);

            }
            else if (exp[i] == '*')
            {
                int d1 = s.pop() ;
                int d2 = s.pop();
                answer = d2 * d1;
                s.push(answer);

            }
            else if (exp[i] == '/')
            {
                int d1 = s.pop() ;
                int d2 = s.pop() ;
                answer =(d2 / d1);
                s.push(answer);

            }

    }
    return s.pop();
}
int main()
{
    char exp[] = "53+82-*";
    int res=postfixEvaluation(exp);
    cout << "RESULT OF 53+82-*   is: " << res << endl;
}