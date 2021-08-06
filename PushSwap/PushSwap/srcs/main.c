#include "utils.h"
#include "myloc.h"

int main() {
    printf("start\n");
    t_list *list = initList();
    addBack(list, 1);
    traverseAll(list);
    addBack(list, 2);
    printf("Two case\n");
    traverseAll(list);
    addBack(list, 3);
    printf("Triple case\n");
    traverseAll(list);
    clearList(&list);
    // removeBack(&head, &back);
    // printf("after remove\n");
    // traverseAll(head, back);
    // printf("after remove\n");
    // removeBack(&head, &back);
    // traverseAll(head, back);
    // printf("after remove\n");
    // removeBack(&head, &back);
    // traverseAll(head, back);
    return 0;
}
