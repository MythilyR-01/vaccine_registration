#include<iostream>
#include<ctime>
#include<string>
#include<string.h>
#include<cctype>
using namespace std;

struct date{
	int dd,mm,yy;
};
int check_condition(){
	int age;
	cout<<"Enter your age :";
	cin>>age;
	if(age>=18){
		int inpu;
		cout<<"\nDo you have any medical complications ? \n\t1.Heart patient \n\t2.Pregnant women \n\t3.Asthma \n\t4.Diabetics & BP \n\t5.None of the Above \nEnter your choice :";
		cin>>inpu;
		if(inpu==1 || inpu==2 || inpu==3){
			cout<<"\nOOPS You aren't Eligible for Vaccination!";
			return 0;
		}
		else if(inpu==4){
            cout<<"\nYou can consult the Doctors !";
            return 1;
		}
		return 1;
	}
	else
	{
		cout<<"\nOOPS You are NOT Eligible for Vaccination!";
		return 0;
	}
}


int check_date_condition(int d,int m,int y){
		time_t time1 = time(NULL);
	    tm* timePtr = localtime(&time1);
		int dd,mm,yy;
 		dd= timePtr->tm_mday;
  		mm= timePtr->tm_mon+1;
		yy= timePtr->tm_year+1900;

if(d>yy){
	return 1;
	}
else if(y==yy){
	if(m>mm){
		return 1;
	}
	else if(m==mm){
		if(d>dd)
			return 1;
		else
		return 0;
	}
	else
		return 0;
	}
else
	return 0;
}

date application(){
    int d,m,y,c;
    date d1;
	cin>>d>>m>>y;
	d1.dd=d;
    d1.mm=m;
    d1.yy=y;
	c=check_date_condition(d,m,y);
	if(c==1){
        cout<<"\nYOUR VALID REGISTRATION DATE IS : "<<d<<"/"<<m<<"/"<<y<<endl;
        return d1;
	}
	else{
		cout<<"\nINVALID DATE!!!";
		cout<<"\nPLEASE ENTER A VALID DATE : ";
		application();
	}
}


namespace meenakshi{
	int covishield;
	int covaccine;

void insert_dose(const string &x,string add,long long int ph,string gen,string v_name,int dmore);

class dose
{
	private:
		struct node{
			string element;
			string address;
			long long int contact;
			string gender;
			string blood;
			string vacc_name;
			int daysmore;
			date vacc;

            node *left;
            node *right;
            int height;
            node(const string &ele,node *p,node *n,int h):element(ele),left(p),right(n),height(h)
            { }
		};
		node *root;

	public:
    friend void assignfunc(node *&t);
    void availability(){
        cout<<"\n\t AVAILABILITY OF VACCINE AT MEENAKSHI MISSION"<<endl;
        cout<<"\t---------------------------------"<<endl;
        cout<<"\t  COVISHIELD \t  COVAXINE "<<endl;
        cout<<"\t  "<<covishield<<"  \t\t  "<<covaccine<<endl;
    }
	void print_hospi(){
		cout<<"\n\n\tWELCOME TO MEENAKSHI MISSION HOSPITAL";
		cout<<"\n\t________________________________";
        cout<<"\n\tGANDHI STREET,\n\tCHENNAI - 600001";
        cout<<"\n\tCONTACT : 44554, 44555, 8889944555";
        availability();
	}
	void covishield_update(int x){
        covishield=covishield-x;
    }
    void covaccine_update(int x){
        covaccine=covaccine-x;
    }
     dose(){
            root=NULL;
        }

        int height(node *t)const{
            return (t==NULL)?-1:t->height;
        }
        int default_ini(){
            covishield=115; //initialisation of vaccines
            covaccine=125;  //initailiation of vaccines
        	string n1,n2,add1,add2,gen1,gen2,blood1,blood2,v_name;
        	int ag1,ag2,dmore1,dmore2;
        	long long int ph1,ph2;
        	n1="RAMESH";
        	add1="CHENNAI";
        	ph1=9876543210;
        	gen1="M";
			blood1="A-";
			v_name="COVISHIELD";
			time_t t2 = time(NULL);
	    	tm* t2Ptr = localtime(&t2);
			date d1;
 			d1.dd= t2Ptr->tm_mday;
  			d1.mm= t2Ptr->tm_mon+1;
			d1.yy= t2Ptr->tm_year+1900;
			dmore1=0;
            default_ini(n1,add1,ph1,gen1,blood1,v_name,d1,dmore1,root);//default initialisation1
            n2="RAMYA";
        	add2="CHENGALPATTU";
        	ph2=8765439281;
        	gen2="F";
			blood2="O+";
			v_name="COVAXINE";
			time_t t1 = time(NULL);
	    	tm* t1Ptr = localtime(&t1);
			date d;
 			d.dd= t1Ptr->tm_mday;
  			d.mm= t1Ptr->tm_mon+1;
			d.yy= t1Ptr->tm_year+1900;
			dmore2=0;
            default_ini(n2,add2,ph2,gen2,blood2,v_name,d,dmore2,root);//default initialisation2
            return 0;
        }
         void default_ini(const string &x,string add,long long int ph,string gen,string b,string v_name,date vdate,int dmore,node *&t){
            if(t==NULL){
                t=new node(x,NULL,NULL,-1);
                t->address=add;
                t->contact=ph;
                t->gender=gen;
                t->blood=b;
                t->vacc_name=v_name;
                t->vacc=vdate;
                t->daysmore=dmore;
            }
            else if(x<t->element){
                default_ini(x,add,ph,gen,b,v_name,vdate,dmore,t->left);
                if((height(t->left)-height(t->right))==2)
                {
                    if(x<t->left->element)
                        singlerotatewithleft(t);
                    else
                        doublerotatewithleft(t);
                }
            }
            else if(x>t->element){
                default_ini(x,add,ph,gen,b,v_name,vdate,dmore,t->right);
                if((height(t->left)-height(t->right))==2){
                    if(x>t->right->element)
                        singlerotatewithright(t);
                    else
                        doublerotatewithright(t);
                }
            }
            else  ;

            t->height=max(height(t->left),height(t->right))+1;
        }

         void insert(const string &x){
            insert(x,root);
        }
        void insert(const string &x,node *&t){
            if(t==NULL){
                t=new node(x,NULL,NULL,-1);
                string in;
                cout<<"\nENTER YOUR ADDRESS 	: ";
                cin>>t->address;
                cout<<"\nENTER YOUR PHONE No. 	: ";
                cin>>t->contact;
                cout<<"\nENTER YOUR GENDER(M/F)	:";
                cin>>t->gender;
                cout<<"\nENTER YOUR BLOOD GROUP	:";
                cin>>t->blood;
                int ch;
                cout<<"\nENTER THE CHOICE FOR VACCINE YOU PREFER( 1.COVISHIELD / 2.COVAXINE ) :";
                cin>>ch;
                if(ch==1)
                {
                 t->vacc_name="COVISHIELD";
                 covishield_update(1);
                }
                if(ch==2)
                {
                 t->vacc_name="COVAXINE";
                 covaccine_update(1);
                }
                cout<<"\nEnter the date of vaccination(dd mm yyyy) :";
                t->vacc=application();
                t->daysmore=check_daysmore(t->vacc);
				cout<<"\nYour details are registered!!";
            }
            else if(x<t->element){
                insert(x,t->left);
                if((height(t->left)-height(t->right))==2)
                {
                    if(x<t->left->element)
                        singlerotatewithleft(t);
                    else
                        doublerotatewithleft(t);
                }
            }
            else if(x>t->element){
                insert(x,t->right);
                if((height(t->left)-height(t->right))==2){
                    if(x>t->right->element)
                        singlerotatewithright(t);
                    else
                        doublerotatewithright(t);
                }
            }
            else  ;

            t->height=max(height(t->left),height(t->right))+1;
        }

        void singlerotatewithleft(node *&k2){
            node *k1=k2->left;
            k2->left=k1->right;
            k1->right=k2;
            k2->height=max(height(k2->left),height(k2->right))+1;
            k1->height=max(height(k1->left),k2->height)+1;
            k2=k1;
        }

        void singlerotatewithright(node *&k2){
            node *k1=k2->right;
            k2->right=k1->left;
            k1->left=k2;
            k2->height=max(height(k2->left),height(k2->right))+1;
            k1->height=max(k2->height,height(k1->right))+1;
            k2=k1;
        }

        void doublerotatewithleft(node *&k3){
            singlerotatewithright(k3->left->right);
            singlerotatewithleft(k3);
        }
        void doublerotatewithright(node *&k3){
            singlerotatewithleft(k3->right->left);
            singlerotatewithright(k3);
        }
    void update_vaccine(){
        string x;
        cout<<"\nEnter your name : ";
        cin>>x;
        search_updatevaccine(x,root);
    }
    void search_updatevaccine(string x,node *&t) {
         if(t!=NULL)
        {  if (t->element == x)
            {
                update_vaccine(t);
            }
            search_updatevaccine(x,t->left);
            search_updatevaccine(x,t->right);
        }
    }
    void update_vaccine(node *&t){
        int ch;
        cout<<"\nENTER THE CHOICE FOR VACCINE TO BE CHANGED( 1.COVISHIELD / 2.COVAXINE ) : ";
        cin>>ch;
        if(ch==1)
        {
            if(t->vacc_name=="COVISHIELD"){
                cout<<"\n VACCINE REGISTERED IS SIMILAR TO BEFORE ";
            }
            else{
                covaccine=covaccine+1;
                t->vacc_name="COVISHIELD";
                covishield_update(1);
                cout<<"\nVACCINE NAME UPDATED";
            }
        }
        if(ch==2)
        {
            if(t->vacc_name=="COVAXINE")
                cout<<"\n VACCINE REGISTERED IS SIMILAR TO BEFORE ";
            else{
                 covishield=covishield+1;
                 t->vacc_name="COVAXINE";
                 covaccine_update(1);
                 cout<<"\nVACCINE NAME UPDATED";
            }
        }
    }
    void display_reg(node *&t){
        if(t!=NULL){
        	cout<<endl<<t->element<<"("<<t->daysmore<<" days more)";
            display_reg(t->left);
            display_reg(t->right);
        }
    }

        void display(){
        display_reg(root);
    }
    void print_details(node *&t){
    	cout<<"\n\tADDRESS     : "<<t->address;
        cout<<"\n\tPHONE No.   : "<<t->contact;
        cout<<"\n\tGENDER      : "<<t->gender;
        cout<<"\n\tBLOOD GROUP : "<<t->blood;
        cout<<"\n\tVACCINE NAME: "<<t->vacc_name;
	}
	void search(string x){
        search(x,root);
	}
	void search(string x,node *t) {
         if(t!=NULL)
        {  if (t->element == x)
            {
                print_details(t);
            }
            search(x,t->left);
            search(x,t->right);
        }
    }
    //to update date
    void update(){
        string x;
        cout<<"\nEnter your name : ";
        cin>>x;
        search_update(x,root);
    }
    void search_update(string x,node *&t) {
         if(t!=NULL)
        {  if (t->element == x)
            {
                update(t);
            }
            search_update(x,t->left);
            search_update(x,t->right);
        }
    }
    void update(node *&t){
        int d,m,y,c;
        date da;
        cout<<"\nENTER THE DATE TO BE UPDATED(dd mm yyyy) : ";
        cin>>d>>m>>y;
        c=check_date_condition(d,m,y);
        if(c==1){
            t->vacc.dd=d;
            t->vacc.mm=m;
            t->vacc.yy=y;
            t->daysmore=check_daysmore(t->vacc);
            cout<<"\nTHE UPDATED DATE IS : "<<t->vacc.dd<<"/"<<t->vacc.mm<<"/"<<t->vacc.yy<<endl;
        }
        else{
           cout<<"\nINVALID DATE!!!";
		cout<<"\nPLEASE ENTER A VALID DATE : ";
            update(t);
        }
    }

    int certificate(node *&t){
    cout<<"\n\t\t|-----------------------------------------------------------------------|"<<endl;
	cout<<"\t\t|                  COVID-19 Vaccination 1st Dose                        |"<<endl;
	cout<<"\t\t|                                                                       |"<<endl;
	cout<<"\t\t|                         Benificiary Details                           |"<<endl;
	cout<<"\t\t|Beneficiary Name : "<<t->element<<"                                         "<<endl;
	cout<<"\t\t|Gender           : "<<t->gender<<"                                                   |"<<endl;
	cout<<"\t\t|                                                                       |"<<endl;
	cout<<"\t\t|                         Vaccination Details                           |"<<endl;
	cout<<"\t\t|Vaccine Name     : "<<t->vacc_name<<"                                    "<<endl;
	cout<<"\t\t|Date of dose     : "<<t->vacc.dd<<"\\"<<t->vacc.mm<<"\\"<<t->vacc.yy<<"                                           |"<<endl;
	cout<<"\t\t|Vaccinated at    : MEENAKSHI MISSION, CHENNAI - 600001                 |"<<endl;
	cout<<"\t\t|                                                                       |"<<endl;
	cout<<"\t\t|-----------------------------------------------------------------------|"<<endl;
	return 0;
}
    int check_daysmore(date d){
    	time_t t = time(NULL);
        tm* timePtr = localtime(&t);
        int d1,m1,y1;
        d1= timePtr->tm_mday;
  		m1= timePtr->tm_mon+1;
		y1= timePtr->tm_year+1900;
        int days=0;
        int i,j,k,m,n,o;
        i=d1;
        j=m1;
        k=y1;
        n=d.dd;
        m=d.mm;
        o=d.yy;
        if(o==k){
                for(days=0;i!=n || j!=m;++days){
                    if( i==31&&(m1==1 || m1==3 || m1==5 || m1== 7 || m1== 8|| m1==10||m1==12))
                       {
                          i=0;
                          j++;
                       }
                    else if(m1==2){
                        if(y1%4==0 && y1%100==0 && i==29)
                           {
                               i=0;
                               j++;
                           }
                        else{
                            if(i==28)
                               {
                                   i=0;
                                   j++;
                               }
                        }
                    }
                    else
                        if((m1==4||m1==6||m1==9||m1==11)&&i==30)
                           {
                              i=0;
                              j++;
                           }
                    i++;
                }
        }
        else{
        for(days=0;i!=n || j!=m || k!=o;++days){
                    if( i==31&&(m1==1 || m1==3 || m1==5 || m1== 7 || m1== 8|| m1==10||m1==12))
                       {
                          i=0;
                          j++;
                       }
                    else if(m1==2){
                        if(y1%4==0 && y1%100==0 && i==29)
                           {
                               i=0;
                               j++;
                           }
                        else{
                            if(i==28)
                               {
                                   i=0;
                                   j++;
                               }
                        }
                    }
                    else if(j==12){
                        j=1;
                        k++;
                    }
                    else{
                        if((m1==4||m1==6||m1==9||m1==11)&&i==30)
                           {
                              i=0;
                              j++;
                           }
                    }
                    i++;
                }
        }
        return days;
	}


node* findMin(node *t)const{
		if(t==NULL)
			return NULL;
		else if(t->left==NULL)
			return t;
		else
			return findMin(t->left);
    }
string search(node *t, int x) {
         if(t!=NULL)
        {  if (t->daysmore == x)
            {
                return t->element;
            }
            search(t->left,x);
            search(t->right,x);

        }
        return "";
}

void remove(){
    string n;
    n=search(root,0);
    //if(strcmp(n,0)!=0)
    remove(n,root);
}

void  replace(node *&t,node *k){
	t->element=k->element;
	t->address=k->address;
    t->contact=k->contact;
	t->gender=k->gender;
    t->blood=k->blood;
    t->vacc_name=k->vacc_name;
    t->vacc=k->vacc;
    t->daysmore=k->daysmore;
}

void remove(const string &x,node *&t){
	if(t==NULL)
		return;
	if(x<t->element)
		remove(x,t->left);
	else if(x>t->element)
		remove(x,t->right);
	else if(t->left!=NULL && t->right!=NULL){
		if(t->daysmore==0){
			certificate(t);
			assignfunc(t);
		}
		replace(t,findMin(t->right));
		//t->element=findMin(t->right)->element;
		remove(t->element,t->right);
	}
	else{
		node *old=t;
		if(t->daysmore==0){
		certificate(t);
		assignfunc(t);
		}
		t=(t->left==NULL)?t->right:t->left;
		delete old;
	}
	balance(t);
}
void balance(node *&t){
	if(t==NULL)
		return;
	if((height(t->left)-height(t->right))==2){
		if(height(t->left->left)>=height(t->left->right))
			singlerotatewithleft(t);
		else
			doublerotatewithleft(t);
	}else{
		if((height(t->right)-height(t->left))==2){
			if(height(t->right->right)>=height(t->right->left))
				singlerotatewithright(t);
			else
				doublerotatewithright(t);
		}
	}
	t->height=max(height(t->left),height(t->right))+1;
}
void assignfunc(node *&t)
{
    string name,vname;
    string add;
    long long int contact;
    string gender;
    int daysmore=80;
    name=t->element;
    add=t->address;
    contact=t->contact;
    gender=t->gender;
    vname=t->vacc_name;
    insert_dose(name,add,contact,gender,vname,daysmore);
}

};
class vacc_dose
{
	private:
		struct node_vacc{
			string name;
			string address;
			long long int contact;
			string gender;
			string blood;
			string vacc_name;
			int daysmore;
			date vacc;

            node_vacc *left;
            node_vacc *right;
            int height2;
            node_vacc(const string &ele,node_vacc *p,node_vacc *n,int h):name(ele),left(p),right(n),height2(h)
            { }
		};
		node_vacc *root;
	public:
	    friend void insert_dose(const string &x,string add,long long int ph,string gen,string v_name,int dmore);
        vacc_dose(){
            root=NULL;
        }
        int max(int a,int b){
            return (a>=b)?a:b;
        }
        int height(node_vacc *t)const{
            return (t==NULL)?-1:t->height2;
        }
        int default_ini(){
        	string n1,n2,add1,add2,gen1,gen2,blood1,blood2,v_name;
        	int ag1,ag2,dmore1,dmore2;
        	long long int ph1,ph2;
        	n1="RAJESH";
        	add1="CHENNAI";
        	ph1=9532543210;
        	gen1="M";
			v_name="COVISHIELD";
			dmore1=20;
            default_ini(n1,add1,ph1,gen1,v_name,dmore1,root);//default initialisation1
            n2="NISHA";
        	add2="GUINDY";
        	ph2=7645439281;
        	gen2="F";
			v_name="COVAXINE";
			dmore2=2;
            default_ini(n2,add2,ph2,gen2,v_name,dmore2,root);//default initialisation2
            return 0;
        }
         void default_ini(const string &x,string add,long long int ph,string gen,string v_name,int dmore,node_vacc *&t){
            if(t==NULL){
                t=new node_vacc(x,NULL,NULL,-1);
                t->address=add;
                t->contact=ph;
                t->gender=gen;
                t->vacc_name=v_name;
                t->daysmore=dmore;
            }
            else if(x<t->name){
                default_ini(x,add,ph,gen,v_name,dmore,t->left);
                if((height(t->left)-height(t->right))==2)
                {
                    if(x<t->left->name)
                        singlerotatewithleft(t);
                    else
                        doublerotatewithleft(t);
                }
            }
            else if(x>t->name){
                default_ini(x,add,ph,gen,v_name,dmore,t->right);
                if((height(t->left)-height(t->right))==2){
                    if(x>t->right->name)
                        singlerotatewithright(t);
                    else
                        doublerotatewithright(t);
                }
            }
            else  ;

            t->height2=max(height(t->left),height(t->right))+1;
        }
         void insert2(const string &x,string add,long long int ph,string gen,string v_name,int dmore){
            insert2(x,add,ph,gen,v_name,dmore,root);
        }
        void insert2(const string &x,string add,long long int ph,string gen,string v_name,int dmore,node_vacc *&t){
            if(t==NULL){
                t=new node_vacc(x,NULL,NULL,-1);
                t->address=add;
                t->contact=ph;
                t->gender=gen;
                t->vacc_name=v_name;
                t->daysmore=dmore;
				cout<<"\nWaiting for 2nd dose!!"; //only  for us remove on submitting.
            }
            else if(x<t->name){
                insert2(x,add,ph,gen,v_name,dmore,t->left);
                if((height(t->left)-height(t->right))==2)
                {
                    if(x<t->left->name)
                        singlerotatewithleft(t);
                    else
                        doublerotatewithleft(t);
                }
            }
            else if(x>t->name){
                insert2(x,add,ph,gen,v_name,dmore,t->right);
                if((height(t->left)-height(t->right))==2){
                    if(x>t->right->name)
                        singlerotatewithright(t);
                    else
                        doublerotatewithright(t);
                }
            }
            else  ;

            t->height2=max(height(t->left),height(t->right))+1;
        }

        void singlerotatewithleft(node_vacc *&k2){
            node_vacc *k1=k2->left;
            k2->left=k1->right;
            k1->right=k2;
            k2->height2=max(height(k2->left),height(k2->right))+1;
            k1->height2=max(height(k1->left),k2->height2)+1;
            k2=k1;
        }

        void singlerotatewithright(node_vacc *&k2){
            node_vacc *k1=k2->right;
            k2->right=k1->left;
            k1->left=k2;
            k2->height2=max(height(k2->left),height(k2->right))+1;
            k1->height2=max(k2->height2,height(k1->right))+1;
            k2=k1;
        }

        void doublerotatewithleft(node_vacc *&k3){
            singlerotatewithright(k3->left->right);
            singlerotatewithleft(k3);
        }
        void doublerotatewithright(node_vacc *&k3){
            singlerotatewithleft(k3->right->left);
            singlerotatewithright(k3);
        }
		void print(node_vacc *&t){
        	cout<<"\n\tADDRESS     : "<<t->address;
       		cout<<"\n\tPHONE No.   : "<<t->contact;
       		cout<<"\n\tGENDER      : "<<t->gender;
        	cout<<"\n\tVACCINE NAME: "<<t->vacc_name;
        	cout<<endl<<"\t"<<t->daysmore<<" days more for next dose."<<endl;
        	cout<<"\n\t_______________________________";
        	//cout<<"\n\tBLOOD GROUP : "<<t->blood;
   		}
        void display(node_vacc *&t){
            if(t!=NULL)
            {
            	cout<<"\n\n\t\tNAME :"<<t->name<<endl;
                print(t);
                display(t->left);
                display(t->right);
           }
        }
        void display(){
            display(root);
        }
};
vacc_dose v1;
void default_ini(){
    v1.default_ini();
}
void insert_dose(const string &x,string add,long long int ph,string gen,string v_name,int dmore){
    v1.insert2(x,add,ph,gen,v_name,dmore);
}
void dose2_disp(){
    v1.display();
}
}



//end of hospital 1*********************************************************************************
namespace rajaji{
	int covishield;
	int covaccine;
	void insert_dose2(const string &x,string add,long long int ph,string gen,string v_name,int dmore);
class dose
{
	private:
		struct node{
			string element;
			string address;
			long long int contact;
			string gender;
			string blood;
			string vacc_name;
			int daysmore;
			date vacc;

            node *left;
            node *right;
            int height;
            node(const string &ele,node *p,node *n,int h):element(ele),left(p),right(n),height(h)
            { }
		};
		node *root;

	public:
    friend void assignfunc(node *&t);
    void availability(){
        cout<<"\n\t\t AVAILABILITY OF VACCINE AT RAJAJI"<<endl;
        cout<<"\t\t---------------------------------"<<endl;
        cout<<"\t\t  COVISHIELD \t  COVAXINE "<<endl;
        cout<<"\t\t  "<<covishield<<"  \t\t  "<<covaccine<<endl;
    }
	void print_hospi(){
		cout<<"\n\n\tWELCOME TO RAJAJI HOSPITAL";
		cout<<"\n\t________________________________";
        cout<<"\n\tLITTLE MOUNT SOUTH,\n\tCHENNAI - 600002";
        cout<<"\n\tCONTACT : 4428292791, 9998899988";
        availability();
	}
	void covishield_update(int x){
        covishield=covishield-x;
    }
    void covaccine_update(int x){
        covaccine=covaccine-x;
    }
     dose(){
            root=NULL;
        }

        int height(node *t)const{
            return (t==NULL)?-1:t->height;
        }
        int default_ini(){
            covishield=80;
            covaccine=75;
        	string n1,n2,add1,add2,gen1,gen2,blood1,blood2,v_name;
        	int ag1,ag2,dmore1,dmore2;
        	long long int ph1,ph2;
        	n1="RAJU";
        	add1="ERODE";
        	ph1=9865432101;
        	ag1=22;
        	gen1="M";
			blood1="O+";
			v_name="COVISHIELD";
			time_t t2 = time(NULL);
	    	tm* t2Ptr = localtime(&t2);
			date d1;
 			d1.dd= t2Ptr->tm_mday;
  			d1.mm= t2Ptr->tm_mon+1;
			d1.yy= t2Ptr->tm_year+1900;
			dmore1=0;
            default_ini(n1,add1,ph1,ag1,gen1,blood1,v_name,d1,dmore1,root);//default initialisation1
            n2="SRI";
        	add2="MADURAI";
        	ph2=9993218502;
        	ag2=29;
        	gen2="F";
			blood2="A+";
			v_name="COVAXINE";
			time_t t1 = time(NULL);
	    	tm* t1Ptr = localtime(&t1);
			date d;
 			d.dd= t1Ptr->tm_mday;
  			d.mm= t1Ptr->tm_mon+1;
			d.yy= t1Ptr->tm_year+1900;
			dmore2=0;
            default_ini(n2,add2,ph2,ag2,gen2,blood2,v_name,d,dmore2,root);//default initialisation2
            return 0;
        }
         void default_ini(const string &x,string add,long long int ph,int a,string gen,string b,string v_name,date vdate,int dmore,node *&t){
            if(t==NULL){
                t=new node(x,NULL,NULL,-1);
                t->address=add;
                t->contact=ph;
                t->gender=gen;
                t->blood=b;
                t->vacc_name=v_name;
                t->vacc=vdate;
                t->daysmore=dmore;
            }
            else if(x<t->element){
                default_ini(x,add,ph,a,gen,b,v_name,vdate,dmore,t->left);
                if((height(t->left)-height(t->right))==2)
                {
                    if(x<t->left->element)
                        singlerotatewithleft(t);
                    else
                        doublerotatewithleft(t);
                }
            }
            else if(x>t->element){
                default_ini(x,add,ph,a,gen,b,v_name,vdate,dmore,t->right);
                if((height(t->left)-height(t->right))==2){
                    if(x>t->right->element)
                        singlerotatewithright(t);
                    else
                        doublerotatewithright(t);
                }
            }
            else  ;

            t->height=max(height(t->left),height(t->right))+1;
        }

         void insert(const string &x){
            insert(x,root);
        }
        void insert(const string &x,node *&t){
            if(t==NULL){
                t=new node(x,NULL,NULL,-1);
                string in;
                cout<<"\nENTER YOUR ADDRESS 	: ";
                cin>>t->address;
                cout<<"\nENTER YOUR PHONE No. 	: ";
                cin>>t->contact;
                cout<<"\nENTER YOUR GENDER(M/F)	:";
                cin>>t->gender;
                cout<<"\nENTER YOUR BLOOD GROUP	:";
                cin>>t->blood;
                int ch;
                cout<<"\nENTER THE CHOICE FOR VACCINE YOU PREFER( 1.COVISHIELD / 2.COVAXINE ) :";
                cin>>ch;
                if(ch==1)
                {
                 t->vacc_name="COVISHIELD";
                 covishield_update(1);
                }
                if(ch==2)
                {
                 t->vacc_name="COVAXINE";
                 covaccine_update(1);
                }
                cout<<"\nEnter the date of vaccination(dd mm yyyy) :";
                t->vacc=application();
                t->daysmore=check_daysmore(t->vacc);
				cout<<"\nYour details are registered!!";
            }
            else if(x<t->element){
                insert(x,t->left);
                if((height(t->left)-height(t->right))==2)
                {
                    if(x<t->left->element)
                        singlerotatewithleft(t);
                    else
                        doublerotatewithleft(t);
                }
            }
            else if(x>t->element){
                insert(x,t->right);
                if((height(t->left)-height(t->right))==2){
                    if(x>t->right->element)
                        singlerotatewithright(t);
                    else
                        doublerotatewithright(t);
                }
            }
            else  ;

            t->height=max(height(t->left),height(t->right))+1;
        }

        void singlerotatewithleft(node *&k2){
            node *k1=k2->left;
            k2->left=k1->right;
            k1->right=k2;
            k2->height=max(height(k2->left),height(k2->right))+1;
            k1->height=max(height(k1->left),k2->height)+1;
            k2=k1;
        }

        void singlerotatewithright(node *&k2){
            node *k1=k2->right;
            k2->right=k1->left;
            k1->left=k2;
            k2->height=max(height(k2->left),height(k2->right))+1;
            k1->height=max(k2->height,height(k1->right))+1;
            k2=k1;
        }

        void doublerotatewithleft(node *&k3){
            singlerotatewithright(k3->left->right);
            singlerotatewithleft(k3);
        }
        void doublerotatewithright(node *&k3){
            singlerotatewithleft(k3->right->left);
            singlerotatewithright(k3);
        }

        void display(){
        display_reg(root);
    }
    void print_details(node *&t){
    	cout<<"\n\tADDRESS     : "<<t->address;
        cout<<"\n\tPHONE No.   : "<<t->contact;
        cout<<"\n\tGENDER      : "<<t->gender;
        cout<<"\n\tBLOOD GROUP : "<<t->blood;
        cout<<"\n\tVACCINE NAME: "<<t->vacc_name;
	}
	void search(string x){
        search(x,root);
	}
	void search(string x,node *t) {
         if(t!=NULL)
        {  if (t->element == x)
            {
                print_details(t);
            }
            search(x,t->left);
            search(x,t->right);
        }
    }
    void display_reg(node *&t){
        if(t!=NULL){
        	cout<<endl<<t->element<<"("<<t->daysmore<<" days more)";
            display_reg(t->left);
            display_reg(t->right);
        }
    }


int certificate(node *&t){
    cout<<"\n\t\t|-----------------------------------------------------------------------|"<<endl;
	cout<<"\t\t|                  COVID-19 Vaccination 1st Dose                        |"<<endl;
	cout<<"\t\t|                                                                       |"<<endl;
	cout<<"\t\t|                         Benificiary Details                           |"<<endl;
	cout<<"\t\t|Beneficiary Name : "<<t->element<<"                                         "<<endl;
	cout<<"\t\t|Gender           : "<<t->gender<<"                                                   |"<<endl;
	cout<<"\t\t|                                                                       |"<<endl;
	cout<<"\t\t|                         Vaccination Details                           |"<<endl;
	cout<<"\t\t|Vaccine Name     : "<<t->vacc_name<<"                                    "<<endl;
	cout<<"\t\t|Date of dose     : "<<t->vacc.dd<<"\\"<<t->vacc.mm<<"\\"<<t->vacc.yy<<"                                           |"<<endl;
	cout<<"\t\t|Vaccinated at    : Rajaji Hospital, Chennai - 600002                   |"<<endl;
	cout<<"\t\t|                                                                       |"<<endl;
	cout<<"\t\t|-----------------------------------------------------------------------|"<<endl;
	return 0;
}
    int check_daysmore(date d){
    	time_t t = time(NULL);
        tm* timePtr = localtime(&t);
        int d1,m1,y1;
        d1= timePtr->tm_mday;
  		m1= timePtr->tm_mon+1;
		y1= timePtr->tm_year+1900;
        int days=0;
        int i,j,k,m,n,o;
        i=d1;
        j=m1;
        k=y1;
        n=d.dd;
        m=d.mm;
        o=d.yy;
        if(o==k){
                for(days=0;i!=n || j!=m;++days){
                    if( i==31&&(m1==1 || m1==3 || m1==5 || m1== 7 || m1== 8|| m1==10||m1==12))
                       {
                          i=0;
                          j++;
                       }
                    else if(m1==2){
                        if(y1%4==0 && y1%100==0 && i==29)
                           {
                               i=0;
                               j++;
                           }
                        else{
                            if(i==28)
                               {
                                   i=0;
                                   j++;
                               }
                        }
                    }
                    else
                        if((m1==4||m1==6||m1==9||m1==11)&&i==30)
                           {
                              i=0;
                              j++;
                           }
                    i++;
                }
        }
        else{
        for(days=0;i!=n || j!=m || k!=o;++days){
                    if( i==31&&(m1==1 || m1==3 || m1==5 || m1== 7 || m1== 8|| m1==10||m1==12))
                       {
                          i=0;
                          j++;
                       }
                    else if(m1==2){
                        if(y1%4==0 && y1%100==0 && i==29)
                           {
                               i=0;
                               j++;
                           }
                        else{
                            if(i==28)
                               {
                                   i=0;
                                   j++;
                               }
                        }
                    }
                    else if(j==12){
                        j=1;
                        k++;
                    }
                    else{
                        if((m1==4||m1==6||m1==9||m1==11)&&i==30)
                           {
                              i=0;
                              j++;
                           }
                    }
                    i++;
                }
        }
        return days;
	}


node* findMin(node *t)const{
		if(t==NULL)
			return NULL;
		else if(t->left==NULL)
			return t;
		else
			return findMin(t->left);
    }

string search(node *t, int x) {
         if(t!=NULL)
        {  if (t->daysmore == x)
            {
                return t->element;
            }
            search(t->left,x);
            search(t->right,x);

        }
        return "";
}

void remove(){
    string n;
    n=search(root,0);
    //if(strcmp(n,0)!=0)
    remove(n,root);
}

void remove(const string &x,node *&t){
	if(t==NULL)
		return;
	if(x<t->element)
		remove(x,t->left);
	else if(x>t->element)
		remove(x,t->right);
	else if(t->left!=NULL && t->right!=NULL){
		t->element=findMin(t->right)->element;
		remove(t->element,t->right);
	}
	else{
		node *old=t;
		certificate(old);
		assignfunc(old);
		t=(t->left==NULL)?t->right:t->left;
		delete old;
	}
	balance(t);
}
void balance(node *&t){
	if(t==NULL)
		return;
	if((height(t->left)-height(t->right))==2){
		if(height(t->left->left)>=height(t->left->right))
			singlerotatewithleft(t);
		else
			doublerotatewithleft(t);
	}else{
		if((height(t->right)-height(t->left))==2){
			if(height(t->right->right)>=height(t->right->left))
				singlerotatewithright(t);
			else
				doublerotatewithright(t);
		}
	}
	t->height=max(height(t->left),height(t->right))+1;
}
void update_vaccine(){
        string x;
        cout<<"\nEnter your name : ";
        cin>>x;
        search_updatevaccine(x,root);
    }
    void search_updatevaccine(string x,node *&t) {
         if(t!=NULL)
        {  if (t->element == x)
            {
                update_vaccine(t);
            }
            search_updatevaccine(x,t->left);
            search_updatevaccine(x,t->right);
        }
    }
    void update_vaccine(node *&t){
        int ch;
        cout<<"\nENTER THE CHOICE FOR VACCINE TO BE CHANGED( 1.COVISHIELD / 2.COVAXINE ) : ";
        cin>>ch;
        if(ch==1)
        {
                 t->vacc_name="COVISHIELD";
                 covishield_update(1);
        }
        if(ch==2)
        {
                 t->vacc_name="COVAXINE";
                 covaccine_update(1);
        }
    }
 void update(){
        string x;
        cout<<"\nEnter your name : ";
        cin>>x;
        search_update(x,root);
    }
void search_update(string x,node *&t) {
         if(t!=NULL)
        {  if (t->element == x)
            {
                update(t);
            }
            search_update(x,t->left);
            search_update(x,t->right);
        }
    }
void update(node *&t){
        int d,m,y,c;
        date da;
        cout<<"\nENTER THE DATE TO BE UPDATED(dd mm yyyy) : ";
        cin>>d>>m>>y;
        c=check_date_condition(d,m,y);
        if(c==1){
            t->vacc.dd=d;
            t->vacc.mm=m;
            t->vacc.yy=y;
            t->daysmore=check_daysmore(t->vacc);
            cout<<"\nTHE UPDATED DATE IS : "<<t->vacc.dd<<"/"<<t->vacc.mm<<"/"<<t->vacc.yy<<endl;
        }
        else{
            cout<<"\nINVALID DATE!!!";
		cout<<"\nPLEASE ENTER A VALID DATE : ";
            update(t);
        }
    }
void assignfunc(node *&t)
{
    string name,vname;
    string add;
    long long int contact;
    string gender;
    int daysmore=80;
    name=t->element;
    add=t->address;
    contact=t->contact;
    gender=t->gender;
    vname=t->vacc_name;
    insert_dose2(name,add,contact,gender,vname,daysmore);
}

};

class vacc_dose
{
	private:
		struct node_vacc{
			string name;
			string address;
			long long int contact;
			string gender;
			string blood;
			string vacc_name;
			int daysmore;
			date vacc;

            node_vacc *left;
            node_vacc *right;
            int height2;
            node_vacc(const string &ele,node_vacc *p,node_vacc *n,int h):name(ele),left(p),right(n),height2(h)
            { }
		};
		node_vacc *root;
	public:
	    friend void insert_dose2(const string &x,string add,long long int ph,string gen,string v_name,int dmore);
        vacc_dose(){
            root=NULL;
        }
        int max(int a,int b){
            return (a>=b)?a:b;
        }
        int height(node_vacc *t)const{
            return (t==NULL)?-1:t->height2;
        }
        int default_ini(){
        	string n1,n2,add1,add2,gen1,gen2,blood1,blood2,v_name;
        	int dmore1,dmore2;
        	long long int ph1,ph2;
        	n1="SARAN";
        	add1="CHENNAI";
        	ph1=9532523410;
        	gen1="M";
			v_name="COVAXINE";
			dmore1=5;
            default_ini(n1,add1,ph1,gen1,v_name,dmore1,root);//default initialisation1
            n2="THARAN";
        	add2="CHENNAI";
        	ph2=8975439281;
        	gen2="M";
			v_name="COVISHIELD";
			dmore2=10;
            default_ini(n2,add2,ph2,gen2,v_name,dmore2,root);//default initialisation2
            return 0;
        }
         void default_ini(const string &x,string add,long long int ph,string gen,string v_name,int dmore,node_vacc *&t){
            if(t==NULL){
                t=new node_vacc(x,NULL,NULL,-1);
                t->address=add;
                t->contact=ph;
                t->gender=gen;
                t->vacc_name=v_name;
                t->daysmore=dmore;
            }
            else if(x<t->name){
                default_ini(x,add,ph,gen,v_name,dmore,t->left);
                if((height(t->left)-height(t->right))==2)
                {
                    if(x<t->left->name)
                        singlerotatewithleft(t);
                    else
                        doublerotatewithleft(t);
                }
            }
            else if(x>t->name){
                default_ini(x,add,ph,gen,v_name,dmore,t->right);
                if((height(t->left)-height(t->right))==2){
                    if(x>t->right->name)
                        singlerotatewithright(t);
                    else
                        doublerotatewithright(t);
                }
            }
            else  ;

            t->height2=max(height(t->left),height(t->right))+1;
        }
         void insert2(const string &x,string add,long long int ph,string gen,string v_name,int dmore){
            insert2(x,add,ph,gen,v_name,dmore,root);
        }
        void insert2(const string &x,string add,long long int ph,string gen,string v_name,int dmore,node_vacc *&t){
            if(t==NULL){
                t=new node_vacc(x,NULL,NULL,-1);
                t->address=add;
                t->contact=ph;
                t->gender=gen;
                t->vacc_name=v_name;
                t->daysmore=dmore;
            }
            else if(x<t->name){
                insert2(x,add,ph,gen,v_name,dmore,t->left);
                if((height(t->left)-height(t->right))==2)
                {
                    if(x<t->left->name){
                        singlerotatewithleft(t);
                    }
                    else{
                        doublerotatewithleft(t);
                    }
                }
            }
            else if(x>t->name){
                insert2(x,add,ph,gen,v_name,dmore,t->right);
                if((height(t->left)-height(t->right))==2){
                    if(x>t->right->name){
                        singlerotatewithright(t);
                    }
                    else
                        doublerotatewithright(t);
                }
            }
            else  ;
            t->height2=max(height(t->left),height(t->right))+1;
        }

        void singlerotatewithleft(node_vacc *&k2){
            node_vacc *k1=k2->left;
            k2->left=k1->right;
            k1->right=k2;
            k2->height2=max(height(k2->left),height(k2->right))+1;
            k1->height2=max(height(k1->left),k2->height2)+1;
            k2=k1;
        }

        void singlerotatewithright(node_vacc *&k2){
            node_vacc *k1=k2->right;
            k2->right=k1->left;
            k1->left=k2;
            k2->height2=max(height(k2->left),height(k2->right))+1;
            k1->height2=max(k2->height2,height(k1->right))+1;
            k2=k1;
        }

        void doublerotatewithleft(node_vacc *&k3){
            singlerotatewithright(k3->left->right);
            singlerotatewithleft(k3);
        }
        void doublerotatewithright(node_vacc *&k3){
            singlerotatewithleft(k3->right->left);
            singlerotatewithright(k3);
        }
		void print(node_vacc *&t){
        	cout<<"\n\tADDRESS     : "<<t->address;
       		cout<<"\n\tPHONE No.   : "<<t->contact;
       		cout<<"\n\tGENDER      : "<<t->gender;
        	cout<<"\n\tVACCINE NAME: "<<t->vacc_name;
        	cout<<endl<<"\t"<<t->daysmore<<" days more for next dose."<<endl;
        	cout<<"\n\t_______________________________";
        	//cout<<"\n\tBLOOD GROUP : "<<t->blood;
   		}
        void display(node_vacc *&t){
            if(t!=NULL)
            {
            	cout<<"\n\n\t\tNAME :"<<t->name<<endl;
                print(t);
                display(t->left);
                display(t->right);
           }
        }
        void display(){
            display(root);
        }
};
vacc_dose v2;
void default_ini(){
    v2.default_ini();
}
void insert_dose2(const string &x,string add,long long int ph,string gen,string v_name,int dmore){
    v2.insert2(x,add,ph,gen,v_name,dmore);
}
void dose2_disp(){
    v2.display();
}
}


int main(){

    cout<<endl<<endl;
    cout<<"                 WELCOME TO VACCINATION REGISTRATION                        "<<endl<<endl;
    cout<<" ************************************************************************** ";
	cout<<"\n --------------------------------------------------------------------------"<<endl;
	cout<<"|                                                                          |"<<endl;
	cout<<"|                         INSTRUCTIONS                                     |"<<endl;
	cout<<"|	1. Only people with age 18 and above will be vaccinated.           |"<<endl;
	cout<<"|	2. You should not have any medical complication.                   |"<<endl;
	cout<<"|	3. Do enter valid date                                             |"<<endl;
	cout<<"|	4. You can choose your preferable hospital and vaccine             |"<<endl;
	cout<<"|	5. Enter valid details                                             |"<<endl;
	cout<<"|	6. You will get your certificate once vaccinated with first dose   |"<<endl;
	cout<<"|       7. You should be vaccinated with next dose within 80 days          |"<<endl;
	cout<<"|                                                                          |"<<endl;
	cout<<"|                                                                          |"<<endl;
	cout<<"|                        STAY HOME STAY SAFE                               |"<<endl;
	cout<<"|__________________________________________________________________________|"<<endl;
	cout<<"  ";

    meenakshi::dose h1;
    rajaji::dose h2;
    	string n;
    	int ch,choice;
    	char yn='Y';
    	int x;
    	meenakshi::default_ini();
    	rajaji::default_ini();
    	h1.default_ini();
    	h2.default_ini();
    	do{
    		cout<<"\n\n\t\t\tCHOOSE YOUR HOSPITAL: \n\t\t\t 1.MEENAKSHI MISSION \n\t\t\t 2.RAJAJI HOSPITALS "<<endl;
    		cin>>ch;
    	if(ch==1){
    		h1.print_hospi();
    		do{
    		cout<<"\n\n\t 1.VACCINE AVALABILITIES \n\t 2.REGISTER \n\t 3.UPDATION OF VACCINE\n\t 4.DISPLAY DOSE 1 PERSONS \n\t 5.SEARCH \n\t 6.REMOVE \n\t 7.DISPLAY DOSE 2 PERSONS \n\t 8.UPDATION OF DOSE1 DATE \n\t 9.EXIT"<<endl;
    		cout<<"ENTER YOUR CHOICE : ";
    		cin>>x;
    		switch(x){
    		case 1:
    			h1.availability();
    			break;
    		case 2:
    		    int s;
    		    s=check_condition();
    		    if(s==1){
                    cout<<"\nENTER YOUR NAME : ";
                    cin>>n;
                    h1.insert(n);
    		    }
    			break;
            case 3:h1.update_vaccine();
                break;
    		case 4:
    			h1.display();
				break;
			case 5:
				cout<<"\nENTER THE PERSON'S NAME : ";
    			cin>>n;
    			h1.search(n);
				break;
			case 6:
				h1.remove();
				break;
            case 7:
                meenakshi::dose2_disp();
                break;
			case 8:
                h1.update();
                break;
            case 9:
				choice=1;
				break;
			default:
				cout<<"\nIT'S AN INVALID CASE!!";
				break;
			}

			}while (choice==0);

		}
		if(ch==2){
				h2.print_hospi();
				int choice1=0;
    		do{
    		cout<<"\n\n\t 1.VACCINE AVALABILITIES \n\t 2.REGISTER \n\t 3.UPDATION OF VACCINE\n\t 4.DISPLAY DOSE 1 PERSONS \n\t 5.SEARCH \n\t 6.REMOVE \n\t 7.DISPLAY DOSE 2 PERSONS \n\t 8.UPDATION OF DOSE1 DATE \n\t 9.EXIT"<<endl;
    		cout<<"ENTER YOUR CHOICE : ";
    		cin>>x;
    		switch(x){
    		case 1:
    			h2.availability();
    			break;
    		case 2:
    		    int s;
    		    s=check_condition();
    		    if(s==1){
                    cout<<"\nENTER YOUR NAME : ";
                    cin>>n;
                    h2.insert(n);
    		    }
    			break;
            case 3:h2.update_vaccine();
                break;
    		case 4:
    			h2.display();
				break;
			case 5:
				cout<<"\nENTER THE PERSON'S NAME : ";
    			cin>>n;
    			h2.search(n);
				break;
			case 6:
				h2.remove();
				break;
			case 7:
                rajaji::dose2_disp();
                break;
			case 8:
                h2.update();
                break;
            case 9:
				choice1=1;
				break;
			default:
				cout<<"\nIT'S AN INVALID CASE!!";
				break;
			}
			}while(choice1==0);
		}
    	cout<<"\n\nDo you need to continue?(Y/N) :";
    	cin>>yn;
		}while(yn=='Y'||yn=='y');

    return 0;
}
