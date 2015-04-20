#include "stdafx.h"
#include "ItemAttr.h"
ItemAttr::ItemAttr()
{
	this->item_id = "";
	this->geohash = "";
	this->item_category = "";
	this->buy_count = 0;
	this->workday_buy_count = 0;
	this->weekend_buy_count = 0;
	this->festival_buy_count = 0;
	this->clicked_count = 0;
	this->collected_count = 0;
	this->addedincart_count = 0;
}
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
string ItemAttr::toString()
{
	char str_buy_count[20];
	sprintf(str_buy_count,"%d",this->buy_count);
	char str_workday_buy_count[20];
	sprintf(str_workday_buy_count,"%d",this->workday_buy_count);
	char str_weekend_buy_count[20];
	sprintf(str_weekend_buy_count,"%d",this->weekend_buy_count);
	char str_festival_buy_count[20];
	sprintf(str_festival_buy_count,"%d",this->festival_buy_count);
	char str_clicked_count[20];
	sprintf(str_clicked_count,"%d",this->clicked_count);
	char str_collected_count[20];
	sprintf(str_collected_count,"%d",this->collected_count);
	char str_addedincart_count[20];
	sprintf(str_addedincart_count,"%d",this->addedincart_count);
	return this->item_id+","+this->geohash+","+this->item_category+","
		+str_buy_count+","+str_workday_buy_count+","+str_weekend_buy_count+","
		+str_festival_buy_count+","+str_clicked_count+","+str_collected_count+","
		+str_addedincart_count+"\r\n";
}