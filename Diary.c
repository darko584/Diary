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

FILE *fp0;
S g[10],*gptr;
S r,*ptr;

S Newrecord(S *w);
void viewrecord();
void editrecord();
void addrecord();
void searchrecord();
void delete();
void addpassword();
void additionalrecord(FILE *fp1);

void choice()
{
  printf("Enter a number :\
  1--To add a new record\t\
  2--To append in the existing record : ");
  int d;
  scanf("%d",&d);
  switch(d)
  {
    case 1:
      Newrecord(ptr);
      break;
    case 2:
      addrecord();
      break;
    default:
      printf("Wrong number choice\n");
      break;
  }

}

int main()
{
  gptr=g;
  ptr=&r;
  choice();
}

S Newrecord(S *w)
{
fp0=fopen("/Users/mac/documents/Diary_1.txt","w");
printf("Enter the name of the owner\n");
scanf(" %[^\n]%*c",w->name);
printf("Current Date : mm-dd-yyyy\n");
scanf(" %[^\n]s",w->date);
printf("Current Time : 00:00:00\n");
scanf(" %[^\n]s",w->time);
printf("Note: ");
scanf(" %[^\n]s",w->note);
fprintf(fp0,"%s\t%s\t%s\n%s",w->name,w->date,w->time,w->note);
fclose(fp0);
choice();

//while(scanf(" %[^\n]%*c",w->note)==1){
  //break;
  //}
}

void addrecord ()
{
  int i;
  fp0=fopen("/Users/mac/documents/Diary_1.txt","a");
    printf("Current Date : mm-dd-yyyy\n");
    scanf(" %[^\n]s",gptr->date);
    printf("Current Time : 00:00:00\n");
    scanf(" %[^\n]s",gptr->time);
    printf("Note: ");
    scanf(" %[^\n]s",gptr->note);
    fprintf(fp0,"%s\t%s\t%s\t",gptr->date,gptr->time,gptr->note);
  additionalrecord(fp0);
  fclose(fp0);
  choice();
}

void additionalrecord(FILE *fp1)
{
  //fp1=fopen("")
  char ch;
  int i,n;
  printf("Do you want to add more records: ");
  printf("GIVE a Y or y for yes\n");
  scanf(" %c",&ch);
  if(ch=='Y'|| ch=='y'){
    printf("How many records do you want to add (MAX 10)\n");
    scanf(" %d",&n);
  for(i=0;i<n;i++)
  {
    printf("Current Date : mm-dd-yyyy\n");
    scanf(" %[^\n]s",gptr->date);
    printf("Current Time : 00:00:00\n");
    scanf(" %[^\n]s",gptr->time);
    printf("Note: ");
    scanf(" %[^\n]s",gptr->note);
    fprintf(fp1,"%s\t%s\t%s\t",gptr->date,gptr->time,gptr->note);
    gptr++;
  }
}

}
