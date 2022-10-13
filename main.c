#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void addstudent();
void studentrecord();

struct std{
  char f_name[30];
  char l_name[30];
  int roll;
  float per;

  };

int main(){

int i;

while(i!=5){

    printf("\t\t=====Student Database=====\t\t\n");
    printf("\t\t  1.Add student\n");
    printf("\t\t  2.Student Record\n");
    printf("\t\t  3.EXIT \n");
   printf("\t\t====================================\n");
   scanf("%d",&i);


   switch(i){
   case 1:
   addstudent();
   break;

   case 2:
   studentrecord();
    break;
   case 3:
    printf("\n\t\t\tthank you using this Software\n");
    exit(0);


   }
}



}
// this dunction is used to creat and save recors in flie
void addstudent(){  
     char another;
     FILE *fp;
     struct std a;

      do{
        printf("\t\t\tAdd Student Detail====");
        
        //here file is created
        fp=fopen("student data.txt","a");
        //////
        printf("\n\t\t Enter first name:: ");
        scanf("%s",&a.f_name);
         printf("\n\t\t Enter last name:: ");
        scanf("%s",&a.l_name);
         printf("\n\t\t Enter Roll no::");
        scanf("%d",&a.roll);
         printf("\n\t\t Enter Percentage:: ");
        scanf("%f",&a.per);
        printf("-----------------------------------\n");

        if(fp==NULL){
            printf("error");
            exit(0);
        }else{
          printf("Recored \n");

        }
        fwrite(&a,sizeof(struct std),1,fp);

         fclose(fp);
          printf("\t\t=============================== \n");
     fflush(stdin);
          printf("Do you want to record another Data(y/n) \n");
          scanf("%c",&another);
}while(another=='y');
}



// this function is used to sisplay save file records
void studentrecord(){
 FILE*fp;
 struct std a;
 
 fp=fopen("student data.txt","r");

   printf("\t\t\t\t=======Student Data=====");


   if(fp==NULL){
    printf("ERROR");
    exit(0);
   }else{
      printf("\n\t\t\t\t===Records===\n");
      printf("\t\t\t\t---------------\n");

   }
   while(fread(&a,sizeof(struct std),1,fp)){
    printf("\n\t\t\tStudent Name::%s %s",a.f_name ,a.l_name);
        printf("\n\t\t\tStudent Roll::%d",a.roll);
    printf("\n\t\t\tStudent Percentage::%f",a.per);
    printf("\n\t\t\t----------------------------------\n\n\n");

   }
   fclose(fp);

}



