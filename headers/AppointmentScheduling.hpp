#include<iostream>
#include<limits>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;

void displayDoctorInfo();
fstream file;
class Information
{
    public:
    string date,dName,pName,status;
    Information(string date,string dName,string pName,string status="pending"):
    date(date),dName(dName),pName(pName),status(status){}
};
class Appointment
{
    string date,dName,pName,status;
    public:
    void bookingAppointment(string &username);
    void reviewAppointment();
    void viewAppointment(string &username);
    void displayAppointments();
    void loadAppointmentDetails();
    void storeAppointmentDetails();
    vector<Information> appointmentDetails;
    fstream appFile;
    Appointment()
    {
        loadAppointmentDetails();
    }
    ~Appointment()
    {
        storeAppointmentDetails();
    }    
};
void Appointment::bookingAppointment(string &username)
{
    displayDoctorInfo();
    cout<<"\nEnter appointment date:";
    cin>>date;
    cout<<"Enter doctor name:";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin,dName);
    Information info(date,dName,username);
    appointmentDetails.push_back(info);
}
void Appointment::reviewAppointment()
{
    displayAppointments();
    string name;
    cout<<"Enter the patient name to schedule the appointment:";
    getline(cin,name);
    vector<Information>::iterator itr;
    for(itr=appointmentDetails.begin();itr!=appointmentDetails.end();itr++)
    {
        if(itr->pName==name)
        {
            itr->status="scheduled";
        }
    }
}
void Appointment::viewAppointment(string &username)
{
    // string id;
    // cout<<"Enter the patient ID:";
    // cin>>id;
    vector<Information>::iterator itr;
    for(itr=appointmentDetails.begin();itr!=appointmentDetails.end();itr++)
    {
        if(itr->pName==username)
        {
            cout<<itr->date<<" "<<itr->dName<<" "<<itr->pName<<" "<<itr->status<<"\n";
        }
    }
}
void Appointment::displayAppointments()
{
    cout<<"Requested Appointments details:-\n";
    vector<Information>::iterator itr;
    for(itr=appointmentDetails.begin();itr!=appointmentDetails.end();itr++)
    {
        if(itr->status=="pending")
        {
            cout<<itr->date<<" "<<itr->dName<<" "<<itr->pName<<" "<<itr->status<<"\n";
        }
    }
}
void Appointment::loadAppointmentDetails()
{
    appFile.open("../data/Appointments.csv",ios::in);
    if(appFile.is_open())
    {
        string line;
        while(getline(appFile,line))
        {
            stringstream ss(line);
            getline(ss,date,',');
            getline(ss,dName,',');
            getline(ss,pName,',');
            getline(ss,status,',');
            Information info(date,dName,pName,status);
            appointmentDetails.push_back(info);
        }
        appFile.close();
    }
    else
        cout<<"File opening failed\n";
}
void Appointment::storeAppointmentDetails()
{
    appFile.open("../data/Appointments.csv",ios::out);
    if(appFile.is_open())
    {
        vector<Information>::iterator itr;
        for(itr=appointmentDetails.begin();itr!=appointmentDetails.end();itr++)
        {
            appFile<<itr->date<<","<<itr->dName<<","<<itr->pName<<","<<itr->status<<"\n";
        }
        appFile.close();
    }
    else
        cout<<"File opening failed\n";
}
void displayDoctorInfo()
{
    cout<<"Here is the doctor information for your reference:-\n";
    string name,specialization;
    file.open("../data/DoctorInfo.csv",ios::in);
    if(file.is_open())
    {
        string line;
        while(getline(file,line))
        {
            stringstream ss(line);
            getline(ss,name,',');
            getline(ss,specialization,',');
            cout<<name<<" - "<<specialization<<"\n";
        }
        file.close();
    }
    else
        cout<<"File opening failed\n";
}