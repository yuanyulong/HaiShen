#ifndef ITEMATTR
#define ITEMATTR
#include <string>
using namespace std;
class ItemAttr
{
public:
	string item_id;//商品编号
	string geohash;//商品所属位置
	string item_category;//商品所属类别
	int buy_count;//商品被购买的次数
	int workday_buy_count;//商品工作日被购买的次数
	int weekend_buy_count;//商品周末被购买的次数
	int festival_buy_count;//商品节日被购买的次数
	int clicked_count;//商品被点击的次数
	int collected_count;//商品被收藏的次数
	int addedincart_count;//商品被加入购物车的次数
public:
	ItemAttr();
	string toString();
	bool operator<(const ItemAttr &a)const
	{
			return item_id < a.item_id;
	}

};
#endif