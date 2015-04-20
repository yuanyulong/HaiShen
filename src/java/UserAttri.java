import java.util.*;
public class UserAttri {
	public class ItemBehavior {
		public int item_id;
		public int count;
	}
	public float user_id;//用户的编号
//用户的购买欲望
	//前三个数越大说明了用户越喜欢o2o的购物形式
	public int usercount;//用户频数	
	public HashMap<Float,Integer> categorycount;//用户购买商品种类的数量	
	public HashMap<String,Integer> itemcount;//用户购买商品的数量
	
	public HashMap<Integer,Integer> behaviorcount;//每个用户消费类型的统计
	public HashMap<Integer,Integer> behaviorbuycount;//每个用户消费类型转化为购买的统计
//匹配量
	public HashMap<String,HashMap<Integer,Integer>> geobehaviorcount;//不同地理位置的行为统计量
	public Vector <String> itemcategory;//每个用户购买商品的种类
	public HashMap<Integer,Time> behaviortime;//不同消费类型所对应的时间
	public ItemBehavior[] clicked_nobuy;//最近三天点击但尚未购买的商品
	public ItemBehavior[] collected_nobuy;//最近三天收藏但未购买的商品
	public ItemBehavior[] shopingcart_nobuy;//最近三天加入购物车但未购买的商品
}
