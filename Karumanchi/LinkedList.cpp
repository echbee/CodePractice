//
//  LinkedList.cpp
//  codePractice
//
//  Created by HarpreetBansal on 04/05/17.
//  Copyright © 2017 echbee. All rights reserved.
//

#include "LinkedList.hpp"

using std::cout;

#pragma mark - SLL
void insert(SLL **head, int val, int index)
{
    if(head == nullptr || *head == nullptr)
    {
        *head = new SLL();
        (*head)->data = val;
        (*head)->next = nullptr;
        return;
    }
    
    if(index <= 0) // insert at the front
    {
        SLL *newNode = new SLL();
        newNode->data = val;
        newNode->next = *head;
        *head = newNode;
        return;
    }
    else
    {
        SLL *iterator = *head;
        SLL *prevIterator = nullptr;
        while(iterator != nullptr && index != 0)
        {
            prevIterator = iterator;
            iterator = iterator->next;
            index--;
        }
        
        SLL *newNode = new SLL();
        newNode->data = val;newNode->next = nullptr;
        
        if(iterator == nullptr) // insert at the end
        {
            prevIterator->next = newNode;
        }
        else
        {
            //insert somewhere in the middle
            SLL *temp = prevIterator->next;
            prevIterator->next = newNode;
            newNode->next = temp;
        }
    }
}

void del(SLL **head, int index)
{
    if(head == nullptr || *head == nullptr)
        return;
    
    if(index <= 0) // remove the 1st element
    {
        SLL *nodeToDelete = *head;
        *head = (*head)->next;
        delete nodeToDelete;
    }
    else
    {
        SLL *iterator = *head;
        SLL *prevIterator = nullptr;
        
        while(iterator != nullptr && index != 0)
        {
            prevIterator = iterator;
            iterator = iterator->next;
            index--;
        }
        
        if(iterator == nullptr) // No-op
        {
            return;
        }
        else
        {
            prevIterator->next = iterator->next;
            delete iterator;
        }
    }
}

void print(SLL *head)
{
    cout<<"Printing SLL:";
    while(head != nullptr)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<std::endl;
}

void reverse(SLL **head)
{
    if(head == nullptr || *head == nullptr)
        return;
    
    SLL *temp,*prev=nullptr,*current=*head;
    
    while(current != nullptr)
    {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    *head = prev;
}

#pragma mark - CLL

int32_t count(CLL *head)
{
    if(head == nullptr)
        return 0;
    
    CLL *iterator = head;
    int length = 0;
    do
    {
        iterator = iterator->next;
        ++length;
    }while(iterator != head);
    
    return length;
}

void print(CLL *head)
{
    if(head == nullptr)
        return;
    
    CLL *iterator = head;
    do
    {
        std::cout<<iterator->data<<" ";
        iterator = iterator->next;
    }while(iterator != head);
}

void insert(CLL **head, int val, int index)
{
    CLL *newNode = new CLL();
    newNode->data = val;
    newNode->next = nullptr;
    
    if(head == nullptr || *head == nullptr)
    {
        *head = newNode;
        newNode->next = *head;
        return;
    }
    
    if(count(*head) == 1) // only one element present
    {
        if(index == 0)
        {
            newNode->next = *head;
            (*head)->next = newNode;
            *head = newNode;
        }
        else
        {
            (*head)->next = newNode;
            newNode->next = *head;
        }
        return;
    }
    else
    {
        CLL *iterator = *head,*prevIterator;
        if(index <= 0 || index >= count(*head)) // insert at the front & end
        {
            do
            {
                prevIterator = iterator;
                iterator = iterator->next;
            }while(iterator != *head);
            
            if(index <=0)
            {
                *head = newNode;
                newNode->next = iterator;
                prevIterator->next = *head;
            }
            else
            {
                prevIterator->next = newNode;
                newNode->next = *head;
            }
        }
        else //insert somewhere in between
        {
            while(index != 0)
            {
                prevIterator = iterator;
                iterator = iterator->next;
                index--;
            }
            
            CLL *temp = prevIterator->next;
            prevIterator->next = newNode;
            newNode->next = temp;
        }
    }
}
