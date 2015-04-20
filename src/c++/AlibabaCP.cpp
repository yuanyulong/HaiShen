// AlibabaCP.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <vector>
#include <time.h>
//#include <locale.h>

#include "ItemAttr.h"
#include "UserAttr.h"
#include "User_Geo.h"
#include "User_Item.h"
using namespace std;
//�ж�������������Ƿ���Ч
bool is_valid(int year,int month,int day)
{
	if(month<0||month>12||day<0||day>31||year<0)
		return false;
	return true;
}
//���������ռ������ڼ�;����ֵΪ1��������һ������
int calculate(int year,int month,int day)
{
	int week = 0;
	if(month==1){month=13;year--;}
	if(month==2){month=14;year--;}
	if((year<1752)||((year==1752)&&(month<9))||((year==1752)&&(month==9)&&(day<3)))//�ж��Ƿ���1752��9��3��֮ǰ
		week = (day+2*month+3*(month+1)/5+year+year/4+5)%7;//1752��9��3��֮ǰ�Ĺ�ʽ
	else
		week = (day+2*month+3*(month+1)/5+year+year/4-year/100+year/400)%7;//1752��9��3��֮��Ĺ�ʽ

	return week+1;
}

//�ַ����ָ�����
list<string> split(string str,string separator)
{
	list<string> result;
	int cutAt;
	while((cutAt = str.find_first_of(separator)) != str.npos)
	{
		if(cutAt>0)
		{
			result.push_back(str.substr(0,cutAt));
		}else{
			result.push_back("");
		}
		str = str.substr(cutAt+1);
	}
	if(str.length()>0)
	{
		result.push_back(str);
	}else
	{
		result.push_back("");
	}
	return result;
		
}
/*
string path_item_attr = "D:\\data\\vs2010Project\\AlibabaCP\\tbl_item_attr.csv";
string path_user_attr = "D:\\data\\vs2010Project\\AlibabaCP\\tbl_user_attr.csv";
string path_user_item = "D:\\data\\vs2010Project\\AlibabaCP\\tbl_user_item.csv";
string path_user_geo = "D:\\data\\vs2010Project\\AlibabaCP\\tbl_user_geo.csv";
map<ItemAttr,ItemAttr> map_tbl_item_attr;//��Ʒ���Ա�
map<UserAttr,UserAttr> map_tbl_user_attr;//�û����Ա�
map<User_Item,User_Item> map_tbl_user_item;//�û�-��Ʒ�����
map<User_Geo,User_Geo> map_tbl_user_geo;//�û�-�����ַ��
*/
/*
string item_id;//��Ʒ���
string geohash;//��Ʒ����λ��
string item_category;//��Ʒ�������
int buy_count;//��Ʒ������Ĵ���
int workday_buy_count;//��Ʒ�����ձ�����Ĵ���
int weekend_buy_count;//��Ʒ��ĩ������Ĵ���
int festival_buy_count;//��Ʒ���ձ�����Ĵ���
int clicked_count;//��Ʒ������Ĵ���
int collected_count;//��Ʒ���ղصĴ���
int addedincart_count;//��Ʒ�����빺�ﳵ�Ĵ���*/
//����Ʒ���Ա��е�����д����Ʒ���Ա���
void writeToFile_item_attr(map<ItemAttr,ItemAttr> map_tbl_item_attr,string path_item_attr)
{
	ofstream fout(path_item_attr);
	if(!fout)
		cout<<"���ļ�ʧ��"<<endl;
	fout<<"item_id,geohash,item_category,buy_count,workday_buy_count,weekend_buy_count,festival_buy_count,clicked_count,collected_count,addedincart_count\r\n";
	map<ItemAttr,ItemAttr>::iterator itr_item_attr;
	for(itr_item_attr = map_tbl_item_attr.begin();itr_item_attr != map_tbl_item_attr.end();itr_item_attr++)
	{
		fout<<itr_item_attr->second.toString();
	}
	fout.close();
}
//���û����Ա��е�����д���û����Ա���
/*
string user_id;//�û����
int click_count;//�û��ܵĵ������
int collect_count;//�û��ܵ��ղش���
int addincart_count;//�û����빺�ﳵ�Ĵ���
int buy_count;//�û��ܵĹ������
int workday_buy_count;//�û������չ���Ĵ���
int weekend_buy_count;//�û���ĩ����Ĵ���
int festival_buy_count;//�û����չ���Ĵ���
*/
void writeToFile_user_attr(map<UserAttr,UserAttr> map_tbl_user_attr,string path_user_attr)
{
	ofstream fout(path_user_attr);
	if(!fout)
		cout<<"���ļ�ʧ��"<<endl;
	fout<<"user_id,click_count,collect_count,addincart_count,buy_count,workday_buy_count,weekend_buy_count,festival_count\r\n";
	map<UserAttr,UserAttr>::iterator itr_user_attr;
	for(itr_user_attr = map_tbl_user_attr.begin();itr_user_attr != map_tbl_user_attr.end();itr_user_attr++)
	{
		fout<<itr_user_attr->second.toString();
	}
}
//���û�-��Ʒ������е�����д���û���Ʒ�������
/*
string user_id;//�û����
string item_id;//��Ʒ������
string item_category;//��Ʒ�������
int buy_count; //��Ʒ�����û�����Ĵ���
int workday_buy_count;//��Ʒ�����ձ����û�����Ĵ���
int weekend_buy_count;//��Ʒ��ĩ�����û�����Ĵ���
int festival_buy_count;//��Ʒ���ձ����û�����Ĵ���
*/
void writeToFile_user_item(map<User_Item,User_Item> map_tbl_user_item,string path_user_item)
{
	ofstream fout(path_user_item);
	if(!fout)
		cout<<"���ļ�ʧ��"<<endl;
	fout<<"user_id,item_id,item_category,buy_count,workday_buy_count,weekend_buy_count,festival_buy_count\r\n";
	map<User_Item,User_Item>::iterator itr_user_item;
	for(itr_user_item = map_tbl_user_item.begin();itr_user_item != map_tbl_user_item.end();itr_user_item++)
	{
		fout<<itr_user_item->second.toString();
	}
}
//���û�-�����ַ���е�����д���û������ַ����
/*
string user_id;//�û����
string geohash;//�����ַ
int buy_count;//�û��ڴ˵�ַ������Ʒ������
int workday_buy_count;//�û������չ������
int weekend_buy_count;//�û���ĩ�������
int festival_buy_count;//�û����չ������*/
void writeToFile_user_geo(map<User_Geo,User_Geo> map_tbl_user_geo,string path_user_geo)
{
	ofstream fout(path_user_geo);
	if(!fout)
		cout<<"���ļ�ʧ��"<<endl;
	fout<<"user_id,geohash,buy_count,workday_buy_count,weekend_buy_count,festival_buy_count\r\n";
	map<User_Geo,User_Geo>::iterator itr_user_geo;
	for(itr_user_geo = map_tbl_user_geo.begin();itr_user_geo != map_tbl_user_geo.end();itr_user_geo++)
	{
		fout<<itr_user_geo->second.toString();
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream fin("D:\\Users\\yuanyulong\\workspace\\AlibabaComp\\files\\tianchi_mobile_recommend_train_user\\tianchi_mobile_recommend_train_user.csv",ios::in);
	string value;
	int i = 0;
	string user_id;
	string item_id;
	int behavior_type;
	string user_geohash;
	string item_category;
	string time;
	string date;
	string d;
	string hour;
	map<string,vector<string>> date_file;
	map<ItemAttr,ItemAttr> map_tbl_item_attr;//��Ʒ���Ա�
	map<UserAttr,UserAttr> map_tbl_user_attr;//�û����Ա�
	map<User_Item,User_Item> map_tbl_user_item;//�û�-��Ʒ�����
	map<User_Geo,User_Geo> map_tbl_user_geo;//�û�-�����ַ��

//���ű�Ĵ洢��ַ
	string path_item_attr = "D:\\data\\vs2010Project\\AlibabaCP\\tbl_item_attr.csv";
	string path_user_attr = "D:\\data\\vs2010Project\\AlibabaCP\\tbl_user_attr.csv";
	string path_user_item = "D:\\data\\vs2010Project\\AlibabaCP\\tbl_user_item.csv";
	string path_user_geo = "D:\\data\\vs2010Project\\AlibabaCP\\tbl_user_geo.csv";

	long beginTime = clock();//��ÿ�ʼʱ��,��λΪ����

	getline(fin,value);
	while(fin.good())
	{
		getline(fin,value);//��ȡ�ļ���һ��
		list<string> list_str = split(value,",");//ʹ��","���ַ������зָ�
		list<string>::iterator itor_str = list_str.begin();
		user_id = *itor_str++;//��ȡ�ļ�һ���е�user_id
		item_id = *itor_str++;//��ȡ�ļ�һ���е�item_id
		behavior_type = atoi((*itor_str).c_str());//��ȡ�ļ�һ���е�behavior_type
		user_geohash = *++itor_str;//��ȡ�ļ�һ���е�user_geohash
		itor_str++;
		item_category = *itor_str++;//��ȡ�ļ�һ���е�item_category
		time = *itor_str;
		date = time.substr(0,time.find_first_of(" "));

		int nYear;
		int nMonth;
		int nDate;
		int nHour;
		sscanf(time.c_str(),"%d-%d-%d %d",&nYear,&nMonth,&nDate,&nHour);
		
//�������ű�ı���
//��tbl_item_attr���Ա������һ���µ���
		ItemAttr itmattr;
		itmattr.item_id = item_id;		
		itmattr.item_category = item_category;

		map<ItemAttr,ItemAttr>::iterator iter_item_attr = map_tbl_item_attr.find(itmattr);
		if(iter_item_attr != map_tbl_item_attr.end())
		{
			if(behavior_type == 4)//���������Ϊ�ǹ����������Ϊ
			{
				iter_item_attr->second.buy_count++;//��Ʒ�ܵĹ��������1
				if((nMonth == 12)&&(nDate == 12))
				{
					iter_item_attr->second.festival_buy_count++;//�����������Ʒ�ܵĹ��������1
				}else
				{
					if(is_valid(nYear,nMonth,nDate))
					{
						int dayofweek = calculate(nYear,nMonth,nDate);
						if((dayofweek>0&&dayofweek<5)||(dayofweek==5&&dayofweek<18))
						{
							iter_item_attr->second.workday_buy_count++;//��Ʒ�����ձ�����Ĵ�����1
						}else
						{
							iter_item_attr->second.weekend_buy_count++;//��Ʒ��ĩ������Ĵ�����1
						}
					}else
					{
						cout<<"���ڸ�ʽ����ȷ!!"<<endl;
					}
				}
				
			}else if(behavior_type == 1)
			{
				iter_item_attr->second.clicked_count++;
			}else if(behavior_type == 2)
			{
				iter_item_attr->second.collected_count++;
			}else
			{
				iter_item_attr->second.addedincart_count++;
			}
			
		}else
		{
			if(behavior_type == 4)
			{
				itmattr.buy_count++;
				if((nMonth == 12)&&(nDate == 12))
				{
					itmattr.festival_buy_count++;//�����������Ʒ�ܵĹ��������1
				}else
				{
					if(is_valid(nYear,nMonth,nDate))
					{
						int dayofweek = calculate(nYear,nMonth,nDate);
						if((dayofweek>0&&dayofweek<5)||(dayofweek==5&&dayofweek<18))
						{
							itmattr.workday_buy_count++;//��Ʒ�����ձ�����Ĵ�����1
						}else
						{
							itmattr.weekend_buy_count++;//��Ʒ��ĩ������Ĵ�����1
						}
					}else
					{
						cout<<"���ڸ�ʽ����ȷ!!"<<endl;
					}
				}
			}else if(behavior_type == 1)
			{
				itmattr.clicked_count++;
			}else if(behavior_type == 2)
			{
				itmattr.collected_count++;
			}else if(behavior_type == 3)
			{
				itmattr.addedincart_count++;
			}
			map_tbl_item_attr.insert(make_pair(itmattr,itmattr));
		}

//��tbl_user_attr�������һ���µ���
		UserAttr usrattr;
		usrattr.user_id = user_id;
		map<UserAttr,UserAttr>::iterator iter_user_attr = map_tbl_user_attr.find(usrattr);
		if(iter_user_attr != map_tbl_user_attr.end())
		{
			if(behavior_type == 4)//���������Ϊ�ǹ����������Ϊ
			{
				iter_user_attr->second.buy_count++;//��Ʒ�ܵĹ��������1
				if((nMonth == 12)&&(nDate == 12))
				{
					iter_user_attr->second.festival_buy_count++;//�����������Ʒ�ܵĹ��������1
				}else
				{
					if(is_valid(nYear,nMonth,nDate))
					{
						int dayofweek = calculate(nYear,nMonth,nDate);
						if((dayofweek>0&&dayofweek<5)||(dayofweek==5&&dayofweek<18))
						{
							iter_user_attr->second.workday_buy_count++;//��Ʒ�����ձ�����Ĵ�����1
						}else
						{
							iter_user_attr->second.weekend_buy_count++;//��Ʒ��ĩ������Ĵ�����1
						}
					}else
					{
						cout<<"���ڸ�ʽ����ȷ!!"<<endl;
					}
				}

			}else if(behavior_type == 1)
			{
				iter_user_attr->second.click_count++;
			}else if(behavior_type == 2)
			{
				iter_user_attr->second.collect_count++;
			}else
			{
				iter_user_attr->second.addincart_count++;
			}
		}else
		{
			if(behavior_type == 4)
			{
				usrattr.buy_count++;
				if((nMonth == 12)&&(nDate == 12))
				{
					usrattr.festival_buy_count++;//�����������Ʒ�ܵĹ��������1
				}else
				{
					if(is_valid(nYear,nMonth,nDate))
					{
						int dayofweek = calculate(nYear,nMonth,nDate);
						if((dayofweek>0&&dayofweek<5)||(dayofweek==5&&dayofweek<18))
						{
							usrattr.workday_buy_count++;//��Ʒ�����ձ�����Ĵ�����1
						}else
						{
							usrattr.weekend_buy_count++;//��Ʒ��ĩ������Ĵ�����1
						}
					}else
					{
						cout<<"���ڸ�ʽ����ȷ!!"<<endl;
					}
				}
			}else if(behavior_type == 1)
			{
				usrattr.click_count++;
			}else if(behavior_type == 2)
			{
				usrattr.collect_count++;
			}else if(behavior_type == 3)
			{
				usrattr.addincart_count++;
			}
			map_tbl_user_attr.insert(make_pair(usrattr,usrattr));
		}

//��tbl_user_item�������һ���µ���
		User_Item usritm;
		usritm.user_id = user_id;
		usritm.item_id = item_id;
		usritm.item_category = item_category;
		map<User_Item,User_Item>::iterator iter_user_item = map_tbl_user_item.find(usritm);
		if(iter_user_item != map_tbl_user_item.end())
		{
			if(behavior_type == 4)
			{
				iter_user_item->second.buy_count++;//��Ʒ�����û�����Ĵ���
				if((nMonth == 12)&&(nDate == 12))
				{
					iter_user_item->second.festival_buy_count++;//�����������Ʒ�ܵĹ��������1
				}else
				{
					if(is_valid(nYear,nMonth,nDate))
					{
						int dayofweek = calculate(nYear,nMonth,nDate);
						if((dayofweek>0&&dayofweek<5)||(dayofweek==5&&dayofweek<18))
						{
							iter_user_item->second.workday_buy_count++;//��Ʒ�����ձ�����Ĵ�����1
						}else
						{
							iter_user_item->second.weekend_buy_count++;//��Ʒ��ĩ������Ĵ�����1
						}
					}else
					{
						cout<<"���ڸ�ʽ����ȷ!!"<<endl;
					}
				}
			}
			
		}else
		{
			if(behavior_type == 4)
			{
				usritm.buy_count++;
				if((nMonth == 12)&&(nDate == 12))
				{
					usritm.festival_buy_count++;//�����������Ʒ�ܵĹ��������1
				}else
				{
					if(is_valid(nYear,nMonth,nDate))
					{
						int dayofweek = calculate(nYear,nMonth,nDate);
						if((dayofweek>0&&dayofweek<5)||(dayofweek==5&&dayofweek<18))
						{
							usritm.workday_buy_count++;//��Ʒ�����ձ�����Ĵ�����1
						}else
						{
							usritm.weekend_buy_count++;//��Ʒ��ĩ������Ĵ�����1
						}
					}else
					{
						cout<<"���ڸ�ʽ����ȷ!!"<<endl;
					}
				}
			}
				map_tbl_user_item.insert(make_pair(usritm,usritm));
		}

		User_Geo usrgeo;
		usrgeo.user_id = user_id;
		usrgeo.geohash = user_geohash;
		map<User_Geo,User_Geo>::iterator iter_user_geo = map_tbl_user_geo.find(usrgeo);
		if(iter_user_geo != map_tbl_user_geo.end())
		{
			if(behavior_type == 4)
			{
				iter_user_geo->second.buy_count++;
				if((nMonth == 12)&&(nDate == 12))
				{
					iter_user_geo->second.festival_buy_count++;//�����������Ʒ�ܵĹ��������1
				}else
				{
					if(is_valid(nYear,nMonth,nDate))
					{
						int dayofweek = calculate(nYear,nMonth,nDate);
						if((dayofweek>0&&dayofweek<5)||(dayofweek==5&&dayofweek<18))
						{
							iter_user_geo->second.workday_buy_count++;//��Ʒ�����ձ�����Ĵ�����1
						}else
						{
							iter_user_geo->second.weekend_buy_count++;//��Ʒ��ĩ������Ĵ�����1
						}
					}else
					{
						cout<<"���ڸ�ʽ����ȷ!!"<<endl;
					}
				}
			}
		}else
		{
			if(behavior_type == 4)
			{
				usrgeo.buy_count++;
				if((nMonth == 12)&&(nDate == 12))
				{
					usrgeo.festival_buy_count++;//�����������Ʒ�ܵĹ��������1
				}else
				{
					if(is_valid(nYear,nMonth,nDate))
					{
						int dayofweek = calculate(nYear,nMonth,nDate);
						if((dayofweek>0&&dayofweek<5)||(dayofweek==5&&dayofweek<18))
						{
							usrgeo.workday_buy_count++;//��Ʒ�����ձ�����Ĵ�����1
						}else
						{
							usrgeo.weekend_buy_count++;//��Ʒ��ĩ������Ĵ�����1
						}
					}else
					{
						cout<<"���ڸ�ʽ����ȷ!!"<<endl;
					}
				}				
			}
			map_tbl_user_geo.insert(make_pair(usrgeo,usrgeo));
		}

		
		/*cout<<nYear<<" "<<nMonth<<" "<<nDate<<" "<<nHour<<endl;
		if(i>10)
		{
			system("pause");
		}
		i++;*/
	}

	//writeToFile_item_attr(map_tbl_item_attr,path_item_attr);
	//writeToFile_user_attr(map_tbl_user_attr,path_user_attr);
	//writeToFile_user_item( map_tbl_user_item,path_user_item);
	//writeToFile_user_geo(map_tbl_user_geo,path_user_geo);

	long endTime = clock();//��ý���ʱ��
	cout<<"running time:"<<endTime-beginTime<<endl;
	system("pause");
	return 0;
}

