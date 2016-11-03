#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HashNode
{
    int val;
    int key;
    struct HashNode * next;
}HashNode;

static inline int hash (int val, int n) {
    int index = val % n;
    return (index > 0) ? (index) : (-index);
}
int* twoSum(int* nums, int numsSize, int target) {
    int ret[2]={0,0};
    int i;
    HashNode **hashtable=(HashNode **)calloc(1,sizeof(HashNode));
    int idx;
    HashNode *p,*tail;
    for(i =0;i<numsSize;i++)
    {
        idx =hash(nums[i],numsSize);
        p=hashtable[idx];
        while(p!=NULL)
        {
            tail =p;
            p=p->next;
        }
        HashNode *new_node = (HashNode *)calloc(1, sizeof(HashNode));
        new_node->val = nums[i];
        new_node->key = i;
        new_node->next = NULL;

        if (tail) {
            tail->next = new_node;
        }
        else {
            hashtable[idx] = new_node;
        }
        
    }
    
    for (i = 0; i < numsSize; i++) {
        int diff = target - nums[i];
        idx = hash(diff, numsSize);
        p = hashtable[idx];
        while (p != NULL) {
            if (p->val == diff && p->key != i) {
                ret[0] = p->key + 1;
                ret[1] = i + 1;
                // swap value
                if (ret[0] > ret[1]) {
                    ret[0] = ret[0] ^ ret[1];
                    ret[1] = ret[0] ^ ret[1];
                    ret[0] = ret[0] ^ ret[1];
                }
                return ret;
            }
            p = p->next;
        }
    }
    return ret;
}