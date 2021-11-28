#include <stdio.h>
#include <stdlib.h>
#define SIZE_HTABLE 31

struct keyval_item{
    int key;
    int data;
};
struct keyval_item* dataBucket[SIZE_HTABLE]={NULL};//will be on application stack
int hashFunc(int key)
{

    return key%SIZE_HTABLE;
}

struct keyval_item* lookup(int key)
{
    if(key<SIZE_HTABLE) return dataBucket[hashFunc(key)];
    //one line code of lookup operation


    //multiple lines
    // int h = hashFunc(key);
    // struct keyval_item* item = dataBucket[h];
    // return item;
    return NULL;
}

void delete(int keey)
{
    for(short i=0;i<SIZE_HTABLE;i++)
    {
        if(dataBucket[i]!=NULL&&dataBucket[i]->key==keey)
        {
            // struct keyval_item* temp = dataBucket[i];
            free(dataBucket[i]);
            // dataBucket[i]->key = -1;
            // dataBucket[i]->data = -1;
            return;
        }
    }
    return;
}

void insert(struct keyval_item* item)
{
    if(NULL == item)return;

    int idx = hashFunc(item->key);
    dataBucket[idx] = item;
    return;
}
void display()
{
    for(short i=0;i<SIZE_HTABLE;i++)
    {
        if(NULL!=dataBucket[i])
            printf("key = %d, data = %d\n",dataBucket[i]->key,dataBucket[i]->data);
    }
    return;
}

int main()
{
    struct keyval_item* item1 = (struct keyval_item*)(malloc(sizeof(struct keyval_item)));
    item1->key = 5;
    item1->data = 45;
    insert(item1);

    struct keyval_item item2;
    item2.key = 3;
    item2.data = 475;
    insert(&item2);

    struct keyval_item item3;
    item3.key = 56;
    item3.data = 4765;
    insert(&item3);

    struct keyval_item item4;
    item4.key = 15;
    item4.data = 4754;
    insert(&item4);

    struct keyval_item* returnitem = lookup(5);
    printf("For key = 5, data = %d\n",returnitem->data);
    printf("For key = 3, data = %d\n",lookup(3)->data);
    // printf("For key = 8, data = %d\n",lookup(8)->data);

    //display function calling
    display();
    delete(5);
    printf("\n-----------------\n");
    display();
    return 0;
}