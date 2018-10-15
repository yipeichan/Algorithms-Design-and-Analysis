#include <iostream>
#include <iomanip>
using namespace std;

void selectionSort(int * const, const int); // function to sort an array
void swap(int * const , int * const);

int main()
{
	const int arraySize=10;
	int test[arraySize]={5,35,70,83,24,577,35,43,23,76};
	cout<<"Data items in original order\n";

	for (int i=0; i<arraySize;i++)
		cout<<setw(4)<<test[i];

	selectionSort(test,arraySize); // sort the array
	cout<<"\n\n Data items in ascending order\n";

	for (int j=0; j<arraySize; j++)
		cout<<setw(4)<<test[j];
	cout<<"\n"<<endl;


}

void selectionSort(int * const array, const int size)
{
	int smallest ; //index of the smallest element

	// loop over size-1 element
	for (int i=0 ; i<size-1; i++)
	{
		smallest=i; // first index of remaining array

		//loop to find the index of the smallest element
		for (int index=i+1;index<size;index++)
			if (array[index]<array[smallest])
				smallest=index;

		cout<<"\n\nthe "<<i+1<<" th swap:"<<endl;
		swap(&array[i],&array[smallest]);

	}
}

void swap(int * const element1Ptr, int * const element2Ptr)
{
	int hold= *element1Ptr;
	*element1Ptr = *element2Ptr;
	*element2Ptr = hold;

	// the debug process
	cout<<"the smallest number at this round is= "<<*element1Ptr<<" swaped to place= "<<element2Ptr<<endl
	    <<", the number being swaped is= "<<*element2Ptr<<" swaped to place= "<<element2Ptr<<"\n"<<endl;
}

