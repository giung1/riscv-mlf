#include "proc.h"

  struct node 
{ 
    struct proc proc; 
  
    struct node *next; 
}node; 
  
  struct queue 
  {
    struct node *head;
    
    struct node *last;
  
    int size;
  }queue;

  struct mlf
  {
    struct queue mlf[4];
  };
  

  void enqueue(struct queue *queue, struct proc proc);

  struct proc* dequeu(struct queue *queue);