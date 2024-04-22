#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

const int DATA_ARRAY_SIZE = 30000;

void init_data_array(char *data_ptr)
{
     for (int i = 0; i < DATA_ARRAY_SIZE; i++) {
	  data_ptr[i] = 0;
     }
}

int main ()
{
     char *instruction_ptr;
     char *data_ptr;
     char *leftmost;

     instruction_ptr = "++++++++[>++++++++<-]>++++++++.>++++++++[>++++++++++++<-]>+++++.+++++++..+++.>++++++++[>+++++<-]>++++.----";
     
     leftmost = malloc(DATA_ARRAY_SIZE * sizeof(char));
     init_data_array(leftmost);

     data_ptr = leftmost;

     while (*instruction_ptr != '\0') {
	  switch (*instruction_ptr) {
	  case '>':
	       data_ptr++;
	       break;
	  case '<':
	       data_ptr--;
	       break;
	  case '+':
	       (*data_ptr)++;
	       break;
	  case '-':
	       (*data_ptr)--;
	       break;
	  case '.':
	       putchar(*data_ptr);
	       break;
	  case ',':
	       *data_ptr = getchar();
	       break;
	  case '[':
	       if (*data_ptr == 0) {
		    instruction_ptr++;
		    for (int stack = 1; stack > 0; instruction_ptr++) {
			 if (*instruction_ptr == '[') {
			      stack++;
			 } else if (*instruction_ptr == ']') {
			      stack--;
			 }
		    }
		    instruction_ptr--;
	       }
	       break;
	  case ']':
	       if (*data_ptr != 0) {
		    instruction_ptr--;
		    for (int stack = 1; stack > 0; instruction_ptr--) {
			 if (*instruction_ptr == '[') {
			      stack--;
			 } else if (*instruction_ptr == ']') {
			      stack++;
			 }
		    }
		    instruction_ptr++;
	       }
	       break;
	  }
	  instruction_ptr++;
     }

     free(leftmost);
     
     return 0;
}
