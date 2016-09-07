//
//  main.c
//  QuickSort
//
//  Created by 洪锐 李 on 15/6/3.
//  Copyright (c) 2015年 洪锐 李. All rights reserved.
//

#include <stdio.h>

int count = 0;
int main(int argc, const char * argv[]) {
    int Array[10];
    puts("Please input 10 integers!");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &Array[i]);
    }
    
    Qsort(Array, 0, 9);
    for (int i = 0; i < 10; i++) {
        printf("%d\n", Array[i]);
    }
    
    return 0;
}

int Qsort(int *Array, int head, int tail){
    
    if (head == tail || head > tail) {
        // To prevent the case head > tail, whcih indicates the sort has been completed.
        return 0;
    }
    
    
    int *pleft, *pright;
    int pivot = 0;
    int tmp = 0;
    int flag = 1;
    //Define the fence and the pointer
    //In order to know which position the pivot should be finally put in, we should set a flag to notice it.
    //Variable tmp is used for swapping
    
    
    pivot = Array[head];
    pleft = &Array[head+1];
    pright = &Array[tail];
    //pleft is the pointer to traverse the array, to find the appropriate element to swap.
    
    
    while (pleft < pright || pleft == pright) {
                                //pright is a fence to confine the pleft not to overthrow the whole program.
        tmp = *pleft;
        
        if (*pleft < pivot) {   //head is always changing everytime the iteration occurs.
            *pleft = Array[head+flag];
            Array[head+flag] = tmp;
            flag++;
            }
        pleft++;

    }
    
    
    flag += head;
    flag--;
    tmp = Array[head];
    Array[head] = Array[flag];
    Array[flag] = tmp;
    //Now it is the time to put the pivot into the right place. The flag will make sure
    //the position is exactly right, that is, the elements on the left side are smaller than it.
    
    Qsort(Array, head, flag);
    Qsort(Array, ++flag, tail);//flag may be greater than tail at this time.
    
    return 0;
}
