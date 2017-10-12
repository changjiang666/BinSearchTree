#include "BST.h"
#include <stdio.h>

Status SearchBST(BinTree T, ElemType key, BinTree f, BinTree *p)
{
	if (!T)
	{
		*p = f;
		return FALSE;
	}
	else
	{
		if (key == T->data)
		{
			*p = T;
			return TRUE;
		}
		else if (key > T->data)
			return SearchBST(T->rchild, key, T, p);
		else
			return SearchBST(T->lchild, key, T, p);
	}
}

Status InsertBST(BinTree *T, ElemType key)
{
	BinTree p, s;
	if (!SearchBST(*T, key, NULL, &p))
	{
		s = (BinTree)malloc(sizeof(BinTreeNode));
		s->data = key;
		s->lchild = s->rchild = NULL;

		if (!p)
		{
			*T = s;
		}
		else
		{
			if (key < p->data)
				p->lchild = s;
			else
				p->rchild = s;
		}
		return TRUE;
	}
	return FALSE;
}


Status DeleteBST(BinTree *T, ElemType key)
{
	if (!*T)
		return FALSE;
	else
	{
		if (key == (*T)->data)
			return Delete(T);
		else if (key > (*T)->data)
			return DeleteBST(&((*T)->rchild), key);
		else
			return DeleteBST(&((*T)->lchild), key);
	}
}

Status Delete(BinTree *p)
{
	BinTree q, s;

	if ((*p)->lchild == NULL)
	{
		q = *p;
		*p = (*p)->rchild;
		free(q);
	}
	else if ((*p)->rchild = NULL)
	{
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	else
	{
		q = *p;
		s = (*p)->lchild;
		while (s->rchild)
		{
			q = s;
			s = s->rchild;
		}

		(*p)->data = s->data;

		if (q != *p)
			q->rchild = s->lchild;
		else
			q->lchild = s->lchild;
		free(s);
	}
	return TRUE;
}