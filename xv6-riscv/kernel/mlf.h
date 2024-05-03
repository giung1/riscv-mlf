
  struct node 
  { 
    struct proc *proc; 
  
    struct node *next; 
  }node; 
  
  struct queue 
  {
    struct node *head;
    
    struct node *last;
  
    struct spinlock lock;

  }queue;

  struct mlf
  {
    struct queue levels[MAXLEVEL];
  };
  

  void enqueue(struct queue *queue, struct proc *proc);

  struct proc* dequeue(struct queue *queue);

  void enqueueMlf( struct mlf *mlf, struct proc *proc);

  struct proc* dequeueMlf(struct mlf *mlf);
  