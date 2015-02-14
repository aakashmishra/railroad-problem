//
//  queue struc.h
//  newfinal
//
//  Created by Aakash Anand Mishra on 10/24/14.
//  Copyright (c) 2014 Aakash Anand Mishra. All rights reserved.
//

#ifndef __newfinal__queue_struc__
#define __newfinal__queue_struc__

#include <stdio.h>
#include <iostream>
 //maximum size of the array that will store Queue.


#endif  //defined(__newfinal__queue_struc__)
using namespace std;

//defining the path 

struct cordinate

{
    
    int row =0;
    
    int col =0;
    
};
template< class que > class Queue

{
    
private:
    
    int length;
    
    que *in_array;
    
    int front;
    
    int rear;
    
    
    
public:
    
    Queue(int x = 100);//default constructor //maximum size of the array that will store Queue
    
    ~Queue()//destructor
    
    {delete [] in_array;}
    
    void push( que );
    
    que pop();
    
    que first() const;
    
    que back() const;
    
    bool IsEmpty();
    
    bool IsFull();
    
    int size() const;
    
    que print_reverse();
    
    
    
};



