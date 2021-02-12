void acreate()
{
        printf("\nEnter the size of the array elements:\t");
        scanf("%d",&n);
        printf("\nEnter the elements for the array:\n");
        for(i=0;i<n;i++)
        {
                scanf("%d",&a[i]);
        }
}//end of create()
void adisplay()  //displaying an array elements
{
        int i;
        printf("\nThe array elements are:\n");
        for(i=0;i<n;i++){
                 printf("%d\t",a[i]);
         }
 }//end of display()
void ainsert()   //inserting an element in to an array
{
    printf("\nEnter the position for the new element:\t");
    scanf("%d",&pos);

 printf("\nEnter the element to be inserted :\t");
    scanf("%d",&val);

 for(i=n-1;i>=pos;i--)
        {
                a[i+1]=a[i];
        }
        a[pos]=val;
        n=n+1;
}//end of insert()


void adel()      //deleting an array element
{
        printf("\nEnter the position of the element to be deleted:\t");
        scanf("%d",&pos);
        val=a[pos];
        for(i=pos;i<n-1;i++)
        {
                a[i]=a[i+1];
        }
        n=n-1;
        printf("\nThe deleted element is =%d",val);
}//end of delete()

void asearch()   //searching an array element
{

 printf("\nEnter the element to be searched:\t");

  scanf("%d",&key);

  for(i=0;i<n;i++)
        {
                if(a[i]==key)
                {
                        printf("\nThe element is present at position %d",i);
                        break;
                }
        }

 if(i==n)
        {
                printf("\nThe search is unsuccessful");
        }
}
int slmenu()
{
    int n=0;
    while(n<1 || n>3)
    {

        printf("\n1:At front\n2:At end\n3:At center\nEnter your choice:");
        scanf("%d",&n);
        if(n<1||n>3)
        {
            printf("\nWrong choice!!\n");
        }
        return n;
    }
}
int slmenu1()
{
    int n=0;
    while(n<1 || n>5)
    {

        printf("\n1:At front\n2:At end\n3:At center\n4:Search and delete\n5:Delete whole list\nEnter your choice:");
        scanf("%d",&n);
        if(n<1||n>5)
        {
            printf("\nWrong choice!!\n");
        }
        return n;
    }
}
struct node* slcreate(int info)
{
    t=malloc(1*sizeof(node));
    if(t!=NULL)
    {
        t->info=info;
        t->next=NULL;
    }
    return t;

}

void slinsert()
{

    printf("\nWhere to insert??\n");
    int n,info;
    n=slmenu();
    struct node *x,*p1,*p2;
    switch(n)
    {
    case 1:
        printf("\nEnter info:");
        scanf("%d",&info);
        x=slcreate(info);
        x->next=start;
        start=x;
        break;
    case 2:
        printf("\nEnter info:");
        scanf("%d",&info);
        x=slcreate(info);
        t=start;
        if(t==NULL)
        {
            x->next=start;
            start=x;
        }
        else
        {
            while(t->next!=NULL)
                t=t->next;
            t->next=x;
        }
        break;
    case 3:
        p1=start;
        p2=start;
        while(p2!=NULL)
        {

            if(p2->next!=NULL && p2->next->next!=NULL)
            {
                p2=p2->next->next;
                p1=p1->next;
            }
            else
                break;
        }
        printf("\nEnter info:");
        scanf("%d",&info);
        x=slcreate(info);
        x->next=p1->next;
        p1->next=x;
        break;

    }
    printf("\nNode inserted!!\n");
}

void sldel()
{
    printf("\nWhere to delete??\n");
    int n;
    int info;
    n=slmenu1();
    node *x,*p1,*p2;
    switch(n)
    {
    case 1:
        if(start==NULL)
        {
            printf("\nNo Node present!!\n");
            return;
        }
        else
        {
            x=start;
            start=start->next;
            free(x);
        }
        break;
    case 2:

        t=start;
        if(t==NULL)
        {
            printf("\nNo Node present!!\n");
            return;
        }
        else
        {
            while(t->next->next!=NULL)
                t=t->next;
            x=t->next;
            t->next=NULL;
            free(x);

        }
        break;
    case 3:
        p1=start;
        p2=start;
        if(p1==NULL)
        {
            printf("\nNo Node present!!\n");
            return;
        }
        while(p2!=NULL)
        {

            if(p2->next!=NULL && p2->next->next!=NULL && p2->next->next->next!=NULL )
            {
                p2=p2->next->next;
                p1=p1->next;
            }
            else
                break;
        }
        x=p1->next;
        p1->next=p1->next->next;
        free(x);

        break;
    case 4:

        printf("\nEnter info to search:");
        scanf("%d",&info);
        t=start;
        if(start->info==info)
        {
            printf("\nNode is present!!\n");
            start=start->next;
            free(t);
            printf("\nNode deleted!!\n");
            return;
        }
        while(t->next!=NULL)
        {
            if(t->next->info==info)
            {
                printf("\nNode is present!!\n");
                x=t->next;
                t->next=x->next;
                free(x);
                printf("\nNode deleted!!\n");
                return;
            }
            t=t->next;

        }
        printf("\nNode not present!!\n");
        return;
    case 5:
        t=start;
        while(t!=NULL)
        {
            x=t;
            t=t->next;
            free(x);
        }
        start=NULL;
        printf("\nList deleted\n");
        return;
    }
    printf("\nNode deleted!!\n");

}
void sldisplay()
{
    t=start;
    printf("\n");
    while(t!=NULL)
    {
        printf("%d -> ",t->info);
        t=t->next;
    }
}
void slsearch()
{
    int info;
    printf("\nEnter info to search:");
    scanf("%d",&info);

    t=start;
    while(t!=NULL)
    {
        if(t->info==info)
        {
            printf("\nNode is present!!\n");
            return;
        }
        t=t->next;

    }
    printf("\nNode is not present!!");
}
node* slreverse(node *x)
{
    node *temp;
    if(x->next==NULL)
    {
        start=x;

        return x;
    }
    else
    {
        temp=slreverse(x->next);
        temp->next=x;

        temp=temp->next;
        temp->next=NULL;
    }
}
void sapush()
{
if(top==19)
  {
    printf("\nStack is full!!\n");
  }
  else
  {
    int x;
    printf("\nEnter element:");
    scanf("%d",&x);
    top++;
    stack[top]=x;
    printf("\nElement pushed!!\n");
 }
}
void sapop()
{
  if(top==-1)
  {
    printf("\nStack is empty!!Can't pop!!\n");
  }
  else
  {
    printf("\nElement popped=%d\n",stack[top]);
    top--;
  }
}
void sadisplay()
{
if(top==-1)
  {
    printf("\nStack is empty!\n");
    exit(50);
  }
  else
  {int i;
    printf("\nStack is....\n");
    for(i=top;i>=0;i--)
    {
      printf("%d\n",stack[i]);
    }
  }
}
void sasize()
{
    printf("\nSize of stack=%d",top+1);
}
void sapeek()
{
    if(top==-1)
        printf("\nStack is empty!!");
    else
    printf("\nElement at top=%d",stack[top]);
}
void qainsert(int item)
{
if( qaisFull() )
	{
		printf("Queue Overflow\n");
		return;
	}
	if( front == -1 )
		front=0;
	rear=rear+1;
	queue_arr[rear]=item ;
}
int qadel()
{
	int item;
	if( qaisEmpty() )
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	item=queue_arr[front];
front=front+1;
	return item;
}
int qapeek()
{
	if( qaisEmpty() )
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	return queue_arr[front];
}
int qaisEmpty()
{
	if( front==-1 || front==rear+1 )
		return 1;
	else
		return 0;
}
int qaisFull()
{
	if( rear==MAX-1 )
		return 1;
	else
		return 0;
}

void qadisplay()
{
    int i;

	if ( qaisEmpty() )
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue is :\n\n");

	for(i=front;i<=rear;i++)
		printf("%d  ",queue_arr[i]);

	printf("\n\n");
}
void btacreate_tree(struct bnode *root, int tree[], int i)
{
    if(root==NULL)
        return;
    if(i*2<=n)
    {
        struct bnode* temp1 = (struct bnode*)malloc(sizeof(struct bnode));
        temp1->data = tree[i*2];
        root->left = temp1;
    }
    else
        root->left=NULL;
    if(i*2+1<=n)
    {
        struct bnode* temp2 = (struct bnode*)malloc(sizeof(struct bnode));
        temp2->data = tree[i*2+1];
        root->right = temp2;
    }
    else
        root->right=NULL;
    btacreate_tree(root->left, tree, i*2);
    btacreate_tree(root->right, tree,i*2+1);
}
void btainorder(struct bnode* root)
{
    if(root!=NULL)
    {
        btainorder(root->left);
        printf("%d ", root->data);
        btainorder(root->right);
    }
}
void btapreorder(struct bnode* root)
{
    if(root!=NULL)
    {
        printf("%d ", root->data);
        btapreorder(root->left);
        btapreorder(root->right);
    }
}
void btapostorder(struct bnode* root)
{
    if(root!=NULL)
    {
        btapostorder(root->left);
        btapostorder(root->right);
         printf("%d ", root->data);
    }
}
void htsamax_heapify(int *heap, int i)
{
    if(i>n)
        return;
     if((2*i+1)<=n)
    {
        int large;
        if(heap[2*i]>heap[2*i+1])
            large = heap[2*i];
        else
            large = heap[2*i+1];
        if(heap[i]<large)
        {
            int temp = heap[i];
            heap[i] = large;
            if(large==heap[2*i])
            {
                heap[2*i] = temp;
                htsamax_heapify(heap,2*i);
            }
            else
            {
               heap[2*i+1] = temp;
               htsamax_heapify(heap,2*i+1);
            }
        }
    }
    if(2*i<=n && heap[i]<heap[2*i])
    {
        int tem = heap[i];
        heap[i] = heap[2*i];
        heap[2*i] = tem;
        htsamax_heapify(heap,2*i);
    }
}
void htsabuild_max_heap(int *heap, int i)
{
    if(i==0)
        return;
    if((2*i+1)<=n)
    {
        int large;
        if(heap[2*i]>heap[2*i+1])
            large = heap[2*i];
        else
            large = heap[2*i+1];
        if(heap[i]<large)
        {
            int temp = heap[i];
            heap[i] = large;
            if(large==heap[2*i])
            {
                heap[2*i] = temp;
                htsamax_heapify(heap,2*i);
            }
            else
            {
               heap[2*i+1] = temp;
               htsamax_heapify(heap,2*i+1);
            }
        }
    }
    if(heap[i]<heap[2*i])
    {
        int tem = heap[i];
        heap[i] = heap[2*i];
        heap[2*i] = tem;
        htsamax_heapify(heap,2*i);
    }
        htsabuild_max_heap(heap, i-1);
}

void htsamin_heapify(int *heap, int i)
{
    if(i>n)
        return;
    if((2*i+1)<=n)
    {
        int small;
        if(heap[2*i]<heap[2*i+1])
            small = heap[2*i];
        else
            small = heap[2*i+1];
        if(heap[i]>small)
        {
            int temp = heap[i];
            heap[i] = small;
            if(small==heap[2*i])
            {
                heap[2*i] = temp;
                htsamin_heapify(heap,2*i);
            }
            else
            {
               heap[2*i+1] = temp;
               htsamin_heapify(heap,2*i+1);
            }
        }
    }
    if(2*i<=n && heap[i]>heap[2*i])
    {
        int tem = heap[i];
        heap[i] = heap[2*i];
        heap[2*i] = tem;
        htsamin_heapify(heap,2*i);
    }
}
void htsabuild_min_heap(int *heap, int i)
{
    if(i==0)
        return;
    if((2*i+1)<=n)
    {
        int small;
        if(heap[2*i]<heap[2*i+1])
            small = heap[2*i];
        else
            small = heap[2*i+1];
        if(heap[i]>small)
        {
            int temp = heap[i];
            heap[i] = small;
            if(small==heap[2*i])
            {
                heap[2*i] = temp;
                htsamin_heapify(heap,2*i);
            }
            else
            {
               heap[2*i+1] = temp;
               htsamin_heapify(heap,2*i+1);
            }
        }
    }
    if(2*i<=n && heap[i]>heap[2*i])
    {
        int tem = heap[i];
        heap[i] = heap[2*i];
        heap[2*i] = tem;
        htsamin_heapify(heap,2*i);
    }
    htsabuild_min_heap(heap, i-1);
}

void htsaheap_sort(int *heap)
{
    if(n==0)
        return;
    htsamax_heapify(heap,1);

    int temp = heap[1];
    heap[1] = heap[n];
    heap[n] = temp;
    n--;
    htsaheap_sort(heap);
}
struct avlnode* avlsearch(avlnode* ptr,int skey)
{
    if(!ptr)
    {
        printf("Key not found");
        return NULL;
    }

    if(ptr->info>skey)
        return avlsearch(ptr->rchild,skey);
    else if(ptr->info<skey)
        return avlsearch(ptr->lchild,skey);
    else return ptr;
}
void avlpreorder(avlnode * ptr)
{
    if(!ptr)
        return ;
    printf("%d ",ptr->info);
    avlpreorder(ptr->lchild);
    avlpreorder(ptr->rchild);
    return;
}
void avlinorder(avlnode* ptr)
{
    if(!ptr)
        return ;
    avlinorder(ptr->lchild);
    printf("%d ",ptr->info);
    avlinorder(ptr->rchild);
}

void avlpostorder(avlnode* ptr)
{
    if(!ptr)
        return ;
    avlpostorder(ptr->lchild);
    avlpostorder(ptr->rchild);
    printf("%d ",ptr->info);
}
int avlheightnode(avlnode* ptr,int p)
{
    if(!ptr)
        return 0;
    if(ptr->info ==p)
    {
            return avlheight(ptr);
    }

}
void avlarry(avlnode* root)
{
    if(root!=NULL)
    {
        avlarry(root->lchild);
        ar[i] = root->info;    i++;
        avlarry(root->rchild);
    }
}
void avlsucc_prede(avlnode* root, int key)
{
    i = 0;
    int j;
    avlarry(root);
    for(j=0;j<i;j++)
    {
        if(ar[j]==key)
        {
            if(j>0)
                printf("Predecessor: %d\n", ar[j-1]);
            else
                printf("No Predecessor!!!\n");
            if(j<i-1)
                printf("Successor: %d", ar[j+1]);
            else
                printf("No Successor!!!\n");
            return;
        }
    }
    if(j==i)
        printf("Key not Found");
}
avlnode * avlinsert(avlnode *T,int x)
{
    if(T==NULL)
    {
        T=(struct avlnode*)malloc(sizeof(avlnode));
        T->data=x;
        T->lchild=NULL;
        T->rchild=NULL;
    }
    else if(x > T->data)       // insert in right subtree
    {
        T->rchild=avlinsert(T->rchild,x);
        if(avlBF(T)==-2)
            if(x>T->rchild->data)
                T=avlRR(T);
            else
                T=avlRL(T);
    }
    else if(x<T->data)
    {
        T->lchild=avlinsert(T->lchild,x);
        if(avlBF(T)==2)
            if(x < T->lchild->data)
                T=avlLL(T);
            else
                T=avlLR(T);
    }

    T->ht=avlheight(T);

    return(T);
}

avlnode * avlDelete(avlnode *T,int x)
{
    struct avlnode *p;

    if(T==NULL)
    {
        printf("\nElement doesn't exist!!\n");
        return NULL;
    }
    else if(x > T->data)
    {
        T->rchild=avlDelete(T->rchild,x);
        if(avlBF(T)==2)
            if(avlBF(T->lchild)>=0)
                T=avlLL(T);
            else
                T=avlLR(T);
    }
    else if(x<T->data)
    {
        T->lchild=avlDelete(T->lchild,x);
        if(avlBF(T)==-2)    //Rebalance during windup
            if(avlBF(T->rchild)<=0)
                T=avlRR(T);
            else
                T=avlRL(T);
    }
    else
    {
        //data to be deleted is found

        if(T->rchild!=NULL)
        {
            //delete its inorder succesor
            p=T->rchild;

            while(p->lchild!= NULL)
                p=p->lchild;

            T->data=p->data;
            T->rchild=avlDelete(T->rchild,p->data);

            if(avlBF(T)==2)//Rebalance during windup
                if(avlBF(T->lchild)>=0)
                    T=avlLL(T);
                else
                    T=avlLR(T);

        }
        else
            return(T->lchild);

    }
    T->ht=avlheight(T);

    return(T);
}
int avlheight(avlnode *T)
{
    int lh,rh;
    if(T==NULL)
        return(0);

    if(T->lchild==NULL)
        lh=0;
    else
        lh=1+T->lchild->ht;

    if(T->rchild==NULL)
        rh=0;
    else
        rh=1+T->rchild->ht;

    if(lh>rh)
        return(lh);

    return(rh);
}

avlnode * avlrotateright(avlnode *x)
{
    avlnode *y;
    y=x->lchild;
    x->lchild=y->rchild;
    y->rchild=x;
    x->ht=avlheight(x);
    y->ht=avlheight(y);
    return(y);
}

avlnode * avlrotateleft(avlnode *x)
{
    avlnode *y;
    y=x->rchild;
    x->rchild=y->lchild;
    y->lchild=x;
    x->ht=avlheight(x);
    y->ht=avlheight(y);

    return(y);
}
avlnode * avlRR(avlnode *T)
{
    T=avlrotateleft(T);
    return(T);
}

avlnode * avlLL(avlnode *T)
{
    T=avlrotateright(T);
    return(T);
}

avlnode * avlLR(avlnode *T)
{
    T->lchild=avlrotateleft(T->lchild);
    T=avlrotateright(T);

    return(T);
}

avlnode * avlRL(avlnode *T)
{
    T->rchild=avlrotateright(T->rchild);
    T=avlrotateleft(T);
    return(T);
}

int avlBF(avlnode *T)
{
    int lh,rh;
    if(T==NULL)
        return(0);

    if(T->lchild==NULL)
        lh=0;
    else
        lh=1+T->lchild->ht;

    if(T->rchild==NULL)
        rh=0;
    else
        rh=1+T->rchild->ht;

    return(lh-rh);
}

void arr()
{

    int choice;
    do{
                printf("1.Create\n");
                printf("2.Display\n");
                printf("3.Insert\n");
                printf("4.Delete\n");
                printf("5.Search\n");
                printf("6.quit\n");
                printf("\nEnter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                acreate();
                                break;
                        case 2:
                                adisplay();
                                break;
                        case 3:
                                ainsert();
                                break;
                        case 4:
                                adel();
                                break;
                        case 5:
                                asearch();
                                break;
                        case 6:
                                printf("Exiting...");
                                break;
                        default:
                                printf("\nInvalid choice:\n");
                                break;
                }
        }while(choice!=6);

}
void singlell()
{

    int ch;
    while(1)
    {
        printf("\nSelect an option:\n1:Insert\n2:Search\n3:Display\n4:Delete\n5:Reverse\n6:Exit\nYour choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            slinsert();
            break;
        case 2:
            slsearch();
            break;
        case 3:
            sldisplay();
            break;
        case 4:
            sldel();
            break;
        case 5:
            slreverse(start);
            break;
        case 6:
            return ;
        default:
            printf("\nWrong choice!!");
        }
        getche();
    }

}
void stacka()
{
    int ch;

  while(1)
  {
    printf("\nSelect an option:\n1:Push\n2:Pop\n3:Size\n4:Peek\n5:Display\n6:Exit\nYour choice:");
    scanf("%d",&ch);

    switch(ch)
    {

      case 1:sapush();
            break;

      case 2:sapop();
            break;

      case 3:sasize();
            break;

      case 4:sapeek();
            break;

      case 5:sadisplay();
            break;

      case 6:exit(0);

      default:printf("\nWrong choice!!\n");
            break;
    }

  }
}
void queuea()
{


    int choice,item;
	while(1)
	{
		printf("1.Insert\n");
		printf("2.Delete\n");

printf("3.Display element at the front\n");

		printf("4.Display all elements of the queue\n");
		printf("5.Quit\n");

		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1:
			printf("Input the element for adding in queue : ");
			scanf("%d",&item);
			qainsert(item);
			break;
		case 2:
			item=qadel();
			printf("Deleted element is  %d\n",item);
			break;
		case 3:
			printf("Element at the front is %d\n",qapeek());
			break;

        case 4:
			qadisplay();
			break;

        }
	}
}
void bintree()
{

    printf("Enter the num of nodes: ");
    scanf("%d", &n);
    int tree[n+1];

    tree[0] = -1;
    int i;
    printf("Enter the tree data\n");
    for(i=1;i<n+1;i++)
        scanf("%d", &tree[i]);
    struct bnode* root = NULL;
    if(n!=0)
    {
        root = (struct bnode*)malloc(sizeof(struct bnode));
        root->data = tree[1];
        btacreate_tree(root,tree,1);
    }
    int opt;
    while(1){
    printf("Options:\n");
    printf("1.Inorder\n2.Preorder\n3.Postorder\n4.Levelorder\n5.Exit\n");
    scanf("%d", &opt);
    if(opt==1){
        btainorder(root);
        printf("\n");}
    else if(opt==2){
        btapreorder(root); printf("\n");}
   else if(opt==3){
        btapostorder(root);  printf("\n");}
    else if(opt==4)
    {
        for(i=1;i<n+1;i++)
            printf("%d ", tree[i]);
         printf("\n");
    }
    else
        break;
    }
}
void htsa()
{
    int n;
    printf("\nEnter the Number of elements in heap: ");
    scanf("%d", &n);
    int heap[n+1];
    heap[0] = -1;
    int i, opt;
    for(i=1;i<n+1;i++)
        scanf("%d", &heap[i]);
    while(1)
    {
        printf("\nOptions:\n");
        printf("\n1. Build max heap\n2. Build min heap\n3. Heap sort\n4. Display heap\n5. Exit");
        scanf("%d", &opt);
        switch(opt)
        {
        case 1:
            htsabuild_max_heap(heap, (n+1)/2);
            break;
        case 2:
            htsabuild_min_heap(heap, (n+1)/2);
            break;
        case 3:
            i = n;
            htsabuild_max_heap(heap, (n+1)/2);
            htsaheap_sort(heap);
            n = i;
            break;
        case 4:
            printf("\n");
            for(i=1;i<n+1;i++)
                printf("%d ", heap[i]);
            printf("\n");
            break;
        case 5:
            break;
        }
        if(opt==5)
            break;
    }
}
void avl()
{
    int choice,key;
    printf("\n1.Search\n2.Insert\n3.Delete\n4.Preorder\n5.postorder\n6.inorder\n7.height of tree \n8.find Successor and predecessor");
    printf("\n9.Height of a node\n10.Quit\n\nEnter your choice:");
    scanf("%d",&choice);
    do{
            switch(choice)
        {
        case 1:
            printf("Enter the number you want to search:");
            scanf("%d",&key);
            ptr=avlsearch(root,key);
                if(ptr) printf("\nKey present");
                else printf("\n key not present");
            break;

        case 2:
            printf("Enter the number you want to insert:");
            scanf("%d",&key);
            root=avlinsert(root,key);

            break;
        case 3:
            printf("Enter the number you want to delete:");
            scanf("%d",&key);
            root=avlDelete(root,key);

            break;
        case 4:
            avlpreorder(root);
            break;
        case 5:
            avlpostorder(root);
            break;
        case 6:
            avlinorder(root);
            break;
        case 7:
            printf("The height of the tree is:%d",avlheight(root));
            break;
        case 8:
            printf("Enter the node value: ");
            scanf("%d",&key);
            avlsucc_prede(root, key);
            break;
        case 9:
            printf("Enter the node value you want to find height of:");
            scanf("%d",&key);
            printf("Height of the node is:%d",avlheightnode(root,key));
            break;
        case 10:
            printf("Exiting...");
            break;
        default:
            printf("Enter correct choice\n");
        }
        if(choice!=10)
        {
            printf("Enter your choice again:");
            scanf("%d",&choice);
        }
    }while(choice!=10);
}
int mins(int x, int y)
{
    return (x<=y)? x : y;
}
int linsearch(int arr[],int n,int x)
{
    int i;
    for (i=0; i<n; i++)
        if (arr[i] == x)
         return i;
    return -1;
}
int binsearch(int arr[],int l,int r,int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binsearch(arr, l, mid-1, x);
        return binsearch(arr, mid+1, r, x);
   }
   return -1;
}
int fibsearch(int arr[],int x,int n)
{
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;
    while (fibM < n)
    {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM  = fibMMm2 + fibMMm1;
    }
    int offset = -1;
    while (fibM > 1)
    {
        int i = mins(offset+fibMMm2, n-1);
        if (arr[i] < x)
        {
            fibM  = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if (arr[i] > x)
        {
            fibM  = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else return i;
    }
    if(fibMMm1 && arr[offset+1]==x)
        return offset+1;
    return -1;
}
void srch()
{
    int a[max],n,i,t,k,choice;
    printf("\nChoices for different type of searching:-");
    printf("\n1.LINEAR SEARCH");
    printf("\n2.BINARY SEARCH");
    printf("\n3.FIBONACCI SEARCH");
    printf("\n4.EXIT");
    do
    {
        printf("\nEnter the choice for searching:-");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:system("cls");
                   printf("\nLinear Search\n");
                   printf("\nEnter the no. of elements in array:");
                   scanf("%d",&n);
                   printf("\nEnter the elements of array:");
                   for(i=0;i<n;i++)
                    scanf("%d",&a[i]);
                   printf("\nEnter the element wanted to be searched in array:");
                   scanf("%d",&k);
                   t=linsearch(a,n,k);
                   (t == -1)? printf("Element is not present in array")
                            : printf("Element is present at index %d",t);
                   break;
            case 2:system("cls");
                   printf("\nBinary Search\n");
                   printf("\nEnter the no. of elements in array:");
                   scanf("%d",&n);
                   printf("\nEnter the elements of array:");
                   for(i=0;i<n;i++)
                     scanf("%d",&a[i]);
                   printf("\nEnter the element wanted to be searched in array:");
                   scanf("%d",&k);
                   t=binsearch(a,0,n-1,k);
                   (t == -1)? printf("Element is not present in array")
                            : printf("Element is present at index %d",t);
                   break;
            case 3:system("cls");
                   printf("\nFibonacci Search\n");
                   printf("\nEnter the no. of elements in array:");
                   scanf("%d",&n);
                   printf("\nEnter the elements of array(space separated):");
                   for(i=0;i<n;i++)
                     scanf("%d",&a[i]);
                   printf("\nEnter the element wanted to be searched in array:");
                   scanf("%d",&k);
                   t=fibsearch(a,k,n);
                   (t == -1 )? printf("Element is not present in array")
                             : printf("Element is present at index %d",t);
                   break;
            case 4:printf("***Program is quiting!!!***\n***Thank-You for using our Program***\n***Have a nice day!!!***\n");
                   exit(5);
            default:printf("WRONG CHOICE");
                    break;
        }
    }while(choice>0 && choice<4);
return 0;
}
void soort()
{
    int arr[MAX],temp,i,n,j,k,min;
    system("cls");
    printf("DIFFERENT TYPES OF SORTING\n1.Bubble Sort\n2.Linear sort\n3.Selection Sort\n4.Quick Sort\n5.Merge Sort");
    printf("\nEnter Choice:");
    int ch;
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            printf("enter the no.of elements in array\n");
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                scanf("%d",&arr[i]);
            }
            for(i=0;i<n-1;i++)
            {
                for(j=0;j<n-i-1;j++)
                {
                    if(arr[j]>arr[j+1])
                    {
                        temp=arr[j];
                        arr[j]=arr[j+1];
                        arr[j+1]=temp;
                    }
                }
            }
            printf("sorted list is\n");
            for(i=0;i<n;i++)
            printf("%d\n",arr[i]);
            break;
        case 2:
            printf("enter the no.of elements in array\n");
            scanf("%d",&n);
            for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
            for(i=0;i<n;i++)
            {
                k=arr[i];
                for(j=i-1;j>=0 && k<arr[j];j--)
                arr[j+1]=arr[j];
                arr[j+1]=k;
            }
            printf("sorted list is\n");
            for(i=0;i<n;i++)
            printf("%d\n",arr[i]);
            break;
        case 3:
            printf("enter the no.of elements in array\n");
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                scanf("%d",&arr[i]);
            }
            for(i=0;i<n-1;i++)
            {
                min=i;
                for(j=i+1;j<n;j++)
                {
                    if(arr[min]>arr[j])
                    min=j;
                }
                if(i!=min)
                {
                    temp=arr[i];
                    arr[i]=arr[min];
                    arr[min]=temp;
                }
            }
            printf("the sorted order of no. is\n");
            for(i=0;i<n;i++)
            printf("%d\n",arr[i]);
            printf("\n");
            break;
        case 4:
            qqsort();
            break;
        case 5:
            msort();
            break;
}
}
void qqsort()
{
    int arr[MAX],n,i;
	printf("Enter the number of elements : ");
	scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter element %d : ",i+1);
		scanf("%d",&arr[i]);
	}
	quick(arr,0,n-1);
	printf("Sorted list is :\n");
	for(i=0;i<n;i++)
       	printf("%d\n",arr[i]);
	printf("\n");
}
void quick(int arr[],int low,int up)
{
	int pivloc;
	printf("\n");
	if(low>=up)
        return ;
	pivloc = part(arr,low,up);
	quick(arr,low,pivloc-1);
	quick(arr,pivloc+1,up);
}
int part(int arr[], int low, int up)
{	int temp,i,j,pivot;
	i=low+1;
	j=up;
	pivot=arr[low];
	while( i <= j )
	{	while( (arr[i] < pivot) && (i<up) )
			i++;
		while( arr[j] > pivot )
			j--;
		if(i < j)
		{	temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			i++;
			j--;
		}
		else
		{i++;
		}
	}

	arr[low]=arr[j];
	arr[j]=pivot;
	return j;
}
void msort()
{
    int arr[MAX],i,n;
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&arr[i]);
	}
	merge_sort(arr,0,n-1);
	printf("\nSorted list is :\n");
	for( i = 0 ; i<n ; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
void merge_sort(int arr[], int low,int up)
{
int mid;
	int temp[MAX];
	if(low<up)
    {
        mid=(low+up)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,up);
        mergee(arr,temp,low,mid,mid+1,up);
        copyy(arr,temp,low,up);
    }
}
void mergee(int arr[], int temp[],int low1, int up1, int low2, int up2 )
{
	int i=low1;
	int j=low2;
	int k=low1;

	while((i<=up1 )&& (j<=up2 ))
	{
		if( arr[i] <= arr[j] )
			temp[k++]=arr[i++];
		else
			temp[k++]=arr[j++];
	}
	while(i<=up1)
		temp[k++]=arr[i++];
	while(j<=up2)
		temp[k++]=arr[j++];
}
void copyy(int arr[], int temp[], int low,int up)
{
	int i;
	for(i=low;i<up;i++)
		arr[i]=temp[i];
}
void bstree()
{
    struct bstnode* root=NULL,*ptr;
    int choice,key;

    printf("1.Search\n2.Insert\n3.Delete\n4.Preorder\n5.postorder\n6.inorder\n7.height of tree \n8.find Successor and predecessor");
    printf("\n9.height of a node\n10.Quit\n\nEnter your choice:");
    scanf("%d",&choice);

    do{

        switch(choice)
        {
        case 1:
            printf("\nEnter the number you want to search:");
            scanf("%d",&key);
            ptr=bstsearch(root,key);
                if(ptr) printf("\nKey present");
                else printf("\n key not present");
                break;
        case 2:
            printf("Enter the number you want to insert:");
            scanf("%d",&key);
            root=bstinsert(root,key);
            break;
        case 3:
            printf("Enter the number you want to delete:");
            scanf("%d",&key);
            root=bstdel(root,key);
            break;
        case 4:
            bstpreorder(root);
            break;
        case 5:
            bstpostorder(root);
            break;
        case 6:
            bstinorder(root);
            break;
        case 7:
            printf("The height of the tree is:%d",bstheight(root));
            break;
        case 8:
            printf("Enter the node value: ");
            scanf("%d",&key);
            bstsucc_prede(root, key);
            break;
        case 9:
            printf("Enter the node value you want to find height of:");
            scanf("%d",&key);
            printf("Height of the node is:%d",bstheightnode(root,key));
            break;
        case 10:
            printf("Exiting...");
            break;
        default:
            printf("Enter correct choice\n");
        }
        if(choice!=10)
        {
            printf("Enter your choice again:");
            scanf("%d",&choice);
        }
    }while(choice!=10);
}
bstnode* bstsearch(bstnode* ptr,int skey)
{
    if(!ptr)
    {
        printf("Key not found");
        return NULL;
    }

    if(ptr->info>skey)
        return bstsearch(ptr->rchild,skey);
    else if(ptr->info<skey)
        return bstsearch(ptr->lchild,skey);
    else return ptr;
}
bstnode* bstinsert(bstnode* ptr,int ikey)
{
    if(ptr==NULL)
    {
        bstnode* temp=(bstnode*)malloc(sizeof(bstnode));
        temp->info=ikey;
        temp->rchild=NULL;
        temp->lchild=NULL;
        return temp;
    }

    if(ptr->info<ikey)
        ptr->rchild=bstinsert(ptr->rchild,ikey);
    else if(ptr->info>ikey)
        ptr->lchild=bstinsert(ptr->lchild,ikey);
    else printf("Duplicate key\n");
    return ptr;
}
void bstpreorder(bstnode * ptr)
{
    if(!ptr)
        return ;
    printf("%d ",ptr->info);
    bstpreorder(ptr->lchild);
    bstpreorder(ptr->rchild);
    return;
}
void bstinorder(bstnode* ptr)
{
    if(!ptr)
        return ;
    bstinorder(ptr->lchild);
    printf("%d ",ptr->info);
    bstinorder(ptr->rchild);
}

void bstpostorder(bstnode* ptr)
{
    if(!ptr)
        return ;
    bstpostorder(ptr->lchild);
    bstpostorder(ptr->rchild);
    printf("%d ",ptr->info);
}

int bstheight(bstnode *ptr)
{
    if(!ptr)
        return 0;

    int x=bstheight(ptr->lchild);
    int y=bstheight(ptr->rchild);

    if(x>y)
        return x+1;
    else return y+1;
}
bstnode* bstdel(bstnode* ptr,int dkey)
{
    if(ptr==NULL)
    {
        printf("Key not found\n");
        return NULL;
    }
    if(ptr->info>dkey)
        return bstdel(ptr->rchild,dkey);
    else if(ptr->info<dkey)
        return bstdel(ptr->lchild,dkey);
    else
    {
            if(ptr->rchild && ptr->lchild)
            {
                bstnode* succ=ptr->rchild;
                while(succ->lchild)
                    succ=succ->lchild;

                ptr->info=succ->info;
                ptr->rchild=bstdel(succ->rchild,succ->info);

            }

            else
            {
                bstnode* tmp=ptr;
                if(ptr->lchild!=NULL)
                    ptr=ptr->lchild;
                else if(ptr->rchild)
                    ptr=ptr->rchild;
                else ptr=NULL;
                free(tmp);
            }
    }
    return ptr;
}
int bstheightnode(bstnode* ptr,int p)
{
    if(!ptr)
        return 0;
    if(ptr->info ==p)
    {
            return bstheight(ptr);
    }

}
void bstarry(bstnode* root)
{
    if(root!=NULL)
    {
        bstarry(root->lchild);
        ar[i] = root->info;
        i++;
        bstarry(root->rchild);
    }
}
void bstsucc_prede(bstnode* root, int key)
{
    i = 0;
    int j;
    bstarry(root);
    for(j=0;j<i;j++)
    {
        if(ar[j]==key)
        {
            if(j>0)
                printf("Predecessor: %d\n", ar[j-1]);
            else
                printf("No Predecessor!!!\n");
            if(j<i-1)
                printf("Successor: %d", ar[j+1]);
            else
                printf("No Successor!!!\n");
            return;
        }
    }
    if(j==i)
        printf("Key not Found");
}


