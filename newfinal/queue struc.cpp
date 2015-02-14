//
//  queue struc.cpp
//  newfinal
//
//  Created by Aakash Anand Mishra on 10/24/14.
//  Copyright (c) 2014 Aakash Anand Mishra. All rights reserved.
//
#ifndef __newfinal__queue_struc__
#define __newfinal__queue_struc__

#include <stdio.h>
#include <iostream>
#include "queue struc.h"
#define MAX_SIZE 101  //maximum size of the array that will store Queue.


#endif  //defined(__newfinal__queue_struc__)
using namespace std;

template< class que >// template class que is defined

Queue<que>::Queue(int x): length(x), in_array(new que[length]) // queue constructor

{ front = 0;                    // initial values of rear and front are 0 and the queue is made of the length
    rear = 0;
}



template< class que >
bool Queue<que>::IsFull()  // turns out to be 1 if queue is full

{if((rear + 1) %  length == front )
        return 1;
else
        return 0;
}

template< class que > void Queue<que>::push(que x) // pushes the element into the queue

{
    if(!Queue<que>::IsFull())
    {in_array[rear] = x;
        rear = (rear + 1) % length;
    }
}
template< class que > bool Queue<que>::IsEmpty()

{if( rear  == front ){
    return 1;
}
else{
    return 0;
}
}



template< class que > que Queue<que>::pop()  // element is popped

{que val;
    if(!Queue<que>::IsEmpty())
        {val = in_array[front];
        front = ( front + 1 ) % length;
    }
    else
    {std::cout << "Queue is Empty : "; // if queue is empty shows "Queue is Empty"
        }
    return val;
}

template<class que>
que Queue<que>::first() const // returns the front object
{
    return in_array[front];
    
}

template<class que>

que Queue<que>::back() const  // returns the rear object

{
    return in_array[rear];
    
}

template<class que>

int Queue<que>::size() const

{
    return ((rear-front +length)%length ); // returns the size of the queue
    
}

template<class que> que Queue<que>::print_reverse()

{
    
    que val;
    if(!Queue<que>::IsEmpty())
    {
        rear = ( rear - 1 ) % length;
        val = in_array[rear];
        
    }
    else
    {std::cout << "Queue is Empty : "; // if queue is empty shows "Queue is Empty"
    }
    return val;
    
    
}



