int counterFB = 0;
int counterGS = 0;


struct nodeFB
{
	int id;
	int age;
	struct nodeFB *next;
};

struct nodeGS
{
	int id;
	struct nodeGS *next;
};

struct newNodeFB
{
	int id;
	int age;
	struct newNodeGS *next;
};

struct newNodeGS
{
	int id;
	struct newNodeFB *next;
};

void printFB(struct nodeFB *startFB){
    struct nodeFB *iter = startFB;
    for(int i=0;i<counterFB;i++){//bedo sort
        
        for(int j=0;j<counterFB-1;j++){
            
            if((iter -> id) > (iter -> next -> id)){
        
                struct nodeFB *temp = (struct nodeFB*) malloc(sizeof(struct nodeFB));
                temp -> id = iter -> id;
                temp -> age = iter -> age;
                iter -> id = iter -> next -> id;
                iter -> age = iter -> next -> age;
                iter -> next -> id = temp -> id;
                iter -> next -> age = temp -> age;
                
            }
            iter = iter -> next; 
        }
        iter = startFB;
    }

    while(startFB != NULL){
        
        printf("%d %d\n",startFB -> id,startFB -> age);
        startFB = startFB -> next;
    }
    
    printf("\n");
    
}

void printGS(struct nodeGS *startGS){
    struct nodeGS *iter = startGS;

    for(int i=0;i<counterGS;i++){//bedo sort
        
        for(int j=0;j<counterGS-1;j++){
            
            if((iter -> id) < (iter -> next -> id)){
                
                struct nodeGS *temp = (struct nodeGS*) malloc(sizeof(struct nodeGS));
                temp -> id = iter -> id;
                iter -> id = iter -> next -> id;
                iter -> next -> id = temp -> id;
                
            }
            iter = iter -> next; 
        }
        iter = startGS;
    }
    
    while(startGS != NULL){
        
        printf("%d\n",startGS -> id);
        startGS = startGS -> next;
    }
    
    printf("\n");
    
}

void insertFB(struct nodeFB **startFB,int id,int age){
    counterFB++;

    while((*startFB) != NULL){
        
        startFB = &((*startFB)->next);
    
    }
    
    (*startFB) = (struct nodeFB*)malloc(sizeof(struct nodeFB));
    (*startFB) -> age = age;
    (*startFB) -> id = id;
    (*startFB) -> next = NULL;
    
}

void insertGS(struct nodeGS **startGS,int id){
    counterGS++;
    
    while((*startGS) != NULL){
        
        startGS = &((*startGS)->next);
        
    }
    
    (*startGS) = (struct nodeGS*)malloc(sizeof(struct nodeGS));
    (*startGS) -> id = id;
    (*startGS) -> next = NULL;

}

void createFinalList(struct newNodeFB **startNewFB,struct nodeFB *startFB,struct nodeGS *startGS){
    
    (*startNewFB) = (struct newNodeFB*)malloc(sizeof(struct newNodeFB));
    struct newNodeGS *startNewGS = (struct newNodeGS*)malloc(sizeof(struct newNodeGS));
    
    for(int i = 0;i < ((counterFB+counterGS)/2);i++){
        
        (*startNewFB) -> next = (struct newNodeGS*)malloc(sizeof(struct newNodeGS));
        //(*startNewFB) -> next = NULL;
        startNewGS = (*startNewFB) -> next;
        (*startNewFB) -> id = startFB -> id;
        (*startNewFB) -> age = startFB -> age;
        startFB = startFB -> next;
        startNewGS -> next = (struct newNodeFB*)malloc(sizeof(struct newNodeFB));  
        //startNewGS -> next = NULL;
        startNewFB = &(startNewGS -> next);
        startNewGS -> id = startGS -> id;
        startGS = startGS -> next;
        
    }
    
}

void printAll(struct newNodeFB *startNewFB){
    
    struct newNodeGS *startNewGS = NULL;
    
    for(int i=0;i<counterFB;i++){
    
    if(startNewFB != NULL){
        
        printf("%d %d\n",startNewFB -> id,startNewFB -> age);
        startNewGS = (startNewFB) -> next;
        
    }
    else
        break;
    
    if(startNewGS != NULL){
        
        printf("%d\n",startNewGS -> id);
        startNewFB = startNewGS -> next;
        
    }
    else
        break;
    
    }
    
}

// You must write all the function definitions to be used in this lab into this file. 
// You may also write other functions that may be called from our functions.
// Do not make any changes to the main.c file.
// Upload function.h file to the system as StudentNumber.h.



