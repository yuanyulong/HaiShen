#ifndef USER_ITEM
#define USER_ITEM
#include <string>
using namespace std;
class User_Item
{
public:
	string user_id;//�û����
	string item_id;//��Ʒ������
	string item_category;//��Ʒ�������
	int buy_count; //��Ʒ�����û�����Ĵ���
	int workday_buy_count;//��Ʒ�����ձ����û�����Ĵ���
	int weekend_buy_count;//��Ʒ��ĩ�����û�����Ĵ���
	int festival_buy_count;//��Ʒ���ձ����û�����Ĵ���

public:
	User_Item();
	string toString();
	bool operator<(const User_Item &a)const
	{
		return (user_id < a.user_id || (user_id == a.user_id  && item_id < a.item_id));

	}
};
#endif