/**
						PROJECT NAME:- 	VISUALIZATION OF BST
Data structures used:- BST(Binary Search Tree), Array, Linked List

Version - 1.0
Date - 10 MAY 2020
Done By -  VIKAS DONGARE     (ROLL NO - 15)
		   
**/

#include<graphics.h>
#include<math.h>
#include <bits/stdc++.h> 
#define offset 19
using namespace std;


// -----------------------------------------------------------------------------------------------------------------

//CLASSES USED IN OVERALL PROJECT
class tree_node											//TO CREATE NODE OF THE TREE IN BST
{
public:
        int idata;
        tree_node *lchild,*rchild;
};

class tree												//TO CREATE OVERALL TREE
{
public:
        tree_node *root;

        tree()
        {
            root=NULL;
        }

        void create();									//ADD NEW ELEMENT TO TREE
        void insert();									//CREATE A TREE
        void inorder_recurssive(tree_node *temp);
};

// -----------------------------------------------------------------------------------------------------------------

//GLOBAL VARIABLES USED IN OVERALL PROJECT
tree t;								
string tree_arr[offset];
int element=0;

// -----------------------------------------------------------------------------------------------------------------

//FUNCTIONS USED IN OVERALL PROJECT
void node_struct(int ,int );				//TO CREATE NODE IN THE GRAPHICS
void tree_creation();									//TO CREATE TREE IN GRAPHICS
void gettree();											//GET ELEMENTS OF TREE FROM USER
void printGivenLevel(tree_node* root, int level);		//READS NODES AT A GIVEN LEVEL
int height(tree_node* node);							/* COMPUTE THE "HEIGHT" OF A TREE -- THE NUMBER OF NODES ALONG THE LONGEST PATH 
														   FROM THE ROOT NODE DOWN TO THE DARTHEST LEAF NODE.*/
void printLevelOrder(tree_node* root);					// FUNCTION TO PRINT THE LEVEL ORDER TRAVERSAL OF A TREE 
void space(int no);										//FUNCTION TO PRINT REQURIED NUMBER OF SPACES
void tree_name();										//FUNCTION TO PRINT HEADER NAME (TREE)
void welcome();											//FUNCTION FOR WELCOME PART OF THE PROGRAM
void graphics();										//FUNCTION FOR THE GRAPHICS PART OF THE PROGRAM

// -----------------------------------------------------------------------------------------------------------------


void tree::create()		//ADD NEW ELEMENT TO TREE
{
			root= new tree_node();
			cout<<"\nEnter element at root : ";
			cin>>root->idata;
			root->lchild=NULL;
			root->rchild=NULL;
			cout<<"\t\t!!! Root created succesfully !!!\n";
}

void tree::insert()			//CREATE A TREE
{
    tree_node *temp,*p;
    if(root==NULL)
        create();
    temp=root;
    int d;
    label:
    cout<<"\nEnter Number : ";
    cin>>d;
    while(1)
    {
        if(d<temp->idata)
        {
            if(temp->lchild==NULL)
            {
                p=new tree_node;
                p->lchild=NULL;
                p->rchild=NULL;
                p->idata=d;
                temp->lchild=p;
                cout<<"\t\t!!! Element Added succesfully !!!\n";
                return;
            }
            else
                temp=temp->lchild;
        }
        else if(d>temp->idata)
        {
            if(temp->rchild==NULL)
            {
                p=new tree_node;
                p->lchild=NULL;
                p->rchild=NULL;
                p->idata=d;
                temp->rchild=p;
                cout<<"\t\t!!! Element Added succesfully !!!\n";
                return;
            }
            else
                temp=temp->rchild;
        }
        else if(d==temp->idata)
        {
            cout<<"\t!!! DATA IS ALREADY ADDED !!!";
            cout<<"\n\t!!! TRY AGAIN !!!";
            goto label;
        }

    }
}

void tree::inorder_recurssive(tree_node *temp)
{
			if(temp!=NULL)
			{
			    inorder_recurssive(temp->lchild);
				cout<<temp->idata<<" ";
				inorder_recurssive(temp->rchild);
			}
}

// -----------------------------------------------------------------------------------------------------------------


void node_struct(int LEFT=10,int TOP=10)			//TO CREATE NODE IN THE GRAPHICS
{
    setcolor(BLACK);
    setlinestyle(SOLID_LINE,0,3);
    rectangle(LEFT-offset,TOP,LEFT,TOP+offset);
    rectangle(LEFT,TOP,LEFT+offset+6,TOP+offset);
    rectangle(LEFT+offset+6,TOP,LEFT+(2*offset)+6,TOP+offset);
}

// -----------------------------------------------------------------------------------------------------------------

void tree_creation()					//TO CREATE TREE IN GRAPHICS
{
	
	int level=1,count;
	int arr[]={312,152,472,72,232,392,553,22,102,192,272,352,432,512,592}; //ARRAY FOR OF NODE CREATION
	char char_arr[20];
  	
  	level = height(t.root);     //TO GET HOW MANY LEVELS ARE THERE IN TREE
    count = pow(2,level)-1;	   //TO GET TOTAL NODE IN THE TREE
    level = 2;					//THIS IS USED LATER ON AS A COUNTER
    for(int i=0;i<count;i++)
    {
     	node_struct(arr[i],(level*80));		//TO DRAW ACTUAL NODE
      	
     	strcpy(char_arr,tree_arr[i].c_str());		//CONVERSION FROM STRING TO CHAR* AS OUTTEXTXY USES CHAR* ARGUMENT 
		outtextxy(arr[i]+1,(level*80)+5,char_arr);	//TO PRINT NODE DATA
		
    	setcolor(LIGHTGRAY);
   		setlinestyle(SOLID_LINE,0,2);
		switch(i)								//FOR DRAWING CORRECT LINE AT CORRECT POSITION
		{
			case 1:
				line(arr[i-1]-13,((level-1)*80)+offset,arr[i]+13,(level*80));
				break;
			case 2:
				line(arr[i-2]+34,((level-1)*80)+offset,arr[i]+13,(level*80));
				break;	
			case 3:
				line(arr[i-2]-13,((level-1)*80)+offset,arr[i]+13,(level*80));
				break;	
			case 4:
				line(arr[i-3]+34,((level-1)*80)+offset,arr[i]+13,(level*80));
				break;
			case 5:
				line(arr[i-3]-13,((level-1)*80)+offset,arr[i]+13,(level*80));
				break;	
			case 6:
				line(arr[i-4]+34,((level-1)*80)+offset,arr[i]+13,(level*80));
				break;
			case 7:
				line(arr[i-4]-13,((level-1)*80)+offset,arr[i]+13,(level*80));
				break;
			case 8:
				line(arr[i-5]+34,((level-1)*80)+offset,arr[i]+13,(level*80));
				break;	
			case 9:
				line(arr[i-5]-13,((level-1)*80)+offset,arr[i]+13,(level*80));
				break;	
			case 10:
				line(arr[i-6]+34,((level-1)*80)+offset,arr[i]+13,(level*80));
				break;	
			case 11:
				line(arr[i-6]-13,((level-1)*80)+offset,arr[i]+13,(level*80));
				break;	
			case 12:
				line(arr[i-7]+34,((level-1)*80)+offset,arr[i]+13,(level*80));
				break;	
			case 13:
				line(arr[i-7]-13,((level-1)*80)+offset,arr[i]+13,(level*80));
				break;	
			case 14:
				line(arr[i-8]+34,((level-1)*80)+offset,arr[i]+13,(level*80));
				break;		
		}
        if(i==0 || i==2 || i==6 || i==14)
            level++;
    }
}

// -----------------------------------------------------------------------------------------------------------------

void gettree()				//GET ELEMENTS OF TREE FROM USER
{
	char choice;
	t.create();			//TO CREATE A NEW TREE
	while(1)
	{
		cout<<"\nWANT TO ENTER ELEMENT(Y/N): ";
		cin>>choice;
		if(choice == 'Y' || choice == 'y')
		{
			t.insert();
		}
		else if(choice == 'N' || choice == 'n')
			break;
		else
			cout<<"\n\t\t!!! INVALID CHOICE !!!";
	}
}

// -----------------------------------------------------------------------------------------------------------------
 
void printGivenLevel(tree_node* root, int level)  	//READS NODES AT A GIVEN LEVEL 
{  
    if (root == NULL )  
    {
    	tree_arr[element++] = "NULL";
    	for(int i=1;i<level;i++)
    		tree_arr[element++] = "NULL";
    	if(level == 3)
    		tree_arr[element++] = "NULL";
        return;  
	}
    if (level == 1)  {
        //cout << root->idata << " ";  
        
        stringstream ss;							//STRINGSTREAM CLASS FOR STRING OPERATIONS
        ss<<root->idata;						
        tree_arr[element++] = ss.str();				//TO COVNVERT INT TO STRING
      }
    else if (level > 1)  
    {  
        printGivenLevel(root->lchild, level-1);  
        printGivenLevel(root->rchild, level-1);  
    }  
}  

// -----------------------------------------------------------------------------------------------------------------

/* COMPUTE THE "HEIGHT" OF A TREE -- THE NUMBER OF  
    NODES ALONG THE LONGEST PATH FROM THE ROOT NODE  
    DOWN TO THE DARTHEST LEAF NODE.*/
int height(tree_node* node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
        
        int lheight = height(node->lchild);     // COMPUTE THE HEIGHT OF EACH SUBTREE 
        int rheight = height(node->rchild);  
  
        
        if (lheight > rheight)       // USE THE LARGER ONE 
            return(lheight + 1);  
        else return(rheight + 1);  
    }  
}  

// -----------------------------------------------------------------------------------------------------------------

void printLevelOrder(tree_node* root)    // FUNCTION TO PRINT THE LEVEL ORDER TRAVERSAL OF A TREE 
{  
    int h = height(root);  
    int i;  
    for (i = 1; i <= h; i++)  
        printGivenLevel(root, i);  
}  

// -----------------------------------------------------------------------------------------------------------------

void space(int no)        //FUNCTION TO PRINT REQURIED NUMBER OF SPACES
{
	for(int i=0;i<no;i++)
	{
		cout<<"     ";
	}
}

// -----------------------------------------------------------------------------------------------------------------

void tree_name()      //FUNCTION TO PRINT HEADER NAME (TREE)
{
	setcolor(BLACK);
	bar(20,30,620,130);
	setcolor(RED);
	setlinestyle(SOLID_LINE,0,10);
	//DRAWING T
	line(170,50,210,50);
	line(190,50,190,100);
	//DRAWING R
	line(240,45,240,100);
	line(240,50,270,50);
	line(270,45,270,75);
	line(240,75,275,75);
	line(240,75,270,100);
	//DRAWING E
	line(310,45,310,100);
	line(310,50,340,50);
	line(310,75,340,75);
	line(305,100,340,100);
	//DRAWING E
	line(370,45,370,100);
	line(370,50,400,50);
	line(370,75,400,75);
	line(365,100,400,100);
	
	setcolor(WHITE);
	//DRAWING T
	line(175,55,215,55);
	line(195,55,195,105);
	//DRAWING R
	line(245,50,245,105);
	line(245,55,275,55);
	line(275,50,275,80);
	line(245,80,280,80);
	line(245,80,275,105);
	//DRAWING E
	line(315,50,315,105);
	line(315,55,345,55);
	line(315,80,345,80);
	line(310,105,345,105);
	//DRAWING E
	line(375,50,375,105);
	line(375,55,405,55);
	line(375,80,405,80);
	line(370,105,405,105);
	
	
}

// -----------------------------------------------------------------------------------------------------------------

void welcome()			//FUNCTION FOR WELCOME PART OF THE PROGRAM
{

	system("clear");
	delay(500);
	
	char welcome[]={'W','E','L','C','O','M','E'};
	cout<<"\n\n\n\n\t\t\t";
	for(int i=0;i<7;i++)
	{
		cout<<"\n\t";
		space(i);
		cout<<welcome[i];
		delay(300);
	}
	cout<<"...";
	cout<<"\n";
	delay(1000);
	cout<<"\n";
}

// -----------------------------------------------------------------------------------------------------------------

void graphics()				//FUNCTION FOR THE GRAPHICS PART OF THE PROGRAM
{
	int gm=0,gd=DETECT;   
	initgraph(&gd,&gm,NULL);
    setcolor(BLUE);
   	bar(0,0,640,480);

    tree_name();
    
    tree_creation();
	
	setcolor(BLACK);
	bar(0,430,640,480);
	char msg[]="*** NOTE :- IF ANY FIELD IS EMPTY THEN CONSIDER IT AS A NULL FIELD ***";
	outtextxy(70,450,msg);
}

// -----------------------------------------------------------------------------------------------------------------

int main()
{

	welcome();
	
	system("clear");
	
	cout<<"\n\n\t\t\t===> CREATING A TREE <===\n";
	cout<<"    \t\t\t     ===============     \n\n";
	gettree();
	for(int i=0;i<offset;i++)
		tree_arr[i] = "NULL";
	printLevelOrder(t.root);
	
	cout<<"\n=================================================\n";
	
	cout<<"\n\nYOUR TREE IS READY PRESS ANY KEY TO CONTINUE....";
	cout<<"\n";
	getch();
	
	graphics();
	
   	getch();
    closegraph();
   	system("clear");
	cout<<"\n\n\n\t\t\t\tTHANK YOU...";
   
}

// -----------------------------------------------------------------------------------------------------------------
//                 *** END OF THE PROJECT ***
