#include <unordered_set>
#include "linked_list.h"

void sList::push_head(int val) {
    sNode_t *pNode = new sNode_t(val);
    pNode->next = m_head;
    m_head = pNode;
}

void sList::delete_node(sNode_t *node) {
    sNode_t *pNode = m_head;
    if (pNode == node) {
        delete m_head;
        m_head = NULL;
    }

    while (pNode->next != NULL) {
        if (pNode->next == node) {
            sNode_t *pNode_to_delete = pNode->next;
            pNode->next = (pNode->next)->next;
            delete pNode_to_delete;
        }
        pNode = pNode->next;
    }
}

// this will delete first node with key val
void sList::delete_node(int val) {
    sNode_t *pNode = m_head;
    if (pNode->m_val == val) {
        delete m_head;
        m_head = NULL;
    }

    while (pNode->next != NULL) {
        if (pNode->next->m_val == val) {
            sNode_t *pNode_to_delete = pNode->next;
            pNode->next = (pNode->next)->next;
            delete pNode_to_delete;
        }
        pNode = pNode->next;
    }
}

bool CLinkedList::delete_duplicate(sList_t *list) {
    sNode_t *pDummy = new sNode_t(0);
    pDummy->next = list->m_head;
    unordered_set<int> data;

    while (pDummy->next != NULL){
        printf("val: %d\n", pDummy->next->m_val);
        if (data.size() > 0 && data.end() != data.find(pDummy->next->m_val)) {
            sNode_t *pNode_del = pDummy->next;
            pDummy->next = (pDummy->next)->next;
            //delete pNode_del;
        } else {
            data.insert(pDummy->next->m_val);
        }
        pDummy = pDummy->next;
    }
    if(pDummy) delete pDummy;
    return true;
}