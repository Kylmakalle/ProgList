#include <iostream>
using namespace std;
struct Node
{
	int info;
	Node *left;
	Node *right;
};
struct spisok
{
	int z;
	spisok *link;
};
int n(1);
spisok * d, *y;
void search(Node *&p, int x)
{
	if (p)
	{
		if (p->info > x)
		{
			search(p->left, x);
		}
		else
			if (p->info < x)
				search(p->right, x);
			else
				cout << "Haha";
	}
	else
	{
		p = new Node;
		p->info = x;
		p->left = p->right = 0;
	}
}
void show(Node *h)
{
	if (h)
	{
		show(h->left);
		cout << h->info << " ";
		show(h->right);
	}
}
void showlist(Node *p, spisok *&y, spisok *&d)
{
	if (p)
	{

		showlist(p->left, y, d);
		if ((p->left == 0) && (p->right == 0))
		{
			if (n == 1)
			{
				y = new spisok;
				y->z = p->info;
				d = y;
				n++;
			}
			else
			{
				d->link = new spisok;
				d = d->link;
				d->z = p->info;
				d->link = 0;
			}
			showlist(p->right, y, d);
		}
	}
}
int main()
{
	int k;

	Node* Root, *g;
	Root = 0;
	while (1)
	{
		cin >> k;
		if (k == 0)
			break;
		search(Root, k);
	}
	show(Root);
	cout << endl;

	showlist(Root, y, d);
	d = y;
	while (d->link != 0)
	{
		cout << d->z;
		d = d->link;
	}

}