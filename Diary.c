#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Diary{
   char name[100];
   char date[25];
   char time[15];
  // char place[15];
   char note[1];
}S ;

S Newrecord(S *w);
void viewrecord();
void editrecord();
void addrecord();
void searchrecord();
void delete();
void addpassword();
S func(S *e);
int main()
{
  char d[1000];
  S r,*ptr;
ptr=&r;
Newrecord(ptr);
fgets(d,100,stdin);



}
S Newrecord(S *w)
{
printf("Enter the name of the owner\n");
scanf("%[^\n]%*c",w->name);
printf("Current Date : mm-dd-yyyy\n");
scanf(" %[^\n]s",w->date);
printf("Current Time : 00:00:00\n");
scanf(" %[^\n]s",w->time);
printf("Note: ");
scanf(" %[^\n]s",w->note);

//while(scanf(" %[^\n]%*c",w->note)==1){
  //break;
  //}
}
