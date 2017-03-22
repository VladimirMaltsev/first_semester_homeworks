#include <stdio.h>

void input(){
	int arr[3];	
	int i = 0;
	printf ("Stack before input: \n\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n\n");
	do
	{
		scanf ("%d", arr+i++);
	}while (arr[i - 1]);
	
	printf ("\nStack after input: \n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n\n");
}

void other()
{
	puts ("OmNomNom --- <your programm is hacked>");
}

int main()
{
	printf ("Stack : \n%p\n%p\n%p\n\n");
	printf ("Address of input = %d\n", &input);
	printf ("Address of other = %d\n\n", &other);
	input();
	return 0;
}
