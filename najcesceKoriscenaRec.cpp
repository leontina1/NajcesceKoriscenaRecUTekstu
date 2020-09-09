#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
	char rec[101];
	int frequency;
} WordArray;
void malaslova(char buff[])
{
	int j;
	int n=strlen(buff);
	for(j=0;j<n;j++)
	{
		if(buff[j]>='A' && buff[j]<='Z')
		buff[j]='a'+buff[j]-'A';
	}
}
main()
{
 int counter = 0;
	int isUnique;
	FILE *file;
	char buff[10000];
	WordArray reci[1000];
	int n;
	printf("Unesi broj dozvoljenih slova u reci:\n");
	scanf("%d",&n);
	file = fopen("AutobiografijaBNusic.txt", "r");

	if (file == NULL){
		printf("Couldn't open file: ");
	}
	
	else {
		while ( (fscanf(file, "%s", buff)) != EOF)
		{
			isUnique = -1;
			if(strlen(buff)==1 && !((buff[0]>='A' && buff[0]<='Z') || (buff[0]>='a' && buff[0]<='z'))) continue;
			while (!((buff[strlen(buff)-1]>='A' && buff[strlen(buff)-1]<='Z') || (buff[strlen(buff)-1]>='a' && buff[strlen(buff)-1]<='z'))) buff[strlen(buff)-1]='\0';
			//Uporedjivanje stringova da se proveri da li je rec u nizu
			if(strlen(buff)==0) continue;
			int k;
			for (k = 0; k < counter; k++)
			{
				malaslova(buff);
				if (strcmp(reci[k].rec, buff) == 0){
					isUnique = k;
				}
			}
			// Ako string nije u nizu,stavi ga u niz
			if (isUnique == -1){
				strcpy(reci[counter].rec, buff);
				reci[counter].frequency = 1;
				counter++;
			}
			// Povecaj ucestalost neunikatih reci
			else {
				reci[isUnique].frequency++;
			}	
		}
	}
	int i,max=0;
	for(i=0;i<counter;i++)
	{
		if(strlen(reci[i].rec)==n) 
		{
			if (max==0) 
				max=reci[i].frequency;
			else if (reci[i].frequency>max)
			
				max=reci[i].frequency;
		}
	}
	if(max>0)
	{
		printf("\nNajcesce koriscene reci u tekstu: \n");
	for(i=0;i<counter;i++)
	{
		if ((strlen(reci[i].rec)==n) && (reci[i].frequency==max))
			printf("\n%s\n",reci[i].rec);
	}
	}
	else printf("\nNe postoji nijedna rec sa unetim brojem slova.\n");
}
