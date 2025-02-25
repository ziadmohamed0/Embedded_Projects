/**
 * @file Student.cpp
 * @author Ziad Mohammed Fathy
 * @brief Student Class File
 * @version 0.1
 * @date 2024-12-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Students {
private:
    int ID[10];
    string Name[10];
    int Age[10];
    string Department[10];
    int AdmissionYear[10];
    long long PhoneNumber[10];
    int counter;
    string fileName;

public:
    Students() {
        counter = 0;
        fileName = "StudentsData.csv";

        // Load existing data from file
        ifstream file(fileName);
        if (file.is_open()) {
            string line;
            getline(file, line); // Skip header
            while (getline(file, line) && counter < 10) {
                stringstream ss(line);
                string temp;
                getline(ss, temp, ',');
                ID[counter] = stoi(temp);
                getline(ss, Name[counter], ',');
                getline(ss, temp, ',');
                Age[counter] = stoi(temp);
                getline(ss, Department[counter], ',');
                getline(ss, temp, ',');
                AdmissionYear[counter] = stoi(temp);
                getline(ss, temp, ',');
                PhoneNumber[counter] = stoll(temp);
                counter++;
            }
            file.close();
        } else {
            // Create a new file with a header if it doesn't exist
            ofstream newFile(fileName);
            newFile << "ID,Name,Age,Department,AdmissionYear,PhoneNumber\n";
            newFile.close();
        }
    }

    void saveToFile() {
        ofstream file(fileName);
        if (file.is_open()) {
            file << "ID,Name,Age,Department,AdmissionYear,PhoneNumber\n";
            for (int i = 0; i < counter; i++) {
                if (ID[i] != 0) { // Skip deleted records
                    file << ID[i] << "," << Name[i] << "," << Age[i] << ","
                         << Department[i] << "," << AdmissionYear[i] << ","
                         << PhoneNumber[i] << "\n";
                }
            }
            file.close();
        } else {
            cerr << "Failed to save data to file!" << endl;
        }
    }

    void setData() {
        int x=0;
        cout << "=> How Many Students Do you Want to Enter? ";
        int n;
        cin >> n;
        for (int i = counter; i < counter + n && i < 10; i++) {
            cout << "\n=>Enter Name of Student {" << x + 1 << "} : ";
            cin.ignore();
            getline(cin, Name[i]);
            cout << "=>Enter Age of Student {" << x + 1 << "} : ";
            cin >> Age[i];
            cout << "=>Enter ID of Student {" << x + 1 << "} : ";
            cin >> ID[i];
            cout << "=>Enter Department of Student {" << x + 1 << "} : ";
            cin.ignore();
            getline(cin, Department[i]);
            cout << "=>Enter Admission Year of Student {" << x + 1 << "} : ";
            cin >> AdmissionYear[i];
            cout << "=>Enter Phone Number of Student {" << x + 1 << "} : ";
            cin >> PhoneNumber[i];
            x++;
            cout << "\n-------------------------------\n";
        }
        counter += n;
        saveToFile();
        cout << "All Data is Set and Stored in File." << endl;
    }

    void showData() {
        cout << "-------------------------------\n";
        if (counter == 0) {
            cout << "Data is Empty" << endl;
        } else {
            for (int i = 0; i < counter; i++) {
                if (ID[i] != 0) { // Skip deleted records
                    cout << "=>Name of Student {" << i + 1 << "} : " << Name[i] << endl;
                    cout << "=>Age of Student {" << i + 1 << "} : " << Age[i] << endl;
                    cout << "=>ID of Student {" << i + 1 << "} : " << ID[i] << endl;
                    cout << "=>Department of Student {" << i + 1 << "} : " << Department[i] << endl;
                    cout << "=>Admission Year of Student {" << i + 1 << "} : " << AdmissionYear[i] << endl;
                    cout << "=>Phone Number of Student {" << i + 1 << "} : +" << PhoneNumber[i] << endl;
                    cout << "-------------------------------\n";
                }
            }
        }
    }

    void updateData() {
        int id;
        cout << "=> Enter the ID of the student which you want to update: ";
        cin >> id;

        bool found = false; // لمعرفة ما إذا تم العثور على الطالب أم لا
        for (int i = 0; i < counter; i++) {
            if (ID[i] == id) {
                found = true;
                cout << "=> Previous data\n";
                cout << "=> Name of Student {" << i + 1 << "} : " << Name[i] << endl;
                cout << "=> Age of Student {" << i + 1 << "} : " << Age[i] << endl;
                cout << "=> Department of Student {" << i + 1 << "} : " << Department[i] << endl;
                cout << "=> Admission Year of Student {" << i + 1 << "} : " << AdmissionYear[i] << endl;
                cout << "=> Phone Number of Student {" << i + 1 << "} : +" << PhoneNumber[i] << endl;

                // إدخال البيانات الجديدة
                cout << "\n=> Enter new data\n";
                cout << "=> Enter Name of Student {" << i + 1 << "} : ";
                cin.ignore();
                getline(cin, Name[i]);
                cout << "=> Enter Age of Student {" << i + 1 << "} : ";
                cin >> Age[i];
                cout << "=> Enter Department of Student {" << i + 1 << "} : ";
                cin.ignore();
                getline(cin, Department[i]);
                cout << "=> Enter Admission Year of Student {" << i + 1 << "} : ";
                cin >> AdmissionYear[i];
                cout << "=> Enter Phone Number of Student {" << i + 1 << "} : ";
                cin >> PhoneNumber[i];
                cout << "\nData updated successfully!\n";

                break; // التوقف عن البحث بعد تعديل البيانات
            }
        }

        if (!found) {
            cout << "Student with ID " << id << " not found!" << endl;
            return; // إذا لم يتم العثور على الطالب، الخروج من الدالة
        }

        // إعادة كتابة الملف ببيانات محدثة
        ofstream file(fileName);
        if (file.is_open()) {
            file << "ID,Name,Age,Department,AdmissionYear,PhoneNumber\n"; // كتابة العنوان
            for (int i = 0; i < counter; i++) {
                if (ID[i] != 0) { // تخطي السجلات المحذوفة
                    file << ID[i] << "," << Name[i] << "," << Age[i] << ","
                        << Department[i] << "," << AdmissionYear[i] << ","
                        << PhoneNumber[i] << "\n";
                }
            }
            file.close();
        } else {
            cerr << "Failed to save updated data to file!" << endl;
        }
    }



    void deleteData() {
        int id;
        cout << "Enter ID of Student to Delete his Data: ";
        cin >> id;
        for (int i = 0; i < counter; i++) {
            if (ID[i] == id) {
                ID[i] = 0; // Mark as deleted
                cout << "Student data deleted successfully!" << endl;
                saveToFile();
                return;
            }
        }
        cout << "Student with ID " << id << " not found!" << endl;
    }

    void searchData() {
        int id, flag;
        cout << "Enter ID of Student to Search for his Data: ";
        cin >> id;
        cout << "-------------------------------\n";
        for (int i = 0; i < counter; i++) {
            if (ID[i] == id) {
                cout << "=>Name of Student {" << i + 1 << "} : " << Name[i] << endl;
                    cout << "=>Age of Student {" << i + 1 << "} : " << Age[i] << endl;
                    cout << "=>ID of Student {" << i + 1 << "} : " << ID[i] << endl;
                    cout << "=>Department of Student {" << i + 1 << "} : " << Department[i] << endl;
                    cout << "=>Admission Year of Student {" << i + 1 << "} : " << AdmissionYear[i] << endl;
                    cout << "=>Phone Number of Student {" << i + 1 << "} : +" << PhoneNumber[i] << endl;
                    cout << "-------------------------------\n";
                flag = 1;
                break;
            }
            else {
                flag = 0;
                cout << "Student with ID " << id << " not found!" << endl;
                break;
            }
        }
    }
};