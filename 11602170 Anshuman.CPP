#include<bits/stdc++.h>
using namespace std;
class APPLICANT
{
    char   sex,  fathr_name[20], addrs[20], e_mail[20], branch[20],name[20],dob[20];
   long int rno;
    float cgpa,cgpa1;
    void disp();
public:
    void reg();
    void write();
    void read();

    void del();
    void mod();
    void eligibility();
}c;
void APPLICANT::reg()
{
    cout<<"\nEnter name of APPLICANT:";
	cin.ignore();
    gets(name);
    cout<<"\nsex (m/f):";
    cin>>sex;
    cout<<("\nEnter date of birth of APPLICANT:");
    cin.ignore();
    gets(dob);
    cout<<("\nEnter branch of APPLICANT:");
    cin.ignore();
    gets(branch);
    cout<<("\nEnter CGPA of APPLICANT:");
    cin>>cgpa;
    cout<<("\nEnter father's name of APPLICANT:");
    cin.ignore();
    gets(fathr_name);
    cout<<("Enter address of APPLICANT:");
    cin.ignore();
    gets(addrs);
    cout<<("\nEnter E-mail of APPLICANT:");
    cin.ignore();
    gets(e_mail);
    cout<<("\nEnter the Registration Number of APPLICANT:");
    cin>>rno;
}
void APPLICANT::disp()
{
    cout<<"The record of APPLICANTS:\n";
    cout<<"\nName of APPLICANT: ";
	cout<<(name);
    cout<<"\nsex: "<<sex;
    cout<<"\nDOB: "<<dob;
    cout<<"\nCGPA:"<<cgpa;
    cout<<"\nBRANCH:";
	cout<<(branch);
    cout<<"\nFather's name: "<<fathr_name;
    cout<<"\nAddress: ";
	cout<<(addrs);
    cout<<"\nE-mail: ";
	cout<<(e_mail);
    cout<<"\nRegistration number: "<<rno;

}
void APPLICANT::write()
{
    ofstream ofile;
    ofile.open("placement", ios::app);
    reg();
    ofile.write((char*)&c, sizeof(c));
    ofile.close();
}
void APPLICANT::read()
{
    ifstream ifile;
    ifile.open("placement");
    ifile.seekg(0, ios::beg);
    ifile.read((char*)&c, sizeof(c));
    while(!ifile.eof())
    {
	disp();
	ifile.read ((char*)&c, sizeof(c));
    }
    ifile.close();
}

void APPLICANT::del()
{
    char b[20];
    ifstream ifile;
    ifile.open("placement", ios::app);
    ofstream ofile;
    ofile.open("new", ios::app);
    cout<<("Enter the name of the APPLICANT whose records you want to del:");
    cin.ignore();
	gets(b);
    ifile.seekg (0, ios::beg);
    ifile.read((char*)&c, sizeof(c));
    while(ifile)
    {
	if (b!=name)
	    ofile.write((char*)&c, sizeof(c));
	ifile.read((char*)&c, sizeof(c));
    }
    ifile.close();
    ofile.close();
    remove ("placement");
    rename("new", "placement");
}
void APPLICANT::mod()
{
    char d[20];
    int p;
    cout<<("\nEnter name of APPLICANT whose record you want to modify\n");
    cin.ignore();
	gets(d);
    fstream f;
    f.open("placement", ios::in|ios::out);
    f.seekg(0, ios::beg);
    f.read((char*)&c, sizeof(c));
    int a=f.tellg();
    while(! f.eof())
    {
	if (d!=name)
	{
	    cout<<("\nPress 1 to change name\nPress 2 to change sex\nPress 3 to change date of birth\nPress 4 to change CGPA\nPress 5 to change BRANCH\nPress 6 to change father's name\nPress 7 to change address\nPress 8 to change E-mail address\nPress 9 to change Registration of APPLICANT\n");
	    cin>>p;
	    switch(p)
	    {
	    case 1:
		gets(name);
		break;
	    case 2:
		cin>>sex;
		break;
	    case 3:
		gets(dob);
		break;
	    case 4:
		cin>>cgpa;
		break;
	    case 5:
		gets(branch);
		break;
	    case 6:
		gets(fathr_name);
		break;
	    case 7:
		gets(addrs);
		break;
	    case 8:
		gets(e_mail);
		break;
	    case 9:
		cin>>rno;
		break;
	    }
	    f.seekg(a-sizeof(c), ios::beg);
	    f.write((char*)&c, sizeof(c));
	}
	f.read((char*)&c, sizeof(c));
	a=f.tellg();
    }
    f.close();
}
void APPLICANT::eligibility()
{
	int a;
	char m[20];
    ifstream ifile("placement");
    cout<<("Enter name of APPLICANT  eligiblity criteria you want to search:");
    cin.ignore();
	cin>>(m);
    ifile.seekg (0, ios::beg);

    while(ifile)
    {
    	    ifile.read((char*)&c, sizeof(c));
	if (m==name)
	    ifile.read((char*)&c, sizeof(c));
    }
    ifile.close();
    cout<<"\t\t*************Select the branch************"<<endl;
	cout<<"\t\t   * 1. CSE                 *\n";
	cout<<endl;
	cout<<"\t\t   * 2. ECE                 *\n";
	cout<<endl;
	cout<<"\t\t   * 3. Mechanical Engineering         *\n";
	cout<<endl;
	cout<<"\t\t   * 4. Civil Engineering   *\n";
	cout<<endl;
	cout<<"\t\t   * 5. Chemical Engineering    *\n";
	cout<<endl;
	cout<<"\t\t   ENTER YOUR CHOICE:";
	cin>>a;
	switch (a)
	{
		case 1:
			if(cgpa>=8.0)
			{
				cout<<"You are eligible to sit in these companies for the placements \n";
				cout<<"1.AMAZON \n";
				cout<<"2.FLIPKART \n";
				cout<<"3.HCL \n";
				cout<<"4.IBM \n";
				cout<<"5.YAHOO \n";
			}
			 if((cgpa>=7.0)&&(cgpa<8.0))
			{
				cout<<"You are eligible to sit in these companies for the placements \n";
				cout<<"1.WIPRO \n";
				cout<<"2.INFOSYS \n";
				cout<<"3.TCS \n";
				cout<<"4.COGNIZANT \n";
				cout<<"5.MAHINDRA \n";
			}
			if(cgpa<7)
			{
				cout<<"You are not eligible to sit in placements";
			}
			break;
		case 2:
			if(cgpa>=8.0)
			{
				cout<<"You are eligible to sit in these companies for the placements \n";
				cout<<"1.SAMSUNG \n";
				cout<<"2.INTEL \n";
				cout<<"3.VODAFONE \n";
				cout<<"4.LG ELECTRONICS \n";
				cout<<"5.TATA TELESERVICES \n";
			}
			else if((cgpa>=7.0)&&(cgpa<8.0))
			{
				cout<<"You are eligible to sit in these companies for the placements \n";
				cout<<"1.WIPRO \n";
				cout<<"2.CISCO NETWORKING \n";
				cout<<"3.INFOTECH \n";
				cout<<"4.PHILIPS ELECTRONICS \n";
				cout<<"5.REDPINE \n";
			}
			else
			{
				cout<<"You are not eligible to sit in placements";
			}
			break;
		case 3:
			if(cgpa>=8.0)
			{
				cout<<"You are eligible to sit in these companies for the placements \n";
				cout<<"1.BRAHMOS AEROSPACE \n";
				cout<<"2.MARUTI SUZUKI \n";
				cout<<"3.TATA MOTORS \n";
				cout<<"4.ADANI GROUP \n";
				cout<<"5.THERMAX \n";
			}
			else if((cgpa>=7.0)&&(cgpa<8.0))
			{
				cout<<"You are eligible to sit in these companies for the placements \n";
				cout<<"1.L&T \n";
				cout<<"2.GODREJ & BOYCE \n";
				cout<<"3.GENERAL MOTORS INDIA \n";
				cout<<"4.RELIANCE GROUP \n";
				cout<<"5.JOHN DEERE \n";
			}
			else
			{
				cout<<"You are not eligible to sit in placements";
			}
			break;
		case 4:
			if(cgpa>=8.0)
			{
				cout<<"You are eligible to sit in these companies for the placements \n";
				cout<<"1.GAMMON INDIA \n";
				cout<<"2.LARSEN & TOUBRO \n";
				cout<<"3.PUNJ LLOYD GROUP \n";
				cout<<"4.LANCO INFRATECH LIMITED \n";
				cout<<"5.GMR GROUP \n";
			}
			else if((cgpa>=7.0)&&(cgpa<8.0))
			{
				cout<<"You are eligible to sit in these companies for the placements \n";
				cout<<"1.NAGARJUNA CONSTRUCTION COMPANY \n";
				cout<<"2.HINDUSTAN CONSTRUCTION COMPANY \n";
				cout<<"3.JAIPRAKASH ASSOCIATES LIMITED \n";
				cout<<"4.IVCRL INFRASTRUCTURES LTD. \n";
				cout<<"5.SIMPLEX INFRASTRUCTURE LTD. \n";
			}
			else
			{
				cout<<"You are not eligible to sit in placements";
			}
			break;
		case 5:
			if(cgpa>=8.0)
			{
				cout<<"You are eligible to sit in these companies for the placements \n";
				cout<<"1.BASF \n";
				cout<<"2.DOW CHEMICAL \n";
				cout<<"3.SINOPEC \n";
				cout<<"4.SHELL \n";
				cout<<"5.SABIC \n";
			}
			else if((cgpa>=7.0)&&(cgpa<8.0))
			{
				cout<<"You are eligible to sit in these companies for the placements \n";
				cout<<"1.EXXONMOBIL \n";
				cout<<"2.FORMOSA PLASTICS \n";
				cout<<"3.LYONDELLBASELL INDUSTRIES \n";
				cout<<"4.DUPOINT \n";
				cout<<"5.MITSUBISHI CHEMICAL \n";
			}
			else
			{
				cout<<"You are not eligible to sit in placements";
			}
			break;
		default:
			cout<<"Please select the correct branch \n";
			break;
	}
}

main ()
{
    int ch;
    char choice;
    do
    {
    cout<<"\t Lovely Professional university Placement portal \n";
    cout<<"\t ********************************************";
    cout<<endl;
    cout<<"\t\t *  1. View APPLICANT  Details               *\n";
    cout<<endl;
    cout<<"\t\t *  2. Add new APPLICANT Details              \n *";
    cout<<endl;
  
    cout<<"\t\t *  3. Delete a APPLICANT record             \n *";
    cout<<endl;
    cout<<"\t\t *  4. Modify a APPLICANT record             \n *";
    cout<<endl;
    cout<<"\t\t *  5. ELIGIBILITY                           \n *";
    cout<<endl;
    cout<<"\t\t *  6. EXIT                                  \n *";
    cout<<endl;
    cout<<"\t ********************************************";
    cout<<endl;
    cout<<"\t\t Enter your choice: ";
    cin>>ch;


    switch(ch)
    {
    case 1:

	     c.read();
	break;
    case 2:

	    c.write();

	    break;
     case 3:
		c.del();
	break;
    case 4:
	c.mod();
	break;
    case 5:
	c.eligibility();
	break;
    case 6:
	exit(0);
	break;
    default:
	{
	cout<<"\nerror!";
	}
	break;
    }
    cout<<"\ncontinue? (y/n)\n";
    cin>>choice;
    }while(choice=='y');
    cout<<"\n Have a good day";
    return 0;
}
