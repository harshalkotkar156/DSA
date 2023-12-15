#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Data{
	int roll_no;
	string name;
	float sgpa;
}record;

void print(Data record[],int n){
	cout<<"Roll no |	Name	|	SGPA	|"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<" "<<record[i].roll_no<<"  	      "<<record[i].name<<"	   	  "<<record[i].sgpa<<endl;
	}
	
}
void bubbleSort(Data record[],int n)
{
    for(int i=0;i<n-1;i++){
        
        for(int j=1;j<(n-i);j++)
        {
            if(record[j-1].roll_no > record[j].roll_no) 
            {
                swap(record[j-1],record[j]);
            }
            
        }
    }
}
void insertionSort(Data record[],int n)
{
	for(int i=1;i<n;i++)
	{
		Data flag = record[i];
		string temp = record[i].name;
		int j=i-1;
		while(j>=0 and record[j].name > temp){
			record[j+1] = record[j];
			j--;
		}
		record[j+1] = flag;
		record[j+1].name = temp;		
	}
}
int hoares_partition(Data record[],int l,int h)
{
	int i=l-1;
	int j =h+1;
	int pivot =record[l].sgpa;
	while(1)
	{
		do
		{
			i++;
		} while(record[i].sgpa > pivot);
		do
		{
			j--;
		} while (record[j].sgpa < pivot);
		if(i>=j)
		{
			return j;
		}
		swap(record[i],record[j]);
	}
}
void quickSort(Data record[],int l,int h)
{
	if(l<h)
	{
		int pos = hoares_partition(record,l,h);
		quickSort(record,l,pos);
		quickSort(record,pos+1,h);
	}
}
void search(Data record[],int n ,int x)
{
	cout<<"Roll no |	Name	|	SGPA	|"<<endl;
	for(int i=0;i<n;i++)
	{
		if(record[i].roll_no == x){
			cout<<" "<<record[i].roll_no<<"  	      "<<record[i].name<<"	   	  "<<record[i].sgpa<<endl;
		}
	}
}
void name_search(Data record[],int n,string x)
{
	int l=0;
	int h=n-1;
	while(l<=h)
	{
		int mid = (l+h) / 2;
		if(record[mid].name == x){
			cout<<"Roll no |	Name	|	SGPA	|"<<endl;
			cout<<" "<<record[mid].roll_no<<"  	      "<<record[mid].name<<"	   	  "<<record[mid].sgpa<<endl;
			return;
		}
		if(record[mid].name < x){
			l=mid+1;
		}else{
			h=mid-1;
		}
	}
	cout<<"NOT FOUND! "<<endl;
	
}
int main()
{
	int n=3;
	Data record[n];
	cout<<"Start:\n";
	for(int i = 0;i<n;i++)
	{
		cout<<"Enter Roll No : ";cin>>record[i].roll_no;

		cout<<"Enter Name : ";cin>>record[i].name;
		transform(record[i].name.begin(),record[i].name.end(),record[i].name.begin(),::toupper);
		cout<<"Enter SGPA : ";cin>>record[i].sgpa;
	}
	//sorting the roll numbers
	int l=0;int h=n-1;
	int roll;
	int temp ;
	bool flag=true,flag_main = true;
	
	while(flag_main)//flag main is for main while loop
	{
		cout<<"		*********		"<<endl;
		cout<<"Enter 1 for according to ROLL NO !"<<endl;
		cout<<"Enter 2 for according to Student Name !"<<endl;
		cout<<"Enter 3 for according to SGPA !"<<endl;
		cout<<"Enter 4 for Searching Data by Roll no  !"<<endl;
		cout<<"Enter 5 for Searching Data by NAME  !"<<endl;
		cout<<"		*********		"<<endl;
		bool name_flag =true;
		int switch_var;cin>>switch_var;
		switch (switch_var)
		{
		case 1:
			cout<<"According to the roll numbers : "<<endl;
			bubbleSort(record,n);
			print(record,n);
			break;

		case 2:
			cout<<"This is according to Student names : ";
			insertionSort(record,n);
			cout<<endl;
			print(record,n);
			break;

		case 3:
			cout<<"This list is according to marks : "<<endl;
			
			quickSort(record,l,h);//this is for sorting the marks in decreasing order
			print(record,n);
			break;

		case 4:
			bubbleSort(record,n);
			while(flag)
			{
				cout<<"Enter the Roll No to access data : ";cin>>roll;
				search(record,n,roll);
				cout<<"Do you want to search for another roll No : "<<endl;
				cout<<"Enter 1 for Yes and 0 for NO: ";
				cin>>temp;
				if(!(temp)){
					flag=false;	
				}
			}
			
			// cout<<"Enter the Roll No to access data : ";cin>>roll;
			// bubbleSort(record,n);
			// search(record,n,roll);
			break;
		case 5:
			insertionSort(record,n);
			while(name_flag)
			{
				string name;
				cout<<"Enter Name : ";cin>>name;
				transform(name.begin(),name.end(),name.begin(),::toupper);
				name_search(record,n,name);
				cout<<"Enter 1 to Search  again else 0 : ";int temp;cin>>temp;
				if(!(temp)){
					name_flag=false;
				}
			}
		default:
			cout<<"DONE!"<<endl;
			break;
		}
		int temp_main;
		cout<<"Want to check again :\nIf YES Enter 1 else 0 : ";cin>>temp_main;
		if(!(temp_main)){
			flag_main=false;
		}
    }
	return 0;
}
