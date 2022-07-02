#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct el {
    char name[256];
    struct el * next;
}node;
 node *hash_table[100];
int size=10;
int convert (char name[]){
    int c,s=0;
    for (int i=0;i<strlen(name);i++){
        c=name[i];
        s=s+c;

    }
return s;
}
void insert(){
   int ascii,key;
   node * n,*n1;
   n=( node*)malloc(sizeof( node));
   printf("enter key: ");
   scanf("%s",n->name);
   n->next=NULL;
   ascii = convert(n->name);
   key=ascii%size;
   if(hash_table[key]==NULL){
   hash_table[key]=n;
   printf("inserted");

   }
 else{
     n1 = hash_table[key];
    while(n1->next!=NULL){
            n1 = n1->next;
    }
    n1->next=n ;

}}
int search(char name[]){
int ascii =convert(name);
int key =  ascii%size;
node *n;
for (n=hash_table[key];n!=NULL;n=n->next){
    if (strcmp(n->name,name)==0){
        return key;}
}
return -1;
}

void display_list( node *n){
 node* n1;
for (n1=n;n1!=NULL;n1=n1->next){
    printf("[%s]\n",n1->name);
}
}
void display(){
    for (int i=0;i<size;i++){
        printf("hash table [%d]\n",i);
        display_list(hash_table[i]);
    }
}
int del(char name[]){
int key,ascii;
ascii =convert(name);
key = ascii%size;
node *n,*n1;
if (strcmp(name,hash_table[key])==0){

    n=hash_table[key];
    hash_table[key]=hash_table[key]->next;
    free(n);
    return;
}
for (n=hash_table[key];n->next!=NULL;n=n->next){
    n1=n->next;
    if (strcmp(n1->name ,name)==0){
        n->next=n1->next;
        free(n);
        break;}

}
}
main()
{
    for(int i=0;i<size;i++){
            hash_table[i]==NULL;
    }
    char Nname[256];
    int opt,i=1;
    while(1)
    {
       printf("1.insert\t 2.print\t 3.Delete\t 4.Search ");
       scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                insert();
                break;
            case 2:
              display();
              break;
            case 3:

                printf("Enter a key to delete: ");
                scanf("%s",&Nname);
                del(Nname);
                break;
            case 4:
                 i;
                printf("Enter key to search: ");
                scanf("%s",&Nname);
                i = search(Nname);
                if (i==-1){printf("not found");}
                else{printf("found");}
                break;

        }
    }
}






