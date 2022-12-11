#ifndef REC_H
#define REC_H


typedef struct recnode
{
	int serial;
	char name[100];
	char phone[12];
	char organ[100];
	char adhaar[12];
	char bloodGroup[12];
	char medicalStatus[10];
	struct recnode *next;
}recnode;
void receiver(recnode *);
void viewRecProfile(recnode *);
#endif
