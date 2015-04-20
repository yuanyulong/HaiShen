#include "stdafx.h"
#include "User_Geo.h"
User_Geo::User_Geo()
{
	this->user_id = "";
	this->geohash = "";
	this->buy_count = 0;
	this->workday_buy_count = 0;
	this->weekend_buy_count = 0;
	this->festival_buy_count = 0;
}
/*
string user_id;//�û����
string geohash;//�����ַ
int buy_count;//�û��ڴ˵�ַ������Ʒ������
int workday_buy_count;//�û������չ������
int workend_buy_count;//�û���ĩ�������
int festival_buy_count;//�û����չ������*/
string User_Geo::toString()
{
	char str_buy_count[20];
	sprintf(str_buy_count,"%d",this->buy_count);
	char str_workday_buy_count[20];
	sprintf(str_workday_buy_count,"%d",this->workday_buy_count);
	char str_weekend_buy_count[20];
	sprintf(str_weekend_buy_count,"%d",this->weekend_buy_count);
	char str_festival_buy_count[20];
	sprintf(str_festival_buy_count,"%d",this->festival_buy_count);
 	return this->user_id+","+this->geohash+","+string(str_buy_count)+","+string(str_workday_buy_count)+","+string(str_weekend_buy_count)+"��"+string(str_festival_buy_count)+"\r\n";
}