//
//  main.cpp
//  newfinal
//
//  Created by Aakash Anand Mishra on 10/24/14.
//  Copyright (c) 2014 Aakash Anand Mishra. All rights reserved.
//

#include <stdio.h>
#include <cctype>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "queue struc.h"
#include "queue struc.cpp"

    using namespace std;

    
    
    
    int main (int argc, const char * argv[]) {
      
    
        
        
        //input array
        int arrayin[30][30];   //initializing variables and an array of 30x30 to take the grid into
        int column = 0;  // to traverse the column of array
        int row = 0; // to traverse the row of array
        int startvalx = strtod(argv[2], NULL);;  //stores x coordinate of the starting value 'S'
        int startvaly = strtod(argv[3], NULL);; //stores y coordinate of the starting value 'S'
        int targetvalx = strtod(argv[4], NULL);; //stores x coordinate of the target value 'T'
        int targetvaly = strtod(argv[5], NULL);; //stores y coordinate of the target value 'T'
        int columncount = 0;// to count the no of columns to show in the input grid file
        
        //creating the ifstream file to get input
        std::ifstream ifs (argv[1], std::ifstream::in);
        //error checking
        if (ifs.fail()){
            std::cout<<"error"<<endl;
        }
       
        
        
        char c = ifs.get();// getting the char of the grid into 'c'
        /*logic to convert the grid input into the array:
         1.run a while loop for the whole grid (exit if end of file is reached )
         2.if c ='1' then that coordinate in array is int 1
         3.if c ='0' then that coordinate in array is int 0
         4.if c ='S' then that coordinate in array is int 10 and startvalx and startvaly get the position of starting value
         5.if c ='T' then that coordinate in array is int 1 and targetvalx and targetvaly get the position of target value
         
         */

            while (!ifs.eof()){
                if(c=='1'){
                    arrayin[row][column] = 1;
                    column++;
                }
                else if(c=='0'){
                    arrayin[row][column] = 0;
                    column++;
                }
                else if (c=='S'){
                    arrayin[row][column] = 10;
                    column++;
                    }
                else if (c=='T'){
                    arrayin[row][column] = 1;
                    column++;

                }
                else if (c=='\n'){
                    row = row + 1;
                    columncount = column ;
                    column =0;
                    
                }
            
            c = ifs.get();
            
        }
        //print the array using the no of rows and columncount that is the no of columns in the input grid file
        for(int i =0; i<row;i++){
            for(int j=0;j<columncount;j++){
                std::cout << arrayin[i][j]<<" ";
            }
            std::cout << '\n';
        }
        
        ifs.close();
        
        //cordinate struct is used to store the coordinates: mydata is to get data from queue
        cordinate mydata;
        cordinate check;                //used later in the program to create coordinates in output
        cordinate initial;              // to load the starting coordinates variables in the queue
        Queue<cordinate> H;             // H is the queue used to populate the array
        initial.row= startvalx;            // putting the coordinates of starting value into the H queue
        initial.col= startvaly;
        H.push(initial);
        int x;                          // the x cordinate of the array is represented by x
        int y;                          // the x cordinate of the array is represented by x
        int now;                            // to store the current value of the popped element
        int outlength;                  // the distance between the 'S' and 'T'
        
        /* logic to find the path or populate the array
         1.A loop runs that keeps on popping the elements in the queue 
         2.loop exit conditions:
         i.either the whole array is covered(in that case H.isempty = 1)
         ii.or the target value has reached (in that case break is used and all the elements of the que are popped)
         3.while the loop is running:
          i.check if any of the values next to the popped coordinate is 1,in that case push that coordinate into the queue H and increase their value
          ii."NO existing signal" is displayed incase no path is found for a specific signal
         
         */
        while(!H.IsEmpty()){
            mydata = H.pop();
            if(mydata.row == targetvalx and mydata.col == targetvaly){
                while(!H.IsEmpty()){
                    H.pop();
                }
            
                break;
                }
        
            x = mydata.row;
            y = mydata.col;
            now = arrayin[x][y];
            
            if(((arrayin[x][y+1] != 1)and y<columncount) and ((arrayin[x][y-1] != 1) and y>0) and ((arrayin[x+1][y] != 1) and x<row) and ((arrayin[x-1][y] != 1)and x>0)) {
                std::cout << "NO Existing signal for coordinates"<<"("<< x <<"," <<y <<")"<<endl;
            }
            else{
       
            if((arrayin[x][y+1] == 1)and y<columncount) {
                arrayin[x][y+1] = 1 + now;
                mydata.row = x;
                mydata.col = y + 1;
                H.push(mydata);
            }
            if((arrayin[x][y-1] == 1) and y>0){
                arrayin[x][y-1] = 1 + now;
                mydata.row = x;
                mydata.col = y -1;
                H.push(mydata);
            }
            if((arrayin[x+1][y] == 1) and x<row){
                arrayin[x+1][y] = 1 + now;
                mydata.row = x + 1;
                mydata.col = y;
                H.push(mydata);
            }
            if((arrayin[x-1][y] == 1)and x>0){
                arrayin[x-1][y] = 1 + now;
                mydata.row = x -1;
                mydata.col = y;
                H.push(mydata);
            }
            
            }
        }
      

        // display the output of the updated the array

        for (int i =0;i<row; i++){
                for(int j=0;j<columncount;j++){
                    std::cout << arrayin[i][j]<<" ";
    }
            std::cout << '\n';
    }
        // displays NO signal is the target is not reached
        if(arrayin[targetvalx][targetvaly]== 1){
            outlength = 0;
            std::cout<<"NO signal"<<endl;
        }
        // the distance from the start to target is shown
        else{
        outlength = arrayin[targetvalx][targetvaly] - 10;
        }
        std::cout<<"distance = "<< outlength<<endl;
    
        
       if(arrayin[targetvalx][targetvaly]!= 1){ //only executed if a path is found
            

            check.row = targetvalx;             // target coordinates x value
            check.col = targetvaly;             //target coordinates y value
            H.push(check);                      //target coordinate is pushed
            cordinate checkpath;                // the cordinate struct is defined to store the popped value
            cordinate outputpath;                  // the cordinate struct is defined to push the value in T
            int checkrow;                       // row coordinate of H popped value
            int checkcolumn;                    //column coordinate of H popped value
            int value;                          // the value of the current popped element
            Queue<cordinate> T;                 // to store the coordinates of the queue
            T.push(check);                      // push the initial value
            cordinate output;                   // output is used to store the T popped value
           
           
           /*the logic to store the coordinates of the path:
            i.loops exits if H is empty
            ii.if the value of the neighboring coordinate is (value of present  -1) then push the coordinate into the queue T
            iii.pushes only one neighbor and not all
            */
            
            while (!H.IsEmpty()) {
                checkpath = H.pop();
                checkrow = checkpath.row;
                checkcolumn = checkpath.col;
                value = arrayin[checkrow][checkcolumn];
                if ((arrayin[checkrow][checkcolumn-1] == (value-1)) and checkcolumn>0){
                    outputpath.row = checkrow;
                    outputpath.col = checkcolumn-1;
                    T.push(outputpath);
                    H.push(outputpath);
                }
                else if ((arrayin[checkrow][checkcolumn+1] == (value-1)) and checkcolumn<columncount){
                    outputpath.row = checkrow;
                    outputpath.col = checkcolumn+1;
                    T.push(outputpath);
                    H.push(outputpath);

                }
                else if ((arrayin[checkrow-1][checkcolumn] == (value-1)) and checkrow>0){
                    outputpath.row = checkrow-1;
                    outputpath.col = checkcolumn;
                    T.push(outputpath);
                    H.push(outputpath);

                         }
                else if ((arrayin[checkrow+1][checkcolumn] == (value-1)) and checkrow<row){
                    outputpath.row = checkrow +1;
                    outputpath.col = checkcolumn;
                    T.push(outputpath);
                    H.push(outputpath);

                         }
                
                         }
          // to display the coordinates
           std::cout<<"Distance coordinates";
          

            while(!T.IsEmpty()){
        
                output = T.print_reverse();       // reverse pop is used to print the coordinates from 'S' to 'T'
                std::cout <<"("<<output.row<<","<<output.col<<")";
            }

        }
    
    
        return 0;
}
        
