#include <stdio.h>
#define MAXLINE 250//max size of user input;

void clean(char* pn);//clean arrey from spaces;
void form(char* pn);//formes arrey with 1 space bitwin words;
int digit(char c);//check if char is a digit, if true return a value from 0 to 9, else -1;
int incarr(char c, char* pn);//check if c is in array, 1 if true, else 0;
void copyarr(char* arr1, char* arr2);//copy arr1 to arr2;

char userinput[MAXLINE] = {0};//user input;

int main() {
	//get user input
	printf("Enter your expression: ");
	fgets(userinput, MAXLINE, stdin);
	//clean(userinput);
	//form(userinput);
	printf("%s\n", userinput);

}
//clean arrey from spaces;
void clean(char* pn) {
	int i, j;
	i = j = 0;
	for (i; i < MAXLINE && pn[i] != 0; i++) {
		if (pn[i] == ' ') {
			j++;
			pn[i] = 0;
			continue;
		} pn[i-j] = pn[i];
	} for (int e = i - j; e <= i; e++) {
		pn[e] = 0;
	}
}

//formats arrey;
void form(char* pn) {
	char clean_arr[MAXLINE] = {0};
	int j = 0;
	char allowed_chars[] = {'^', '(', ')', '/', '*', '+', '-', '.', '\0'};
	for (int i = 0; pn[i] != '\0' && i < MAXLINE && j < MAXLINE; i++) {
		if (digit(pn[i]) >= 1) { //incarr(pn[i], allowed_chars)) {
			clean_arr[j++] = pn[i];
		} else if (incarr(pn[i], allowed_chars)) {
			clean_arr[j++] = ' ';
			clean_arr[j++] = pn[i];
			clean_arr[j++] = ' ';
		}
	} 
	copyarr(clean_arr, pn);
}

//check if c is in array, 1 if true, else 0;
int digit(char c) {
	if (c - '0' > 0 && c - '0' < 9) {
		return c - '0';
	} else {
		return -1;
	}
}

//check if c is in array, 1 if true, else 0;
int incarr(char c, char* pn) {
	for (int i = 0; pn[i] != '\0'; i++) {
		if (pn[i] == c) {
			return 1;
		}
	} return 0;
}

//copy arr1 to arr2;
void copyarr(char* arr1, char* arr2) {
	for (int i = 0; arr2[i] != 0; i++) {
		arr2[i] = '\0';
	} for (int j = 0; arr1[j] != '\0'; j++) {
		arr2[j] = arr1[j];
	}
}
