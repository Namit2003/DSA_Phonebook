#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    char number[40];
    char name[40];
    struct Node * next ;
    struct Node * prev;
};
struct Node *head=NULL;
void linkedListTraversal(struct Node *ptr)
{
    int i=1;
    if(ptr==NULL)
        printf("The PhoneBook is Empty !!!");
    else
    {
    while (ptr!= NULL)
    {
        printf("Name = %s\n", ptr->name);
        printf("Number = %s\n", ptr->number);
        ptr = ptr->next;
        i++;
    }
    //printf("Element %d = %s\n",i, ptr->data);
    }
}
 struct Node * AddContact(struct Node *head,char x[],char y[]){
            struct Node *temp= (struct Node *) malloc(sizeof(struct Node));
            //char x[40];
            strcpy(temp->name,x);
            strcpy(temp->number,y);
            if(head==NULL)
            {
                head=temp;
                head->next=NULL;
                head->prev=NULL;
            }
            else
            {
                struct Node *ptr=head;
                while(ptr->next!=NULL)
                {
                    ptr=ptr->next;
                }
               ptr->next=temp;
               temp->prev=ptr;
               temp->next=NULL;
            }
            printf("Contact Inserted \n");
            return head;
 }
 void Sort(struct Node *head)
 {
     struct Node *i= (struct Node *) malloc(sizeof(struct Node));
     struct Node *j= (struct Node *) malloc(sizeof(struct Node));
     int temp;
        char n[10];
        for(i=head;i->next!=NULL;i=i->next)
        {
            for(j=i->next;j!=NULL;j=j->next)
            {
                temp=strcmpi(i->name,j->name);
                if(temp>0)
                {
                   strcpy(n,i->name);
                   strcpy(i->name,j->name);
                   strcpy(j->name,n);
                   strcpy(n,i->number);
                   strcpy(i->number,j->number);
                   strcpy(j->number,n);
                }
            }
        }
 }
 struct Node * EditContact(struct Node *head,char value[])
 {
        struct Node *p = head;
        struct Node *q = head->next;
     int a;
     char x[40],y[40];
     printf("What do you want to Edit ? \n");
     printf("1)Contact Name \n2)Contact Number \n");
     printf("Select Any : ");
     scanf("%d",&a);
     switch(a)
     {
 case 1:
        printf("Enter the new name : ");
        scanf("%s",&x);
        if(strcmpi(p->name,value)==0 && p->next==NULL)
        {
            strcpy(p->name,x);
            printf("Contact Name Updated\n");
        }
    else if(strcmpi(p->name,value)==0)
    {
        strcpy(p->name,x);
            printf("Contact Name Updated \n");
    }
    else
    {
    while(strcmpi(q->name,value)!=0 && q->next!= NULL)
    {
        p = p->next;
        q = q->next;
    }

    if(strcmpi(q->name,value)==0){
        strcpy(q->name,x);
            printf("Contact Name Updated \n");
    }
    else
        printf("Contact name is not present in the Phonebook !!!\n");
    }
    break;
 case 2:
        printf("Enter the new number : ");
        scanf("%s",&y);
            while(strlen(y)!=10)
            {
            printf("ENTER VALID NUMBER  :");
            scanf("%s",&y);
            }
        if(strcmpi(p->name,value)==0 && p->next==NULL)
        {
            strcpy(p->number,y);
            printf("Contact number updated\n");
        }
    else if(strcmpi(p->name,value)==0)
    {
            strcpy(p->number,y);
            printf("Contact Number Updated \n");
    }
    else
    {
    while(strcmpi(q->name,value)!=0 && q->next!= NULL)
    {
        p = p->next;
        q = q->next;
    }

    if(strcmpi(q->name,value)==0){
            strcpy(q->number,y);
            printf("Contact Number Updated \n");
    }
    else
        printf("Contact name is not present in the Phonebook !!!\n");
    }
    break;
     }

    return head;
 }
 struct Node * RemoveContact(struct Node *head,char value[])
 {
     if(head==NULL)
     {
         printf("The PhoneBook is Empty !!!");
     }
     else{
        struct Node *p = head;
        struct Node *q = head->next;
        struct Node *s = head->prev;
        if(strcmpi(p->name,value)==0 && p->next==NULL)
        {
            head=NULL;
            free(p);
            printf("%s Contact deleted \n",value);
        }
        else if(strcmpi(p->name,value)!=0 && p->next==NULL)
        {
            printf("Contact is not present in the Phonebook !!!\n");
        }
    else if(strcmpi(p->name,value)==0)
    {
        p->next=head->next;
        head->next->prev=NULL;
        //p=NULL;
        free(head);
        head=p->next;
        printf("%s Contact deleted \n",value);
    }
    else if(strcmpi(q->name,value)==0 && q->next== NULL)
    {
        p->next=NULL;
        p->prev=NULL;
        free(q);
        printf("%s Contact deleted \n",value);
    }
    else
    {
        while(strcmpi(q->name,value)!=0 && q->next!= NULL)
        {
        p = p->next;
        q = q->next;
        }
    if(strcmpi(q->name,value)==0){
        p->next = q->next;
        q->next->prev=p;
        free(q);
        printf("%s Contact deleted \n",value);
    }
        else
        printf("Contact is not present in the Phonebook !!!\n");
    }
     }
    return head;
 }
 struct Node * RemoveSameContactName(struct Node *head)
 {
     int flag=1;
     if(head==NULL)
     {
         printf("The PhoneBook is Empty !!!");
     }
     else{
        struct Node *p = head;
        while (p != NULL && p->next != NULL)
        {
        struct Node *q = p;
        //flag=0;
        while (q->next != NULL)
        {
            if (strcmpi(p->name,q->next->name)==0)
            {
                struct Node *dup = q->next;
                q->next = q->next->next;
                free(dup);
                flag=0;
            }
            else
            {
                q = q->next;
            }
        }
        p = p->next;
        }
     }
    if(flag==1)
        printf("There are no duplicate Contact Names ");
    else
        printf("Contacts with the same name Deleted ");
    return head;
 }
 struct Node * RemoveSameContactNumber(struct Node *head)
 {
     int flag=1;
     if(head==NULL)
     {
         printf("The PhoneBook is Empty !!!");
     }
     else{
        struct Node *p = head;
        while (p != NULL && p->next != NULL)
        {
        struct Node *q = p;
        //flag=0;
        while (q->next != NULL)
        {
            if (strcmpi(p->number,q->next->number)==0)
            {
                struct Node *dup = q->next;
                q->next = q->next->next;
                free(dup);
                flag=0;
            }
            else
            {
                q = q->next;
                flag=1;
            }
        }
        p = p->next;
        }
     }
    if(flag==1)
        printf("There are no duplicate Contact Numbers ");
    else
        printf("Contacts with the same number Deleted ");
    return head;
 }
struct Node * SearchNumber(struct Node *head,char num[])
{
    struct Node *p = head;
    int flag=0,n=strlen(num);
    char ch[n];
    while(p!=NULL)
    {
        memcpy(ch,p->number,n);
        if(strcmpi(num,ch)==0 || strcmpi(num,p->number)==0)
            {
                printf("NUMBER FOUND\n");
                printf("CONTACT DETAILS ARE BELOW:\n");
        	printf("\n\nNAME  :: %s",p->name);
			printf("\nNUMBER :: +91-%s \n\n",p->number);
			flag=1;
            //break;
            }
            strcpy(ch,"");
            p=p->next;
    }
    if(flag==0)
        printf("The Searched Number Is not in the Phonebook");
    return head;
}
struct Node * SearchName(struct Node *head,char name[])
{
    struct Node *p = head;
    int flag=0,n=strlen(name);
     char ch[n];
    while(p!=NULL)
    {
        memcpy(ch,p->name,n);
        if(strcmpi(name,ch)==0 || strcmpi(name,p->name)==0)
            {
                printf("NAME FOUND\n");
                printf("CONTACT DETAILS ARE BELOW:\n");
        	printf("\n\nNAME  :: %s",p->name);
			printf("\nNUMBER :: +91-%s \n\n",p->number);
			flag=1;
            //break;
            }
            strcpy(ch,"");
            p=p->next;
    }
    if(flag==0)
        printf("The Searched Name Is not in the Phonebook");
    return head;
}
int main()
{
    system("COLOR 0B");
    int n,t1,t2;
    char x[40],y[40],z[40],w[40],q[40];
    printf("****************** PHONE BOOK ********************");
    printf("\n\nEnter YOUR NAME : \n");
    gets(x);
    printf("\n\n   WELCOME ");
    puts(x);
    printf("\n\n\nLET'S CREATE OUR PHONEBOOK  ");
    do{
    printf("\n\n\n\n1) DISPLAY YOUR PHONE BOOK\n2) INSERT NEW CONTACT\n3) UPDATE DETAILS ON EXISTING CONTACT\n4) DELETE CONTACT\n5) DELETE SAME NAME IN PHONEBOOK\n6) DELETE SAME NUMBERS IN PHONEBOOK\n7) SEARCH\n8) Exit \n");
    printf("Enter any choice : ");
    scanf("%d",&n);
    switch(n)
    {
    case 2:
       // int x;
       printf("Enter the Contact name you want to insert : ");
       scanf("%s",&y);

       printf("Enter the Contact number you want to insert : ");
       scanf("%s",&z);
        while(strlen(z)!=10)
        {
        printf("ENTER VALID NUMBER  :");
        scanf("%s",&z);
        }
        head=AddContact(head,y,z);
        Sort(head);
        break;
    case 3:
       // int x;
        printf("Enter the Contact you want to Edit : ");
        scanf("%s",&y);
        head=EditContact(head,y);
        break;
    case 4:
        printf("Enter the Contact name you want to Delete : ");
        scanf("%s",&y);
        head=RemoveContact(head,y);
        break;
    case 6:
        head=RemoveSameContactNumber(head);
        break;
   case 5:
       head=RemoveSameContactName(head);
        break;
    case 7:
           printf("1)Search by Number \n2)Search by Name \n");
           printf("Enter any : ");
           scanf("%d",&t1);
           switch(t1)
           {
                case 1:
                    printf("Enter the Number : ");
                    scanf("%s",&z);
                    head=SearchNumber(head,z);
                    break;
                case 2:
                    printf("Enter the Name : ");
                    scanf("%s",&w);
                    head=SearchName(head,w);
                    break;
                default:
                    printf("Enter a valid Number !!!");
           }
        break;
    case 1:
        linkedListTraversal(head);
        break;
    case 8:
        break;
    default:
        printf("Enter a valid number !!! \n");
        break;

    }
    }while(n!=8);
    printf("**************EXIT****************");
}
