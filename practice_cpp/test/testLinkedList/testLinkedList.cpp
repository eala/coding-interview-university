#include "linked_list.h"
#include "testLinkedList.h"

//using ::testing::Return;

LinkedListTest::LinkedListTest() {

}

LinkedListTest::~LinkedListTest() {};

void LinkedListTest::SetUp() {};

void LinkedListTest::TearDown() {};

TEST_F(LinkedListTest, deleteNodeKey) {
    sList_t *list = new sList_t();
    list->push_head(3);
    list->push_head(5);
    list->push_head(3);
    list->push_head(7);
    list->delete_node(5);
    sNode_t *pNode = list->m_head;
    EXPECT_EQ(pNode->m_val, 7);
    pNode = pNode->next;
    EXPECT_EQ(pNode->m_val, 3);
    pNode = pNode->next;
    EXPECT_EQ(pNode->m_val, 3);
    if (list) delete list;
}

TEST_F(LinkedListTest, deleteNode) {
    sList_t *list = new sList_t();
    list->push_head(3);
    list->push_head(5);
    list->push_head(3);
    list->push_head(7);
    sNode_t *pNode = list->m_head;
    pNode = pNode->next;
    pNode = pNode->next;
    list->delete_node(pNode);
    pNode = list->m_head;
    EXPECT_EQ(pNode->m_val, 7);
    pNode = pNode->next;
    EXPECT_EQ(pNode->m_val, 3);
    pNode = pNode->next;
    EXPECT_EQ(pNode->m_val, 3);
    if (list) delete list;
}

TEST_F(LinkedListTest, removeDuplicate) {
    sList_t *list = new sList_t();
    list->push_head(3);
    list->push_head(5);
    list->push_head(3);
    list->push_head(7);
    CLinkedList::delete_duplicate(list);
    sNode_t *pNode = list->m_head;
    EXPECT_EQ(pNode->m_val, 7);
    pNode = pNode->next;
    EXPECT_EQ(pNode->m_val, 5);
    pNode = pNode->next;
    EXPECT_EQ(pNode->m_val, 3);
    if (list) delete list;
}