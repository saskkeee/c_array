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



```
push(array,value) - Appends the specified element to the end of this list.
pop(array) - Removes the last element from this list.
clear(array) - Clears the memory(Deletes Array)
size(array) - Returns size of array
get(array,index) - Returns element by its index
```
