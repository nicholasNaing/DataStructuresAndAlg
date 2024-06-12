//
// Created by leonard221b on 10/06/24.
//

#ifndef DATASTRUCTURE_ADMINSECTOR_H
#define DATASTRUCTURE_ADMINSECTOR_H

#include "programHeaders.h"
#include "stdio.h"

void ban_users(){
    int ban_userid = 0;
    printf("You can ban the users from the following list\n");
    for(int i=3;i<g_userCount;i++){
        printf("UserId:%d||Name:%s\n",data[i].user_id,data[i].user_name);
    }
    printf("Choose userId you want to ban :");
    scanf("%d",&ban_userid);
    if(ban_userid>2){
        data[ban_userid].isDeleted = 1;
        printf("You have ban the user %s\n",data[ban_userid].user_name);
        record_data();
    }else if(ban_userid<3 && ban_userid>=0){
        printf("That's the id of the admin. You can't ban another admin\n");
    }else{
        printf("Please input the correct number");
    }
}
void suspend_users(){
    int suspend_userid = 0;
    printf("Whose activities do you want to suspend?\n");
    for(int i=3;i<g_userCount;i++){
        printf("UserId:%d||Name:%s\n",data[i].user_id,data[i].user_name);
    }
    printf("Choose userId you want to suspend :");
    scanf("%d",&suspend_userid);
    if(suspend_userid>2){
        data[suspend_userid].isSuspended = 1;
        printf("You have suspend the activities of the user %s\n",data[suspend_userid].user_name);
        record_data();
    }else if(suspend_userid<3 && suspend_userid>=0){
        printf("That's the id of the admin. You can't suspend the activities of another admin");
    }else{
        printf("Please input the correct number");
    }
}

#endif //DATASTRUCTURE_ADMINSECTOR_H
