#include "stdafx.h"
#include "User_Item.h"
User_Item::User_Item()
{
	this->user_id = "";
	this->item_id = "";
	this->item_category = "";
	this->buy_count = 0;
	this->workday_buy_count = 0;
	this->weekend_buy_count = 0;
	this->festival_buy_count = 0;
}
/*
string user_id;//�û����
string item_id;//��Ʒ������
string item_category;//��Ʒ�������
int buy_count; //��Ʒ�����û�����Ĵ���
int workday_buy_count;//��Ʒ�����ձ����û�����Ĵ���
int workend_buy_count;//��Ʒ��ĩ�����û�����Ĵ���
int festival_buy_count;//��Ʒ���ձ����û�����Ĵ���
*/
string User_Item::toString()
{
	char str_buy_count[20];
	sprintf(str_buy_count,"%d",this->buy_count);
	char str_workday_buy_count[20];
	sprintf(str_workday_buy_count,"%d",this->workday_buy_count);
	char str_weekend_buy_count[20];
	sprintf(str_weekend_buy_count,"%d",this->weekend_buy_count);
	char str_festival_buy_count[20];
	sprintf(str_festival_buy_count,"%d",this->festival_buy_count);
	return this->user_id+","+this->item_id+","+this->item_category+","+str_buy_count+","+str_workday_buy_count+","+str_weekend_buy_count+","+str_festival_buy_count+"\n";
}
