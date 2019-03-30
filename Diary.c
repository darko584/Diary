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

int count=0;
FILE *fp0;
S g[10],*gptr;
S r,*ptr;
S d[10],*dptr;

S Newrecord(S *w);
void editrecord();
void addrecord();
void searchrecord();
void delete();
void addpassword();
void additionalrecord(FILE *fp1);
void reader();

void viewrecord()
{
  printf("The total number of records currently present : %d\n",count);
}

void choice()
{
  printf("Enter a number :\
  1--To add a new record :\t\
  2--To append in the existing record\t\
  3--To exit :\t\
  4--To view the total no of records :\t\
  5--To serach records respective to dates : ");
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
    case 3:
      exit(0);
      break;
    case 4:
      viewrecord();
      break;
    case 5:
      reader();
      break;
    default:
      printf("Wrong number choice\n");
      break;
  }

}

int main()
{
  gptr=g;
  dptr=d;
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
count++;
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
    count++;
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
    count++;
    gptr++;
  }
}

}

void reader()
{
  FILE *fp0;
  int i;
  fp0=fopen("/Users/mac/documents/Diary_1.txt","r");
  for(i=0;i<10;i++)
  {
  fscanf(fp0,"%s%s%s%s",dptr->name,dptr->date,dptr->time,dptr->note);
  dptr++;
  }
  searchrecord();
}

void searchrecord()
{
  int i;
  dptr=d;
  char ch[10];
  printf("Enter the entry date for the record to be searched : ");
  scanf(" %[^\n]s",ch);
    for(i=0;i<10;i++)
      {
        if(strcmp(ch,dptr->date)==0)
        {
          printf("NAME:%s\tTIME:%s\nNOTE: %s\n ",dptr->name,dptr->time,dptr->note);
        }
        dptr++;
      }


}
