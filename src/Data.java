import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.*;
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
	//从文件中读取数据的函数
	public void readData(String filename)
	{
		try {
			BufferedReader br = new BufferedReader(new FileReader(filename));
			String s = null;
			while((s=br.readLine())!=null)
			{
				String[] str = s.split(",");
				Train_User tu = new Train_User();
				tu.user_id = str[0];
				tu.item_id = str[1];
				tu.behavior_type = Integer.parseInt(str[2]);
				tu.user_geohash = str[3];
				tu.item_category = str[4];
				
				//data.get(key);
				System.out.println(s);
			}
			br.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
}
