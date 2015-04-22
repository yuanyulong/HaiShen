#include "stdafx.h"
#include "UserAttr.h"
UserAttr::UserAttr()
{
	this->user_id = "";
	this->click_count = 0;
	this->collect_count = 0;
	this->addincart_count = 0;
	this->buy_count = 0;
	this->workday_buy_count = 0;
	this->weekend_buy_count = 0;
	this->festival_buy_count = 0;
}
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
string UserAttr::toString()
{
	char str_click_count[20];
	sprintf(str_click_count,"%d",this->click_count);
	char str_collect_count[20];
	sprintf(str_collect_count,"%d",this->collect_count);
	char str_addincart_count[20];
	sprintf(str_addincart_count,"%d",this->addincart_count);
	char str_buy_count[20];
	sprintf(str_buy_count,"%d",this->buy_count);
	char str_workday_buy_count[20];
	sprintf(str_workday_buy_count,"%d",this->workday_buy_count);
	char str_weekend_buy_count[20];
	sprintf(str_weekend_buy_count,"%d",this->weekend_buy_count);
	char str_festival_buy_count[20];
	sprintf(str_festival_buy_count,"%d",this->festival_buy_count);
	return user_id+","
		+str_click_count+","+str_collect_count+","+str_addincart_count+","
		+str_buy_count+","+str_workday_buy_count+","+str_weekend_buy_count+","
		+str_festival_buy_count+"\n";
}