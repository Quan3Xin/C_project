#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


	char* itoa(int value, char* result, int base) {
		// check that the base if valid
		if (base < 2 || base > 36) { *result = '\0'; return result; }

		char* ptr = result, *ptr1 = result, tmp_char;
		int tmp_value;

		do {
			tmp_value = value;
			value /= base;
			*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
		} while ( value );

		// Apply negative sign
		if (tmp_value < 0) *ptr++ = '-';
		*ptr-- = '\0';
		while(ptr1 < ptr) {
			tmp_char = *ptr;
			*ptr--= *ptr1;
			*ptr1++ = tmp_char;
		}
		return result;
	}
void gobble(float *a, int n, float *b);
int main()
{
   //float a[] = {123,4,1,4,4,23,44,4,32,4,4,4,4,123};
   int a = 1112;
    char b[10];
    itoa(a,b,2);
    printf("a->>>>>%s\n", b);
   char str;
    //int n=strspn(str,"0123456789.");
    printf("n ir -->>>%s\n", str);
    /*
    printf("n is -->>>%d\n", strlen(str));

    if(strlen(str) != n || strlen(str) == 0)
    {
    puts("存在非小数点和数字");
    }
    else 
    {
    puts("不存在非小数点和数字");
    }
    /*
   int size_a = sizeof(a) / sizeof(a[0]);
   float b[size_a-1];
   int c = 1;
   gobble(a, size_a, b);
   for(int i = 0; i < size_a ; i ++){
        printf("b value is -->>%0.2f\n", b[i]);
        if(c != 1) {
            b[i] = a[i];
        } else {
        
            b[i] = a[i] -1;
        }
        
        printf("end b value is -->>%0.2f\n", b[i]);
   }


  */ 
    return 0;

}

void gobble(float *a, int n ,float * b)
{
    for(int i = 0; i < n; i++){
        b[i] = a[i];
    }
}
