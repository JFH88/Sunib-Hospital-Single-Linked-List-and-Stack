#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
	char medName[50];
	struct node *next;
};

struct node *top = NULL;
int itemCount = 0;

void convertToLowercase(char *str)
{
	char lowerStr[10];
	int i=0;
	while(str[i] != '\0')
	{
		lowerStr[i] = (65 <= str[i] && str[i] <= 90) ? tolower(str[i]) : str[i];
		i++;
	}
	
	str[i] = '\0';
	
	strcpy(str, lowerStr);
}

void pushItem(char *inputMed)
{
	struct node *newMed = (struct node*)calloc(1, sizeof(struct node));
	strcpy(newMed->medName, inputMed);
	
	if(top == NULL)
	{
		top = newMed;
		top->next = NULL;
	}
	else
	{
		newMed->next = top;
		top = newMed;
	}
	
	itemCount++;
	printf("Medicine %s is added to the prescription\n", inputMed);
}

void popItem()
{
	struct node *ptr = top;
	int count = 1;
	while(ptr != NULL)
	{
		printf("Take Medicine #%d: %s\n", count++, ptr->medName);
		ptr = ptr->next;
	}
	
	top = NULL;
	itemCount = 0;
}

int main()
{
	char inputMed[50];
	char inputContinue[5];
	char copyInputMed[50];
	do{
		do{
			printf("Enter the medicine name [minimum 5 medicines] ('done' to finish): ");
			fflush(stdin);
			scanf("%[^\n]", inputMed);
			strcpy(copyInputMed, inputMed);
			convertToLowercase(copyInputMed);
			if(strcmp(copyInputMed, "done") != 0)
			{
				pushItem(inputMed);
			}
		}while(strcmp(copyInputMed, "done") != 0 || itemCount < 5);
		
		printf("\n");
		printf("Medicine Prescription:\n");
		popItem();
		
		printf("Do you want to continue? (yes/no): ");
		scanf("%s", inputContinue);
		convertToLowercase(inputContinue);
	}while(strcmp(inputContinue, "yes") == 0);
	
	return 0;
}
