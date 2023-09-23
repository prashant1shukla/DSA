#include<bits/stdc++.h>
using namespace std;
//mutex
//semphores

//peterson's solutions:
do {
    flag[i] = true;
    turn = j;
    while(flag[j]&& turn==j);
    // Critical Section

    flag[i]= false;    
} While(true);

do {
    flag[j] = true;
    turn = i;
    while(flag[j]&& turn==i);
    // Critical Section

    flag[j]= false;    
} While(true);
   
