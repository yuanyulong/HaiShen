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
	HashMap<Time,Vector<Train_User>> data;//�����ڻ��ֱ�����û�����
	static float count=0;



	public Data()
	{
		data = new HashMap<Time,Vector<Train_User>>();
	}
	//���ļ��ж�ȡ���ݵĺ���
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
//�Ƿ��ǹ�����
				if((cal.get(Calendar.DAY_OF_WEEK)-1)>=1&&(cal.get(Calendar.DAY_OF_WEEK)-1)<=5)
				{
					tu.time.setType(1);
				}else//�Ƿ�����ĩ
				{
					tu.time.setType(2);
				}
//�Ƿ���˫ʮ���������������
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
//����ʱ��ļ�ֵ
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

	//�����ݱ��浽���ݿ���
	public void saveData(String filename)
	{
		BufferedReader br = null;
		PreparedStatement pstmt = null;
		DbConnection dbconn = null;
		try {
			br = new BufferedReader(new FileReader(filename));
			String s = null;
			s=br.readLine();

			GlobalInfo gi = GlobalInfo.getInstance();
			dbconn = new DbConnection(gi.host,gi.port,gi.dbname,gi.username,gi.password);
			if(! dbconn.getConnection()) {
				System.out.println("����ʧ��!");
                System.out.println("Can not connect the mysql\n");
                System.exit(1);
            }
            //public Connection conn = dbconn.getConnecitonHandle();
            dbconn.conn.setAutoCommit(false);
            int count = 0;
            String sql = "insert into tbl_tianchi_mobile_recommend_train_user(user_id,item_id,behavior_type,user_geohash,item_category,time,hour) values(?,?,?,?,?,?,?);";
            pstmt = dbconn.conn.prepareStatement(sql);
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
				//�����������ÿ���������������
				//֮��������Ϊ1����Ϊ���������ظ���
				//�����ݿ��н�����Ψһ��Լ��
                //if (count < 1) {
				pstmt.setString(1,user_id);
                pstmt.setString(2,item_id);
                pstmt.setInt(3, behavior_type);
                pstmt.setString(4, user_geohash);
                pstmt.setString(5,item_category);
                pstmt.setDate(6,sql_date);
                pstmt.setInt(7, hour);
                pstmt.addBatch();
                count++;
				if (count < 5000) {
                    
                } else {
                    /*��������*/
                	try{
                		pstmt.executeBatch();
                	}catch (SQLException e) {
            			// TODO Auto-generated catch block
            			//e.printStackTrace();
                	}
            		dbconn.conn.commit();
            		pstmt.close();
            		pstmt = dbconn.conn.prepareStatement(sql);
                    count = 0;
                }
                //int t = pstmt.executeUpdate();//ִ�в���
                //System.out.println(t);
			}
			br.close();
            if (count > 0) {
            	try{
            		pstmt.executeBatch();
            		dbconn.conn.commit();
            		pstmt.close();
            	}catch (SQLException e) {
        			// TODO Auto-generated catch block
        			e.printStackTrace();
            	}
            }
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
	
		public void saveDataToItemAttr(String filename)
		{
			BufferedReader br = null;
			PreparedStatement pstmt = null;
			DbConnection dbconn = null;
			try {
				br = new BufferedReader(new FileReader(filename));
				String s = null;
				s=br.readLine();

				GlobalInfo gi = GlobalInfo.getInstance();
				dbconn = new DbConnection(gi.host,gi.port,gi.dbname,gi.username,gi.password);
				if(! dbconn.getConnection()) {
					System.out.println("����ʧ��!");
	                System.out.println("Can not connect the mysql\n");
	                System.exit(1);
	            }
	            //public Connection conn = dbconn.getConnecitonHandle();
	            dbconn.conn.setAutoCommit(false);
	            int count = 0;
	            String sql = "insert into tbl_item_attr_temp(item_id,geohash,item_category,buy_count,workday_buy_count,weekend_buy_count,festival_buy_count,clicked_count,collected_count,addedincart_count) values(?,?,?,?,?,?,?,?,?,?);";
	            pstmt = dbconn.conn.prepareStatement(sql);
				while((s=br.readLine())!=null)
				{
					String[] str = s.split(",");
					String item_id = str[0];
					String geohash = str[1];
					String item_category = str[2];
					int buy_count = Integer.parseInt(str[3]);
					int workday_buy_count = Integer.parseInt(str[4]);
					int weekend_buy_count = Integer.parseInt(str[5]);
					int festival_buy_count = Integer.parseInt(str[6]);
					int clicked_count = Integer.parseInt(str[7]);
					int collected_count = Integer.parseInt(str[8]);
					int addedincart_count = Integer.parseInt(str[9]);

						pstmt.setString(1, item_id);
						pstmt.setString(2, geohash);
						pstmt.setString(3, item_category);
						pstmt.setInt(4, buy_count);
						pstmt.setInt(5, workday_buy_count);
						pstmt.setInt(6, weekend_buy_count);
						pstmt.setInt(7, festival_buy_count);
						pstmt.setInt(8, clicked_count);
						pstmt.setInt(9, collected_count);
						pstmt.setInt(10,addedincart_count);
	                pstmt.addBatch();
	                count++;
					if (count < 5000) {
	                    
	                } else {
	                    /*��������*/
	                	try{
	                		pstmt.executeBatch();
	                	}catch (SQLException e) {
	            			// TODO Auto-generated catch block
	            			//e.printStackTrace();
	                	}
	            		dbconn.conn.commit();
	            		pstmt.close();
	            		pstmt = dbconn.conn.prepareStatement(sql);
	                    count = 0;
	                }
	                //int t = pstmt.executeUpdate();//ִ�в���
	                //System.out.println(t);
				}
				br.close();
	            if (count > 0) {
	            	try{
	            		pstmt.executeBatch();
	            		dbconn.conn.commit();
	            		pstmt.close();
	            	}catch (SQLException e) {
	        			// TODO Auto-generated catch block
	        			e.printStackTrace();
	            	}
	            }
				dbconn.conn.close();
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}  catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				
			}
		}
		

		
		
		public void saveDataToUserAttr(String filename)
		{
			BufferedReader br = null;
			PreparedStatement pstmt = null;
			DbConnection dbconn = null;
			try {
				br = new BufferedReader(new FileReader(filename));
				String s = null;
				s=br.readLine();

				GlobalInfo gi = GlobalInfo.getInstance();
				dbconn = new DbConnection(gi.host,gi.port,gi.dbname,gi.username,gi.password);
				if(! dbconn.getConnection()) {
					System.out.println("����ʧ��!");
	                System.out.println("Can not connect the mysql\n");
	                System.exit(1);
	            }
	            //public Connection conn = dbconn.getConnecitonHandle();
	            dbconn.conn.setAutoCommit(false);
	            int count = 0;
	            String sql = "insert into tbl_user_attr_temp(user_id,click_count,collect_count,addincart_count,buy_count,workday_buy_count,weekend_buy_count,festival_buy_count) values(?,?,?,?,?,?,?,?);";
	            pstmt = dbconn.conn.prepareStatement(sql);
				while((s=br.readLine())!=null)
				{
					String[] str = s.split(",");
					String user_id = str[0];
					int click_count = Integer.parseInt(str[1]);
					int collect_count = Integer.parseInt(str[2]);
					int addincart_count = Integer.parseInt(str[3]);
					int buy_count = Integer.parseInt(str[4]);
					int workday_buy_count = Integer.parseInt(str[5]);
					int weekend_buy_count = Integer.parseInt(str[6]);
					int festival_buy_count = Integer.parseInt(str[7]);

					pstmt.setString(1, user_id);
					pstmt.setInt(2, click_count);
					pstmt.setInt(3, collect_count);
					pstmt.setInt(4, addincart_count);
					pstmt.setInt(5, buy_count);
					pstmt.setInt(6, workday_buy_count);
					pstmt.setInt(7, weekend_buy_count);
					pstmt.setInt(8,festival_buy_count);

					pstmt.addBatch();
		            count++;
		            if (count < 5000) {
		                    
		            } else {
		              /*��������*/
		                try{
		                		pstmt.executeBatch();
		                	}catch (SQLException e) {
		            			// TODO Auto-generated catch block
		            			//e.printStackTrace();
		                	}
		            		dbconn.conn.commit();
		            		pstmt.close();
		            		pstmt = dbconn.conn.prepareStatement(sql);
		                    count = 0;
		             }
						//System.out.println(t);
	
				}
				br.close();
				if (count > 0) {
	            	try{
	            		pstmt.executeBatch();
	            		dbconn.conn.commit();
	            		pstmt.close();
	            	}catch (SQLException e) {
	        			// TODO Auto-generated catch block
	        			e.printStackTrace();
	            	}
	            }
				dbconn.conn.close();
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}	

		
		
		public void saveDataToUserGeo(String filename)
		{
			BufferedReader br = null;
			PreparedStatement pstmt = null;
			DbConnection dbconn = null;
			try {
				br = new BufferedReader(new FileReader(filename));
				String s = null;
				s=br.readLine();

				GlobalInfo gi = GlobalInfo.getInstance();
				dbconn = new DbConnection(gi.host,gi.port,gi.dbname,gi.username,gi.password);
				if(! dbconn.getConnection()) {
					System.out.println("����ʧ��!");
	                System.out.println("Can not connect the mysql\n");
	                System.exit(1);
	            }
	            //public Connection conn = dbconn.getConnecitonHandle();
	            dbconn.conn.setAutoCommit(false);
	            int count = 0;
	            String sql = "insert into tbl_user_geo_temp(user_id,geohash,buy_count,workday_buy_count,weekend_buy_count,festival_buy_count) values(?,?,?,?,?,?);";
	            pstmt = dbconn.conn.prepareStatement(sql);
				while((s=br.readLine())!=null)
				{
					String[] str = s.split(",");
					String user_id = str[0];
					String geohash = str[1];
					int buy_count = Integer.parseInt(str[2]);
					int workday_buy_count = Integer.parseInt(str[3]);
					int weekend_buy_count = Integer.parseInt(str[4]);
					int festival_buy_count = Integer.parseInt(str[5]);

					pstmt.setString(1, user_id);
					pstmt.setString(2, geohash);
					pstmt.setInt(3, buy_count);
					pstmt.setInt(4, workday_buy_count);
					pstmt.setInt(5,weekend_buy_count);
					pstmt.setInt(6, festival_buy_count);

					pstmt.addBatch();
		            count++;
		            if (count < 5000) {
		                    
		            } else {
		              /*��������*/
		                try{
		                		pstmt.executeBatch();
		                	}catch (SQLException e) {
		            			// TODO Auto-generated catch block
		            			//e.printStackTrace();
		                	}
		            		dbconn.conn.commit();
		            		pstmt.close();
		            		pstmt = dbconn.conn.prepareStatement(sql);
		                    count = 0;
		             }
						//System.out.println(t);
	
				}
				br.close();
				if (count > 0) {
	            	try{
	            		pstmt.executeBatch();
	            		dbconn.conn.commit();
	            		pstmt.close();
	            	}catch (SQLException e) {
	        			// TODO Auto-generated catch block
	        			e.printStackTrace();
	            	}
	            }
				dbconn.conn.close();
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}	
		
		

		
		
		public void saveDataToUserItem(String filename)
		{
			BufferedReader br = null;
			PreparedStatement pstmt = null;
			DbConnection dbconn = null;
			try {
				br = new BufferedReader(new FileReader(filename));
				String s = null;
				s=br.readLine();

				GlobalInfo gi = GlobalInfo.getInstance();
				dbconn = new DbConnection(gi.host,gi.port,gi.dbname,gi.username,gi.password);
				if(! dbconn.getConnection()) {
					System.out.println("����ʧ��!");
	                System.out.println("Can not connect the mysql\n");
	                System.exit(1);
	            }
	            //public Connection conn = dbconn.getConnecitonHandle();
	            dbconn.conn.setAutoCommit(false);
	            int count = 0;
	            String sql = "insert into tbl_user_item_temp(user_id,item_id,item_category,buy_count,workday_buy_count,weekend_buy_count,festival_buy_count) values(?,?,?,?,?,?,?);";
	            pstmt = dbconn.conn.prepareStatement(sql);
				while((s=br.readLine())!=null)
				{
					String[] str = s.split(",");
					String user_id = str[0];
					String item_id = str[1];
					String item_category = str[2];
					int buy_count = Integer.parseInt(str[3]);
					int workday_buy_count = Integer.parseInt(str[4]);
					int weekend_buy_count = Integer.parseInt(str[5]);
					int festival_buy_count = Integer.parseInt(str[6]);

					pstmt.setString(1, user_id);
					pstmt.setString(2, item_id);
					pstmt.setString(3, item_category);
					pstmt.setInt(4,buy_count);
					pstmt.setInt(5,workday_buy_count);
					pstmt.setInt(6,weekend_buy_count);
					pstmt.setInt(7,festival_buy_count);

					pstmt.addBatch();
		            count++;
		            if (count < 5000) {
		                    
		            } else {
		              /*��������*/
		                try{
		                		pstmt.executeBatch();
		                	}catch (SQLException e) {
		            			// TODO Auto-generated catch block
		            			//e.printStackTrace();
		                	}
		            		dbconn.conn.commit();
		            		pstmt.close();
		            		pstmt = dbconn.conn.prepareStatement(sql);
		                    count = 0;
		             }
						//System.out.println(t);
	
				}
				br.close();
				if (count > 0) {
	            	try{
	            		pstmt.executeBatch();
	            		dbconn.conn.commit();
	            		pstmt.close();
	            	}catch (SQLException e) {
	        			// TODO Auto-generated catch block
	        			e.printStackTrace();
	            	}
	            }
				dbconn.conn.close();
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	
}
