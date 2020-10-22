#include<bits/stdc++.h>
using namespace std;
int main()
{
	char linestr[80];
	char sroll[6],sname[30],sbatch[4];
	int i,j,k,N=0;
	FILE *fp;
	fp=fopen("inputdata.txt","r");
	if(fp==NULL)
	{
		cout<<"could not open file"<<endl;
		return -1;
	}
	fgets(linestr,79,fp);
	while(!feof(fp))
	{
		i=0; k=0;
		while((sroll[i++]=linestr[k++])!=',');
		sroll[i-1]='\0'; i=0;
		while((sname[i++]=linestr[k++])!=',');
		for(j=i-1 ; j<20 ; j++) sname[j]=' ';
		sname[20]='\0'; i=0;
		while((sbatch[i++]=linestr[k++])!=',');
		sbatch[i-1]='\0';
		
		cout<<N++<<" "<<sroll<<" "<<sname<<" "<<sbatch<<endl;
		fgets(linestr,79,fp);
	}
	cout<<"inputfile has been read and printed\n";
	cout<<endl<<endl;
	fclose(fp);
	
	
}//main ends

