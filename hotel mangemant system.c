#include <stdio.h> 
#include <string.h> 
#include <conio.h>
#include <stdlib.h>

int main()
{
	//login();
//	book_a_room();
	guest_data();
	return 0;
}

int login()
{
	
	char userc [10]="";
    char passc[10]="";
    char line[400];
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

struct Data
{
	int room;
	int id;
	char first_name[400];
	char last_name[400];
	int phone;
	char nationality[400];
	int period;
	int fees;
	int total;
}d;

int main_menu(void)
{
	int x;
	printf("Welcome\nplease choose menu\n1-book a room\n2-guest data\n3-room services\n4-edit or delete gusts data\n5-exit\n");
	scanf("%d",&x);
	switch(x)
	{
		case 1:
			book_a_room();
			break;
		case 2:
			guest_data();
			break;
		case 3:
			//room_services();
			break;
		case 4:
			//edit_or_delete_guest_data();
			break;
		case 5:
			exit(0);
			break;
		default:
			printf("Oops,something went wrongw");
			sleep(2);
			main_menu();
			break;
	}
}

int book_a_room(void)
{
	int x;
	FILE *guest_data;
	if ((guest_data = fopen("guest_data.txt", "a+")) == NULL)
	{
        printf("Error! File cannot be opened.");
        exit(1);
    }
	
	system ("cls");
	guest_data = fopen("guest_data.txt","a+");
	printf("enter room number:\n");
	scanf("%d",&d.room);
	printf("enter the guest id/passport number:\n");
	scanf("%d",&d.id);
	printf("enter the guest first name:\n");
	scanf("%s",&d.first_name);
	printf("enter the guest last name:\n");
	scanf("%s",&d.last_name);
	printf("enter the guest phone number:\n");
	scanf("%d",&d.phone);
	printf("enter nationaltiy:\n");
	scanf("%s",&d.nationality);
	printf("enter the guest period of staying by days:\n");
	scanf("%d",&d.period);
	printf("enter fees per day:\n");
	scanf("%d",&d.fees);
	d.total = d.fees * d.period;
	printf("total fees:\n%d\n",d.total);
	fprintf(guest_data,"\n%d   %d   %s   %s   %d   %s   %d   %d   %d\n",d.room,d.id,d.first_name,d.last_name,d.phone,d.nationality,d.period,d.fees,d.total);
	fclose(guest_data);
	while(x!=1|x!=2)
	{
		printf("1-to add another gusest\n2-to return to main menu\n");
		scanf("%d",&x);
	    switch (x)
	    {
		    case 1:
			    book_a_room();
			    break;
		    case 2:
			    main_menu();
			    break;
		    default:
			    printf("Oops,soemting went wrong\n");
			    break;
	    }
    }
}
int guest_data(void)
{
	int x,line[400];
	FILE *guest_data;
	guest_data= fopen("guest_data.txt","r");
	printf("Enter room number:\n");
	scanf("%d",&x);
	fscanf(guest_data , "%[^\n]", line);
	/*while(fgets(line, sizeof(line) , guest_data) != NULL)
	{
		fscanf(guest_data,"%d",&d.room);
		fputs(line, stdout);
	}*/
	fclose(guest_data);
	if(strcmp(x,d.room)==0)
	{
		guest_data= fopen("guest_data.txt","r");
		fscanf(guest_data,"%d%d%s%s%d%s%d%d%d",&d.room,&d.id,&d.first_name,&d.last_name,&d.phone,&d.nationality,&d.period,&d.fees,&d.total);
	    fputs(line, stdout);
		//printf("%d   %d   %s   %s   %d   %s   %d   %d   %d\n",d.room,d.id,d.first_name,d.last_name,d.phone,d.nationality,d.period,d.fees,d.total);
	}		    
	else
	{
		printf("username doesn't exist\nprees any key to retry");
	}
}
