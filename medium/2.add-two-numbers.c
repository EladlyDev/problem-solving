#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int concat(int *dst, int y) {
    char str1[20], str2[20];

    sprintf(str1, "%d", *dst);
    sprintf(str2, "%d", y);

    strcat(str1, str2);

    *dst = atoi(str1);

    return(atoi(str1));
}


struct ListNode *add_node_end(struct ListNode **head, int val) {
    struct ListNode *new_node, *tmp;

    new_node = malloc(sizeof(struct ListNode *));
    if (!new_node)
	return (NULL);

    new_node->next = NULL;
    new_node->val = val;

    if (!head) {
	*head = new_node;
	return (new_node);
    }

    tmp = *head;
    while (tmp->next) {
	tmp = tmp->next;
    }

    tmp->next = new_node;

    return (new_node);
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *out, *tmp;
    int l1val, l2val, sum_i, i;
    char sum_s[100];

    l1val = l2val = sum_i = i = 0;

    tmp = l1;
    while (tmp) {
	concat(&l1val, tmp->val);
	tmp = tmp->next;
    }

    tmp = l2;
    while (tmp) {
	concat(&l2val, tmp->val);
	tmp = tmp->next;
    }

    sum_i = l1val + l2val;
    sprintf(sum_s, "%d", sum_i);

    while (sum_s[i]) {
	add_node_end(&out, atoi(&sum_s[i]));
	i++;
    }

    return(out);
}

int main(void) {

    struct ListNode *l1 = malloc(sizeof(struct ListNode));
    struct ListNode *l2 = malloc(sizeof(struct ListNode));

    add_node_end(&l1, 2);
    add_node_end(&l1, 4);
    add_node_end(&l1, 3);

    add_node_end(&l2, 5);
    add_node_end(&l2, 6);
    add_node_end(&l2, 4);

    addTwoNumbers(l1, l2);

    return (0);
}
