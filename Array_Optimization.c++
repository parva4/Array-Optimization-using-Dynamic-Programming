//Author-Parva Siddhartha Parikh

#include<iostream>
#include<algorithm>
#include<array>
using namespace std;

void Display(int arr[],int n){
    for(int i=0;i<n;i++){
        std::cout<<arr[i]<<" ";
    }
}

void Array_input(int arr[],int n){
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
}

void Display_2d(int arr[20][20],int rows,int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            std::cout<<arr[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}

int ArraySum(int arr[],int start,int end){
    int sum=0;
    for(int i=start;i<=end;i++){
        sum+=arr[i];
    }
    return sum;
}

//i=rows,j=columns
int Max_min_grouping(int A[],int rows,int cols){
    //int A[12]={3,9,7,8,2,6,5,10,1,7,6,4},n=12;
    int c[rows][cols],P[rows][cols],G[rows],B[rows];
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            int maximum=0,maxk=0;
            if(j<i){
                c[i][j]=0;
            }
            else{
                if(i==0){
                    c[i][j]=ArraySum(A,0,j);
                }
                else if(i!=0){
                    for(int k=i-1;k<j;k++){
                        c[i][j]=min(c[i-1][k],ArraySum(A,k+1,j));
                        if(c[i][j]>maximum){
                            maximum=c[i][j];
                            maxk=k;
                        }
                    c[i][j]=maximum;
                    P[i][j]=maxk;
                    }
                }
            }
        }
    }
    //Array G
    int p=rows-1,q=cols-1;
    while(p>=0){
        int x=P[p][q];
        G[p]=q-x;
        q=P[p][q];
        p--;
        G[0]=cols-ArraySum(G,1,rows-1);
    }

    int start=0;
    for(int i=0;i<rows;i++){
        B[i]=ArraySum(A,start,start+G[i]-1);
        start=G[i];
    }
    std::cout<<"Array G"<<"\n";
    Display(G,rows);
    std::cout<<"\nArray B\n";
    Display(B,rows);
    return 0;
}

int main(){
    int n,M,A[30];
    std::cout<<"enter n and M\n";
    std::cin>>n>>M;
    Array_input(A,n);
    std::cout<<"Array A\n";
    Display(A,n);
    std::cout<<"\nAfter Max_min_grouping\n";
    Max_min_grouping(A,M,n);
}