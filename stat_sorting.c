#include "header.h"
#include <stdio.h>
#include <stdlib.h>

/* function to swap data of two nodes a and b*/
void swap(Node *a,Node *b) 
{ 
    Pokemon temp = a->data; 
    a->data = b->data; 
    b->data = temp; 
} 

void sort_by_bst(Node *pHead)
{
    int swapped = 0;
    Node *ptr1; 
    Node *lptr = NULL; 

    /* Checking for empty list */
    if (pHead == NULL) 
        return; 

    do
    {
        swapped = 0; 
        ptr1 = pHead; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->data.stats.Total > ptr1->next->data.stats.Total) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } while (swapped);
}

void sort_by_hp(Node *pHead)
{
    int swapped = 0;
    Node *ptr1; 
    Node *lptr = NULL; 

    /* Checking for empty list */
    if (pHead == NULL) 
        return; 

    do
    {
        swapped = 0; 
        ptr1 = pHead; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->data.stats.HP > ptr1->next->data.stats.HP) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } while (swapped);
}

void sort_by_attack(Node *pHead)
{
    int swapped = 0;
    Node *ptr1; 
    Node *lptr = NULL; 

    /* Checking for empty list */
    if (pHead == NULL) 
        return; 

    do
    {
        swapped = 0; 
        ptr1 = pHead; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->data.stats.Attack > ptr1->next->data.stats.Attack) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } while (swapped);
}

void sort_by_defense(Node *pHead)
{
    int swapped = 0;
    Node *ptr1; 
    Node *lptr = NULL; 

    /* Checking for empty list */
    if (pHead == NULL) 
        return; 

    do
    {
        swapped = 0; 
        ptr1 = pHead; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->data.stats.Defense > ptr1->next->data.stats.Defense) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } while (swapped);
}

void sort_by_sp_attack(Node *pHead)
{
    int swapped = 0;
    Node *ptr1; 
    Node *lptr = NULL; 

    /* Checking for empty list */
    if (pHead == NULL) 
        return; 

    do
    {
        swapped = 0; 
        ptr1 = pHead; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->data.stats.Sp_Attack> ptr1->next->data.stats.Sp_Attack) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } while (swapped);
}

void sort_by_sp_defense(Node *pHead)
{
    int swapped = 0;
    Node *ptr1; 
    Node *lptr = NULL; 

    /* Checking for empty list */
    if (pHead == NULL) 
        return; 

    do
    {
        swapped = 0; 
        ptr1 = pHead; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->data.stats.Sp_Defense > ptr1->next->data.stats.Sp_Defense) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } while (swapped);
}

void sort_by_speed(Node *pHead)
{
    int swapped = 0;
    Node *ptr1; 
    Node *lptr = NULL; 

    /* Checking for empty list */
    if (pHead == NULL) 
        return; 

    do
    {
        swapped = 0; 
        ptr1 = pHead; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->data.stats.Speed > ptr1->next->data.stats.Speed) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } while (swapped);
}
