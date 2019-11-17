// ham sau day thuc hien noi 2 doi tuong xau

#include<iostream>
#include<string.h>


using namespace std;

class String{
    private:
        char *str;
    public:
        String (char *s=0){   //constructor trong truong hop mac dinh =0
            if (s==0)
                str= strdup("");   // trong string.h co tac dung khoi tao str va copy "" vao ~ strcpy (str,"")
            else 
                str=strdup(s);    // khac 0 thi khoi tao khac
        }

        String (const String& s){ // ham thiet lap sao chep
            str=strdup(s.str);
        }

        String & operator = (const String &s){   // chong toan tu
            delete str;      // xoa cai cu
            str =strdup(s.str);
            return *this;
        }

        ~String(){
            delete []str;
        }

        String & concat(const String& s){
            // cap phat 
            char * nstr=new char[strlen(str)+strlen(s.str)+1];//  + 1 la cua ki tu 0 o cuoi
            strcpy(nstr,str);
            strcat(nstr,s.str);

            // xoa noi dung cu
            delete str;

            // noi dung moi
            str=nstr;
            return *this;
        
        }

        void print(){
            cout <<str;
        }


};// sau class phai co ;
int main(){
String s1;
cout << "s1="; s1.print();cout<< endl;
String s2 = "Hello";
cout << "s2="; s2.print(); cout << endl;
s1 =s2 . concat(" Tuan Anh");
cout<< "sau khi concat\n";
cout << "s1="; s1.print();cout<< endl;
cout << "s2="; s2.print();cout<< endl;

return 1;
}


