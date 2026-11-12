#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
} Node;

Node* createNode(char ch, int freq) {
    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->ch = ch;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;

    return newNode;
}

void swap(Node **a, Node **b) {
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(Node *heap[], int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && heap[l]->freq < heap[smallest]->freq)
        smallest = l;

    if (r < n && heap[r]->freq < heap[smallest]->freq)
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}

Node* extractMin(Node *heap[], int *n) {
    Node *temp = heap[0];

    heap[0] = heap[*n - 1];
    (*n)--;

    heapify(heap, *n, 0);

    return temp;
}

void insertHeap(Node *heap[], int *n, Node *node) {
    int i = *n;
    heap[(*n)++] = node;

    while (i > 0 &&
           heap[(i - 1) / 2]->freq > heap[i]->freq) {

        swap(&heap[(i - 1) / 2], &heap[i]);
        i = (i - 1) / 2;
    }
}

void printCodes(Node *root, int code[], int depth) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) {
        printf("%c : ", root->ch);

        for (int i = 0; i < depth; i++)
            printf("%d", code[i]);

        printf("\n");
        return;
    }

    code[depth] = 0;
    printCodes(root->left, code, depth + 1);

    code[depth] = 1;
    printCodes(root->right, code, depth + 1);
}

int main() {
    int n;

    printf("Enter number of symbols: ");
    scanf("%d", &n);

    Node *heap[100];

    int heapSize = 0;

    for (int i = 0; i < n; i++) {
        char ch;
        int freq;

        printf("Enter symbol and frequency: ");
        scanf(" %c %d", &ch, &freq);

        heap[heapSize++] = createNode(ch, freq);
    }

    for (int i = heapSize / 2 - 1; i >= 0; i--)
        heapify(heap, heapSize, i);

    while (heapSize > 1) {
        Node *x = extractMin(heap, &heapSize);
        Node *y = extractMin(heap, &heapSize);

        Node *parent = createNode('$', x->freq + y->freq);

        parent->left = x;
        parent->right = y;

        insertHeap(heap, &heapSize, parent);
    }

    int code[100];

    printf("\nHuffman Codes:\n");
    printCodes(heap[0], code, 0);

    return 0;
}