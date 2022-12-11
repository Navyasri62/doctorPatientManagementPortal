#include "common.h"
#include "receiver.h"
extern recnode *rechead;

void receiver(recnode *recpointer){
	printf("*********************************ORGAN REQUEST REGISTRATION PORTAL  ************************************************\n\n\n");
	int srl=1;
	char key;

	if(recpointer==NULL){
		rechead=(recnode*)malloc(sizeof(recnode));
		recpointer=rechead;
		recpointer->next=NULL;  
		printf("Enter  name: ");
		getchar();
		gets(recpointer->name);
		printf("Enter blood group : ");
		getchar();
		gets(recpointer->bloodGroup);
		printf("Organ Needed:\t");
		getchar();
		gets(recpointer->organ);
		printf("Emergency?(Y/N):\t");
		printf("\n1.Yes\n2.No\n");
		getchar();
		gets(recpointer->medicalStatus);

phone_tag1:
		printf("Enter  Mobile Number: ");
		gets(recpointer->phone);

	}
	else{
		while(recpointer->next!=NULL)
		{
			recpointer=recpointer->next;
		}
		recpointer->next=(recnode*)malloc(sizeof(recnode));
		recpointer=recpointer->next;
		recpointer->next=NULL;
		printf("Enter name: ");
		getchar();
		printf("Enter blood group : ");
		getchar();
		gets(recpointer->bloodGroup);
		printf("Organ Needed:\t");
		getchar();
		gets(recpointer->organ);
		printf("Emergency?(Y/N):\t");
		printf("\n1.Yes\n2.No\n");
		getchar();
		gets(recpointer->medicalStatus);

phone_tag:
		printf("Enter Mobile Number: ");
		gets(recpointer->phone);

	}

	int len=strlen(recpointer->phone);
	if(len!=10)
	{
		printf("Invalid Mobile Number. Try again\n");
		goto phone_tag1;
	}
	int i;
	for(i=0;recpointer->phone[i]!='\0';i++)
	{
		if(recpointer->phone[i]<'0' || recpointer->phone[i]>'9')
		{
			printf("Invalid Mobile Number. Try again\n");
			goto phone_tag1;
		}
	}
	recpointer->serial=srl;
	srl++;
	printf("\n\nDetail added Successfully\n\n");
	printf("Press any key to continue...");
	scanf("%c",&key);
	if(key>=0){
		return;
	}
}

void viewRecProfile(recnode *recpointer){
	printf("*************************************************  Organ Request list ******************************************************\n\n\n");
	if(recpointer==NULL)
	{
		printf("No Record Found!!!\n\n\n");
		return;
	}
	while(recpointer!=NULL)
	{
		printf("%d: ",recpointer->serial);
		printf("\n");
		printf("Name\t\t:\t");
		printf("%s",recpointer->name);
		printf("\n");
		printf("Phone\t\t:\t");
		printf("%s",recpointer->phone);
		printf("\n");
		printf("Blood Group\t\t:\t");
		printf("%s",recpointer->bloodGroup);
		printf("\n");
		printf("Organ Needed\t\t:\t");
		printf("%s",recpointer->organ);
		
		recpointer=recpointer->next;
	}
	printf("\n\n\nPress any key to go back : ");
	char key;
	getchar();
	scanf("%c",&key);
	if(key>=0)
	{   
		return;
	}
}


