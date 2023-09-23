#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#define SIZE 10000

void wordsearch(char *sent, char *find){
	int n;
	char *ptr;
	ptr=strstr(sent,find);
	while(ptr!=NULL){
		n++;
		ptr=strstr(ptr+1,find);
	}
	printf("%d %s found in the text.\n",n,find);
}

void printword(char *sent){
	char *ayrac=" ";
	char *ptr;
	ptr= strtok(sent,ayrac);
	while(ptr!=NULL){
		printf("%s,",ptr);
		ptr=strtok(NULL,ayrac);//NULL is sent to continue with the same text.
	}
}

void palatalharmony(char *sent){ 
	char strong[]="aýouAIOU";
	char thin[]="eiöüEÝÖÜ";
	char vowel[17]="aeiouöüAEIOUÖÜ";
	int i=0,k=0,number=0,m=0;
	int nustrong=0,nuthin=0;
	while(sent[i]!='\0'){
		int start=i,end=i;
		while(sent[end]!=' '){ //Breaks down the text into individual words
			end++;
			if(sent[end]=='\0'){
				break;	
			}
		}
		end++;
		nuthin=0;nustrong=0;
		for(k=start;k<end;k++){
			if(strchr(strong,sent[k])!=NULL){ //Counts the vowels "a,ý,o,u" in the word
				nustrong++; 
			}
		}
		for(k=start;k<end;k++){
			if(strchr(thin,sent[k])!=NULL){ //Counts the vowels "e,i,ö,ü" in the word
				nuthin++;
			}	
		}
		if(m==0){
			printf("\nPalatal harmony words:");
		}
		m++;
		
		if((nustrong>0&&nuthin==0) || (nuthin>0&&nustrong==0) ){ //The letters must be in one of two groups to comply with the rule
			number++;
			for(k=start;k<end;k++){//Print the words that comply with the rule.
				printf("%c",sent[k]);
			}
			printf(",");
		}

		i=end;
	}
	printf(".%d palatal harmony found.\n",number);
	
}

void labialharmony(char *sent){ 
	char x[]="aeýiAEIÝ";
	char y[]="oöuüOÖUÜ";
	char z[]="aeuüAEUÜ";
	char q[]="oöýiOÖIÝ";
	int i=0,k=0,number=0,a=0,b=0,c=0,m=0,p=0;
	while(sent[i]!='\0'){
		int start=i,end=i;
		while(sent[end]!=' '){ //Checks that it complies with the rule by dividing the text into words
			end++;
			if(sent[end]=='\0'){
				break;	
			}
		}
		end++;
		
		for(k=start;k<end;k++){
			if(strchr(x,sent[k])!=NULL){ //If the first vowel is either one of "a,e,ý,i" the other vowels must be too.
				m=k+1;//To move to the next vowel
				for(m;m<end;m++){
					if(strchr(x,sent[m])!=NULL){ 
						a++;
					}
					else if(strchr(y,sent[m])!=NULL){
						c++;
					}
				}
				break;
			}
			
			if(strchr(y,sent[k])!=NULL){//If the first vowel is "o,ö,u,ü", the other vowels must be "a,e,u,ü".
				m=k+1;
				for(m;m<end;m++){
					if(strchr(z,sent[m])!=NULL){
						b++;
					}
					else if(strchr(q,sent[m])!=NULL){
						c++;
					}
				}
				break;
			}
		}
		
		if(p==0){
			printf("\nLabial harmony words:");
		}
		p++;
		
		if((a>0&&c==0) || (b>0&&c==0) ){ //It compares the number of vowels to check whether it follows the rule or not.
			number++;
			for(k=start;k<end;k++){
				printf("%c",sent[k]);
			}
			printf(",");
		}

	i=end;
	}

	printf("%d labial harmony found.\n",number);
}

void strongsoft(char *sent){
	char strong[9]="fstkçþhp";
	char changed[5]="pçtk";
	char print[SIZE];
	int i=0,n=0,k=0,m=0;
	int end,start;
	
	while(sent[i]!='\0'){
		end=i;start=i;
		while(sent[end]!=' '){ 
			end++;
			if(sent[end]=='\0'){
				break;
			}
		}
		end++;
		if(m==0){
			printf("\nStrong-soft words:");
		}
		m++;
		for(k=start;k<end;k++){
			if((strchr(strong,sent[k])!=NULL) && (strchr(changed,sent[k+1])!=NULL)){ 
				n++;
				for(k=start;k<end;k++){ // print the words that comply with the rule.
				printf("%c",sent[k]);
				}
				printf(",");
			}
		}
		i=end;
	}
	
	printf("%d strong-soft words found.\n",n);

}

int numberofword(char *word){ 
	int i=0;
	int number=1;//The word count must be initialized with an extra, as the code counts the number of spaces.
	while(word[i]!='\0'){
		if(word[i]==' '){ //It is assumed that the text is written correctly.
			number++;
		}
		i++;
	}
	return number;
}

int numberofsent(char *sent){ 
	int i=0;
	int number=0;
	while(sent[i]!='\0'){
		if((sent[i]=='.') || (sent[i]=='?') || (sent[i]=='!') ){
			number++;
		}
		i++;
	}
	return number; 
}

int numberoflet(char *let){
	int i=0;
	int number=0;
	while(let[i]!='\0'){
		if(isalpha(let[i])){ //Checks if the character is a letter
			number++;
		}
		i++;
	}
	return number;
}

void connexion(char *sent){ 
	char vowel[17]="aeiýouöüAEIÝOUÖÜ";
	char consonant[43]="bcçdfgðhjklmnprsþtvyzBCÇDFGÐHJKLMNPRSÞTVYZ";
	int i=0,n=0,k=0,a,m=0;
	int end=0,start=0;
	
	while(sent[i]!='\0'){
		end=i;start=i;
			while(sent[end]!=' '){ 
			end++;
			if(sent[end]=='\0'){
				break;
			}
		}
		end++;
		if(m==0){
			printf("\nConnexion:");
		}
		m++;
		for(k=start;k<end;k++){
			if((strchr(consonant,sent[k])!=NULL) && (sent[k+1]==' ') && (strchr(vowel,sent[k+2])!=NULL)){ //The vowel that comes after the consonant is connexion
				n++;
				for(k=start;k<end;k++){
					printf("%c",sent[k]);
				}
				for(k;sent[k]!=' ';k++){
					if(sent[k]=='\0'){
						break;
					}	
					printf("%c",sent[k]);
				}
				printf(",");
			}
		}
		i=end;
	}
	printf("\n%d connexion found.\n",n);
	printf("\n");
}

void plural(const char *sent){
	int i=0,n=0,k=0,m=0;
	int end,start;
	char print[SIZE];
	
	while(sent[i]!='\0'){
		end=i;start=i;
		while(sent[end]!=' '){
			end++;
			if(sent[end]=='\0'){
				break;
			}
		}
		end++;
		if(m==0){
			printf("\nPlural words:");
		}
		m++;
		for(k=start;k<end;k++){
			if((sent[k]=='l') && (sent[k+1]=='a'|| sent[k+1]=='e') && (sent[k+2]=='r')){ //Roughly checks words.
				n++;
				for(k=start;k<end;k++){ //print the words that comply with the rule.
				printf("%c",sent[k]);
				}
				printf(",");
			}
		}
		i=end;
	}
	printf("%d plural words found.",n);
	printf("\n");

}
	
int main(){
	setlocale(LC_ALL,"Turkish");
	char text[SIZE];
	char choice[SIZE];
	char find[SIZE];
	int a;
	
	printf("Welcome to the grammar rule program.\nEnter the text from keyboard:\n");
	fgets(text,SIZE,stdin);
	printf("\n\nI'M CHECKING FOR: Connexion, labial-palatal harmony, hard-soft vowels, plural words, number of words, number of sentences,\nnumber of letters, etc.\nIs there a rule you want checked?\n\n");
	printf("1.connexion\n2.palatalharmony\n3.labialharmony\n4.strongsoftvowel\n5.pluralwords\n6.numberofwords\n7.numberofsentences\n8.numberofletters\n9.wordsearch\n");
	
	
	do{
	printf("\nType the name of the rule you want without spaces. Example : numberofwords\nYour choice is:");
	scanf("%s",choice);
	if(strcmp(choice,"connexion")==0){ //Since the selection received from the user is a array, it is compared with strcmp and the appropriate function is provided to work.
		connexion(text);
	}
	else if(strcmp(choice,"palatalharmony")==0){
		palatalharmony(text);
	}
	else if(strcmp(choice,"labialharmony")==0){
		labialharmony(text);
	}
	else if(strcmp(choice,"strongsoftvowel")==0){
		strongsoft(text);
	}
	else if(strcmp(choice,"pluralwords")==0){
		plural(text);
		printf("\n");
	}
	else if(strcmp(choice,"numberofwords")==0){
		printf("%d words found.\n",numberofword(text));
	}
	
	else if(strcmp(choice,"numberofsentences")==0){
		printf("%d sentences found.\n",numberofsent(text));
	}
	else if(strcmp(choice,"numberofletters")==0){
		printf("%d letters found.\n",numberoflet(text));
	}
	else if(strcmp(choice,"wordsearch")==0){
		printf("Enter the word you want to search in the text.\n");
		scanf("%s",find);
		wordsearch(text,find);
	}
	else{
		printf("\nPlease write correctly.\n");
	}
	
	printf("\nDo you want to continue the program?\nIf you wish to close the program, enter 0.\nIf you wish to continue, enter 1.\n");
	scanf("%d",&a);
	}while(a>0);

	
	return 0;
}
