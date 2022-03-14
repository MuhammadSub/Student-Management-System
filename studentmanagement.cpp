#include <iostream>
#include <string>
using namespace std;
//structure to store details
struct Student
{
  int rollnumber;
  string name;
  string phone;
  float percentage;
  struct Student *next;
  
}* head;
//function to add details 
void insert(int rollnumber, string name, string phone, float percentage)
{
  //creating a struct instance, new is used to allocate memory
  struct Student * student = new Student;
  //assigning varibles
  student->rollnumber = rollnumber;
  student->name=name;
  student->phone= phone;
  student->percentage = percentage;
  student->next = NULL;
  if(head==NULL){
    // if head is NULL
    // set student as the new head
    head = student;
  }
  else{
    // if list is not empty
    // insert student in beginning of head
    student->next = head;
    head = student;
  }
}
//function to serach details of a student
void search(int rollnumber)
{
  //using temp structure variable
  struct Student * temp = head;
  //searching for roolno details
  while(temp!=NULL)
  {
    //rollnumber found condition
    if(temp->rollnumber==rollnumber)
    {
      //here cout is used to print details
      cout<<"Roll Number: "<<temp->rollnumber<<endl;
      cout<<"Name: "<<temp->name<<endl;
      cout<<"Phone: "<<temp->phone<<endl;
      cout<<"Percentage: "<<temp->percentage<<endl;
      return;
      }
    temp = temp->next;
    }
  //details not found condition
  cout<<"Student with roll number "<<rollnumber<<" is not found !!!"<<endl;
}
//function to update details
void update(int rollnumber)
{
    
  struct Student * temp = head;
  while(temp!=NULL)
  {
    //checking for roolnumber in the list
    if(temp->rollnumber==rollnumber)
    {
      //cin is used to get input and cout is to print output
      cout<<"Record with roll number "<<rollnumber<<" Found !!!"<<endl;
      cout<<"Enter new name: ";
      cin>>temp->name;
      cout<<"Enter new phone number: ";
      cin>>temp->phone;
      cout<<"Enter new percentage: ";
      cin>>temp->percentage;
      cout<<"Updation Successful!!!"<<endl;
      return;
    }
    temp = temp->next;
  }
  //roolnumber not found condition
  cout<<"Student with roll number "<<rollnumber<< "is not found !!!"<<endl;
    
}
//function to delete details
void Delete(int rollnumber)
{
  //taking two temp variable of structre
  struct Student * temp1 = head;
  struct Student * temp2 = head;
  //finding roolnumber
  while(temp1!=NULL){
  if(temp1->rollnumber==rollnumber){  
    cout<<"Record with roll number "<<rollnumber<<" Found !!!"<<endl;
    if(temp1==temp2){
      // this condition will run if
      // the record that we need to delete is the first node
      // of the linked list
      head = head->next;
      delete temp1;
    }
  else{
    // temp1 is the node we need to delete
    // temp2 is the node previous to temp1
    temp2->next = temp1->next;
    delete temp1;
  }
  cout<<"Record Successfully Deleted !!!\n";
  return;    
  }
  temp2 = temp1;
  temp1 = temp1->next;
  }
  //not found case
  cout<<"Student with roll number "<<rollnumber<<" is not found !!!\n";
}
//function to display details
void display()
{
  struct Student * temp = head;
  //loop to print every student details
  while(temp!=NULL){
    //printing to output screen
    cout<<"Roll Number: "<<temp->rollnumber<<endl;
    cout<<"Name: "<<temp->name<<endl;
    cout<<"Phone: "<<temp->phone<<endl;
    cout<<"Percentage: "<<temp->percentage<<endl;
    temp = temp->next;
  }
}
//main function
int main()
{
  head = NULL;
  int choice;
  //decalring variables as string type
  string name;
  string phone;
  int rollnumber;
  float percentage;
  //ptinitng output 
  cout<<"1 to insert student details\n2 to search for student details\n3 to delete student details\n4 to update student details\n5 to display all student details";
  do
  {
    //getting inut from user 
    cout<<"\nEnter Choice: ";
    cin>>choice;
    switch (choice)
    {
      //case 1 is to add details
      case 1:
        cout<<"Enter roll number: ";
        cin>>rollnumber;
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter phone number: ";
        cin>>phone;
        cout<<"Enter percentage: ";
        cin>>percentage;
        insert(rollnumber, name, phone, percentage);
        break;
      //when choice ==2 then this case
      case 2:
        cout<<"Enter roll number to search: ";
        cin>>rollnumber;
        search(rollnumber);
        break;
      //if choice == 3
      case 3:
        cout<<"Enter roll number to delete: ";
        cin>>rollnumber;
        Delete(rollnumber);
        break;
      //if choice ==4
      case 4:
        cout<<"Enter roll number to update: ";
        cin>>rollnumber;
        update(rollnumber);
        break; 
      //if choice==5 
      case 5:
        display();
        break;
      //wrong case
      default :
        cout<<"Wrong Choice";
    }
  } while (choice != 0);
}
