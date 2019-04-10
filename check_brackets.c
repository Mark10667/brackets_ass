#include <string.h>
#include "stack.h"

int main() {
    int max_line = 105000;
	char input_buffer[max_line];
	int input_len = 0;

	fgets(input_buffer, max_line, stdin);
	input_buffer [strcspn (input_buffer, "\r\n")] = '\0';  //remove end-of-line characters

    input_len = strlen(input_buffer);
    printf("%d characters were read.\n",input_len);
    // printf("The input was: '%s'\n",input_buffer);
	fflush(stdout);
    Stack * opening_brackets_stack = createStack(max_line);
    for (int position = 0; position < input_len; ++position) {
        char next = input_buffer[position];
        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            Bracket top;
            if(next == '('){
              top.type = ROUND;
            }if(next == '['){
              top.type = SQUARE;
            }if(next == '{'){
              top.type = CURLY;
            }
            top.position = position;
            push(opening_brackets_stack, top);
        }

        if (next == ')' || next == ']' || next == '}') {
          // Process closing bracket, write your code here
          if(isEmpty(opening_brackets_stack)){
            printf("My result is: %d\n", position+1);
            return 1;
          }
          Bracket most_recent = pop(opening_brackets_stack);
          if((most_recent.type==ROUND && next!=')') || (most_recent.type==SQUARE && next!=']') || (most_recent.type==CURLY && next!='}')){
            printf("My result is: %d\n", position+1);
            return 1;
          }
        }
    }
    if(isEmpty(opening_brackets_stack)){
      printf("My result is Success\n");
      return 0;
    }else{
      printf("My result is: %d\n", (opening_brackets_stack->array[0]).position+1);
      return 1;
    }

    // Printing answer, write your code here
  free(opening_brackets_stack->array);
  free(opening_brackets_stack);
  return 0;
}
