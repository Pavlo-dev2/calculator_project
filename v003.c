#include <stdio.h>
#define MAXLINE 250//max size of user input;

void clean(char* pn);//clean arrey from spaces;
void form(char* pn);//formes arrey with 1 space bitwin words;
int digit(char c);//check if char is a digit, if true return a value from 0 to 9, else -1;
int incarr(char c, char* pn);//check if c is in array, 1 if true, else 0;
void copyarr(char* arr1, char* arr2);//copy arr1 to arr2;
int arrlen(char* pn);//returns length of the arrey;
void colektarguments(char* arr1, float* arr2);//colekts all of arguments in arr1 to arr2;
int countarguments(char* pn);//count arguments;
void fullwithzirow(float* pn, int length);//full array with 0;

char userinput[MAXLINE] = {0};//user input;

int main() {
	//get user input
	printf("Enter your expression: ");
	fgets(userinput, MAXLINE, stdin);
	//clean(userinput);
	form(userinput);
	int size = countarguments(userinput);
	printf("Size: %d\n", size);
	float expression[size];//expression;
	fullwithzirow(expression, size);
	colektarguments(userinput, expression);
	for (int i = 0; i < size; i++) {
		printf("Argument: %f\n", expression[i]);
	}
	return 0;

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

//check if c is digit, returns velue from 0 to 9 if true, else -1;
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
//returns length of the arrey;
int arrlen(char* pn) {
	int i;
	for (i = 0; pn[i] != 0; i++);
	return i;
}

//colekts all of arguments in arr1 to arr2;
void colektarguments(char* arr1, float* arr2) {
	float rs = 1.0;
	int c = countarguments(arr1) - 1;
	for (int i = arrlen(arr1); i >= 0; --i) {
		int d = digit(arr1[i]);
		if (d > -1) {
			arr2[c] = arr2[c] + d * rs;
			printf("New element = %c\n", arr1[i]);
			rs = rs * 10;
		} else if (arr1[i] == ' ') {
			rs = 1.0;
			c--;
		}
	}
}

//count arguments;
int countarguments(char* pn) {
	char io = 0;
	int c = 0;
	for (int i = 0; pn[i] != 0; i++) {
		if (pn[i] != ' ') {
			if (io == 0) {
				c++;
			} io = 1;
		} else {
			io = 0;
		}
	} return c;
}

//full array with 0;
void fullwithzirow(float* pn, int length) {
	for (int i = 0; i < length; i++) {
		pn[i] = 0;
	}
}
