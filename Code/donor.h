#ifndef DON_H
#define DON_H


typedef struct donornode
{
	int serial;
	char name[100];
	char phone[12];
	char organ[100];
	char adhaar[12];
	char bloodGroup[12];
	char medicalStatus[10];
	struct donornode *next;
}donornode;
void donor(donornode *);
void viewDonProfile(donornode *);
#endif



