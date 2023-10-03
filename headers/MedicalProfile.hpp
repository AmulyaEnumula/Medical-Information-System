#ifndef MEDICALPROFILE_HPP
#define MEDICALPROFILE_HPP
#include<iostream>
#include<vector>
#include<list>
#include<fstream>
#include<sstream>
#include<limits>
using namespace std;
char* InputCurrentDate();
class Medicine
{
    public:
    string name,dose,duration;
    Medicine(){}
    Medicine(string name,string dose,string duration):
    name(name),dose(dose),duration(duration){}
};
class Test
{
    public:
    string date,diagnosis,treatment;
    Test(){}
    Test(string date,string diagnosis,string treatment):
    date(date),diagnosis(diagnosis),treatment(treatment){}
};
class MedicalRecord
{
    public:
    Test test;
    vector<Medicine> medicineList;
    MedicalRecord(){}
    MedicalRecord(string date,string diagnosis,string treatment,vector<Medicine> medicineList):
    test(date,diagnosis,treatment),medicineList(medicineList){}
    vector<MedicalRecord> records;
    ~MedicalRecord()
    {
        records.clear();
    }
    void consultation(string &,string &);
    void loadMedicalHistory(string &);
    void storeMedicalRecord(string &);
    void showMedicalHistory(string &,string &);
    void addMedicalRecord(string &,string &);
    void updateMedicalRecord(string &,string &);
};
void MedicalRecord::consultation(string &doctorId,string &patientId)
{
    string fileName=doctorId+"-"+patientId+".csv";
    loadMedicalHistory(fileName);
    showMedicalHistory(doctorId,patientId);
    addMedicalRecord(doctorId,patientId);
    showMedicalHistory(doctorId,patientId);
    updateMedicalRecord(doctorId,patientId);
    storeMedicalRecord(fileName);
}
void MedicalRecord::addMedicalRecord(string &doctorId,string &patientId)
{
    string date,diagnosis,treatment,medicineName,dose,duration;
    char response;
    cout<<"Enter Test details of Patient:-\n";
    date=InputCurrentDate();
    
    cout<<"Diagnosis:";
    getline(cin,diagnosis);
    //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<"Treatment:";
    getline(cin,treatment);
    cout<<"Enter Prescription details:-\n";
    do
    {
        cout<<"Medicine Name:";
        getline(cin,medicineName);
        //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout<<"Number of times the medicine to be taken in a day:";
        cin>>dose;
        cout<<"Number of days medicine to be taken:";
        cin>>duration;
        medicineList.push_back(Medicine(medicineName,dose,duration));
        cout<<"Do you want to add more medicine(y/n):";
        cin>>response;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }while(response!='n');
    MedicalRecord record(date,diagnosis,treatment,medicineList);
    records.push_back(record);
}
void MedicalRecord::showMedicalHistory(string &doctorId,string &patientId)
{
    if(records.empty())
    { 
        cout<<"No medical records available\n";
        return;
    }
    vector<MedicalRecord>::iterator itr;
    vector<Medicine>::iterator it;
    int i=0;
    for(itr=records.begin();itr!=records.end();itr++)
    {
        cout<<itr->test.date<<","<<itr->test.diagnosis<<","<<itr->test.treatment;
        for(it=itr->medicineList.begin();it!=itr->medicineList.end();it++)
        {
            cout<<"/"<<it->name<<" -"<<it->dose<<" times -"<<it->duration<<" days";
        }
        medicineList.clear();
        cout<<"\n";
    }
}
void MedicalRecord::updateMedicalRecord(string &doctorId,string &patientId)
{
    
}
void MedicalRecord::storeMedicalRecord(string &fileName)
{
    ofstream file("../data/Prescriptions/"+fileName);
    if(file.is_open())
    {
        vector<MedicalRecord>::iterator itr;
        vector<Medicine>::iterator it;
        for(itr=records.begin();itr!=records.end();itr++)
        {
            file<<itr->test.date<<","<<itr->test.diagnosis<<","<<itr->test.treatment<<",";
            for(it=itr->medicineList.begin();it!=itr->medicineList.end();it++)
            {
                file<<it->name<<":"<<it->dose<<":"<<it->duration<<";";
            }
            file<<"\n";
            medicineList.clear();
        }
        file.close();
    }
    else
    {
        cout<<"Unable to open file...\n";
    }
}
void MedicalRecord::loadMedicalHistory(string &fileName)
{
    ifstream file("../data/Prescriptions/"+fileName);
    string date,diagnosis,treatment,medicineName,dose,duration;
    if(file.is_open())
    {
        string line,medlist,medicine;
        while(getline(file,line))
        {
            stringstream ss(line);
            getline(ss,date,',');
            getline(ss,diagnosis,',');
            getline(ss,treatment,',');
            getline(ss,medlist,',');
            stringstream s(medlist);
            while(getline(s,medicine,';'))
            {
                stringstream sss(medicine);
                getline(sss,medicineName,':');
                getline(sss,dose,':');
                getline(sss,duration,':');
                medicineList.push_back(Medicine(medicineName,dose,duration));
            }
            MedicalRecord record(date,diagnosis,treatment,medicineList);
            records.push_back(record);
            medicineList.clear();
        }
        file.close();
    }
    else
    {
        cout<<"Unable to open file...\n";
    }
}
char* InputCurrentDate()
{ 
    time_t currentTime=time(nullptr); 
    tm* currentDate=localtime(&currentTime); 
    char* s=new char[50]; 
    strftime(s, 50, "%d-%m-%Y", currentDate); 
    return s; 
} 
#endif