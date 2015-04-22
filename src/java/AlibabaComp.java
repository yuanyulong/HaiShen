import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Connection;
import java.sql.Statement;

public class AlibabaComp {

	public static void main(String[] args) {
		Data data = new Data();
		long starttime = System.currentTimeMillis();
		//data.saveData("DataSrc\\tianchi_mobile_recommend_train_user.csv");
		String[] file_postfix={"_2014_11_18","_2014_11_19","_2014_11_20","_2014_11_21","_2014_11_22"
				,"_2014_11_23","_2014_11_24","_2014_11_25","_2014_11_26","_2014_11_27","_2014_11_28"
				,"_2014_11_29","_2014_11_30","_2014_12_01","_2014_12_02","_2014_12_03","_2014_12_04"
				,"_2014_12_05","_2014_12_06","_2014_12_07","_2014_12_08","_2014_12_09","_2014_12_10"
				,"_2014_12_11","_2014_12_12","_2014_12_13","_2014_12_14","_2014_12_15","_2014_12_16"
				,"_2014_12_17","_2014_12_18"};
		String file_item_attr = "D:\\Users\\yuanyulong\\workspace\\AlibabaComp\\files\\tianchi_mobile_recommend_train_user (1)\\tbl_item_attr\\tbl_item_attr";
		String file_user_attr = "D:\\Users\\yuanyulong\\workspace\\AlibabaComp\\files\\tianchi_mobile_recommend_train_user (1)\\tbl_user_attr\\tbl_user_attr";
		String file_user_geo = "D:\\Users\\yuanyulong\\workspace\\AlibabaComp\\files\\tianchi_mobile_recommend_train_user (1)\\tbl_user_geo\\tbl_user_geo";
		String file_user_item = "D:\\Users\\yuanyulong\\workspace\\AlibabaComp\\files\\tianchi_mobile_recommend_train_user (1)\\bl_user_item\\bl_user_item";
		for(int i=0; i<31; i++)
		{
			data.saveDataToItemAttr(file_item_attr+file_postfix[0]+".csv");
			data.saveDataToUserAttr(file_user_attr+file_postfix[i]+".csv");
			data.saveDataToUserGeo(file_user_geo+file_postfix[i]+".csv");
			data.saveDataToUserItem(file_user_item+file_postfix[i]+".csv");
		}
		long endtime = System.currentTimeMillis();
		System.out.println(""+(endtime-starttime)+"ms");

		/*String host="192.168.133.141";//主机ip地址
		String port="3306";//端口号
		String dbname="AlibabaTC";//数据库名称
		String username="root";//用户名
		String password="root123";//密码
		DbConnection dbconn = new DbConnection(host,port,dbname,username,password);
		if(dbconn.getConnection())
		{
			try {
				Statement stmt = dbconn.conn.createStatement();
				String sql = "select * from tbl_tianchi_mobile_recommend_train_user;";
				ResultSet rs = stmt.executeQuery(sql);//执行查询
				while(rs.next())
				{
					System.out.println(rs.getInt(1)+"\t"+rs.getString(2)+"\t"+rs.getString(3)
							+"\t"+rs.getInt(4)+"\t"+rs.getString(5)+"\t"+rs.getString(6)
							+"\t"+rs.getDate(7)+"\t"+rs.getInt(8));

				}
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				dbconn.closeConneciton();
			}
		}else
		{
			System.out.println("连接失败!");
		}*/

	}

}
