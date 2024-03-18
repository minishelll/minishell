#include "libft.h"
#include "parser.h"
#include <stdio.h>


#include <stdio.h>
#include <stdbool.h>

void print_tree_helper(t_tree *root) {
    if (root == NULL)
        return;

    // 노드의 타입에 따라 출력 방식이 달라짐
	if (root->type == 0)
		printf("type: PIPE\n");
	else if (root->type == AND)
		printf("type: AND\n");
	else if (root->type == OR)
		printf("type: OR\n");
	else if (root->type == PEREN)
		printf("type: PEREN\n");
    
	if (root->child_type[LEFT] == 0) {
        // 문자열인 경우
		if (root->left == NULL)
        	printf("left: NULL\n");
		else
        	printf("left: %s/\n", (char *)root->left);
    } else {
        printf("-----left 진입\n\n");
		print_tree_helper(root->left);
        // 트리 노드인 경우
    }

    if (root->child_type[RIGHT] == 0) {
        // 문자열인 경우
		if (root->right == NULL)
        	printf("right: NULL\n");
		else
		{
        	printf("right: %s/\n", (char *)root->right);
        	printf("---탈출\n");
		}
    } else {
        // 트리 노드인 경우
        printf("-----right 진입\n");
		print_tree_helper(root->right);
    }
}

// 트리 전체를 출력하는 함수
void print_tree(t_tree *root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }

    printf("Tree contents: \n");
    print_tree_helper(root); // 트리 순회 시작
    printf("\n");
}


int main(void)
{
	char *input = "a|b||c|d";
	int len = ft_strlen(input);
	t_tree *root = lexer(input, len);
	// t_tree *curr;

    print_tree(root);

}

