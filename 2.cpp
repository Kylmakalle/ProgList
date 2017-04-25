#include <iostream>
using namespace std;

struct x
{
	int p;
	x* next;
	x* pred;
};

void Sort(x *y, x *t)
{
	y = t;

	while (y->next != NULL)
	{
		if ((y->p) > (y->next->p))
		{
			swap(y->p, y->next->p);
			Sort(y, t);
		}
		else
			y = y->next;
	}
};

int main()
{
	int n(0), k;
	x *t, *h, *g;
	t = new x;
	g = t;

	while (1)
	{
		cin >> k;
		if ((k == 0) && (n == 0))
			return 0;
		if (k == 0)
		{
			g->next = NULL;
			break;
		}
		else
		{
			h = g;
			if (n == 0)
				h->pred = 0;
			g->p = k;
			g->next = new x;
			h->pred = g;
			g = g->next;
			n++;
		}
	}

	g = t;

	Sort(g, t);

	g = t->next;

	while (g != NULL)
	{
		cout << g->p << " ";
		g = g->next;
	}

	while (t) {
		g = t->next;
		delete t; //deleting memory
		t = g;
	}
}