#include<stdio.h>
#include<stdlib.h>

#define print() printf("\n")
#define printn(c) printf("%c ", c)

struct node{
	char data;
	struct node *left;
	struct node *right;
};


struct node_{
	struct node *data;
	struct node_ *next;
};

typedef struct{
	struct node_ *top;
}STACK;

void push(STACK *s, struct node *v){
	struct node_ *curr = (struct node_ *)malloc(sizeof(struct node_));
	curr->data = v;
	curr->next = NULL;
	if(s->top == NULL){
		s->top = curr;
	}else{
		curr->next = s->top;
		s->top = curr;
	}
}

int pop(STACK *s, struct node **v){
	if(s->top == NULL){
		printf("Underflow");
		return -1;
	}else{
		*v = s->top->data;
		struct node_ *ptr =s->top;
		s->top = s->top->next;
		free(ptr);
		return 0;
	}
}

struct node * create_node(char data){
	struct node *curr=(struct node *)malloc(sizeof(struct node));
	curr->left = NULL;
	curr->right = NULL;
	curr->data = data;
	return curr;
}

void initialise(STACK *s){
	s->top = NULL;
}

int is_empty(STACK s){
	if(s.top == NULL)
		return 1;
	return 0;
}

void inorder(struct node *root){
	if(root == NULL)
		return;
	inorder(root->left);
	printf("%c ",root->data);
	inorder(root->right);
}

void postorder(struct node *root){
	if(root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%c ",root->data);
}

void preorder(struct node *root){
	if(root == NULL)
		return;
	printf("%c ",root->data);
	preorder(root->left);
	preorder(root->right);
}

void preorder_s(struct node *root){
	STACK s;
	initialise(&s);
	push(&s, root);
	while(!is_empty(s)){
		struct node *sn;
		pop(&s,&sn);
		printf("%c ", sn->data);
		if(sn->right!=NULL){
			push(&s,sn->right);	
		}
		if(sn->left!=NULL){
			push(&s,sn->left);	
		}
	}
}

void inorder_s(struct node *root){
	STACK s;
	initialise(&s);
	struct node *curr;
	struct node *v;
	curr = root;
	while(1){
		while(curr!=NULL){
			push(&s,curr);
			curr = curr->left;
		}
		pop(&s,&v);
		printn(v->data);
		curr = v->right;
		if(is_empty(s) && curr == NULL){
			break;
		}	
	}
}

void postorder_s(struct node *root){
	STACK s;
	initialise(&s);
	struct node *curr;
	struct node *a, *b;
	curr= root;
	push(&s, root);
	while(){
		while(curr!=NULL){
			if(curr->right!=NULL)
				push(&s, curr->right);
			push(&s, curr);
			curr = curr->left;
		}
		pop(&s,&a);
		if(a->right==NULL){
			printf("%d ", a->data);
		}else{
			int m = pop(&s, &b);
			if(m == -1){
				printf("%d ",a->data);
				break;
			}
			if(a->right == b){
				push(&s, a);
				curr = b;
			}else{
				printf("%d ", a->data);
				push(&s,b);
			}
		}
	}
}

int main(){
	struct node *root=NULL;
	
	root = create_node('a');
	root->left = create_node('b');
	root->right = create_node('c');
	root->left->left = create_node('d');
	root->left->right = create_node('e');
	root->right->right = create_node('f');
	root->right->left = create_node('g');
		
	preorder_s(root);
	printf("\n");
	inorder_s(root);
	printf("\n");
	//postorder(root);
}
