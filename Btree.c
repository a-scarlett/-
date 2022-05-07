#include <stdio.h>
#include <stdlib.h>
struct BNode
{
	int data; // элемент данных
	struct BNode* left, * right; // указатели на сыновей
};
struct BNode* node(int d, struct BNode* l, struct BNode* r)
{
	struct BNode* p = (struct BNode*)malloc(sizeof(struct BNode));
	p->data = d;
	p->left = l;
	p->right = r;
	return p;
}
void print(struct BNode* r, int d) // d - смещение
{
	if (r == NULL)
		return;
	print(r->right, d + 3);
	for (int i = 0; i < d; i++)
		printf(" ");
	printf("%d\n", r->data);
	print(r->left, d + 3);
}

struct BNode* grand1(struct BNode* tree) {
	struct BNode* r=0;
	if (tree == 0) {
		return 0;
	}
	if (tree->right == 0 && tree->left == 0) {
		return 0;
	}
	if (tree->left != 0) {
		if (tree->left->left != 0) { r = tree->left->left; }
		if (tree->left->right != 0) { r = tree->left->right; }
	}
	if (tree->right != 0) {
		if (tree->right->left != 0) { r = tree->right->left; }
		if (tree->right->right != 0) { r = tree->right->right; }
	}
	return r;

}
int num_grand2(struct BNode* tree) {
	int r = 0;
	if (tree == 0) {
		return 0;
	}
	if (tree->left != 0) {
		if (tree->left->left != 0) { r++; }
		if (tree->left->right != 0) { r++; }
	}
	if (tree->right != 0) {
		if (tree->right->left != 0) { r++; }
		if (tree->right->right != 0) { r++; }
	}
	return r;

}
struct BNode* rev3(struct BNode* tree) {
	struct BNode* a = tree;
	if (tree == 0) {
		return 0;
	}
	struct BNode* e = tree->right;
	if ((tree->left) != 0) {
		struct BNode* b = tree->left;
		struct BNode* c = tree->left->left;
		struct BNode* d = tree->left->right;
		a->left = c;
		a->right = d;
		b->left = a;
		b->right = e;
		return b;
	}
	return 0;
}
struct BNode* rev4(struct BNode* tree) {
	struct BNode* a = tree;
	if (tree == 0) {
		return 0;
	}
	struct BNode* b = tree->right;
	if ((tree->right) != 0) {
		struct BNode* y = tree->right->left;
		a->right = y;
		b->left = a;
		return b;
	}
	return 0;
}
struct BNode* left5(struct BNode* tree)
 {
	struct BNode* t;
	if (tree == 0) {
		return 0;
	}
	t = tree;
	while ((t->left) != 0) {
		t = t->left;
	}
	return t;
}
struct BNode* left6(struct BNode* tree) {
	struct BNode* t;
	if (tree == 0) {
		return 0;
	}
	t = tree;
	while ((t->right) != 0 || (t->left) != 0) {
		if (t->left != 0) {
			t = t->left;
		}
		else if (t->right != 0) {
			t = t->right;
		}
	}
	return t;
}
struct BNode* left7(struct BNode* tree) {
	struct BNode* t=0;
	struct BNode* del=0;
	if (tree == 0) {
		return 0;
	}
	t = tree;

	while ((t->right) != 0 || (t->left) != 0) {
		if ((t->left != 0) && t->right != 0) {
			del = t;
		}
		if (t->left != 0) {
			t = t->left;
		}
		else if (t->right != 0) {
			t = t->right;
		}
	}
	t = del->right;
	while ((t->right) != 0 || (t->left) != 0) {
		if (t->left != 0) {
			t = t->left;
		}
		else if (t->right != 0) {
			t = t->right;
		}
	}
	return t;

}
struct BNode* add8(struct BNode* tree, int d) {
	struct BNode* t;
	if (tree == 0) {
		return 0;
	}
	t = tree;
	while ((t->left) != 0) {
		t = t->left;
	}
	struct BNode* p = (struct BNode*)malloc(sizeof(struct BNode));
	t->left = p;
	p->data = d;
	p->left = 0;
	p->right = 0;
	return tree;
}
struct BNode* del9(struct BNode* tree) {
	struct BNode* p=0;
	struct BNode* f=0;
	if (tree == 0) {
		return 0;
	}
	p = tree;
	while ((p->left) != 0) {
		f = p;
		p = p->left;
	}
	if (p == tree) {
		struct BNode* t = p->right;
		free(p);
		return t;
	}
	f->left = p->right;
	free(p);
	return tree;
}
struct BNode* del10(struct BNode* tree) {
	struct BNode* t, * f;
	f = 0;
	if (tree == 0) {
		return 0;
	}
	t = tree;
	int flag = 0;
	while ((t->right) != 0 || (t->left) != 0) {
		flag = 0;
		if (t->left != 0) {
			f = t;
			t = t->left;
			flag = 0;
		}
		else if (t->right != 0) {
			f = t;
			t = t->right;
			flag = 1;
		}
	}
	if (f == 0) {
		free(t);
		return 0;
	}
	if (flag == 0) f->left= 0;
	else f->right = 0;
	free(t);
	return tree;
}
int main()
{
	struct BNode* p6 = node(6, NULL, NULL),
		* p5 = node(5, NULL, NULL),
		* p4 = node(4, NULL, NULL),
		* p3 = node(3, p6, NULL),
		* p2 = node(2, p4, p5),
		* p1 = node(1, p2, p3);
	struct BNode* tree = p1;
	print(tree, 0);
	free(p1); free(p2); free(p3);
	free(p4); free(p5); free(p6);
	return EXIT_SUCCESS;
}
