#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

struct array_data;
struct array;

struct array carray();
void push(struct array* arr,void* element);
void remove_at(struct array* arr, int index);
void* get(struct array* arr, int index);
void pop(struct array* arr);
void clear(struct array* arr);
void set(struct array* arr, int index, void* element);
bool is_empty(struct array* arr);
size_t size(struct array* arr);

struct array_data
{
	int current_size;
	void** elements;
};

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

void set(struct array* arr, int index, void* element)
{
	if (arr->data.current_size < 0 || index >= arr->data.current_size)
	{
		printf("Index out of Bounds\n");
		return NULL;
	}

	arr->data.elements[index] = element;
}

void remove_at(struct array* arr, int index)
{
	if (arr->data.current_size < 0 || index >= arr->data.current_size || arr->data.current_size == 0)
	{
		printf("Index out of Bounds\n");
		return NULL;
	}

	int new_size = arr->data.current_size - 1;

	void** new_elements = malloc(sizeof(void*) * new_size);
	
	int j = 0;
	for (unsigned i = 0; i < arr->data.current_size; i++)
	{
		if (i != index)
		{
			new_elements[j++] = arr->data.elements[i];
		}
	}

	free(arr->data.elements);
	arr->data.elements = new_elements;
	arr->data.current_size = new_size;
}

void* get(struct array* arr, int index)
{
	if (arr->data.current_size < 0 || index >= arr->data.current_size)
	{
		printf("Index out of Bounds\n");
		return NULL;
	}

	return arr->data.elements[index];
}

bool is_empty(struct array* arr)
{
	return arr->data.current_size == 0;
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