#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>

typedef struct {
    char surname[50];       
    char name[50];          
    char country[50];       
    char team[50];          
    int number;             
    int age;                
    float height;           
    float weight;           
    union {
        int matchesPlayed;  
        char awards[50];    
    } additionalInfo;       
} Player;

#endif