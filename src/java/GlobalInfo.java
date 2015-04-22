
public class GlobalInfo {
   /*
	public static String host="192.168.133.141";//主机ip地址
	public static String port="3306";//端口号
	public static String dbname="AlibabaTC";//数据库名称
	public static String username="root";//用户名
	public static String password="root123";//密码
    */

	public static String host="192.168.133.141";//主机ip地址
	public static String port="3306";//端口号
	public static String dbname="AlibabaTC";//数据库名称
	public static String username="root";//用户名
	public static String password="root123";//密码自己设
	public static GlobalInfo gi = null;
	//默认构造函数
	private GlobalInfo()
	{

	}


    public void setHost(String hostStr) {
        host = hostStr;
    }


    public void setPort(String portStr) {
        port = portStr;
    }

    public void setUsername(String usernameStr) {
        username = usernameStr;
    }


    public void setPassword(String passwordStr) {
        password = passwordStr;
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
