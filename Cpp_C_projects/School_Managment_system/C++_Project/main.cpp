/**
 * @file main.cpp
 * @author Ziad Mohammed Fathy
 * @brief  Student Management System using C++. 
 * @version 0.1
 * @date 2024-12-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include "Student.cpp"
#include <cstdlib>
int Menu() {
    int choise = 0;
    cout<<"\nChoose option: \n";
    cout<<"----------------\n\n";
    cout<<"1-Enter New Data\n";
    cout<<"2-Update Data\n";
    cout<<"3-Delete Data\n";
    cout<<"4-Print All Data\n";
    cout<<"5-Search Data\n";
    cout<<"6-Exit\n";
    cout<<"\n=> Enter Choise : ";
    cin>>choise;
    return choise;
}

int main(void) {
    Students Data;
    cout<<"------ Welcome in Student Management Programe -----\n";
    while (1)
    {
        int retChoise = Menu();
        system("cls");
        switch (retChoise)
        {
        case 1:
            Data.setData();
            break;
        case 2:
            Data.updateData();
            break;
        case 3:
            Data.deleteData();
            break;
        case 4:
            Data.showData();
            break;
        case 5:
            Data.searchData();
            break;   
        default:
            break;
        }
        if(retChoise == 6) {
            break;
        }
    }
    
    return 0;
}
