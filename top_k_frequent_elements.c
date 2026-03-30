#include<stdio.h>
#include<stdlib.h>

#define HASH_SIZE 2000003//定义哈希表大小为质数

typedef struct HashNode{
    int key;
    int count;
    struct HashNode* next;
}Node;

Node* HashTable[HASH_SIZE];//哈希表

//哈希函数
int hash(int key){
    return (key % HASH_SIZE + HASH_SIZE) % HASH_SIZE;
}

void insert(int key){
    int h = hash(key);
    Node* cur = HashTable[h];
    while(cur!=NULL){
        if(cur->key == key){
            cur->count++;
            return;
        }
        cur = cur->next;
    }
    // 如果键不存在，创建新节点
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->count = 1;
    newNode->next = HashTable[h];
    HashTable[h] = newNode;
}

typedef struct {
    int key;
    int count;
}HeapNode;

HeapNode heap[HASH_SIZE];
int heapSize = 0;

//交换
void swap(int i, int j){
    HeapNode temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

//上浮
void heapify_up(int i){
    while(i > 1 && heap[i].count < heap[i/2].count){
        swap(i,i/2);
        i /= 2;
    }
}

//下沉
void heapify_down(int i){
    while(1){
        int smallest = i;
        int l = 2*i;
        int r = 2*i +1;
        if(l <= heapSize && heap[l].count < heap[smallest].count){
            smallest = l;
        }
        if(r <= heapSize && heap[r].count < heap[smallest].count){
            smallest = r;
        }
        if(smallest == i) break;
        swap(i, smallest);
        i = smallest;
    }
}

// 插入堆
void push(int key, int count, int k) {
    heap[++heapSize].key = key;
    heap[heapSize].count = count;
    heapify_up(heapSize);
    
    if (heapSize > k) {
        // 弹出堆顶
        heap[1] = heap[heapSize--];
        heapify_down(1);
    }
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    // 统计频率
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        insert(x);
    }

    // 遍历哈希表
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* cur = HashTable[i];
        while (cur) {
            push(cur->key, cur->count, K);
            cur = cur->next;
        }
    }

    // 输出结果
    for (int i = 1; i <= heapSize; i++) {
        printf("%d ", heap[i].key);
    }

    return 0;
}
