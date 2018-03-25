/*
 Please note that it's Function problem i.e.
 you need to write your solution in the form of Function(s) only.
 Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Node structure  used in the program
 struct Node{
	int data;
	struct Node * next;
	struct Node * bottom ;
 }; */
/*  Function which returns the  root of
 the flattened linked list. */

// Please implement the serializer and deserializer for char array below.
// For char arrays, we follow the JSON standard according to http://www.json.org/
// Therefore, a single character A is represented as "A" (wrapped in double quotes instead of single quotes).
// A char array containing 3 elements "A", "B", "C" is represented in string as ["A","B","C"].
// For the purpose of this problem, you must not use JSON parser library or eval method.
// Standard library provided by the language (not including JSON library) is allowed.

#include "CommonHeaders.h"

template <typename T>
class MyStack
{
public:
    MyStack(int size = 0);
    
    void push(const T &elem);
    void pop();
    const T top();
    bool isEmpty();
private:
    deque<T> vec;
};

template <class T>
MyStack<T>::MyStack(int size) : vec(size)
{
    
}

template <class T>
void MyStack<T>::push(const T &elem)
{
    vec.push_back(elem);
}

template <class T>
void MyStack<T>::pop()
{
    if(!isEmpty())
        vec.pop_back();
    else
        throw "Not Possible";
}

template <class T>
const T MyStack<T>::top()
{
    if(!isEmpty())
    {
        return vec.back();
    }
    else
        throw "Not possible";
}

template <class T>
bool MyStack<T>::isEmpty()
{
    return ((vec.size() == 0) ? true : false);
}

int bSearch(vector<int>::iterator beginIt,vector<int>::iterator endIt, int elemToSearch)
{
    decltype(beginIt) start = beginIt;
    decltype(beginIt) end = endIt;
    
    decltype(beginIt) mid;
    
    while(start < end)
    {
        mid = start + (end - start)/2;
        
        if((*mid) == elemToSearch)
            return (mid - beginIt);
        else if((*mid) < elemToSearch)
            start = mid + 1;
        else
            end = mid - 1;
        
    }
    return -1;
}

int main()
{
    vector<int> v{1, 2, 3, 4};
    cout<<bSearch(v.begin(), v.end(), 4)<<endl;
    return 0;
}

