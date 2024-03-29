
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>
typedef struct list add;
struct list
{
    char name[40];
    char num[20];
    char gmail[40];
    add* next;
};
int i=1,size=0;
void Insert(add** head)
{
    add* temp=(add*)malloc(sizeof(add));
    printf("\n\n\n\t\tContact name : ");
    gets(temp->name);
    system("cls");
    printf("\n\n\n\t\tContact Name : ");
    gets(temp->name);
    system("cls");
    printf("\n\n\n\t\t\tMobile Number : ");
    gets(temp->num);
    system("cls");
    printf("\n\n\n\t\t\tGmail id : ");
    gets(temp->gmail);
    system("cls");
    temp->next = NULL;
    size++;
    if(size > 5)
    {
        system("cls");
        printf("\n\n\n\t\t\tPhone Memory is full!!!");
        printf("\n\t\tIf you want to add more contact,You have to delete some contact from your list...\n\n\n");
        return;
    }
    else
    {
        if(*head == NULL)
        {
            *head = temp;
            system("cls");
            printf("\n\n\t\t\t\t\tDone!!!\n\n");
            return;
        }
        else
        {
            add* p = *head;
            while(p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;
            system("cls");
            printf("\n\t\t\t\t\tDone!!!\n\n");
        }
        return;
    }
}
void Search(add*head)
{
    char ch[40];
    printf("\n\n\n\t\tContact name : ");
    gets(ch);
    system("cls");
    printf("\n\n\n\t\tContact name : ");
    gets(ch);
    system("cls");
    if(head == NULL)
    {
        system("cls");
        printf("\n\n\n\t\tNo Contact exists in this Phone Book List!!!\n\n");
        return;
    }
    else
    {
        add*p = head;
        while(p != NULL)
        {
            if(strcmp((p->name),ch) == 0)
            {
                system("cls");
                printf("\n\t\t\t%s",p->name);
                printf("\n\t\t-------------------------");
                printf("\n\t\tNumber : %s",p->num);
                printf("\n\t\tGmail ID : %s",p->gmail);
                return;
            }
            p = p->next;
        }
        system("cls");
        printf("\n\n\n\t\tThis Contact is not exists in the list! ");
    }
}
void Delete(add** head)
{
    char ch[40];
    printf("\n\t\tContact name : ");
    gets(ch);
    system("cls");
    printf("\n\t\tContact name : ");
    gets(ch);
    system("cls");
    if(*head == NULL)
    {
        system("cls");
        printf("\n\t\t\t\t\tNo Contact exists in this Phone Book List!\n\n");
        return;
    }
    else
    {
        if(strcmp(((*head)->name),ch) == 0)
        {
            add*p=*head;
            *head = (*head)->next;
            free(p);
            printf("\n\t\t\t\t\tDone!!!\n\n\n\n");
            return;
        }
        else
        {
            add*p = *head;
            while(p->next != NULL)
            {
                if(strcmp((p->next->name),ch) == 0)
                {
                    p->next = p->next->next;
                    size--;
                    return;
                }
                p = p->next;
            }
            system("cls");
            printf("\n\t\t\t\t\tInvalid Contact!!!\n\n");
        }
    }
}
void Display(add* head)
{
    if(head == NULL)
    {
        system("cls");
        printf("\n\n\n\t\tNo Contact exists in this Phone Book List!");
        return;
    }
    else
    {
        add*p = head;
        while(p != NULL)
        {
            printf("\n\t\t\tName     :%c%s",32,p->name);
            printf("\n\t\t\tNumber   : %s",p->num);
            printf("\n\t\t\tGmail ID : %s",p->gmail);
            p = p->next;
            printf("\n\n");
            i++;
        }
        i=1;
        return;
    }
}
void main()
{
    add* head=NULL;
    char c[40];
mainhome:
    system("cls");
    printf("\n\t\t|!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!|");
    printf("\n\t\t|                  !!!!!!!!!!!!!!!!!!!!!!!!!!!!                 |");
    printf("\n\t\t|!!!!!!!!!!!!!!!!!!! WELCOME TO OUR PHONE BOOK !!!!!!!!!!!!!!!!!|");
    printf("\n\t\t|!!!!!!!!!!!!!!!!!!! DEVELOPED BY FERDAUS HASSEN !!!!!!!!!!!!!!!|");
    printf("\n\t\t|                  !!!!!!!!!!!!!!!!!!!!!!!!!!!!                 |");
    printf("\n\t\t|!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!|\n\n\n");
    while(1)
    {
        printf("\n\n\t\t\t\t\t\tMenu");
        printf("\n\t\t\t-------------------------------------------------");
        printf("\n\t\t\t1)Create A Contact\t\t2)Remove A Contact");
        printf("\n\t\t\t3)Show The Contact List\t\t4)Find A Contact");
        printf("\n\t\t\t0)Quit\n\t\t\t");
        int ch;
        printf("Enter your choice : ");
        scanf("%d",&ch);
        if(ch == 0)
        {
            break;
        }
        else
        {
            switch(ch)
            {
            case 1 :
                system("cls");
                Insert(&head);
                break;
            case 2 :
                system("cls");
                Delete(&head);
                break;
            case 3 :
                system("cls");
                Display(head);
                break;
            case 4 :
                system("cls");
                Search(head);
                break;
            default :
                printf("\n\t\tInvalid Choice!Try again!!!");
                break;
            }
        }
    }
}
