//#include<bits/stdc++.h>
//Either use bits/stdc++ or include add headers manually
/*
Input Format for csv file: The first row of csv file must contain the number of data and number of attributes.
For example here in IrisDataSet1.csv first row contains: 150,4 where 150 is number of data and 4 is number of attributes
*/

#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<inttypes.h>
#include<vector>
#include<cmath>
#include<string>
#define dd double
#define random (double)rand()/(double)RAND_MAX
#define Add push_back
using namespace std;
class KMean{
	vector<vector<dd> >Centroid;
	vector<vector<dd> >Data;
	vector<vector<int> >Cluster;
	vector<dd>Lower;
	vector<dd>Upper;
	dd Similarity,Dissimilarity;
	int TotalData,Attributes,TotalCluster;
public:
	void displayCluster();
	void displayCentroid();
	void displayData();
	void displayLowerUpper();
	void readData(string location,int TotalCluster);
	void createCentroid();
	void updateCentroid();
	void createCluster();
	void train(int iterations,dd error_margin);
	dd manhattanDistance(vector<dd>v1,vector<dd>v2); //between manhattan distance and euclidean distance, any distance formula can be used, or new distance formula can be added
	dd euclideanDistance(vector<dd>v1,vector<dd>v2);
	void predictCluster(vector<dd>inputData);
};
void KMean::displayCluster(){
	cout<<"\n==========Cluster==========\n";
	for(int i=0;i<Cluster.size();i++){
		cout<<"\nCluster "<<(i+1)<<" ["<<Cluster[i].size()<<"]:\t";
		for(int j=0;j<Cluster[i].size();j++){
			cout<<setw(5)<<Cluster[i][j];
		}
	}
}

void KMean::displayCentroid(){
	cout<<"\n==========Centroid==========\n";
	for(int i=0;i<Centroid.size();i++){
		cout<<"\nCentroid "<<(i+1)<<": \t";
		for(int j=0;j<Centroid[i].size();j++){
			cout<<setw(8)<<setprecision(4)<<Centroid[i][j];
		}
	}
}

void KMean::displayData(){
	cout<<"\n==========Data==========\n";
	for(int i=0;i<Data.size();i++){
		cout<<"\nIndex "<<(i+1)<<":\t";
		for(int j=0;j<Data[i].size();j++){
			cout<<setw(8)<<setprecision(4)<<Data[i][j];
		}
	}
}

void KMean::displayLowerUpper(){
	cout<<"\n==========Lower==========\n";
	for(int i=0;i<Lower.size();i++){
		cout<<setw(8)<<setprecision(4)<<Lower[i];
	}
	cout<<"\n==========Upper==========\n";
	for(int i=0;i<Upper.size();i++){
		cout<<setw(8)<<setprecision(4)<<Upper[i];
	}
}

void KMean::readData(string location,int TotalCluster){
	this->TotalCluster=TotalCluster;
	ifstream ptr(location);
	string temp,s;
	getline(ptr,s);
	int index=0;
	temp="";
	while(s[index]!=','){
		temp+=s[index++];
	}
	index++;
	TotalData=atoi(temp.c_str());
	temp="";
	while(index<s.size()){
		temp+=s[index++];
	}
	Attributes=atoi(temp.c_str());
	Data.resize(TotalData,vector<dd>(Attributes,0));
	for(int i=0;i<TotalData;i++){
		getline(ptr,s);
		index=0;
		for(int j=0;j<Attributes;j++){
			temp="";
			while(s[index]!=','){
				temp+=s[index++];
			}
			index++;
			Data[i][j]=atof(temp.c_str());
		}
	}
	for(int j=0;j<Attributes;j++){
		dd min=Data[0][j];
		dd max=min;
		for(int i=0;i<TotalData;i++){
			if(Data[i][j]>max){
				max=Data[i][j];
			}
			if(Data[i][j]<min){
				min=Data[i][j];
			}
		}
		Lower.Add(min);
		Upper.Add(max);
	}
}

void KMean::createCentroid(){
	Centroid.resize(TotalCluster,vector<dd>(Attributes,0));
	for(int i=0;i<Centroid.size();i++){
		for(int j=0;j<Centroid[i].size();j++){
			Centroid[i][j]=Lower[j]+(Upper[j]-Lower[j])*random;
		}
	}
}

void KMean::updateCentroid(){
	for(int i=0;i<Centroid.size();i++){
		for(int j=0;j<Centroid[i].size();j++){
			dd sum=0;
			for(int k=0;k<Cluster[i].size();k++){
				sum+=Data[Cluster[i][k]][j];
			}
			Centroid[i][j]=sum/Cluster[i].size();
		}
	}
}

void KMean::createCluster(){
	Similarity=0;
	Dissimilarity=0;
	Cluster.resize(TotalCluster);
	for(int i=0;i<Cluster.size();i++){
		Cluster[i].resize(0);
	}
	for(int i=0;i<Data.size();i++){
		dd min_distance=manhattanDistance(Data[i],Centroid[0]);
		dd max_distance=min_distance;
		int index=0;
		for(int j=0;j<Centroid.size();j++){
			dd distance=manhattanDistance(Data[i],Centroid[j]);
			if(distance<min_distance){
				min_distance=distance;
				index=j;
			}
			if(distance>max_distance){
				max_distance=distance;
			}
		}
		Similarity+=min_distance;
		Dissimilarity+=max_distance;
		Cluster[index].Add(i);
	}
}

void KMean::train(int iterations,dd error_margin){
	dd temp_similarity;
	createCentroid();
	createCluster();
	displayCentroid();
	displayCluster();
	temp_similarity=Similarity;
	cout<<"\nIteration: "<<0;
	cout<<"\nSimilarity: "<<Similarity<<"\tDissimilarity: "<<Dissimilarity;
	for(int i=0;i<iterations;i++){
		updateCentroid();
		createCluster();
		cout<<"\nIteration: "<<(i+1);
		cout<<"\nSimilarity: "<<Similarity<<"\tDissimilarity: "<<Dissimilarity;
		if((temp_similarity-Similarity)<error_margin){
			break;
		}
		temp_similarity=Similarity;
	}
	displayCentroid();
	displayCluster();
	
}

dd KMean::manhattanDistance(vector<dd>v1,vector<dd>v2){
	dd result=0;
	for(int i=0;i<v1.size();i++){
		result+=abs(v1[i]-v2[i]);
	}
	return result;
}

dd KMean::euclideanDistance(vector<dd>v1,vector<dd>v2){
	dd result=0;
	for(int i=0;i<v1.size();i++){
		result+=(v1[i]-v2[i])*(v1[i]-v2[i]);
	}
	return sqrt(result);
}
void KMean::predictCluster(vector<dd>inputData){
	dd min_distance=manhattanDistance(inputData,Centroid[0]);
	int index=0;
	for(int j=0;j<Centroid.size();j++){
		dd distance=manhattanDistance(inputData,Centroid[j]);
		if(distance<min_distance){
			index=j;
		}
	}
	cout<<"\n\nData belongs to cluster : "<<(index+1);
}

int main(){
	
	string dataLocation;
	
	cout<<"Enter the locaiton of dataset :";
	getline(cin,dataLocation);
	
	//dataLocation="E:\\AI Practical\\IrisDataSet1.csv";
	
	int cluster;
	cout<<"Enter total number of cluster: ";
	cin>>cluster;
	
	KMean k;
	k.readData(dataLocation,cluster);
	
	int iterations;
	cout<<"Enter number of iterations: ";
	cin>>iterations;
	
	dd error_margin;
	cout<<"Enter error margin: ";
	cin>>error_margin;
	
	k.train(iterations,error_margin);
	
	vector<dd>v(4);
	v={6.3,2.8,5.1,1.5};
	k.predictCluster(v);
	
	return 0;
}
