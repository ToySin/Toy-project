/**********************************
�ּ� �ۼ� ���

//
//(������ ����)
//
(�������)

**********************************/
#include <stdio.h>
#include <stdlib.h>
//
//�������� �����ϴ� ����ü
//
typedef struct Variable
{
	int val[26];
}Variable;
//
//�������� 0���� �ʱ�ȭ��
//
void set_variable(Variable* variable)
{
	for (int i = 0; i < 26; i++)
		variable->val[i] = 0;
}
//
//char�� int���� �ִ� ���Ͽ�����
//
typedef struct Node
{
	char elem;
	int num;
	struct Node* next;
}Node;
//
//top��带 ����Ű�� Stack����ü
//
typedef struct Stack
{
	Node* top;
}Stack;
//
//�� ��� �Ҵ�
//
Node* getnode()
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->next = NULL;
	return node;
}
//
//���ڸ� ���ÿ� �־��ش�
//
void push_c(Stack * stack, char c)
{
	Node* node = getnode();
	node->elem = c;
	node->next = stack->top;
	stack->top = node;
}
//
//������ ���ÿ� �־��ش�
//
void push_n(Stack * stack, int n)
{
	Node* node = getnode();
	node->elem = '\0';
	node->num = n;
	node->next = stack->top;
	stack->top = node;
}
//
//���ÿ��� ���ڸ� ������
//
char pop_c(Stack * stack)
{
	char p = stack->top->elem;
	Node* t = stack->top;
	stack->top = stack->top->next;
	free(t);
	return p;
}
//
//���ÿ��� ������ ������
//
int pop_n(Stack * stack)
{
	int n = stack->top->num;
	Node* t = stack->top;
	stack->top = stack->top->next;
	free(t);
	return n;
}
//
//ž����� ���ڸ� Ȯ���Ѵ�
//
char peek_c(Stack * stack)
{
	return stack->top->elem;
}
//
//ž����� ������ Ȯ���Ѵ�
//
int peek_n(Stack * stack)
{
	return stack->top->num;
}
//
//�������� �켱������ ��ȯ�Ѵ�
//
int get_rank(char s)
{
	/****************************************

	p -> +=	m -> -=	d -> *=	n -> %=
	| -> ||	& -> &&
	e -> ==	o -> !=
	r -> <=	l -> >=
	k -> +	b -> -	s -> !

	****************************************/
	if (s == '=' || s == 'p' || s == 'm' || s == 'd' || s == 'n')
		return 1;
	else if (s == '|')
		return 2;
	else if (s == '&')
		return 3;
	else if (s == 'e' || s == 'o')
		return 4;
	else if (s == '<' || s == '>' || s == 'r' || s == 'l')
		return 5;
	else if (s == '-' || s == '+')
		return 6;
	else if (s == '/' || s == '*' || s == '%')
		return 7;
	else if (s == 'k' || s == 'b' || s == '!')
		return 8;
	else if (s == '(' || s == ')')
		return 0;
	else
		return -1;
}
//
//���������� ������������ ��ȯ�Ѵ�
//
char* convert(char* str)
{
	//
	//�����ڰ� �� ����
	//
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->top = NULL;
	//
	//���� Ȯ���� ����
	//
	char s = '\0';
	int idx = 0;
	//
	//���������� ����� �����Ͱ�
	//
	char* aka = (char*)malloc(101 * sizeof(char));
	//
	//aka�� index a
	//
	int a = 0;

	while (str[idx])
	{
		//
		//�ǿ������� ���
		//
		if (get_rank(str[idx]) == -1)
			s = str[idx];
		//
		//+=, -=, *=, ==, !=, >=, <=�� ���
		//str[idx] != ')' �� (A+=5)=7�� ���� ��츦 ����ϱ� ����
		//���� �ΰ��� �̷���� �������̹Ƿ� idx++;�� ���ش�
		//
		else if (str[idx + 1] == '=' && str[idx] != ')')
		{
			if (str[idx] == '+')
			{
				idx++;
				s = 'p';
			}
			else if (str[idx] == '-')
			{
				idx++;
				s = 'm';
			}
			else if (str[idx] == '*')
			{
				idx++;
				s = 'd';
			}
			else if (str[idx] == '%')
			{
				idx++;
				s = 'n';
			}
			else if (str[idx] == '=')
			{
				idx++;
				s = 'e';
			}
			else if (str[idx] == '!')
			{
				idx++;
				s = 'o';
			}
			else if (str[idx] == '<')
			{
				idx++;
				s = 'r';
			}
			else if (str[idx] == '>')
			{
				idx++;
				s = 'l';
			}
		}
		//
		//||�� &&�� ���
		//
		else if (str[idx] == '|')
		{
			idx++;
			s = str[idx];
		}
		else if (str[idx] == '&')
		{
			idx++;
			s = str[idx];
		}
		//
		//���׿����ڿ� ���� ��ȣ�� ���
		//
		else if (idx == 0 || str[idx - 1] != ')' && get_rank(str[idx - 1]) != -1)
		{
			if (str[idx] == '+')
				s = 'k';
			else if (str[idx] == '-')
				s = 'b';
			else if (str[idx] == '!')
				s = '!';
			else if (str[idx] == '(')
				s = '(';
		}
		//
		//�׿��� ���
		//
		else
			s = str[idx];
		//
		//�ǿ������� ��� �ٷ� �������Ŀ� �־��ش�
		//
		if (get_rank(s) == -1)
			aka[a++] = s;
		//
		//���� ��ȣ�� ��� �ٷ� ���ÿ� �־��ش�
		//
		else if (s == '(')
			push_c(stack, s);
		//
		//�ݴ� ��ȣ�� ��� ���� ��ȣ�� ������ ������ ������ش�
		//
		else if (s == ')')
		{
			while (peek_c(stack) != '(')
				aka[a++] = pop_c(stack);
			//
			//���� ��ȣ�� ���ÿ��� �����Ѵ�
			//
			pop_c(stack);
		}
		//
		//������ �����ں��� ���� �������� �켱������ �������
		//���ÿ� ���� �����ڸ� �־��ش�
		//
		else if (stack->top == NULL || get_rank(peek_c(stack)) < get_rank(s))
			push_c(stack, s);
		//
		//������ �����ں��� ���� �������� �켱������ �������
		//
		else
		{
			//
			//���� �����ں��� ���������� �����ڰ� ���ö�����
			//�������Ŀ� �߰����ش�
			//
			while (stack->top != NULL && get_rank(peek_c(stack)) >= get_rank(s))
			{
				//
				//�� ���չ����� �������� ����, ���Կ����ڴ� �����Ѵ�
				//
				if (get_rank(peek_c(stack)) == get_rank(s))
					if (get_rank(s) == 8 || get_rank(s) == 1)
						break;
				aka[a++] = pop_c(stack);
			}
			//
			//���� �����ڸ� ���ÿ� �־��ش�
			//
			push_c(stack, s);
		}
		idx++;
	}
	//
	//���ÿ� ���� �����ڸ� �������Ŀ� �߰����ش�
	//
	while (stack->top)
		aka[a++] = pop_c(stack);
	free(stack);
	//
	//���������� ���� ���ڿ��� ���� ǥ�����ش�
	//
	aka[a] = '\0';
	//
	//���������� �����͸� ��ȯ�Ѵ�
	//
	return aka;
}
//
//�ٲ㼭 �������� �����ڸ� �ٽ� ������� ����Ѵ�
//
void print(char* str)
{
	int idx = 0;
	while (str[idx])
	{
		//
		//�ǿ������� ��� �ٷ� ���
		//�ٲ��� �������� ��� ������� ���
		//�ٲ����� ���� �����ڴ� �ٷ� ���
		//
		if (get_rank(str[idx]) == -1)
			printf("%c", str[idx]);
		else if (str[idx] == 'r')
			printf("<=");
		else if (str[idx] == 'l')
			printf(">=");
		else if (str[idx] == 'e')
			printf("==");
		else if (str[idx] == 'o')
			printf("!=");
		else if (str[idx] == '&')
			printf("&&");
		else if (str[idx] == '|')
			printf("||");
		else if (str[idx] == 'p')
			printf("+=");
		else if (str[idx] == 'm')
			printf("-=");
		else if (str[idx] == 'd')
			printf("*=");
		else if (str[idx] == 'n')
			printf("%%=");
		else if (str[idx] == 'p')
			printf("+");
		else if (str[idx] == 'k')
			printf("+");
		else if (str[idx] == 'b')
			printf("-");
		else
			printf("%c", str[idx]);
		idx++;
	}
	printf("\n");
}
//
//���������� ����Ѵ�
//
int evaluate(char* str, Variable * v)
{
	//
	//�ǿ����ڰ� �� ����
	//
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->top = NULL;
	int idx = 0;
	//
	//� ���������� �����Ѵ�
	//
	char tmp;
	//
	//����� ���ڸ� �����Ѵ�
	//
	int a, b;
	//
	//����� ����� �����Ѵ�
	//
	int result;

	while (str[idx])
	{
		//
		//������ �ƴѰ�� node->elem�� '\0'�� �����ϰ��ϰ�
		//������ ��� node->elem�� ���� ���ڸ� �����ϴ� ����� �����
		//
		tmp = '\0';
		//
		//�ǿ������� ���
		//
		if (get_rank(str[idx]) == -1)
		{
			//
			//������ ���
			//��忡 �������� ����
			//
			if (str[idx] >= 'A' && str[idx] <= 'Z')
			{
				push_n(stack, v->val[str[idx] - 'A']);
				stack->top->elem = str[idx];
			}
			//
			//����� ���
			//��忡 '\0'�� ����
			//push_n()�Լ����� �׷��� �ϵ��� ������
			//
			else
				push_n(stack, str[idx] - '0');
		}
		//
		//���Կ������� ���
		//���� �����ϴ� ����� �������
		//tmp�� ������ �̸��� �����صд�
		//������-'A'�� ���� ������ ������ ����Ͽ�
		//variable���� ��������ش�
		//���� ���ο� ��带 ����� ���� �����ϰ�
		//�� ��尡 �������� �������ش� (stack->top->elem = tmp;)
		//
		else if (get_rank(str[idx]) == 1)
		{
			if (str[idx] == '=')
			{
				b = pop_n(stack);
				if (peek_c(stack) >= 'A' && peek_c(stack) <= 'Z')
				{
					v->val[peek_c(stack) - 'A'] = b;
					tmp = peek_c(stack);
				}
				a = pop_n(stack);
				push_n(stack, b);
				stack->top->elem = tmp;
			}
			else if (str[idx] == 'p')
			{
				b = pop_n(stack);
				if (peek_c(stack) >= 'A' && peek_c(stack) <= 'Z')
				{
					v->val[peek_c(stack) - 'A'] += b;
					tmp = peek_c(stack);
				}
				a = pop_n(stack);
				push_n(stack, a + b);
				stack->top->elem = tmp;
			}
			else if (str[idx] == 'm')
			{
				b = pop_n(stack);
				if (peek_c(stack) >= 'A' && peek_c(stack) <= 'Z')
				{
					v->val[peek_c(stack) - 'A'] -= b;
					tmp = peek_c(stack);
				}
				a = pop_n(stack);
				push_n(stack, a - b);
				stack->top->elem = tmp;
			}
			else if (str[idx] == 'd')
			{
				b = pop_n(stack);
				if (peek_c(stack) >= 'A' && peek_c(stack) <= 'Z')
				{
					v->val[peek_c(stack) - 'A'] *= b;
					tmp = peek_c(stack);
				}
				a = pop_n(stack);
				push_n(stack, a * b);
				stack->top->elem = tmp;
			}
			else if (str[idx] == 'n')
			{
				b = pop_n(stack);
				if (peek_c(stack) >= 'A' && peek_c(stack) <= 'Z')
				{
					v->val[peek_c(stack) - 'A'] %= b;
					tmp = peek_c(stack);
				}
				a = pop_n(stack);
				push_n(stack, a % b);
				stack->top->elem = tmp;
			}
		}
		//
		//���Կ����ڰ� �ƴѰ�� ��길 �����Ѵ�
		//
		else if (get_rank(str[idx]) == 2)
		{
			b = pop_n(stack);
			a = pop_n(stack);
			push_n(stack, a || b);
		}
		else if (get_rank(str[idx]) == 3)
		{
			b = pop_n(stack);
			a = pop_n(stack);
			push_n(stack, a && b);
		}
		else if (get_rank(str[idx]) == 4)
		{
			if (str[idx] == 'e')
			{
				b = pop_n(stack);
				a = pop_n(stack);
				push_n(stack, a == b);
			}
			else
			{
				b = pop_n(stack);
				a = pop_n(stack);
				push_n(stack, a != b);
			}
		}
		else if (get_rank(str[idx]) == 5)
		{
			if (str[idx] == '<')
			{
				b = pop_n(stack);
				a = pop_n(stack);
				push_n(stack, a < b);
			}
			else if (str[idx] == '>')
			{
				b = pop_n(stack);
				a = pop_n(stack);
				push_n(stack, a > b);
			}
			else if (str[idx] == 'r')
			{
				b = pop_n(stack);
				a = pop_n(stack);
				push_n(stack, a <= b);
			}
			else
			{
				b = pop_n(stack);
				a = pop_n(stack);
				push_n(stack, a >= b);
			}
		}
		else if (get_rank(str[idx]) == 6)
		{
			if (str[idx] == '+')
			{
				b = pop_n(stack);
				a = pop_n(stack);
				push_n(stack, a + b);
			}
			else
			{
				b = pop_n(stack);
				a = pop_n(stack);
				push_n(stack, a - b);
			}
		}
		else if (get_rank(str[idx]) == 7)
		{
			if (str[idx] == '*')
			{
				b = pop_n(stack);
				a = pop_n(stack);
				push_n(stack, a * b);
			}
			else if (str[idx] == '%')
			{
				b = pop_n(stack);
				a = pop_n(stack);
				push_n(stack, a % b);
			}
			else
			{
				b = pop_n(stack);
				a = pop_n(stack);
				push_n(stack, a / b);
			}
		}
		//
		//���׿������� ���
		//����ϴ� ����� �ϳ��̹Ƿ�
		//�ѹ��� pop�Ͽ� ����ϰ� �ٽ� push���ش�
		//
		else
		{
			if (str[idx] == 'k')
			{
				b = pop_n(stack);
				push_n(stack, b * 1);
			}
			else if (str[idx] == 'b')
			{
				b = pop_n(stack);
				push_n(stack, b * -1);
			}
			else
			{
				b = pop_n(stack);
				push_n(stack, !b);
			}
		}
		idx++;
	}
	//
	//result�� ���� �����ϰ� �޸� �������ش�
	//
	result = pop_n(stack);
	free(stack);
	//
	//��갪�� ��ȯ�Ѵ�
	//
	return result;
}

void main()
{
	//
	//��������ü�� �����Ѵ�
	//
	Variable* v = (Variable*)malloc(sizeof(Variable));
	set_variable(v);
	int N = 0;
	scanf("%d", &N);
	//
	//�ִ� ������ ���̴� 100�̴�
	//
	char* str = (char*)malloc(101 * sizeof(char));
	//
	//������ �Է¹ް�
	//���������� ��ȯ�ϰ�
	//���������� ����ϰ�
	//���������� ����Ͽ� ����Ѵ�
	//
	for (int i = 0; i < N; i++)
	{
		scanf("%s", str);
		str = convert(str);
		print(str);
		printf("%d\n", evaluate(str, v));
	}
	//
	//�����Ҵ���� �޸𸮸� �����Ѵ�
	//
	free(str);
	free(v);
}