#include<iostream>
#include<string.h>
using namespace std;
class Point
{
public:
    int x;
    int y;

    Point(){
        x=0;
        y=0;
    }
    
    Point(int a,int b){
        x=a;
        y=b;
    }
    void set(int a,int b){
        x=a;
        y=b;
    }
      // ">" 运算符重载
      bool operator >( Point &a){
         if((x*x+y*y-a.x*a.x-a.y*a.y)>0)
             return true;
             else
                 return false;
         }
};
template<class T>
class DynamicArray{
private:
    T *aData;
    int num;
    int length;
public:
    DynamicArray(){
        length=10;
        num=0;
        aData=new T[10];
    }
   
    ~DynamicArray(){
        if (aData!=NULL) {
            delete []aData;
        }
        aData=NULL;
    }
    int Addltem(T pData){
        if(num==length){
            T *aTata;
            aTata=new T[num+1];
            for(int i=0;i<num;i++){
                aTata[i]=aData[i];
            }
            delete []aData;
            aData=new T[num+1];
            for (int i=0; i<num; i++) {
                aData[i]=aTata[i];
            }
            delete []aTata;
            aTata=NULL;
            aData[num+1]=pData;
            length++;
            num++;
            return num;
        }
        aData[num]=pData;
        num++;
        return num;
    }
    int Addltem(Point &a){
        if(num==length){
            T *aTata;
            aTata=new T[num+2];
            for(int i=0;i<num;i=i+2){
                aTata[i]=a.x;
                aTata[i+1]=a.y;
            }
            delete []aData;
            aData=new T[num+2];
            for (int i=0; i<num; i++) {
                aData[i]=aTata[i];
            }
            delete []aTata;
            aTata=NULL;
            aData[num+2]=a.y;
            aData[num+1]=a.x;
            length++;
            num++;
            return num;
        }
        aData[num]=a.x;
        aData[num+1]=a.y;
        
        num=num+2;
        return num;
    }
    bool RemoveAt(int index){
        for(;index<num;index++){
            aData[index]=aData[index+1];
        }
        num=num-1;
        return 1;
    }
    void InsertItem( int index, T aCata){
        aData[num+1]=aData[num];
        int x=num;
        for(int i=index;i<num;i++,x--){
            aData[x]=aData[x-1];
        }
        aData[index]=aCata;
        num++;
    }
    void SelectSort(){
        T temp;
        for(int i=0;i<num;i++)
           {
            for(int j=0;j<num-1;j++)
               {
                if(aData[j]<aData[j+1]){
                    temp=aData[j];
                    aData[j]=aData[j+1];
                    aData[j+1]=temp;
                }
            }
        }
    }
    void Show(){
        for(int i=0;i<num;i++){
            cout<<aData[i]<<" ";
        }
    }
};

int main(){
    cout<<"请选择输入的类型，int型请输入1，float型请输入2，string型请输入3,Point类型请输入4"<<endl;
    int f1;
    cin>>f1;
    int num;
    if(f1==1){
    int a;
        DynamicArray< int > D1;
        cout<<"输入数据个数"<<endl;
        cin>>num;
    
        cout<<"末尾插入"<<endl;
    for(int i=0;i<num;i++){
        cin>>a;
         D1.Addltem(a);
    }
        D1.Show();
        cout<<"输入插入"<<endl;
        int s;
        cin>>s;
        cout<<"输入插入位置"<<endl;
        int index;
        cin>>index;
        D1.InsertItem(index, s);
        D1.Show();
        cout<<"删除位置"<<endl;
        int k;
        cin>>k;
        D1.RemoveAt(k);
        cout<<"删除成功"<<endl;
        D1.Show();
        cout<<"排序"<<endl;
        D1.SelectSort();
        D1.Show();
    }
    if(f1==2){
    float f;
        DynamicArray< float > D2;
        cout<<"输入数据个数"<<endl;
        cin>>num;
        cout<<"末尾插入"<<endl;
    for(int i=0;i<num;i++){
        cin>>f;
         D2.Addltem(f);
    }
        D2.Show();
        cout<<"输入插入"<<endl;
        float s;
        cin>>s;
        cout<<"输入插入位置"<<endl;
        int index;
        cin>>index;
        D2.InsertItem(index, s);
        D2.Show();
        cout<<"删除位置"<<endl;
        int k;
        cin>>k;
        D2.RemoveAt(k);
        cout<<"删除成功"<<endl;
        D2.Show();
        cout<<"排序"<<endl;
        D2.SelectSort();
        D2.Show();
    }
    if(f1==3){
       string a;
            DynamicArray< string > D3;
            cout<<"输入数据个数"<<endl;
            cin>>num;
        
            cout<<"末尾插入"<<endl;
        for(int i=0;i<num;i++){
            cin>>a;
             D3.Addltem(a);
        }
            D3.Show();
            cout<<"输入插入"<<endl;
            string s;
            cin>>s;
            cout<<"输入插入位置"<<endl;
            int index;
            cin>>index;
            D3.InsertItem(index, s);
            D3.Show();
        cout<<"删除位置"<<endl;
        int k;
        cin>>k;
        D3.RemoveAt(k);
        cout<<"删除成功"<<endl;
        D3.Show();
            cout<<"排序"<<endl;
            D3.SelectSort();
            D3.Show();
        }
    if(f1==4){
       
        }
    return 0;
}
