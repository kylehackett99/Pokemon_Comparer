#include <stdio.h>
#include <stdlib.h>
#include "header.h"

//Constants
char stats[7][20] = {"Base Stat Total", "HP", "Attack", "Defense", "Special Attack", "Special Defense",
    "Speed"}; 
const int LONGEST_NAME_LENGTH = 20;
const int NUM_POKEMON = 1000;

int main(int argc, char * argv[]){

    Node *head = NULL;
    int num, lead = 0, state = 0;
    int some_pkmn = 0, some_num_results = 0;

    print_ascii();    
    //Gets Number of Comparisons from user
    printf("How Many Pokemon would you like to compare? (Enter 0 to Compare All Pokemon)\n");
    scanf("%d", &num);
    clear_keyboard_buffer();
    while(num < 0 || num > NUM_POKEMON)
    {
       printf("Invalid Input, must lie between 0 and %d\n", NUM_POKEMON);
       scanf("%d", &num);
       clear_keyboard_buffer();
    }
    if(num == 0){num=NUM_POKEMON;}
    
    //Retrieve Pokemon from Pokedex
    if(num != NUM_POKEMON)
    {
        //Get Pokemon Names
        printf("< Enter Pokemon names, each separated by a space >\n");
        //Find and Add Pokemon within String array to linked list
        retrieve_some(&head, num);
        some_num_results = num;
        some_pkmn = 1;

    }
    else
    {
        //Adds all Pokemon to Linked List
        retrieve_all(&head);
    }


    //Asks users if they want to sort by type if theres a large num
    if(num > 15)
    {
        printf("\n \n\nWould You Like to sort by Type?\n1) Yes\n2) No\n");
        num = sort_by_type(&head);
        print_divider();
        if(num == 1)
        {   
            //Ask again to sort list by type again
            printf("\nWould you Like to sort by another Type?\n1) Yes\n2) No\n");
            sort_by_type(&head);
            print_divider();
        }
    }


    //Ask What Stat should be compared
    printf("\n\n\nWhich Stat would you like to sort by?\n");
    print_divider();
    for(int i = 0; i < 7; i++)
    {
        printf("%5d)%-15s ",i+1, stats[i]);
        if(i % 2 != 0)
        {
            printf("\n");
        }
    }
    printf("\n");
    print_divider();
    printf("Please enter the number of the corresponding type\n");
    compare_stats(&head);
    reverse_list(&head);

    //Change to 1 depending on if people think seeing them all at once is better
    if(some_pkmn == 12)
    {
        printf("\n\n\n\nFinal Results!\n");
        state = display_results(&head, some_num_results, lead);
    }
    else
    {
        //Display Pokemon with best stat + however many more are requested
        printf("\n\n\n\nFinal Results!\n");
        num = 3;
        state = display_results(&head, num, lead);
        lead = 3;
        while(num != 0 && state != 1)
        {
           printf("Enter how more results would you like to see:\n");
           printf("        (-1 will Print all remaining pokemon and 0 will end the session)\n");
           scanf("%d", &num);
           clear_keyboard_buffer();
           if(num < 0){num = 2000;}
           printf("\n");
           state = display_results(&head, num, lead);
           lead = lead + num;
        }
    }

    deleteList(&head); 
    printf("Thank you for coming! Come Again!\n\n");
    return 0;
}