#include <iostream>

using namespace std;

//Linked List Start
struct log{
       string LOG;
       log* down;

};
struct log_handler{
       int Account_Number;
       log_handler* next;
       log* down;
};
struct log_handler *head  = NULL;


void insertion_for_log(int account_number) //Inserion in Linked List
{
  struct log_handler *newnode = new log_handler;
  log_handler *temp=NULL;
  log_handler *temp2 = NULL;
  if(head == NULL){
     newnode -> Account_Number = account_number;
     newnode -> next = NULL;
     newnode -> down = NULL;
     head = newnode;}
  else{for(temp2 = head; temp2-> next != NULL ; temp2 = temp2 -> next){}
     temp =new log_handler;
     temp -> Account_Number = account_number;
     temp2 -> next = temp;
     temp ->  next = NULL;
     temp -> down = NULL;}
}

void insert_log(int number,string nn) //Insert Logs 
{
  {
  struct log_handler *temp2 = new log_handler;
  struct log *temp =new log;
  struct log *newnode =new log;
  newnode -> LOG  = nn;
  newnode -> down=NULL;
  for(temp2 = head ; temp2 != NULL; temp2 = temp2 -> next){
     if(temp2 -> Account_Number == number){
      if(temp2->down == NULL){
         temp2 -> down  = newnode;
         newnode -> down = NULL;}
       else{
         temp = temp2 -> down;
         temp2 -> down  = newnode;
         newnode -> down = temp;}}}
}
}

int  display(int acc_num)    //Display Function 
{                                
   struct log_handler *temp=new log_handler;
   struct log *temp2 = new log;
   if(head == NULL){return 0;}
   else{
      for(temp = head; temp != NULL; temp = temp -> next){
       if(temp-> Account_Number == acc_num){
        for(temp2 = temp->down; temp2 != NULL; temp2 = temp2-> down)
        {
      	cout<<"                                 -> " <<  temp2-> LOG <<endl;
		}
		break;
	return 1;

}}
}}
int  display1(int acc_num)    //Display Function 
{                                
   struct log_handler *temp=new log_handler;
   struct log *temp2 = new log;
   if(head == NULL){return 0;}
   else{
      for(temp = head; temp != NULL; temp = temp -> next){
       if(temp-> Account_Number == acc_num){
        for(temp2 = temp->down; temp2 != NULL; temp2 = temp2-> down)
        {
      	 temp2-> LOG;
		}

	return 1;

}}
}}
#include <iostream>

#include<iomanip>
using namespace std;


//AVL code Start
struct node{
  //Data Entry
  string Name;
  string CNIC;
  char Gender;
  string Type;
  int Acc_Number;
  int pin;
  int bala;
  //Node
  node *right, *left;
  int height;
};
node *temp, *temp1, *temp2, *tempcell = NULL;
/////////////////////////////////////////////////////////////////////////////////////////Main Functions used in AVL
// Max Function
int max(int a, int b){
  if(a > b){return a;}
  else{return b;}
}
// Height Function
int height(struct node* temp){
  if(temp == NULL){return 0;}
  int lh = height(temp->left);
  int rh = height(temp->right);
  if(lh > rh){return lh+1;}
  else{return rh+1;}
}
// Left Rotation Function
struct node *left_rotation(struct node* temp2) {
  temp1 = temp2->right;
  temp2->right = temp1->left;
  temp1->left = temp2;

  temp2->height = max(height(temp2->left), height(temp2->right)) + 1;
  temp1->height = max(height(temp1->left), height(temp1->right)) + 1;
  return temp1;
}
// Right Rotation Function
struct node *right_rotation(struct node* temp2){
  temp1 = temp2->left;
  temp2->left = temp1->right;
  temp1->right = temp2;

  temp2->height = max(height(temp2->left), height(temp2->right)) +1;
  temp1->height = max(height(temp1->left), height(temp1->right)) +1;

  return temp1;
}
// right left rotation
struct node *right_left_rotation(struct node* temp3)   {
  temp3->right = right_rotation(temp3->right);
  return left_rotation(temp3);
}
// Left right rotation
struct node *left_right_rotation(node *temp3)     {
  temp3->left = left_rotation(temp3->left);
  return right_rotation(temp3);
}
//Minimum Function{
struct node *min(struct node* temp){
  if(temp == NULL){return 0;}
  if(temp->left == NULL){return temp;}
  else{min(temp->left);}
}
// balance function
struct node *balance(struct node* temp)  {
 if(temp == NULL){cout<<"No rotation is found "<<endl;}
 if( height(temp->left)-height(temp->right) > 1){
 if(height(temp->left->left) >= height(temp->left->right)){temp =right_rotation(temp);}
 else{temp =left_right_rotation(temp);}}
 else if( height(temp->right)-height(temp->left) > 1){if(height(temp->right->right) >= height(temp->right->left))
 {
  temp =left_rotation(temp);
 }
 else
 {
  temp =right_left_rotation(temp);
 }
 }
  temp->height = max(height(temp->left), height(temp->right)) + 1;
  return temp;
}
/////////////////////////////////////////////////////////////////////////////////////////END of main Functions in AVL


struct node *insertion(struct node* temp,string name,string cnc,char gen,string type,int account_no,int PIN,int bal){    ///////////////////////// insertion
 if(temp == NULL){
  temp = new node();
  temp->Name          = name;
  temp->CNIC          = cnc;
  temp->Gender        = gen;
  temp->Type          = type;
  temp->Acc_Number    = account_no;
  temp->pin           = PIN;
  temp->bala          = bal;
  temp->left          = NULL;
  temp->right         = NULL;
  temp->height        = 0;}

if(account_no < temp->Acc_Number){
     temp->left = insertion(temp->left, name, cnc,gen,type, account_no,PIN,bal);
  if(height(temp->left) - height(temp->right) == 2){
     if(account_no < temp->left->Acc_Number){temp = right_rotation(temp);}
     else{temp = left_right_rotation(temp);}}}

if(account_no > temp->Acc_Number){
    temp->right = insertion(temp->right, name, cnc,gen,type, account_no,PIN,bal);
  if(height(temp->right) - height(temp->left) == 2){
    if(account_no > temp->right->Acc_Number){temp = left_rotation(temp);}
    else{temp = right_left_rotation(temp);}}}

 temp->height = max(height(temp->left), height(temp->right)) +1 ;
 return temp;
}


struct node *deletion(struct node* temp, int x) ///////////////////////// deletion
{
 if(temp == NULL){
		return temp;}
 else if(x < temp->Acc_Number){
		temp->left = deletion(temp->left, x);}
 else if(x > temp->Acc_Number){
		temp->right = deletion(temp->right, x);}
 else if(temp->left && temp->right){
		tempcell = min(temp->right);
		temp->Acc_Number = tempcell->Acc_Number;
		temp->right = deletion(temp->right, temp->Acc_Number);}
 else{
		tempcell = temp;
 if(temp->left == NULL){
		temp = temp->right;}
 else if(temp->right == NULL){
		temp = temp->left;}
		delete tempcell;}
 if(temp != NULL){
		temp = balance(temp);}

 return temp;

}

int findMax(struct node* root)  ///////////////////////// find max
{
 if (root == NULL){return 0;}
 int res = root->Acc_Number;
 int lres = findMax(root->left);
 int rres = findMax(root->right);
 if (lres > res){res = lres;}
 if (rres > res)
      res = rres;
    return res;
}

bool search(struct node* temp, int x)  ///////////////////////// search
{
  while (temp != NULL)
    {

        if (x> temp->Acc_Number)
            temp = temp->right;


        else if (x < temp->Acc_Number)
           temp = temp->left;
        else
            return true;
    }
    return false;

}


int print_data(struct node* temp, int x) ///////////////////////// Print Function
{
 while (temp != NULL)
    {
    // pass right subtree as new tree
    if (x> temp->Acc_Number)
        temp = temp->right;

    // pass left subtree as new tree
    else if (x < temp->Acc_Number)
        temp = temp->left;
    else{
        cout<<"        ####################################################################################################################################"<<endl;
        cout<<" "<<endl;
        cout<<"          "<<"ACC_Number"<<"                 "<<"NAME"<<"                   "<<"CNIC"<<"                     "<<"GENDER"<<"            "<<"Type"<<"          "<<"Balance"<<endl;
        cout<<" "<<endl;
        cout<<"        ####################################################################################################################################"<<endl;
        cout<<" "<<endl;
        cout<<"             ";
        cout<<temp->Acc_Number;
        cout<<"            ";
        cout<<setw(18)<<temp->Name;
        cout<<"           ";
        cout<<temp->CNIC;
        cout<<"                ";
        cout<<temp->Gender;
        cout<<"                ";
        cout<<temp->Type;
        cout<<"             ";
        cout<<temp->bala<<endl;
        return true;
        }
    }
    return false;


}

void pre_order(struct node* temp)   ///////////////////////// pre order function
{
//cout << temp->pin<<endl;
if(temp->left != NULL){pre_order(temp->left);}
 //cout<<"          "<< setw(2)<<temp->Acc_Number;
 cout<<"             ";
 cout<<temp->Acc_Number;
 cout<<"            ";
 cout<<setw(18)<<temp->Name;
 cout<<"           ";
 cout<<temp->CNIC;
 cout<<"                ";
 cout<<temp->Gender;
 cout<<"                ";
 cout<<temp->Type;
 cout<<"             ";
 cout<<temp->bala<<endl;
 if(temp->right != NULL){pre_order(temp->right);}

}

void print_for_admin(struct node* temp)   ////////////////////////// print For order function
{
 if(temp->left != NULL){print_for_admin(temp->left);}
 cout<<"             ";
 cout<<temp->Acc_Number;
 cout<<"            ";
 cout<<setw(18)<<temp->Name;
 cout<<"           ";
 cout<<temp->CNIC;
 cout<<"                ";
 cout<<temp->Gender;
 cout<<"                ";
 cout<<temp->Type;
 cout<<"         ";
 cout<<temp->pin;
 cout<<"          ";
 cout<<temp->bala<<endl;
 if(temp->right != NULL){print_for_admin(temp->right);}

}



int deposit(struct node* temp,int acc_num,int PIN,int bal)   ///////////////////////// deposit Balance
{

 while (temp != NULL){
  if (acc_num> temp->Acc_Number){temp = temp->right;}
  else if (acc_num < temp->Acc_Number){temp = temp->left;}
  else{
    if(temp->pin == PIN){temp->bala= temp->bala +bal;}
    else if(temp->pin != PIN){return -1;}
       return 1;}}
  return 0;

}

int with_draw(struct node* temp,int acc_num,int PIN,int bal)   /////////////////////////  with_draw balance
{
 while (temp != NULL){
  if (acc_num> temp->Acc_Number){temp = temp->right;}
  else if (acc_num < temp->Acc_Number){temp = temp->left;}
  else{
    if(temp->pin == PIN){
        if((temp->bala < bal)){	return -1;	}
        else {temp->bala = temp->bala - bal;}}
	else if(temp->pin != PIN){return -2	;}
        return 1;}}
  return 0;

}


int change_info(struct node* temp,string name,string cnic,char gender,string type,int acc_num,int PIN)   ///////////////////////// Change Info
{

 while (temp != NULL){
  if (acc_num> temp->Acc_Number){temp = temp->right;}
  else if (acc_num < temp->Acc_Number){temp = temp->left;}
  else{
    if(temp->Acc_Number == acc_num){
           temp->Name = name;
           temp->CNIC = cnic;
           temp->Gender = gender;
           temp->pin = PIN;
           temp->Type = type;}

       return 1;}}
  return 0;

}

int check_acc_pin(struct node* temp,int acc_num,int PIN)   ///////////////////////// check acc & PIn number
{
 while (temp != NULL){
  if (acc_num> temp->Acc_Number){temp = temp->right;}
  else if (acc_num < temp->Acc_Number){temp = temp->left;}
  else{
    if(temp->pin == PIN){return 1;}
    else if(temp->pin != PIN){return -1;}}}

  return 0;

}
#include <iostream>

#include <sstream>
#include <time.h>
#include <string>

using namespace std;

int main();
struct node *root = NULL;
int sleep_value =130;
int admin_pswd= 1122;
int staff_pswd= 2233;

int create_Acc()
{
  //Declared Variables
  string full_name;
  string cnic;
  string Acc_type;
  char g;
  int acc_no;
  int pin;
  long long Balance;
  int load=0;
  int a=1;
  //END Declared Variables
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";
  cout<<""<<endl;
  cout<<"                                                 Create User Account"<<endl;
  cout<<" "<<endl;
  cout<<"                                            Enter Customer's Full Name : ";cin.ignore();getline(cin,full_name);
  cout<<" "<<endl;
  cout<<"                                            Enter CNIC (xxxxx-xxxxxxx-x) : ";getline(cin,cnic);
  cout<<" "<<endl;
  cout<<"                                            Enter Gender  (M/F) : ";cin>>g;
  cout<<" "<<endl;
  cout<<"                                            Enter Account Type (C/S) : ";cin.ignore();cin>>Acc_type;
  cout<<" "<<endl;
  load=findMax(root);
  acc_no = load + 1;
  cout<<"                                            Your Account Number is : "<<acc_no<<endl;
  cout<<" "<<endl;
  cout<<"                                            Enter Pin : " ;cin.ignore();cin>>pin;
  cout<<" "<<endl;
  jump2:
  cout<<"                                            Enter Balance (Min:500) : ";cin.ignore();cin>> Balance;
  if(Balance >= 500){goto jump3;}
  else{cout<<"                                            Minimum Balance is 500Rs. "<<endl;goto jump2;}

  jump3:
      root = insertion(root,full_name,cnic,g,Acc_type,acc_no,pin,Balance); //insertion(root)
      insertion_for_log(acc_no);
  return 1;
}


int admin_panel()
{
  //Declared Variables
  int b;
  int admin_delete_cin;
  int admin_search_cin;
  int result_admin_1;
  int result_admin_2;
  int result_admin_3;
  int result_admin_4;
  int admin_return;

  int acc_1;
  int pin_1;
  string cnc_1;
  char gen_1;
  string acc_type_1;
  string new_cnc_1;
  int new_pin_1;
  string new_acc_1;
  int admin_logs_cin;
  //END Declared Variables

  /////////////JUMP_2
  jump2:
  system("Color B");
  system("cls");
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";
  cout<<"                                                       ***************************************"<<endl;
  cout<<"                                                       *************ADMIN|||PANEL*************"<<endl;
  cout<<"                                                       ***************************************"<<endl;
  cout<<"                                                       *  Press 1 To Create Account          *"<<endl;
  cout<<"                                                       *  Press 2 To Delete Account          *"<<endl;
  cout<<"                                                       *  Press 3 To Search Account          *"<<endl;
  cout<<"                                                       *  Press 4 To Show List of All Acc    *"<<endl;
  cout<<"                                                       *  Press 5 To Edit Information        *"<<endl;
  cout<<"                                                       *  Press 6 To Show Logs of Deleted Acc*"<<endl;
  cout<<"                                                       *  Press 7 To Go Back to Main Menu    *"<<endl;
  cout<<"                                                       ***************************************"<<endl;
  cout<<"                                                       Enter an Option : ";
  cin>>b;
  if(b == 1){
            lol_admin_1:
            system("cls");
            create_Acc();
            lol_admin_2:
            cout<<" "<<endl;
            cout<<" "<<endl;
            cout<<"                                         Press 1 to create another account or Press 7 to return to ADMIN PANEL ...!!! ";
            cin>>admin_return;
            if(admin_return == 7){goto jump2;}
            else if(admin_return == 1){goto lol_admin_1;}
            else{goto lol_admin_2;}}
  else if(b == 2){
  	 		lol_admin_3:
                system("cls");
                cout<<"                                         Enter the Account Number to Delete :";
                cin>>admin_delete_cin;
                result_admin_1 = search(root,admin_delete_cin);
			    cout<<result_admin_1<<endl;
	        if(result_admin_1 == 1){
			    cout<<"                                         Account number Found....!!!"<<endl;
			    cout<<" " <<endl;
			    deletion(root,admin_delete_cin);
			    cout<<" " <<endl;
			    cout<<"                                         Account is Deleted....!!!"<<endl;}
			else{
			    cout<<" " <<endl;
			    cout<<"                                         Account not found ....!!!"<<endl;
				cout<<" "<<endl;}
	        lol_admin_4:
                cout<<" "<<endl;
                cout<<" "<<endl;
                cout<<"                                         Press 2 to Delete another account or Press 7 to return to ADMIN PANEL ...!!! ";
                cin>>admin_return;
                if(admin_return==7){goto jump2;}
                else if(admin_return==2){goto lol_admin_3;}
                else{cout<<"                                         Invalid Output !! "<<endl;goto lol_admin_4; }}

  else if(b == 3){
            lol_admin_5:
  			  system("cls");
              cout<<"                                         Enter the Account Number to Search : ";
			  cin>>admin_search_cin;
              result_admin_2 = search(root,admin_search_cin);
              if(result_admin_2 == 1){
				cout<<" "<<endl;
				cout<<"                                         User Found..!!"<<endl;
				cout<<" "<<endl;
				print_data(root,admin_search_cin);
	      	    cout<<" "<<endl;}
	      	  else if(result_admin_2 == 0){
				     cout<<" "<<endl;
					 cout<<" "<<endl;
					 cout<<"                                         User not found..!! :("<<endl;
				     cout<<" "<<endl;
				     cout<<" "<<endl;}
		        cout<<" "<<endl;
			lol_admin_6:
                cout<<" "<<endl;
             	cout<<" "<<endl;
                cout<<"                                         Press 3 to Search another account or Press 7 to return to ADMIN PANEL ...!!! ";
                cin>>admin_return;
                if(admin_return==7){goto jump2;}
                else if(admin_return == 3){goto lol_admin_5;}
                else{cout<<"                                         Invalid Output !!"<<endl;goto lol_admin_6; }}

  else if(b == 4){
    	    lol_admin_7:
  	            system("cls");
                cout<<"        ####################################################################################################################################"<<endl;
    		    cout<<" "<<endl;
    			cout<<"          "<<"ACC_Number"<<"                 "<<"NAME"<<"                   "<<"CNIC"<<"                     "<<"GENDER"<<"            "<<"Type"<<"          "<<"PIN"<<"          "<<"BALANCE"<<endl;
    			cout<<" "<<endl;
    			cout<<"        ####################################################################################################################################"<<endl;
    			cout<<" "<<endl;
				print_for_admin(root);
            lol_admin_8:
                cout<<" "<<endl;
                cout<<" "<<endl;
                cout<<"                                         Press 4 to Show list of accounts or Press 7 to return to ADMIN PANEL ...!!! ";
                cin>>admin_return;
                if(admin_return==7){goto jump2;}
                else if(admin_return == 4){goto lol_admin_7;}
                else{cout<<"                                         Invalid Output !!"<<endl;goto lol_admin_8;}}
  else if(b == 5){
    	    lol_admin_9:
  	            system("cls");
  	            cout<<"                                            Change Informaion of Account "<<endl;
  	            cout<<"                                            Enter User_Account Number : ";
  	            cin>>acc_1;
  	            cout<<"                                            Enter User_Account PIN number : ";
  	            cin>>pin_1;
  	            result_admin_3 = check_acc_pin(root,acc_1,pin_1);
  	            if(result_admin_3 == 1){
  	            	cout<<"                                            Change Informaion of Account "<<endl;
  	            	cout<<"\n"<<endl;
  	            	cout<<"                                            Enter New Name / previous Name : ";
  	            	cin>>new_acc_1;
  	            	getline(cin, new_acc_1);
  	            	cout<<"                                            Enter New Cnic / Previous Cnic : ";
  	            	getline(cin, new_cnc_1);
  	            	cout<<"                                            Enter Gender : ";
  	            	cin>>gen_1;
  	            	cout<<"                                            Enter Account Type C/S : ";
  	            	cin>> acc_type_1;
  	            	cout<<"                                            Enter New PIN / Previous PIN : ";
  	            	cin>> new_pin_1;
  	            	change_info(root,new_acc_1,new_cnc_1,gen_1,acc_type_1,acc_1,new_pin_1);
  	            	cout<<"                                            Account information is Sucessfully Changed"<<endl;
				  }
				else if(result_admin_3 == -1){cout<<"                                            PIN is Incorrect...!!!"<<endl;}
				else if(result_admin_3 == 0){cout<<"                                            Account is not Present...!!!"<<endl;}
				else{cout<<"                                            Account is not Present...!!!"<<endl;}
			lol_admin_10:
                cout<<" "<<endl;
                cout<<" "<<endl;
                cout<<"                                         Press 5 to Change other Account info or Press 7 to return to ADMIN PANEL ...!!! ";
                cin>>admin_return;
                if(admin_return==7){goto jump2;}
                else if(admin_return == 5){goto lol_admin_9;}
                else{cout<<"                                         Invalid Output !!"<<endl;goto lol_admin_10;}}
  else if(b == 6){
  	        lol_admin_11:
                system("cls");
  	            cout<<"                                         Enter Account Number: ";
  	            cin>>admin_logs_cin;
                result_admin_4 = display1(admin_logs_cin);
                print_data(root,admin_logs_cin);
                if(result_admin_4 == 1){
                	cout<<""<<endl;
                	cout<<""<<endl;
                	display(admin_logs_cin);
				    }
                else{cout<<""<<endl;
                	cout<<""<<endl;
                	display(admin_logs_cin);}
			lol_admin_12:
				cout<<"                                         Press 6 to Check Logs of  another account or Press 7 to return to ADMIN PANEL...!!! ";
                cin>>admin_return;
                if(admin_return==6){goto lol_admin_11;}
                else if(admin_return==7){goto jump2;}
                else{cout<<"                                         Invalid Output !!"<<endl;goto lol_admin_12;}
                }
  else if(b == 7){main();}
            else{
                system("cls");
	            goto jump2;}
}

int staff_panel(){
   //Variable Used
   int staff_acc_no;
   int staff_pin_no;
   int staff_amount_to_dep;
   int staff_acc_no_1;
   int staff_pin_no_1;
   int staff_amount_to_wdraw_1;
   int account_logs_cin;
   int c;
   int staff_return;
   int lol_staff_1;
   int lol_staff_2;
   int account_info_cin;
   int result_staff_1;
   int result_staff_2;
   int result_staff_3;
   int result_staff_4;
   //End Variable Declaration

   ////////////JUMP_3:
  jump3:
  system("Color B");
  system("cls");
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";
  cout<<"                                                       ***************************************"<<endl;
  cout<<"                                                       *************STAFF|||PANEL*************"<<endl;
  cout<<"                                                       ***************************************"<<endl;
  cout<<"                                                       *  Press 1 To Check Account Info      *"<<endl;
  cout<<"                                                       *  Press 2 To Deposit Cash            *"<<endl;
  cout<<"                                                       *  Press 3 To With_Draw Cash          *"<<endl;
  cout<<"                                                       *  Press 4 To Check Logs of User      *"<<endl;
  cout<<"                                                       *  Press 5 To Go Back to Main Menu    *"<<endl;
  cout<<"                                                       ***************************************"<<endl;
  cout<<"                                                       Enter an Option : ";
  cin>>c;
  if(c == 1){
  	    lol_staff_1:
  	        system("cls");
            cout<<"                                         Enter the Account Number to Check info : ";
			cin>>account_info_cin;
            result_staff_1= search(root,account_info_cin);
			if(result_staff_1 == 1){cout<<" "<<endl;
             	cout<<"                                         User Found..!!"<<endl;
				cout<<" "<<endl;
				print_data(root,account_info_cin);
				cout<<" "<<endl;}
            else if(result_staff_1 == 0){cout<<"                                         User not found..!! :("<<endl;
				cout<<" "<<endl;
				cout<<" "<<endl;}

				cout<<" "<<endl;
			lol_staff_2:
				cout<<"                                         Press 1 to search again or Press 5 to return to STAFF PANEL..!! ";
				cin>>staff_return;
				if(staff_return  == 1){goto lol_staff_1;}
				else if(staff_return == 5){ goto jump3;}
				else{cout<<"                                         Invalid Output !!"<<endl;goto lol_staff_2;}
				}
  else if(c == 2){
  	  		lol_staff_3:
  				system("cls");
  	            cout<<"                                         Enter Account : ";
  	            cin>>staff_acc_no;
  	            cout<<"                                         Enter Account PIN : ";
  	            cin>>staff_pin_no;
  	            cout<<"                                         Enter The Amount Deposit : ";
  	            cin>>staff_amount_to_dep;
  	            cout<<" "<<endl;
  	            cout<<"                                                   Status ""BEFORE"" Deposit Amount in ACCOUNT"<<endl;
  	            cout<<" "<<endl;
    			print_data(root,staff_acc_no);
    			cout<<" "<<endl;
    			cout<<" "<<endl;
    			result_staff_2 = deposit(root,staff_acc_no,staff_pin_no,staff_amount_to_dep);
    			if(result_staff_2 == 1){
    		    		cout<<"                                                   Status ""AFTER"" Deposit Amount in ACCOUNT"<<endl;
  	            		cout<<" "<<endl;
    					print_data(root,staff_acc_no);
    					cout<<" "<<endl;
    					cout<<" "<<endl;
    			time_t now = time(0);
                char* dt = ctime(&now);
                ostringstream str1;
                str1 << staff_amount_to_dep;
                        string add = "Amount " + str1.str();
                        string add1 = add + " has been deposited  at " + dt;

						cout<<"                                         Amount "<<staff_amount_to_dep<<" has been Deposited in Account Number  "<<staff_acc_no<<endl; insert_log(staff_acc_no,add1);}
    			else if(result_staff_2 == 0){cout<<"                                                     Account not Found....Amount is not Deposit in your Account...!"<<endl;}
				else if(result_staff_2 == -1){cout<<"                                                     PIN is Incorrect"<<endl;}
    			cout<<" "<<endl;
    			cout<<" "<<endl;
			lol_staff_4:
				cout<<"                                         Press 4 to Deposit amount in another account : 5 to return to STAFF PANEL...!!! ";
                cin>>staff_return;
                if(staff_return==4){goto lol_staff_3;}
                else if(staff_return==5){goto jump3;}
                else{cout<<"                                         Invalid Output !!"<<endl;goto lol_staff_4;}}
  else if(c == 3){cout<<"with draw cash"<<endl;
            lol_staff_5:
  				system("cls");
  	            cout<<"                                         Enter Account Number : ";
  	            cin>>staff_acc_no_1;
  	            cout<<"                                         Enter Account PIN : ";
  	            cin>>staff_pin_no_1;
  	            cout<<"                                         Enter The Amount WithDraw : ";
  	            cin>>staff_amount_to_wdraw_1;
  	            cout<<" "<<endl;
  	            cout<<"                                                   Status ""BEFORE"" WITHDRAW Amount from ACCOUNT"<<endl;
  	            cout<<" "<<endl;
    			print_data(root,staff_acc_no_1);
    			cout<<" "<<endl;
    			cout<<" "<<endl;
    			result_staff_3 = with_draw(root,staff_acc_no_1,staff_pin_no_1,staff_amount_to_wdraw_1);
    			if(result_staff_3 == 1){
    		    		cout<<"                                                   Status ""AFTER"" WITHDRAW Amount from ACCOUNT"<<endl;
  	            		cout<<" "<<endl;
    					print_data(root,staff_acc_no_1);
    					cout<<" "<<endl;
    					cout<<" "<<endl;
    				time_t now = time(0);
                	char* dt = ctime(&now);
                	ostringstream str1;
                	str1 << staff_amount_to_dep;
                        string add2 = "Amount " + str1.str();
                        string add3 = add2 + " has been Withdrawn  at " + dt;
						cout<<"                                         Amount "<<staff_amount_to_wdraw_1<<" has been Withdraw in Account Number  "<<staff_acc_no_1<<endl;insert_log(staff_acc_no_1,add3);}
    			else if(result_staff_3 == 0){cout<<"                                                     Account not Found....Amount is not With Drawn from User Account...!"<<endl;}
				else if(result_staff_3 == -1){cout<<"                                                     Account Balance is Insufficient "<<endl;}
				else if(result_staff_3 == -2){cout<<"                                                     PIN is InCorrect..!! "<<endl;}
    			cout<<" "<<endl;
    			cout<<" "<<endl;
			lol_staff_6:
				cout<<"                                         Press 3 to With Draw from another account : 5 to return to STAFF PANEL...!!! ";
                cin>>staff_return;
                if(staff_return==3){goto lol_staff_5;}
                else if(staff_return==5){goto jump3;}
                else{cout<<"                                         Invalid Output !!"<<endl;goto lol_staff_6;}}
  else if(c == 4){
            lol_staff_7:
  				system("cls");
  	            cout<<"                                         Enter Account Number: ";
  	            cin>>account_logs_cin;
                result_staff_4 = display1(account_logs_cin);
                print_data(root,account_logs_cin);
                if(result_staff_4 == 1){
                	cout<<""<<endl;
                	cout<<""<<endl;
                	display(account_logs_cin);
				    }
                else{cout<<"                                         Logs Not Found....!!!"<<endl;}
			lol_staff_8:
				cout<<"                                         Press 4 to Check Logs of  another account : 5 to return to STAFF PANEL...!!! ";
                cin>>staff_return;
                if(staff_return==4){goto lol_staff_7;}
                else if(staff_return==5){goto jump3;}
                else{cout<<"                                         Invalid Output !!"<<endl;goto lol_staff_8;}
			}
  else if(c == 5){
      system("cls");main();}
  else{goto jump3;}
}

int atm_panel()
{
  // declare variable
  int d;
  int atm_acc_no_1;
  int atm_pin_no_1;
  int atm_amount_to_wdraw_1;
  int result_atm_3;
  int atm_return;
  //End Variable Declaration

  ////////////JUMP_4
  jump4:
  system("Color B");
  system("cls");
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";
  cout<<"                                                       ***************************************"<<endl;
  cout<<"                                                       *******************ATM*****************"<<endl;
  cout<<"                                                       ***************************************"<<endl;
  cout<<"                                                       *  Press 1 To Deposit Cash            *"<<endl;
  cout<<"                                                       *  Press 2 To Go Back to Main Menu    *"<<endl;
  cout<<"                                                       ***************************************"<<endl;
  cout<<"                                                       Enter an Option : ";
  cin>>d;
  if(d == 1){
  			lol_atm_1:
  				system("cls");
  	            cout<<"                                         Enter Account Number : ";
  	            cin>>atm_acc_no_1;
  	            cout<<"                                         Enter Account PIN : ";
  	            cin>>atm_pin_no_1;
  	            cout<<"                                         Enter The Amount WithDraw : ";
  	            cin>>atm_amount_to_wdraw_1;
  	            cout<<" "<<endl;
  	            cout<<"                                                   Status ""BEFORE"" WITHDRAW Amount from ACCOUNT"<<endl;
  	            cout<<" "<<endl;
    			print_data(root,atm_acc_no_1);
    			cout<<" "<<endl;
    			cout<<" "<<endl;
    			result_atm_3 = with_draw(root,atm_acc_no_1,atm_pin_no_1,atm_amount_to_wdraw_1);
    			if(result_atm_3 == 1){
    		    		cout<<"                                                   Status ""AFTER"" WITHDRAW Amount from ACCOUNT"<<endl;
  	            		cout<<" "<<endl;
    					print_data(root,atm_acc_no_1);
    					cout<<" "<<endl;
    					cout<<" "<<endl;
    				time_t now = time(0);
                	char* dt = ctime(&now);
                	ostringstream str1;
                	str1 << atm_amount_to_wdraw_1;
                        string add2 = "Amount " + str1.str();
                        string add3 = add2 + " has been Withdrawn  at " + dt;
						cout<<"                                         Amount "<<atm_amount_to_wdraw_1<<" has been Withdraw in Account Number  "<<atm_acc_no_1<<endl;insert_log(atm_acc_no_1,add3);}
    			else if(result_atm_3 == 0){cout<<"                                                     Account not Found....Amount is not With Drawn from User Account...!"<<endl;}
				else if(result_atm_3 == -1){cout<<"                                                     Account Balance is Insufficient "<<endl;}
				else if(result_atm_3 == -2){cout<<"                                                     PIN is InCorrect..!! "<<endl;}
    			cout<<" "<<endl;
    			cout<<" "<<endl;
			lol_staff_6:
				cout<<"                                         Press 3 to With Draw from another account : 5 to return to ATM PANEL...!!! ";
                cin>> atm_return;
                if(atm_return==3){goto lol_atm_1;}
                else if(atm_return==5){goto jump4;}
                else{cout<<"                                         Invalid Output !!"<<endl;goto lol_atm_1;}}

  else if(d == 2){
      system("cls");main();}
  else{goto jump4;}
}


int main()
{
  //Declare RECORD
    root = insertion(root,"somendra meena ","12345-6789101-1",'M',"C",32001,1234,500);
    insertion_for_log(32001);
    
  int a;
  int b;
  system("MODE 150, 40");
  //End Variable Declaration
  /////////////JUMP_1
  jump1:
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";


  system("Color B");
  system("cls");
  cout<<"\n";
  cout<<"                   ____              _      __  __                                                   _      _____           _                  "<<endl;
  cout<<"                  |  _ \            | |    |  \/  |                                                 | |    / ____|         | |                 "<<endl;
  cout<<"                  | |_) | __ _ _ __ | | __ | \  / | __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_  | (___  _   _ ___| |_ ___ _ __ ___   "<<endl;
  cout<<"                  |  _ < / _` | '_ \| |/ / | |\/| |/ _` | '_ \ / _` |/ _` |/ _ \ '_ ` _ \ / _ \ '_ \| __|  \___ \| | | / __| __/ _ \ '_ ` _ \  "<<endl;
  cout<<"                  | |_) | (_| | | | |   <  | |  | | (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_   ____) | |_| \__ \ ||  __/ | | | | | "<<endl;
  cout<<"                  |____/ \__,_|_| |_|_|\_\ |_|  |_|\__,_|_| |_|\__,_|\__, |\___|_| |_| |_|\___|_| |_|\__| |_____/ \__, |___/\__\___|_| |_| |_| "<<endl;
  cout<<"                                                                      __/ |                                        __/ |                       "<<endl;
  cout<<"                                                                     |___/                                        |___/                        "<<endl;
  cout<<"                                                                                                                                               "<<endl;
  cout<<"                                                            Made by somendra meena                                                           "<<endl;
  cout<<"\n"<<endl;
  cout<<"                                                       ********************************"<<endl;
  cout<<"                                                       **********LOGIN||PANEL**********"<<endl;
  cout<<"                                                       ********************************"<<endl;
  cout<<"                                                       *  Press 1 For ADMIN Login     *"<<endl;
  cout<<"                                                       *  Press 2 For STAFF Login     *"<<endl;
  cout<<"                                                       *  Press 3 For ATM Service     *"<<endl;
  cout<<"                                                       *  Press 4 To  Exit            *"<<endl;
  cout<<"                                                       ********************************"<<endl;
  cout<<"                                                       ********************************"<<endl;
  cout<<"\n"<<endl;
  cout<<"                                                       Enter Your Choice : ";
  cin>>a;
  if(a == 1){
        jump2:
        system("Color B");
        system("cls");
        cout<<"\n";
        cout<<"\n";
        cout<<"\n";
        cout<<"\n";
        cout<<"                                                       Enter Pin : ";
        cin >>b;
        if(b == admin_pswd){admin_panel();}
        else{goto jump2;}}
  else if(a == 2){
        jump3:
        system("Color B");
        system("cls");
        cout<<"\n";
        cout<<"\n";
        cout<<"\n";
        cout<<"\n";
        cout<<"                                                       Enter Pin : ";
        cin >>b;
        if(b == staff_pswd){staff_panel();}
        else{goto jump3;}}
  else if(a == 3){atm_panel();}
  else if(a == 4){exit(0);}
  else {goto jump1;}


}