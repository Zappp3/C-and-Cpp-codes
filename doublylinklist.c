#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
    int rollno;
    char name[10],branch[5];
    int sem,score;
    struct node *llink;
    struct node *rlink;
};
typedef struct node* NODE;
NODE first = NULL;
int count=0;
NODE insertend();
NODE insertfront();
NODE deleteend();
NODE deletefront();
void display();


void main()

{

    int ch,i,n;

    while(1)

    {

        printf("\n1:DisplayStatus");

         printf("\n2:InsertAtEnd");

         printf("\n3:DeleteAtEnd");

         printf("\n4:InsertAtFront");

         printf("\n5:DeleteAtFront");

         printf("\n6:Exit \n");

         printf("\nPlease enter your choice: ");

        scanf("%d",&ch);

        switch(ch)

        {

        case 1:  display();
            break;
        case 2: first = insertend();
            break;
        case 3: first = deleteend();
            break;
        case 4: first = insertfront();
            break;
        case 5: first = deletefront();
            break;
        case 6 : exit(0);
        default: printf("\nPlease Enter the valid choice");
        }

    }

} 
NODE create(){
    NODE enode;
    enode=(NODE)malloc(sizeof(struct node));
    if(enode==NULL){
        printf("running out of memory");
        exit(0);
    }
    printf("\nenter the rollno,name,branch, sem,score: \n");
    scanf("%d %s %s %d %d",&enode->rollno, enode->name,enode->branch,&enode->sem, &enode->score);
    enode->llink=NULL;
    enode->rlink=NULL;
    count++;
    return enode;
}
NODE insertfront()

{
    NODE temp;
    temp = create();
    if(first == NULL)
    {
        return temp;
    }
    temp->rlink = first;
    first->llink = temp;
    return temp;

}
void display()

{
    NODE cur;
    int nodeno=1;
    cur = first;
    if(cur == NULL){
        printf("\nNo Contents to display in DLL");
    }
    while(cur!=NULL)
    {
        printf("\nENode:%d||rollno:%d|Name:%s|branch:%s|sem:%d|score:%d", nodeno, cur->rollno, cur->name,cur->branch, cur->sem, cur->score);
        cur = cur->rlink;
        nodeno++;
    }
    printf("\nNo of students is %d",count);
}
NODE insertend()
{
    NODE cur, temp;
    temp = create();
    if(first == NULL)
    {
        return temp;
    }
    cur= first;
    while(cur->rlink!=NULL)
    {
        cur = cur->rlink;
    }
    cur->rlink = temp;
    temp->llink = cur;
    return first;
}
NODE deletefront()
{
    NODE temp;
    if(first == NULL)
    {
        printf("\nDoubly Linked List is empty");
        return NULL;
    }
    if(first->rlink== NULL)
    {
        printf("\nThe student node with the name:%s is deleted", first->name);
        free(first);
        count--;
        return NULL;
    }
    temp = first;
    first = first->rlink;
    temp->rlink = NULL;
    first->llink = NULL;
    printf("\nThe student node with the name:%s is deleted",temp->name);
    free(temp);
    count--;
    return first;
}
NODE deleteend()
{
    NODE prev,cur;
    if(first == NULL)
    {
        printf("\nDoubly Linked List is empty");
        return NULL;
    }
    if(first->rlink == NULL)
    {
        printf("\nThe student node with the name:%s is deleted",first->name);
        free(first);
        count--;
        return NULL;
    }
    prev=NULL;
    cur=first;
    while(cur->rlink!=NULL)
    {
        prev=cur;
        cur = cur->rlink;
    }
    cur->llink = NULL;
    printf("\nThe student node with the name :%s is deleted",cur->name);
    free(cur);
    prev->rlink = NULL;
    count--;
    return first;
}