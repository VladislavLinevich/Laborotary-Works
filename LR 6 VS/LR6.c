#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>

typedef struct _node //Элемент стека
{
	int tn;
	int n;

	struct _node *next;
} node;

typedef struct  {  //стек
	 node *head;

} Stack;

Stack* CreateStack(){  //Создание cтека
	Stack *temp;
	temp = (Stack*)malloc(sizeof(Stack));

	temp->head = NULL;

	return temp;
}

void Push(Stack *stack, int number, int TreeNumber) //Вставка элементов в стек
{
if (stack->head == NULL) {
	node *temp;
	temp = (node*)malloc(sizeof(node));

	temp->n = number;
	temp->tn = TreeNumber;
	temp->next = NULL;
	stack->head = temp;
}
else {
	node *temp;
	temp = (node*)malloc(sizeof(node));

	temp->n = number;
	temp->tn = TreeNumber;
	temp->next = stack->head;
	stack->head = temp;
}
}

void Delete(Stack *stack)//Удаление верхушкки стека
{
	if (stack->head ==NULL) {
		printf("Empty stack");
		return ;
	}
	else {
        node *temp;
		temp = (node*)malloc(sizeof(node));
		temp = stack->head;
		stack->head = stack->head->next;
        free(temp);
	}
}

int ShowTreeNumber(Stack *stack)//Просмотр номера дерева из стека
{
	if (stack->head ==NULL) {
		printf("Empty stack");
		return 0;
	}
	else {
		return stack->head->tn;
	}
}

int ShowNumber(Stack *stack) //Просмотр значения из стека
	{
	if (stack->head ==NULL) {
		printf("Empty stack");
		return 0;
	}
	else {
		return stack->head->n;
	}
}

typedef struct _tnode { //Узел дерева
	int n;

	struct _tnode *left;
	struct _tnode *right;
} tnode;

tnode *AddNode(int number, tnode *tree){//Добавление элементов в дерево
	if (tree == NULL) {
		tree = (tnode*)malloc(sizeof(tnode));
		tree->n = number;
		tree->left = NULL;
		tree->right = NULL;
	}
	else {
		if (number < tree->n) {
			tree->left = AddNode(number, tree->left);
		}
		else {
			tree->right = AddNode(number, tree->right);
		}
	}
	return(tree);
}

void Summa(tnode *node, int *s){ //Сумма значений в дереве
	if (node == NULL) {
		return ;
	}
	*s = *s + node->n;
	Summa(node->left, s);
	Summa(node->right, s);

}

int main()
{
	int size, TreeNumber, number, answer, sum;
	Stack *stack = CreateStack(); //Создание стека
	answer = 0;
	TreeNumber = 1;
	printf("Enter the stack size");
	while(scanf("%d", &size) == 0 || size <= 0){
		printf("Enter integer value");
		while (getchar() != '\n');
	}

	for (int i = 0; i < size; i++) {
		printf("Enter the number to be pushed onto the stack");
		while(scanf("%d", &number) == 0){
			printf("Enter integer value");
			while (getchar() != '\n');
		}
		Push(stack, number, TreeNumber); //Добавляем элементы в стек
		if (i == size - 1) {//Чтобы не изменять номер дерева
			break;
		}
		while (answer < 1 || answer > 2){
			printf("Want to change the tree number: 1)yes; 2) no?");
			while (scanf("%d", &answer) == 0){
                printf("Enter integer value");
				while (getchar() != '\n');
			}
		}
		if (answer == 1) { //Изменяем номер дерева
			TreeNumber++;
			printf("New tree number = %d\n", TreeNumber);
		}
		answer = 0;
	}

	tnode *root[TreeNumber];
	for (int i = 0; i < TreeNumber; i++) {
		root[i] = NULL;
	}

	for (int i = 0; i < size; i++) {      //Заполняем деревья
		root[ShowTreeNumber(stack) - 1] = AddNode(ShowNumber(stack), root[ShowTreeNumber(stack) - 1]);
		Delete(stack);
	}

	for (int i = 0; i < TreeNumber; i++) { //Вывод суммы элементов деревьев
		sum = 0;
		Summa(root[i], &sum);
		printf("The sum of the elements of %d tree = %d\n", i+1, sum);

	}

	getch();
	return 0;
}