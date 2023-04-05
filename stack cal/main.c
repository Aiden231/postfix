#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

// 스택 초기화
void init_stack(StackType* s)
{
	s->top = -1;
}

// 공백 상태 검사
int is_empty(StackType* s)
{
	return (s->top == -1);
}

// 포화 상태 검사
int is_full(StackType* s)
{
	return(s->top == (MAX_STACK_SIZE - 1));
}

// 삽입함수
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else {
		s->top++;
		s->data[s->top] = item;
		return;
	}
}

//삭제함수
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		return;
	}
	else return s->data[(s->top--)];
}

// 피크함수
element peek(StackType* s)
{
	if (is_empty) {
		fprintf(stderr, "스택 공백 에러\n");
		return;
	}
	else return s->data[s->top];
}

// 후위 표기 수식 계산 
int eval(char exp[])
{
	int op1, op2, value, i = 0;
	int len = strlen(exp);
	char ch;

	StackType s;
	init_stack(&s);

	for (i = 0; i < len; i++)
	{
		ch = exp[i];

		// 숫자인 경우
		if (ch >= '0' && ch <= '9') {
			value = ch - '0';
			push(&s, value);
		}

		// + - * / 인 경우
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {

			// 스택이 비어 있을 경우
			if (is_empty(&s)) {
				fprintf(stderr, "스택 공백 에러\n");
				return 0;
			}

			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch) {
			case '+': push(&s, op1 + op2); break;
			case '-': push(&s, op1 - op2); break;
			case '*': push(&s, op1 * op2); break;
			case '/': push(&s, op1 / op2); break;
			}
		}

		else {
			fprintf(stderr, "Error ! 잘못된 값이 있습니다.\n");
			exit(1);
		}
	}

	return pop(&s);
}

int main()
{
	int result;
	char s1[10];

	printf("계산하고 싶은 후위표기식을 입력하세요(최대10개) : ");
	scanf_s("%9s", s1, sizeof(s1));

	result = eval(s1);
	printf("결과는 %d이다.\n", result);

	return 0;
}