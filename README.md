Array written in C  

## Usage

```c
int main()
{
	struct array test = carray();
	push(&test, 5);
	printf("before: %i\n", (int) get(&test,0));
	set(&test, 0, 10);
	printf("after: %i\n", (int) get(&test, 0));
	pop(&test);
	printf("after pop: %i\n", (int)get(&test, 0)); //Index out of Bound 0
	clear(&test);
}
```

## All Methods
```
push(array,element)
pop(array)
set(array,index,element)
clear(array)
get(array,index)
remove_at(array,index)
```
