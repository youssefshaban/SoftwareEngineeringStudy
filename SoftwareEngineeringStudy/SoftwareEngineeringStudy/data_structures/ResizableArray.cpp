//
//  ResizableArray.cpp
//  SoftwareEngineeringStudy
//
//  Created by youssef shaban on 7/12/20.
//  Copyright © 2020 youssef shaban. All rights reserved.
//  finally i have to thank Mmuhammed Ablelkawy for helping 

#include "ResizableArray.hpp"
#include <iostream>
using namespace std;
class ArrayImpl {
    int *arr ;
    int size ;
    int capacity ;
    public :
    ArrayImpl (){
        size = 0;
        capacity = 1;
        arr = new int[capacity];
    }
    void push (int newInt){
        if (size==capacity){
            dubleSize();
        }
        arr[size]=newInt;
        size++;
    }
    void pop (){
        size--;
    }
    void print (){
        for (int i = 0 ; i < size ;i++){
            cout<<arr[i];
        }
    }
    void prepend (int Data){
        if (size==capacity){
            int *temp = new int[capacity*2];
            capacity*=2;
            temp[0]=Data;
            size++;
            for (int i = 0; i<size ;i++)
            {
                temp[i+1]=arr[i];
            }
            delete[]  arr ;
            arr = temp;
        }else{
            size++;
            for (int i = size; i>0; i++) {
                arr[i]=arr[i-1];
            }
            
        }
        
        
    }
    void resize() {
        if (size<(capacity/2)){
            int *temp = new int [capacity/2];
            for (int i =0; i<size; i++) {
                temp[i]=arr[i];
                
            }
            delete[] arr;
            arr=temp;
            capacity/=capacity;
        }else{
            return;
        }
    }
    void deleteAt(int index){
        if (index==size){
            pop();
        }else{
            for(int i=index;i>size;i++){
                arr[i]=arr[i+1];
            }
            pop();
        }
    }
    void remove(int data){
        for(int i=0;i<size;i++){
            if(arr[i]==data){
                deleteAt(i);
            }
        }
    }
    void dubleSize (){
        int *temp = new int[capacity*2];
        capacity*=2;
        for (int i = 0; i<size ;i++) {
            temp[i]=arr[i];
        }
        delete[]  arr ;
        arr = temp;
    }
    
    
    
};



int main () {
    
    ArrayImpl arrayImpl ;
    arrayImpl.push(7);
    arrayImpl.push(8);
    arrayImpl.push(9);
    arrayImpl.push(10);
    arrayImpl.push(99);
    arrayImpl.print();
    cout<<endl;
    arrayImpl.prepend(2);
    arrayImpl.print();
    cout<<endl;
    arrayImpl.pop();
    arrayImpl.print();
    cout<<endl;
    arrayImpl.deleteAt(2);
    arrayImpl.resize();
    arrayImpl.remove(3);
    
    return 0;
}
