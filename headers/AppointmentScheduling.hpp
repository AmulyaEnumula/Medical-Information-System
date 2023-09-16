#include "../headers/Validation.hpp"
#include<limits>
// #include<fstream>
// #include<sstream>
#include<vector>
#include<string>

void displayDoctorInfo();
string selectDate();
fstream file;
class AppointmentDetails
{
    public:
    string date,dName,pName,status;
    AppointmentDetails(string date,string dName,string pName,string status="pending"):
    date(date),dName(dName),pName(pName),status(status){}
};
class Appointment
{
    string date,dName,pName,status;
    public:
    void bookingAppointment(string &username);
    void scheduleAppointment();
    void viewAppointment(string &username);
    bool displayRequestedAppointments();
    void loadAppointmentDetails();
    void storeAppointmentDetails();
    vector<AppointmentDetails> appointmentDetails;
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
    vector<AppointmentDetails>::iterator itr;
    for(itr=appointmentDetails.begin();itr!=appointmentDetails.end();itr++)
    {
        if(itr->pName==username)
        {
            cout<<"You have already booked\n";
            return;
        }
    }
    displayDoctorInfo();
    cout<<"Enter appointment date:";
    date=selectDate();
    cout<<"Enter doctor name:";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin,dName);
    if(is_Valid_Doctor(dName))
    {
        AppointmentDetails details(date,dName,username);
        appointmentDetails.push_back(details);
        cout<<"Appointment booking is successful!!!\n";
    }
    else
    {
        cout<<"Doctor not found\n";
    }
}
void Appointment::scheduleAppointment()
{
    if(displayRequestedAppointments())
    {
        string name;
        cout<<"Enter the patient name to schedule the appointment:";
        getline(cin,name);
        vector<AppointmentDetails>::iterator itr;
        for(itr=appointmentDetails.begin();itr!=appointmentDetails.end();itr++)
        {
            if(itr->pName==name)
            {
                itr->status="scheduled";
                return;
            }
        }
        cout<<"Patient not found\n";
    }
    else
    {
        return;
    }
}
void Appointment::viewAppointment(string &username)
{
    // string id;
    // cout<<"Enter the patient ID:";
    // cin>>id;
    int i=0;
    vector<AppointmentDetails>::iterator itr;
    for(itr=appointmentDetails.begin();itr!=appointmentDetails.end();itr++)
    {
        if(itr->pName==username)
        {
            i=1;
            cout<<itr->date<<" "<<itr->dName<<" "<<itr->pName<<" "<<itr->status<<"\n";
        }
    }
    if(i==0)
    {
        cout<<"No Appointments found...Kindly book an Appointment\n";
    }
}
bool Appointment::displayRequestedAppointments()
{
    if(appointmentDetails.empty())
    {
        cout<<"No pending Appointments\n";
        return false;
    }
    cout<<"Requested Appointments details:-\n";
    vector<AppointmentDetails>::iterator itr;
    for(itr=appointmentDetails.begin();itr!=appointmentDetails.end();itr++)
    {
        if(itr->status=="pending")
        {
            cout<<itr->date<<" "<<itr->dName<<" "<<itr->pName<<" "<<itr->status<<"\n";
        }
    }
    return true;
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
            AppointmentDetails details(date,dName,pName,status);
            appointmentDetails.push_back(details);
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
        vector<AppointmentDetails>::iterator itr;
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
    cout<<"\n";
}
string selectDate()
{
    string Date;
    cout<<"(Note: Enter date in DD-MM-YYYY format)\n";
    // validates the date and asks re-input if date is not in DD-MM-YYYY format
    input:
        cin>>Date;
        if(!is_Valid_Date(Date))
        {
            goto input;
        }
    return Date;
}