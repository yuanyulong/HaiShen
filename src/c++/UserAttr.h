#ifndef USERATTR
#define USERATTR
#include <string>
using namespace std;
class UserAttr
{
public:
	string user_id;//用户编号
	int click_count;//用户总的点击次数
	int collect_count;//用户总的收藏次数
	int addincart_count;//用户加入购物车的次数
	int buy_count;//用户总的购买次数
	int workday_buy_count;//用户工作日购买的次数
	int weekend_buy_count;//用户周末购买的次数
	int festival_buy_count;//用户节日购买的次数
public:
	UserAttr();
	string toString();
	bool operator<(const UserAttr &a)const
	{
		return user_id < a.user_id;
	}
};
#endif