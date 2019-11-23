#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct person
{
    char name[35];
    char address[50];
    char father_name[35];
    char mother_name[30];
    int mble_no;
}p;

void addrecord();
void listrecord();
void deleterecord();
void searchrecord();

int main()
{
    int choice;
    system("color 5f");

        printf("\n\n\n\t\t**********WELCOME TO PHONEBOOK*************");

        getch();

        while(1)
        {
            system("cls");
            printf("\n\n\t\t\t  MENU\t\t\n\n");
            printf("\t1.Add New   \n\t2.List    \n\t3.Search  \n\t4.Delete  \n\t5.Exit");
            printf("\n\nEnter your choice:");
            scanf("%d",&choice);

            switch(choice)
            {
                case 1:
                    addrecord();
                break;
               case 2: listrecord();
                break;
                case 3: searchrecord();
                break;
                case 4: deleterecord();
                break;
                case 5: exit(0);
                break;
                default:
                            system("cls");
                            printf("\nEnter 1 to 5 only");
                            printf("\n Enter any key");
                    getch();
            }
        }

    return 0;
}


void addrecord()
{
        system("cls");
        FILE *f;
        f=fopen("ei_suno","ab");
        printf("\n Enter name: ");
        fflush(stdin);
        gets(p.name);
        printf("\nEnter the address: ");
        fflush(stdin);
        gets(p.address);
        printf("\nEnter father name: ");
        fflush(stdin);
        gets(p.father_name);
        printf("\nEnter mother name: ");
        fflush(stdin);
        gets(p.mother_name);
        printf("\nEnter phone no.:");
        scanf("%d",&p.mble_no);

        fwrite(&p,sizeof(p),1,f);

        fflush(stdin);
        printf("\nrecord saved");

    fclose(f);

    printf("\n\nEnter any key");

    getch();
}

void listrecord()
{
    system("cls");
    FILE *f;
    f=fopen("ei_suno","rb");
    
    printf("\n\n\n YOUR RECORD IS\n\n ");

    while(fread(&p,sizeof(p),1,f)==1)
    {   
        printf("\nName=%s\nAdress=%s\nFather name=%s\nMother name=%s\nMobile no=%ld",p.name,p.address,p.father_name,p.mother_name,p.mble_no);
		printf("\n");
         //getch();
         //system("cls");
    }
    fclose(f);
    printf("\n Enter any key");
    getch();
    system("cls");
}


void searchrecord()
{
    system("cls");
    FILE *f;
    char name[100];

    f=fopen("ei_suno","rb");

    printf("\nEnter name of person to search\n");
    fflush(stdin);
    gets(name);
    while(fread(&p,sizeof(p),1,f)==1)
    {
        if(strcmp(p.name,name)==0)
        {
            printf("\n\tDetail Information About %s",name);
            printf("\nName:%s\naddress:%s\nFather name:%s\nMother name:%s\nMobile no:%ld",p.name,p.address,p.father_name,p.mother_name,p.mble_no);
        }
        else
        {
            printf("file not found");
        }


    }
 fclose(f);
  printf("\n Enter any key");

	 getch();
    system("cls");

}


void deleterecord()
{
	FILE *f,*t;
	char name[20];
	system("cls");
	f=fopen("ei_suno","rb");
	t=fopen("ei_suno1","wb");
	do{
	rewind(f);
	printf("Enter the phone number to be deleted from the Database: ");
	fflush(stdin);
	gets(name);
	while(fread(&p,sizeof(p),1,f)==1)
	{
		if(strcmp(p.name,name)!=0)
		{
		    fwrite(&p,sizeof(p),1,t);
		}
		else
		printf("Record deleted successfully.");
	}

	fclose(f);
	fclose(t);
	remove("ei_suno");
	rename("ei_suno1","ei_suno");

	f=fopen("ei_suno","rb");
	t=fopen("ei_suno1","wb");
    printf("\nDo you want to delete another record (y/n):");
	fflush(stdin);
	  }
    	while(getche()=='y'||getche()=='Y');
		fclose(f);
	getch();
}
