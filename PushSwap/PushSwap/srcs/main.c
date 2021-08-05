#include "utils.h"
#include "myloc.h"

int main() {
    write(1, "Hello, World!\n", 15);
    t_list *head = initList(1);
    t_list *back = head;
    t_list *temp = initList(2);
    addBack(head, &back, temp);
    printf("Two case\n");
    traverseAll(head, back);
    temp = initList(3);
    printf("Triple case\n");
    addBack(head, &back, temp);
    traverseAll(head, back);
    removeBack(&head, &back);
    printf("after remove\n");
    traverseAll(head, back);
    printf("after remove\n");
    removeBack(&head, &back);
    traverseAll(head, back);
    printf("after remove\n");
    removeBack(&head, &back);
    traverseAll(head, back);
    return 0;
}
