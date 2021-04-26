#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

inline int imax(int a, int b)
{
    return a > b ? a : b;
}

inline void printCharTimes(char c, int count)
{
    for (int i = 0; i < count; i++)
        printf_s("%c", c);
}

struct AVLNode
{
    int               m_Value;
    struct AVLNode*   m_Children[2];
    int               m_Depth;
};
struct AVLNodeInfo
{
    int m_Null;
    int m_Value;
    int m_Depth;
    struct AVLNode* m_Children[2];
};
struct AVL 
{
    struct AVLNode*  m_Root;
};
struct DequeNode
{
    struct AVLNodeInfo m_Value;
    struct DequeNode* m_Next;
};
struct Deque
{
    struct DequeNode* m_Begin;
    struct DequeNode* m_End;
};

struct AVLNodeInfo  avlInfo(struct AVLNode* node, int depth)
{
    struct AVLNodeInfo info = {0, 0, depth, {0, 0}};
    if (node == NULL)
    {
        info.m_Null = 1;
        return info;
    }
    info.m_Value = node->m_Value;
    info.m_Children[0] = node->m_Children[0];
    info.m_Children[1] = node->m_Children[1];
    return info;
}

void                avlInfoPrint(struct AVLNodeInfo info)
{
    if (info.m_Null == 1)
        printf_s(" - ");
    else
        printf_s("%3d", info.m_Value);
}

void                dequeFree(struct Deque* queue)
{
    struct DequeNode* next;
    struct DequeNode* current = queue->m_Begin;
    while (current != NULL)
    {
        next = current->m_Next;
        free(current);
        current = next;
    }
}

void                dequePush(struct Deque* queue, struct AVLNodeInfo value)
{
    struct DequeNode* newNode = malloc(sizeof(struct DequeNode));
    *newNode = (struct DequeNode){value, NULL};
    if (queue->m_End != NULL)
        queue->m_End->m_Next = newNode;
    queue->m_End = newNode;
    if (queue->m_Begin == NULL)
        queue->m_Begin = queue->m_End;
}

struct AVLNodeInfo  dequePop(struct Deque* queue)
{
    if (queue->m_Begin == NULL)
        return (struct AVLNodeInfo){1, 0, 0, {0, 0}};
    
    struct DequeNode* node = queue->m_Begin;
    struct AVLNodeInfo value = node->m_Value;

    if (queue->m_Begin == queue->m_End)
        queue->m_End = NULL;

    queue->m_Begin = queue->m_Begin->m_Next;
    free(node);
    return value;
}

void                dequePrint(struct Deque* queue)
{   
    printf_s("[ ");
    struct DequeNode* current = queue->m_Begin;
    while (current != NULL)
    {
        avlInfoPrint(current->m_Value);
        current = current->m_Next;
    }
    printf_s(" ]\n");
}

struct AVLNode* avlNewNode(int value)
{
    struct AVLNode* node = malloc(sizeof(struct AVLNode));
    *node = (struct AVLNode){value, {NULL, NULL}, 1};
    return node;
}

void            avlFreeNode(struct AVLNode* node)
{
    if (node == NULL)
        return;

    avlFreeNode(node->m_Children[0]);
    avlFreeNode(node->m_Children[1]);
    free(node);
}

int             avlDepth(struct AVLNode* node)
{
    return node == NULL ? 0 : node->m_Depth;
}

int             avlTotalDepth(struct AVLNode* node)
{
    return node == NULL ? 0 : imax(avlDepth(node->m_Children[0]), avlDepth(node->m_Children[1])) + 1;
}

int             avlImbalance(struct AVLNode* node)
{
    if (node == NULL)
        return 0;
    return avlDepth(node->m_Children[0]) - avlDepth(node->m_Children[1]);
}


struct AVLNode* avlFix(struct AVLNode* node);
struct AVLNode* avlInsert(int value, struct AVLNode* node)
{
    struct AVLNode* newNode;

    if (node == NULL)
    {
        newNode = malloc(sizeof(struct AVLNode));
        *newNode = (struct AVLNode){value, {NULL, NULL}, 1};
        return newNode;
    }

    if (value < node->m_Value)
    {
        newNode = avlInsert(value, node->m_Children[0]);
        node->m_Children[0] = newNode;
    }
    else if (value > node->m_Value)
    {
        newNode = avlInsert(value, node->m_Children[1]);
        node->m_Children[1] = newNode;
    }
    node->m_Depth = avlTotalDepth(node);
    node = avlFix(node);
    // node->m_Depth = avlTotalDepth(node);
    return node;
}

struct AVLNode* avlRotateR(struct AVLNode* node)
{
    if (node == NULL || node->m_Children[0] == NULL)
        return node;

    struct AVLNode* promotedNode = node->m_Children[0];
    struct AVLNode* swappedChild = promotedNode->m_Children[1];

    node->m_Children[0] = swappedChild;
    node->m_Depth = avlTotalDepth(node);

    promotedNode->m_Children[1] = node;
    promotedNode->m_Depth = avlTotalDepth(promotedNode);

    return promotedNode;
}

struct AVLNode* avlRotateL(struct AVLNode* node)
{
    if (node == NULL || node->m_Children[1] == NULL)
        return node;

    struct AVLNode* promotedNode = node->m_Children[1];
    struct AVLNode* swappedChild = promotedNode->m_Children[0];

    node->m_Children[1] = swappedChild;
    node->m_Depth = avlTotalDepth(node);

    promotedNode->m_Children[0] = node;
    promotedNode->m_Depth = avlTotalDepth(promotedNode);

    return promotedNode;
}

struct AVLNode* avlRotateLR(struct AVLNode* node)
{
    if (node == NULL)
        return node;

    node->m_Children[0] = avlRotateL(node->m_Children[0]);
    return avlRotateR(node);
}

struct AVLNode* avlRotateRL(struct AVLNode* node)
{
    if (node == NULL)
        return node;

    node->m_Children[1] = avlRotateR(node->m_Children[1]);
    return avlRotateL(node);
}

struct AVLNode* avlFix(struct AVLNode* node)
{
    if (node == NULL)
        return node;
    int imbalance = avlImbalance(node);
    int imbalanceSubL = avlImbalance(node->m_Children[0]);
    int imbalanceSubR = avlImbalance(node->m_Children[1]);
    struct AVLNode* returnNode = node;
    if (imbalance >= 2)
    {
        if (imbalanceSubL > 0)
            returnNode = avlRotateR(node);
        else if (imbalanceSubL < 0)
            returnNode = avlRotateLR(node);
    }
    else if (imbalance <= -2)
    {
        if (imbalanceSubR > 0)
            returnNode = avlRotateRL(node);
        else if (imbalanceSubR < 0)
            returnNode = avlRotateL(node);
    }
    return returnNode;
}

void            avlPrint(struct AVLNode* node)
{
    struct Deque queue = {NULL, NULL};

    int maxDepth = node->m_Depth;
    int currentDepth = 0;

    dequePush(&queue, avlInfo(node, 1));

    int H_last = 0;
    int W = 3;
    int L = pow(2, maxDepth - 1) * (W + H_last);

    int H_current = 2 * L - W;

    printf_s("\n");
    while (currentDepth < maxDepth)
    {
        printCharTimes(' ', 1 + H_current / 2);

        for (int i = 0; i < pow(2, currentDepth); i++)
        {
            struct AVLNodeInfo info = dequePop(&queue);
            avlInfoPrint(info);
            printCharTimes(' ', H_current);

            struct AVLNodeInfo infoChildL = avlInfo(info.m_Children[0], currentDepth + 1);
            struct AVLNodeInfo infoChildR = avlInfo(info.m_Children[1], currentDepth + 1);

            dequePush(&queue, infoChildL);
            dequePush(&queue, infoChildR);
        }
        printf_s("\n");
        printCharTimes('\n', (maxDepth - currentDepth));
        currentDepth++;
    
        H_current = (H_current - W/2) / 2;

    }
    printf_s("\n");
    dequeFree(&queue);
}

void            avlNodePrint(struct AVLNode* node)
{
    printf_s("{%d}", node->m_Value);
}

struct AVLNode* testGenerateBranch(int count, int lowerBound, int upperBound)
{
    if (count <= 0 || lowerBound >= upperBound )
        return NULL;

    time_t t;
    srand(time(&t));

    struct AVLNode* root = avlNewNode(rand() % (upperBound - lowerBound) + lowerBound);

    for (int i = 1; i < count; i++)
    {
        avlInsert(rand() % (upperBound - lowerBound) + lowerBound, root);
    }

    return root;
}

struct AVL*     testGenerateTree(int count, int lowerBound, int upperBound)
{
    if (count <= 0 || lowerBound >= upperBound )
        return NULL;

    time_t t;
    srand(time(&t));

    struct AVLNode* root = avlNewNode(rand() % (upperBound - lowerBound) + lowerBound);

    struct AVL* tree = malloc(sizeof(struct AVL));
    tree->m_Root = NULL;

    for (int i = 1; i < count; i++)
    {
        tree->m_Root = avlInsert(rand() % (upperBound - lowerBound) + lowerBound, tree->m_Root);
    }
    return tree;
}

int main(int argc, char** argv)
{

    struct AVL tree;
    struct AVL* treePtr = &tree;
    treePtr = testGenerateTree(20, -100, 100);

    avlPrint(treePtr->m_Root);

    printf_s("Success!\n");

    return 0;
}