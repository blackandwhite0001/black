#include<iostream>
#include<string.h>
#include<fstream>

class BanDoc
{
	// ma va ten ban doc
	char*ma,*ten;
	//du lieu tinh ve ca ban doc toi da 100 ban
	static int soBanDoc;
	static BanDoc *cacBanDoc[100];
    // ten tep du lieu ban doc
	static const char * tep;
	public :
	// ham thiet lap va huy bo ban doc
	BanDoc( char *m, char * t )
	{
	ma = strdup (m);
	ten = strdup (t);	
		}	
	BanDoc()
	{
		delete ma;
		delete ten;
	}
	virtual int laUT () {return 0;} 
	// cac ham giup viec dang ki va tim kiem mot ban doc
	static void dangKi();
	static BanDoc* timBD(char*ma);
	//doc va ghi du lieu ve cac ban doc
	static void ghiTep();
	static void docTep();
};
// mo rong them lop ban doc uu tien
class BanDocUT: public BanDoc
{
	friend class BanDoc;
	char * uutien; 
	public :
	BanDocUT (char*m,char*t,char*u):BanDoc(m,t)
	{
    uutien = strdup (u);
	}
	~BanDocUT()
	{
		delete uutien;
	}
	int laUT (){ return 1;}
};
// cac khai bao can thiet cho thanh phan du lieu tinh 
int BanDoc:: soBanDoc = 0 ;
BanDoc *BanDoc::BanDoc[100];
const char*BanDoc::tep = " bandoc.dat";
// thay doi ham dang ki de co ban doc uu tien
void BanDoc::dangKi() 
{
	//nhap ma va ten ban doc
	char ma[80];
	cout <<"Ma ban doc:"; cin.getline(ma , sizeof(ma));
	char ten[80];
	cout<<"Ten ban doc:"; cin.getline(ten , sizeof(ten));
	char ut[80];
	cout<<"Uu tien:"; cin.getline(ut , sizeof(ut));
	if (strcmp(ut,"")==0)
	// khong uu tien
	cacBanDoc[soBanDoc++] = new BanDoc(ma,ten);
	else
	cacBanDoc[soBanDoc++] = new BanDocUT(ma,ten,ut);
	cout<<"BanDoc"<< ten << " da duoc dang ki\n";
}
//ham nay khong thay doi
BanDoc* BanDoc::timBD(char*ma)
{
	for ( int i=0; i<soBanDoc;i++)
	if ( strcmp (ma,cacBanDoc[i]->ma)==0)
	return cacBanDoc[i];
	// khong tim thay tra ve null
	return 0;
}
// thay doi ham doc ghi tep
void BanDoc::ghiTep()
{
	// mo tep de ghi
	ofstream os(tep);
	for (int i=0; i< soBanDoc;i++)
	{
		// ghi thong tin cus ban doc thu i trong mang
		os<<cacBanDoc[i]->ma<<endl;
		os<<cacBanDoc[i]->ten<<endl;
		if (cacBanDoc[i]->laUT())
		{
		    os<<"uu tien"<< endl;
	    	os((BanDocUT*)cacBanDoc[i])->uutien<<endl;
		}else
		os<<"khong uu tien"<<endl;
	}
	
}
void BanDoc::docTep()
{
	// mo tep de doc
	ifstream is (tep);
	while(1)
	{
		// doc ma va ten ban doc tu tep
		char ma [80];
		is.getline(ma,sizeof(ma));
			char ten [80];
		is.getline(ten,sizeof(ten));
			char uutien [80];
		is.getline(uutien,sizeof(uutien));
		if (is.gcount()==0) break;
		if ( strcmp ( uutien,"uu tien")==0)
		{
			is.getline(uutien,sizeof(uutien));
			cacBanDoc[soBanDoc++] = new BanDocUT(ma;uutien);
		}
		else cacBanDoc[soBanDoc++]=new BanDoc(ma,ten);
	}
}
