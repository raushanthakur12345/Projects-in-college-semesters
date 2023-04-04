#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bank{
	char phone[50];
	char password[20];
	float balance;
}node;

int main(){
	node user,use;
	char filename[50],phone[50],password[20];
	FILE *fp,*fpt;
	int opt,choice,amount;
	char count='y';
	printf("\nWhat do you want to do?");
	printf("\n\n1.Create an account");
	printf("\n2.Login to your account");

	printf("\n\nPlease enter your choice:\t");
	scanf("%d",&opt);
		if(opt == 1){
		system("CLS");
		printf("\t******* WELCOME TO CORPORATIVE BANK *******\n\n\n");
		printf("Enter your phone number:\t");
		scanf("%s",user.phone);
		printf("Enter your new password:\t");
		scanf("%s",user.password);
		user.balance=0;
		strcpy(filename,user.phone);
		fp=fopen(strcat(filename,".text"),"w");
		fwrite(&user,sizeof(user),1,fp);
		if(fwrite != 0){
			printf("Succesfully registered");
		}
	}
	else if(opt == 2){
		system("CLS");
		printf("\nPhone No.:\t");
		scanf("%s",phone);
		printf("Password:\t");
		scanf("%s",password);
		fp = fopen(strcat(phone,".text"),"r");
		if(fp == NULL) printf("Account number not registered");
		else {
			fread(&user,sizeof(node),1,fp);
			fclose(fp);
			if(!strcmp(password,user.password)){
				while(count == 'y' || count == 'Y'){
				system("CLS");
				printf("\n\t/******* Welcome To Corparitive Bank ******* \n\n\tRegistered Phone No. :      %s",user.phone);
				printf("\n   Press 1 for balance inquiry");
				printf("\n   Press 2 for adding fund");
				printf("\n   Press 3 for cash withdraw");
				printf("\n   Press 4 for changing password\n\nEnter Your Choice :   ");
				scanf("%d",&choice);
				switch(choice){
					case 1:
						printf("Your current balance is Rs. %.2f",user.balance);
						break;

					case 2:
						system("CLS");
						printf("Enter amount to be added:\t");
						scanf("%d",&amount);
						user.balance += amount;
						fp = fopen(phone,"w");
						fwrite(&user,sizeof(node),1,fp);
						if(fwrite !=0) printf("\n\nYou have depostied Rs.%d",amount);
						fclose(fp);
						break;

					case 3:
						system("CLS");
						printf("Enter withdrawl amount:\t");
						scanf("%d",&amount);
						if(amount % 500 != 0) printf("\nSorry amount should be multiple of 500");
						else if(amount>user.balance) printf("\nSorry insufficeint balance");
						else {
							user.balance -= amount;
						fp = fopen(phone,"w");
						fwrite(&user,sizeof(node),1,fp);
						if(fwrite !=0) printf("\n\nYou have withdrawn Rs.%d",amount);
						fclose(fp);
						}
						break;
									
					case 4:
						printf("\n\nPlease enter your old password:\t");
						scanf("%s",password);
						if(!strcmp(password,user.password)){
							printf("\n\nPlease enter your new password:\t");
							scanf("%s",password);
							strcpy(user.password,password);
							strcpy(filename,user.phone);
							fp = fopen(strcat(filename,".text"),"w");
							fwrite(&user,sizeof(node),1,fp);
							fclose(fp);	
							printf("\nPassword succesfullly changed");
						}else printf("\nSorry your password is wrong");
					
					default:
					break;
				}//switch ends here
				printf("\n\nDo you want to countinue?[y/n]:\t");
				scanf("%s",&count);
				}
			}
			else {
				printf("Invalid password");
			}	
		}
		printf("\n\n***Thank you for banking with CORPORATIVE BANK ***\n\n");
	}
	
	return 0;
}