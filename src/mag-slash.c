/*
 * MAG-SLASH - Magnetic Card reader 
 * Douglas Berdeaux - WeakNetLabs.com
 *
 * Tested with MSR100 from POSMATE
 * http://www.amazon.com/gp/product/B00E85TH9I
 */
#include<stdio.h>
#define MAX_LEN 250 // max length for mag string in bytes
#define NAME_OFFSET 19 // offset to cardholder's name in string
void luhn(unsigned short *ccNum);
void printString(unsigned short *pi,char *pstring, int c); // prototype
int main(void){ //main entry point for application
	printf("Swipe Card now: "); // ask for input
	unsigned char string[MAX_LEN]; // long byte length for variable cards
	fgets(string,MAX_LEN,stdin); // get string from card reader
	if(string[1] == 'E'){ // an error occured if format code is "E"
		printf("Track 1 returned an error\n");
	}else{ // no error for track 1, is it a credit card?
		if(string[1] == 'B'){ // format code of B for financial/bank
			unsigned short ccNums[16]; // array to pass to luhn for checking
			unsigned short k=0; 
			unsigned short j=0; // counter for pushing elements to array ccNums[]
			for(int j=2;j<=18;j++){
				ccNums[k]=string[j] - '0';
				k++;
			}
			luhn(ccNums); // verify the card number
			printf("PAN: %.16s\n",string+2); // print CC#
			printf("NAME: "); // print the name
			//register unsigned short i=NAME_OFFSET; // store counter in CPU register
			unsigned short i=NAME_OFFSET; // store counter in CPU register
			while(string[i]!='^'){ // the FS
				printf("%c",string[i]);
				i++;
			}
			// Get expiration date:
			i++; // We still have the register counter. get rid of FS, ^
			if(string[i]!='='){ // financial ID cards
				printf("\nEXPR: 20");
				printString(&i,string,2);
				printf("/"); // separate the date
				printString(&i,string,2);
			}
			printf("\n"); // newline after last string
		}else{
			printf("Could not determine card type.\n");
			return 1;
		}
	}
	return 0;
} 
// print some chars from array pointer, string[]
void printString(unsigned short *pi,char *pstring, int c){
	for(int k=0;k<c;k++){ // loop and print this many chars
		printf("%c",pstring[*pi]);
		(*pi)++; // increment the original pointer, i from main()
	}
	return;
}
// Luhn Algorithm for verification
void luhn(unsigned short *ccNum){
	// add them all up
	unsigned int sum = 0;
	for(int i=1;i<16;i++){
		if(i%2==0){ // every other number gets doubled
			sum += ccNum[i]*2;
		}else{
			sum += ccNum[i];
		}
	}
	if(sum%10==0){ // if it's a multiple of 10, it's probably an actual number
		printf("PAN has been verified\n");
	}else{
		printf("PAN # is invalid, Try swiping again\n");
	}
	return;
}
