#include <iostream>

using namespace std;

typedef struct sNode {
    int m_val;
    sNode *next;

    sNode(int val): m_val(val), next(NULL) {}
    sNode(): m_val(0), next(NULL) {}
} sNode_t;

typedef struct sList {
    sNode_t *m_head;

    sList(): m_head(NULL) {}
    void push_head(int val);
    void delete_node(int val);
    void delete_node(sNode_t *node);
} sList_t;

class CLinkedList {
    public:
        static bool delete_duplicate(sList_t *list);
};