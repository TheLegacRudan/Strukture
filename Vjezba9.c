#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node *pos;
typedef struct node {
	int num;
	pos left;
	pos right;
};

pos insert(pos current, pos el) {
	if (NULL == current)
		return el;
	if (current->num > el->num)
		current->left = insert(current->left, el);	
	else if (current->num < el->num)
		current->right = insert(current->right, el);
	else{
		printf("error nepotrebno");
		free(el);
	}
	return current;
}

void printInOrder(pos cur) {
	if (NULL == cur)
		return;
	//in order printf u sredini, post ord left i right zaminjeni, 
	//preorder printf prije poziva f-je
	printInOrder(cur->left);
	printf("%d", cur->num);
	printInOrder(cur->right);
}
pos find(pos cur, int num) {
	if (NULL == cur)
		return NULL;
	if (cur->num == num)
		return cur;
	else if (cur->num > num)
		return find(cur->left, num);
	else if (cur->num < num)
		return find(cur->left, num);
}

pos del(pos cur, int num) {
	if (NULL == cur)
		return NULL;

	if (cur->num == num) {
		if (cur->left != NULL) {
			pos result = findMax(cur->left);
			cur->num = result->num;
			cur->left = delete(cur->left, result->num);
		}
		else if (cur->right != NULL) {
			pos result = findMin(cur->right);
			cur->num = result->num;
			cur->right = delete(cur->right, result->num);
		}
		else {
			free(cur);
			return NULL;
		}
	}
	else if (cur->num > num)
		cur->left = delete(cur->left, num);	
	else if (cur->num < num)
		cur->right = delete(cur->right, num);
	return cur;
}

pos findMax(pos cur) {
	if (NULL == cur)
		return NULL;
	while (cur->right != NULL)
		cur = cur->right;
	return cur;
}
pos findMin(pos cur) {
	if (NULL == cur)
		return NULL;
	while (cur->left != NULL)
		cur = cur->left;
	return cur;
}

int main() {
	pos root = NULL;
	return 0;
}
