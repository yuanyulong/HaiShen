import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;


public class AlibabaComp {

	public static void main(String[] args) {
		Data data = new Data();
		long starttime = System.currentTimeMillis();
		data.readData("D:\\Users\\yuanyulong\\workspace\\AlibabaComp\\files\\tianchi_mobile_recommend_train_user\\tianchi_mobile_recommend_train_user.csv");
		long endtime = System.currentTimeMillis();
		System.out.println(""+(endtime-starttime)+"ms");
		
	}

}
