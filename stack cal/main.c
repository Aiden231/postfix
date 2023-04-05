#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

// ���� �ʱ�ȭ
void init_stack(StackType* s)
{
	s->top = -1;
}

// ���� ���� �˻�
int is_empty(StackType* s)
{
	return (s->top == -1);
}

// ��ȭ ���� �˻�
int is_full(StackType* s)
{
	return(s->top == (MAX_STACK_SIZE - 1));
}

// �����Լ�
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else {
		s->top++;
		s->data[s->top] = item;
		return;
	}
}

//�����Լ�
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		return;
	}
	else return s->data[(s->top--)];
}

// ��ũ�Լ�
element peek(StackType* s)
{
	if (is_empty) {
		fprintf(stderr, "���� ���� ����\n");
		return;
	}
	else return s->data[s->top];
}

// ���� ǥ�� ���� ��� 
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

		// ������ ���
		if (ch >= '0' && ch <= '9') {
			value = ch - '0';
			push(&s, value);
		}

		// + - * / �� ���
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {

			// ������ ��� ���� ���
			if (is_empty(&s)) {
				fprintf(stderr, "���� ���� ����\n");
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
			fprintf(stderr, "Error ! �߸��� ���� �ֽ��ϴ�.\n");
			exit(1);
		}
	}

	return pop(&s);
}

int main()
{
	int result;
	char s1[10];

	printf("����ϰ� ���� ����ǥ����� �Է��ϼ���(�ִ�10��) : ");
	scanf_s("%9s", s1, sizeof(s1));

	result = eval(s1);
	printf("����� %d�̴�.\n", result);

	return 0;
}