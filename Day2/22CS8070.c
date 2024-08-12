#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1000
#define MAX_PATHS 100

typedef struct TreeNode {
    int val;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode* createNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

TreeNode* insert(TreeNode* root, int val) {
    if (!root)
        return createNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

void dfs(TreeNode* node, int* path, int depth, int z_turns, int last_turn,
         int* max_z_turns, int* min_length, int results[MAX_PATHS][MAX_NODES], int* results_count) {
    if (!node)
        return;
    
    path[depth] = node->val;
    
    int current_turn = 0;
    if (depth >= 3) {
        int parent = path[depth - 3];
        int child1 = path[depth - 2];
        int child2 = path[depth - 1];
        int child3 = path[depth];
        if (parent < child1 && child1 > child2 && child2 < child3) {
            current_turn = 1;
        }
    }
    
    if (current_turn) {
        z_turns++;
        last_turn = 1;
    } else {
     
        last_turn = 0;
    }
    
    if (!node->left && !node->right) {
        if (z_turns > *max_z_turns) {
            *max_z_turns = z_turns;
            *min_length = depth + 1;
            *results_count = 0;
            memcpy(results[*results_count], path, sizeof(int) * (depth + 1));
            (*results_count)++;
        } else if (z_turns == *max_z_turns) {
            if (depth + 1 < *min_length) {
                *min_length = depth + 1;
                *results_count = 0;
                memcpy(results[*results_count], path, sizeof(int) * (depth + 1));
                (*results_count)++;
            } else if (depth + 1 == *min_length) {
                memcpy(results[*results_count], path, sizeof(int) * (depth + 1));
                (*results_count)++;
            }
        }
    }
    
    dfs(node->left, path, depth + 1, z_turns, last_turn, max_z_turns, min_length, results, results_count);
    dfs(node->right, path, depth + 1, z_turns, last_turn, max_z_turns, min_length, results, results_count);
}

void find_max_z_turn_path(int* preorder, int n) {
    if (n == 0) {
        printf("NIL\n");
        return;
    }
    
    TreeNode* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, preorder[i]);
    }
    
    int path[MAX_NODES];
    int results[MAX_PATHS][MAX_NODES];
    int max_z_turns = 0;
    int min_length = MAX_NODES;
    int results_count = 0;
    
    dfs(root, path, 0, 0, 0, &max_z_turns, &min_length, results, &results_count);
    
    if (max_z_turns == 0) {
        printf("NIL\n");
    } else {
        for (int i = 0; i < results_count; i++) {
            for (int j = 0; j < min_length; j++) {
                if (j > 0) printf("-");
                printf("%d", results[i][j]);
            }
            printf("\n");
        }
        printf("%d\n", max_z_turns);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int preorder[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }
    
    find_max_z_turn_path(preorder, n);
    
    return 0;
}