#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const int MAX_POKEMON = 1000;

//Linked List Functions
void head_insert(Node** pHead, Pokemon value)
{
	Node* temp;
	temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}

	temp->data = value;
	temp->next = *pHead;
	
	*pHead = temp;
}

void reverse_list(Node** head_ref) 
{ 
    Node* prev = NULL; 
    Node* current = *head_ref; 
    Node* next = NULL; 
    while (current != NULL) { 
        // Store next 
        next = current->next; 
  
        // Reverse current node's pointer 
        current->next = prev; 
  
        // Move pointers one position ahead. 
        prev = current; 
        current = next; 
    } 
    *head_ref = prev; 
} 

void deleteList(struct node** head_ref)
{  
  struct node* current = *head_ref;
  struct node* next;
  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
  *head_ref = NULL;
}

void clear_keyboard_buffer(void)
{
	char c;

	scanf("%c", &c);

	while (c != '\n')
	{
		scanf("%c", &c);
	}
}

//Retrieval Functions
void retrieve_some(Node** pHead, int num)
{
    FILE *fp = fopen("pokedex.csv", "r");
    if(fp == NULL){exit(1);}

    
    char input[num][30];
    char c;
    int num_pkmn;
    char line[MAX_POKEMON];
    Pokemon pkmn;

    for(int i = 0; i < num; i++)
    {
       scanf("%s", input[i]);
       //Add protections for case sensitivity

    }

    //Gets number of pokemon
    c = fgetc(fp);
    while(c != EOF)
    {
        if(c == '\n' || c == '\0'){num_pkmn++;}
        c = fgetc(fp);
    }
    num_pkmn++;
    rewind(fp);
    
    //searches for pokemon in list
    fgets(line,MAX_POKEMON,fp);
    for(int i = 0; i < num_pkmn - 1;i++)
    {
        fgets(line,MAX_POKEMON,fp);
        pkmn = readPokemon(line);

        for(int j = 0; j < num; j++)
        {
            //if names are the same, adds it to list
            if(!strcmp(input[j], pkmn.Name))
            {
                head_insert(pHead, pkmn);
            }
        }

    }


    fclose(fp);
}

void retrieve_all(Node** pHead)
{
    FILE *fp = fopen("pokedex.csv", "r");
    if(fp == NULL){exit(1);}

    char line[MAX_POKEMON];
    char c;
    int num;
    Pokemon pkmn;

    //Gets number of pokemon
    c = fgetc(fp);
    while(c != EOF)
    {
        if(c == '\n' || c == '\0'){num++;}
        c = fgetc(fp);
    }
    num++;
    rewind(fp);

    fgets(line,MAX_POKEMON,fp);
    for(int i = 0; i < num - 1;i++)
    {
        fgets(line,MAX_POKEMON,fp);
        pkmn = readPokemon(line);
        head_insert(pHead, pkmn);
    }

    fclose(fp);
}
    //Reads Info from CSV
Pokemon readPokemon(char*s)
{
    int j = 0 , i = 0;

    Pokemon *pkmn = malloc(sizeof(Pokemon));
    char *name = malloc(sizeof(char*) * 20);
    char *type1 = malloc(sizeof(char*) * 20);
    char *type2 = malloc(sizeof(char*) * 20);
    char *Total = malloc(sizeof(char*) * 6), 
     *HP = malloc(sizeof(char*) * 6), *Speed = malloc(sizeof(char*) * 6),
     *Attack = malloc(sizeof(char*) * 6), *Defense = malloc(sizeof(char*) * 6),
     *Sp_Attack = malloc(sizeof(char*) * 6), *Sp_Defense = malloc(sizeof(char*) * 6);

    // <<<Gets Name>>>
    while(s[i] != ',')
    {
        name[j] = s[i];
        i++;j++;
    }
    pkmn->Name = name;
    j = 0; i++;

    // <<<Gets Type1>>>
    while(s[i] != ',')
    {
        type1[j] = s[i];
        i++;j++;
    }
    pkmn->Type_1 = type1;
    j = 0; i++;

    // <<<Gets Type2>>>
    while(s[i] != ',')
    {
        type2[j] = s[i];
        i++;j++;
    }
    pkmn->Type_2 = type2;
    j = 0; i++;

    // <<<Gets Stats>>>i

    //total
    while(s[i] != ',')
    {
       Total[j] = s[i];
       i++;j++;
    }
    pkmn->stats.Total = atoi(Total);
    j=0;i++;

    //hp
    while(s[i] != ',')
    {
        HP[j] = s[i];
        i++;j++;
        
    }
    pkmn->stats.HP = atoi(HP);
    j=0;i++;

    //attack
    while(s[i] != ',')
    {
        Attack[j] = s[i];
        i++;j++;
    }
    pkmn->stats.Attack = atoi(Attack);
    j=0;i++;

    //defense
    while(s[i] != ',')
    {
        Defense[j] = s[i];
        i++;j++;
    }
    pkmn->stats.Defense = atoi(Defense);
    j=0;i++;

    //spattack
    while(s[i] != ',')
    {
        Sp_Attack[j] = s[i];
        i++;j++;
    }
    pkmn->stats.Sp_Attack = atoi(Sp_Attack);
    j=0;i++;

    //spdefense
    while(s[i] != ',')
    {
        Sp_Defense[j] = s[i];
        i++;j++;
    }
    pkmn->stats.Sp_Defense = atoi(Sp_Defense);
    j=0;i++;

    //speed
    while(s[i] != '\0')
    {
        Speed[j] = s[i];
        i++;j++;
    }
    pkmn->stats.Speed = atoi(Speed);
    j=0;i++;


    return *pkmn;
}

//Takes User Input and executes Type Sort
int sort_by_type(Node **pHead)
{
    //Ask if list should be narrowed down by type
    int choice = 0;
    char types [18][10] = {"Normal", "Fighting", "Flying","Poison",
    "Ground", "Rock", "Bug", "Ghost", "Steel", "Fire", "Water",
    "Grass", "Electric", "Psychic", "Ice", "Dragon", "Dark", "Fairy"};
    
    //printf("Would You Like to sort by Type?\n1) Yes\n2) No\n");
    printf("Enter the number of the corresponding choice:\n");
    scanf("%d", &choice);
    clear_keyboard_buffer();
    while(choice != 1 && choice != 2)
    {
        printf("Invalid Input. 1) Yes  2) No\n");
        scanf("%d", &choice);
        clear_keyboard_buffer();
    }

    if(choice == 1)
    {
        printf("What Type would you like to sort by?\n");
        print_divider();
        for(int i = 0; i < 18; i++)
        {
            printf("%5d)",i+1);
            printf("%-10s", types[i]);
            if(i % 2 == 1){printf("\n");}
        }
        print_divider();
        printf("\nEnter the number of the corresponding Type\n");
        scanf("%d", &choice);
        clear_keyboard_buffer();
        while(choice > 18 || choice < 1)
        {
            printf("Invalid Selection. Enter a type between 1 and 18\n");
            scanf("%d", &choice);
            clear_keyboard_buffer();
        }

        switch(choice)
        {
            case 1:
                *pHead = pokemon_by_type(*pHead, "Normal");
                break;
            case 2:
                *pHead = pokemon_by_type( *pHead, "Fighting");
                break;
            case 3:
                *pHead = pokemon_by_type( *pHead, "Flying");
                break;
            case 4:
                *pHead = pokemon_by_type( *pHead, "Poison");
                break;
            case 5:
                *pHead = pokemon_by_type( *pHead, "Ground");
                break;
            case 6:
                *pHead = pokemon_by_type( *pHead, "Rock");
                break;
            case 7:
                *pHead = pokemon_by_type( *pHead, "Bug");
                break;
            case 8:
                *pHead = pokemon_by_type( *pHead, "Ghost");
                break;
            case 9:
                *pHead = pokemon_by_type( *pHead, "Steel");
                break;
            case 10:
                *pHead = pokemon_by_type( *pHead, "Fire");
                break;
            case 11:
                *pHead = pokemon_by_type( *pHead, "Grass");
                break;
            case 12:
                *pHead = pokemon_by_type( *pHead, "Water");
                break;
            case 13:
                *pHead = pokemon_by_type( *pHead, "Electric");
                break;
            case 14:
                *pHead = pokemon_by_type( *pHead, "Psychic");
                break;
            case 15:
                *pHead = pokemon_by_type( *pHead, "Ice");
                break;
            case 16:
                *pHead = pokemon_by_type( *pHead, "Dragon");
                break;
            case 17:
                *pHead = pokemon_by_type( *pHead, "Dark");
                break;
            case 18:
                *pHead = pokemon_by_type( *pHead, "Fairy");
                break;
            default:
                break;
        }
    }
    else
    {
        return 0;
    }
    
    return 1;
}

//Creates new List of Pokemon with the selected Type
Node* pokemon_by_type(Node* pHead, char* type)
{
    Node* newList = NULL;
    int i = 0;

    //Creates new list with only given type 
    Node *temp = NULL;
    temp = pHead;
    while(temp !=NULL)
    {
        if( !strcmp(temp->data.Type_1, type) || !strcmp(temp->data.Type_2,type) )
        {
            head_insert(&newList, temp->data);
            i++;
        }
        temp=temp->next;
    }

    printf("\n\n<------ %d Pokemon Found ----->\n\n", i );
    return newList;
}


void compare_stats(Node **pHead)
{
    int choice = 0;
    scanf("%d",&choice);
    clear_keyboard_buffer();
    while(choice < 1 || choice > 7)
    {
        printf("Invalid Selection. Enter a stat between 1 and 7\n");
        scanf("%d",&choice);
        clear_keyboard_buffer();
    }

    switch(choice)
    {
        case 1:
            sort_by_bst(*pHead);
            break;
        case 2:
            sort_by_hp(*pHead);
            break;
        case 3:
            sort_by_attack(*pHead);
            break;
        case 4:
            sort_by_defense(*pHead);
            break;
        case 5:
            sort_by_sp_attack(*pHead);
            break;
        case 6:
            sort_by_sp_defense(*pHead);
            break;
        case 7:
            sort_by_speed(*pHead);
            break;
        default:
        break;
    };
}


//Display
void print_ascii(void)
{
    FILE *fp = fopen("ascii_art.txt", "r");
    char c;
    while(c != EOF )
    {
        c = fgetc(fp);
        if(c == EOF)break;
        printf("%c",c);
    }
    printf("\n");
    printf("\n");

    fclose(fp);
}

void print_stat_visual(int value)
{
    value = value / 10;

    printf(" |");
    for(int i = 0; i < value; i++)
    {
        printf("*");
    }

    printf("\n");
}

int display_results(Node ** pHead, int num, int place)
{
    char stats[7][20] = {"Base Stat Total", "HP", "Attack", "Defense", "Special Attack", "Special Defense",
    "Speed"}; 
    
    Node * current = *pHead;
    int j = 0, i = place;

    for(int k = 0; k < place; k++)current = current->next;;

    if(current == NULL)return 1;

    while (current != NULL && j != num && current != NULL){
        printf("%22d\n", i+1);
        print_divider();
        printf("     <  %s  >\n", current->data.Name);
        printf("Type:%s",current->data.Type_1);
        if(isalpha(current->data.Type_2[0])){printf("/%s\n", current->data.Type_2);}
        else{printf("\n");}
        printf("%-15s %3d\n",stats[0], current->data.stats.Total);
        printf("%-15s %3d",stats[1], current->data.stats.HP);
        print_stat_visual(current->data.stats.HP);
        printf("%-15s %3d",stats[2], current->data.stats.Attack);
        print_stat_visual(current->data.stats.Attack);
        printf("%-15s %3d",stats[3], current->data.stats.Defense);
        print_stat_visual(current->data.stats.Defense);
        printf("%-15s %3d",stats[4], current->data.stats.Sp_Attack);
        print_stat_visual(current->data.stats.Sp_Attack);
        printf("%-15s %3d", stats[5], current->data.stats.Sp_Defense);
        print_stat_visual(current->data.stats.Sp_Defense);
        printf("%-15s %3d",stats[6], current->data.stats.Speed);
        print_stat_visual(current->data.stats.Speed);
        print_divider();
        printf("\n\n");
        i++;j++;
        current = current->next;
        if(current == NULL)
        {
            return 1;
        }
    }

    return 0;
}

void print_divider(void)
{
    for(int i = 0; i < 50; i++)
    {
        printf("-");
    }
    printf("\n");
}
