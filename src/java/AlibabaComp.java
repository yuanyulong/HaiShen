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
		data.saveData("DataSrc\\tianchi_mobile_recommend_train_user.csv");
		long endtime = System.currentTimeMillis();
		System.out.println(""+(endtime-starttime)+"ms");

		/*String host="192.168.133.141";//����ip��ַ
		String port="3306";//�˿ں�
		String dbname="AlibabaTC";//���ݿ�����
		String username="root";//�û���
		String password="root123";//����
		DbConnection dbconn = new DbConnection(host,port,dbname,username,password);
		if(dbconn.getConnection())
		{
			try {
				Statement stmt = dbconn.conn.createStatement();
				String sql = "select * from tbl_tianchi_mobile_recommend_train_user;";
				ResultSet rs = stmt.executeQuery(sql);//ִ�в�ѯ
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
			System.out.println("����ʧ��!");
		}*/

	}

}
