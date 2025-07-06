#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAXLINE 250//max size of user input;
#define SKIP 0.00005

void clean(char* pn);//clean arrey from spaces;
void form(char* pn);//formes arrey with 1 space bitwin words;
int digit(char c);//check if char is a digit, if true return a value from 0 to 9, else -1;
int incarr(char c, char* pn);//check if c is in array, 1 if true, else 0;
void copyarr(char* arr1, char* arr2);//copy arr1 to arr2;
int arrlen(char* pn);//returns length of the arrey;
void colektarguments(char* arr1, float* arr2);//colekts all of arguments in arr1 to arr2;
int countarguments(char* pn);//count arguments;
void fullwithzirow(float* pn, int length);//full array with 0;
float rd(float n);//rount number to 4 digits after koma;
float calculate(int len, float* exp, int start, int end);//calculate the result;

char userinput[MAXLINE] = {0};//user input;
char allowed_chars[] = {'^', '(', ')', '/', '*', '+', '-', '.', '\0'};//allowed operatorsi

int main()
{
	//get user input
	printf("Enter your expression: ");
	fgets(userinput, MAXLINE, stdin);
	clean(userinput);
	//printf("Formated: \"%s\"\n", userinput);
	int size = countarguments(userinput);
	//printf("Size: %d\n", size);
	float *expression = calloc(size, sizeof(float));//expression;
	//fullwithzirow(expression, size);
	colektarguments(userinput, expression);
	//printf("function is done\n");
	/*for (int i = 0; i < size; i++)
	{
		if (expression[i] == (float) SKIP)
		{
			continue;
		}
		printf("Argument: %f\n", expression[i]);
	}*/
	float result = calculate(size, expression, 0, size);
	printf("Result: %f\n", result);
	free(expression);
	return 0;

}
//clean arrey from spaces;
void clean(char* pn)
{
	int i, j;
	i = j = 0;
	for (i; i < MAXLINE && pn[i] != 0; i++)
	{
		if (pn[i] == ' ' || pn[i] == '\n')
		{
			j++;
			pn[i] = 0;
			continue;
		} pn[i-j] = pn[i];
	} for (int e = i - j; e <= i; e++)
	{
		pn[e] = 0;
	}
}

//formats arrey;
void form(char* pn)
{
	char clean_arr[MAXLINE] = {0};
	int j = 0;
	for (int i = 0; pn[i] != '\0' && i < MAXLINE && j < MAXLINE; i++)
	{
		if (digit(pn[i]) >= 0)
		{
			clean_arr[j++] = pn[i];
		}
		else if (incarr(pn[i], allowed_chars))
		{
			if (j > 0)
			{
				clean_arr[j++] = ' ';
			}
			clean_arr[j++] = pn[i];
			clean_arr[j++] = ' ';
		}
	} if (clean_arr[j] == ' ')
	{
		clean_arr[j] == 0;
	}
	copyarr(clean_arr, pn);
}

//check if c is digit, returns velue from 0 to 9 if true, else -1;
int digit(char c)
{
	if (c - '0' >= 0 && c - '0' <= 9)
	{
		return c - '0';
	}
	else
	{
		return -1;
	}
}

//check if c is in array, 1 if true, else 0;
int incarr(char c, char* pn)
{
	for (int i = 0; pn[i] != '\0'; i++)
	{
		if (pn[i] == c)
		{
			return 1;
		}
	} return 0;
}

//copy arr1 to arr2;
void copyarr(char* arr1, char* arr2)
{
	for (int i = 0; arr2[i] != 0; i++)
	{
		arr2[i] = '\0';
	} for (int j = 0; arr1[j] != '\0'; j++)
	{
		arr2[j] = arr1[j];
	}
}
//returns length of the arrey;
int arrlen(char* pn)
{
	int i;
	for (i = 0; pn[i] != 0; i++);
	return i;
}

//colekts all of arguments in arr1 to arr2;
void colektarguments(char* arr1, float* arr2)
{
	char io = 1;
	int c = 0;
	long afp = 0;
	for (int i = 0; arr1[i] != 0; i++)
	{
		//printf("char+1 == 0: %d\n", arr1[i+1] == 0);
		int d = digit(arr1[i]);
		if (d >= 0)
		{
			//printf("arr2[c]: %f\nrs: %f\nd: %d\n", arr2[c], rs, d);
			arr2[c] = arr2[c] * 10 + d;
			//if (io == 1 || io == 2) {c++;}
			io = 0;
			if (afp >= 1)
			{
				afp = afp * 10;
				//printf("afp: %ld\n", afp);
			}
		}
		if (incarr(arr1[i], allowed_chars) || arr1[i+1] == '\0' || arr1[i+1] == '\n')
		{
			if (arr1[i] == '.')
			{
				afp = 1;
				//printf("punkt\n");
			}
			else
			{
				if (afp > 0)
				{
					//printf("Exp: %f\n", arr2[c-2] + arr2[c] / afp);
					arr2[c-2] = rd(arr2[c-2] + arr2[c] / afp);
					arr2[c-1] = arr2[c] = (float) SKIP;//skip;
					//printf("N: %f\n", arr2[c-2]);
				}
				afp = 0;
			}
			if (io == 0) {c++;}
			arr2[c] = ((float) arr1[i]) / 1000000.0;
			c++;
			io = 1;
		}
	}
}

//count arguments;
int countarguments(char* pn)
{
	char io = 1;
	int c = 0;
	for (int i = 0; pn[i] != 0; i++)
	{
		if (incarr(pn[i], allowed_chars))
		{
				c++;
				io = 1;
		}
		else if (digit(pn[i]) >= 0)
		{
			if (io == 1)
			{
				c++;
			}
			io = 0;
		}
	} 
	//printf("Count: %d\n", c);
	return c;
}

//full array with 0;
void fullwithzirow(float* pn, int length)
{
	for (int i = 0; i < length; i++)
	{
		pn[i] = 0;
	}
}

float rd(float n)
{
        float e = n;
        int c = 0;
        while ((n/1.0) != (int) n/1 && c < 7)
	{
                if (c == 5)
		{
                        break;
                }
                n = n*10;
                c++;
        }//printf("c: %d\n", c);
        if (c <= 4)
	{
                return e;
        }
	else
	{
                while (c != 0)
		{
                        if (c == 4)
			{
                                if (n < (int) n + 0.5)
				{
                                        n = (int) n;
                                }
				else
				{
                                        n = (int) n + 1;
                                }
                        }
                        n = n / 10;
                        c--;
                }
        }
        return n;
}

//calculate the result;
float calculate(int len, float* exp, int start, int end)
{
	//printf("Start: %d, End: %d\n", start, end);
	int p = 0, l = 0;
	for (int i = start; i < end; i++)
	{
		int op1, op2;
		int counter;
		for (counter = i - 1; counter >= 0 && exp[counter] == (float) SKIP; counter--);
		op1 = counter;
		for (counter = i + 1; counter < len && exp[counter] == (float) SKIP; counter++);
		op2 = counter;
		if (exp[i] != (float) SKIP)
		{
			if (exp[i] == (float) '(' / 1000000)
			{
				exp[i] = (float) SKIP;
				for (int j = i+1; j < end; j++)
				{
					if ((float) exp[j] == (float) 0.00004) 
					{
						l++;
					}
					else if ((float) exp[j] == (float) 0.000041)
					{
						if (l==0)
						{
							calculate(j-i-1, exp, i+1, j-1);
							exp[j] = (float) SKIP;
							break;
						}
						l--;
					}
				}
				i = start;
			}
			else if (p == 0 && exp[i] == (float) '^' / 1000000)
			{
				exp[i] = rd((float) pow((double) exp[op1], (double) exp[op2]));
				exp[op1] = exp[op2] = (float) SKIP;
			}
			else if (p == 1 && exp[i] == (float) '*' / 1000000)
			{
                	        exp[i] = exp[op1] * exp[op2];
                	        exp[op1] = exp[op2] = (float) SKIP;
			}
			else if (p == 1 && exp[i] == (float) '/' / 1000000)
                	{
                	        exp[i] = exp[op1] / exp[op2];
                	        exp[op1] = exp[op2] = (float) SKIP;
                	}
			else if (p == 2 && exp[i] == (float) '+' / 1000000)
                	{
                	        exp[i] = exp[op1] + exp[op2];
                	        exp[op1] = exp[op2] = (float) SKIP;
                	}
			else if (p == 2 && exp[i] == (float) '-' / 1000000)
                	{
                	        exp[i] = exp[op1] - exp[op2];
                	        exp[op1] = exp[op2] = (float) SKIP;
                	}
		}
			if (!((i + 1) < end) && p <= 2)
			{
				i = start-1;
				p++;
			}

	}
	for (int e = start; e < end; e++)
	{
		if (exp[e] != (float) SKIP)
		{
			//printf("%f\n", exp[e]);
			return exp[e];
		}
	}
	return (float) SKIP;
}
