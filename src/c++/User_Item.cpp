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
string user_id;//用户编号
string item_id;//商品的名字
string item_category;//商品所属类别
int buy_count; //商品被此用户购买的次数
int workday_buy_count;//商品工作日被此用户购买的次数
int workend_buy_count;//商品周末被此用户购买的次数
int festival_buy_count;//商品节日被此用户购买的次数
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
