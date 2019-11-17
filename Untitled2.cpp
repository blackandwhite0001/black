#include <iostream.h>

class PhanSo
{
	// thuoc tinh tu so va mau so
	int ts, ms ;
	// ham rut gon tu so va mau so cua phan so
	void rutgon();
	public;
	PhanSo(int_ts = 0, int_ms = 1 ); ms(_ms),ts(_ts)
	{
		rutgon();
	}
	//cac toan tu chuyen kieu
	
	// chuyen kieu int tra ve phan chia nguyen cua phan so
	oprator int()
	{
		return ts/ms;
	}
	// chuyen kieu thuc ve phan chia thuc
	operator float ()
	{
		return float (ts)/ms;
	}
	PhanSo operator -() const
	{
		return PhanSo(-ts,ms);
	}
	//cac toan tu toan hoc co so
	friend int operator ==( const PhanSo&, const PhanSo&);
	friend int operator !=( const PhanSo&, const PhanSo&);
	friend int operator +( const Phanso&, const PhanSo&);
	friend int operator -( const PhanSo&, const PhanSo&);
	friend int operator *( const PhanSo&, const PhanSo&);
	friend int operator /( const PhanSo&, const PhanSo&);
	// cac toan tu mo rong
	PhanSo operator += ( const PhanSo& ps)
	{return ( *this = *this + ps);
	}
	PhanSo operator -= ( const PhanSo& ps)
	{return ( *this = *this - ps);
	}
	PhanSo operator *= ( const PhanSo& ps)
	{return ( *this = *this * ps);
	}
	PhanSo operator /= ( const PhanSo& ps)
	{return ( *this = *this / ps);
	}
	// toan tu ket xuat du lieu mot phan so
	friend ostream& operator << ( ostream& out, const PhanSo& ps);
	//ham tim USCLN cua hai so m va n nguyen duong
	int uscln(int m, int n)
	{
		if (m<n)
		{
			if (m==0) return n;
			return uscln (m&n,m);
		}
		// m>=n
		if (==0) return m;
		return uscln (m&n,n);
	}
	void PhanSo : : rutgon()
	{
		//chi co ts la co the mang dau 
		if (ms<0)
		{
			ms=-ms;
			ts=-ts;
		}
		// tim USCLN
		int usc = ( ts >= 0 ) ? uscln (ts,ms) : uscln (-ts,ms);
		ts/= usc;
		ms/=usc;
	}
	// thi hanh cac toan tu cho lop phan so
	int operator == (const PhanSo& ps1,const PhanSo& ps2)
	{
		//vi cac phan so luon duoc rut gon nen hai phan so bang nhau khi tu so va mau so bang nhau
		return ( ps1.ts==ps2.ts&&ps1.ms==ps2.ms );
	}
	int operator != ( const PhanSo& ps1 ,const PhanSo& ps2)
	{
	return ( ps1.ts!=ps2.ts||ps1.ms!=ps2.ms );
    }
    PhanSo operator + ( const PhanSo& ps1, const PhanSo& ps2)
    {
  	return PhanSo(ps1.ts*ps2.ms+ps2.ts*ps1.ms,ps1.ms*ps2.ms);
    } 
	 PhanSo operator - ( const PhanSo& ps1, const PhanSo& ps2)
    {
  	return PhanSo(ps1.ts*ps2.ms-ps2.ts*ps1.ms,ps1.ms*ps2.ms);
    }    
     PhanSo operator * ( const PhanSo& ps1, const PhanSo& ps2)
    {
  	return PhanSo(ps1.ts*ps2.ts,ps1.ms*ps2,ms);
    }
     PhanSo operator / ( const PhanSo& ps1, const PhanSo& ps2)
    {
  	return PhanSo(ps1.ts*ps2.ms,ps1.ms*ps2.ts);
    }
    ostream& operator << ( ostream& out , const PhanSo& ps)
    {
   	return(out<< ps.ts << "/"<< ps.ms );
	}
    //ham chinh thu lop phan so
    void main ()
    { 
    PhanSo a(5,4),b(1,4);
    cout << "a = "<<a<<"\n";
    cout << "b = "<<b<<"\n";
    cout << "a+b = "<<( a+b)<<"\n";
    cout << "a-b = "<<( a-b)<<"\n";
    cout << "a*b = "<<( a*b)<<"\n";
    cout << "a/b = "<<( a/b)<<"\n";
	}
}
