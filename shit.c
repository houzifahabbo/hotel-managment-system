#include <stdio.h> 
#include <string.h> 
#include <conio.h>
#include <stdlib.h>

int main()
{
	login();
}

int login()
{
	
	char userc [10]="";
    char passc[10]="";
    char line[100];
    int log;
    
    struct Account
	{
		char username [10];
		char password [10];
	}a;
	
    system("cls");
    printf("please choose menu\n1- signup\n2- login\n");
    scanf("%d",&log);
    
    switch (log)
    {
    	case 1:
    	{
    		FILE *users;
			users  = fopen("users.txt", "a+");
    		printf("username:");
	        scanf("%s",a.username);
	        printf("password:");
	        scanf("%s",a.password);
	        fprintf(users, "\n%s     %s\n", a.username,a.password);
	        printf("plese enter any key");
    	    fclose(users);
	        getch();
	        login();
	        break;
	    }
	    case 2:
	    {
	    	FILE *users;
			users  = fopen("users.txt", "r");
			/*if(users == NULL)
			{
                perror("Unable to open file!");
                exit(1);
            }*/
	        printf("username:");
	        scanf("%s",userc);
	        printf("password:");
	        scanf("%s",passc);
            while(fgets(line, sizeof(line) , users) != NULL)
			{
	            fscanf(users, "%s%s",&a.username,&a.password);
	     	}
            fclose(users);      
	        if(strcmp(userc,a.username)==0)
		    {   
			    if(strcmp(passc,a.password)==0)
			    {
				    main_menu();
			    }
			    else
			    {
				    printf("wrong password\nprees any key to retry");
				    getch();
			    	main();
		    	}
		    }
	        else
		    {
			    printf("username doesn't exist\nprees any key to retry");
			    getch();
			    main();
		    }
		    break;
		}
		default:
		{
			printf("Oops,something went wrong");
			sleep(2);
			main();
			break;
		} 
	}
    return 0;
}


void main_menu()
{
	int x;
	printf("Welcome\nplease choose menu\n1-book a room\n2-guest data\n3-room services\n4-edit or delete gusts data\n5-exit\n");
	scanf("%d",&x);
	switch(x)
	{
		case 1:
			book_a_room();
		case 2:
			guets_data();
		case 3:
			room_services();
		case 4:
			edit_or_delete_guest_data();
		case 5:
			exit(0);
		default:
			printf("Oops,something went wrongw");
			sleep(2);
			main_menu();
	}
}

void book_a_room()
{
	FILE *guest_data;
	int x;
	struct Data
	{
		int room[100];
		char id[400];
		char first_name[400];
		char last_name[400];
		int phone[200];
		char nationality[400];
		int period[400];
		int fees[100];
	}d;
	system ("cls");
	add = fopen("guest_data.txt","a+");
	printf("enter room number:\n");
	scanf("%d",&d.room);
	printf("enter the guest id/passport number:\n");
	scanf("%s",&d.id);
	printf("enter the guest first name:\n");
	scanf("%s",&d.first_name);
	printf("enter the guest last name:\n");
	scanf("%s",&d.last_name);
	printf("enter the guest phone number:\n");
	scanf("%d",&d.phone);
	printf("enter nationaltiy:\n");
	scanf("%s",&d.nationalty);
	printf("enter the guest period of staying by days:\n");
	scanf("%d",&d.period);
	printf("enter fees per day:\n");
	scanf("%d",&d.fees);
	d.fees*= d.period;
	fprintf(guest_data,"\nroom number:   id/passport number:   first name:   last name:   phone number:   nationaltiy:   period of staying by days:   fees per day:   %d   %s   %s   %s   %d   %s   %d   %d\n",d.room,d.id,d.first_name,d.last_name,d.phone,d.nationaltiy,d.period,d.fees);
	fclose(guest_data);
	printf("1-to add another gusest\n2-to return to main menu");
	scanf("%d",&x);
	switch (x)
	{
		case 1:
			
	}
}
