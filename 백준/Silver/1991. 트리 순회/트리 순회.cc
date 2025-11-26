#include <iostream>
using namespace std;

struct Node
{
	char left;
	char right;
};

void PreOrder(Node tree[], char node)
{
	if (node == '.')
		return;

	cout << node;
	PreOrder(tree, tree[node - 'A'].left);
	PreOrder(tree, tree[node - 'A'].right);
}

void InOrder(Node tree[], char node)
{
	if (node == '.')
		return;

	InOrder(tree, tree[node - 'A'].left);
	cout << node;
	InOrder(tree, tree[node - 'A'].right);
}

void PostOrder(Node tree[], char node)
{
	if (node == '.')
		return;

	PostOrder(tree, tree[node - 'A'].left);
	PostOrder(tree, tree[node - 'A'].right);
	cout << node;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	Node* tree = new Node[26]; 

	for (int i = 0; i < 26; i++)
	{
		tree[i] = { '.', '.' };
	}

	while (N--)
	{
		char p, l, r;
		cin >> p >> l >> r;
		tree[p - 'A'] = { l, r };
	}

	PreOrder(tree, 'A');
	cout << "\n";
	InOrder(tree, 'A');
	cout << "\n";
	PostOrder(tree, 'A');
	cout << "\n";

	delete[] tree;
	return 0;
}