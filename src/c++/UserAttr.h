#ifndef USERATTR
#define USERATTR
#include <string>
using namespace std;
class UserAttr
{
public:
	string user_id;//�û����
	int click_count;//�û��ܵĵ������
	int collect_count;//�û��ܵ��ղش���
	int addincart_count;//�û����빺�ﳵ�Ĵ���
	int buy_count;//�û��ܵĹ������
	int workday_buy_count;//�û������չ���Ĵ���
	int weekend_buy_count;//�û���ĩ����Ĵ���
	int festival_buy_count;//�û����չ���Ĵ���
public:
	UserAttr();
	string toString();
	bool operator<(const UserAttr &a)const
	{
		return user_id < a.user_id;
	}
};
#endif