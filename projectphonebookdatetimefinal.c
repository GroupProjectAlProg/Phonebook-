#include<stdio.h>
#include<time.h>
//THIS PROGRAM IS MADE BY JOHN WINNSTON 1706064675
//						  KAIZEN LOLO   1706064681

/*With help from: https://stackoverflow.com/questions/18421619/c-language-record-data-add-delete-in-text-file-using-file-io-structure-fun
				  https://stackoverflow.com/questions/19473629/file-and-fp-translation
				  https://www.programiz.com/c-programming/c-file-input-output															*/

int menu();
void displaycontact();
void addcontact();
void deletecontact();
void searchcontact();

int main()
{	
    int choice;
	choice=menu();
    while(choice!=5){
		switch(choice)
	    {
	    case 1:
	    	displaycontact();
	        break;
	    case 2:
	        addcontact();
	        break;
	    case 3:
	        deletecontact();	
	        break;
	    case 4:
	        searchcontact();
	        break;
	    default:
	    	printf("\tInvalid Choice\n");
	    	system("pause");
	    	break;
		}
		choice=menu();
	}
	return 0;
}

int menu(){
	system("cls");
    printf("\tPHONE BOOK\n");
    printf("[1] Display Contact\n");
    printf("[2] Add Contact\n");
    printf("[3] Delete Contact\n");
    printf("[4] Search Contact\n");
    printf("[5] Exit\n");
    printf("\nEnter Your Choice: ");
    
    int choice;
    scanf("%d",&choice);
    return choice;
}

void displaycontact()
{
    FILE *fp;
    fp=fopen("contact.txt","r+");
    system("cls");
    printf("\t\tALL CONTACTS");
    
	char fname[20], lname[20], phone[20], timee[20];
    while(fscanf(fp,"%s %s %s %s\n",fname,lname,phone,timee)!=EOF)
    {
        printf("\n\tFirst Name\t: %s",fname);
        printf("\n\tLast Name\t: %s",lname);
    	printf("\n\tPhone\t\t: %s",phone);
        printf("\n\tDate Recorded\t: %s\n\n",timee);    
    }
    
	fclose(fp);
	printf("\n");
    system("pause");
}

void addcontact()
{
    int i;
	time_t rawtime;
	char *timeinfo;
	char *timee, *timed;
  	time ( &rawtime );
  	timeinfo = localtime ( &rawtime );
	
	FILE *fp;
    fp=fopen("contact.txt","a+");
    system("cls");
    printf("ADD CONTACT");
    
    char fname[20], lname[20];
	printf("\n\tFirst Name\t: ");
    scanf("%s",fname);
    printf("\n\tLast Name\t: ");
    scanf("%s",lname);
	printf("\n\tPhone\t\t: " );
    char phone[20];
    scanf("%s",phone);
    timee = asctime (timeinfo);
    while(timee[i]!='\0')
     {
           if(timee[i]== ' ')
           {
               timee[i]= '_';
           }  
           i++; 
     }
     
	fprintf(fp,"%s %s %s %s\n",fname, lname, phone, timee);
    printf("\n\tDate Recorded\t: %s\n", timee);
	
	fclose(fp);
	printf("\n");
    system("pause");
}


void deletecontact()
{
    FILE *fp,*fp1;
    fp=fopen("contact.txt","r");
    fp1=fopen("temp.txt","w");
    system("cls");
    printf("DELETE CONTACT");
    
	printf("\n\tEnter First Name : ");
    char fname[20], fname1[20];
    int found=0;
    scanf("%s",fname);
    char lname[20],phone[20], timee[25];
	while(fscanf(fp,"%s %s %s %s",fname1,lname,phone, timee)!=EOF){
        if(strcmp(fname,fname1)==0){
            found=1;
			continue;
        }
        fprintf(fp1,"%s %s %s %s\n",fname1, lname, phone, timee);
    }
    if(found==0){
    	printf("Contact name not found.");
	}
    fclose(fp);
    fclose(fp1);
    
	fp=fopen("contact.txt","w");
    fp1=fopen("temp.txt","r");
    while(fscanf(fp1,"%s %s %s %s",fname1, lname, phone, timee)!=EOF)
    {

        fprintf(fp,"%s %s %s %s\n",fname1, lname, phone, timee);
    }
    fclose(fp);
    fclose(fp1);
    
    remove("temp.txt");
    printf("\n\tYour Contact has been deleted.\n");
    system("pause");
}


void searchcontact()
{
    FILE *fp;
    fp=fopen("contact.txt","r");
    system("cls");
    printf("SEARCH CONTACT");
    printf("\n\tEnter Name : ");
    char fname[20], fname1[20];
    int found=0;
    scanf("%s",fname);
    char lname[20], phone[20], timee[25];
    while(fscanf(fp,"%s %s %s %s",fname1, lname, phone, timee)!=EOF)
    {
        if(strcmp(fname,fname1)==0)
        {
        	found=1;
            printf("\n\tFirst Name\t: %s",fname1);
            printf("\n\tLast Name\t: %s",lname);
            printf("\n\tPhone\t\t: %s",phone);
            printf("\n\tDate Recorded\t: %s\n",timee);
        }
    }
    if(found==0){
    	printf("Contact name not found.");
	}
    fclose(fp);
    printf("\n");
    system("pause");
}
