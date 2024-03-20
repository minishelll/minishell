#include "libft.h"
#include "parser.h"
#include <stdio.h>


#include <stdio.h>
#include <stdbool.h>

#define RED      "\x1b[31m"
#define RED      "\x1b[31m"
#define GREEN    "\x1b[32m"
#define YELLOW   "\x1b[33m"
#define BLUE     "\x1b[34m"
#define MAGENTA  "\x1b[35m"
#define CYAN     "\x1b[36m"
#define RESET    "\x1b[0m"
// 출처: https://blog.muabow.com/173 [이름 같은게 중요 한가요:티스토리]

void print_tree_helper(t_tree *root) {
    if (root == NULL)
        return;

    // 노드의 타입에 따라 출력 방식이 달라짐
	if (root->type == PIPE)
	{
		printf(RESET " TREE-TYPE: ");
		printf(BLUE "PIPE\n");
	}
	else if (root->type == AND)
	{
		printf(RESET " TREE-TYPE: ");
		printf(MAGENTA "AND\n");
	}
	else if (root->type == OR)
	{
		printf(RESET " TREE-TYPE: ");
		printf(CYAN "OR\n");
	}
	else if (root->type == PEREN)
	{
		printf(RESET " TREE-TYPE: ");
		printf(YELLOW "PEREN\n");
	}
	else if (root->type == INIT)
	{
		printf(RESET " TREE-TYPE: ");
		printf(RED "INIT\n");
	}

	if (root->child_type[LEFT] == OPERATOR)
	{
		printf(RESET "   LEFT--CHILD: ");
		printf(GREEN "OPERATOR\n");
	}
	else
		printf(RESET "   LEFT--CHILD: COMMAND\n");
	if (root->child_type[RIGHT] == OPERATOR)
	{
		printf(RESET "   RIGHT-CHILD: ");
		printf(GREEN "OPERATOR\n");
	}
	else
		printf(RESET "   RIGHT-CHILD: COMMAND\n");
	

	if (root->child_type[LEFT] == 0) {
        // 문자열인 경우
		if (root->left == NULL)
		{
        	printf(RESET "     LEFT--CONTENT: ");
        	printf(RED "NULL\n");

		}
		else
		{
        	printf(RESET "     LEFT--CONTENT: ");
        	printf(RED "%s/\n", (char *)root->left);

		}
    } else {
        printf(RESET "├─────────────────────────(left 진입)\n\n");
		print_tree_helper(root->left);
        // 트리 노드인 경우
    }

    if (root->child_type[RIGHT] == 0) {
        // 문자열인 경우
		if (root->right == NULL)
		{
        	printf(RESET "     RIGHT-CONTENT: ");
			printf(RED "NULL\n");
		}
		else
		{
        	printf(RESET "     RIGHT-CONTENT: ");
			printf(RED "%s/\n", (char *)root->right);
        	printf(RESET "    └─────────────────────(탈출)\n");
		}
    } else {
        printf(RESET "├─────────────────────────(right 진입)\n");
		print_tree_helper(root->right);
    }
}

// 트리 전체를 출력하는 함수
void print_tree(t_tree *root) {
    if (root == NULL) {
        printf(RESET "Tree is empty\n");
        return;
    }

    printf(RESET "Tree contents: \n");
    print_tree_helper(root); // 트리 순회 시작
    printf(RESET "\n");
}

// ''
// ()

// char **
// 	<
// 	''

int main(void)
{
	char *input = "a|   b && c | d | e &&   f | g";
	int len = ft_strlen(input);
	t_tree *root = parser(input, len);
	// t_tree *curr;

    print_tree(root);
}

