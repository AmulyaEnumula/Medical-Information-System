#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;

class Appointment
{
    string date,dID,pID;
    bool status;
    public:
    void bookingAppointment();
    void reviewAppointment();
    void viewAppointment();
    void displayAppointments();
    void loadAppointmentDetails();
    void storeAppointmentDetails();
    vector<Appointment> appointmentDetails;
    fstream appFile;
    Appointment()
    {
        loadAppointmentDetails();
    }
    Appointment(string date,string dID,string pID,bool status=0)
    {
        this->date=date;
        this->dID=dID;
        this->pID=pID;
        this->status=status;
    }
    ~Appointment()
    {
        storeAppointmentDetails();
        appointmentDetails.clear();
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
    appointmentDetails.push_back(Appointment(date,dID,pID));
}
void Appointment::reviewAppointment()  // make sure dr. can accept or reject
{
    displayAppointments();
    cout<<"Enter the patient ID to schedule the appointment:";
    cin>>pID;
    vector<Appointment>::iterator itr;
    for(itr=appointmentDetails.begin();itr!=appointmentDetails.end();itr++)
    {
        if(itr->pID==pID)
        {
            itr->status=1;
        }
    }
}
void Appointment::viewAppointment()
{
    cout<<"Enter the patient ID:";
    cin>>pID;
    vector<Appointment>::iterator itr;
    for(itr=appointmentDetails.begin();itr!=appointmentDetails.end();itr++)
    {
        if(itr->pID==pID)
        {
            cout<<itr->date<<" "<<itr->dID<<" "<<itr->pID<<itr->status<<"\n";
        }
    }
}
void Appointment::displayAppointments()
{
    vector<Appointment>::iterator itr;
    for(itr=appointmentDetails.begin();itr!=appointmentDetails.end();itr++)
    {
        if(itr->status==0)
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
            string temp;
            getline(ss,date,',');
            getline(ss,dID,',');
            getline(ss,pID,',');
            getline(ss,temp,',');
            status=stoi(temp);
            appointmentDetails.push_back(Appointment(date,dID,pID,status));
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
        vector<Appointment>::iterator itr;
        for(itr=appointmentDetails.begin();itr!=appointmentDetails.end();itr++)
        {
            cout<<itr->date<<" "<<itr->dID<<" "<<itr->pID<<" "<<itr->status<<"\n";
        }
        appFile.close();
    }
    else
        cout<<"File opening failed\n";
}