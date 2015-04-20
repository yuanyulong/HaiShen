#ifndef ITEMATTR
#define ITEMATTR
#include <string>
using namespace std;
class ItemAttr
{
public:
	string item_id;//��Ʒ���
	string geohash;//��Ʒ����λ��
	string item_category;//��Ʒ�������
	int buy_count;//��Ʒ������Ĵ���
	int workday_buy_count;//��Ʒ�����ձ�����Ĵ���
	int weekend_buy_count;//��Ʒ��ĩ������Ĵ���
	int festival_buy_count;//��Ʒ���ձ�����Ĵ���
	int clicked_count;//��Ʒ������Ĵ���
	int collected_count;//��Ʒ���ղصĴ���
	int addedincart_count;//��Ʒ�����빺�ﳵ�Ĵ���
public:
	ItemAttr();
	string toString();
	bool operator<(const ItemAttr &a)const
	{
			return item_id < a.item_id;
	}

};
#endif