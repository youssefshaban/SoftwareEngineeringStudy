#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// todo : add error handling , sound for unexpexted inputs , add validator for all inputs , remove at location not implemented yet
struct st {
    int id;
    char name [10];
    int subject ,grade[3];
};
//---------------------------
struct node {
    struct st data;
    struct node* next;
    struct node* prev;
};
//--------------------------
struct node* head;
struct node* tail;
//---------- Global Val
struct node* create ();
void insert (int location);
struct st getDataFromUser();
void deleteAll();
void print();
void searchById();
void searchByName();
void addNode ();
//---------------- define Functions
int main (){
    int opration;
    int location=-1;
    int flag = 0;
    do{
        // todo: change printf to list (to be more friendly to the users)
        printf(" to add new student enter 1 \n to add student in location enter 2 \n to search by id 3 \n to search by name 4 \n and 5 for end program and print \n or 6 to delete all records and end the program \n");
        scanf("%d",&opration);
        if(opration==1){
            insert(location);
        }else if (opration == 2){
            printf("\n enter the location : ");
            scanf("%d",&location);
            insert(location-1);
        }else if(opration==3){
            searchById();
        }else if(opration==4){
            searchByName();
        }else if (opration==5){
            print();
            flag=1;
        }else if(opration==6){
            deleteAll();
            flag=1;
        }

    }while(flag == 0);

    print();

return 0;
}
void insert(int location){
    int loopHelper = 0;
    struct node* newNode;
    struct node* temp;
    if(location==-1){
        if(!head){
            addNode();
        }else {
           newNode= create();
           tail->next=newNode;
           tail=newNode;
        }
    }// todo : recheck the logic for location 0 and other locations (the first item removed)
    else if(location==0){
        addNode();
    }else{
        temp = head;
        while(loopHelper>=location){
                if(temp->next!=NULL){
                    temp=temp->next;
                }
        }
       newNode = create();
       if(temp->next){
            newNode->next=temp->next;
       }else {
            tail=newNode;
       }
       temp->next=newNode;
    }
}
void addNode(){
    struct node* newNode = create();
    if(newNode){
        if (head==NULL){
            head=newNode;
            tail=newNode;
        }else{
            head->prev=newNode;
            newNode->next=head;
            head=newNode;
        }
    }
}
struct st getDataFromUser(){
    // todo : get the grades from user --- this code makes error

       // int loopHealper = 0;
        struct st newSt;
        printf(" enter student id : ");
        scanf("%d",&newSt.id);
        printf("\n enter student name : " );
        scanf("%s",newSt.name);
        printf("\n enter the subject number : ");
        scanf("%d",&newSt.subject);
        /*
       for (loopHealper;loopHealper<=2;loopHealper++){
            printf("\n enter the grade %d : ",loopHealper+1);
            scanf("%d",newSt.grade[loopHealper]);
        }
         */

        return newSt;

};
struct node* create(){
    struct node* n =(struct node*) malloc(sizeof(struct node));
    if(n){
        struct st student = getDataFromUser();
        n->data=student;
    }else{
        printf("sorry we can't allocate new student");
    }
    return n;
}
void deleteAll (){
    struct node* temp;
    temp=head;
    while(temp){
        head=temp->next;
        free(temp);
        temp=head;
    }
}

void print(){
    struct node* temp;
    temp=head;
      printf("ID  | Name   |  subject   |   grade 1  |  grade 2  |  grade 3   \n");
        printf("-------------------------------------------------------------------------\n");
    while(temp){

        printf("%d  | %s\n",temp->data.id,temp->data.name);

        temp=temp->next;
    }
    deleteAll();
}
void searchById(){
    struct node* temp = head ;
    int flag = 0 ;
    int id ;
    printf ("\n enter the ID : ");
    scanf("%d",&id);
    while(flag == 0 && temp){
        if (temp->data.id==id){
            printf("ID  | Name   |  subject   |   grade 1  |  grade 2  |  grade 3   \n");
            printf("-------------------------------------------------------------------------\n");
            printf("%d  | %s\n",temp->data.id,temp->data.name);
            flag =1;
        }
        temp=temp->next;
    }
    if (flag ==0){
        printf("Opps ... id not found \n");
    }

}

void searchByName(){
// todo : this function not working as expected
    char ar[10];
    printf("\n enter the name : ");
    scanf("%s",ar);
    struct node* temp = head ;
    int flag = 0 ;
    while(flag == 0 && temp){
        if (temp->data.name==ar){
            printf("ID  | Name   |  subject   |   grade 1  |  grade 2  |  grade 3   \n");
            printf("-------------------------------------------------------------------------\n");
            printf("%d  | %s\n",temp->data.id,temp->data.name);
            flag =1;
        }
        temp=temp->next;
    }
    if (flag ==0){
        printf("Opps .....name not found \n");
    }

}
