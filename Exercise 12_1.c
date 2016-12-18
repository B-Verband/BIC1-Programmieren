void minimum(TNode *tree)
{
	if (tree->pleft != NULL)
	{
		minimum_(tree->pleft);
	}
	else
	{
		/* gibt Minimum aus */
		printf("\nMinimum: %d\n", tree->data);
	}
}
void maximum(TNode *tree)
{
	if (tree->pright != NULL)
	{
		maximum(tree->pright);
	}
	else
	{
		/* gibt Maximum aus */
		printf("Maximum: %d\n", tree->data);
	}
}
double average(TNode *tree)
{
	static double summe;
	static double nodes;

	if (tree != NULL)
	{
		summe = summe + tree->data;
		nodes++;
		average(tree->pright);
		average(tree->pleft);
	}
	/* gibt Mittrlwert zurück */
	return summe / nodes;
}
