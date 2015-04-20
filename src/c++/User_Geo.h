#ifndef USER_GEO
#define USER_GEO
#include<string>
using namespace std;
class User_Geo
{
public:
	string user_id;//�û����
	string geohash;//�����ַ
	int buy_count;//�û��ڴ˵�ַ������Ʒ������
	int workday_buy_count;//�û��������ڴ˵�ַ�������
	int weekend_buy_count;//�û���ĩ�ڴ˵�ַ�������
	int festival_buy_count;//�û������ڴ˵�ַ�������
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