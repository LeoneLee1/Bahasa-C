#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
    struct node *prev;    
};
typedef struct node n;
 
n* create_node(int);
void add_node();
void insert_at_first();
void insert_at_end();
void insert_at_position();
void delete_node_position();
void sort_list();
void update();
void search();
void display_from_beg();
void display_in_rev();
 
n *new, *ptr, *prev;
n *first = NULL, *last = NULL;
int number = 0;
 
void main()
{
    int ch;
 
    printf("\n LINKED LIST!\n\n");
    printf("[1]. Insert at Beginning\n");
 	printf("[2]. Insert at End\n");
 	printf("[3]. Insert at Position\n");
 	printf("[4]. Sort linked List\n");
 	printf("[5]. Delete Node at Position\n");
 	printf("[6]. Update Node Value\n");
 	printf("[7]. Search Element\n\n");
 	printf("[8]. Display List from Beginning\n");
 	printf("[9]. Display List from End\n\n");
 	printf("[10]. EXIT\n\n");
 	
 	
    while (1)
    {
 
        printf("\n[>] Enter Your Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1 :
            insert_at_first();
            break;
        case 2 :
            insert_at_end();
            break;
        case 3 :
            insert_at_position();
            break;
        case 4 :
            sort_list();
            break;
        case 5 :
            delete_node_position();
            break;
        case 6 :
            update();
            break;
        case 7 :
            search();
            break;
        case 8 :
            display_from_beg();
            break;
        case 9 :
            display_in_rev();
            break;
        case 10 :
            exit(0);
        case 11 :
            add_node();
            break;
        default:
            printf("\nINVALID CHOICE!!\n\n");
			printf("PLEASE TRY AGAIN!\n");
			printf("========================\n");                
        }
    }
}

n* create_node(int info)
{
    number++;
    new = (n *)malloc(sizeof(n));
    new->val = info;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

void add_node()
{
 
    int info;
 
    printf("\n [>] Enter the value you would like to add : ");
    scanf("%d", &info);
    new = create_node(info);
 
    if (first == last && first == NULL)
    {
 
        first = last = new;
        first->next = last->next = NULL;
        first->prev = last->prev = NULL;
    }
    else
    {
        last->next = new;
        new->prev = last;
        last = new;
        last->next = first;
        first->prev = last;
    }
}

void insert_at_first()
{
 
    int info;
 
    printf("\n [>] Enter the value to be inserted at first : ");
    scanf("%d",&info);
    new = create_node(info);
 
    if (first == last && first == NULL)
    {    
        printf("\n [>] Initially it is empty linked list later insertion is done [<]\n");
        first = last = new;
        first->next = last->next = NULL;
        first->prev = last->prev = NULL;
    }
    else
    {
        new->next = first;
        first->prev = new;
        first = new;
        first->prev = last;
        last->next = first;
        printf("\n [>] The value is inserted at begining [<]\n");
    }
}

void insert_at_end()
{
 
    int info;    
 
    printf("\n [>] Enter the value that has to be inserted at last : ");
    scanf("%d", &info);
    new = create_node(info);
 
    if (first == last && first == NULL)
    {
        printf("\n [>] initially the list is empty and now new node is inserted but at first [<]\n");
        first = last = new;
        first->next = last->next = NULL;    
        first->prev = last->prev = NULL;
    }
    else
    {
        last->next = new;
        new->prev = last;
        last = new;
        first->prev = last;
        last->next = first;
    }
}

void insert_at_position()
{    
    int info, pos, len = 0, i;
    n *prevnode;
 
    printf("\n [>] Enter the value that you would like to insert : ");
    scanf("%d", &info);
    printf("\n [>] Enter the position where you have to enter : ");
    scanf("%d", &pos);
    new = create_node(info);
 
    if (first == last && first == NULL)
    {
        if (pos == 1)
        {
            first = last = new;
            first->next = last->next = NULL;    
            first->prev = last->prev = NULL;
        }
        else
            printf("\n[>] Empty linked list you cant insert at that particular position [<]\n");
    }
    else
    {
        if (number < pos)
            printf("\n[>] Node cant be inserted as position is exceeding the linkedlist length [<]\n");
 
        else
        {
            for (ptr = first, i = 1;i <= number;i++)
            {
                prevnode = ptr;
                ptr = ptr->next;
                if (i == pos-1)
                {
                    prevnode->next = new;
                    new->prev = prevnode;
                    new->next = ptr;
                    ptr->prev = new;
                    printf("\n[>] Inserted at position %d succesfully [<]\n", pos);
                    break;
                }
            }
        }
    }
}

void sort_list()
{    
    n *temp;
    int tempval, i, j;
 
    if (first == last && first == NULL)
        printf("\n[>] Linked list is empty no elements to sort [<]\n");
    else
    {
        for (ptr = first,i = 0;i < number;ptr = ptr->next,i++)
        {
            for (temp = ptr->next,j=i;j<number;j++)
            {
                if (ptr->val > temp->val)
                {
                    tempval = ptr->val;
                    ptr->val = temp->val;
                    temp->val = tempval;
                }
            }
        }
        for (ptr = first, i = 0;i < number;ptr = ptr->next,i++)
            printf("\n %d", ptr->val);
    }
}

void delete_node_position()
{    
    int pos, count = 0, i;
    n *temp, *prevnode;
 
    printf("\n [>] Enter the position which u wanted to delete : ");
    scanf("%d", &pos);
 
    if (first == last && first == NULL)
        printf("\n[>] Empty linked list you cant delete [<]\n");
 
    else
    {
        if (number < pos)
            printf("\n[>] Node cant be deleted at position as it is exceeding the linked list length [<]\n");
 
        else
        {
            for (ptr = first,i = 1;i <= number;i++)
            {
                prevnode = ptr;
                ptr = ptr->next;
                if (pos == 1)
                {    
                    number--;
                    last->next = prevnode->next;
                    ptr->prev = prevnode->prev;
                    first = ptr;
                    printf("\n %d is deleted", prevnode->val);
                    free(prevnode);
                    break;        
                }
                else if (i == pos - 1)
                {    
                    number--;
                    prevnode->next = ptr->next;
                    ptr->next->prev = prevnode;
                    printf("\n %d is deleted", ptr->val);
                    free(ptr);
                    break;
                }
            }
        }
    }
}

void update()
{    
    int oldval, newval, i, f = 0;
    printf("\n [>] Enter the value old value : ");
    scanf("%d", &oldval);
    printf("\n [>] Enter the value new value : ");
    scanf("%d", &newval);
    if (first == last && first == NULL)
        printf("\n[>] List is empty no elemnts for updation [<]\n");
    else
    {    
        for (ptr = first, i = 0;i < number;ptr = ptr->next,i++)
        {    
            if (ptr->val == oldval)
            {    
                ptr->val = newval;
                printf("[!] Value is updated to %d [!]\n", ptr->val);
                f = 1;
            }    
        }
        if (f == 0)
            printf("\n[>] No such old value to be get updated [<]\n");
    }
}

void search()
{
    int count = 0, key, i, f = 0;
 
    printf("\n [>] Enter the value to be searched : ");
    scanf("%d", &key);
 
    if (first == last && first == NULL)
        printf("\n[>] List is empty no elemnets in list to search [<]\n");
    else
    {
        for (ptr = first,i = 0;i < number;i++,ptr = ptr->next)
        {
            count++;
            if (ptr->val == key)
            {
                printf("\n[!] The value is found at position at %d [!]\n", count);
                f = 1;
            }    
        }
        if (f == 0)
            printf("\n[>] The value is not found in linked list [<]\n");
    }
}

void display_from_beg()
{
    int i;
    if (first == last && first == NULL)
        printf("\n[>] List is empty no elemnts to print [<]\n");
    else
    {    
        printf("\n[!] %d number of nodes are there [!]\n", number);
        for (ptr = first, i = 0;i < number;i++,ptr = ptr->next)
            printf("\n %d", ptr->val);
    }
}

void display_in_rev()
{
    int i;        
    if (first == last && first == NULL)
        printf("\n[>] List is empty there are no elments [<]\n");
    else
    {
        for (ptr = last, i = 0;i < number;i++,ptr = ptr->prev)
        {
            printf("\n %d", ptr->val);
        }
    }
}
