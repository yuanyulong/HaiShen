#ifndef USER_GEO
#define USER_GEO
#include<string>
using namespace std;
class User_Geo
{
public:
	string user_id;//用户编号
	string geohash;//购买地址
	int buy_count;//用户在此地址购买商品的数量
	int workday_buy_count;//用户工作日在此地址购买次数
	int weekend_buy_count;//用户周末在此地址购买次数
	int festival_buy_count;//用户节日在此地址购买次数
public:
	User_Geo();
	string toString();
	bool operator<(const User_Geo &a)const
	{
		if(user_id==a.user_id)
		{
			return geohash < a.geohash;
		}else
		{
			return user_id < a.user_id;
		}
	}
};
#endif