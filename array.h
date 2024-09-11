#pragma once
#include <stdlib.h>

struct array_data;
struct array;

struct array carray();
void push(struct array* arr,void* element);
void* get(struct array* arr, int index);
void pop(struct array* arr);
void clear(struct array* arr);
size_t size(struct array* arr);

typedef struct array_data
{
	int current_size;
	void** elements;
}array_data;

struct array
{
	struct array_data data;
};

size_t size(struct array* arr)
{
	return arr->data.current_size;
}

struct array carray()
{
	struct array temp;
	temp.data.current_size = 0;
	temp.data.elements = NULL;

	return temp;
}

void* get(struct array* arr, int index)
{
	if (arr->data.current_size < 0 || index >= arr->data.current_size)
	{
		printf("\nIndex out of Bounds\n");
		return NULL;
	}

	return arr->data.elements[index];
}

void push(struct array* arr, void* element)
{
	int old_size = arr->data.current_size;
	int new_size = old_size + 1;

	void** new_elements = malloc(sizeof(void*) * new_size);
	if (new_elements == NULL) return;
	for (unsigned i = 0; i < old_size; i++)
	{
		new_elements[i] = arr->data.elements[i];
	}

	new_elements[old_size] = element;

	free(arr->data.elements);

	arr->data.elements = new_elements;
	arr->data.current_size = new_size;
}

void pop(struct array* arr)
{
	if (arr->data.current_size == 0)
	{
		return;
	}
	int new_size = arr->data.current_size - 1;

	void** new_elements = malloc(sizeof(void*) * new_size);

	for (unsigned i = 0; i < new_size; i++)
	{
		new_elements[i] = arr->data.elements[i];
	}

	free(arr->data.elements);

	arr->data.elements = new_elements;
	arr->data.current_size = new_size;
}

void clear(struct array* arr)
{
	free(arr->data.elements);
	arr->data.elements = NULL;
	arr->data.current_size = 0;
}