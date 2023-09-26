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
    string date,doctorId,patientId,status;
    AppointmentDetails(string date,string doctorId,string patientId,string status="pending"):
    date(date),doctorId(doctorId),patientId(patientId),status(status){}
};
class Appointment
{
    string date,dId,pId,status;
    public:
    void bookingAppointment(string &userid);
    void scheduleAppointment(string &);
    void viewAppointment(string &userid);
    bool displayRequestedAppointments(string &);
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
void Appointment::bookingAppointment(string &userid)
{
    displayDoctorInfo();
    cout<<"Enter appointment date:";
    date=selectDate();
    cout<<"Enter doctor ID:";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin,dId);
    vector<AppointmentDetails>::iterator itr;
    for(itr=appointmentDetails.begin();itr!=appointmentDetails.end();itr++)
    {
        if(itr->patientId==userid && itr->doctorId==dId)
        {
            cout<<"You have already booked\n";
            return;
        }
    }
    if(is_Valid_Doctor(dId))
    {
        AppointmentDetails details(date,dId,userid);
        appointmentDetails.push_back(details);
        cout<<"Appointment booking is successful!!!\n";
    }
    else
    {
        cout<<"Doctor not found\n";
    }
}
void Appointment::scheduleAppointment(string &userid)
{
    if(displayRequestedAppointments(userid))
    {
        string id;
        cout<<"Enter the patient ID to schedule the appointment:";
        cin>>id;
        vector<AppointmentDetails>::iterator itr;
        for(itr=appointmentDetails.begin();itr!=appointmentDetails.end();itr++)
        {
            if(itr->doctorId==userid && itr->patientId==id)
            {
                itr->status="scheduled";
                storeAppointmentDetails();
                cout<<"Scheduled successfully!!!\n";
                return;
            }
        }
        cout<<"Patient not found\n";
    }
    else
    {
        cout<<"No requested Appointmenrs\n";
        return;
    }
}
void Appointment::viewAppointment(string &userid)
{
    int i=0;
    vector<AppointmentDetails>::iterator itr;
    for(itr=appointmentDetails.begin();itr!=appointmentDetails.end();itr++)
    {
        if(itr->patientId==userid)
        {
            i=1;
            cout<<itr->date<<" "<<itr->doctorId<<" "<<itr->patientId<<" "<<itr->status<<"\n";
        }
    }
    if(i==0)
    {
        cout<<"No Appointments found...Kindly book an Appointment\n";
    }
}
bool Appointment::displayRequestedAppointments(string &userid)
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
        if(itr->doctorId==userid)
        {
            if(itr->status=="pending")
            {
                cout<<itr->date<<" "<<itr->doctorId<<" "<<itr->patientId<<" "<<itr->status<<"\n";
            }
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
            getline(ss,dId,',');
            getline(ss,pId,',');
            getline(ss,status,',');
            AppointmentDetails details(date,dId,pId,status);
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
            appFile<<itr->date<<","<<itr->doctorId<<","<<itr->patientId<<","<<itr->status<<"\n";
        }
        appFile.close();
    }
    else
        cout<<"File opening failed\n";
}
void displayDoctorInfo()
{
    cout<<"Here is the doctor information for your reference:-\n";
    string doctorid,name,specialization;
    file.open("../data/DoctorInfo.csv",ios::in);
    if(file.is_open())
    {
        string line;
        while(getline(file,line))
        {
            stringstream ss(line);
            getline(ss,doctorid,',');
            getline(ss,name,',');
            getline(ss,specialization,',');
            cout<<doctorid<<" - "<<name<<" - "<<specialization<<"\n";
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