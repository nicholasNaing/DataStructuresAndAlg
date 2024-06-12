//
// Created by leonard221b on 10/05/24.
//
#include "programHeaders.h"
#include "transactionUtil.h"
#include "validationUtil.h"
#include "adminSector.h"
#include "stdio.h"
#include "time.h"


int main(){
    //using avl tree with linear search or make a separate hash table for email correspond to userId
    // when user log in we only got email and can't user that to search for the match unless it's an id.
    // so final conclusion was that if it's 1000 users, the linear search efficiency is neglegible but
    //if it's about a million users, making a separate hash table for the search efficiency would be better.

    // in conclusion, it's a trade off between memory and search efficiency.


    loading_data_from_file();
    // transaction_record(1,2,1000);

    all_data();
    menu();

//    char *arr = "This is plain text";
//    char *key = "This is key";
//    int *array = encryption(arr,key);
//    for(int i=0;i<18;i++){
//        printf("%d",array[i]);
//    }
    return 0;
}