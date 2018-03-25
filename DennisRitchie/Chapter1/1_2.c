//
//  1.c
//  codePractice
//
//  Created by HarpreetBansal on 07/03/17.
//  Copyright © 2017 echbee. All rights reserved.
//

#include "1_2.h"
#include <stdbool.h>

void func()
{
    printf("Hello\c");
}

void func1_4()
{
    int min = 20;
    int max = 300;
    int step = 20;
    
    float cel,fah=min;
    printf("%s\t %s\n","Farenheit","Celsius");
    while(fah<=max)
    {
        cel = 5*(fah-32)/9.0;
        printf("%6.0f\t%6.2f\n",fah,cel);
        fah+=step;
    }
}

//Use file stream redirection in terminal
void echoFunction()
{
    int c;
    while((c=getchar()) != EOF)
    {
        putchar(c);
    }
}

void func1_19() //reverse a string
{
    char c[9] = "helloMeH";
    int len = 8;
    int numToReplace = len/2;
    for(int i=0;i<numToReplace;i++)
    {
        int temp = c[i];
        c[i] = c[len-1-i];
        c[len-1-i] = temp;
    }
    printf("Output=%s\n",c);
}

void func1_9()
{
    int blanks,tabs,nl;
    blanks=tabs=nl = 0;
    int c;
    bool inBlanks = false;
    while((c = getchar()) != EOF)
    {
        if(c == ' ' && inBlanks)
            continue;
        else if(c == ' ')
            inBlanks = true;
        else
            inBlanks = false;
        
        putchar(c);
        
    }
}

void func1_8()
{
    int blanks,tabs,nl;
    blanks=tabs=nl = 0;
    int c;
    while((c = getchar()) != EOF)
    {
        if(c == ' ')
            blanks++;
        if(c=='\t')
            tabs++;
        if(c=='\n')
            nl++;
    }
    printf("\nBlanks=%d\n",blanks);
    printf("\nTabs=%d\n",tabs);
    printf("\nNewLines=%d\n",nl);
}

void func1_7()
{
    printf("EOF=%d",EOF);
}
