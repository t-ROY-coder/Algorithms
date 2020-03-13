#include<iostream.h>
#include<fstream.h>
struct student
{
	int rno,pos;
	char course;
	student()
	{
	rno=-1;pos=-1;
	}
};
struct index
{
	int data,pos,lchild,rchild;
	index()
	{data=-1;pos=-1,lchild=-1,rchild=-1;}
};
int main()
{
	fstream f("student.txt",ios::out|ios::in);
	fstream fi("index.txt",ios::out|ios::in);

	student s,temp;index in,temp1;int i=0;
	char ch='y';
	while(ch=='y')
	{
		cout<<"enter rno";
		cin>>s.rno;
		cout<<"enter course";
		cin>>s.course;
		s.pos=i;
		f.seekp(i*sizeof(student),ios::beg);
		f.write((char*)&s,sizeof(student));
		i++;
		cout<<"continue?";
		cin>>ch;
	}
	fi.seekp(0,ios::beg);
	int j=0;

	while(j<i)
	{
		if(j==0)
		{
			f.seekg(0,ios::beg);
			f.read((char*)&temp,sizeof(student));
			in.data=temp.rno;in.pos=temp.pos;in.lchild=-1;in.rchild=-1;
			fi.seekp(0,ios::beg);
			fi.write((char*)&in,sizeof(index));
			j++;
		}
		else
		{
				int k;
				f.seekg(j*sizeof(student),ios::beg);
				f.read((char*)&temp,sizeof(student));
				in.pos=j;in.data=temp.rno;
				in.lchild=-1;in.rchild=-1;
				fi.seekp(j*sizeof(index),ios::beg);
				fi.write((char*)&in,sizeof(index));
				fi.seekg(0,ios::beg);
				fi.read((char*)&temp1,sizeof(index));
				int m=temp1.pos;
				if(temp.rno<temp1.data)k=temp1.lchild;
				else k=temp1.rchild;
				while(k!=-1)
				{
					fi.seekg(k*sizeof(index),ios::beg);
					fi.read((char*)&temp1,sizeof(index));
					if(temp.rno<temp1.data)
						k=temp1.lchild;
					else
						k=temp1.rchild;
					m=temp1.pos;
				}

				fi.seekg(m*sizeof(index),ios::beg);
				fi.read((char*)&temp1,sizeof(index));
				if(temp.rno<temp1.data)
					temp1.lchild=j;
				else
					temp1.rchild=j;
				fi.seekp(m*sizeof(index),ios::beg);
				fi.write((char*)&temp1,sizeof(index));
				j++;
		}
	}
		 ch='y';
		while(ch=='y')
		{
			cout<<"enter rno to be found";
			int x;cin>>x;
			fi.seekg(0,ios::beg);
			fi.read((char*)&in,sizeof(index));
			int k=-1;int g=0;
			if(in.data==x)
			{
				f.seekg(in.pos*sizeof(student),ios::beg);
				f.read((char*)&temp,sizeof(student));
				cout<<"found & course is  "<<temp.course;g=1;
			}

			else if(x<in.data)
				k=in.lchild;
			else
				k=in.rchild;

			while(k!=-1)
			{  fi.seekg(k*sizeof(index),ios::beg);
				fi.read((char*)&in,sizeof(index));
				if(in.data==x)
				{
					f.seekg(in.pos*sizeof(student),ios::beg);
					f.read((char*)&temp,sizeof(student));
					cout<<"found & course is  "<<temp.course;
					g=1;
					break;
				}
				else if(x<in.data)
					k=in.lchild;
				else
					k=in.rchild;
			}
			if(g==0)
				cout<<"not found";
			cout<<"continue?";
			cin>>ch;
		}

	return 0;
}