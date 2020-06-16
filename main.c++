#include<bits/stdc++.h>

std::vector<std::vector<int>> transposeMatrix(std::vector<std::vector<int>> a){
    int temp;
    for(auto i = 0; i < a.size(); ++i)
    {
        for(auto j = i+1; j < a[i].size(); ++j)
        {
            std::swap(a[i][j],a[j][i]);
        }
    }
    return a;
}

std::vector<std::vector<int>> flipMatrixRightLeft(std::vector<std::vector<int>> a){
    int ptr1 = 0,ptr2 = a.size()-1;
    while(ptr1<ptr2)
    {
        for(int i = 0; i < a[1].size(); ++i)
        {
            std::swap(a[i][ptr1],a[i][ptr2]);
        }
        ptr1++;ptr2--;
    }
    return a;
}

std::vector<std::vector<int>> flipMatrixTopBottom(std::vector<std::vector<int>> a){
    int ptr1 = 0,ptr2 = a.size()-1;
    while(ptr1<ptr2)
    {
        for(int i = 0; i < a[1].size(); ++i)
        {
            std::swap(a[ptr1][i],a[ptr2][i]);
        }
        ptr1++;ptr2--;
    }
    return a;
}

void show(std::vector<std::vector<int>> a){
    for(auto i = 0; i < a.size(); ++i){
        for(auto j = 0; j < a[i].size(); ++j){
            std::cout<<a[i][j]<<"  ";
        }
        std::cout<<"\n";
    }
}

std::vector<std::vector<int>> nintyClockwise(std::vector<std::vector<int>> a){
    std::vector<std::vector<int>> b;
    b = transposeMatrix(a);
    b = flipMatrixRightLeft(b);
    return b;
}

std::vector<std::vector<int>> oneEightyClockwise(std::vector<std::vector<int>> a){
   std::vector<std::vector<int>> b;
   b = flipMatrixTopBottom(a);
   b = flipMatrixRightLeft(b);
   return b;
}

std::vector<std::vector<int>> twoSeventyClockwise(std::vector<std::vector<int>> a){
    std::vector<std::vector<int>> b;
    b = transposeMatrix(a);
    b = flipMatrixRightLeft(b);
    b = flipMatrixTopBottom(b);
    b = flipMatrixRightLeft(b);
    return b;
}

int main()
{
    std::vector<std::vector<int>> a;
    std::vector<int> row;
    int n,choice,input; 
    char choice1;
    do{
        std::cout<<"Enter the size of the square matrix::";
        std::cin>>n;
        std::cout<<"Enter the elements::";
        for(auto  i = 0; i < n; ++i)
        {
            for(auto j = 0; j < n; ++j)
            {
                std::cin>>input;
                row.push_back(input);
            }
            a.push_back(row);
            row.clear();
        }
        show(a);
        std::cout<<"Choose from the followig::"<<"\n";
        std::cout<<"1.Rotate the matrix to a 90::"<<"\n";
        std::cout<<"2.Rotate the matrix to a 180::"<<"\n";
        std::cout<<"3.Rotate the matrix to a 270::"<<"\n";
        std::cin>>choice;
        switch(choice){
            case 1: 
            a = nintyClockwise(a);
            show(a);
            break;
            case 2: 
            a = oneEightyClockwise(a);
            show(a);
            break;
            case 3: 
            a = twoSeventyClockwise(a);
            show (a);
            break;
        }
        std::cout<<"DO YOU WANT TO CONTINUE?";
        std::cin>>choice1;
        a.clear();
    }while(choice1=='y'||choice1=='Y');
}