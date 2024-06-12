//
// Created by leonard221b on 10/06/24.
//

#ifndef DATASTRUCTURE_TRANSACTIONUTIL_H
#define DATASTRUCTURE_TRANSACTIONUTIL_H

#include "stdio.h"
#include "programHeaders.h"
#include "validationUtil.h"
#include "time.h"

void transaction(int sender_id , int receiver_id,double amount){
    double percentage = amount*0.02;
    data[sender_id].amount = data[sender_id].amount-amount-percentage;
    data[receiver_id].amount = data[receiver_id].amount+amount;
    data[0].amount += percentage;
    printf("Transaction Complete From %s to %s : amount = %lf\n",data[sender_id].user_name,data[receiver_id].user_name,amount);
    transaction_record(sender_id , receiver_id,amount);
    all_data();
    my_privilege(sender_id);

}

void transaction_record(int sender_id , int receiver_id,double amount){
    time_t currentTime;
    time(&currentTime);

    char *timeString = ctime(&currentTime);
    // Replace spaces with hyphens in the time string
    for (int i = 0; i < size_of_charArray(timeString); i++) {
        if (timeString[i] == ' ') {
            timeString[i] = '-';
        }
    }

    // Print the modified time string

    int sender_index= data[sender_id].trans_counter;

    int receiver_index=data[receiver_id].trans_counter;
    int admin_index = data[0].trans_counter;
//    int sender_index= 0;
//    int receiver_index=0;

    char *from="From-";
    //char *sender = data[sender_id].user_name;
//    char sender[20];
//    char receiver[20];
    char *sender = data[sender_id].user_name;
    char *to="-To-";
    char *receiver= data[receiver_id].user_name;
    //char *receiver= data[receiver_id].user_name;

//    copy_two_charArray(sender,data[sender_id].user_name);
//    copy_two_charArray(receiver,data[receiver_id].user_name);


    char *receive="ReceiveFrom-";
    char *on = "-on-";

    sprintf((char *) data[sender_id].trans[sender_index].trans_record, "%s%s%s%s%c%lf%s%s", from, sender, to, receiver,'-',amount,on,
            timeString);
    sprintf((char *) data[receiver_id].trans[receiver_index].trans_record, "%s%s%c%lf%s%s", receive, sender,'-',amount,on,
            timeString);
    //for ower account which is admin 0
    sprintf((char *) data[0].trans[admin_index].trans_record, "%s%s%s%s%c%lf%s%s", from, sender, to, receiver,'-',amount,on,
            timeString);

//    printf("all data for Sender %s\n",data[sender_id].trans);
//    printf("all data for receiver %s\n",data[receiver_id].trans);

    data[sender_id].trans_counter++;
    data[receiver_id].trans_counter++;
    data[admin_index].trans_counter++;

}

void to_transfer_checking(int id){
    double amount=0;
    int receiver_phone=0;//
    int phone_id=0;
    int option=0;
    int cout_wrong=0;
    printf("Enter your amount to transfer:");
    scanf("%lf",&amount);

    while(data[id].amount>amount+100){

        printf("Enter receiver phone number to send money:");
        scanf("%d",&receiver_phone);
        phone_id =to_check_phone(receiver_phone);
        if(data[phone_id].isSuspended==1){
            printf("You cannot transfer money to this phone number\nThis phone number owner is suspended\n");
        }else {
            if (phone_id != -1) {
                transaction(id, phone_id, amount);
            } else {
                printf("This phone number is not available in our system!\n");
                cout_wrong++;
                if (cout_wrong > 2) {
                    fprintf(stderr, "Wrong Phone Number!");
                    my_privilege(id);
                }
            }
        }
    }

    printf("Insufficient Amount: %lf\n",data[id].amount);
    printf("Press 1 to continue transaction:\nPress 2 To get Privilege:\n");
    scanf("%d",&option);
    if(option==1){
        to_transfer_checking(id);
    } else if(option==2){
        my_privilege(id);
    } else{
        fprintf(stderr,"Invalid Option\n");
        menu();
    }

}

#endif //DATASTRUCTURE_TRANSACTIONUTIL_H
