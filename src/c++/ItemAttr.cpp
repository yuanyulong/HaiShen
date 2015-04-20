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