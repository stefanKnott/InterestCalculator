#ifndef CLIENTINTERESTPROJECT_H
#define CLIENTINTERESTPROJECT_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

typedef struct Person{
        char name[20];
        double balance;
        int compounds;
        double rate;
        double estimate;
        struct Person * next;
        struct Person * prev;
 }Person;

typedef struct List{
        struct Person * head;
        struct Person * tail;
        int count;
} List;

/*Outputs the list with its stored information to file labeled Clients.txt upon exiting the program
 @param List * list*/
int printListToFile(List *list);

/*Stores the information given as input to the respective client-node in the list
 @param Person * person*/
int info(Person *p);

/*Calculate the balance estimates for the clients stored with the information given as input.
 @param List * list*/
int calcBalanceEst(List *list);

/*End Menu -- reached after each iteration of the program.
 @param List * list*/
int end(List *list);

/*Deletes the List of Client
 @param List * list*/
int deleteList(List *list);

#endif
