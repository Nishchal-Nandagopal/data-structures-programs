#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
//#include<process.h>
#define QUE_SIZE 3
int item, front = 0, rear = -1, q[10];
 
void insertRear() {
                if(rear == QUE_SIZE-1){
                                printf("Queue Overflow \n");
                               
                }
                rear = rear+1;
                q[rear] = item;
}
 
int deleteFront() {
                if(front>rear){
                                front = 0;
                                rear = -1;
                                return -1;
                }
                return q[front++];
}
 
void displayQ() {
                int i;
                if(front>rear){
                                printf("queue is empty\n");
                }
                printf("Contents of the queue\n");
                for(i=front;i<=rear;i++){
                                printf("%d\n",q[i]);
                }
}
 
int main() {
                int choice = 0;
                for(;;){
                                printf("\n1:insertrear\n2:deletefront\n3:display\n4:exit\n");
                                printf("enter the choice\n");
                                scanf("%d",&choice);
 
                                switch(choice){
                                                case 1: printf("Enter the item to be inserted\n");
                                                                                                                scanf("%d",&item);
                                                                                                                insertRear();
                                                                                                                break;
                                                case 2: item = deleteFront();
                                                                                                                if(item == -1)
                                                                                                                                printf("queue is empty\n");
                                                                                                                else
                                                                                                                                printf("item deleted = %d\n", item);
                                                                                                                break;
                                                case 3: displayQ();
                                                                                                                break;
                                                default:exit(0);

                                }
                }
}
