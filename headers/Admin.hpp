#include "../headers/User.hpp"
#include "../headers/Menu.hpp"
#include "../headers/Patient.hpp"
#include "../headers/Doctor.hpp"
#include<iostream>
#include<vector>
#include<iterator>
using namespace std;
class Admin: public User
{
    void accessPatientDetails(); 
    void accessDoctorDetails(); 
    void addPatientRecord(); 
    void editPatientRecord(); 
    void deletePatientRecord(); 
    void addDoctorRecord(); 
    void editDoctorRecord(); 
    void deleteDoctorRecord(); 
    void filterPatientRecords(); 
    void storePatientRecords(); 
    void loadPatientRecords(); 
    void storeDoctorRecords(); 
    void loadDoctorRecords(); 
    void displayPatientRecords(); 
    void displayDoctorRecords(); 
    int displaySignUpPatientsId(); 
    int displayDoctorsId(); 
    string MobileNo();
    string Gender();
    void loadDoctorPatientIDs(); 
     
    vector<Patient> patientRecords; //vector to store & handle patient details
    vector<Doctor> doctorRecords; //vector to store & handle doctor information
    vector<string> patientids; //vector to store IDs of patients who are Signed Up
    vector<string> doctorids; //vector to store IDs of doctors who are available
    fstream file;
    public: 
    void home(string &); 
    Admin() 
    { 
        loadPatientRecords(); 
        loadDoctorRecords(); 
        loadDoctorPatientIDs(); 
    } 
    ~Admin() 
    { 
        storePatientRecords(); 
        storeDoctorRecords(); 
        patientRecords.clear(); 
        doctorRecords.clear(); 
    }
};

void Admin::home(string &userId) 
{ 
    cout<<"\t\t*** Welcome "<<userId<<" ***"<<std::endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    char input;
    do 
    { 
        admin_Menu(); 
        cout<<"-------------------------------------------------------------------------------------------------\n"; 
        cout<<"Select your option from menu: "; 
        try 
        { 
            cin>>input; 
            cout<<"\n"; 
            if(!isdigit(input)) 
            { 
                throw input; 
            } 
            int option=input-'0'; //converts char '1' to int 1 
            switch(option) 
            { 
                case 1: { 
                            accessDoctorDetails(); 
                            break; 
                        } 
                case 2:  
                        { 
                            accessPatientDetails(); 
                            break; 
                        } 
                case 3: 
                        { 
                            filterPatientRecords(); 
                            break; 
                        } 
                case 4: 
                        { 
                            cout<<"***** Successfully Logged Out *****\n"; 
                            break; 
                        } 
                default: 
                        cout<<"Invalid choice....Enter any option from 1-4 given in Menu\n"; 
            } 
        } 
        catch(std::exception &e) 
        { 
            cout<<e.what()<<"\n"; 
        } 
    }while(input!='4'); 
} 
//function for performing CRUD operations on Patient details
void Admin::accessPatientDetails() 
{ 
    displayPatientRecords(); 
    char choice; 
    do 
    { 
        Patient_Operations_Menu(); 
        cout<<"\nEnter your choice:"; 
        try 
        { 
            cin>>choice; 
            cout<<"\n"; 
            if(!isdigit(choice)) 
            { 
                throw choice; 
            } 
            if(choice=='1') 
            { 
                //displays the IDs of patients who are Signed Up 
                int temp=displaySignUpPatientsId(); 
                if(temp==0) 
                { 
                    cout<<"No Patient has signed up yet...\n"; 
                } 
                else 
                { 
                    addPatientRecord(); 
                } 
            } 
            else if(choice=='2') 
            { 
                editPatientRecord(); 
            } 
            else if(choice=='3') 
            { 
                deletePatientRecord(); 
            } 
            else if(choice=='4') 
            { 
                cout<<"*** Exited from accessing patient details ***\n"; 
            } 
            else 
            { 
                cout<<"Invalid choice. Input from 1-4 as per Menu given.\n"; 
            } 
        } 
        catch(std::exception &e) 
        { 
            cerr<<e.what()<<"\n"; 
        } 
    }while(choice!='4'); 
} 
//function to add the details of the patient who Signed In
void Admin::addPatientRecord()
{ 
    int age,i=0; 
    string ID,name,gender,medical_history,allergies,medication,mobileNo; 
    cout<<"Enter the details of the patient:-\n"; 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cout<<"Enter Patient ID : "; 
    cin>>ID; 
    vector<Patient>::iterator itr; 
    if(find(patientids.begin(),patientids.end(),ID)!=patientids.end()) 
    { 
        for(itr=patientRecords.begin();itr!=patientRecords.end();itr++) 
        { 
            //checks whether the patient details exists in the vector.
            if(itr->patientID==ID)
            {
                i=1; 
            } 
        } 
        if(i==1) 
        { 
            cout<<"Patient details have already been added\n"; 
        } 
        else 
        { 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout<<"Name : "; 
            getline(cin,name); 
            cout<<"Gender : ";
            gender=Gender();
            cout<<"Age : "; 
            cin>>age; 
            cout<<"Medical History : "; 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            getline(cin,medical_history); 
            cout<<"Allergies : "; 
            getline(cin,allergies); 
            cout<<"Medictaion : "; 
            getline(cin,medication); 
            cout<<"Mobile No. : "; 
            mobileNo=MobileNo(); 
            Patient info(ID,name,gender,age,medical_history,allergies,medication,mobileNo); 
            patientRecords.push_back(info); 
            cout<<"*** Patient details added successfully ***\n"; 
        } 
    } 
    else 
    { 
        cout<<"Invalid ID\n"; 
    } 
    cout<<"\n"; 
} 
//function to edit the patient details which are already exists/added.
void Admin::editPatientRecord() 
{ 
    displayPatientRecords(); 
    cout<<"Enter Patient ID which you want to edit : "; 
    string pid; 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin>>pid; 
    int place; 
    vector<Patient>::iterator itr; 
    for(itr=patientRecords.begin();itr!=patientRecords.end();itr++) 
    { 
        if(itr->patientID==pid) 
        { 
            do 
            { 
                cout<<"Enter which field to be updated(Note:Fields are from 1-7. Press 8 to stop updating)\n"; 
                cin>>place; 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                switch(place) 
                { 
                    case 1: cout<<"Name : "; 
                            getline(cin,itr->patientName); 
                            break; 
                    case 2: cout<<"Gender : ";
                            itr->gender=Gender();
                            break;
                    case 3: cout<<"Age : "; 
                            cin>>itr->age; 
                            break; 
                    case 4: cout<<"Medical History : "; 
                            getline(cin,itr->medical_history); 
                            break; 
                    case 5: cout<<"Allergies : "; 
                            getline(cin,itr->allergies); 
                            break; 
                    case 6: cout<<"Medictaion : "; 
                            getline(cin,itr->medication); 
                            break; 
                    case 7: cout<<"Mobile No. : "; 
                            itr->mobileNo=MobileNo(); 
                            break; 
                    case 8: break; 
                    default: cout<<"Invalid field. Give input from 1-7\n"; 
                            break; 
                } 
            }while(place!=8); 
            cout<<"*** Successfully updated Patient details ***\n"; 
            cout<<"\n"; 
            return; 
        } 
    } 
    cout<<"Patient ID not found\n"; 
    cout<<"\n"; 
} 
//displaying all the patient details stored in vector
void Admin::displayPatientRecords() 
{ 
    cout<<"Patient's details:-\n"; 
    cout<<"-------------------\n"; 
    if(patientRecords.empty()) 
    cout<<"~~~~ No Patient Details are recorded ~~~~\n"; 
    vector<Patient>::iterator itr; 
    for(itr=patientRecords.begin();itr!=patientRecords.end();itr++) 
    { 
        cout<<itr->patientID<<", "<<itr->patientName<<", "<<itr->gender<<", "<<itr->age<<", "<<itr->medical_history<<", "<<itr->allergies<<", "<<itr->medication<<", "<<itr->mobileNo<<"\n"; 
    } 
    cout<<"\n"; 
} 
//function to delete a particular patient record
void Admin::deletePatientRecord() 
{ 
    displayPatientRecords(); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cout<<"Enter the Patient ID to be deleted : "; 
    string pid; 
    cin>>pid; 
    vector<Patient>::iterator itr; 
    for(itr=patientRecords.begin();itr!=patientRecords.end();itr++) 
    { 
        if(itr->patientID==pid) 
        { 
            patientRecords.erase(itr); 
            cout<<"*** Deleted Patient record***\n"; 
            cout<<"\n"; 
            return; 
        } 
    } 
    cout<<"Patient ID not found\n"; 
    cout<<"\n"; 
} 
//storing all the patient details from vector to the file.
void Admin::storePatientRecords() 
{ 
    file.open("../data/PatientsInfo.csv",ios::out); 
    if(file.is_open()) 
    { 
        vector<Patient>::iterator itr; 
        for(itr=patientRecords.begin();itr!=patientRecords.end();itr++) 
        { 
            file<<itr->patientID<<","<<itr->patientName<<","<<itr->gender<<","<<itr->age<<","<<itr->medical_history<<","<<itr->allergies<<","<<itr->medication<<","<<itr->mobileNo<<"\n"; 
        } 
        file.close(); 
    } 
    else 
    cout<<"File opening failed\n"; 
} 
//loading/fetching the patient details from file and storing into vector
void Admin::loadPatientRecords() 
{ 
    file.open("../data/PatientsInfo.csv",ios::in); 
    if(file.is_open()) 
    { 
        string line; 
        while(getline(file,line)) 
        { 
            stringstream ss(line); 
            string temp; 
            string pid,name,gender,medical_history,allergies,medication,mobileNo; 
            int age; 
            getline(ss,pid,','); 
            getline(ss,name,','); 
            getline(ss,gender,',');
            getline(ss,temp,','); 
            age=stoi(temp); 
            getline(ss,medical_history,','); 
            getline(ss,allergies,','); 
            getline(ss,medication,','); 
            getline(ss,mobileNo,','); 
            Patient info(pid,name,gender,age,medical_history,allergies,medication,mobileNo); 
            patientRecords.push_back(info); 
        } 
        file.close(); 
    } 
    else 
    cout<<"File opening failed\n"; 
} 
//function to perform CRUD operations on doctor information
void Admin::accessDoctorDetails() 
{ 
    displayDoctorRecords(); 
    char choice; 
    do 
    { 
        Doctor_Operations_Menu(); 
        cout<<"\nEnter your choice:"; 
        try 
        { 
            cin>>choice; 
            cout<<"\n"; 
            if(!isdigit(choice)) 
            { 
                throw choice; 
            } 
            if(choice=='1') 
            { 
                //displays the doctor IDs who are available 
                int temp=displayDoctorsId(); 
                if(temp==0) 
                { 
                    cout<<"No Doctors Found\n"; 
                } 
                else 
                { 
                    addDoctorRecord(); 
                } 
            } 
            else if(choice=='2') 
            { 
                editDoctorRecord(); 
            } 
            else if(choice=='3') 
            { 
                deleteDoctorRecord(); 
            } 
            else if(choice=='4') 
            { 
                cout<<"*** Exited from accessing doctor details ***\n"; 
            } 
            else 
            { 
                cout<<"Invalid choice. Input from 1-4 as per Menu given.\n"; 
            } 
        } 
        catch(std::exception &e) 
        { 
            cerr<<e.what()<<"\n"; 
        } 
    }while(choice!='4'); 
} 
//function to add doctor details if the details doesn't exist for the particular doctor ID.
void Admin::addDoctorRecord() 
{ 
    string id,name,specialization; 
    int i=0; 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cout<<"Enter the details of the Doctor:-\n"; 
    cout<<"Enter Doctor Id : "; 
    cin>>id; 
    vector<Doctor>::iterator itr; 
    if(find(doctorids.begin(),doctorids.end(),id)!=doctorids.end()) 
    { 
        for(itr=doctorRecords.begin();itr!=doctorRecords.end();itr++) 
        { 
            //checking whether the doctor details exist in the vector
            if(itr->doctorID==id) 
            { 
                i=1; 
            } 
        } 
        if(i==1) 
        { 
            cout<<"Doctor details have already been added\n"; 
        } 
        else 
        { 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout<<"Name : "; 
            getline(cin,name); 
            cout<<"Specialization : "; 
            getline(cin,specialization); 
            Doctor info(id,name,specialization); 
            doctorRecords.push_back(info); 
            cout<<"*** Doctor details added successfully ***\n"; 
        } 
    } 
    else 
    { 
        cout<<"Invalid ID\n"; 
    } 
    cout<<"\n"; 
} 
//function to change/edit/update doctor information which already exists.
void Admin::editDoctorRecord() 
{ 
    displayDoctorRecords(); 
    cout<<"Enter Doctor Id which you want to edit : "; 
    string Id; 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin>>Id; 
    int place; 
    vector<Doctor>::iterator itr; 
    for(itr=doctorRecords.begin();itr!=doctorRecords.end();itr++) 
    { 
        if(itr->doctorID==Id) 
        { 
            do 
            { 
                cout<<"Enter which field to be updated(Note:Input 1-Name,2-Specialization. Press 3 to stop updating)\n"; 
                cin>>place; 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                switch(place) 
                { 
                    case 1: cout<<"Name : "; 
                            getline(cin,itr->doctorName); 
                            break; 
                    case 2: cout<<"Specialization : "; 
                            getline(cin,itr->Specialization); 
                            break; 
                    case 3: break; 
                    default: cout<<"Incorrect field. Input 1-Name,2-Specialization.\n"; 
                            break; 
                } 
            }while(place!=3); 
            cout<<"*** Updated doctor details ***\n"; 
            cout<<"\n"; 
            return; 
        } 
    } 
    cout<<"Doctor Id not found\n"; 
    cout<<"\n"; 
} 
//displaying the details of all doctors
void Admin::displayDoctorRecords() 
{ 
    cout<<"Doctor's details:-\n"; 
    cout<<"------------------\n"; 
    if(doctorRecords.empty()) 
    cout<<"~~~~ No Doctor Details are recorded ~~~~\n"; 
    vector<Doctor>::iterator itr; 
    for(itr=doctorRecords.begin();itr!=doctorRecords.end();itr++) 
    { 
        cout<<itr->doctorID<<", "<<itr->doctorName<<", "<<itr->Specialization<<"\n"; 
    } 
    cout<<"\n"; 
} 
//function to delete particular doctor information
void Admin::deleteDoctorRecord() 
{ 
    displayDoctorRecords(); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cout<<"Enter the Doctor Id to be deleted : "; 
    string Id; 
    cin>>Id; 
    vector<Doctor>::iterator itr; 
    for(itr=doctorRecords.begin();itr!=doctorRecords.end();itr++) 
    { 
        if(itr->doctorID==Id) 
        { 
            doctorRecords.erase(itr); 
            //storeDoctorRecords(); 
            cout<<"*** Deleted doctor record ***\n"; 
            cout<<"\n"; 
            return; 
        } 
    } 
    cout<<"Doctor Id not found\n"; 
    cout<<"\n"; 
} 
//stores all the doctor details from vector into the file.
void Admin::storeDoctorRecords() 
{ 
    file.open("../data/DoctorInfo.csv",ios::out); 
    if(file.is_open()) 
    { 
        vector<Doctor>::iterator itr; 
        for(itr=doctorRecords.begin();itr!=doctorRecords.end();itr++) 
        { 
            file<<itr->doctorID<<","<<itr->doctorName<<","<<itr->Specialization<<"\n"; 
        } 
        file.close(); 
    } 
    else 
    cout<<"File opening failed\n"; 
} 
//function to load/fetch the doctor details from file into the vector
void Admin::loadDoctorRecords() 
{ 
    file.open("../data/DoctorInfo.csv",ios::in); 
    if(file.is_open()) 
    { 
        string line; 
        while(getline(file,line)) 
        { 
            stringstream ss(line); 
            string Id,name,specialisation; 
            getline(ss,Id,','); 
            getline(ss,name,','); 
            getline(ss,specialisation,','); 
            Doctor info(Id,name,specialisation); 
            doctorRecords.push_back(info); 
        } 
        file.close(); 
    } 
    else 
    cout<<"File opening failed\n"; 
} 
//fetching the doctor and patient IDs from the login file to know the persons present
void Admin::loadDoctorPatientIDs() 
{ 
    ifstream file("../data/login.csv",ios::in); 
    if(file.is_open()) 
    { 
        string line; 
        while(getline(file,line)) 
        { 
            string id, name, pwd, accessLevel; 
            stringstream s(line); 
            getline(s,id,','); 
            getline(s,name,','); 
            getline(s,pwd,','); 
            getline(s,accessLevel,','); 
            if(accessLevel=="PATIENT") 
            { 
                patientids.push_back(id); 
            } 
            if(accessLevel=="DOCTOR") 
            { 
                doctorids.push_back(id); 
            } 
        } 
        file.close(); 
    } 
    else 
    { 
        cout<<"File opening failed\n"; 
    } 
} 
//function to display the IDs of patients who Signed Up
int Admin::displaySignUpPatientsId() 
{ 
    cout<<"Patients who Signed Up:-\n"; 
    cout<<"-----------------------\n"; 
    int i=0; 
    if(!patientids.empty()) 
    { 
        for(auto id:patientids) 
        { 
            i++; 
            cout<<i<<"."<<id<<"\n"; 
        } 
    } 
    cout<<"\n"; 
    return i; 
} 
//displays the doctor IDs which are present
int Admin::displayDoctorsId() 
{ 
    cout<<"Doctors Id's:-\n"; 
    cout<<"--------------\n"; 
    int i=0; 
    if(!doctorids.empty()) 
    { 
        for(auto id:doctorids) 
        { 
            i++; 
            cout<<i<<"."<<id<<"\n"; 
        } 
    } 
    cout<<"\n"; 
    return i; 
} 
//function to take input of Mobile number from the user
string Admin::MobileNo() 
{ 
    string number; 
    // validates the number and asks re-input if number is not in desired format 
    input:  
        cout<<"\n(Note:Enter 10-digit Numeric mobile number(First digit-6/7/8/9))\n"; 
        getline(cin,number); 
        if(!is_Valid_MobileNo(number)) 
        { 
            goto input; 
        } 
    return number; 
} 
//function to perform filtering on patient medical records based on different categories.
void Admin::filterPatientRecords() 
{ 
     cout<<"Implementation in progress...\n";
}
string Admin::Gender()
{
    int gender;
    selection:
        cout<<"Select 0-Male,1-Female,2-Transgender:-\n";
        cin>>gender;
        if(gender==0)
        return "Male";
        else if(gender==1)
        return "Female";
        else if(gender==2)
        return "Transgender";
        else 
        {
            cout<<"Invalid selection\n";
            goto selection;
        }
    return NULL;
}