
public class GlobalInfo {
	public static String host="192.168.133.141";//主机ip地址
	public static String port="3306";//端口号
	public static String dbname="AlibabaTC";//数据库名称
	public static String username="root";//用户名
	public static String password="root123";//密码
	public static GlobalInfo gi = null;
	//默认构造函数
	private GlobalInfo()
	{
		
	}
	//静态工厂方法
	public static GlobalInfo getInstance()
	{
		if(gi == null)
		{
			gi = new GlobalInfo();
		}
		return gi;
	}
}
