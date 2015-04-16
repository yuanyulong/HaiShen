import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;


public class AlibabaComp {

	public static void main(String[] args) {
		Data data = new Data();
		//data.readData("D:\\Users\\yuanyulong\\workspace\\AlibabaComp\\files\\tianchi_mobile_recommend_train_user\\tianchi_mobile_recommend_train_user.csv");
		SimpleDateFormat mydf = new SimpleDateFormat("yyyy-MM-dd");
		try {
			Date dt = mydf.parse("2015-03-05");
			Calendar cal = Calendar.getInstance();
			cal.setTime(dt);
			System.out.println(cal.get(Calendar.DAY_OF_WEEK)-1);

		} catch (ParseException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

}
