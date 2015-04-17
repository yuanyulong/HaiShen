import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.sql.SQLException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;

import java.sql.PreparedStatement;
public class Data {
	public class Train_User
	{
		public String user_id;
		public String item_id;
		public int behavior_type;
		public String user_geohash;
		public String item_category;
		public Time time; 
	}
	HashMap<Time,Vector<Train_User>> data;//按日期划分保存的用户购买集
	static float count=0;
	
	
	
	public Data()
	{
		data = new HashMap<Time,Vector<Train_User>>();
	}
	//从文件中读取数据的函数
	public void readData(String filename)
	{
		try {
			BufferedReader br = new BufferedReader(new FileReader(filename));
			String s = null;
			s=br.readLine();
			while((s=br.readLine())!=null)
			{
				String[] str = s.split(",");
				Train_User tu = new Train_User();
				tu.user_id = str[0];
				tu.item_id = str[1];
				tu.behavior_type = Integer.parseInt(str[2]);
				tu.user_geohash = str[3];
				tu.item_category = str[4];
				
				String[] str_time = str[5].split(" ");
				SimpleDateFormat mydf = new SimpleDateFormat("yyyy-MM-dd");
				Date dt = mydf.parse(str_time[0]);
				Calendar cal = Calendar.getInstance();
				cal.setTime(dt);
				tu.time = new Time();
				tu.time.setYear(cal.get(Calendar.YEAR));
				tu.time.setMonth(cal.get(Calendar.MONTH));
				tu.time.setDay(cal.get(Calendar.DAY_OF_MONTH));
				tu.time.setHour(Integer.parseInt(str_time[1]));
//是否是工作日				
				if((cal.get(Calendar.DAY_OF_WEEK)-1)>=1&&(cal.get(Calendar.DAY_OF_WEEK)-1)<=5)
				{
					tu.time.setType(1);
				}else//是否是周末
				{
					tu.time.setType(2);
				}
//是否是双十二这以特殊的日期
				if(cal.get(Calendar.MONTH)==12&&cal.get(Calendar.DAY_OF_MONTH)==12)
				{
					tu.time.setType(3);
				}
				
				//data.get(key);
				//System.out.println(s);
				/*System.out.println(tu.user_id);
				System.out.println(tu.item_id);
				System.out.println(tu.behavior_type);
				System.out.println(tu.user_geohash);
				System.out.println(tu.item_category);
				System.out.println(tu.time.getYear());
				System.out.println(tu.time.getMonth());
				System.out.println(tu.time.getDay());
				System.out.println(tu.time.getType());
				System.out.println("============");*/
//生成时间的键值
				Time key_time = new Time();
				key_time.setYear(tu.time.getYear());
				key_time.setMonth(tu.time.getMonth());
				key_time.setDay(tu.time.getDay());
				key_time.setHour(-1);
				key_time.setType(tu.time.getType());
				if(data.get(key_time)==null)
				{
					Vector<Train_User> vec_value_tu = new Vector<Train_User>();
					vec_value_tu.add(tu);
					data.put(key_time, vec_value_tu);
				}else
				{
					data.get(key_time).add(tu);
				}

			}
			br.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (ParseException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	
	//将数据保存到数据库中
	public void saveData(String filename)
	{
		BufferedReader br = null;
		PreparedStatement pstmt = null;
		DbConnection dbconn = null;
		try {
			br = new BufferedReader(new FileReader(filename));
			String s = null;
			s=br.readLine();
			
			while((s=br.readLine())!=null)
			{
				String[] str = s.split(",");
				String user_id = str[0];
				String item_id = str[1];
				int behavior_type = Integer.parseInt(str[2]);
				String user_geohash = str[3];
				String item_category = str[4];
				
				String[] str_time = str[5].split(" ");
				SimpleDateFormat mydf = new SimpleDateFormat("yyyy-MM-dd");
				java.util.Date util_date = mydf.parse(str_time[0]);
				java.sql.Date sql_date = new java.sql.Date(util_date.getTime());	
				
				int hour = Integer.parseInt(str_time[1]);
				
				GlobalInfo gi = GlobalInfo.getInstance();
				dbconn = new DbConnection(gi.host,gi.port,gi.dbname,gi.username,gi.password);
				if(dbconn.getConnection())
				{
					String sql = "insert into tbl_tianchi_mobile_recommend_train_user(user_id,item_id,behavior_type,user_geohash,item_category,time,hour) values(?,?,?,?,?,?,?);";
					pstmt = dbconn.conn.prepareStatement(sql);
					pstmt.setString(1,user_id);
					pstmt.setString(2,item_id);
					pstmt.setInt(3, behavior_type);
					pstmt.setString(4, user_geohash);
					pstmt.setString(5,item_category);
					pstmt.setDate(6,sql_date);
					pstmt.setInt(7, hour);
					int t = pstmt.executeUpdate();//执行插入
					//System.out.println(t);
				}else
				{
					System.out.println("连接失败!");
				}
			}
			br.close();
			pstmt.close();
			dbconn.conn.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (ParseException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
