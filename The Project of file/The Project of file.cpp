#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class file
{
public:
	char name[20];      //2
	char address[20];   //2
	char gender[10];    //2
	char phone[15]; // to contact  //2 
	char spcialization[20];
	int age;

	char disease[60];
	char blood[5];
	char datacometoho[20];
	char name_doc_patiant[20];
	char department[20];
	double billcost;
	string index;
	void insert_Doctors();
	void inser_Patian();
	void insert_Department();
	void Display(string a);
	void Display_Dep_Record();
	void Search(string Li);
};
	void file::insert_Doctors()
	{
		ofstream my;
		my.open("Doctors.txt",  /*ios::binary |*/ ios::app);
		my.seekp(0, ios::beg);
		if (my.is_open())
		{
			short length;
			cout << "enter the index you want to insert : \n";
			cin >> index;
			cin.ignore();

			cout << "Enter Doctor's name :\n";
			cin.getline(name, 20);

			cout << "Enter Doctor's address :\n";
			cin.getline(address, 20);


			cout << "Enter Doctor's gender :\n";
			cin.getline(gender, 20);


			cout << "Enter Doctor's phone :\n";
			cin.getline(phone, 20);

			cout << "Enter Doctor's spcialization :\n";
			cin.getline(spcialization, 20);


			cout << "Enter Doctor's age :\n";
			cin >> age;


			my << index;

			length = strlen(name);
			my.write((char*)&length, sizeof(short));
			my.write(name, strlen(name));


			length = strlen(address);
			my.write((char*)&length, sizeof(short));
			my.write(address, strlen(address));

			length = strlen(gender);
			my.write((char*)&length, sizeof(short));
			my.write(gender, strlen(gender));

			length = strlen(phone);
			my.write((char*)&length, sizeof(short));
			my.write(phone, strlen(phone));

			length = strlen(spcialization);
			my.write((char*)&length, sizeof(short));
			my.write(spcialization, strlen(spcialization));

			my.put('|');
			my << age;

			my << endl;

		}
		else
			cout << "error";
		my.close();

	}
	

	void file::inser_Patian()
	{
		ofstream p;
		p.open("Patients.txt", ios::app);

		if (p.is_open())
		{

			short length;

			cout << "enter the index you want to insert : \n";
			cin >> index;
			cin.ignore();

			cout << "Enter patian's name :\n";
			cin.getline(name, 20);
			

			cout << "Enter patian's address :\n";
			cin.getline(address, 20);

			cout << "Enter patian's gender :\n";
			cin.getline(gender, 10);

			cout << "Enter patian's phone :\n";
			cin.getline(phone, 15);

			cout << "Enter patian's disease :\n";
			cin.getline(disease, 20);

			cout << "Enter patian's blood :\n";
			cin.getline(blood, 5);

			cout << "Enter patian's datacometoho :\n";
			cin.getline(datacometoho, 20);

			cout << "Enter patian's name_doc_patiant :\n";
			cin.getline(name_doc_patiant, 20);


			cout << "Enter patian's age :\n";
			cin >> age;

			cout << "enter patian's billcost : \n";
			cin >> billcost;

			//p<<endl; //to don;t enter a next line
			p << index;

			length = strlen(name);
			p.write((char*)&length, sizeof(short));
			p.write(name, strlen(name));


			length = strlen(address);
			p.write((char*)&length, sizeof(short));
			p.write(address, strlen(address));

			length = strlen(gender);
			p.write((char*)&length, sizeof(short));
			p.write(gender, strlen(gender));

			length = strlen(phone);
			p.write((char*)&length, sizeof(short));
			p.write(phone, strlen(phone));

			length = strlen(disease);
			p.write((char*)&length, sizeof(short));
			p.write(disease, strlen(disease));

			length = strlen(blood);
			p.write((char*)&length, sizeof(short));
			p.write(blood, strlen(blood));


			length = strlen(datacometoho);
			p.write((char*)&length, sizeof(short));
			p.write(datacometoho, strlen(datacometoho));

			length = strlen(name_doc_patiant);
			p.write((char*)&length, sizeof(short));
			p.write(name_doc_patiant, strlen(name_doc_patiant));

			p.put('|');
			p << age;

			p.put('|');
			p << billcost;

			p << endl;

		}
		else
			cout << "error";
		p.close();


	}

	

	void file::insert_Department()
	{
		ofstream dept;
		dept.open("Departments.txt", ios::app);

		if (dept.is_open())
		{
			char Num_of_hours[30];
			char Head[30];
			int Num_of_Dep;
			short length;
			cout << "Enter the index of the department : \n";
			cin >> index;
			cin.ignore();

			cout << "Enter the department you want to insert : \n";
			cin.getline(department, 60);

			cout << "Working hours in the Department (.....am To ....pm): " << "";
			cin.getline(Num_of_hours, 30);

			cout << "The Head of  the Department : " << "";
			cin.getline(Head, 30);

			cout << "The absorptive capacity of  the Department : " << "";
			cin >> Num_of_Dep;

			dept << index;

			length = strlen(department);
			dept.write((char*)&length, sizeof(short));
			dept.write(department, strlen(department));

			length = strlen(Num_of_hours);
			dept.write((char*)&length, sizeof(short));
			dept.write(Num_of_hours, strlen(Num_of_hours));

			length = strlen(Head);
			dept.write((char*)&length, sizeof(short));
			dept.write(Head, strlen(Head));

			dept.put('|');
			dept << age;

			dept << endl;
		}
		else
			cout << "Error!! file is not found"<<endl;
		dept.close();
	}

	void file::Display(string File_Name)
	{
		ifstream my_file;
		my_file.open(File_Name);
		string line;
		while (!my_file.eof()) {
			getline(my_file, line);
			if (my_file.good()) {
				cout << line << endl;
			}
		}



	}
	
	void file::Search(string Li)
	{
		string line;
		string Index_search;
		bool found = false;
		cout << "Enter the index of the line that you want to search about:" << " ";
		cin >> Index_search;
		ifstream My_file(Li);
		if (My_file.is_open())
		{
			while (!My_file.eof())
			{
				getline(My_file, line);
				index = line.substr(0, 5);
				if (index == Index_search)
				{
					found = true;
					break;
				}
				else
				{
					found = false;
				}
			}
		}
		if (found=true)
		{
			cout << line << endl;
		}
	}
	/*void Delete(string st) {
	char fn[11], cn[11], id[11], ln[11];
	char nfn[11], ncn[11], nid[11], nln[11];
	int postion;
	short e;
	short length;
	char idsearch[11];
	bool found = false;
	cout << "inter id:";
	cin >> idsearch;
	cin.ignore();
	fstream f(st, ios::in |ios::out| ios::app );
	while (!f.eof())
	{
		f.read(id, 5);
		cout << id;
		if (id == idsearch)
		{
			found = true;
			postion = f.tellg();
			 postion = postion - 5; 
			break;
		}
	 else
		{
			found = false;
			f.read((char*)&e, sizeof(short)); f.read(fn, e);
			fn[e] = '\0';
			f.read((char*)&e, sizeof(short)); f.read(ln, e);
			ln[e] = '\0';
			f.read((char*)&e, sizeof(short)); f.read(cn, e);
			cn[e] = '\0';


		} 




	}

	if (found == true) {

	 
		ofstream nf(st,ios::out| ios::app|ios::binary);
		nf.seekp(postion,ios::beg);
			f.write("$",1);			 



	}

	else
	{

		cout << "id not existing" << endl;


	}
	}*/
	/*void update(string st) {
	char fn[11], cn[11], id[11], ln[11];
	char nfn[11], ncn[11], nid[11], nln[11];
	int postion;
	short e;
	char idsearch[11];
	bool found = false;
	cout << "inter id:";
	cin >> idsearch;
	cin.ignore();
	ifstream f(st, ios::in |ios::app|ios::binary);
	while (!f.eof())
	{
		f.read(id, 5);
		cout << id;
		if (id == idsearch)
		{
			found = true;
			postion = f.tellg();
			
			break;
		}
		else
		{
			found = false;
			f.read((char*)&e, sizeof(short)); f.read(fn, e);
			 fn[e] = '\0';
			 f.read((char*)&e, sizeof(short)); f.read(ln, e);
			 ln[e] = '\0';
			 f.read((char*)&e, sizeof(short)); f.read(cn, e);
			 cn[e] = '\0';


		}


 

	}
	if (found == true) {

		short length;
		ofstream nf(st,ios::out| ios::app|ios::binary);
		nf.seekp(postion,ios::beg);
					cout << "enter first name:"; cin.getline(nfn , 11);
					cout << "enter last name :"; cin.getline(nln, 11);
					cout << "enter  city name :"; cin.getline(ncn, 11);
					cin.ignore();
					cin.ignore();
					length = strlen(nfn);
					nf.write((char*)&length, sizeof(short)); nf.write(nfn, strlen(fn));
					length = strlen(nln);
					nf.write((char*)&length, sizeof(short)); nf.write(nln, strlen(ln));
					length = strlen(ncn);
					nf.write((char*)&length, sizeof(short)); nf.write(ncn, strlen(cn));
					



	}

	else
	{

		cout << "id not existing" << endl;


	}






}*/

int main()
{
	file Pr;
	string File_Name;
	cout << "================================================" << endl;
	cout << "=======================[Menu]===================\n";
	cout << "================================================" << endl;
	bool system = true;
	while (system)
	{
		cout << "If you want to inseart in doctor file click 1 :\n";
		cout << "If you want to inseart in pation file click 2 :\n";
		cout << "If you want to inseart in department file click 3 :\n";

		cout << "If you want to search in file click 4 :\n";


		cout << "If you want to delete in doctor file click 5 :\n";
		cout << "If you want to delete in pation file click 6 :\n";
		cout << "If you want to delete in department file click 7 :\n";

		cout << "If you want to update in doctor file click 8 :\n";
		cout << "If you want to update in pation file click 9 :\n";
		cout << "If you want to update in department file click 10 :\n";

		cout << "If you want to getlength of file  click 11 :\n";

		cout << "If you want to Dispaly  click 12 in :\n";
		cout << "/==================================================/" << endl;
		cout << "Select Option ->"<<" ";
		int Option;
		cin >> Option;
		switch (Option)
		{
		case 1:
			Pr.insert_Doctors();
			break;
		case 2:
			Pr.inser_Patian();
			break;
		case 3:
			Pr.insert_Department();
			break;

		case 4:
			cout << "Enter the name of file that you want to search in : "<<" ";
			cin >> File_Name;
			Pr.Search(File_Name);
			break;
		case 12:
			cout << "Enter the name of file that you want to display it : "<< " ";
			cin >> File_Name;
			cout << endl;
			Pr.Display(File_Name);
			cout<< endl;
			break;

		default:
			cout << "sorry enter the right number \n";
		}
		cout << "if you want to continue in the system enter 'T' or enter 'N' to close system \n";
		char h;
		cout << "Your choise -> "<<" ";
		cin >> h;
		if (h != 'T')
		{
			system = false;
		}
	}

	return 0;

}