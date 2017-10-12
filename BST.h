#pragma once
#define FALSE	0
#define TRUE	1

typedef int ElemType;
typedef int Status;
typedef struct BinTNode
{
	ElemType data;
	struct BinTNode *lchild, *rchild;
}BinTreeNode, *BinTree;

Status SearchBST(BinTree T, ElemType key, BinTree f, BinTree *p);
Status InsertBST(BinTree *T, ElemType key);
Status DeleteBST(BinTree *T, ElemType key);
Status Delete(BinTree *p);




