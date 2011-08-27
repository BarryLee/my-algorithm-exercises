#include<iostream>
using namespace std;
void print_sq(int start,int end){ //打印序列
    for(int i=start;i<=end;i++)
        cout<<i<<" ";
    cout<<endl;
}
void find_the_sq(int num){
    int start=1,end=2,mid=num/2;
    int sum=(start+end);
    while(start<=mid){ //检索，若是sum大了，则start右移，若是小了则end右移
        if(sum<num)
            sum+=++end;
        else if(sum>num)
            sum-=start++;
        else{
            print_sq(start,end);
            sum-=start++;
        }
    }
}
int main(void){
    int num;
    while(cin>>num)
    {
        find_the_sq(num);
    }
    return 0;
}
