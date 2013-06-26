    #include <iostream>
    #include <string.h>
    using namespace std;
    #define MAXLEN 1000
     
    struct SNL
    {
        char sign;//da^'u, ne^'u so^' âm thì sign=-1
        char len;//chie^`u dài
        char num[MAXLEN];//lu+u các chu+~ so^'
    };
     
    void initSNL(SNL &n);//Kho+?i ta.o so^' nguyên lo+'n
    void str2snl(char *str, SNL &n);//Chuye^?n mo^.t chuo^~i kí tu+. thành so^' nguyên lo+'n
    void scanSNL(SNL &n);//?o.c so^' nguyên lo+'n tu+` bàn phím
    void printSNL(SNL &n);//In so^' nguyên lo+'n ra màn hình
    int cmpu(SNL &a, SNL &b);//So sánh 2 so^' nguyên lo+'n không xét da^'u
    int cmp(SNL &a, SNL &b);//So sánh 2 so^' nguyên lo+'n, ne^'u a>b tra? ve^` 1, a=b tra? ve^` 0, a<b tra? ve^` -1
    void addu(SNL &s, SNL &a, SNL &b);//Co^.ng không xét da^'u
    void add(SNL &s, SNL &a, SNL &b);//Co^.ng có xét da^'u
    void subu(SNL &s, SNL &a, SNL &b);//Tru+` không xét da^'u
    void sub(SNL &s, SNL &a, SNL &b);//Tru+` có xét da^'u
    void mul(SNL &r, SNL &a, SNL &b);//Nhân hai so^' nguyên lo+'n
    void div(SNL &r, SNL a, SNL b);//Phép chia so^' nguyên lo+'n
     
    void InitSNL(SNL &n)
    {
        for (int i=0; i<MAXLEN; i++) n.num[i]=0;
        n.len=0;
        n.sign=1;
    }
    void str2snl(char *str, SNL &n)
    {
        int i;
        if (str[0]=='-')
        {
            n.sign=-1;
            str++; //bo? qua kí tu+. ?a^`u tiên
        }
        else
            n.sign=1;
     
        n.len=strlen(str);//Chie^`u dài (so^' chu+~ so^') cu?a so^' nguyên lo+'n
     
        for (i=0; i<n.len; i++)
            n.num[i]=str[n.len-i-1]-'0';//Chuye^?n tu+`ng kí tu+. thành so^'
    }
     
    int cmpu(SNL &a, SNL &b)
    {
     
        if (a.len>b.len)//So^' nào dài ho+n thì so^' ?ó lo+'n ho+n
            return 1;
        else if (a.len<b.len)
            return -1;
        else//Tru+o+`ng ho+.p chie^`u dài 2 so^' ba(`ng nhau
        {
            int len=a.len-1;
            while (len>=0)
            {
                //So sánh tu+` chu+~ so^'
                if (a.num[len]>b.num[len])
                    return 1;
                else if (a.num[len]<b.num[len])
                    return -1;
                else
                    len--;
            }
        }
        return 0;
    }
     
    int cmp(SNL &a, SNL &b)
    {
        if (a.sign * b.sign<0) return a.sign;
        return a.sign * cmpu(a,b);
    }
     
    void scanSNL(SNL &n)//?o.c SNL tu+` bàn phím
    {
        char *t=new char[MAXLEN];
        cin>>t;
        str2snl(t,n);
        delete []t;
    }
     
    void printSNL(SNL &n)
    {
        if (n.sign<0) cout<<"-";
        for (int i=n.len-1; i>=0; i--) cout<<(int)n.num[i];
    }
     
    void addu(SNL &s, SNL &a, SNL &b)
    {
        InitSNL(s);
        s.len=a.len>b.len?a.len:b.len;
        char m=0;//bie^'n nho+'
        for (int i=0; i<s.len; i++)
        {
            s.num[i]=a.num[i]+b.num[i]+m;
            if (s.num[i]>9)
            {
                s.num[i] -= 10;
                m=1;
            }
            else
                m=0;
        }
        if (m)
        {
            s.num[s.len]=1;
            s.len++;
        }
    }
     
    void add(SNL &s, SNL &a, SNL &b)
    {
        if (a.sign*b.sign>0)//Ne^'u a và b cùng da^'u
        {
            addu(s,a,b);
            s.sign=a.sign;//Da^'u cu?a s cu~ng là da^'u cu?a a hoa(.c b
        }
        else
        {
            int t=cmpu(a,b);
            if (t==1)
            {
                subu(s,a,b);
                s.sign=a.sign;
            }
            else if (t==-1)
            {
                subu(s,b,a);
                s.sign=b.sign;
            }
            else
                InitSNL(s);
     
        }
    }
     
    void subu(SNL &r, SNL &a, SNL &b)
    {
        InitSNL(r);
        r.len=a.len>b.len?a.len:b.len;
        int m=0;
        for (int i=0; i<r.len; i++)
        {
            if (a.num[i]<b.num[i]+m)
            {
                r.num[i]=10+a.num[i]-b.num[i]-m;
                m=1;
            }
            else
            {
                r.num[i]=a.num[i]-b.num[i]-m;
                m=0;
            }
        }
        while (r.num[r.len-1]==0) r.len--;
    }
     
    void sub(SNL &r, SNL &a, SNL &b)
    {
        b.sign=-b.sign;
        add(r,a,b);
        b.sign=-b.sign;
    }
     
    void mul(SNL &r, SNL &a, SNL &b)
    {
        InitSNL(r);
        for (int i=0; i<b.len; i++)
            for (int j=0; j<b.num[i]; j++)
                for (int k=0; k<a.len; k++)
                {
                    r.num[k+i] += a.num[k];
                    if (r.num[k+i]>9)
                    {
                        r.num[k+i] -= 10;
                        r.num[k+i+1]++;
                    }
                }
                r.len=a.len+b.len;
                while (r.num[r.len-1]==0) r.len--;
                r.sign=a.sign*b.sign;
    }
     
    void div(SNL &r, SNL a, SNL b)
    {
        InitSNL(r);
        r.len=a.len-b.len+1;
        if (a.len>=b.len)
        {
            int blen=b.len;
            int i;
            if (a.len>b.len)
            {
                i=a.len-1;
                int x=a.len-b.len;
                while (i>=0)
                {
                    if (i>=x)
                        b.num[i]=b.num[i-x];
                    else
                        b.num[i]=0;
                    i--;
                }
            }
            b.len=a.len;
            SNL d;
            i=1;
            while (b.len>=blen)
            {
                while (cmpu(a,b)>-1)
                {
                    subu(d,a,b);
                    r.num[r.len-i]++;
                    a=d;
                }
                b.len--;
                i++;
                for (int k=0; k<b.len; k++) b.num[k]=b.num[k+1];
                b.num[b.len]=0;
            }
            while (r.num[r.len-1]==0) r.len--;
        }
        r.sign=a.sign*b.sign;
    }
     
    int main()
    {
        SNL a,b,c;
        InitSNL(a);
        InitSNL(b);
        InitSNL(c);
     
        cout<<"Nhap so nguyen a: "; scanSNL(a);
        cout<<"Nhap so nguyen b: "; scanSNL(b);
     
        add(c,a,b);
        cout<<endl<<"a + b = "; printSNL(c);
        sub(c,a,b);
        cout<<endl<<"a - b = "; printSNL(c);
     
        mul(c,a,b);
        cout<<endl<<"a * b = "; printSNL(c);
     
        div(c,a,b);
        cout<<endl<<"a / b = "; printSNL(c);
     
        cout<<endl;
        system("pause");
        return 0;
    }


