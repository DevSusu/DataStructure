#include "List.h"

int List::listNode::getData() {
    return 1;
}

List::listNode::listNode(int newItem) {
    data = newItem;
}