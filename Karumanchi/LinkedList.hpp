//
//  LinkedList.hpp
//  codePractice
//
//  Created by HarpreetBansal on 04/05/17.
//  Copyright © 2017 echbee. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <iostream>

struct SLL
{
    int data;
    SLL *next;
};

void insert(SLL **head, int val, int index);
void del(SLL **head, int index);
void print(SLL *head);

void reverse(SLL **head);

struct CLL
{
    int data;
    CLL *next;
};

int32_t count(CLL *head);
void print(CLL *head);
void insert(CLL **head, int val, int index);

#endif /* LinkedList_hpp */
