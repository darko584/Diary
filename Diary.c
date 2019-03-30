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
  gptr=g;
  S r,*ptr;
  ptr=&r;
  switch(getchar())
  {
    case '1':
      Newrecord(ptr);
    case '2':
      addrecord();
  }

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

void addrecord ()
{
  int i;
  FILE *fp;
  fp=fopen("/Users/mac/documents/Diary_1.txt","w");
  for(i=0;i<10;i++)
  {
    printf("Current Date : mm-dd-yyyy\n");
    scanf(" %[^\n]s",gptr->date);
    printf("Current Time : 00:00:00\n");
    scanf(" %[^\n]s",gptr->time);
    printf("Note: ");
    scanf(" %[^\n]s",gptr->note);
    fprintf(fp,"%s\t%s\t%s\t",gptr->date,gptr->time,gptr->note);
    gptr++;
  }
  fclose(fp);
}

void editrecord()
{

}
