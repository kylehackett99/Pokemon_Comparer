#ifndef HEADER
#define HEADER

//Structure for Stats
typedef struct{
    int Total, HP, Attack, Defense, Sp_Attack, Sp_Defense, Speed; 
}Stats;

//Structure for Pokemon
typedef struct{
    char *Name;
    char *Type_1;
    char *Type_2;
    Stats stats;
}Pokemon;


//Linked List
struct node;
typedef struct node Node;
struct node
{
	Node* next;
	Pokemon data;
};
struct list
{
	Node* head;
	Node* tail;
};

void head_insert(Node** pHead, Pokemon value);
void reverse_list(Node** head_ref);
void deleteList(struct node** head_ref);

void clear_keyboard_buffer(void);

void retrieve_some(Node** pHead, int num);
void retrieve_all(Node** pHead);
Pokemon readPokemon(char*s);
int sort_by_type(Node** pHead);
Node* pokemon_by_type(Node* pHead, char * type);

void compare_stats(Node **pHead);
void swap(Node *a,Node *b);
void sort_by_bst(Node *pHead);
void sort_by_hp(Node *pHead);
void sort_by_attack(Node *pHead);
void sort_by_defense(Node *pHead);
void sort_by_sp_attack(Node *pHead);
void sort_by_sp_defense(Node *pHead);
void sort_by_speed(Node *pHead);

void print_stat_visual(int value);
void print_divider(void);
int display_results(Node **pHead, int num, int place);
void print_ascii(void);


#endif