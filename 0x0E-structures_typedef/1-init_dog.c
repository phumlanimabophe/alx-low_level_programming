#include <stdio.h>
#include "dog.h"

/**
 * @d: dog's details
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
