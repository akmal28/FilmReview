#include <stdio.h>
#include <conio.h>
#include <string.h>
#define max 101

typedef struct movie{
	char title[100];
	char swtitle[100];															
	int top;
	int ttl;						
	int avg;
} m;
typedef struct input{
	int rate;
	char review[1000];	
	int id;
} stack;

m mov[3];
stack inp[3][max];

void movietitle();
void header();
void createEmpty();
int isFull();
void num1();
void num2();
void num3();
void num4();

int i,j,x,pilihan,rate,swap,maximum,idnum,c;
char *titlePtr[3];
int *avgPtr[3];

int main(){
	system("COLOR F0");	
	createEmpty();
	strcpy(mov[0].title,"Murder on the Orient Express");
	strcpy(mov[1].title,"The Perks of Being a Wallflower");
	strcpy(mov[2].title,"The Shawshank Redemption");
	do{
		do{
			header();
			movietitle();
			printf("\n What do you want?\n 1. Give rate and review\n 2. Show user reviews\n 3. Show user ratings\n 4. Show movie rankings\n 5. End program\n");
			printf(" Your answer: ");
			scanf("%d",&pilihan);
			if(pilihan<1||pilihan>5){
				printf("\n Wrong input!\n\n");
				printf("\n\n\n\n\n (Press any button to refresh)\n ");
				getch();
				system("cls");
			}	
		}
		while(pilihan<1||pilihan>5);
		printf("\n\n\n\n\n (Press any button to continue)\n ");
		getch();
		system("cls");
		switch(pilihan){
			case 1:	
				num1();
				break;
			case 2:
				num2();
				break;
			case 3:
				num3();
				break;
			case 4:
				num4();	
				break;
		}
	}
	while(pilihan!=5);
	return 0;
}

void header(){
	printf("===================================================\n");
	printf("              RATE AND REVIEW PROGRAM\n");
	printf("===================================================\n\n\n");
}

int average(int a, int b){
	return a/b;
}
void movietitle(){
	for(i=0;i<3;i++){		
				printf("  %d. %s : %d%%\n\n",i+1,mov[i].title,mov[i].avg);
				if(mov[i].top>0){
					printf("     Latest review: %s\n",inp[i][mov[i].top].review);
				}
				printf("\n");
	}
}

void createEmpty(){
	for(i=0;i<3;i++){
		mov[i].top = 0;
	}
}

int isFull(int check){
	if(mov[check].top==max){
		return 1;
	}
	else{
		return 0;
	}
}

void num1(){
	header();
	movietitle();
	printf("\n Input your ID: ");
	scanf("%d",&idnum);
	printf("\n\n\n\n\n (Press any button to continue)\n ");
	getch();
	system("cls");
	do{
		do{
			do{
				header();
				movietitle();
				printf("\n Choose a movie (by number): ");		
				scanf("%d",&x);
				if(x<1||x>3){
					printf(" Wrong input!\n");
					printf("\n\n\n\n\n (Press any button to refresh)\n ");
					getch();
					system("cls");
				}
			}
			while(x<1||x>3);
			for (c = 0; c <= mov[x-1].top; c++){   								//revisi dari sebelumnya
		      	if (idnum==inp[x-1][c].id) {
					printf(" You've already rated this movie.\n"); 
		    	    printf("\n\n\n\n\n (Press any button to refresh)\n ");
					getch();
					system("cls");
					break;
		      }
			}
		}
		while(idnum==inp[x-1][c].id);
		isFull(mov[x-1].top);
		if(isFull(mov[x-1].top)==1){
			printf(" The program for this movie has already reached its limit.\n Please choose another movie.");
			printf("\n\n\n\n\n (Press any button to continue)\n ");
			getch();
			system("cls");
		}
	}
	while(isFull(mov[x-1].top)==1);
	printf("\n\n\n\n\n (Press any button to continue)\n ");
	getch();
	system("cls");
	
	mov[x-1].top++;
	inp[x-1][mov[x-1].top].id = idnum;
	do{
	header();
	printf(" [ %s ]",mov[x-1].title);
	printf("\n\n");
		printf("\n Give your rate (in scale 1 to 100): ");		
		scanf("%d",&rate);					
		if(rate<1||rate>100){
			printf(" Wrong input!\n");
			printf("\n\n\n\n\n (Press any button to refresh)\n ");
			getch();
			system("cls");
		}
	}
	while(rate<1||rate>100);
	inp[x-1][(mov[x-1].top)].rate = rate;
	mov[x-1].ttl += rate;
	getchar();
	printf("\n Give your review:\n ");
	fgets(inp[x-1][(mov[x-1].top)].review,1000,stdin);										
	mov[x-1].avg = average(mov[x-1].ttl,mov[x-1].top);
	printf("\n\n\n\n\n (Press any button to continue)\n ");
	getch();
	system("cls");	
}

void num2(){
	header();
	printf("  [ Movie reviews ]\n\n\n");
	for(i=0;i<3;i++){		
		printf("  %d. %s\n",i+1,mov[i].title);
		if(mov[i].top==0){
			printf("  No reviews\n\n");
		}
		else{
			for(j=1;j<=mov[i].top;j++){
				printf("  ID [%d]: %s",inp[i][j].id,inp[i][j].review);
			}
			printf("\n");
		}
	}
	printf("\n\n\n\n\n (Press any button to continue)\n ");
	getch();
	system("cls");
}

void num3(){
	header();
	printf("  [ Movie ratings ]\n\n\n");
	for(i=0;i<3;i++){		
		printf("  %d. %s\n",i+1,mov[i].title);
		if(mov[i].top==0){
			printf("  No user ratings\n\n");
		}
		else{
			for(j=1;j<=mov[i].top;j++){
				printf("  ID [%d]: %d%%\n",inp[i][j].id,inp[i][j].rate);
			}
			printf("\n");
		}
	}
	printf("\n\n\n\n\n (Press any button to continue)\n ");
	getch();
	system("cls");
}

void num4(){
	header();
	printf("  [ Movie rankings from BEST to WORST ]\n\n\n");
	char title2[3][100];
	for(i=0;i<3;i++){
		strcpy(title2[i],mov[i].title);
	}
	for(i=0;i<3;i++){
		avgPtr[i] = &mov[i].avg;
	}
	for(i=0;i<3;i++){
		maximum = i;
		for(j=i+1;j<3;j++){
			if(*avgPtr[j]>*avgPtr[maximum]){
				maximum = j;
			}
		}
		swap = avgPtr[i];						
		avgPtr[i] = avgPtr[maximum];			
		avgPtr[maximum] = swap;				
		strcpy(mov[0].swtitle,title2[i]);		
		strcpy(title2[i],title2[maximum]);
		strcpy(title2[maximum],mov[0].swtitle);
	}
	for(i=0;i<3;i++){		
				printf("  %d. %s : %d%%\n\n\n",i+1,title2[i],*avgPtr[i]);
	}
	printf("\n\n\n\n\n (Press any button to continue)\n ");
	getch();
	system("cls");
}
