#include<iostream>
#include<string>
#include"qi.h"
#include<stdlib.h>
using namespace std;

Qizi::Qizi(string name,string color):name(name),color(color){}
//����ʵ��
Che::Che(string color):Qizi("che",color){}
int Che::move(Qipan &qp, int start_x,int start_y, int end_x,int end_y)
{
    int i;
	//��㡢�յ㲻��ͬһ��ֱ����
	if((start_x!=end_x) && (start_y!=end_y))
	{
	    cout<<"��������ֱ��"<<endl;
		return 0;
	}
	//�����ƶ�ʱ���м��Ƿ������ӡ�
	if(start_x==end_x)
	{
	    if(start_y<end_y)
		{
			for(i=start_y+1;i<end_y;i++)
				if(qp.q[start_x][i]->name!="   ")
				{
					cout<<"ˮƽ��·��������"<<endl;
					return 0;
				}
		}
		else
		{
			for(i=end_y+1;i<start_y;i++)
				if(qp.q[start_x][i]->name!="   ")
				{
					cout<<"ˮƽ��·��������"<<endl;
					return 0;
				}
		}
	}
	//�����ƶ�ʱ���м��Ƿ������ӡ�
    if(start_y==end_y)
	{
	    if(start_x<end_x)
		{
			for(i=start_x+1;i<end_x;i++)
				if(qp.q[i][start_y]->name!="   ")
				{
					cout<<"��ֱ��·��������"<<endl;
					return 0;
				}
		}
		else
		{
			for(i=end_x+1;i<start_x;i++)
				if(qp.q[i][start_y]->name!="   ")
				{
					cout<<"��ֱ��·��������"<<endl;
					return 0;
				}
		}
	}
	return 1;
}
//���ʵ��
Ma::Ma(string color):Qizi("ma",color){}
int Ma::move(Qipan &qp, int start_x,int start_y, int end_x,int end_y)
{
	if((start_x-end_x)==2&&abs(start_y-end_y)==1)	
	{	
		if(qp.q[start_x-1][start_y]->name!="   ")
		{	
			cout<<"������"<<endl;
			return 0;	
		}	
		else return 1;
	}
	if((start_x-end_x)==-2&&abs(start_y-end_y)==1)	
	{	
		if(qp.q[start_x+1][start_y]->name!="   ")
		{	
			cout<<"������"<<endl;
			return 0;	
		}	
		else return 1;
	}
	if(abs(start_x-end_x)==1&&(start_y-end_y)==2)	
	{	
		if(qp.q[start_x][start_y-1]->name!="   ")
		{	
			cout<<"������"<<endl;
			return 0;	
		}	
		else return 1;
	}
	if(abs(start_x-end_x)==1&&(start_y-end_y)==-2)	
	{	
		if(qp.q[start_x][start_y+1]->name!="   ")
		{	
			cout<<"������"<<endl;
			return 0;	
		}	
		else return 1;
	}

	else
	{
		cout<<"�߷�����"<<endl;
		return 0;
	}
}


//�ڵ�ʵ��
Pao::Pao(string color):Qizi("pao",color){}
int Pao::move(Qipan &qp, int start_x,int start_y, int end_x,int end_y)
{
  int i,j=1,temp=1;	
  //�����ƶ������
	if(start_x==end_x)
	{
	    if(start_y<end_y)
		{
		    //�����ƶ�ʱ���м��Ƿ������ӡ�
			for(i=start_y+1;i<end_y;i++)
			{
				if(qp.q[start_x][i]->name!="   ")
			        {j=0;temp=i;}
			}
			if(j)
				return 1;
			//�������ӵ�����£�Ŀ��λ���Ƿ��ǶԷ������ӡ�
			else
			{	j=1;
			for(i=temp+1;i<end_y;i++)
			{
				if(qp.q[start_x][i]->name!="   ")
					j=0;
			}
			if(j&&(qp.q[start_x][start_y]->color!=qp.q[end_x][end_y]->color))
	        return 1;
			}
		}
		else
		{
			for(i=start_y-1;i>end_y;i--)
			{
				if(qp.q[start_x][i]->name!="   ")
			        {j=0;temp=i;}
			}
			if(j)
				return 1;
			else
			{	j=1;
			for(i=temp-1;i>end_y;i--)
			{
				if(qp.q[start_x][i]->name!="   ")
					j=0;
			}
			if(j&&(qp.q[start_x][start_y]->color!=qp.q[end_x][end_y]->color))
	        return 1;
			}
		}
	}
	//�����ƶ��������
    if(start_y==end_y)
	{
	   if(start_x<end_x)
		{
			for(i=start_x+1;i<end_x;i++)
			{
				if(qp.q[i][start_y]->name!="   ")
			        {j=0;temp=i;}
			}
			if(j)
				return 1;
			else
			{	j=1;
			for(i=temp+1;i<end_x;i++)
			{
				if(qp.q[i][start_y]->name!="   ")
					j=0;
			}
			if(j&&(qp.q[start_x][start_y]->color!=qp.q[end_x][end_y]->color))
	        return 1;
			}
		}
		else
		{
			for(i=start_x-1;i>end_x;i--)
			{
				if(qp.q[i][start_y]->name!="   ")
			        {j=0;temp=i;}
			}
			if(j)
				return 1;
			else
			{	j=1;
			for(i=temp-1;i>end_x;i--)
			{
				if(qp.q[i][end_y]->name!="   ")
				{j=0;}
			}
			if(j&&(qp.q[start_x][start_y]->color!=qp.q[end_x][end_y]->color))
	        return 1;
			}
		}
	}
  return 0;
}


//���ʵ��
Xiang::Xiang(string color):Qizi("xiang",color){}
int Xiang::move(Qipan &qp, int start_x,int start_y, int end_x,int end_y)
{
    if(qp.q[start_x][start_y]->color=="R")
	{
		if(end_x<=5)
		{	
			if((start_x-end_x)==2&&(start_y-end_y)==2)
			{
				if(qp.q[start_x-1][start_y-1]->name!="   ")
				{
					cout<<"�����"<<endl;
					return 0;
				}
				else return 1;
			}
			else if((start_x-end_x)==2&&(start_y-end_y)==-2)
			{
				if(qp.q[start_x-1][start_y+1]->name!="   ")
				{
					cout<<"�����"<<endl;
					return 0;
				}
				else return 1;
			}
			else if((start_x-end_x)==-2&&(start_y-end_y)==2)
			{
				if(qp.q[start_x+1][start_y-1]->name!="   ")
				{
					cout<<"�����"<<endl;
					return 0;
				}
				else return 1;	
			}
			else if((start_x-end_x)==-2&&(start_y-end_y)==-2)
			{
				if(qp.q[start_x+1][start_y+1]->name!="   ")
				{
					cout<<"�����"<<endl;
					return 0;
				}
				else return 1;
			}		
			else		
			{	
				cout<<"�߷�����"<<endl;	
				return 0;	
			}
		}
		else
		{
		cout<<"�߷�����"<<endl;
		return 0;
		}
	}
	else if(qp.q[start_x][start_y]->color=="B")
	{
		if(end_x>=6)
		{	
			if((start_x-end_x)==2&&(start_y-end_y)==2)
			{
				if(qp.q[start_x-1][start_y-1]->name!="   ")
				{
					cout<<"�����"<<endl;
					return 0;
				}
				else return 1;
			}
			else if((start_x-end_x)==2&&(start_y-end_y)==-2)
			{
				if(qp.q[start_x-1][start_y+1]->name!="   ")
				{
					cout<<"�����"<<endl;
					return 0;
				}
				else return 1;
			}
			else if((start_x-end_x)==-2&&(start_y-end_y)==2)
			{
				if(qp.q[start_x+1][start_y-1]->name!="   ")
				{
					cout<<"�����"<<endl;
					return 0;
				}
				else return 1;	
			}
			else if((start_x-end_x)==-2&&(start_y-end_y)==-2)
			{
				if(qp.q[start_x+1][start_y+1]->name!="   ")
				{
					cout<<"�����"<<endl;
					return 0;
				}
				else return 1;
			}		
			else		
			{	
				cout<<"�߷�����"<<endl;	
				return 0;	
			}
		}
		else
		{
		cout<<"�߷�����"<<endl;
		return 0;
		}
	}
}

	
//ʿ��ʵ��
Shi::Shi(string color):Qizi("shi",color){}
int Shi::move(Qipan &qp, int start_x,int start_y, int end_x,int end_y)
{
  if(((start_x-end_x)*(start_x-end_x)+(start_y-end_y)*(start_y-end_y))==2)
	 {
	  if(end_y<4||end_y>6)
	  {
		  cout<<"Խ�磡";
		  return 0;
	  }
	  else
	  {
		  if(qp.q[start_x][start_y]->color=="R")
			{
			  if(end_x>3)
	          {
		       cout<<"Խ�磡";
		       return 0;
	           }
		     }  
		  else
		    {
              if(end_x<8)
	          {
		       cout<<"Խ�磡";
		       return 0;
	           }
		   }
	    }
	  return 1;
    } 
  return 0;

}
	
//˧��ʵ��
Shuai::Shuai(string color):Qizi("shuai",color){}
int Shuai::move(Qipan &qp, int start_x,int start_y, int end_x,int end_y)
{
	if(end_x>=1&&end_x<=3&&end_y>=4&&end_y<=6)
	{
		if((abs(start_x-end_x)==1&&start_y==end_y)||(abs(start_y-end_y)==1&&start_x==end_x))
		{
			for(int i=start_x+1;i<=10;i++)
			{
				if(qp.q[i][end_y]->name=="   ")
					continue;
				else 
				{
					if(qp.q[i][end_y]->name=="jiang")
						return 0;
					else 
						return 1;
				}
			}
			return 1;
		}
		else 
			return 0;
	}
	else{
		cout<<"�߷�����"<<endl;
		return 0;
	}
}
	
//����ʵ��
Jiang::Jiang(string color):Qizi("jiang",color){}
int Jiang::move(Qipan &qp, int start_x,int start_y, int end_x,int end_y)
{
  if(end_x>=8&&end_x<=10&&end_y>=4&&end_y<=6)
	{
		if((abs(start_x-end_x)==1&&start_y==end_y)||(abs(start_y-end_y)==1&&start_x==end_x))
		{
			for(int i=start_x-1;i>=1;i--)
			{
				if(qp.q[i][end_y]->name=="   ")
					continue;
				else 
				{
					if(qp.q[i][end_y]->name=="shuai")
						return 0;
					else 
						return 1;
				}
			}
			return 1;
		}
		else 
			return 0;
	}
	else
	{
		cout<<"�߷�����"<<endl;
		return 0;
	}
}
	
//����ʵ��
Bing::Bing(string color):Qizi("bing",color){}
int Bing::move(Qipan &qp, int start_x,int start_y, int end_x,int end_y)
{
	if(start_x<6)
	{
		if(end_y==start_y&&(end_x-start_x==1))
			return 1;
	}
	else
	{
		if(end_x-start_x==1||start_y-end_y==1||end_y-start_y==1)
			return 1;
	}
	return 0;
}
	
//���ʵ��
Zu::Zu(string color):Qizi("zu",color){}
int Zu::move(Qipan &qp, int start_x,int start_y, int end_x,int end_y)
{
	if(start_x>5)
	{
		if(end_y==start_y&&(start_x-end_x==1))
			return 1;
	}
	else
	{
		if(start_x-end_x==1||start_y-end_y==1||end_y-start_y==1)
			return 1;
	}
	return 0;

}

//�����ӵ�ʵ��
Space::Space(string color):Qizi("   ",color){}
int Space::move(Qipan &qp, int start_x,int start_y, int end_x,int end_y)
{
  return 1;
}

//����ʵ��
Qipan::Qipan():che_red("R"),ma_red("R"),pao_red("R"),xiang_red("R"),shi_red("R"),shuai_red("R"),
		bing_red("R"),che_black("B"),ma_black("B"),pao_black("B"),xiang_black("B"),
		shi_black("B"),jiang_black("B"),zu_black("B"),space()
{
		int i,j;
	    for(i=1;i<=10;i++)
			for(j=1;j<=9;j++)
			{
			    q[i][j]=&space;
			}
		//��ֵ�췽
	    q[1][1]=q[1][9]=&che_red;
	    q[1][2]=q[1][8]=&ma_red;
	    q[1][3]=q[1][7]=&xiang_red;
	    q[1][4]=q[1][6]=&shi_red;
	    q[1][5]=&shuai_red;
        q[3][2]=q[3][8]=&pao_red;
	    for(i=1;i<=10;i=i+2) q[4][i]=&bing_red;
	    //��ֵ�ڷ�
	    q[10][1]=q[10][9]=&che_black;
	    q[10][2]=q[10][8]=&ma_black;
	    q[10][3]=q[10][7]=&xiang_black;
	    q[10][4]=q[10][6]=&shi_black;
	    q[10][5]=&jiang_black;
        q[8][2]=q[8][8]=&pao_black;
	    for(i=1;i<=10;i=i+2) q[7][i]=&zu_black;
}
int Qipan::exist(int x,int y,string color)//����x��y��color��ɫ����
{
	    if(q[x][y]->color==color)
			return 1;
		else
			return 0;
}
void Qipan::show()
{
	    int i,j;
        for(i=0;i<=9;i++)//���ͷ������ 
		{
			cout.width(7);
		    cout<<i;
		}
		cout<<endl;
		for(i=1;i<=10;i++)
		{
		    cout.width(7);
			cout<<i;  //���ͷ������
			for(j=1;j<=9;j++)
			{
			    cout.width(7);
				cout<<q[i][j]->name+q[i][j]->color;
			}
			cout<<endl;
		}
}