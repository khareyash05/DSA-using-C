#include"prototype.h"
#include"Definitions.c"
int main()
{
    int choice;
    printf("DEVELOPER - NAMAN RUHELA(15103074) & ANKIT PALIWAL(15103077)");
    printf("\nChoices are:-\n");
    printf("1.ARRAY");
    printf("\n2.SINGLE LINKED LIST");
    printf("\n3.STACK USING ARRAY");
    printf("\n4.QUEUE USING ARRAY");
    printf("\n5.BINARY TREE USING ARRAY");
    printf("\n6.HEAP TREE & SORT USING ARRAY");
    printf("\n7.AVL TREE");
    printf("\n8.BS TREE");
    printf("\n9.SEARCHING");
    printf("\n10.SORTING");
    printf("\n11.Exit");
    do
    {
     printf("\nEnter choice:");
     scanf("%d",&choice);
     switch(choice)
     {
         case 1:system("cls");
                printf("ARRAY");
                arr();
                break;
         case 2:system("cls");
                printf("SINGLE LINKED LIST");
                singlell();
                break;
         case 3:system("cls");
                printf("STACK USING ARRAY");
                stacka();
                break;
         case 4:system("cls");
                printf("QUEUE USING ARRAY");
                queuea();
                break;
         case 5:system("cls");
                printf("BINARY TREE USING ARRAY");
                bintree();
                break;
         case 6:system("cls");
                printf("HEAP TREE AND SORT USING ARRAY");
                htsa();
                break;
         case 7:system("cls");
                printf("AVL TREE");
                avl();
                break;
         case 8:system("cls");
                printf("BINARY SEARCH TREE");
                bstree();
                break;
         case 9:system("cls");
                printf("SEARCHING");
                srch();
                break;
         case 10:system("cls");
                printf("SORTING");
                soort();
         case 11:printf("***Program is quiting!!!***\n***Thank-You for using our Program***\n***Have a nice day!!!***\n");
                exit(0);
         default:printf("\n###WRONG CHOICE###");
                 break;
     }
    }while(choice<=11 && choice>0);
    return 0;
}
