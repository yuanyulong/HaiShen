
public class Time {
	public int year;//��Ӧ�����
	public int month;//��Ӧ���·�
	public int day;//��Ӧ������
	public int hour;//��Ӧ��Сʱ��,�������ʾhour����hourΪ-1
	public int type;//1:��������2:������ĩ3:������������
	
	public int getYear()
	{
		return this.year;
	}
	public int getMonth()
	{
		return this.month;
	}
	public int getDay()
	{
		return this.day;
	}
	public int getHour()
	{
		return this.hour;
	}
	public int getType()
	{
		return this.type;
	}
	
	public void setYear(int year)
	{
		this.year = year;
	}
	
	public void setMonth(int month)
	{
		this.month = month;
	}
	
	public void setDay(int day)
	{
		this.day = day;
	}
	
	public void setHour(int hour)
	{
		this.hour = hour;
	}
	
	public void setType(int type)
	{
		this.type = type;
	}
	
	@Override
	public int hashCode() {
		return this.year+this.month+this.day+this.hour+this.type;
	}
	@Override
	public boolean equals(Object obj) {
		Time t_obj = (Time)obj;
		return this.year==t_obj.year&&this.month==t_obj.month
				&&this.day==t_obj.month&&this.hour==t_obj.hour&&this.type==t_obj.type;
	}
	
	
	
}
