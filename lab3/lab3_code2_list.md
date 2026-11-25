# Програма 2: Стек на основі однозв'язного списку

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


#define BUF_SIZE 256


/* Stack */


typedef struct Node {
   char val;
   struct Node *next;
} Node;


typedef struct {
   Node *top;
} Stack;


void init(Stack *s) {
   s->top = NULL;
}


bool is_empty(const Stack *s) {
   return s->top == NULL;
}


bool is_full(const Stack *s) {
   (void)s;
   return false;
}


bool push(Stack *s, char c) {
   Node *node = (Node *)malloc(sizeof(Node));
   if (node == NULL) {
       printf("Error: push failed, memory allocation error.\n");
       return false;
   }
   node->val = c;
   node->next = s->top;
   s->top = node;
   return true;
}


bool pop(Stack *s, char *out) {
   if (is_empty(s)) {
       printf("Error: pop failed, stack is empty.\n");
       return false;
   }
   Node *tmp = s->top;
   *out = tmp->val;
   s->top = tmp->next;
   free(tmp);
   return true;
}


bool peek(const Stack *s, char *out) {
   if (is_empty(s)) {
       return false;
   }
   *out = s->top->val;
   return true;
}


void clear_stack(Stack *s) {
   char dummy;
   while (!is_empty(s)) {
       pop(s, &dummy);
   }
}


/* Application Logic */


int precedence(char op) {
   if (op == '+' || op == '-') return 1;
   if (op == '*' || op == '/') return 2;
   return 0;
}


bool is_operator(char c) {
   return c == '+' || c == '-' || c == '*' || c == '/';
}


bool infix_to_postfix(const char *infix, char *postfix, size_t out_size) {
   Stack s;
   init(&s);


   size_t i = 0;
   size_t k = 0;
   char top_ch;


   while (infix[i] != '\0') {
       if (isspace((unsigned char)infix[i])) {
           i++;
           continue;
       }


       if (isalnum((unsigned char)infix[i]) || infix[i] == '.') {
           while (isalnum((unsigned char)infix[i]) || infix[i] == '.') {
               if (k + 2 >= out_size) {
                   printf("Error: output buffer overflow.\n");
                   clear_stack(&s);
                   return false;
               }
               postfix[k++] = infix[i++];
           }
           postfix[k++] = ' ';
       } else if (infix[i] == '(') {
           if (!push(&s, '(')) {
               clear_stack(&s);
               return false;
           }
           i++;
       } else if (infix[i] == ')') {
           bool found_open = false;
           while (pop(&s, &top_ch)) {
               if (top_ch == '(') {
                   found_open = true;
                   break;
               }
               if (k + 2 >= out_size) {
                   printf("Error: output buffer overflow.\n");
                   clear_stack(&s);
                   return false;
               }
               postfix[k++] = top_ch;
               postfix[k++] = ' ';
           }
           if (!found_open) {
               printf("Error: mismatched closing parenthesis ')'.\n");
               clear_stack(&s);
               return false;
           }
           i++;
       } else if (is_operator(infix[i])) {
           char cur = infix[i];
           while (peek(&s, &top_ch) && is_operator(top_ch) &&
                  precedence(top_ch) >= precedence(cur)) {
               pop(&s, &top_ch);
               if (k + 2 >= out_size) {
                   printf("Error: output buffer overflow.\n");
                   clear_stack(&s);
                   return false;
               }
               postfix[k++] = top_ch;
               postfix[k++] = ' ';
           }
           if (!push(&s, cur)) {
               clear_stack(&s);
               return false;
           }
           i++;
       } else {
           printf("Error: invalid character '%c' in expression.\n", infix[i]);
           clear_stack(&s);
           return false;
       }
   }


   while (!is_empty(&s)) {
       pop(&s, &top_ch);
       if (top_ch == '(') {
           printf("Error: mismatched opening parenthesis '('.\n");
           clear_stack(&s);
           return false;
       }
       if (k + 2 >= out_size) {
           printf("Error: output buffer overflow.\n");
           clear_stack(&s);
           return false;
       }
       postfix[k++] = top_ch;
       postfix[k++] = ' ';
   }


   if (k > 0 && postfix[k - 1] == ' ') {
       k--;
   }
   postfix[k] = '\0';
   return true;
}


int main(void) {
   char infix[BUF_SIZE];
   char postfix[BUF_SIZE * 2];


   printf("Enter infix expression: ");
   if (fgets(infix, sizeof(infix), stdin) == NULL) {
       return 1;
   }
   infix[strcspn(infix, "\r\n")] = '\0';


   if (infix[0] == '\0') {
       Stack empty_test;
       char dummy;
       init(&empty_test);
       printf("Empty expression. Testing pop on empty stack:\n");
       pop(&empty_test, &dummy);
       return 1;
   }


   if (infix_to_postfix(infix, postfix, sizeof(postfix))) {
       printf("Postfix expression: %s\n", postfix);
       return 0;
   }
   return 1;
}
```
