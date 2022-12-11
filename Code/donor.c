#include "common.h"
#include "donor.h"
extern donornode *donorhead;

void donor(donornode *donorpointer){
	printf("*********************************ORGAN DONATION REGISTRATION PORTAL  ************************************************\n\n\n");
	int srl=1;
	char key;

	if(donorpointer==NULL){
		donorhead=(donornode*)malloc(sizeof(donornode));
		donorpointer=donorhead;
		donorpointer->next=NULL;  
		printf("Enter  name: ");
		getchar();
		gets(donorpointer->name);
		printf("Enter blood group : ");
		getchar();
		gets(donorpointer->bloodGroup);
		printf("Which organ you wish to donate:\t");
		getchar();
		gets(donorpointer->organ);
		printf("Current medical status:\n");
		printf("Are you taking any medicine for any disease?(Y/N):\t");
		printf("\nY.Yes\nN.No\n");
		getchar();
		gets(donorpointer->medicalStatus);

phone_tag1:
		printf("Enter  Mobile Number: ");
		gets(donorpointer->phone);

	}
	else{
		while(donorpointer->next!=NULL)
		{
			donorpointer=donorpointer->next;
		}
		donorpointer->next=(donornode*)malloc(sizeof(donornode));
		donorpointer=donorpointer->next;
		donorpointer->next=NULL;
		printf("Enter name: ");
		getchar();
		printf("Enter blood group : ");
		getchar();
		gets(donorpointer->bloodGroup);
		printf("Which organ you wish to donate:\t");
		getchar();
		gets(donorpointer->organ);
		printf("Current medical status:\n");
		printf("Are you taking any medicine for any disease?(Y/N):\t");
		printf("\nY.Yes\nN.No\n");
		getchar();
		gets(donorpointer->medicalStatus);

phone_tag:
		printf("Enter Mobile Number: ");
		gets(donorpointer->phone);

	}

	int len=strlen(donorpointer->phone);
	if(len!=10)
	{
		printf("Invalid Mobile Number. Try again\n");
		goto phone_tag1;
	}
	int i;
	for(i=0;donorpointer->phone[i]!='\0';i++)
	{
		if(donorpointer->phone[i]<'0' || donorpointer->phone[i]>'9')
		{
			printf("Invalid Mobile Number. Try again\n");
			goto phone_tag1;
		}
	}
	donorpointer->serial=srl;
	srl++;
	printf("\n\nSuccessfully Registered\n\n");
	printf("Press any key to continue...");
	scanf("%c",&key);
	if(key>=0){
		return;
	}
}

void viewDonProfile(donornode *donorpointer){
	printf("*************************************************  Organ Donor's list ******************************************************\n\n\n");
	if(donorpointer==NULL)
	{
		printf("No Record Found!!!\n\n\n");
		return;
	}
	while(donorpointer!=NULL)
	{
		printf("%d: ",donorpointer->serial);
		printf("\n");
		printf("Name\t\t:\t");
		printf("%s",donorpointer->name);
		printf("\n");
		printf("Phone\t\t:\t");
		printf("%s",donorpointer->phone);
		printf("\n");
		printf("Blood Group\t\t:\t");
		printf("%s",donorpointer->bloodGroup);
		printf("\n");
		printf("Organ \t\t:\t");
		printf("%s",donorpointer->organ);

		donorpointer=donorpointer->next;
	}
	printf("\n\n\n\Press any key to go back : ");
	char key;
	getchar();
	scanf("%c",&key);
	if(key>=0)
	{
		return;
	}
}
