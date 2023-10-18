#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_f - List representation of a stack (or queue)
 * @x: integer
 * @prev: Previous element of the stack (or queue)
 * @next: Next element of the stack (or queue)
 *
 * Description: Doubly linked list node structure
 */
typedef struct stack_f
{
	int x;
	struct stack_f *prev;
	struct stack_f *next;
} stack_t;
/**
 * struct bus_v - Variables -args, file, line content
 * @arg: Value
 * @txt: Pointer to monty file
 * @content: Line content
 * @lifi: Flag change stack <-> queue
 * Description: Carries values through the program
 */
typedef struct bus_v
{
	char *arg;
	FILE *txt;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;
/**
 * struct instruct_n - Opcode and its function
 * @opcode: The opcode
 * @r: Function to handle the opcode
 *
 * Description: Opcode and its function
 *
 */

typedef struct instruct_n
{
	char *opcode;
	void (*r)(stack_t **stack, unsigned int line_number);
} instruction_t;
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void f_push(stack_t **head, unsigned int number);
void f_pall(stack_t **head, unsigned int number);
void f_pint(stack_t **head, unsigned int number);
int execute(char *content, stack_t **head, unsigned int counter, FILE *txt);
void free_stack(stack_t *head);
void f_pop(stack_t **head, unsigned int counter);
void f_swap(stack_t **head, unsigned int counter);
void f_add(stack_t **head, unsigned int counter);
void f_nop(stack_t **head, unsigned int counter);
void f_sub(stack_t **head, unsigned int counter);
void f_div(stack_t **head, unsigned int counter);
void f_mul(stack_t **head, unsigned int counter);
void f_mod(stack_t **head, unsigned int counter);
void f_pchar(stack_t **head, unsigned int counter);
void f_pstr(stack_t **head, unsigned int counter);
void f_rotl(stack_t **head, unsigned int counter);
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void addnode(stack_t **head, int x);
void addqueue(stack_t **head, int x);
void f_queue(stack_t **head, unsigned int counter);
void f_stack(stack_t **head, unsigned int counter);
#endif
