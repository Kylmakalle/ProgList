#include <iostream>
using namespace std;
struct x
{
	int p;
	x* next;
	x* pred;
};
int z;
void delspisok(x *y)
{
	if (y->next == 0)
		return;
	delspisok(y->next);
	delete y;
}
void f(x *y)
{
	if (y->next == 0)
		return;
	if (y->p > 0)
		z++;
	f(y->next);
};
int main()
{
	int n(0), i, j, k;
	x *t, *h, *g, *l;
	t = new x;
	g = t;
	while (1)
	{
		cin >> k;
		if ((k == 0) && (n == 0))
			return 0;
		if (k == 0)
		{
			g->next = 0;
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

	delspisok(t);

}
