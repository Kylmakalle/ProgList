#include <iostream> 
using namespace std;

struct Node {
	int info;
	Node*link;
};

int main()
{
	Node*Head = NULL;
	Node*Back;
	Node*p;
	Node*last;
	int x;

	cin >> x;

	if (x != 0) {
		Head = new Node;
		Head->info = x;
		Back = Head;
		if (x < 0) {
			p = new Node;
			Back->link = p;
			p->info = 0;    //if first element is negative, inserts 0 after it

			Back = p;
		}
		while (1) {
			cin >> x;
			if (x == 0)
				break;

			p = new Node;
			Back->link = p;
			p->info = x;
			Back = p;

			if (x < 0) {
				p = new Node;
				Back->link = p;
				p->info = 0;    //inserting 0 after negative elements
				Back = p;
			}
		}

		Back->link = 0;
	}


	p = Head;
	last = Head;  //last nonpositive element 

	while (p != NULL) {

		if (p->info > 0) {

			if (p == Head) {

				p = p->link;
				delete Head;
				Head = p;
				last = Head;
			}

			else {
				p = p->link;
				delete last->link;
				last->link = p;
			}
		}
		else {
			last = p;
			p = p->link;
			last->link = p;
		}
	}

	p = Head;

	while (p != NULL) {
		cout << p->info << " "; //output
		p = p->link;
	}


	while (Head) {
		p = Head->link;
		delete Head; //deleting memory
		Head = p;
	}
	return 0;
}
