//insert pre-order get post-order
#include <stdio.h>
#include <stdlib.h>

struct tree
{
	struct tree *left;
	int data;
	struct tree *right;
} t;

struct tree *root = NULL;

void insert()
{
	int element;

	printf("enter the data of BST in pre-order and -666 to exit:-\n");
	do
	{
		scanf("%d", &element);
		struct tree *temp = malloc(sizeof(struct tree));
		temp->data = element;
		temp->left = NULL;
		temp->right = NULL;

		if (root == NULL)
		{
			root = temp;
		}
		else
		{
			struct tree *ptr = root;
			struct tree *pptr = NULL;
			while (ptr != NULL)
			{
				pptr = ptr;
				if (element < ptr->data)
					ptr = ptr->left;
				else
					ptr = ptr->right;
			}
			if (element < pptr->data)
				pptr->left = temp;
			else
				pptr->right = temp;
		}

	} while (element != -666);
}

void print(struct tree *ptr)
{
	if (ptr != NULL)
	{
		print(ptr->left);
		print(ptr->right);
		if (ptr->data != -666)
			printf("-->%d", ptr->data);
		else
			printf(" ");
	}
}

void main()
{
	int choice;

	while (1)
	{
		printf("\nselect your choice:\n1.insert\n2.print PostOrder\n3.exit\n...............\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			insert();
			break;
		case 2:
			print(root);
			break;
		case 3:
			exit(0);
		}
	}
}
