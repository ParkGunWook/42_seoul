#include "utils.h"
#include "myloc.h"

int main() {
    printf("start\n");
    t_list *list = initList();
    printf("list on %p and points to %p\n", &list, list);
    addBack(list, 1);
    traverseAll(list);
    addBack(list, 2);
    printf("Two case\n");
    traverseAll(list);
    addBack(list, 3);
    printf("Triple case\n");
    traverseAll(list);
    t_node *poped = popBack(list);
    printf("after pop %d\n", poped->content);
    traverseAll(list);
    poped = popBack(list);
    printf("after pop %d\n", poped->content);
    traverseAll(list);
    poped = popBack(list);
    printf("after pop %d\n", poped->content);
    traverseAll(list);
    addBack(list, 1);
    traverseAll(list);
    addBack(list, 2);
    printf("Two case\n");
    traverseAll(list);
    addBack(list, 3);
    printf("Triple case\n");
    traverseAll(list);
    clearList(&list);
    printf("list on %p and points to %p\n", &list, list);
    return 0;
}
