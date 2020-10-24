#include <stdio.h>
#include <stdlib.h>

void swap(int array[] ,int neu[],int cnt){
	//Mit Pointern arbeiten, um Original-Array mit sortiertem Array zu ersetzen
	for(int i=0;i<cnt;i++){
			*(&array[i])=*(&neu[i]);
	}
}
int isSorted(int array[],int cnt){
	for(int i=1;i<cnt;i++){
		if(array[i-1]>array[i])return 0;
	}
	return 1;	
}
void fillCheck(int check[],int cnt){
		for(int i=0;i<cnt;i++){
			check[i]=1;
		}
}
void randomSort(int array[],int cnt){
	//ist das Array bereits sortiert oder nur 1 groß?
	if(cnt==1){
		printf("Array ist bereits sortiert.");
		return;
	}
	else if(isSorted(array,cnt)==1){
		printf("Array ist bereits sortiert.");
		return;
	}
	else{
		//Wir brauchen eine Kopie des A und ein Prüfarray für bereits gezogene Zahlen
		int neu[cnt];
		int check[cnt];
		
		do{
		//Prüfarray, um Zahlen zu entwerten
		fillCheck(check,cnt);

			for(int i=0;i<cnt;i++){
				int zufall;
				int weiter=1;
				//Suche eine Zahl zufällig aus dem Array, so lange bis eine noch nicht genutzt wurde
				while(weiter==1){
					zufall=rand()%cnt;
					
					if(check[zufall]!=0){
						neu[i]=array[zufall];
						weiter=0;
					}
					
				}
			
				//Entwerte die Stelle am Prüfarray
				check[zufall]=0;
				printf("%d ",neu[i]);

			}
			printf("\n");
		}while(isSorted(neu,cnt)==0);
		printf("Array fertig sortiert.");
		swap(array,neu,cnt);
	}

}


void main(){
	int array[]={25,10,38,8,-107,0,95};
	randomSort(array,sizeof(array)/sizeof(int));
	
}
