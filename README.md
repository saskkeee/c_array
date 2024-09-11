Array written in C  

## Usage

```c
int main()
{
	struct array test = carray();
	push(&test, 5);
	push(&test, 10);
	for (unsigned i = 0; i < size(&test); i++)
	{
		printf("element %i | value %i \n", i, get(&test, i));
	}
	pop(&test);
	for (unsigned i = 0; i < size(&test); i++)
	{
		printf("element %i | value %i \n", i, get(&test, i));
	}
	clear(&test);
}
```
