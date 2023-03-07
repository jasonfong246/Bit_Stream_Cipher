/*  BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
    WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS 
    FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR 
    OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF 
    THE OHIO STATE UNIVERSITY' ACADEMIC INTEGRITY POLICY.
    THIS IS THE README FILE FOR LAB 2.

    Student name: Jason Fong Shen Yik
*/
#include <stdio.h>

int main()
{
	int char_value;
	int i=0,x=1,j=0,z=1,length,bitNum=0,count=0,leftBit,rightBit;
	char textArr[200]; /* Maximum of 200 letter length */
	int out =0;
	#ifdef PROMPT
	printf("Enter a clear text: ");
	#endif
	while(char_value!= '\n'){
	    char_value = getchar();
		if (char_value != '\n' && char_value!= EOF){				
			textArr[i]=(char)char_value;	 /* inputs each character into an array */	
		}
	    i++;
	}
	length = i;
	#ifdef PROMPT
	printf("The text entered is: ");
	while(j<length){
		putchar(textArr[j]);
		j++;
	}
	printf("\nThe hexadecimal text is: ");
	while(z<length){
		printf("%02X ", textArr[z-1]);
		z++;
	}
	#endif
	char_value='a';
	#ifdef PROMPT
	printf("\nEnter your 4-bit value : ");
	#endif
    while(char_value!='\n' && char_value!=EOF){
        char_value=getchar();
        if(char_value == '1'){ 
            leftBit=rightBit=1; /* takes the first bit as value "1"*/
            leftBit=1<<count;  
            rightBit=1<<(count+4); /* shifts 1 bit to left by 4 times + count value*/
        }
        if(char_value =='0'){
            leftBit=rightBit=0; 
        }
        bitNum= bitNum|leftBit|rightBit; /* byte numbers are changed according to leftBigt and Rightbit of the byte*/
        count++;
    }
	#ifdef PROMPT
	printf("Hexadecimal cipher text is: \n");
	#endif
	while(x<length){
		int cipher=textArr[x-1]^bitNum ; /* prints the hexadecimal value of the cipher text*/
        printf("%02X ",cipher); 
		if(x%10==0){
			printf("\n");
		}
		x++;
	}   
	printf("\n");
    return 0;
}

