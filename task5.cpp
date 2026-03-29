#include<string>
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


int main()
{
    Stack<string> backStack(20);     
    Stack<string> forwardStack(20);  
    string currentPage = "";         
    string command, url;
    while (true) 
    {
        cout << "Enter Command .Type only VISIT, BACK, FORWARD, EXIT\n";
        cin >> command;
        if (command == "VISIT") 
        {
            cout << "enter url: " << endl;
            cin >> url;
            backStack.push(url);
            currentPage = url;
            while (!forwardStack.isEmpty())
            {
                forwardStack.pop();
            }

        }
        else if (command == "BACK")
        {
            if (backStack.isEmpty())
            {
                cout << "NOTHING TO GO BACK" << endl;
            }
            else
            {
                forwardStack.push(currentPage);
                currentPage = backStack.pop();
                cout << "Current: " << currentPage<<endl;
            }
        }
        else if (command == "FORWARD")
        {
            if (forwardStack.isEmpty())
            {
                cout << "NOTHING TO GO Forward" << endl;
            }
            else
            {
                backStack.push(currentPage);
                currentPage = forwardStack.pop();
                cout << "Current: " << currentPage;
            }
        }
        else if (command == "EXIT") 
        {
            cout << "CLOSING ALL PAGES..." << endl
                << "Loading Please Wait.......\nExited.\n";
            exit(0);
        }
        else
        {
            cout << "INVALID COMMAND.\nType only VISIT, BACK, FORWARD, EXIT\n";
        }
    }




}