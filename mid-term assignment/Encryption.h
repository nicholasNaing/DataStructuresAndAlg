//
// Created by leonard221b on 10/06/24.
//

#ifndef DATASTRUCTURE_ENCRYPTION_H
#define DATASTRUCTURE_ENCRYPTION_H

#include "stdlib.h"
#include "stdio.h"

int size_of_char(char arr[30]);

int *encryption(char *plainText, char *key){
    int sizeOfPlain = size_of_char(plainText);
    int sizeOfKey = size_of_char(key);
    char encryptedArray[sizeOfPlain];
    printf("This is plain text : %s\n",plainText);
    printf("This is key : %s\n",key);
    printf("This is size of plain text %d\n", sizeOfPlain);
    printf("This is size of key %d\n", sizeOfKey);

    for(int e = 0; e<sizeOfPlain;e++){
        int plain = plainText[e];
        for(int k = 0;k<sizeOfKey;k++){
            plain = plain^key[k];
            printf("%c\n",plain);
        }
        printf("This is last word for %c is %d\n",plainText[e],plain);
        encryptedArray[e] = plain;
    }
    printf("%c\n",28);
    printf("%c\n",3);
    printf("%s",encryptedArray);
    return &encryptedArray;
}
int size_of_char(char arr[30]){
    int size=0;
    for(int i=0; i<30 ;i++){

        if(arr[i]=='\0'){
            break;
        }
        size++;
    }
    return size;
}

#endif //DATASTRUCTURE_ENCRYPTION_H
