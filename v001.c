#include <stdio.h>
#define MAXLINE 250

void clean(char* pn);

char userinput[MAXLINE] = {0};

int main() {
	printf("Enter your expression: ");
	fgets(userinput, MAXLINE, stdin);
	clean(userinput);
	printf("%s", userinput);

}

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
