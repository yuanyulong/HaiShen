#ifndef USER_ITEM
#define USER_ITEM
#include <string>
using namespace std;
class User_Item
{
public:
	string user_id;//用户编号
	string item_id;//商品的名字
	string item_category;//商品所属类别
	int buy_count; //商品被此用户购买的次数
	int workday_buy_count;//商品工作日被此用户购买的次数
	int weekend_buy_count;//商品周末被此用户购买的次数
	int festival_buy_count;//商品节日被此用户购买的次数

public:
	User_Item();
	string toString();
	bool operator<(const User_Item &a)const
	{
		if(user_id==a.user_id)
		{
			return item_id < a.item_id;
		}else
		{
			return user_id < a.user_id;
		}
	}
};
#endif