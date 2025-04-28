#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF -1000000

int max(int a, int b){
    
    return a >= b ? a : b;
}

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int size;
    int height;
} Node;

typedef struct {
    
    Node* rt;
} BinTree;

BinTree* create_BinTree(){
    
    BinTree* tree = (BinTree*)malloc(sizeof(BinTree));
    tree->rt = NULL;
    
    return tree;
}

Node* create_node(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    
    node->key = key;
    
    node->left = NULL;
    node->right = NULL;
    
    node->size = 1;
    node->height = 1;
    
    return node;
}

int get_size(Node* node) {
    
    return node != NULL ? node->size : 0;
}

int get_height(Node* node) {
    
    return node != NULL ? node->height : 0;
}

void update_node(Node* node) {
    
    node->size = 1 + get_size(node->left) + get_size(node->right);
    node->height = 1 + max(get_height(node->left), get_height(node->right));
}

Node* insert(Node* node, int key) {
    
    if (node == NULL){ 
        
        return create_node(key);
    }
    
    if (key < node->key) {
        
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        
        node->right = insert(node->right, key);
    } else {
        
        return node;
    }
    
    update_node(node);
    return node;
}

Node* find_min(Node* node) {
    
    while (node->left){ 
        
        node = node->left;
    }
    
    return node;
}

Node* delete_node(Node* node, int key) {
    
    if (node == NULL){ 
        
        return NULL;
    }
    if (key < node->key) {
        
        node->left = delete_node(node->left, key);
    } else if (key > node->key) {
        
        node->right = delete_node(node->right, key);
    } else {
        
        if (node->left == NULL || node->right == NULL) {
            
            Node* temp = node->left != NULL ? node->left : node->right;
            free(node);
            return temp;
        }
        
        Node* temp = find_min(node->right);
        node->key = temp->key;
        node->right = delete_node(node->right, temp->key);
    }
    if (node != NULL) { 
        
        update_node(node);
    }
    
    return node;
}

bool find(Node* node, int key) {
    
    if (node == NULL) {
        
        return false;
    }
    
    if (key < node->key) {
        
        return find(node->left, key);
    }
    if (key > node->key) {
        
        return find(node->right, key);
    }
    
    return true;
}

int main() {
    BinTree* tree = create_BinTree();
    
    Node* root = tree->rt;
    
    int N;
    scanf("%d", &N);
    
    char cmd[10];
    
    int key;

    int result[100];
    int indx = 0;
    
    for(int i = 0; i < 100; i++){
        
        result[i] = INF;
    }

    for (int i = 0; i < N; ++i) {
        
        scanf("%s", cmd);
        
        if (cmd[0] == '+') {
            
            scanf("%d", &key);
            root = insert(root, key);
        } 
        else if (cmd[0] == '-') {
            
            scanf("%d", &key);
            root = delete_node(root, key);
        } 
        else if (cmd[0] == '?') {
            
            scanf("%d", &key);
            result[indx++] = (find(root, key) ? -1001 : -1002);
        } 
        else if (cmd[0] == 's') {
            
            result[indx++] = get_size(root);
        } 
        else if (cmd[0] == 'h') {
            
            result[indx++] = get_height(root);
        }
    }
    
    for(int i = 0; i < indx; i++){
        
        if(result[i] == -1001){
            
            printf("true\n");
        }
        else if(result[i] == -1002){
            
            printf("false\n");
        }
        else{
            
            printf("%d\n", result[i]);
        }
    }

    return 0;
}