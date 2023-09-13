#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;

class Information
{
    public:
    string date,dID,pID,status;
    Information(string date,string dID,string pID,string status="pending"):
    date(date),dID(dID),pID(pID),status(status){}
};
class Appointment
{
    string date,dID,pID,status;
    public:
    void bookingAppointment();
    void reviewAppointment();
    void viewAppointment();
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
void Appointment::bookingAppointment() // make sure no repeat Appointment
{
    cout<<"Enter appointment date:";
    cin>>date;
    cout<<"Enter doctor ID:";
    cin>>dID;
    cout<<"Enter patient ID:";
    cin>>pID;
    Information info(date,dID,pID);
    appointmentDetails.push_back(info);
}
void Appointment::reviewAppointment()  // make sure dr. can accept or reject
{
    displayAppointments();
    string id;
    cout<<"Enter the patient ID to schedule the appointment:";
    cin>>id;
    vector<Information>::iterator itr;
    for(itr=appointmentDetails.begin();itr!=appointmentDetails.end();itr++)
    {
        if(itr->pID==id)
        {
            itr->status=1;
        }
    }
}
void Appointment::viewAppointment()
{
    string id;
    cout<<"Enter the patient ID:";
    cin>>id;
    vector<Information>::iterator itr;
    for(itr=appointmentDetails.begin();itr!=appointmentDetails.end();itr++)
    {
        if(itr->pID==id)
        {
            cout<<itr->date<<" "<<itr->dID<<" "<<itr->pID<<" "<<itr->status<<"\n";
        }
    }
}
void Appointment::displayAppointments()
{
    vector<Information>::iterator itr;
    for(itr=appointmentDetails.begin();itr!=appointmentDetails.end();itr++)
    {
        if(itr->status=="pending")
        {
            cout<<itr->date<<" "<<itr->dID<<" "<<itr->pID<<" "<<itr->status<<"\n";
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
            getline(ss,dID,',');
            getline(ss,pID,',');
            getline(ss,status,',');
            Information i(date,dID,pID,status);
            appointmentDetails.push_back(i);
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
            appFile<<itr->date<<","<<itr->dID<<","<<itr->pID<<","<<itr->status<<"\n";
        }
        appFile.close();
    }
    else
        cout<<"File opening failed\n";
}