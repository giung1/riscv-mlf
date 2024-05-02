#include "proc.h"

  struct node 
{ 
    struct proc proc; 
  
    struct node *next; 
}node; 
  
  struct level {

    struct node *head;
    
    struct node *last;
  
    int size;
  }level;

  void insertNode(struct level *level, struct proc proc);

  struct proc* levelPop(struct level *level);