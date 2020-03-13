#include<fstream>
#include<string.h>
#include<iostream>
using namespace std;
class stud;
class Buffer
{
	char buf[35];
	int nextbyte;
	public:
		Buffer()
		{
			buf[0]='\0';
			nextbyte=0;
		}
		void pack(char []);
		void unpack(char []);
		void read_direct(fstream &,Buffer &,int);
		void write_direct(fstream &,Buffer &,int);
		void cr_bf(stud);
		friend void insert(int);
		friend int search(char [],int);
		friend void remove(char [],int);
};
class stud
{
	char flag[2];
	char fp[3];
	char bp[3];
	char rl[5];
	char cg[5];
	char nm[10];
	public:
		stud()
		{
			strcpy(flag,"0");
			strcpy(fp,"*");
			strcpy(bp,"*");
		}
		void putdata();
		void getdata();
		friend void Buffer::cr_bf(stud);
		friend int search(char [],int);
		friend void insert(int);
		friend void remove(char [],int);
		friend void update(char[],int);
		friend void display_all(int);
};
void Buffer::pack(char str[10])
{
	strcat(buf,str);
	strcat(buf,"|");
}
void Buffer::unpack(char str[10])
{
	int i=nextbyte,c=0;
	while(buf[i]!='|')
		str[c++]=buf[i++];
	str[c]='\0';
	nextbyte=i+1;	
}
void Buffer::read_direct(fstream &stream,Buffer &TP,int k)
{
	stream.seekg(k,ios::beg);
	stream.read((char*)&TP,sizeof(Buffer));
}
void Buffer::write_direct(fstream &stream,Buffer &TP,int k)
{
	stream.seekp(k,ios::beg);
	stream.write((char*)&TP,sizeof(Buffer));
}
void Buffer::cr_bf(stud sk)
{
	pack("1");
	pack(sk.fp);
	pack(sk.bp);
	pack(sk.rl);
	pack(sk.nm);
	pack(sk.cg);
}
void stud::putdata()
{
	cout<<"\t\t  "<<rl<<" \t\t     "<<nm<<" \t       "<<cg;
}
int l=sizeof(Buffer);
int index(int r,int n)
{
	return r%n;
}
void stud::getdata()
{
	char h;
	strcpy(flag,"1");
	cin.get(h);
	cout<<"\n Enter the Roll : ";
	cin.getline(rl,5);
	cout<<" Enter the Name : ";
	cin.getline(nm,10);
	cout<<" Enter the CGPA : ";
	cin.getline(cg,5);
}
int getnext(fstream &f,int r,int n)
{
	Buffer Q;
	char ch[3];
	Q.read_direct(f,Q,r*l);
	Q.unpack(ch);
	while(!strcmp(ch,"1"))
	{
		r=(++r)%n;
		Q.read_direct(f,Q,r*l);
		Q.unpack(ch);
	}
	return r;
}
int give(int n)
{
	int k;
	fstream f;
	f.open("NITW",ios::in);
	f.seekg(n*l,ios::beg);
	f>>k;
	f.close();
	return k;
}
void recs(int n,int fl)
{
	int k;
	fstream f;
	f.open("NITW",ios::in);
	f.seekg(n*l,ios::beg);
	f>>k;
	f.close();
	fstream fout;
	fout.open("NITW",ios::in|ios::out);
	if(fl==1)
		k++;
	else
		k--;
	fout.seekp(n*l,ios::beg);
	fout<<k;
	fout.close();
}
void insert(int n)
{
	Buffer TP,Q;
	fstream fout;
	stud st,tem;
	int i=0,a=0,g,r;
	g=give(n);
	if(g==n)
	{
		cout<<"\n No Space Available";
		return;
	}
	recs(n,1);
	fout.open("NITW",ios::in|ios::out);
	st.getdata();
	while(st.rl[i])
		a=a*10+(st.rl[i++]-48);
	r=index(a,n);
	do
	{
		g=r;
		Q.read_direct(fout,Q,r*l);
		Q.unpack(tem.flag);
		Q.unpack(tem.fp);
		Q.unpack(tem.bp);
		r=tem.fp[0]-48;
	}while(tem.flag[0]=='1'&&tem.fp[0]!='*');
	if(strcmp(tem.flag,"1"))
	{
		strcpy(st.fp,tem.fp);
		strcpy(st.bp,tem.bp);
		TP.cr_bf(st);
		TP.write_direct(fout,TP,g*l);
		fout.close();
		return;
	}
	r=getnext(fout,g+1,n);
	st.bp[0]='a'+g-49;
	st.bp[1]='\0';
	TP.cr_bf(st);
	TP.write_direct(fout,TP,r*l);
	TP.read_direct(fout,Q,g*l);
	Q.buf[2]='a'+r-49;
	TP.write_direct(fout,Q,g*l);
	fout.close();
}
int search(char rk[5],int n)
{
	Buffer Q;
	int fl=0,i=0,g=0,r,d,count=0;
	stud tem;
	fstream fout;
	fout.open("NITW",ios::in|ios::out);
	if(fout.fail())
	{
		cout<<"\nUnable to Open File !!! ";
		exit(1);
	}
	while(rk[i])
		g=g*10+(rk[i++]-48);
	r=index(g,n);
	do
	{
		g=r;
		Q.read_direct(fout,Q,r*l);
		Q.unpack(tem.flag);
		if(!strcmp(tem.flag,"0"))
		{
			cout<<"\n Such a Record is not Present ";
			fout.close();
			return -1;
		}
		Q.unpack(tem.fp);
		Q.unpack(tem.bp);
		Q.unpack(tem.rl);
		if(!strcmp(tem.rl,rk))
		{
			fl=1;
			Q.unpack(tem.nm);
			Q.unpack(tem.cg);
			tem.putdata();
			return r;
		}
		r=tem.fp[0]-48;
		count++;
	}while(tem.fp[0]!='*');
	if(tem.fp[0]=='*')
		cout<<"\n Such a Record is not Present ";
	fout.close();
	return -1;
}
void display_all(int n)
{
	Buffer TP;
	int c=0,r,m=1;
	stud st;
	fstream fin;
	fin.open("NITW",ios::in|ios::out);
	if(fin.fail())
		cout<<"\n Unable to Open file";
	else
	{
		TP.read_direct(fin,TP,0);
		cout<<"\n\n\t\t\tROLL NO.\t     NAME \t      CGPA \n";
		while(c<n)
		{
			TP.unpack(st.flag);
			if(!strcmp(st.flag,"1"))
			{
				TP.unpack(st.fp);
				TP.unpack(st.bp);
				TP.unpack(st.rl);
				TP.unpack(st.nm);
				TP.unpack(st.cg);
				cout<<"\n    Record "<<m++;
				st.putdata();
			}
			c++;
			r=index(c,n);
			TP.read_direct(fin,TP,r*l);
		}
	}
	fin.close();
}
void remove(char rm[10],int n)
{
	Buffer TP,Q;
	int pos,c;
	c=search(rm,n);
	if(c!=-1)
	{
		stud st;
		fstream fin;
		fin.open("NITW",ios::in|ios::out);
		TP.read_direct(fin,TP,c*l);
		TP.unpack(st.flag);
		TP.unpack(st.fp);
		TP.unpack(st.bp);
		if(st.fp[0]!='*')
		{
			pos=st.fp[0]-48;
			Q.read_direct(fin,Q,pos*l);
			Q.buf[4]=st.bp[0];
			Q.write_direct(fin,Q,pos*l);
		}
		if(st.bp[0]!='*')
		{
			pos=st.bp[0]-48;
			Q.read_direct(fin,Q,pos*l);
			Q.buf[2]=st.fp[0];
			Q.write_direct(fin,Q,pos*l);
		}
		TP.buf[0]='2';
		//TP.buf[2]='*';
		//TP.buf[4]='*';
		TP.buf[6]='0';
		TP.buf[7]='|';
		TP.nextbyte=0;
		TP.write_direct(fin,TP,c*l);
		recs(n,0);
	}
}
void update(char nm[10],int n)
{
	Buffer TP,Q;
	int pos,c;
	c=search(nm,n);
	if(c!=-1)
	{
		stud st;
		fstream fin;
		fin.open("NITW",ios::in|ios::out);
		TP.read_direct(fin,TP,c*l);
		TP.unpack(st.flag);
		TP.unpack(st.fp);
		TP.unpack(st.bp);
		TP.unpack(st.rl);
		TP.unpack(st.nm);
		TP.unpack(st.cg);
		cout<<"\n\n Enter the new CGPA : ";
		cin.getline(st.cg,5);
		Q.pack(st.flag);
		Q.pack(st.fp);
		Q.pack(st.bp);
		Q.pack(st.rl);
		Q.pack(st.nm);
		Q.pack(st.cg);
		Q.write_direct(fin,Q,c*l);
	}
}
void fileclear(int n)
{
	ifstream fin("NITW");
	Buffer TP;
	int i=1;
	fin.read((char*)&TP,sizeof(Buffer));
	if(fin.fail())	
	{
		fin.close();
		TP.pack("0");
		TP.pack("*");
		TP.pack("*");
		ofstream fout("NITW");		
		while(i<=n)
		{
			fout.write((char*)&TP,sizeof(Buffer));
			i++;
		}
		fout<<"0";
	}
}
main()
{
	int ch,v,n=7;
	fileclear(n);
	char rc[5],c;
	do
	{
		cout<<"\n\n\t  !!!! MENU !!!!"
	    	    <<"\n\t 1.Insert A Record"
	    	    <<"\n\t 2.Delete A Record"
	    	    <<"\n\t 3.Search For A Record"
	    	    <<"\n\t 4.Update A Record"
	    	    <<"\n\t 5.Display All Records"
	    	    <<"\n\t 6.Exit"
	    	    <<"\n\t Enter your choice (1-6) : ";
		cin>>ch;
		switch(ch)
		{
		case 1 :insert(n);
			break;
		case 2 :cout<<"\n Enter Roll No. for record to be deleted : ";
			cin.get(c);
			cin.getline(rc,5);
			remove(rc,n);
			break;
		case 3 :cout<<"\n Enter Roll No. for record to be searched : ";
			cin.get(c);
			cin.getline(rc,5);
			v=search(rc,n);
			break;
		case 4 :cout<<"\n Enter Roll No. for record to be updated : ";
			cin.get(c);
			cin.getline(rc,5);
			update(rc,n);
			break;
		case 5 :display_all(n);
			break;
		case 6 :cout<<"\n   Thank You\n";
			break;
		default:cout<<"\n  Wrong Input\n";
			break;
		}
	}while(ch!=6);
}
