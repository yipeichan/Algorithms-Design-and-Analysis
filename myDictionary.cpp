/*
*	b01303133_hw10.cpp
*
*	Created on:2016.12.26
*	Author: Yi-Pei Chan (b01303133)
*	Application: myDictionary
*/


/* This dictionary allows user to find, insert, edit, and delete words, and display the whole dictionary.
It is designed with tree structure.
*/


#include "treeNode.h"

int main()
{

	string key , key2;
	string arrayW[] = {"curiosity","curious","abrupt","accuracy","acme","ADC","adit","0"};
	string arrayM[] = {"1. a desire to know about something; 2. something that is- unusual.","1. interested; 2. unusual or difficult to understand.","sudden and unexpected","exactness or precision","the highest point or period (of achievement, success etc.)","analogue-digital converter","a horizontal entrance or passage in a mine","0"};
	string arrayD[] = {"noun","adjective","adjective","noun","noun","abberivation","noun","0"};
	treeNode *tmp;
	treeNode *root = new treeNode(arrayW[0],arrayM[0],arrayD[0]);
	for(int i=1 ; arrayW[i]!= "0" ; i++)
	{
		insert(root,arrayW[i],arrayM[i],arrayD[i]);
	}
	
	cout<<"\n\nWelcome to myDictionary, "<<endl;
	cout<<"This dictionary is designed by Yi-Pei Chan (B01303133) based on tree structure"<<endl;
	cout<<"The initial dictionary has the following content: "<<endl;
	cout<<endl;
	cout<<endl;
	printDictionary(root);
	cout<<endl;



	do
	{
		cout<<"\n"<<endl;
		cout << "press i to insert a word " << endl; 
	    cout << "      e to edit a word" << endl; 
		cout << "      d to delete a word" << endl;
		cout << "      s to show the entire dictionary " << endl; 
		cout << "      f to find word a word" << endl;
		cout << "      quit to quit the program" << endl;
		//cin >> key;
		getline(cin,key);
		if(key == "e")
		{
			string m,d;
			cout << "\nenter the word to be replaced: ";
			getline( cin,key);
			cout << "enter the new word: ";
			getline( cin,key2);
			cout << "enter the meaning of the new word: ";
			getline( cin,m);
			cout << "enter description (noun, verb, adj, adv, abberivation): ";
			getline( cin,d);
			Edit(root, key , key2,m, d);
		}
		else if(key == "i")
		{
			string m,d;
			cout << "\nPlease insert a new word into the dictionary "<<endl;
			cout << "enter new Word: ";
			getline( cin,key2);
			cout << "enter the meaning of the new word: ";
			getline( cin,m);
			cout << "enter description (noun, verb, adj, adv, abberivation): ";
			getline( cin,d);
			insert(root,key2,m, d);
		}
		else if(key == "d")
		{
			cout << "\nenter Word To delete :";
			getline(cin,key2);
			if((root = Delete(root,key2)) != NULL)
				cout << "successfully deleted : " << key2 << endl; 
		}
		else if(key == "s")
		{
			cout<<endl;
			printDictionary(root);
		}
		else if(key == "f")
		{
			cout<<"\nenter the word to find, and the word would be at the top of the result: "<<endl;
			getline(cin, key2);
			cout<<"\n"<<endl;
			Find(root, key2 );
			if(!Find(root, key2 ))
				cout << key2 << " not founded" << endl ;
		}


		ofstream outFile("knownWords.txt ", ios::out);
		if(!outFile)
		{
			cerr<<"File cannot be opened"<<endl;
		}

		for(int i=0; arrayW[i]!= "0" ; ++i )
		{
			outFile<<arrayW[i]<<endl;
			outFile<<arrayM[i]<<endl;
			outFile<<arrayD[i]<<endl;
			outFile<<endl;
		}

	}while(key != "quit");
	DeleteDictionary(root);
	return 0;
}

