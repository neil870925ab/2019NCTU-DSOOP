#include <bits/stdc++.h>
#include <fstream> 
#include <sstream>
using namespace std;

int layers;
void distribution(bool **arr, string c);

int main(){
	
	int constraints;
	ifstream iF;
	ofstream oF;
	iF.open("sample data.txt");
	oF.open("TP_Sort_Result.txt");
	
	while(iF>>layers){
		
		int *arr=new int [layers];
		for(int i=0;i<layers;i++){
			iF>>*(arr+i);
		}
		
		int tmp=*(arr+layers-1); 

		bool **adjacent=new bool *[tmp+1];	//create a tmp+1*tmp+1 adjacent matrix
		for(int i=0;i<=tmp;i++){
			adjacent[i]=new bool [tmp+1];
		}
		for(int i=0;i<=tmp;i++){			//initialization
			for(int j=0;j<=tmp;j++){
				adjacent[i][j]=0;
			}
		}		
		 
		int *ref = new int [tmp+1];				//create an array to record how many nodes are directing to i
		for(int i=0;i<=tmp;i++){				//initialization
			*(ref+i)=0;
		}
		for(int i=0;i<=tmp;i++){		
			bool exist=false;
			for(int j=0;j<layers;j++){
				if(i==*(arr+j)){
					exist=true;
					break;
				}
			}
			if(!exist){
				ref[i]=-2;						//ref[i]=-2 represents that i is not exist in all of the layers 
			}
		}
								
		
		iF>>constraints;
		string ignore_me;				//to prevent the compiler from reading a "\n" after constraints when reading the condition,
		getline(iF,ignore_me);			//so I have to pre-read it
		
		while(constraints--){
			string condition;
			getline(iF,condition);
			distribution(adjacent,condition);	
		}
		
		for(int i=0;i<=tmp;i++){		//give the values to the ref array according to the adjacent matrix
			for(int j=0;j<=tmp;j++){
				if(adjacent[i][j]){
					ref[j]++;
				}
			}
		}
		
		for(int i=0;i<layers;i++){
			
			int find=0;
			while(find<=tmp&&ref[find]!=0){
				++find;
			}
			
			ref[find]=-1;				// ref[find]=-1 represent that the node "find" has been found and thus deleted
			
			for(int j=0;j<=tmp;j++){
				if(adjacent[find][j]){
					ref[j]--;
				}
			}
			*(arr+i)=find;
		}
	
//		for(int i=0;i<=tmp;i++){			
//			for(int j=0;j<=tmp;j++){
//				cout<<adjacent[i][j]<<" ";
//			}
//			cout<<endl;
//		}	
//		
//		cout<<endl;
//		
//		for(int i=0;i<=tmp;i++){
//			cout<<"ref["<<i<<"]= "<<ref[i]<<endl;
//		}	
		
		
		
		for(int i=0;i<layers;i++){
			oF<<*(arr+i)<<" ";
		}
		oF<<"\n";
		
		
		
		delete [] arr;
		delete [] ref;
		
		for(int i=0;i<=tmp;i++){
		delete [] adjacent[i];
		}
		delete [] adjacent;
		
	}
	
	iF.close();
	oF.close();
	cout<<"Topological sort succeeds!"<<endl;
	return 0;
}
	
	
void distribution(bool **arr, string c){
	
	stringstream str2int_left;
	stringstream str2int_right;
	int pos=c.find(">");
	int ptr=0;

	string left_string=c.substr(ptr,pos-ptr);	//divide the condition(string) into two parts(string) by the gap ">"
	ptr=pos+1;
	string right_string=c.substr(ptr,c.length()-pos);
	
	int terminal,start;							//convert str to int
	str2int_left<<left_string;
	str2int_left>>terminal;
	str2int_right<<right_string;
	str2int_right>>start;
	
	arr[start][terminal]=true;

}

