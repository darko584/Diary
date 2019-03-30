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
printf("Enter the name of the owner\n");
scanf(" %[^\n]%*c",w->name);
printf("Current Date : mm-dd-yyyy\n");
scanf(" %[^\n]s",w->date);
printf("Current Time : 00:00:00\n");
scanf(" %[^\n]s",w->time);
printf("Note: ");
scanf(" %[^\n]s",w->note);
choice();

//while(scanf(" %[^\n]%*c",w->note)==1){
  //break;
  //}
}

void addrecord ()
{
  int i;
  FILE *fp;
  fp=fopen("/Users/mac/documents/Diary_1.txt","w");
    printf("Current Date : mm-dd-yyyy\n");
    scanf(" %[^\n]s",gptr->date);
    printf("Current Time : 00:00:00\n");
    scanf(" %[^\n]s",gptr->time);
    printf("Note: ");
    scanf(" %[^\n]s",gptr->note);
    fprintf(fp,"%s\t%s\t%s\t",gptr->date,gptr->time,gptr->note);
  additionalrecord(fp);
  fclose(fp);
  choice();
}

void additionalrecord(FILE *fp1)
{
  //fp1=fopen("")
  char ch;
  int i,n;

  printf("GIVE a yes for y\n");
  scanf(" %c",&ch);
  printf("How amy times\n");
  scanf("%d",&n);
  if(ch=='Y'&&ch=='y'){
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
