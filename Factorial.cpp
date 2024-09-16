#include <stdio.h>
#include <stdlib.h>

struct ArrayList
{

	int* items;
	long long int capacity = 1000000;
	long long int length = 0;

	void Push(int value)
	{
		if(capacity <= length)
		{
			//creating a new cap
			int newCap = capacity * 2;
			
			//creating a new array
			int* newArr = (int*)malloc(newCap * sizeof(int));
			
			//old array
			int* oldArr = items;
			
			//Transfering all the value in the old array
			for(int i = 0; i < length; i++)
			{
				newArr[i] = oldArr[i];
			}
			
			//pointing to the new array
			items = newArr;
			capacity = newCap;
			
			//freeing the oldArr
			free(oldArr);
			
		}
		
		//Adding the items
		items[length] = value;
		length++;
		
	}
	
	void AllocateMemory()
	{
		//Allocating the memory for the first time
		items = (int*)malloc(capacity * sizeof(int));
	}
	
	void PrintAll()
	{
		for(int i = 0; i < length; i++)
		{	
			//print items
			printf("%d\n", items[i]);
		}
		
		//show the capacity and the length
		printf("Capacity: %d, Length: %d", capacity, length);
	}
	
	void PrintAllReversed()
	{
		for(int i = length - 1; i >= 0; i--)
		{
			//print items
			printf("%d", items[i]);
		}
	}

};

//--------------- FACTORIAL PART ----------------------


//Temporary Array
ArrayList tempArray;

void Multiply(int multiplier)
{
	//Declaring the variables
	int carry = 0;
	int value = 0;
	
	// Multiply it one by one using array
	for(int i = 0; i < tempArray.length; i++)
	{
		value = tempArray.items[i] * multiplier + carry;
		tempArray.items[i] = value % 10;
		carry = value / 10;
	}
	
	//if the carry is not 0 insert it to the new array
	while(carry != 0)
	{
		tempArray.Push(carry % 10);
		carry /= 10;
	}
}

void Factorial(int value)
{	
	//Pushing the first value of a Factorial
	tempArray.Push(1);
	
	//Multiply it from lowest to the value
	for(int i = 2; i <= value; i++)
	{
		Multiply(i);
		
		//See progress
		printf("%d\n", i);
	}
	
	system("cls");
}

int main(void)
{	
	//Allocating the memory
	tempArray.AllocateMemory();
	
	//N times
	int n = 0;
	
	//User Input
	printf("Enter Factorial: ");
	scanf("%d", &n); getchar();
	Factorial(n);
	system("cls");
	
	//Output
	printf("%d! = ", n);
	tempArray.PrintAllReversed();
}