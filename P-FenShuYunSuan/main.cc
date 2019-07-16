#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int StrtoDigit (const string& s) {
  int back=0;
  for ( auto e : s  ) {
    back = back * 10 + e-'0';

  }
  return back;

}

string DigittoStr (int num,int signal=0) {
  string back;
  if ( num == 0&&signal  )
    return back;
  stringstream ss;
  ss << num;
  ss >> back;
  if(signal)
    back += " ";
  return back;

}

void split (string& s , int& a , int& b) {
  int flag = 1;
  if ( s [0] == '-'  ) {
    flag = -1;
    s.erase (0 , 1);

  }
  size_t pos = s.find ('//');
  a = StrtoDigit (s.substr (0 , pos))*flag;
  b = StrtoDigit (s.substr (pos + 1));

}

class Rat {
  private:
    int a,b;
    string spec;
    int MaxYue (int fir , int sec) {
      int a = fir > sec ? fir : sec , b = fir > sec ? sec : fir;
      while ( b  ) {
        int tmp = b;
        b = a%b;
        a = tmp;

      }
      return a;

    }
  public:
    Rat (int _a=0 , int _b=0 , int _flag=0)
      :a (_a) , b (_b) 
    {}
    Rat operator+(const Rat& d) {
      Rat c;
      c.a = a*d.b + d.a*b;
      c.b = b*d.b;
      if ( !c.a  )
        c.spec = "0";
      return c;

    }
    Rat operator-(const Rat& d) {
      Rat c;
      c.a = a*d.b - d.a*b;
      c.b = b*d.b;
      if ( !c.a  )
        c.spec = "0";
      return c;

    }
    Rat operator*(const Rat& d) {
      Rat c;
      c.a = a*d.a;
      c.b = b*d.b;
      if ( !c.a  )
        c.spec = "0";
      return c;

    }
    Rat operator/(const Rat& d) {
      Rat c;
      c.a = a*d.b;
      c.b = b*d.a;
      if ( c.b < 0  ) {
        c.a *= -1 , c.b *= -1;

      }
      if ( !c.a  )
        c.spec = "0";
      if ( !c.b  )
        c.spec = "Inf";
      return c;

    }
    Rat& operator=(const Rat& d) {
      if ( this != &d  ) {
        a = d.a , b = d.b ;
        spec = d.spec;

      }
      return *this;

    }
    string Display () {
      if ( spec.size ()>0  )
        return spec;
      string back;
      int c=abs(a),k = c/ b,yue;
      c = c - b*k;
      if ( c == 0  ) {
        if ( k == 0  )
          back += "0";
        else if ( a > 0  ) 
          back += DigittoStr (k);
        else
          back += "(-" + DigittoStr (k)+")";
        return back;

      }
      yue = MaxYue (c , b);
      c /= yue , b /= yue,a/=yue;
      if ( a < 0  )
        back += "(-" + DigittoStr (k , 1) + DigittoStr (c) + "/" + DigittoStr (b) + ")";
      else if ( a == 0  )
        back += "0";
      else
        back += DigittoStr (k,1)+ DigittoStr (c) + "/" + DigittoStr (b) ;
      return back;

    }

};
int main () {
  string as , bs;
  while ( cin >> as >> bs  ) {
    int a1 , a2 , b1 , b2;
    split (as , a1 , a2);
    split (bs , b1 , b2);
    Rat a (a1 , a2) , b (b1 , b2);
    Rat c = a + b , d = a - b , e = a*b , f = a / b;
    cout << a.Display () << " + " << b.Display () << " = " << c.Display ()<<endl;
    cout << a.Display () << " - " << b.Display () << " = " << d.Display ()<<endl;
    cout << a.Display () << " * " << b.Display () << " = " << e.Display ()<<endl;
    cout << a.Display () << " / " << b.Display () << " = " << f.Display ()<<endl<<endl;

  }
  return 0;

}

