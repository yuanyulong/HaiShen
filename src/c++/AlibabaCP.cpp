// AlibabaCP.cpp : 定义控制台应用程序的入口点。
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
//判断输入的年月日是否有效
bool is_valid(int year,int month,int day)
{
	if(month<0||month>12||day<0||day>31||year<0)
		return false;
	return true;
}
//根据年月日计算星期几;返回值为1就是星期一。。。
int calculate(int year,int month,int day)
{
	int week = 0;
	if(month==1){month=13;year--;}
	if(month==2){month=14;year--;}
	if((year<1752)||((year==1752)&&(month<9))||((year==1752)&&(month==9)&&(day<3)))//判断是否在1752年9月3日之前
		week = (day+2*month+3*(month+1)/5+year+year/4+5)%7;//1752年9月3日之前的公式
	else
		week = (day+2*month+3*(month+1)/5+year+year/4-year/100+year/400)%7;//1752年9月3日之后的公式

	return week+1;
}

//字符串分隔函数
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
map<ItemAttr,ItemAttr> map_tbl_item_attr;//商品属性表
map<UserAttr,UserAttr> map_tbl_user_attr;//用户属性表
map<User_Item,User_Item> map_tbl_user_item;//用户-商品购买表
map<User_Geo,User_Geo> map_tbl_user_geo;//用户-购买地址表
*/
/*
string item_id;//商品编号
string geohash;//商品所属位置
string item_category;//商品所属类别
int buy_count;//商品被购买的次数
int workday_buy_count;//商品工作日被购买的次数
int weekend_buy_count;//商品周末被购买的次数
int festival_buy_count;//商品节日被购买的次数
int clicked_count;//商品被点击的次数
int collected_count;//商品被收藏的次数
int addedincart_count;//商品被加入购物车的次数*/
//将商品属性表中的数据写入商品属性表中
void writeToFile_item_attr(map<ItemAttr,ItemAttr> map_tbl_item_attr,string path_item_attr)
{
	ofstream fout(path_item_attr);
	if(!fout)
		cout<<"打开文件失败"<<endl;
	fout<<"item_id,geohash,item_category,buy_count,workday_buy_count,weekend_buy_count,festival_buy_count,clicked_count,collected_count,addedincart_count\r\n";
	map<ItemAttr,ItemAttr>::iterator itr_item_attr;
	for(itr_item_attr = map_tbl_item_attr.begin();itr_item_attr != map_tbl_item_attr.end();itr_item_attr++)
	{
		fout<<itr_item_attr->second.toString();
	}
	fout.close();
}
//将用户属性表中的数据写入用户属性表中
/*
string user_id;//用户编号
int click_count;//用户总的点击次数
int collect_count;//用户总的收藏次数
int addincart_count;//用户加入购物车的次数
int buy_count;//用户总的购买次数
int workday_buy_count;//用户工作日购买的次数
int weekend_buy_count;//用户周末购买的次数
int festival_buy_count;//用户节日购买的次数
*/
void writeToFile_user_attr(map<UserAttr,UserAttr> map_tbl_user_attr,string path_user_attr)
{
	ofstream fout(path_user_attr);
	if(!fout)
		cout<<"打开文件失败"<<endl;
	fout<<"user_id,click_count,collect_count,addincart_count,buy_count,workday_buy_count,weekend_buy_count,festival_count\r\n";
	map<UserAttr,UserAttr>::iterator itr_user_attr;
	for(itr_user_attr = map_tbl_user_attr.begin();itr_user_attr != map_tbl_user_attr.end();itr_user_attr++)
	{
		fout<<itr_user_attr->second.toString();
	}
}
//将用户-商品购买表中的数据写入用户商品购买表中
/*
string user_id;//用户编号
string item_id;//商品的名字
string item_category;//商品所属类别
int buy_count; //商品被此用户购买的次数
int workday_buy_count;//商品工作日被此用户购买的次数
int weekend_buy_count;//商品周末被此用户购买的次数
int festival_buy_count;//商品节日被此用户购买的次数
*/
void writeToFile_user_item(map<User_Item,User_Item> map_tbl_user_item,string path_user_item)
{
	ofstream fout(path_user_item);
	if(!fout)
		cout<<"打开文件失败"<<endl;
	fout<<"user_id,item_id,item_category,buy_count,workday_buy_count,weekend_buy_count,festival_buy_count\r\n";
	map<User_Item,User_Item>::iterator itr_user_item;
	for(itr_user_item = map_tbl_user_item.begin();itr_user_item != map_tbl_user_item.end();itr_user_item++)
	{
		fout<<itr_user_item->second.toString();
	}
}
//将用户-购买地址表中的数据写入用户购买地址表中
/*
string user_id;//用户编号
string geohash;//购买地址
int buy_count;//用户在此地址购买商品的数量
int workday_buy_count;//用户工作日购买次数
int weekend_buy_count;//用户周末购买次数
int festival_buy_count;//用户节日购买次数*/
void writeToFile_user_geo(map<User_Geo,User_Geo> map_tbl_user_geo,string path_user_geo)
{
	ofstream fout(path_user_geo);
	if(!fout)
		cout<<"打开文件失败"<<endl;
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
	map<ItemAttr,ItemAttr> map_tbl_item_attr;//商品属性表
	map<UserAttr,UserAttr> map_tbl_user_attr;//用户属性表
	map<User_Item,User_Item> map_tbl_user_item;//用户-商品购买表
	map<User_Geo,User_Geo> map_tbl_user_geo;//用户-购买地址表

//四张表的存储地址
	string path_item_attr = "D:\\data\\vs2010Project\\AlibabaCP\\tbl_item_attr.csv";
	string path_user_attr = "D:\\data\\vs2010Project\\AlibabaCP\\tbl_user_attr.csv";
	string path_user_item = "D:\\data\\vs2010Project\\AlibabaCP\\tbl_user_item.csv";
	string path_user_geo = "D:\\data\\vs2010Project\\AlibabaCP\\tbl_user_geo.csv";

	long beginTime = clock();//获得开始时间,单位为毫秒

	getline(fin,value);
	while(fin.good())
	{
		getline(fin,value);//获取文件的一行
		list<string> list_str = split(value,",");//使用","将字符串进行分隔
		list<string>::iterator itor_str = list_str.begin();
		user_id = *itor_str++;//获取文件一行中的user_id
		item_id = *itor_str++;//获取文件一行中的item_id
		behavior_type = atoi((*itor_str).c_str());//获取文件一行中的behavior_type
		user_geohash = *++itor_str;//获取文件一行中的user_geohash
		itor_str++;
		item_category = *itor_str++;//获取文件一行中的item_category
		time = *itor_str;
		date = time.substr(0,time.find_first_of(" "));

		int nYear;
		int nMonth;
		int nDate;
		int nHour;
		sscanf(time.c_str(),"%d-%d-%d %d",&nYear,&nMonth,&nDate,&nHour);
		
//生成四张表的表项
//在tbl_item_attr属性表中添加一个新的项
		ItemAttr itmattr;
		itmattr.item_id = item_id;		
		itmattr.item_category = item_category;

		map<ItemAttr,ItemAttr>::iterator iter_item_attr = map_tbl_item_attr.find(itmattr);
		if(iter_item_attr != map_tbl_item_attr.end())
		{
			if(behavior_type == 4)//如果消费行为是购买的消费行为
			{
				iter_item_attr->second.buy_count++;//商品总的购买次数加1
				if((nMonth == 12)&&(nDate == 12))
				{
					iter_item_attr->second.festival_buy_count++;//特殊节日中商品总的购买次数加1
				}else
				{
					if(is_valid(nYear,nMonth,nDate))
					{
						int dayofweek = calculate(nYear,nMonth,nDate);
						if((dayofweek>0&&dayofweek<5)||(dayofweek==5&&dayofweek<18))
						{
							iter_item_attr->second.workday_buy_count++;//商品工作日被购买的次数加1
						}else
						{
							iter_item_attr->second.weekend_buy_count++;//商品周末被购买的次数加1
						}
					}else
					{
						cout<<"日期格式不正确!!"<<endl;
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
					itmattr.festival_buy_count++;//特殊节日中商品总的购买次数加1
				}else
				{
					if(is_valid(nYear,nMonth,nDate))
					{
						int dayofweek = calculate(nYear,nMonth,nDate);
						if((dayofweek>0&&dayofweek<5)||(dayofweek==5&&dayofweek<18))
						{
							itmattr.workday_buy_count++;//商品工作日被购买的次数加1
						}else
						{
							itmattr.weekend_buy_count++;//商品周末被购买的次数加1
						}
					}else
					{
						cout<<"日期格式不正确!!"<<endl;
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

//在tbl_user_attr表中添加一个新的项
		UserAttr usrattr;
		usrattr.user_id = user_id;
		map<UserAttr,UserAttr>::iterator iter_user_attr = map_tbl_user_attr.find(usrattr);
		if(iter_user_attr != map_tbl_user_attr.end())
		{
			if(behavior_type == 4)//如果消费行为是购买的消费行为
			{
				iter_user_attr->second.buy_count++;//商品总的购买次数加1
				if((nMonth == 12)&&(nDate == 12))
				{
					iter_user_attr->second.festival_buy_count++;//特殊节日中商品总的购买次数加1
				}else
				{
					if(is_valid(nYear,nMonth,nDate))
					{
						int dayofweek = calculate(nYear,nMonth,nDate);
						if((dayofweek>0&&dayofweek<5)||(dayofweek==5&&dayofweek<18))
						{
							iter_user_attr->second.workday_buy_count++;//商品工作日被购买的次数加1
						}else
						{
							iter_user_attr->second.weekend_buy_count++;//商品周末被购买的次数加1
						}
					}else
					{
						cout<<"日期格式不正确!!"<<endl;
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
					usrattr.festival_buy_count++;//特殊节日中商品总的购买次数加1
				}else
				{
					if(is_valid(nYear,nMonth,nDate))
					{
						int dayofweek = calculate(nYear,nMonth,nDate);
						if((dayofweek>0&&dayofweek<5)||(dayofweek==5&&dayofweek<18))
						{
							usrattr.workday_buy_count++;//商品工作日被购买的次数加1
						}else
						{
							usrattr.weekend_buy_count++;//商品周末被购买的次数加1
						}
					}else
					{
						cout<<"日期格式不正确!!"<<endl;
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

//在tbl_user_item表中添加一个新的项
		User_Item usritm;
		usritm.user_id = user_id;
		usritm.item_id = item_id;
		usritm.item_category = item_category;
		map<User_Item,User_Item>::iterator iter_user_item = map_tbl_user_item.find(usritm);
		if(iter_user_item != map_tbl_user_item.end())
		{
			if(behavior_type == 4)
			{
				iter_user_item->second.buy_count++;//商品被此用户购买的次数
				if((nMonth == 12)&&(nDate == 12))
				{
					iter_user_item->second.festival_buy_count++;//特殊节日中商品总的购买次数加1
				}else
				{
					if(is_valid(nYear,nMonth,nDate))
					{
						int dayofweek = calculate(nYear,nMonth,nDate);
						if((dayofweek>0&&dayofweek<5)||(dayofweek==5&&dayofweek<18))
						{
							iter_user_item->second.workday_buy_count++;//商品工作日被购买的次数加1
						}else
						{
							iter_user_item->second.weekend_buy_count++;//商品周末被购买的次数加1
						}
					}else
					{
						cout<<"日期格式不正确!!"<<endl;
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
					usritm.festival_buy_count++;//特殊节日中商品总的购买次数加1
				}else
				{
					if(is_valid(nYear,nMonth,nDate))
					{
						int dayofweek = calculate(nYear,nMonth,nDate);
						if((dayofweek>0&&dayofweek<5)||(dayofweek==5&&dayofweek<18))
						{
							usritm.workday_buy_count++;//商品工作日被购买的次数加1
						}else
						{
							usritm.weekend_buy_count++;//商品周末被购买的次数加1
						}
					}else
					{
						cout<<"日期格式不正确!!"<<endl;
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
					iter_user_geo->second.festival_buy_count++;//特殊节日中商品总的购买次数加1
				}else
				{
					if(is_valid(nYear,nMonth,nDate))
					{
						int dayofweek = calculate(nYear,nMonth,nDate);
						if((dayofweek>0&&dayofweek<5)||(dayofweek==5&&dayofweek<18))
						{
							iter_user_geo->second.workday_buy_count++;//商品工作日被购买的次数加1
						}else
						{
							iter_user_geo->second.weekend_buy_count++;//商品周末被购买的次数加1
						}
					}else
					{
						cout<<"日期格式不正确!!"<<endl;
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
					usrgeo.festival_buy_count++;//特殊节日中商品总的购买次数加1
				}else
				{
					if(is_valid(nYear,nMonth,nDate))
					{
						int dayofweek = calculate(nYear,nMonth,nDate);
						if((dayofweek>0&&dayofweek<5)||(dayofweek==5&&dayofweek<18))
						{
							usrgeo.workday_buy_count++;//商品工作日被购买的次数加1
						}else
						{
							usrgeo.weekend_buy_count++;//商品周末被购买的次数加1
						}
					}else
					{
						cout<<"日期格式不正确!!"<<endl;
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

	long endTime = clock();//获得结束时间
	cout<<"running time:"<<endTime-beginTime<<endl;
	system("pause");
	return 0;
}

