import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Connection;
import java.sql.Statement;
public class DbConnection {
	public Connection conn = null;
	public String host;//主机ip地址
	public String port;//端口号
	public String dbname;//数据库名称
	public String username;//用户名
	public String password;//密码
	public String url;//连接地址
//初始化参数
	public DbConnection(String host,String port,String dbname,String username,String password)
	{
		this.host = host;
		this.port = port;
		this.dbname = dbname;
		this.username = username;
		this.password = password;
		this.url = "jdbc:mysql://"+this.host+":"+this.port+"/"+this.dbname
				+"?"+"user="+this.username+"&"+"password="+this.password;
	}
	public boolean getConnection()
	{
		try {
			Class.forName("com.mysql.jdbc.Driver");//动态加载mysql驱动
			conn = DriverManager.getConnection(url);
			return true;
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return false;
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return false;
		}

	}
	public void closeConneciton()
	{
		try {
			conn.close();
            conn = null;
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}


	public Connection getConnecitonHandle()
    {
        if (conn == null) {
            getConnection();
        }
        return conn;
    }

}
