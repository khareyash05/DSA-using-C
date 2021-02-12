#include<stdio.h>
#include<stdlib.h>
#define MAX 20
#define max 20
struct bstnode
{
    struct bstnode* lchild;
    int info;
    struct bstnode* rchild;
};
typedef struct bstnode bstnode;
struct bnode
    {
        int data;
        struct bnode* left;
        struct bnode* right;
    };
    int n;
int queue_arr[MAX];
    int rear=-1;
    int front=-1;

    int stack[MAX];
    int top=-1;
typedef struct node
    {
        int info;
        struct node* next;
    } node;
    node *start=NULL,*t=NULL;
typedef struct avlnode
{
    int data;
    struct avlnode *lchild,*rchild,*info;
    int ht;
} avlnode;
struct avlnode* root=NULL,*ptr;
int n,info,i,j;
int ar[100];
struct node *x,*p1,*p2,*t1;
int a[20],b[20],c[40];
int m,n,p,val,i,j,key,pos,temp;
void acreate();
void adisplay();
void ainsert();
void adel();
void asearch();
int slmenu();
int slmenu1();
void slinsert();
void sldel();
void sldisplay();
void slsearch();
struct node* slcreate(int info);
struct node* slreverse(struct node *x);
void sapush();
void sapop();
void sadisplay();
void sasize();
void sapeek();
void qainsert(int item);
int qadel();
int qapeek();
int qaisEmpty();
int qaisFull();
void qadisplay();
void btacreate_tree(struct bnode *root, int tree[], int i);
void btainorder(struct bnode* root);
void btapreorder(struct bnode* root);
void btapostorder(struct bnode* root);
void htsamax_heapify(int *heap, int i);
void htsabuild_max_heap(int *heap, int i);
void htsamin_heapify(int *heap, int i);
void htsabuild_min_heap(int *heap, int i);
void htsaheap_sort(int *heap);
void avlarry(avlnode* root);
avlnode* avlsearch(avlnode* ptr,int skey);
void avlpreorder(avlnode* ptr);
void avlinorder(avlnode* ptr);
void avlpostorder(avlnode* ptr);
int avlheightnode(avlnode* ptr,int p);
void avlsucc_prede(avlnode* root, int key);
avlnode* avlinsert(avlnode *,int);
avlnode* avlDelete(avlnode *,int);
int avlheight(avlnode *);
avlnode* avlrotateright(avlnode *);
avlnode* avlrotateleft(avlnode *);
avlnode* avlRR(avlnode *);
avlnode* avlLL(avlnode *);
avlnode* avlLR(avlnode *);
avlnode* avlRL(avlnode *);
int avlBF(avlnode *);
void bstarry(bstnode* root);
bstnode* bstsearch(bstnode* ptr,int skey);
bstnode* bstinsert(bstnode* ptr,int ikey);
bstnode* bstdel(bstnode* ptr,int dkey);
bstnode* bstmin(bstnode* ptr);
bstnode* bstmax(bstnode* ptr);
void bstpreorder(bstnode* ptr);
void bstinorder(bstnode* ptr);
void bstpostorder(bstnode* ptr);
int bstheight(bstnode* ptr);
int bstheightnode(bstnode* ptr,int p);
int mins(int x, int y);
int linsearch(int arr[],int n,int x);
int binsearch(int arr[],int l,int r,int x);
int fibsearch(int arr[],int x,int n);
void qqsort();
void quick(int arr[],int low,int up);
int part(int arr[], int low, int up);
void msort();
void merge_sort(int arr[], int low ,int up);
void mergee(int arr[], int temp[],int low1, int up1, int low2, int up2 );
void copyy(int arr[], int temp[], int low,int up);
void arr();
void singlell();
void stacka();
void queuea();
void bintree();
void htsa();
void avl();
void bstree();
void srch();
void soort();
